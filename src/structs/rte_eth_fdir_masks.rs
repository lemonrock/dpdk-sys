// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_eth_fdir_masks
{
	pub vlan_tci_mask: uint16_t,
	pub ipv4_mask: rte_eth_ipv4_flow,
	pub ipv6_mask: rte_eth_ipv6_flow,
	pub src_port_mask: uint16_t,
	pub dst_port_mask: uint16_t,
	pub mac_addr_byte_mask: uint8_t,
	pub tunnel_id_mask: uint32_t,
	pub tunnel_type_mask: uint8_t,
}

impl Default for rte_eth_fdir_masks
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
