// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct AnonymousUnion4
{
	pub _bindgen_data_: [u32; 2usize],
}

impl AnonymousUnion4
{
	pub unsafe fn rss(&mut self) -> *mut uint32_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
	pub unsafe fn fdir(&mut self) -> *mut AnonymousStruct5
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
	pub unsafe fn sched(&mut self) -> *mut AnonymousStruct6
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
	pub unsafe fn usr(&mut self) -> *mut uint32_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
}

impl Default for AnonymousUnion4
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
