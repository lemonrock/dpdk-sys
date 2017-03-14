// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct rte_eth_conf
{
	pub link_speeds: uint32_t,
	pub rxmode: rte_eth_rxmode,
	pub txmode: rte_eth_txmode,
	pub lpbk_mode: uint32_t,
	pub rx_adv_conf: rte_eth_conf_AnonymousStruct_rx_adv_conf,
	pub tx_adv_conf: rte_eth_conf_AnonymousUnion_tx_adv_conf,
	pub dcb_capability_en: uint32_t,
	pub fdir_conf: rte_fdir_conf,
	pub intr_conf: rte_intr_conf,
}

impl Clone for rte_eth_conf
{
	#[inline(always)]
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for rte_eth_conf
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
