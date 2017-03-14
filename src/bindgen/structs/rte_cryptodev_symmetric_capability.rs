// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_cryptodev_symmetric_capability
{
	pub xform_type: rte_crypto_sym_xform_type,
	pub _bindgen_data_1_: [u32; 6usize],
}

impl rte_cryptodev_symmetric_capability
{
	pub unsafe fn auth(&mut self) -> *mut rte_cryptodev_symmetric_capability_AnonymousStruct_auth
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
	pub unsafe fn cipher(&mut self) -> *mut rte_cryptodev_symmetric_capability_AnonymousStruct_cipher
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
}

impl Default for rte_cryptodev_symmetric_capability
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
