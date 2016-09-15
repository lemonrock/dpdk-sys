// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct AnonymousStruct32
{
	pub rss_conf: rte_eth_rss_conf,
	pub vmdq_dcb_conf: rte_eth_vmdq_dcb_conf,
	pub dcb_rx_conf: rte_eth_dcb_rx_conf,
	pub vmdq_rx_conf: rte_eth_vmdq_rx_conf,
}

impl Clone for AnonymousStruct32
{
	#[inline(always)]
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for AnonymousStruct32
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
