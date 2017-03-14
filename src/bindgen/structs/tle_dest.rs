// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct tle_dest
{
	pub head_mp: *mut rte_mempool,
	pub dev: *mut tle_dev,
	pub mtu: uint16_t,
	pub l2_len: uint8_t,
	pub l3_len: uint8_t,
	pub hdr: [uint8_t; 96usize],
}

impl Clone for tle_dest
{
	#[inline(always)]
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for tle_dest
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
