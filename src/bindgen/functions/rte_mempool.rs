// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_mempool_audit(mp: *mut rte_mempool);
	pub fn rte_mempool_avail_count(mp: *const rte_mempool) -> c_uint;
	pub fn rte_mempool_cache_create(size: uint32_t, socket_id: c_int) -> *mut rte_mempool_cache;
	pub fn rte_mempool_cache_free(cache: *mut rte_mempool_cache);
	pub fn rte_mempool_calc_obj_size(elt_size: uint32_t, flags: uint32_t, sz: *mut rte_mempool_objsz) -> uint32_t;
	pub fn rte_mempool_check_cookies(mp: *const rte_mempool, obj_table_const: *const *mut c_void, n: c_uint, free: c_int);
	pub fn rte_mempool_create(name: *const c_char, n: c_uint, elt_size: c_uint, cache_size: c_uint, private_data_size: c_uint, mp_init: rte_mempool_ctor_t, mp_init_arg: *mut c_void, obj_init: rte_mempool_obj_cb_t, obj_init_arg: *mut c_void, socket_id: c_int, flags: c_uint) -> *mut rte_mempool;
	pub fn rte_mempool_create_empty(name: *const c_char, n: c_uint, elt_size: c_uint, cache_size: c_uint, private_data_size: c_uint, socket_id: c_int, flags: c_uint) -> *mut rte_mempool;
	pub fn rte_mempool_dump(f: *mut FILE, mp: *mut rte_mempool);
	pub fn rte_mempool_free(mp: *mut rte_mempool);
	pub fn rte_mempool_in_use_count(mp: *const rte_mempool) -> c_uint;
	pub fn rte_mempool_list_dump(f: *mut FILE);
	pub fn rte_mempool_lookup(name: *const c_char) -> *mut rte_mempool;
	pub fn rte_mempool_mem_iter(mp: *mut rte_mempool, mem_cb: rte_mempool_mem_cb_t, mem_cb_arg: *mut c_void) -> uint32_t;
	pub fn rte_mempool_obj_iter(mp: *mut rte_mempool, obj_cb: rte_mempool_obj_cb_t, obj_cb_arg: *mut c_void) -> uint32_t;
	pub fn rte_mempool_ops_alloc(mp: *mut rte_mempool) -> c_int;
	pub fn rte_mempool_ops_free(mp: *mut rte_mempool);
	pub fn rte_mempool_ops_get_count(mp: *const rte_mempool) -> c_uint;
	pub fn rte_mempool_populate_anon(mp: *mut rte_mempool) -> c_int;
	pub fn rte_mempool_populate_default(mp: *mut rte_mempool) -> c_int;
	pub fn rte_mempool_populate_phys(mp: *mut rte_mempool, vaddr: *mut c_char, paddr: phys_addr_t, len: size_t, free_cb: rte_mempool_memchunk_free_cb_t, opaque: *mut c_void) -> c_int;
	pub fn rte_mempool_populate_phys_tab(mp: *mut rte_mempool, vaddr: *mut c_char, paddr: *mut phys_addr_t, pg_num: uint32_t, pg_shift: uint32_t, free_cb: rte_mempool_memchunk_free_cb_t, opaque: *mut c_void) -> c_int;
	pub fn rte_mempool_populate_virt(mp: *mut rte_mempool, addr: *mut c_char, len: size_t, pg_sz: size_t, free_cb: rte_mempool_memchunk_free_cb_t, opaque: *mut c_void) -> c_int;
	pub fn rte_mempool_register_ops(ops: *const rte_mempool_ops) -> c_int;
	pub fn rte_mempool_set_ops_byname(mp: *mut rte_mempool, name: *const c_char, pool_config: *mut c_void) -> c_int;
	pub fn rte_mempool_walk(func: Option<unsafe extern "C" fn(arg1: *mut rte_mempool, arg: *mut c_void)>, arg: *mut c_void);
	pub fn rte_mempool_xmem_create(name: *const c_char, n: c_uint, elt_size: c_uint, cache_size: c_uint, private_data_size: c_uint, mp_init: rte_mempool_ctor_t, mp_init_arg: *mut c_void, obj_init: rte_mempool_obj_cb_t, obj_init_arg: *mut c_void, socket_id: c_int, flags: c_uint, vaddr: *mut c_void, paddr: *mut phys_addr_t, pg_num: uint32_t, pg_shift: uint32_t) -> *mut rte_mempool;
	pub fn rte_mempool_xmem_size(elt_num: uint32_t, total_elt_sz: size_t, pg_shift: uint32_t) -> size_t;
	pub fn rte_mempool_xmem_usage(vaddr: *mut c_void, elt_num: uint32_t, total_elt_sz: size_t, paddr: *mut phys_addr_t, pg_num: uint32_t, pg_shift: uint32_t) -> ssize_t;
}
