// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct rte_eth_vmdq_dcb_conf
{
	pub nb_queue_pools: rte_eth_nb_pools,
	pub enable_default_pool: uint8_t,
	pub default_pool: uint8_t,
	pub nb_pool_maps: uint8_t,
	pub pool_map: [AnonymousStruct39; 64usize],
	pub dcb_tc: [uint8_t; 8usize],
}

impl Clone for rte_eth_vmdq_dcb_conf
{
	#[inline(always)]
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for rte_eth_vmdq_dcb_conf
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
