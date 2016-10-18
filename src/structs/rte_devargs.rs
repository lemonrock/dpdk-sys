// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_devargs
{
	pub next: AnonymousStruct30,
	pub type_: rte_devtype,
	pub _bindgen_data_1_: [u16; 16usize],
	pub args: *mut c_char,
}

impl rte_devargs
{
	pub unsafe fn pci(&mut self) -> *mut AnonymousStruct31
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
	pub unsafe fn virt(&mut self) -> *mut AnonymousStruct32
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
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
