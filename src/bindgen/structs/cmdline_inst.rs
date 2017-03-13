// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct cmdline_inst
{
	pub f: Option<unsafe extern "C" fn(arg1: *mut c_void, arg2: *mut cmdline, arg3: *mut c_void)>,
	pub data: *mut c_void,
	pub help_str: *const c_char,
	pub tokens: [*mut cmdline_parse_token_hdr_t; 0usize],
}

impl Default for cmdline_inst
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
