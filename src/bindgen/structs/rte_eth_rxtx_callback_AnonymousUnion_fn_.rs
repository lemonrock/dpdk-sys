// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_eth_rxtx_callback_AnonymousUnion_fn_
{
	pub _bindgen_data_: [u64; 1usize],
}

impl rte_eth_rxtx_callback_AnonymousUnion_fn_
{
	pub unsafe fn rx(&mut self) -> *mut rte_rx_callback_fn
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
	pub unsafe fn tx(&mut self) -> *mut rte_tx_callback_fn
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
}

impl Default for rte_eth_rxtx_callback_AnonymousUnion_fn_
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}