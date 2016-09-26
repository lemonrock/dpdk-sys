# This file is part of mbedtls-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/mbedtls-sys/master/COPYRIGHT. No part of mbedtls-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
# Copyright © 2016 The developers of mbedtls-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/mbedtls-sys/master/COPYRIGHT.


bindingsName='dpdk'
rootIncludeFileName='ssl.h'
link=''
macosXHomebrewPackageNames='coreutils'
alpineLinuxPackageNames=''
headersFolderPath="$configurationFolderPath"/dpdk-temp/destdir/usr/local/include


#bindgen_wrapper_addTacFallbackIfNotPresent

preprocess_before_headersFolderPath()
{
	bindgen_wrapper_ensureRequiredBinariesArePresent "Essential tools (GNU make, not BSD make)" make rm mkdir rsync find xargs gcc
	sudo apk add linux-headers
	
	local dpdkTempDir="$configurationFolderPath"/dpdk-temp
	local dpdkSrcDir="$dpdkTempDir"/src
	local dpdkBuildDir="$dpdkTempDir"/build
	local dpdkDestDir="$dpdkTempDir"/destdir
	
	# We do not delete the src dir, as we use rsync to populate it
	rm -rf "$dpdkBuildDir" "$dpdkDestDir"
	mkdir -m 0755 -p "$dpdkSrcDir"
	mkdir -m 0755 -p "$dpdkBuildDir"
	mkdir -m 0755 -p "$dpdkDestDir"
	
	rsync -a --quiet --delete "$homeFolder"/lib/dpdk/ "$dpdkSrcDir"/
	
	cd "$dpdkSrcDir" 1>/dev/null 2>/dev/null
		
		sed -i -e 's/#include <rte_per_lcore.h>/#include <sched.h>\n#include <rte_per_lcore.h>/g' lib/librte_eal/common/include/rte_lcore.h
		sed -i -e 's/#include <string.h>/#include <string.h>\n#include <fcntl.h>/g' lib/librte_eal/linuxapp/eal/eal_hugepage_info.c
		sed -i -e 's/#include <errno.h>/#include <errno.h>\n#include <fcntl.h>/g' lib/librte_eal/linuxapp/eal/eal_memory.c
		
		make install T=x86_64-native-linuxapp-gcc DESTDIR="$dpdkDestDir" prefix=/usr/local V=1 O="$dpdkBuildDir" EXTRA_CFLAGS="-D_GNU_SOURCE -I/usr/include -I$configurationFolderPath/musl-fixes -Wno-pointer-to-int-cast"
		
	cd - 1>/dev/null 2>/dev/null
}

postprocess_after_generation()
{	
	:
}

postprocess_after_rustfmt()
{
	:
}
