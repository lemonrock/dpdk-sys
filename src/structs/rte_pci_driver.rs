// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_pci_driver
{
	pub next: AnonymousStruct24,
	pub name: *const c_char,
	pub devinit: pci_devinit_t,
	pub devuninit: pci_devuninit_t,
	pub id_table: *const rte_pci_id,
	pub drv_flags: uint32_t,
}

impl Default for rte_pci_driver
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
