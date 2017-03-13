// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct eth_driver
{
	pub pci_drv: rte_pci_driver,
	pub eth_dev_init: eth_dev_init_t,
	pub eth_dev_uninit: eth_dev_uninit_t,
	pub dev_private_size: c_uint,
}

impl Default for eth_driver
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
