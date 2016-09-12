// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C, packed)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct rte_mem_config
{
	pub magic: uint32_t,
	pub nchannel: uint32_t,
	pub nrank: uint32_t,
	pub mlock: rte_rwlock_t,
	pub qlock: rte_rwlock_t,
	pub mplock: rte_rwlock_t,
	pub memzone_cnt: uint32_t,
	pub memseg: [rte_memseg; 256usize],
	pub memzone: [rte_memzone; 2560usize],
	pub tailq_head: [rte_tailq_head; 32usize],
	pub malloc_heaps: [malloc_heap; 8usize],
	pub mem_cfg_addr: uint64_t,
}

impl Clone for rte_mem_config
{
	#[inline(always)]
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for rte_mem_config
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
