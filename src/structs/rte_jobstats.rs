// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_jobstats
{
	pub period: uint64_t,
	pub min_period: uint64_t,
	pub max_period: uint64_t,
	pub target: int64_t,
	pub update_period_cb: rte_job_update_period_cb_t,
	pub exec_time: uint64_t,
	pub min_exec_time: uint64_t,
	pub max_exec_time: uint64_t,
	pub exec_cnt: uint64_t,
	pub name: [c_char; 32usize],
	pub context: *mut rte_jobstats_context,
}
impl Default for rte_jobstats
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
