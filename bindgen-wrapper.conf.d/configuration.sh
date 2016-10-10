# This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
# Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


bindingsName='dpdk'
rootIncludeFileName='dpdk.h'
# rte_kni rte_pmd_bnxt rte_pmd_cxgbe rte_pmd_e1000 rte_pmd_ena rte_pmd_enic rte_pmd_fm10k rte_pmd_i40e rte_pmd_ixgbe rte_pmd_vhost rte_pmd_virtio rte_pmd_vmxnet3_uio rte_vhost
link='dpdk ethdev rte_acl rte_cfgfile rte_cmdline rte_cryptodev rte_distributor rte_eal rte_hash rte_ip_frag rte_jobstats rte_kvargs rte_lpm rte_mbuf rte_mempool rte_meter rte_pdump rte_pipeline rte_pmd_af_packet rte_pmd_bond rte_pmd_null rte_pmd_null_crypto rte_pmd_ring rte_port rte_power rte_reorder rte_ring rte_sched rte_table rte_timer'
macosXHomebrewPackageNames=''
alpineLinuxPackageNames='rsync make gcc linux-headers libunwind-dev linux-grsec-dev'
headersFolderPath="$configurationFolderPath"/dpdk-temp/destdir/usr/local/include/dpdk
clangAdditionalArguments=''

preprocess_before_headersFolderPath()
{
	bindgen_wrapper_ensureRequiredBinariesArePresent "Essential tools (GNU make, not BSD make)" rm mkdir find xargs cat mv grep tac
	
	local dpdkTempDir="$configurationFolderPath"/dpdk-temp
	
	if [ ! -e "$dpdkTempDir"/.do-not-make ]; then
	
		local dpdkSrcDir="$dpdkTempDir"/src
		local dpdkBuildDir="$dpdkTempDir"/build
		local dpdkDestDir="$dpdkTempDir"/destdir
		local dpdkMuslFixesDir="$dpdkTempDir"/musl-fixes
	
		# We do not delete the src dir, as we use rsync to populate it
		rm -rf "$dpdkBuildDir" "$dpdkDestDir" "$dpdkMuslFixesDir"
		mkdir -m 0755 -p "$dpdkSrcDir"
		mkdir -m 0755 -p "$dpdkBuildDir"
		mkdir -m 0755 -p "$dpdkDestDir"
		mkdir -m 0755 -p "$dpdkMuslFixesDir"/sys "$dpdkMuslFixesDir"/bits
	
		rsync --quiet --archive --delete "$homeFolder"/lib/dpdk/ "$dpdkSrcDir"/
		rsync --quiet --archive "$configurationFolderPath"/overrides/ "$dpdkSrcDir"/
	
		# Musl fixes	
			# (1) Make an useful io.h
			(
				cat /usr/include/bits/io.h
				cat "$configurationFolderPath"/musl-fixes/io.extra.h
			) >"$dpdkMuslFixesDir"/bits/io.h
	
			# (2) Install sys/queue.h
			cat "$configurationFolderPath"/musl-fixes/queue.h >"$dpdkMuslFixesDir"/sys/queue.h
	
		# Speed up make
		local numberOfCpus="$(grep -c '^processor' /proc/cpuinfo)"
	
		cd "$dpdkSrcDir" 1>/dev/null 2>/dev/null
		
			sed -i -e 's;#include <rte_per_lcore.h>;#include <sched.h>\n#include <rte_per_lcore.h>;g' lib/librte_eal/common/include/rte_lcore.h
			sed -i -e 's;#include <string.h>;#include <string.h>\n#include <fcntl.h>;g' lib/librte_eal/linuxapp/eal/eal_hugepage_info.c
			sed -i -e 's;#include <errno.h>;#include <errno.h>\n#include <fcntl.h>;g' lib/librte_eal/linuxapp/eal/eal_memory.c
			sed -i -e 's;#include <string.h>;#include <string.h>\n#include <sys/sysmacros.h>\n;g' lib/librte_eal/linuxapp/eal/eal_pci_uio.c
			sed -i -e 's;#define PAGE_SIZE;#undef PAGE_SIZE\n#define PAGE_SIZE;g' lib/librte_eal/linuxapp/eal/eal_pci_vfio.c
			sed -i -e 's;#include <string.h>;#include <string.h>\n#include <fcntl.h>;g' app/test/test_eal_flags.c
			sed -i -e 's;uint hash_key_len;uint8_t hash_key_len;g' app/test-pmd/testpmd.c app/test-pmd/testpmd.h app/test-pmd/config.c
		
			# Local build assumes glibc
			sed -i -e 's;-g;-g -I'"$dpdkMuslFixesDir"';g' buildtools/pmdinfogen/Makefile
		
			# Assumes GNU tar
			sed -i -e '/--keep-newer-files/d' -e 's;--strip-components=1 \\;--strip-components=1;g' mk/rte.sdkinstall.mk
		
			local baseConfiguration=x86_64-native-linuxapp-gcc
			(
				printf '\nCONFIG_RTE_EAL_IGB_UIO=n\n'
				printf '\nCONFIG_RTE_KNI_KMOD=n\n'
				printf '\nCONFIG_RTE_LIBRTE_XEN_DOM0=n\n'
			) >>config/defconfig_"$baseConfiguration"
		
			make --jobs $numberOfCpus install T="$baseConfiguration" DESTDIR="$dpdkDestDir" prefix=/usr/local V=1 O="$dpdkBuildDir" EXTRA_CFLAGS="-D_GNU_SOURCE -D_BSD_SOURCE -I/usr/include -I$dpdkMuslFixesDir -Wno-pointer-to-int-cast" EXTRA_LDLIBS="-lexecinfo -lunwind-x86_64 -lunwind-ptrace -lunwind-generic -lunwind-coredump -lunwind -lunwind-setjmp"
		
		cd - 1>/dev/null 2>/dev/null
	
		# Install musl-fixes; DPDK headers assumes they are installed as a system library
		rsync -a -v "$dpdkMuslFixesDir"/ "$headersFolderPath"/
	
		# rte_memcpy.h fixes
		sed -i -e 's;#include <stdio.h>;#include <stdio.h>\n#include <tmmintrin.h>;g' "$headersFolderPath"/rte_memcpy.h
	fi
}

postprocess_after_rustfmt()
{
	# Sed explanations:-
	# 1 - unwanted constants from header file parsing
	# 2 - unwanted private function
	# 3 - functions that uses va_list (sort of supported, but difficult to use)
	# 4 - fix incorrect static mut types
	| sed \
		-e '/pub const _RTE_RTM_H_:/d' \
		-e '/pub const __ELASTERROR:/d' \
		-e '/pub const __RESERVED:/d' \
	| sed \
		-e '/pub fn __rte_panic/d' \
	| sed \
		-e '/pub fn rte_vlog/d' \
	| sed \
		-e 's/pub static mut per_lcore__rte_errno: c_void;/pub static mut per_lcore__rte_errno: c_int;/g' \
		-e 's/pub static mut per_lcore__cpuset: c_void;/pub static mut per_lcore__cpuset: rte_cpuset_t;/g' \
		-e 's/pub static mut per_lcore__lcore_id: c_void;/pub static mut per_lcore__lcore_id: c_uint;/g'
}

final_chance_to_tweak()
{
	# Make a copy of the headers suitable for use by the rust-c / dpdk crate combination
	mkdir -m 0750 -p "$outputFolderPath"/headers/
	rsync --quiet -a -v "$headersFolderPath"/ "$outputFolderPath"/headers/
	
	
	# Make these compatible with PosixErrorNumber
	#sed -i -e 's/: u32 /: c_int /g' "$outputFolderPath"/constants/E_RTE.rs
	
	# Fix up lcore_config - the presence of rte_cpuset_t (in the Linux version) creates problems
	sed -i -e 's/#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]/#[derive(Copy, Clone)]'"$neline"'#[allow(missing_debug_implementations)]/g' "$outputFolderPath"/structs/lcore_config.rs
	
	# Fix up some structs with bitfields in them; won't work if multiple bitfields are present
	local structWithBitfield
	for structWithBitfield in rte_eth_rxmode rte_eth_txmode rte_cryptodev_data rte_eth_dev_data rte_eth_link rte_lpm_tbl_entry rte_lpm_tbl_entry_v20
	do
		sed -i \
			-e 's/pub _bindgen_bitfield_1_: /pub __bindgen_bitfield: /g' \
			-e '/pub _bindgen_bitfield_[2-9][0-9]*_/d' \
			"$outputFolderPath"/structs/"$structWithBitfield".rs
	done
	
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
}
