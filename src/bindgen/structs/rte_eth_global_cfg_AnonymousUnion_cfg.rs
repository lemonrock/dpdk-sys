// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_eth_global_cfg_AnonymousUnion_cfg
{
	pub _bindgen_data_: [u64; 1usize],
}

impl rte_eth_global_cfg_AnonymousUnion_cfg
{
	#[inline(always)]
	pub unsafe fn gre_key_len(&mut self) -> *mut uint8_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
	#[inline(always)]
	pub unsafe fn reserved(&mut self) -> *mut uint64_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
}

impl Default for rte_eth_global_cfg_AnonymousUnion_cfg
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
