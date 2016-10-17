# This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
# Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


bindingsName='dpdk'
rootIncludeFileName='dpdk.h'
link='ethdev rte_acl rte_cfgfile rte_cmdline rte_cryptodev rte_distributor rte_eal rte_hash rte_ip_frag rte_jobstats rte_kni rte_kvargs rte_lpm rte_mbuf rte_mempool rte_meter rte_pdump rte_pipeline rte_pmd_af_packet rte_pmd_bnxt rte_pmd_bond rte_pmd_cxgbe rte_pmd_e1000 rte_pmd_ena rte_pmd_enic rte_pmd_fm10k rte_pmd_i40e rte_pmd_ixgbe rte_pmd_null rte_pmd_null_crypto rte_pmd_ring rte_pmd_vhost rte_pmd_virtio rte_pmd_vmxnet3_uio rte_port rte_power rte_reorder rte_ring rte_sched rte_table rte_timer rte_vhost'
macosXHomebrewPackageNames=''
alpineLinuxPackageNames='rsync make gcc linux-headers libunwind-dev linux-grsec-dev'
clangAdditionalArguments=''

# Running under Cargo
if [ ${OUT_DIR+defined} ]; then
	dpdkTempDir="$OUT_DIR"/dpdk-temp		
else
	dpdkTempDir="$configurationFolderPath"/dpdk-temp
fi
headersFolderPath="$dpdkTempDir"/destdir/usr/local/include/dpdk


preprocess_before_headersFolderPath()
{
	# Running under Cargo
	if [ ${OUT_DIR+defined} ]; then
		local dpdkTempDir="$OUT_DIR"/dpdk-temp		
	else
		local dpdkTempDir="$configurationFolderPath"/dpdk-temp
	fi

	if [ ! -e "$dpdkTempDir"/.do-not-make ]; then
		printf '%s\n' "Please run compile-dpdk first"
		exit 1
	fi
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
	# Make a copy of the headers suitable for use by the rust-c / dpdk crate combination
	mkdir -m 0750 -p "$outputFolderPath"/headers/
	rsync --quiet -a -v "$headersFolderPath"/ "$outputFolderPath"/headers/
	
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
	
	# Wrapper functions to make working with thread-local globals correct
	sed -i \
		-e 's/pub static mut per_lcore__rte_errno: c_void;/static mut per_lcore__rte_errno: c_int;/g' \
		-e 's/pub static mut per_lcore__cpuset: c_void;/static mut per_lcore__cpuset: rte_cpuset_t;/g' \
		-e 's/pub static mut per_lcore__lcore_id: c_void;/static mut per_lcore__lcore_id: c_uint;/g' \
		"$outputFolderPath"/statics/lcore.rs
	cat >>"$outputFolderPath"/statics/lcore.rs <<EOF
		
#[inline(always)]
pub fn rte_cpuset() -> rte_cpuset_t
{
	unsafe { per_lcore__cpuset }
}

#[inline(always)]
pub fn rte_lcore_id() -> c_uint
{
	unsafe { per_lcore__lcore_id }
}

#[inline(always)]
pub fn rte_errno() -> c_int
{
	unsafe { per_lcore__rte_errno }
}
EOF
}
