// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C, packed)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct rte_config
{
	pub master_lcore: uint32_t,
	pub lcore_count: uint32_t,
	pub lcore_role: [rte_lcore_role_t; 128usize],
	pub process_type: rte_proc_type_t,
	pub mem_config: *mut rte_mem_config,
}

impl Clone for rte_config
{
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for rte_config
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
