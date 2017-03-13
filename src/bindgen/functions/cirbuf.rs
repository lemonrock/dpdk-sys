// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn cirbuf_add_buf_head(cbuf: *mut cirbuf, c: *const c_char, n: c_uint) -> c_int;
	pub fn cirbuf_add_buf_tail(cbuf: *mut cirbuf, c: *const c_char, n: c_uint) -> c_int;
	pub fn cirbuf_add_head(cbuf: *mut cirbuf, c: c_char);
	pub fn cirbuf_add_head_safe(cbuf: *mut cirbuf, c: c_char) -> c_int;
	pub fn cirbuf_add_tail(cbuf: *mut cirbuf, c: c_char);
	pub fn cirbuf_add_tail_safe(cbuf: *mut cirbuf, c: c_char) -> c_int;
	pub fn cirbuf_align_left(cbuf: *mut cirbuf) -> c_int;
	pub fn cirbuf_align_right(cbuf: *mut cirbuf) -> c_int;
	pub fn cirbuf_del_buf_head(cbuf: *mut cirbuf, size: c_uint) -> c_int;
	pub fn cirbuf_del_buf_tail(cbuf: *mut cirbuf, size: c_uint) -> c_int;
	pub fn cirbuf_del_head(cbuf: *mut cirbuf);
	pub fn cirbuf_del_head_safe(cbuf: *mut cirbuf) -> c_int;
	pub fn cirbuf_del_tail(cbuf: *mut cirbuf);
	pub fn cirbuf_del_tail_safe(cbuf: *mut cirbuf) -> c_int;
	pub fn cirbuf_get_buf_head(cbuf: *mut cirbuf, c: *mut c_char, size: c_uint) -> c_int;
	pub fn cirbuf_get_buf_tail(cbuf: *mut cirbuf, c: *mut c_char, size: c_uint) -> c_int;
	pub fn cirbuf_get_head(cbuf: *mut cirbuf) -> c_char;
	pub fn cirbuf_get_tail(cbuf: *mut cirbuf) -> c_char;
	pub fn cirbuf_init(cbuf: *mut cirbuf, buf: *mut c_char, start: c_uint, maxlen: c_uint) -> c_int;
}
