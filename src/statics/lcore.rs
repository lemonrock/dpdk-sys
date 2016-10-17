// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub static mut lcore_config: [lcore_config; 128usize];
	static mut per_lcore__cpuset: rte_cpuset_t;
	static mut per_lcore__lcore_id: c_uint;
	static mut per_lcore__rte_errno: c_int;
}
		
#[inline(always)]
pub fn rte_cpuset() -> rte_cpuset_t
{
	unsafe { per_lcore__cpuset }
}

#[inline(always)]
pub fn rte_lcore_id() -> c_uint
{
	unsafe { per_lcore__lcore_id }
}

#[inline(always)]
pub fn rte_errno() -> c_int
{
	unsafe { per_lcore__rte_errno }
}
