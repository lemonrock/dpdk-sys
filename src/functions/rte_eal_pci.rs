// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_eal_pci_detach(addr: *const rte_pci_addr) -> c_int;
	pub fn rte_eal_pci_dump(f: *mut FILE);
	pub fn rte_eal_pci_ioport_map(dev: *mut rte_pci_device, bar: c_int, p: *mut rte_pci_ioport) -> c_int;
	pub fn rte_eal_pci_ioport_read(p: *mut rte_pci_ioport, data: *mut c_void, len: size_t, offset: off_t);
	pub fn rte_eal_pci_ioport_unmap(p: *mut rte_pci_ioport) -> c_int;
	pub fn rte_eal_pci_ioport_write(p: *mut rte_pci_ioport, data: *const c_void, len: size_t, offset: off_t);
	pub fn rte_eal_pci_map_device(dev: *mut rte_pci_device) -> c_int;
	pub fn rte_eal_pci_probe() -> c_int;
	pub fn rte_eal_pci_probe_one(addr: *const rte_pci_addr) -> c_int;
	pub fn rte_eal_pci_read_config(device: *const rte_pci_device, buf: *mut c_void, len: size_t, offset: off_t) -> c_int;
	pub fn rte_eal_pci_register(driver: *mut rte_pci_driver);
	pub fn rte_eal_pci_scan() -> c_int;
	pub fn rte_eal_pci_unmap_device(dev: *mut rte_pci_device);
	pub fn rte_eal_pci_unregister(driver: *mut rte_pci_driver);
	pub fn rte_eal_pci_write_config(device: *const rte_pci_device, buf: *const c_void, len: size_t, offset: off_t) -> c_int;
}
