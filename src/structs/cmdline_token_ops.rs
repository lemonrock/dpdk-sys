// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct cmdline_token_ops
{
	pub parse: Option<unsafe extern "C" fn(arg1: *mut cmdline_parse_token_hdr_t, arg2: *const c_char, arg3: *mut c_void, arg4: c_uint) -> c_int>,
	pub complete_get_nb: Option<unsafe extern "C" fn(arg1: *mut cmdline_parse_token_hdr_t) -> c_int>,
	pub complete_get_elt: Option<unsafe extern "C" fn(arg1: *mut cmdline_parse_token_hdr_t, arg2: c_int, arg3: *mut c_char, arg4: c_uint) -> c_int>,
	pub get_help: Option<unsafe extern "C" fn(arg1: *mut cmdline_parse_token_hdr_t, arg2: *mut c_char, arg3: c_uint) -> c_int>,
}

impl Default for cmdline_token_ops
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
