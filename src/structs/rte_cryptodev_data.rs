// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct rte_cryptodev_data
{
	pub dev_id: uint8_t,
	pub socket_id: uint8_t,
	pub name: [c_char; 64usize],
	pub _bindgen_bitfield_1_: uint8_t,
	pub session_pool: *mut rte_mempool,
	pub queue_pairs: *mut *mut c_void,
	pub nb_queue_pairs: uint16_t,
	pub dev_private: *mut c_void,
}

impl Clone for rte_cryptodev_data
{
	#[inline(always)]
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for rte_cryptodev_data
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
