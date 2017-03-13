# This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
# Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


bindingsName='dpdk'
rootIncludeFileName='dpdk.h'
# sed -e 's;^GROUP ( ;;g' -e 's; )$;;g' -e 's;\.a ; ;g' -e 's;\.a$;;g' -e 's;^lib;;g' -e 's; lib; ;g' compile-dpdk.conf.d/temporary/destdir/usr/local/lib/libdpdk.a 
#link='ethdev rte_acl rte_cfgfile rte_cmdline rte_cryptodev rte_distributor rte_eal rte_hash rte_ip_frag rte_jobstats rte_kni rte_kvargs rte_lpm rte_mbuf rte_mempool rte_meter rte_pdump rte_pipeline rte_pmd_af_packet rte_pmd_bnxt rte_pmd_bond rte_pmd_cxgbe rte_pmd_e1000 rte_pmd_ena rte_pmd_enic rte_pmd_fm10k rte_pmd_i40e rte_pmd_ixgbe rte_pmd_null rte_pmd_null_crypto rte_pmd_ring rte_pmd_vhost rte_pmd_virtio rte_pmd_vmxnet3_uio rte_port rte_power rte_reorder rte_ring rte_sched rte_table rte_timer rte_vhost'
link='dpdk'
macosXHomebrewPackageNames=''
alpineLinuxPackageNames='rsync make gcc linux-headers libunwind-dev linux-grsec-dev'
clangAdditionalArguments=''

if [ -z "{RTE_SDK:+defined}" ]; then
	if [ ! -d "$RTE_SDK" ]; then
		bindgen_wrapper_fail "Please define the environment variable RTE_SDK ('$RTE_SDK') to an extant folder path"
	fi
	if [ ! -r "$RTE_SDK" ]; then
		bindgen_wrapper_fail "Please define the environment variable RTE_SDK ('$RTE_SDK') to an extant, readable folder path"
	fi
	
	if [ -z "{RTE_TARGET+defined}" ]; then
		headersFolderPath="$RTE_SDK"/"$RTE_TARGET"/include/dpdk

		if [ ! -d "$headersFolderPath" ]; then
			bindgen_wrapper_fail "Please define the environment variable RTE_TARGET ('$RTE_TARGET') to an folder under the environment variable RTE_SDK ('$RTE_SDK')"
		fi
		if [ ! -r "$headersFolderPath" ]; then
			bindgen_wrapper_fail "Please define the environment variable RTE_TARGET ('$RTE_TARGET') to an extant, readable folder under the environment variable RTE_SDK ('$RTE_SDK')"
		fi
		
	else
		bindgen_wrapper_fail "Please define the environment variable RTE_TARGET if defining the environment variable RTE_SDK ('$RTE_SDK')"
	fi
else
	if [ -z "{RTE_TARGET+defined}" ]; then
		bindgen_wrapper_fail "Please define the environment variable RTE_SDK if defining the environment variable RTE_TARGET ('$RTE_TARGET')"
	fi

	headersFolderPath="$homeFolder"/compile-dpdk.conf.d/temporary/destdir/usr/local/include/dpdk
	
	printf '%s\n' "The RTE_SDK and RTE_TARGET environment variables are not defined; assuming that headers have been compiled previously by tools/compile-dpdk to '$headersFolderPath'"
	
	if [ ! -d "$headersFolderPath" ]; then
		bindgen_wrapper_fail "Please run tools/compile-dpdk first or specify the RTE_SDK and RTE_TARGET environment variables"
	fi
fi

preprocess_before_headersFolderPath()
{
	:
}

postprocess_after_rustfmt()
{
	# Sed explanations:-
	# 1 - unwanted constants from header file parsing
	# 2 - unwanted private function
	# 3 - functions that uses va_list (sort of supported, but difficult to use)
	sed \
		-e '/pub const _RTE_RTM_H_:/d' \
		-e '/pub const __ELASTERROR:/d' \
		-e '/pub const __RESERVED:/d' \
	| sed \
		-e '/pub fn __rte_panic/d' \
	| sed \
		-e '/pub fn rte_vlog/d'
}

final_chance_to_tweak()
{
	# Make these compatible with PosixErrorNumber; can't be done as constant type mapping as conversion of unnamed enums occurs after constant type mapping
	sed -i -e 's/: u32 /: c_int /g' "$outputFolderPath"/constants/E_RTE.rs
	
	# Fix up lcore_config - the presence of rte_cpuset_t (in the Linux version) creates problems
	sed -i -e 's/#\[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)\]/#\[derive(Copy, Clone)\]/g' "$outputFolderPath"/structs/lcore_config.rs
	
	# Make code work on FreeBSD - fix cpu_set_t
	{
		cat "$configurationFolderPath"/preamble.rs
		cat <<-EOF
			#[cfg(any(target_os = "android", target_os = "linux"))] pub type rte_cpuset_t = cpu_set_t;
			#[cfg(target_os = "freebsd")] pub type rte_cpuset_t = cpuset_t;
			#[cfg(not(any(target_os = "android", target_os = "linux", target_os = "freebsd")))] pub type rte_cpuset_t = [u64; 16];
		EOF
	} >"$outputFolderPath"/types/rte_cpuset_t.rs
	
	# Fix up some structs with bitfields in them; won't work if multiple bitfields are present
	local structWithBitfield
	for structWithBitfield in rte_eth_rxmode rte_eth_txmode rte_cryptodev_data rte_eth_dev_data rte_eth_link rte_lpm_tbl_entry rte_lpm_tbl_entry_v20
	do
		sed -i \
			-e 's/pub _bindgen_bitfield_1_: /pub __bindgen_bitfield: /g' \
			-e '/pub _bindgen_bitfield_[2-9][0-9]*_/d' \
			"$outputFolderPath"/structs/"$structWithBitfield".rs
	done
	
	# Fix up an union whose size changes depending on SSE options
	sed -i -e 's/u8; 48usize/u32; 9usize/g' "$outputFolderPath"/structs/rte_thash_tuple.rs
	
	# rte_mbuf seems to be generated incorrectly. Convert to an opaque struct, as it's only ever used as a pointer
	{
		cat "$configurationFolderPath"/preamble.rs
		cat <<-EOF
			// Incorrectly generated by bindgen and so made an opaque struct (done in Rust by using an empty enum)
			#[derive(Debug, Copy, Clone, PartialEq, Eq, PartialOrd, Ord, Hash)]
			pub enum rte_mbuf
			{
			}
		EOF
	} >"$outputFolderPath"/structs/rte_mbuf.rs
	
	# rte_timer_status isn't used as a union; the _u32 'field' exists to allow code to atomically set states and owner
	{
		cat "$configurationFolderPath"/preamble.rs
		cat <<-EOF
			#[repr(C, packed)]
			#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
			pub struct rte_timer_status
			{
				pub state: uint16_t,
				pub owner: int16_t,
			}

			impl Default for rte_timer_status
			{
				#[inline(always)]
				fn default() -> Self
				{
					rte_timer_status
					{
						state: RTE_TIMER_STOP,
						owner: RTE_TIMER_NO_OWNER,
					}
				}
			}
		EOF
	} >"$outputFolderPath"/structs/rte_timer_status.rs
	
	# Remove thread-local statics, as there seems to be a problem with them when linking
	sed -e '/pub static mut per_lcore__/d' "$outputFolderPath"/statics/lcore.rs
	
	sed -i -e 's/0usize/RTE_MAX_ETHPORTS/g' "$outputFolderPath"/statics/rte_eth.rs
}
