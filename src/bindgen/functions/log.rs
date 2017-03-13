// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_get_log_level() -> uint32_t;
	pub fn rte_get_log_type() -> uint32_t;
	pub fn rte_log(level: uint32_t, logtype: uint32_t, format: *const c_char, ...) -> c_int;
	pub fn rte_log_cur_msg_loglevel() -> c_int;
	pub fn rte_log_cur_msg_logtype() -> c_int;
	pub fn rte_openlog_stream(f: *mut FILE) -> c_int;
	pub fn rte_set_log_level(level: uint32_t);
	pub fn rte_set_log_type(type_: uint32_t, enable: c_int);
}
