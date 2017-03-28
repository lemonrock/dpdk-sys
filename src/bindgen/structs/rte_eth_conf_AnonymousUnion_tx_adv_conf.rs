// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_eth_conf_AnonymousUnion_tx_adv_conf
{
	pub _bindgen_data_: [u32; 3usize],
}

impl rte_eth_conf_AnonymousUnion_tx_adv_conf
{
	#[inline(always)]
	pub unsafe fn vmdq_dcb_tx_conf(&mut self) -> *mut rte_eth_vmdq_dcb_tx_conf
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
	#[inline(always)]
	pub unsafe fn dcb_tx_conf(&mut self) -> *mut rte_eth_dcb_tx_conf
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
	#[inline(always)]
	pub unsafe fn vmdq_tx_conf(&mut self) -> *mut rte_eth_vmdq_tx_conf
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
}

impl Default for rte_eth_conf_AnonymousUnion_tx_adv_conf
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
