// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct vxlan_hdr
{
	pub vx_flags: uint32_t,
	pub vx_vni: uint32_t,
}
impl Default for vxlan_hdr
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
