// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum rte_crypto_auth_algorithm
{
	RTE_CRYPTO_AUTH_NULL = 1,
	RTE_CRYPTO_AUTH_AES_CBC_MAC = 2,
	RTE_CRYPTO_AUTH_AES_CCM = 3,
	RTE_CRYPTO_AUTH_AES_CMAC = 4,
	RTE_CRYPTO_AUTH_AES_GCM = 5,
	RTE_CRYPTO_AUTH_AES_GMAC = 6,
	RTE_CRYPTO_AUTH_AES_XCBC_MAC = 7,
	RTE_CRYPTO_AUTH_KASUMI_F9 = 8,
	RTE_CRYPTO_AUTH_MD5 = 9,
	RTE_CRYPTO_AUTH_MD5_HMAC = 10,
	RTE_CRYPTO_AUTH_SHA1 = 11,
	RTE_CRYPTO_AUTH_SHA1_HMAC = 12,
	RTE_CRYPTO_AUTH_SHA224 = 13,
	RTE_CRYPTO_AUTH_SHA224_HMAC = 14,
	RTE_CRYPTO_AUTH_SHA256 = 15,
	RTE_CRYPTO_AUTH_SHA256_HMAC = 16,
	RTE_CRYPTO_AUTH_SHA384 = 17,
	RTE_CRYPTO_AUTH_SHA384_HMAC = 18,
	RTE_CRYPTO_AUTH_SHA512 = 19,
	RTE_CRYPTO_AUTH_SHA512_HMAC = 20,
	RTE_CRYPTO_AUTH_SNOW3G_UIA2 = 21,
	RTE_CRYPTO_AUTH_ZUC_EIA3 = 22,
	RTE_CRYPTO_AUTH_LIST_END = 23,
}
