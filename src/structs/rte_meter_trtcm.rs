// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_meter_trtcm
{
	pub time_tc: uint64_t,
	pub time_tp: uint64_t,
	pub tc: uint64_t,
	pub tp: uint64_t,
	pub cbs: uint64_t,
	pub pbs: uint64_t,
	pub cir_period: uint64_t,
	pub cir_bytes_per_period: uint64_t,
	pub pir_period: uint64_t,
	pub pir_bytes_per_period: uint64_t,
}
impl Default for rte_meter_trtcm
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
