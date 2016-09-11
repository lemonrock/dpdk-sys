// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct AnonymousUnion1
{
	pub _bindgen_data_: [u32; 4usize],

}

impl AnonymousUnion1
{
	pub unsafe fn ipv4(&mut self) -> *mut in_addr

	{

		let raw: *mut u8 = transmute(&self._bindgen_data_);

		transmute(raw.offset(0))

	}

	pub unsafe fn ipv6(&mut self) -> *mut in6_addr

	{

		let raw: *mut u8 = transmute(&self._bindgen_data_);

		transmute(raw.offset(0))

	}

}

impl Default for AnonymousUnion1
{
	fn default() -> Self

	{

		unsafe { zeroed() }

	}

}

