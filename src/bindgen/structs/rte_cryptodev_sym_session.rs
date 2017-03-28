// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_cryptodev_sym_session
{
	pub _bindgen_data_1_: [u64; 2usize],
	pub _private: [c_char; 0usize],
}

impl rte_cryptodev_sym_session
{
	#[inline(always)]
	pub unsafe fn dev_id(&mut self) -> *mut uint8_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw)
	}
	#[inline(always)]
	pub unsafe fn dev_type(&mut self) -> *mut rte_cryptodev_type
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(1))
	}
	#[inline(always)]
	pub unsafe fn mp(&mut self) -> *mut *mut rte_mempool
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(5))
	}
}

impl Default for rte_cryptodev_sym_session
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
