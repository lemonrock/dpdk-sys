// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_crypto_sym_op
{
	pub m_src: *mut rte_mbuf,
	pub m_dst: *mut rte_mbuf,
	pub sess_type: rte_crypto_sym_op_sess_type,
	pub _bindgen_data_1_: [u64; 1usize],
	pub cipher: rte_crypto_sym_op_AnonymousStruct_cipher,
	pub auth: rte_crypto_sym_op_AnonymousStruct_auth,
}

impl rte_crypto_sym_op
{
	pub unsafe fn session(&mut self) -> *mut *mut rte_cryptodev_sym_session
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
	pub unsafe fn xform(&mut self) -> *mut *mut rte_crypto_sym_xform
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
}

impl Default for rte_crypto_sym_op
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
