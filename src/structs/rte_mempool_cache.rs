// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct rte_mempool_cache
{
	pub size: uint32_t,
	pub flushthresh: uint32_t,
	pub len: uint32_t,
	pub objs: [*mut c_void; 1536usize],
}

impl Clone for rte_mempool_cache
{
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for rte_mempool_cache
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
