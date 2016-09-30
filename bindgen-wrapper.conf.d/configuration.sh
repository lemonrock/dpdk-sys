# This file is part of mbedtls-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/mbedtls-sys/master/COPYRIGHT. No part of mbedtls-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
# Copyright © 2016 The developers of mbedtls-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/mbedtls-sys/master/COPYRIGHT.


bindingsName='dpdk'
rootIncludeFileName='dpdk.h'
link=''
macosXHomebrewPackageNames=''
alpineLinuxPackageNames='rsync make gcc linux-headers libunwind-dev linux-grsec-dev'
headersFolderPath="$configurationFolderPath"/dpdk-temp/destdir/usr/local/include/dpdk
clangAdditionalArguments='-U__SSE2__'

preprocess_before_headersFolderPath()
{
	bindgen_wrapper_ensureRequiredBinariesArePresent "Essential tools (GNU make, not BSD make)" rm mkdir find xargs cat mv grep tac
	
	local dpdkTempDir="$configurationFolderPath"/dpdk-temp
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
	
	# Generate an include file that includes all useful files
	cat >"$headersFolderPath"/"$rootIncludeFileName" <<-EOF
		#define _GNU_SOURCE
		#define _BSD_SOURCE
		#include <cmdline.h>
		#include <cmdline_parse_etheraddr.h>
		#include <cmdline_parse_ipaddr.h>
		#include <cmdline_parse_num.h>
		#include <cmdline_parse_portlist.h>
		#include <cmdline_parse_string.h>
		#include <cmdline_socket.h>
		// #include <rte_acl.h> Vectors
		#include <rte_alarm.h>
		#include <rte_approx.h>
		#include <rte_arp.h>
		#include <rte_atomic.h>
		//#include <rte_bitmap.h>  All static inline methods
		#include <rte_byteorder.h>
		#include <rte_cfgfile.h>
		#include <rte_config.h>
		#include <rte_cpuflags.h>
		#include <rte_crypto.h>
		//#include <rte_cryptodev_pmd.h>
		#include <rte_dev.h>
		#include <rte_dev_info.h>
		//#include <rte_devargs.h>
		#include <rte_distributor.h>
		#include <rte_eal.h>
		#include <rte_eal_memconfig.h>
		#include <rte_errno.h>
	EOF
	
	# Install musl-fixes; DPDK headers assumes they are installed as a system library
	rsync -a -v "$dpdkMuslFixesDir"/ "$headersFolderPath"/
	
	# rte_memcpy.h fixes
	sed -i -e 's;#include <stdio.h>;#include <stdio.h>\n#include <tmmintrin.h>;g' "$headersFolderPath"/rte_memcpy.h
}

postprocess_after_rustfmt()
{
	# Sed line explanations:-
	# 1 - remove a #derive(Debug)
	# 2 - suppress warnings about missing Debug
	tac \
	| sed \
		-e '/pub struct lcore_config/{n; d;}' \
		-e 's/pub struct rdline$/pub struct rdline'"$newline"'#[allow(missing_debug_implementations)]/g' \
		-e 's/pub struct cmdline$/pub struct cmdline'"$newline"'#[allow(missing_debug_implementations)]/g' \
		-e 's/pub struct rte_config$/pub struct rte_config'"$newline"'#[allow(missing_debug_implementations)]/g' \
		-e 's/pub struct lcore_config$/pub struct lcore_config'"$newline"'#[allow(missing_debug_implementations)]/g' \
		-e 's/pub struct rte_mempool_cache$/pub struct rte_mempool_cache'"$newline"'#[allow(missing_debug_implementations)]/g' \
		-e 's/pub struct rte_cfgfile_entry$/pub struct rte_cfgfile_entry'"$newline"'#[allow(missing_debug_implementations)]/g' \
		-e 's/pub struct rte_mem_config$/pub struct rte_mem_config'"$newline"'#[allow(missing_debug_implementations)]/g' \
	| tac
}
