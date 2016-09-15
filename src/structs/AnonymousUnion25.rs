// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct AnonymousUnion25
{
	pub _bindgen_data_: [u32; 130usize],
}

impl AnonymousUnion25
{
	pub unsafe fn enable(&mut self) -> *mut uint8_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
	pub unsafe fn global_conf(&mut self) -> *mut rte_eth_hash_global_conf
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
	pub unsafe fn input_set_conf(&mut self) -> *mut rte_eth_input_set_conf
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
}

impl Clone for AnonymousUnion25
{
	#[inline(always)]
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for AnonymousUnion25
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
