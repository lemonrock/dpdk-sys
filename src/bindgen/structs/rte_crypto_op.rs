// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_crypto_op
{
	pub type_: rte_crypto_op_type,
	pub status: rte_crypto_op_status,
	pub mempool: *mut rte_mempool,
	pub phys_addr: phys_addr_t,
	pub opaque_data: *mut c_void,
	pub _bindgen_data_1_: [u64; 1usize],
	_bindgen_padding_0_: [u8; 24usize],
}

impl rte_crypto_op
{
	#[inline(always)]
	pub unsafe fn sym(&mut self) -> *mut *mut rte_crypto_sym_op
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw)
	}
}

impl Default for rte_crypto_op
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
