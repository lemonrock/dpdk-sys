// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_cryptodev_session
{
	pub _bindgen_data_1_: [u64; 2usize],
	pub _private: [c_char; 0usize],
}

impl rte_cryptodev_session
{
	#[inline(always)]
#[allow(trivial_casts)]
	pub fn dev_id(&mut self) -> *mut uint8_t
	{
		let raw = &mut self._bindgen_data_1_ as *mut _ as *mut u8;
		raw as *mut _
	}

	#[inline(always)]
#[allow(trivial_casts)]
	pub fn type_(&mut self) -> *mut rte_cryptodev_type
	{
		let raw = &mut self._bindgen_data_1_ as *mut _ as *mut u8;
		(unsafe { raw.offset(1) }) as *mut _
	}

	#[inline(always)]
#[allow(trivial_casts)]
	pub fn mp(&mut self) -> *mut *mut rte_mempool
	{
		let raw = &mut self._bindgen_data_1_ as *mut _ as *mut u8;
		(unsafe { raw.offset(5) }) as *mut _
	}
}

impl Default for rte_cryptodev_session
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
