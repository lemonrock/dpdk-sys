// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub static mut devargs_list: rte_devargs_list;
	pub static mut pci_device_list: pci_device_list;
	pub static mut pci_driver_list: pci_driver_list;
	pub static mut rte_cryptodev_globals: *mut rte_cryptodev_global;
	pub static mut rte_cryptodevs: *mut rte_cryptodev;
	pub static mut rte_cyptodev_names: *mut *const c_char;
	pub static mut rte_eth_devices: [rte_eth_dev; 0usize];
	pub static mut rte_rtm_supported: uint8_t;
}
