// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct rte_eth_vlan_mirror
{
	pub vlan_mask: uint64_t,
	pub vlan_id: [uint16_t; 64usize],
}

impl Clone for rte_eth_vlan_mirror
{
	#[inline(always)]
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for rte_eth_vlan_mirror
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
