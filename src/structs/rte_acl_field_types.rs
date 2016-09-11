// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_acl_field_types
{
	pub _bindgen_data_: [u64; 1usize],

}

impl rte_acl_field_types
{
	pub unsafe fn u8_(&mut self) -> *mut uint8_t

	{

		let raw: *mut u8 = transmute(&self._bindgen_data_);

		transmute(raw.offset(0))

	}

	pub unsafe fn u16_(&mut self) -> *mut uint16_t

	{

		let raw: *mut u8 = transmute(&self._bindgen_data_);

		transmute(raw.offset(0))

	}

	pub unsafe fn u32_(&mut self) -> *mut uint32_t

	{

		let raw: *mut u8 = transmute(&self._bindgen_data_);

		transmute(raw.offset(0))

	}

	pub unsafe fn u64_(&mut self) -> *mut uint64_t

	{

		let raw: *mut u8 = transmute(&self._bindgen_data_);

		transmute(raw.offset(0))

	}

}

impl Default for rte_acl_field_types
{
	fn default() -> Self

	{

		unsafe { zeroed() }

	}

}

