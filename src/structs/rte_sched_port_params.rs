// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_sched_port_params
{
	pub name: *const c_char,

	pub socket: c_int,

	pub rate: uint32_t,

	pub mtu: uint32_t,

	pub frame_overhead: uint32_t,

	pub n_subports_per_port: uint32_t,

	pub n_pipes_per_subport: uint32_t,

	pub qsize: [uint16_t; 4usize],

	pub pipe_profiles: *mut rte_sched_pipe_params,

	pub n_pipe_profiles: uint32_t,

}

impl Default for rte_sched_port_params
{
	fn default() -> Self

	{

		unsafe { zeroed() }

	}

}

