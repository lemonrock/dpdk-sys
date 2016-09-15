// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn _rte_eth_dev_callback_process(dev: *mut rte_eth_dev, event: rte_eth_event_type);
	pub fn pci_get_sysfs_path() -> *const c_char;
	pub fn pci_map_resource(requested_addr: *mut c_void, fd: c_int, offset: off_t, size: size_t, additional_flags: c_int) -> *mut c_void;
	pub fn pci_unmap_resource(requested_addr: *mut c_void, size: size_t);
	pub fn rte_cryptodev_callback_register(dev_id: uint8_t, event: rte_cryptodev_event_type, cb_fn: rte_cryptodev_cb_fn, cb_arg: *mut c_void) -> c_int;
	pub fn rte_cryptodev_callback_unregister(dev_id: uint8_t, event: rte_cryptodev_event_type, cb_fn: rte_cryptodev_cb_fn, cb_arg: *mut c_void) -> c_int;
	pub fn rte_cryptodev_close(dev_id: uint8_t) -> c_int;
	pub fn rte_cryptodev_configure(dev_id: uint8_t, config: *mut rte_cryptodev_config) -> c_int;
	pub fn rte_cryptodev_count() -> uint8_t;
	pub fn rte_cryptodev_count_devtype(type_: rte_cryptodev_type) -> uint8_t;
	pub fn rte_cryptodev_create_vdev(name: *const c_char, args: *const c_char) -> c_int;
	pub fn rte_cryptodev_get_dev_id(name: *const c_char) -> c_int;
	pub fn rte_cryptodev_get_feature_name(flag: uint64_t) -> *const c_char;
	pub fn rte_cryptodev_info_get(dev_id: uint8_t, dev_info: *mut rte_cryptodev_info);
	pub fn rte_cryptodev_parse_vdev_init_params(params: *mut rte_crypto_vdev_init_params, input_args: *const c_char) -> c_int;
	pub fn rte_cryptodev_pmd_allocate(name: *const c_char, type_: pmd_type, socket_id: c_int) -> *mut rte_cryptodev;
	pub fn rte_cryptodev_pmd_callback_process(dev: *mut rte_cryptodev, event: rte_cryptodev_event_type);
	pub fn rte_cryptodev_pmd_driver_register(crypto_drv: *mut rte_cryptodev_driver, type_: pmd_type) -> c_int;
	pub fn rte_cryptodev_pmd_release_device(cryptodev: *mut rte_cryptodev) -> c_int;
	pub fn rte_cryptodev_pmd_virtual_dev_init(name: *const c_char, dev_private_size: size_t, socket_id: c_int) -> *mut rte_cryptodev;
	pub fn rte_cryptodev_queue_pair_count(dev_id: uint8_t) -> uint16_t;
	pub fn rte_cryptodev_queue_pair_setup(dev_id: uint8_t, queue_pair_id: uint16_t, qp_conf: *const rte_cryptodev_qp_conf, socket_id: c_int) -> c_int;
	pub fn rte_cryptodev_queue_pair_start(dev_id: uint8_t, queue_pair_id: uint16_t) -> c_int;
	pub fn rte_cryptodev_queue_pair_stop(dev_id: uint8_t, queue_pair_id: uint16_t) -> c_int;
	pub fn rte_cryptodev_socket_id(dev_id: uint8_t) -> c_int;
	pub fn rte_cryptodev_start(dev_id: uint8_t) -> c_int;
	pub fn rte_cryptodev_stats_get(dev_id: uint8_t, stats: *mut rte_cryptodev_stats) -> c_int;
	pub fn rte_cryptodev_stats_reset(dev_id: uint8_t);
	pub fn rte_cryptodev_stop(dev_id: uint8_t);
	pub fn rte_cryptodev_sym_session_create(dev_id: uint8_t, xform: *mut rte_crypto_sym_xform) -> *mut rte_cryptodev_sym_session;
	pub fn rte_cryptodev_sym_session_free(dev_id: uint8_t, session: *mut rte_cryptodev_sym_session) -> *mut rte_cryptodev_sym_session;
	pub fn rte_ctrlmbuf_init(mp: *mut rte_mempool, opaque_arg: *mut c_void, m: *mut c_void, i: c_uint);
	pub fn rte_exit(exit_code: c_int, format: *const c_char, ...);
	pub fn rte_set_application_usage_hook(usage_func: rte_usage_hook_t) -> rte_usage_hook_t;
	pub fn rte_socket_id() -> c_uint;
	pub fn rte_strerror(errnum: c_int) -> *const c_char;
	pub fn rte_strsplit(string: *mut c_char, stringlen: c_int, tokens: *mut *mut c_char, maxtokens: c_int, delim: c_char) -> c_int;
}
