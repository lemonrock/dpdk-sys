// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rdline_add_history(rdl: *mut rdline, buf: *const c_char) -> c_int;
	pub fn rdline_char_in(rdl: *mut rdline, c: c_char) -> c_int;
	pub fn rdline_clear_history(rdl: *mut rdline);
	pub fn rdline_get_buffer(rdl: *mut rdline) -> *const c_char;
	pub fn rdline_get_history_item(rdl: *mut rdline, i: c_uint) -> *mut c_char;
	pub fn rdline_init(rdl: *mut rdline, write_char: rdline_write_char_t, validate: rdline_validate_t, complete: rdline_complete_t) -> c_int;
	pub fn rdline_newline(rdl: *mut rdline, prompt: *const c_char);
	pub fn rdline_quit(rdl: *mut rdline);
	pub fn rdline_redisplay(rdl: *mut rdline);
	pub fn rdline_reset(rdl: *mut rdline);
	pub fn rdline_restart(rdl: *mut rdline);
	pub fn rdline_stop(rdl: *mut rdline);
}
