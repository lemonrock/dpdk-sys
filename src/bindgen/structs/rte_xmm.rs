// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_xmm
{
	pub _bindgen_data_: [u8; 16usize],
}

impl rte_xmm
{
	#[inline(always)]
	pub unsafe fn x(&mut self) -> *mut xmm_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
	#[inline(always)]
	pub unsafe fn u8_(&mut self) -> *mut [uint8_t; 16usize]
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
	#[inline(always)]
	pub unsafe fn u16_(&mut self) -> *mut [uint16_t; 8usize]
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
	#[inline(always)]
	pub unsafe fn u32_(&mut self) -> *mut [uint32_t; 4usize]
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
	#[inline(always)]
	pub unsafe fn u64_(&mut self) -> *mut [uint64_t; 2usize]
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
	#[inline(always)]
	pub unsafe fn pd(&mut self) -> *mut [f64; 2usize]
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
}

impl Default for rte_xmm
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
