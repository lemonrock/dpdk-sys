// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_cryptodev_symmetric_capability_AnonymousStruct_cipher
{
	pub algo: rte_crypto_cipher_algorithm,
	pub block_size: uint16_t,
	pub key_size: rte_crypto_param_range,
	pub iv_size: rte_crypto_param_range,
}

impl Default for rte_cryptodev_symmetric_capability_AnonymousStruct_cipher
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
