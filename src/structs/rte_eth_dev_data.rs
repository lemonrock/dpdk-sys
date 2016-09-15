// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct rte_eth_dev_data
{
	pub name: [c_char; 32usize],
	pub rx_queues: *mut *mut c_void,
	pub tx_queues: *mut *mut c_void,
	pub nb_rx_queues: uint16_t,
	pub nb_tx_queues: uint16_t,
	pub sriov: rte_eth_dev_sriov,
	pub dev_private: *mut c_void,
	pub dev_link: rte_eth_link,
	pub dev_conf: rte_eth_conf,
	pub mtu: uint16_t,
	pub min_rx_buf_size: uint32_t,
	pub rx_mbuf_alloc_failed: uint64_t,
	pub mac_addrs: *mut ether_addr,
	pub mac_pool_sel: [uint64_t; 128usize],
	pub hash_mac_addrs: *mut ether_addr,
	pub port_id: uint8_t,
	pub _bindgen_bitfield_1_: uint8_t,
	pub _bindgen_bitfield_2_: uint8_t,
	pub _bindgen_bitfield_3_: uint8_t,
	pub _bindgen_bitfield_4_: uint8_t,
	pub _bindgen_bitfield_5_: uint8_t,
	pub rx_queue_state: [uint8_t; 1024usize],
	pub tx_queue_state: [uint8_t; 1024usize],
	pub dev_flags: uint32_t,
	pub kdrv: rte_kernel_driver,
	pub numa_node: c_int,
	pub drv_name: *const c_char,
}

impl Clone for rte_eth_dev_data
{
	#[inline(always)]
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for rte_eth_dev_data
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
