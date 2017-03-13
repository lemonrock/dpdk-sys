// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn __rte_pktmbuf_read(m: *const rte_mbuf, off: uint32_t, len: uint32_t, buf: *mut c_void) -> *const c_void;
	pub fn rte_ctrlmbuf_init(mp: *mut rte_mempool, opaque_arg: *mut c_void, m: *mut c_void, i: c_uint);
	pub fn rte_exit(exit_code: c_int, format: *const c_char, ...);
	pub fn rte_get_hpet_cycles() -> uint64_t;
	pub fn rte_get_hpet_hz() -> uint64_t;
	pub fn rte_get_ptype_inner_l2_name(ptype: uint32_t) -> *const c_char;
	pub fn rte_get_ptype_inner_l3_name(ptype: uint32_t) -> *const c_char;
	pub fn rte_get_ptype_inner_l4_name(ptype: uint32_t) -> *const c_char;
	pub fn rte_get_ptype_l2_name(ptype: uint32_t) -> *const c_char;
	pub fn rte_get_ptype_l3_name(ptype: uint32_t) -> *const c_char;
	pub fn rte_get_ptype_l4_name(ptype: uint32_t) -> *const c_char;
	pub fn rte_get_ptype_name(ptype: uint32_t, buf: *mut c_char, buflen: size_t) -> c_int;
	pub fn rte_get_ptype_tunnel_name(ptype: uint32_t) -> *const c_char;
	pub fn rte_get_rx_ol_flag_list(mask: uint64_t, buf: *mut c_char, buflen: size_t) -> c_int;
	pub fn rte_get_tx_ol_flag_list(mask: uint64_t, buf: *mut c_char, buflen: size_t) -> c_int;
	pub fn rte_set_application_usage_hook(usage_func: rte_usage_hook_t) -> rte_usage_hook_t;
	pub fn rte_socket_id() -> c_uint;
	pub fn rte_strerror(errnum: c_int) -> *const c_char;
	pub fn rte_strsplit(string: *mut c_char, stringlen: c_int, tokens: *mut *mut c_char, maxtokens: c_int, delim: c_char) -> c_int;
}
