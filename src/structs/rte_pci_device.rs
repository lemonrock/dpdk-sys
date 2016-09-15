// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_pci_device
{
	pub next: AnonymousStruct23,
	pub addr: rte_pci_addr,
	pub id: rte_pci_id,
	pub mem_resource: [rte_pci_resource; 6usize],
	pub intr_handle: rte_intr_handle,
	pub driver: *mut rte_pci_driver,
	pub max_vfs: uint16_t,
	pub numa_node: c_int,
	pub devargs: *mut rte_devargs,
	pub kdrv: rte_kernel_driver,
}

impl Default for rte_pci_device
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
