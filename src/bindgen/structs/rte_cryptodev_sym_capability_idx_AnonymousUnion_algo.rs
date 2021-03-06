// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_cryptodev_sym_capability_idx_AnonymousUnion_algo
{
	pub _bindgen_data_: [u32; 1usize],
}

impl rte_cryptodev_sym_capability_idx_AnonymousUnion_algo
{
	#[inline(always)]
	#[allow(trivial_casts)]
	pub fn cipher(&mut self) -> *mut rte_crypto_cipher_algorithm
	{
		let raw = &mut self._bindgen_data_ as *mut _ as *mut u8;
		raw as *mut _
	}

	#[inline(always)]
	#[allow(trivial_casts)]
	pub fn auth(&mut self) -> *mut rte_crypto_auth_algorithm
	{
		let raw = &mut self._bindgen_data_ as *mut _ as *mut u8;
		raw as *mut _
	}
}

impl Default for rte_cryptodev_sym_capability_idx_AnonymousUnion_algo
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
