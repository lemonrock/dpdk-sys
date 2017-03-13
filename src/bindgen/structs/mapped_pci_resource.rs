// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct mapped_pci_resource
{
	pub next: AnonymousStruct20,
	pub pci_addr: rte_pci_addr,
	pub path: [c_char; 4096usize],
	pub nb_maps: c_int,
	pub maps: [pci_map; 6usize],
}

impl Clone for mapped_pci_resource
{
	#[inline(always)]
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for mapped_pci_resource
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
