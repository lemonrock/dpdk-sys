// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C, packed)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct slow_protocol_frame
{
	pub eth_hdr: ether_hdr,
	pub slow_protocol: slow_protocol,
}

impl Clone for slow_protocol_frame
{
	#[inline(always)]
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for slow_protocol_frame
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
