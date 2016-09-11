// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum rte_crypto_cipher_algorithm
{
	RTE_CRYPTO_CIPHER_NULL = 1,
	RTE_CRYPTO_CIPHER_3DES_CBC = 2,
	RTE_CRYPTO_CIPHER_3DES_CTR = 3,
	RTE_CRYPTO_CIPHER_3DES_ECB = 4,
	RTE_CRYPTO_CIPHER_AES_CBC = 5,
	RTE_CRYPTO_CIPHER_AES_CCM = 6,
	RTE_CRYPTO_CIPHER_AES_CTR = 7,
	RTE_CRYPTO_CIPHER_AES_ECB = 8,
	RTE_CRYPTO_CIPHER_AES_F8 = 9,
	RTE_CRYPTO_CIPHER_AES_GCM = 10,
	RTE_CRYPTO_CIPHER_AES_XTS = 11,
	RTE_CRYPTO_CIPHER_ARC4 = 12,
	RTE_CRYPTO_CIPHER_KASUMI_F8 = 13,
	RTE_CRYPTO_CIPHER_SNOW3G_UEA2 = 14,
	RTE_CRYPTO_CIPHER_ZUC_EEA3 = 15,
	RTE_CRYPTO_CIPHER_LIST_END = 16,
}
