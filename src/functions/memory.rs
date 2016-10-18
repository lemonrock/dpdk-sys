// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_calloc(type_: *const c_char, num: size_t, size: size_t, align: c_uint) -> *mut c_void;
	pub fn rte_calloc_socket(type_: *const c_char, num: size_t, size: size_t, align: c_uint, socket: c_int) -> *mut c_void;
	pub fn rte_free(ptr: *mut c_void);
	pub fn rte_malloc(type_: *const c_char, size: size_t, align: c_uint) -> *mut c_void;
	pub fn rte_malloc_dump_stats(f: *mut FILE, type_: *const c_char);
	pub fn rte_malloc_get_socket_stats(socket: c_int, socket_stats: *mut rte_malloc_socket_stats) -> c_int;
	pub fn rte_malloc_set_limit(type_: *const c_char, max: size_t) -> c_int;
	pub fn rte_malloc_socket(type_: *const c_char, size: size_t, align: c_uint, socket: c_int) -> *mut c_void;
	pub fn rte_malloc_validate(ptr: *const c_void, size: *mut size_t) -> c_int;
	pub fn rte_malloc_virt2phy(addr: *const c_void) -> phys_addr_t;
	pub fn rte_mbuf_sanity_check(m: *const rte_mbuf, is_header: c_int);
	pub fn rte_mem_lock_page(virt: *const c_void) -> c_int;
	pub fn rte_mem_virt2phy(virt: *const c_void) -> phys_addr_t;
	pub fn rte_memdump(f: *mut FILE, title: *const c_char, buf: *const c_void, len: c_uint);
	pub fn rte_memory_get_nchannel() -> c_uint;
	pub fn rte_memory_get_nrank() -> c_uint;
	pub fn rte_realloc(ptr: *mut c_void, size: size_t, align: c_uint) -> *mut c_void;
	pub fn rte_zmalloc(type_: *const c_char, size: size_t, align: c_uint) -> *mut c_void;
	pub fn rte_zmalloc_socket(type_: *const c_char, size: size_t, align: c_uint, socket: c_int) -> *mut c_void;
}
