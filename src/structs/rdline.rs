// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct rdline
{
	pub status: rdline_status,
	pub left: cirbuf,
	pub right: cirbuf,
	pub left_buf: [c_char; 514usize],
	pub right_buf: [c_char; 512usize],
	pub prompt: [c_char; 32usize],
	pub prompt_size: c_uint,
	pub kill_buf: [c_char; 512usize],
	pub kill_size: c_uint,
	pub history: cirbuf,
	pub history_buf: [c_char; 1024usize],
	pub history_cur_line: c_int,
	pub write_char: rdline_write_char_t,
	pub validate: rdline_validate_t,
	pub complete: rdline_complete_t,
	pub vt100: cmdline_vt100,
	pub opaque: *mut c_void,
}

impl Clone for rdline
{
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for rdline
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
