// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn _rte_eth_dev_callback_process(dev: *mut rte_eth_dev, event: rte_eth_event_type);
	pub fn pci_get_sysfs_path() -> *const c_char;
	pub fn pci_map_resource(requested_addr: *mut c_void, fd: c_int, offset: off_t, size: size_t, additional_flags: c_int) -> *mut c_void;
	pub fn pci_unmap_resource(requested_addr: *mut c_void, size: size_t);
	pub fn rte_ctrlmbuf_init(mp: *mut rte_mempool, opaque_arg: *mut c_void, m: *mut c_void, i: c_uint);
	pub fn rte_exit(exit_code: c_int, format: *const c_char, ...);
	pub fn rte_set_application_usage_hook(usage_func: rte_usage_hook_t) -> rte_usage_hook_t;
	pub fn rte_socket_id() -> c_uint;
	pub fn rte_strerror(errnum: c_int) -> *const c_char;
	pub fn rte_strsplit(string: *mut c_char, stringlen: c_int, tokens: *mut *mut c_char, maxtokens: c_int, delim: c_char) -> c_int;
}
