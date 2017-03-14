// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[allow(missing_debug_implementations)]
#[allow(missing_copy_implementations)]
#[derive(Copy, Clone)]
pub struct tle_dev_param
{
	pub rx_offload: uint32_t,
	pub tx_offload: uint32_t,
	pub local_addr4: in_addr,
	pub local_addr6: in6_addr,
	pub bl4: tle_bl_port,
	pub bl6: tle_bl_port,
}

impl Default for tle_dev_param
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
