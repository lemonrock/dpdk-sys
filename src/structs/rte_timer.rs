// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_timer
{
	pub expire: uint64_t,
	pub sl_next: [*mut rte_timer; 10usize],
	pub status: rte_timer_status,
	pub period: uint64_t,
	pub f: rte_timer_cb_t,
	pub arg: *mut c_void,
}

impl Default for rte_timer
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
