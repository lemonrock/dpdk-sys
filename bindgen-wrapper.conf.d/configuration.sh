# This file is part of mbedtls-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/mbedtls-sys/master/COPYRIGHT. No part of mbedtls-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
# Copyright © 2016 The developers of mbedtls-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/mbedtls-sys/master/COPYRIGHT.


bindingsName='dpdk'
rootIncludeFileName='ssl.h'
link=''
macosXHomebrewPackageNames=''
alpineLinuxPackageNames=''
#headersFolderPath="$homeFolder"/lib/"$bindingsName"/include/"$bindingsName"


#bindgen_wrapper_addTacFallbackIfNotPresent

postprocess_after_generation()
{	
	:
}

postprocess_after_rustfmt()
{
	:
}
