// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_pci_driver_AnonymousStruct_next
{
	pub tqe_next: *mut rte_pci_driver,
	pub tqe_prev: *mut *mut rte_pci_driver,
}

impl Default for rte_pci_driver_AnonymousStruct_next
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
