// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_crypto_op_pool_private
{
	pub type_: rte_crypto_op_type,
	pub priv_size: uint16_t,
	_bindgen_padding_0_: [u8; 2usize],
}

impl Default for rte_crypto_op_pool_private
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
