// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_hash_add_key(h: *const rte_hash, key: *const c_void) -> int32_t;
	pub fn rte_hash_add_key_data(h: *const rte_hash, key: *const c_void, data: *mut c_void) -> c_int;
	pub fn rte_hash_add_key_with_hash(h: *const rte_hash, key: *const c_void, sig: hash_sig_t) -> int32_t;
	pub fn rte_hash_add_key_with_hash_data(h: *const rte_hash, key: *const c_void, sig: hash_sig_t, data: *mut c_void) -> int32_t;
	pub fn rte_hash_create(params: *const rte_hash_parameters) -> *mut rte_hash;
	pub fn rte_hash_del_key(h: *const rte_hash, key: *const c_void) -> int32_t;
	pub fn rte_hash_del_key_with_hash(h: *const rte_hash, key: *const c_void, sig: hash_sig_t) -> int32_t;
	pub fn rte_hash_find_existing(name: *const c_char) -> *mut rte_hash;
	pub fn rte_hash_free(h: *mut rte_hash);
	pub fn rte_hash_get_key_with_position(h: *const rte_hash, position: int32_t, key: *mut *mut c_void) -> c_int;
	pub fn rte_hash_hash(h: *const rte_hash, key: *const c_void) -> hash_sig_t;
	pub fn rte_hash_iterate(h: *const rte_hash, key: *mut *const c_void, data: *mut *mut c_void, next: *mut uint32_t) -> int32_t;
	pub fn rte_hash_lookup(h: *const rte_hash, key: *const c_void) -> int32_t;
	pub fn rte_hash_lookup_bulk(h: *const rte_hash, keys: *mut *const c_void, num_keys: uint32_t, positions: *mut int32_t) -> c_int;
	pub fn rte_hash_lookup_bulk_data(h: *const rte_hash, keys: *mut *const c_void, num_keys: uint32_t, hit_mask: *mut uint64_t, data: *mut *mut c_void) -> c_int;
	pub fn rte_hash_lookup_data(h: *const rte_hash, key: *const c_void, data: *mut *mut c_void) -> c_int;
	pub fn rte_hash_lookup_with_hash(h: *const rte_hash, key: *const c_void, sig: hash_sig_t) -> int32_t;
	pub fn rte_hash_lookup_with_hash_data(h: *const rte_hash, key: *const c_void, sig: hash_sig_t, data: *mut *mut c_void) -> c_int;
	pub fn rte_hash_reset(h: *mut rte_hash);
	pub fn rte_hash_set_cmp_func(h: *mut rte_hash, func: rte_hash_cmp_eq_t);
}
