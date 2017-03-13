// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_eal_dev_init() -> c_int;
	pub fn rte_eal_get_configuration() -> *mut rte_config;
	pub fn rte_eal_get_lcore_state(slave_id: c_uint) -> rte_lcore_state_t;
	pub fn rte_eal_get_physmem_layout() -> *const rte_memseg;
	pub fn rte_eal_get_physmem_size() -> uint64_t;
	pub fn rte_eal_has_hugepages() -> c_int;
	pub fn rte_eal_hpet_init(make_default: c_int) -> c_int;
	pub fn rte_eal_init(argc: c_int, argv: *mut *mut c_char) -> c_int;
	pub fn rte_eal_iopl_init() -> c_int;
	pub fn rte_eal_lcore_role(lcore_id: c_uint) -> rte_lcore_role_t;
	pub fn rte_eal_primary_proc_alive(config_file_path: *const c_char) -> c_int;
	pub fn rte_eal_process_type() -> rte_proc_type_t;
	pub fn rte_eal_remote_launch(f: lcore_function_t, arg: *mut c_void, slave_id: c_uint) -> c_int;
	pub fn rte_eal_wait_lcore(slave_id: c_uint) -> c_int;
}
