// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_pdump_disable(port: uint8_t, queue: uint16_t, flags: uint32_t) -> c_int;
	pub fn rte_pdump_disable_by_deviceid(device_id: *mut c_char, queue: uint16_t, flags: uint32_t) -> c_int;
	pub fn rte_pdump_enable(port: uint8_t, queue: uint16_t, flags: uint32_t, ring: *mut rte_ring, mp: *mut rte_mempool, filter: *mut c_void) -> c_int;
	pub fn rte_pdump_enable_by_deviceid(device_id: *mut c_char, queue: uint16_t, flags: uint32_t, ring: *mut rte_ring, mp: *mut rte_mempool, filter: *mut c_void) -> c_int;
	pub fn rte_pdump_init(path: *const c_char) -> c_int;
	pub fn rte_pdump_set_socket_dir(path: *const c_char, type_: rte_pdump_socktype) -> c_int;
	pub fn rte_pdump_uninit() -> c_int;
}
