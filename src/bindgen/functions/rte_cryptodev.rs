// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_cryptodev_callback_register(dev_id: uint8_t, event: rte_cryptodev_event_type, cb_fn: rte_cryptodev_cb_fn, cb_arg: *mut c_void) -> c_int;
	pub fn rte_cryptodev_callback_unregister(dev_id: uint8_t, event: rte_cryptodev_event_type, cb_fn: rte_cryptodev_cb_fn, cb_arg: *mut c_void) -> c_int;
	pub fn rte_cryptodev_close(dev_id: uint8_t) -> c_int;
	pub fn rte_cryptodev_configure(dev_id: uint8_t, config: *mut rte_cryptodev_config) -> c_int;
	pub fn rte_cryptodev_count() -> uint8_t;
	pub fn rte_cryptodev_count_devtype(type_: rte_cryptodev_type) -> uint8_t;
	pub fn rte_cryptodev_create_vdev(name: *const c_char, args: *const c_char) -> c_int;
	pub fn rte_cryptodev_devices_get(dev_name: *const c_char, devices: *mut uint8_t, nb_devices: uint8_t) -> uint8_t;
	pub fn rte_cryptodev_get_dev_id(name: *const c_char) -> c_int;
	pub fn rte_cryptodev_get_feature_name(flag: uint64_t) -> *const c_char;
	pub fn rte_cryptodev_info_get(dev_id: uint8_t, dev_info: *mut rte_cryptodev_info);
	pub fn rte_cryptodev_parse_vdev_init_params(params: *mut rte_crypto_vdev_init_params, input_args: *const c_char) -> c_int;
	pub fn rte_cryptodev_pci_probe(pci_drv: *mut rte_pci_driver, pci_dev: *mut rte_pci_device) -> c_int;
	pub fn rte_cryptodev_pci_remove(pci_dev: *mut rte_pci_device) -> c_int;
	pub fn rte_cryptodev_pmd_allocate(name: *const c_char, socket_id: c_int) -> *mut rte_cryptodev;
	pub fn rte_cryptodev_pmd_callback_process(dev: *mut rte_cryptodev, event: rte_cryptodev_event_type);
	pub fn rte_cryptodev_pmd_create_dev_name(name: *mut c_char, dev_name_prefix: *const c_char) -> c_int;
	pub fn rte_cryptodev_pmd_get_dev(dev_id: uint8_t) -> *mut rte_cryptodev;
	pub fn rte_cryptodev_pmd_get_named_dev(name: *const c_char) -> *mut rte_cryptodev;
	pub fn rte_cryptodev_pmd_is_valid_dev(dev_id: uint8_t) -> c_uint;
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
	pub fn rte_cryptodev_sym_capability_check_auth(capability: *const rte_cryptodev_symmetric_capability, key_size: uint16_t, digest_size: uint16_t, aad_size: uint16_t) -> c_int;
	pub fn rte_cryptodev_sym_capability_check_cipher(capability: *const rte_cryptodev_symmetric_capability, key_size: uint16_t, iv_size: uint16_t) -> c_int;
	pub fn rte_cryptodev_sym_capability_get(dev_id: uint8_t, idx: *const rte_cryptodev_sym_capability_idx) -> *const rte_cryptodev_symmetric_capability;
	pub fn rte_cryptodev_sym_session_create(dev_id: uint8_t, xform: *mut rte_crypto_sym_xform) -> *mut rte_cryptodev_sym_session;
	pub fn rte_cryptodev_sym_session_free(dev_id: uint8_t, session: *mut rte_cryptodev_sym_session) -> *mut rte_cryptodev_sym_session;
}
