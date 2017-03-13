// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_eth_dev_info
{
	pub pci_dev: *mut rte_pci_device,
	pub driver_name: *const c_char,
	pub if_index: c_uint,
	pub min_rx_bufsize: uint32_t,
	pub max_rx_pktlen: uint32_t,
	pub max_rx_queues: uint16_t,
	pub max_tx_queues: uint16_t,
	pub max_mac_addrs: uint32_t,
	pub max_hash_mac_addrs: uint32_t,
	pub max_vfs: uint16_t,
	pub max_vmdq_pools: uint16_t,
	pub rx_offload_capa: uint32_t,
	pub tx_offload_capa: uint32_t,
	pub reta_size: uint16_t,
	pub hash_key_size: uint8_t,
	pub flow_type_rss_offloads: uint64_t,
	pub default_rxconf: rte_eth_rxconf,
	pub default_txconf: rte_eth_txconf,
	pub vmdq_queue_base: uint16_t,
	pub vmdq_queue_num: uint16_t,
	pub vmdq_pool_base: uint16_t,
	pub rx_desc_lim: rte_eth_desc_lim,
	pub tx_desc_lim: rte_eth_desc_lim,
	pub speed_capa: uint32_t,
	pub nb_rx_queues: uint16_t,
	pub nb_tx_queues: uint16_t,
}

impl Default for rte_eth_dev_info
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
