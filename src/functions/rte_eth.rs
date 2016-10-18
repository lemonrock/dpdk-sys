// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_eth_add_first_rx_callback(port_id: uint8_t, queue_id: uint16_t, fn_: rte_rx_callback_fn, user_param: *mut c_void) -> *mut c_void;
	pub fn rte_eth_add_rx_callback(port_id: uint8_t, queue_id: uint16_t, fn_: rte_rx_callback_fn, user_param: *mut c_void) -> *mut c_void;
	pub fn rte_eth_add_tx_callback(port_id: uint8_t, queue_id: uint16_t, fn_: rte_tx_callback_fn, user_param: *mut c_void) -> *mut c_void;
	pub fn rte_eth_allmulticast_disable(port_id: uint8_t);
	pub fn rte_eth_allmulticast_enable(port_id: uint8_t);
	pub fn rte_eth_allmulticast_get(port_id: uint8_t) -> c_int;
	pub fn rte_eth_copy_pci_info(eth_dev: *mut rte_eth_dev, pci_dev: *mut rte_pci_device);
	pub fn rte_eth_dma_zone_reserve(eth_dev: *const rte_eth_dev, name: *const c_char, queue_id: uint16_t, size: size_t, align: c_uint, socket_id: c_int) -> *const rte_memzone;
	pub fn rte_eth_driver_register(eth_drv: *mut eth_driver);
	pub fn rte_eth_from_ring(r: *mut rte_ring) -> c_int;
	pub fn rte_eth_from_rings(name: *const c_char, rx_queues: *mut *mut rte_ring, nb_rx_queues: c_uint, tx_queues: *mut *mut rte_ring, nb_tx_queues: c_uint, numa_node: c_uint) -> c_int;
	pub fn rte_eth_led_off(port_id: uint8_t) -> c_int;
	pub fn rte_eth_led_on(port_id: uint8_t) -> c_int;
	pub fn rte_eth_link_get(port_id: uint8_t, link: *mut rte_eth_link);
	pub fn rte_eth_link_get_nowait(port_id: uint8_t, link: *mut rte_eth_link);
	pub fn rte_eth_macaddr_get(port_id: uint8_t, mac_addr: *mut ether_addr);
	pub fn rte_eth_mirror_rule_reset(port_id: uint8_t, rule_id: uint8_t) -> c_int;
	pub fn rte_eth_mirror_rule_set(port_id: uint8_t, mirror_conf: *mut rte_eth_mirror_conf, rule_id: uint8_t, on: uint8_t) -> c_int;
	pub fn rte_eth_promiscuous_disable(port_id: uint8_t);
	pub fn rte_eth_promiscuous_enable(port_id: uint8_t);
	pub fn rte_eth_promiscuous_get(port_id: uint8_t) -> c_int;
	pub fn rte_eth_remove_rx_callback(port_id: uint8_t, queue_id: uint16_t, user_cb: *mut rte_eth_rxtx_callback) -> c_int;
	pub fn rte_eth_remove_tx_callback(port_id: uint8_t, queue_id: uint16_t, user_cb: *mut rte_eth_rxtx_callback) -> c_int;
	pub fn rte_eth_rx_queue_info_get(port_id: uint8_t, queue_id: uint16_t, qinfo: *mut rte_eth_rxq_info) -> c_int;
	pub fn rte_eth_rx_queue_setup(port_id: uint8_t, rx_queue_id: uint16_t, nb_rx_desc: uint16_t, socket_id: c_uint, rx_conf: *const rte_eth_rxconf, mb_pool: *mut rte_mempool) -> c_int;
	pub fn rte_eth_set_queue_rate_limit(port_id: uint8_t, queue_idx: uint16_t, tx_rate: uint16_t) -> c_int;
	pub fn rte_eth_set_vf_rate_limit(port_id: uint8_t, vf: uint16_t, tx_rate: uint16_t, q_msk: uint64_t) -> c_int;
	pub fn rte_eth_speed_bitflag(speed: uint32_t, duplex: c_int) -> uint32_t;
	pub fn rte_eth_stats_get(port_id: uint8_t, stats: *mut rte_eth_stats) -> c_int;
	pub fn rte_eth_stats_reset(port_id: uint8_t);
	pub fn rte_eth_timesync_adjust_time(port_id: uint8_t, delta: int64_t) -> c_int;
	pub fn rte_eth_timesync_disable(port_id: uint8_t) -> c_int;
	pub fn rte_eth_timesync_enable(port_id: uint8_t) -> c_int;
	pub fn rte_eth_timesync_read_rx_timestamp(port_id: uint8_t, timestamp: *mut timespec, flags: uint32_t) -> c_int;
	pub fn rte_eth_timesync_read_time(port_id: uint8_t, time: *mut timespec) -> c_int;
	pub fn rte_eth_timesync_read_tx_timestamp(port_id: uint8_t, timestamp: *mut timespec) -> c_int;
	pub fn rte_eth_timesync_write_time(port_id: uint8_t, time: *const timespec) -> c_int;
	pub fn rte_eth_tx_buffer_count_callback(pkts: *mut *mut rte_mbuf, unsent: uint16_t, userdata: *mut c_void);
	pub fn rte_eth_tx_buffer_drop_callback(pkts: *mut *mut rte_mbuf, unsent: uint16_t, userdata: *mut c_void);
	pub fn rte_eth_tx_buffer_init(buffer: *mut rte_eth_dev_tx_buffer, size: uint16_t) -> c_int;
	pub fn rte_eth_tx_buffer_set_err_callback(buffer: *mut rte_eth_dev_tx_buffer, callback: buffer_tx_error_fn, userdata: *mut c_void) -> c_int;
	pub fn rte_eth_tx_queue_info_get(port_id: uint8_t, queue_id: uint16_t, qinfo: *mut rte_eth_txq_info) -> c_int;
	pub fn rte_eth_tx_queue_setup(port_id: uint8_t, tx_queue_id: uint16_t, nb_tx_desc: uint16_t, socket_id: c_uint, tx_conf: *const rte_eth_txconf) -> c_int;
	pub fn rte_eth_xstats_get(port_id: uint8_t, xstats: *mut rte_eth_xstat, n: c_uint) -> c_int;
	pub fn rte_eth_xstats_get_names(port_id: uint8_t, xstats_names: *mut rte_eth_xstat_name, size: c_uint) -> c_int;
	pub fn rte_eth_xstats_reset(port_id: uint8_t);
}
