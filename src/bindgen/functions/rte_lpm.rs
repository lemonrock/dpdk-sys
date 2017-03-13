// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_lpm6_add(lpm: *mut rte_lpm6, ip: *mut uint8_t, depth: uint8_t, next_hop: uint8_t) -> c_int;
	pub fn rte_lpm6_create(name: *const c_char, socket_id: c_int, config: *const rte_lpm6_config) -> *mut rte_lpm6;
	pub fn rte_lpm6_delete(lpm: *mut rte_lpm6, ip: *mut uint8_t, depth: uint8_t) -> c_int;
	pub fn rte_lpm6_delete_all(lpm: *mut rte_lpm6);
	pub fn rte_lpm6_delete_bulk_func(lpm: *mut rte_lpm6, ips: *mut [uint8_t; 16usize], depths: *mut uint8_t, n: c_uint) -> c_int;
	pub fn rte_lpm6_find_existing(name: *const c_char) -> *mut rte_lpm6;
	pub fn rte_lpm6_free(lpm: *mut rte_lpm6);
	pub fn rte_lpm6_is_rule_present(lpm: *mut rte_lpm6, ip: *mut uint8_t, depth: uint8_t, next_hop: *mut uint8_t) -> c_int;
	pub fn rte_lpm6_lookup(lpm: *const rte_lpm6, ip: *mut uint8_t, next_hop: *mut uint8_t) -> c_int;
	pub fn rte_lpm6_lookup_bulk_func(lpm: *const rte_lpm6, ips: *mut [uint8_t; 16usize], next_hops: *mut int16_t, n: c_uint) -> c_int;
	pub fn rte_lpm_add(lpm: *mut rte_lpm, ip: uint32_t, depth: uint8_t, next_hop: uint32_t) -> c_int;
	pub fn rte_lpm_add_v1604(lpm: *mut rte_lpm, ip: uint32_t, depth: uint8_t, next_hop: uint32_t) -> c_int;
	pub fn rte_lpm_add_v20(lpm: *mut rte_lpm_v20, ip: uint32_t, depth: uint8_t, next_hop: uint8_t) -> c_int;
	pub fn rte_lpm_create(name: *const c_char, socket_id: c_int, config: *const rte_lpm_config) -> *mut rte_lpm;
	pub fn rte_lpm_create_v1604(name: *const c_char, socket_id: c_int, config: *const rte_lpm_config) -> *mut rte_lpm;
	pub fn rte_lpm_create_v20(name: *const c_char, socket_id: c_int, max_rules: c_int, flags: c_int) -> *mut rte_lpm_v20;
	pub fn rte_lpm_delete(lpm: *mut rte_lpm, ip: uint32_t, depth: uint8_t) -> c_int;
	pub fn rte_lpm_delete_all(lpm: *mut rte_lpm);
	pub fn rte_lpm_delete_all_v1604(lpm: *mut rte_lpm);
	pub fn rte_lpm_delete_all_v20(lpm: *mut rte_lpm_v20);
	pub fn rte_lpm_delete_v1604(lpm: *mut rte_lpm, ip: uint32_t, depth: uint8_t) -> c_int;
	pub fn rte_lpm_delete_v20(lpm: *mut rte_lpm_v20, ip: uint32_t, depth: uint8_t) -> c_int;
	pub fn rte_lpm_find_existing(name: *const c_char) -> *mut rte_lpm;
	pub fn rte_lpm_find_existing_v1604(name: *const c_char) -> *mut rte_lpm;
	pub fn rte_lpm_find_existing_v20(name: *const c_char) -> *mut rte_lpm_v20;
	pub fn rte_lpm_free(lpm: *mut rte_lpm);
	pub fn rte_lpm_free_v1604(lpm: *mut rte_lpm);
	pub fn rte_lpm_free_v20(lpm: *mut rte_lpm_v20);
	pub fn rte_lpm_is_rule_present(lpm: *mut rte_lpm, ip: uint32_t, depth: uint8_t, next_hop: *mut uint32_t) -> c_int;
	pub fn rte_lpm_is_rule_present_v1604(lpm: *mut rte_lpm, ip: uint32_t, depth: uint8_t, next_hop: *mut uint32_t) -> c_int;
	pub fn rte_lpm_is_rule_present_v20(lpm: *mut rte_lpm_v20, ip: uint32_t, depth: uint8_t, next_hop: *mut uint8_t) -> c_int;
}
