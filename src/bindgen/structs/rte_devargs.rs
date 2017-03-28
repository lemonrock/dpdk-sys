// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_devargs
{
	pub next: rte_devargs_AnonymousStruct_next,
	pub type_: rte_devtype,
	pub _bindgen_data_1_: [u16; 16usize],
	pub args: *mut c_char,
}

impl rte_devargs
{
	#[inline(always)]
#[allow(trivial_casts)]
	pub fn pci(&mut self) -> *mut rte_devargs_AnonymousStruct_pci
	{
		let raw = &mut self._bindgen_data_1_ as *mut _ as *mut u8;
		raw as *mut _
	}

	#[inline(always)]
#[allow(trivial_casts)]
	pub fn virt(&mut self) -> *mut rte_devargs_AnonymousStruct_virt
	{
		let raw = &mut self._bindgen_data_1_ as *mut _ as *mut u8;
		raw as *mut _
	}
}

impl Default for rte_devargs
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
