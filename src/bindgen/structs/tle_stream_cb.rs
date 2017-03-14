// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct tle_stream_cb
{
	pub func: Option<unsafe extern "C" fn(arg1: *mut c_void, arg2: *mut tle_stream)>,
	pub data: *mut c_void,
}

impl Default for tle_stream_cb
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
