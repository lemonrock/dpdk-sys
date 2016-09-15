// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_eth_tunnel_filter_conf
{
	pub outer_mac: ether_addr,
	pub inner_mac: ether_addr,
	pub inner_vlan: uint16_t,
	pub ip_type: rte_tunnel_iptype,
	pub ip_addr: AnonymousUnion22,
	pub filter_type: uint16_t,
	pub tunnel_type: rte_eth_tunnel_type,
	pub tenant_id: uint32_t,
	pub queue_id: uint16_t,
}

impl Default for rte_eth_tunnel_filter_conf
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
