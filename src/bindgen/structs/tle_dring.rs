// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct tle_dring
{
	pub flags: uint32_t,
	pub prod: AnonymousStruct53,
	pub cons: AnonymousStruct54,
	_bindgen_padding_0_: [u8; 24usize],
	pub dummy: tle_drb,
	_bindgen_padding_1_: [u64; 16usize],
}

impl Default for tle_dring
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
