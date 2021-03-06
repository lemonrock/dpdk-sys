// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct tle_evq
{
	pub lock: rte_spinlock_t,
	pub nb_events: uint32_t,
	pub nb_armed: uint32_t,
	pub nb_free: uint32_t,
	pub armed: tle_evq_AnonymousStruct_armed,
	pub free: tle_evq_AnonymousStruct_free,
	_bindgen_padding_0_: [u8; 16usize],
	pub events: [tle_event; 0usize],
}

impl Default for tle_evq
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
