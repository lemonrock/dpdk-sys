// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_cryptodev_info
{
	pub driver_name: *const c_char,
	pub dev_type: rte_cryptodev_type,
	pub pci_dev: *mut rte_pci_device,
	pub feature_flags: uint64_t,
	pub capabilities: *const rte_cryptodev_capabilities,
	pub max_nb_queue_pairs: c_uint,
	pub sym: AnonymousStruct29,
}

impl Default for rte_cryptodev_info
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
