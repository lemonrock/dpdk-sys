// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_vhost_avail_entries(vid: c_int, queue_id: uint16_t) -> uint16_t;
	pub fn rte_vhost_dequeue_burst(vid: c_int, queue_id: uint16_t, mbuf_pool: *mut rte_mempool, pkts: *mut *mut rte_mbuf, count: uint16_t) -> uint16_t;
	pub fn rte_vhost_driver_callback_register(arg1: *const virtio_net_device_ops) -> c_int;
	pub fn rte_vhost_driver_register(path: *const c_char, flags: uint64_t) -> c_int;
	pub fn rte_vhost_driver_session_start() -> c_int;
	pub fn rte_vhost_driver_unregister(path: *const c_char) -> c_int;
	pub fn rte_vhost_enable_guest_notification(vid: c_int, queue_id: uint16_t, enable: c_int) -> c_int;
	pub fn rte_vhost_enqueue_burst(vid: c_int, queue_id: uint16_t, pkts: *mut *mut rte_mbuf, count: uint16_t) -> uint16_t;
	pub fn rte_vhost_feature_disable(feature_mask: uint64_t) -> c_int;
	pub fn rte_vhost_feature_enable(feature_mask: uint64_t) -> c_int;
	pub fn rte_vhost_feature_get() -> uint64_t;
	pub fn rte_vhost_get_ifname(vid: c_int, buf: *mut c_char, len: size_t) -> c_int;
	pub fn rte_vhost_get_numa_node(vid: c_int) -> c_int;
	pub fn rte_vhost_get_queue_num(vid: c_int) -> uint32_t;
}
