// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_eth_bond_8023ad_conf
{
	pub fast_periodic_ms: uint32_t,
	pub slow_periodic_ms: uint32_t,
	pub short_timeout_ms: uint32_t,
	pub long_timeout_ms: uint32_t,
	pub aggregate_wait_timeout_ms: uint32_t,
	pub tx_period_ms: uint32_t,
	pub rx_marker_period_ms: uint32_t,
	pub update_timeout_ms: uint32_t,
	pub slowrx_cb: rte_eth_bond_8023ad_ext_slowrx_fn,
}

impl Default for rte_eth_bond_8023ad_conf
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
