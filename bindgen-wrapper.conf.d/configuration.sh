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
		
		make install T=x86_64-native-linuxapp-gcc DESTDIR="$dpdkDestDir" prefix=/usr/local O="$dpdkBuildDir" EXTRA_CFLAGS="-I$configurationFolderPath/musl-fixes"
		
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
