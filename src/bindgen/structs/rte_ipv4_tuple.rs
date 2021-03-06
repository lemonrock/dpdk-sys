// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_ipv4_tuple
{
	pub src_addr: uint32_t,
	pub dst_addr: uint32_t,
	pub _bindgen_data_1_: [u32; 1usize],
}

impl rte_ipv4_tuple
{
	#[inline(always)]
	#[allow(trivial_casts)]
	pub fn dport(&mut self) -> *mut uint16_t
	{
		let raw = &mut self._bindgen_data_1_ as *mut _ as *mut u8;
		raw as *mut _
	}

	#[inline(always)]
	#[allow(trivial_casts)]
	pub fn sport(&mut self) -> *mut uint16_t
	{
		let raw = &mut self._bindgen_data_1_ as *mut _ as *mut u8;
		(unsafe { raw.offset(2) }) as *mut _
	}

	#[inline(always)]
	#[allow(trivial_casts)]
	pub fn sctp_tag(&mut self) -> *mut uint32_t
	{
		let raw = &mut self._bindgen_data_1_ as *mut _ as *mut u8;
		raw as *mut _
	}
}

impl Default for rte_ipv4_tuple
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
