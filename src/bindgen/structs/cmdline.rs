// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct cmdline
{
	pub s_in: c_int,
	pub s_out: c_int,
	pub ctx: *mut cmdline_parse_ctx_t,
	pub rdl: rdline,
	pub prompt: [c_char; 32usize],
	pub oldterm: termios,
}

impl Clone for cmdline
{
	#[inline(always)]
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for cmdline
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
