// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct tle_drb
{
	pub next: *mut tle_drb,
	pub udata: *mut c_void,
	pub size: uint32_t,
	pub start: uint32_t,
	pub objs: [*const c_void; 0usize],
	_bindgen_padding_0_: [u64; 5usize],
}

impl Default for tle_drb
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
