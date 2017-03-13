// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct rte_eth_dev
{
	pub rx_pkt_burst: eth_rx_burst_t,
	pub tx_pkt_burst: eth_tx_burst_t,
	pub data: *mut rte_eth_dev_data,
	pub driver: *const eth_driver,
	pub dev_ops: *const eth_dev_ops,
	pub pci_dev: *mut rte_pci_device,
	pub link_intr_cbs: rte_eth_dev_cb_list,
	pub post_rx_burst_cbs: [*mut rte_eth_rxtx_callback; 1024usize],
	pub pre_tx_burst_cbs: [*mut rte_eth_rxtx_callback; 1024usize],
	pub attached: uint8_t,
	pub dev_type: rte_eth_dev_type,
}

impl Clone for rte_eth_dev
{
	#[inline(always)]
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for rte_eth_dev
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
