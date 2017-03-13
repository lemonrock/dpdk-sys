// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_eth_ntuple_filter
{
	pub flags: uint16_t,
	pub dst_ip: uint32_t,
	pub dst_ip_mask: uint32_t,
	pub src_ip: uint32_t,
	pub src_ip_mask: uint32_t,
	pub dst_port: uint16_t,
	pub dst_port_mask: uint16_t,
	pub src_port: uint16_t,
	pub src_port_mask: uint16_t,
	pub proto: uint8_t,
	pub proto_mask: uint8_t,
	pub tcp_flags: uint8_t,
	pub priority: uint16_t,
	pub queue: uint16_t,
}

impl Default for rte_eth_ntuple_filter
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
