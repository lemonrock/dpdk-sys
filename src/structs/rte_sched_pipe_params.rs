// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_sched_pipe_params
{
	pub tb_rate: uint32_t,

	pub tb_size: uint32_t,

	pub tc_rate: [uint32_t; 4usize],

	pub tc_period: uint32_t,

	pub wrr_weights: [uint8_t; 16usize],

}

impl Default for rte_sched_pipe_params
{
	fn default() -> Self

	{

		unsafe { zeroed() }

	}

}

