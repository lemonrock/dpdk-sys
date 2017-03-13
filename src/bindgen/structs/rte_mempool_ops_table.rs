// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_mempool_ops_table
{
	pub sl: rte_spinlock_t,
	pub num_ops: uint32_t,
	_bindgen_padding_0_: [u64; 7usize],
	pub ops: [rte_mempool_ops; 16usize],
}

impl Default for rte_mempool_ops_table
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
