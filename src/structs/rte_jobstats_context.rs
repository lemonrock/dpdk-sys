// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_jobstats_context
{
	pub state_time: uint64_t,
	pub loop_executed_jobs: uint64_t,
	pub exec_time: uint64_t,
	pub min_exec_time: uint64_t,
	pub max_exec_time: uint64_t,
	pub management_time: uint64_t,
	pub min_management_time: uint64_t,
	pub max_management_time: uint64_t,
	pub start_time: uint64_t,
	pub job_exec_cnt: uint64_t,
	pub loop_cnt: uint64_t,
	_bindgen_padding_0_: [u64; 5usize],
}

impl Default for rte_jobstats_context
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
