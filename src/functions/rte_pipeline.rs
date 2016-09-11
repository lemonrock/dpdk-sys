// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_pipeline_ah_packet_drop(p: *mut rte_pipeline, pkts_mask: uint64_t) -> c_int;
	pub fn rte_pipeline_ah_packet_hijack(p: *mut rte_pipeline, pkts_mask: uint64_t) -> c_int;
	pub fn rte_pipeline_check(p: *mut rte_pipeline) -> c_int;
	pub fn rte_pipeline_create(params: *mut rte_pipeline_params) -> *mut rte_pipeline;
	pub fn rte_pipeline_flush(p: *mut rte_pipeline) -> c_int;
	pub fn rte_pipeline_free(p: *mut rte_pipeline) -> c_int;
	pub fn rte_pipeline_port_in_connect_to_table(p: *mut rte_pipeline, port_id: uint32_t, table_id: uint32_t) -> c_int;
	pub fn rte_pipeline_port_in_create(p: *mut rte_pipeline, params: *mut rte_pipeline_port_in_params, port_id: *mut uint32_t) -> c_int;
	pub fn rte_pipeline_port_in_disable(p: *mut rte_pipeline, port_id: uint32_t) -> c_int;
	pub fn rte_pipeline_port_in_enable(p: *mut rte_pipeline, port_id: uint32_t) -> c_int;
	pub fn rte_pipeline_port_in_stats_read(p: *mut rte_pipeline, port_id: uint32_t, stats: *mut rte_pipeline_port_in_stats, clear: c_int) -> c_int;
	pub fn rte_pipeline_port_out_create(p: *mut rte_pipeline, params: *mut rte_pipeline_port_out_params, port_id: *mut uint32_t) -> c_int;
	pub fn rte_pipeline_port_out_packet_insert(p: *mut rte_pipeline, port_id: uint32_t, pkt: *mut rte_mbuf) -> c_int;
	pub fn rte_pipeline_port_out_stats_read(p: *mut rte_pipeline, port_id: uint32_t, stats: *mut rte_pipeline_port_out_stats, clear: c_int) -> c_int;
	pub fn rte_pipeline_run(p: *mut rte_pipeline) -> c_int;
	pub fn rte_pipeline_table_create(p: *mut rte_pipeline, params: *mut rte_pipeline_table_params, table_id: *mut uint32_t) -> c_int;
	pub fn rte_pipeline_table_default_entry_add(p: *mut rte_pipeline, table_id: uint32_t, default_entry: *mut rte_pipeline_table_entry, default_entry_ptr: *mut *mut rte_pipeline_table_entry) -> c_int;
	pub fn rte_pipeline_table_default_entry_delete(p: *mut rte_pipeline, table_id: uint32_t, entry: *mut rte_pipeline_table_entry) -> c_int;
	pub fn rte_pipeline_table_entry_add(p: *mut rte_pipeline, table_id: uint32_t, key: *mut c_void, entry: *mut rte_pipeline_table_entry, key_found: *mut c_int, entry_ptr: *mut *mut rte_pipeline_table_entry) -> c_int;
	pub fn rte_pipeline_table_entry_add_bulk(p: *mut rte_pipeline, table_id: uint32_t, keys: *mut *mut c_void, entries: *mut *mut rte_pipeline_table_entry, n_keys: uint32_t, key_found: *mut c_int, entries_ptr: *mut *mut rte_pipeline_table_entry) -> c_int;
	pub fn rte_pipeline_table_entry_delete(p: *mut rte_pipeline, table_id: uint32_t, key: *mut c_void, key_found: *mut c_int, entry: *mut rte_pipeline_table_entry) -> c_int;
	pub fn rte_pipeline_table_entry_delete_bulk(p: *mut rte_pipeline, table_id: uint32_t, keys: *mut *mut c_void, n_keys: uint32_t, key_found: *mut c_int, entries: *mut *mut rte_pipeline_table_entry) -> c_int;
	pub fn rte_pipeline_table_stats_read(p: *mut rte_pipeline, table_id: uint32_t, stats: *mut rte_pipeline_table_stats, clear: c_int) -> c_int;
}
