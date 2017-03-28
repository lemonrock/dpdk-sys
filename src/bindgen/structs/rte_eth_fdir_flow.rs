// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_eth_fdir_flow
{
	pub _bindgen_data_: [u32; 11usize],
}

impl rte_eth_fdir_flow
{
	#[inline(always)]
	pub unsafe fn l2_flow(&mut self) -> *mut rte_eth_l2_flow
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
	#[inline(always)]
	pub unsafe fn udp4_flow(&mut self) -> *mut rte_eth_udpv4_flow
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
	#[inline(always)]
	pub unsafe fn tcp4_flow(&mut self) -> *mut rte_eth_tcpv4_flow
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
	#[inline(always)]
	pub unsafe fn sctp4_flow(&mut self) -> *mut rte_eth_sctpv4_flow
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
	#[inline(always)]
	pub unsafe fn ip4_flow(&mut self) -> *mut rte_eth_ipv4_flow
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
	#[inline(always)]
	pub unsafe fn udp6_flow(&mut self) -> *mut rte_eth_udpv6_flow
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
	#[inline(always)]
	pub unsafe fn tcp6_flow(&mut self) -> *mut rte_eth_tcpv6_flow
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
	#[inline(always)]
	pub unsafe fn sctp6_flow(&mut self) -> *mut rte_eth_sctpv6_flow
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
	#[inline(always)]
	pub unsafe fn ipv6_flow(&mut self) -> *mut rte_eth_ipv6_flow
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
	#[inline(always)]
	pub unsafe fn mac_vlan_flow(&mut self) -> *mut rte_eth_mac_vlan_flow
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
	#[inline(always)]
	pub unsafe fn tunnel_flow(&mut self) -> *mut rte_eth_tunnel_flow
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw)
	}
}

impl Default for rte_eth_fdir_flow
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
