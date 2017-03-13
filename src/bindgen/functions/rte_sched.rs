// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_sched_pipe_config(port: *mut rte_sched_port, subport_id: uint32_t, pipe_id: uint32_t, pipe_profile: int32_t) -> c_int;
	pub fn rte_sched_port_config(params: *mut rte_sched_port_params) -> *mut rte_sched_port;
	pub fn rte_sched_port_dequeue(port: *mut rte_sched_port, pkts: *mut *mut rte_mbuf, n_pkts: uint32_t) -> c_int;
	pub fn rte_sched_port_enqueue(port: *mut rte_sched_port, pkts: *mut *mut rte_mbuf, n_pkts: uint32_t) -> c_int;
	pub fn rte_sched_port_free(port: *mut rte_sched_port);
	pub fn rte_sched_port_get_memory_footprint(params: *mut rte_sched_port_params) -> uint32_t;
	pub fn rte_sched_port_pkt_read_color(pkt: *const rte_mbuf) -> rte_meter_color;
	pub fn rte_sched_port_pkt_read_tree_path(pkt: *const rte_mbuf, subport: *mut uint32_t, pipe: *mut uint32_t, traffic_class: *mut uint32_t, queue: *mut uint32_t);
	pub fn rte_sched_port_pkt_write(pkt: *mut rte_mbuf, subport: uint32_t, pipe: uint32_t, traffic_class: uint32_t, queue: uint32_t, color: rte_meter_color);
	pub fn rte_sched_queue_read_stats(port: *mut rte_sched_port, queue_id: uint32_t, stats: *mut rte_sched_queue_stats, qlen: *mut uint16_t) -> c_int;
	pub fn rte_sched_subport_config(port: *mut rte_sched_port, subport_id: uint32_t, params: *mut rte_sched_subport_params) -> c_int;
	pub fn rte_sched_subport_read_stats(port: *mut rte_sched_port, subport_id: uint32_t, stats: *mut rte_sched_subport_stats, tc_ov: *mut uint32_t) -> c_int;
}
