// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_lpm_tbl_entry_v20
{
	pub _bindgen_data_1_: [u8; 1usize],
	pub __bindgen_bitfield: uint8_t,
}

impl rte_lpm_tbl_entry_v20
{
	#[inline(always)]
	#[allow(trivial_casts)]
	pub fn next_hop(&mut self) -> *mut uint8_t
	{
		let raw = &mut self._bindgen_data_1_ as *mut _ as *mut u8;
		raw as *mut _
	}

	#[inline(always)]
	#[allow(trivial_casts)]
	pub fn group_idx(&mut self) -> *mut uint8_t
	{
		let raw = &mut self._bindgen_data_1_ as *mut _ as *mut u8;
		raw as *mut _
	}
}

impl Default for rte_lpm_tbl_entry_v20
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
