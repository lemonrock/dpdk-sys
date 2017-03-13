// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn cmdline_complete(cl: *mut cmdline, buf: *const c_char, state: *mut c_int, dst: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_complete_get_elt_string(tk: *mut cmdline_parse_token_hdr_t, idx: c_int, dstbuf: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_complete_get_nb_string(tk: *mut cmdline_parse_token_hdr_t) -> c_int;
	pub fn cmdline_file_new(ctx: *mut cmdline_parse_ctx_t, prompt: *const c_char, path: *const c_char) -> *mut cmdline;
	pub fn cmdline_free(cl: *mut cmdline);
	pub fn cmdline_get_help_etheraddr(tk: *mut cmdline_parse_token_hdr_t, dstbuf: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_get_help_ipaddr(tk: *mut cmdline_parse_token_hdr_t, dstbuf: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_get_help_num(tk: *mut cmdline_parse_token_hdr_t, dstbuf: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_get_help_portlist(tk: *mut cmdline_parse_token_hdr_t, dstbuf: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_get_help_string(tk: *mut cmdline_parse_token_hdr_t, dstbuf: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_in(cl: *mut cmdline, buf: *const c_char, size: c_int) -> c_int;
	pub fn cmdline_interact(cl: *mut cmdline);
	pub fn cmdline_isendofcommand(c: c_char) -> c_int;
	pub fn cmdline_isendoftoken(c: c_char) -> c_int;
	pub fn cmdline_new(ctx: *mut cmdline_parse_ctx_t, prompt: *const c_char, s_in: c_int, s_out: c_int) -> *mut cmdline;
	pub fn cmdline_parse(cl: *mut cmdline, buf: *const c_char) -> c_int;
	pub fn cmdline_parse_etheraddr(tk: *mut cmdline_parse_token_hdr_t, srcbuf: *const c_char, res: *mut c_void, ressize: c_uint) -> c_int;
	pub fn cmdline_parse_ipaddr(tk: *mut cmdline_parse_token_hdr_t, srcbuf: *const c_char, res: *mut c_void, ressize: c_uint) -> c_int;
	pub fn cmdline_parse_num(tk: *mut cmdline_parse_token_hdr_t, srcbuf: *const c_char, res: *mut c_void, ressize: c_uint) -> c_int;
	pub fn cmdline_parse_portlist(tk: *mut cmdline_parse_token_hdr_t, srcbuf: *const c_char, res: *mut c_void, ressize: c_uint) -> c_int;
	pub fn cmdline_parse_string(tk: *mut cmdline_parse_token_hdr_t, srcbuf: *const c_char, res: *mut c_void, ressize: c_uint) -> c_int;
	pub fn cmdline_poll(cl: *mut cmdline) -> c_int;
	pub fn cmdline_printf(cl: *const cmdline, fmt: *const c_char, ...);
	pub fn cmdline_quit(cl: *mut cmdline);
	pub fn cmdline_set_prompt(cl: *mut cmdline, prompt: *const c_char);
	pub fn cmdline_stdin_exit(cl: *mut cmdline);
	pub fn cmdline_stdin_new(ctx: *mut cmdline_parse_ctx_t, prompt: *const c_char) -> *mut cmdline;
	pub fn cmdline_write_char(rdl: *mut rdline, c: c_char) -> c_int;
	pub fn vt100_init(vt: *mut cmdline_vt100);
	pub fn vt100_parser(vt: *mut cmdline_vt100, c: c_char) -> c_int;
}
