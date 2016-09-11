// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub static mut cmdline_token_etheraddr_ops: cmdline_token_ops;
	pub static mut cmdline_token_ipaddr_ops: cmdline_token_ops;
	pub static mut cmdline_token_num_ops: cmdline_token_ops;
	pub static mut cmdline_token_portlist_ops: cmdline_token_ops;
	pub static mut cmdline_token_string_ops: cmdline_token_ops;
	pub static mut cmdline_vt100_commands: [*const c_char; 0usize];
	pub static mut eal_default_log_stream: *mut FILE;
	pub static mut eal_timer_source: timer_source;
	pub static mut lcore_config: [lcore_config; 128usize];
	pub static mut per_lcore__cpuset: c_void;
	pub static mut per_lcore__lcore_id: c_void;
	pub static mut per_lcore__rte_errno: c_void;
	pub static mut rte_cycles_vmware_tsc_map: c_int;
	pub static mut rte_logs: rte_logs;
	pub static mut rte_mempool_ops_table: rte_mempool_ops_table;
	pub static mut rte_port_ethdev_reader_ops: rte_port_in_ops;
	pub static mut rte_port_ethdev_writer_nodrop_ops: rte_port_out_ops;
	pub static mut rte_port_ethdev_writer_ops: rte_port_out_ops;
	pub static mut rte_port_ring_multi_reader_ops: rte_port_in_ops;
	pub static mut rte_port_ring_multi_writer_nodrop_ops: rte_port_out_ops;
	pub static mut rte_port_ring_multi_writer_ops: rte_port_out_ops;
	pub static mut rte_port_ring_reader_ipv4_frag_ops: rte_port_in_ops;
	pub static mut rte_port_ring_reader_ipv6_frag_ops: rte_port_in_ops;
	pub static mut rte_port_ring_reader_ops: rte_port_in_ops;
	pub static mut rte_port_ring_writer_ipv4_ras_ops: rte_port_out_ops;
	pub static mut rte_port_ring_writer_ipv6_ras_ops: rte_port_out_ops;
	pub static mut rte_port_ring_writer_nodrop_ops: rte_port_out_ops;
	pub static mut rte_port_ring_writer_ops: rte_port_out_ops;
	pub static mut rte_port_sched_reader_ops: rte_port_in_ops;
	pub static mut rte_port_sched_writer_ops: rte_port_out_ops;
	pub static mut rte_port_sink_ops: rte_port_out_ops;
	pub static mut rte_port_source_ops: rte_port_in_ops;
	pub static mut rte_power_freq_down: rte_power_freq_change_t;
	pub static mut rte_power_freq_max: rte_power_freq_change_t;
	pub static mut rte_power_freq_min: rte_power_freq_change_t;
	pub static mut rte_power_freq_up: rte_power_freq_change_t;
	pub static mut rte_power_freqs: rte_power_freqs_t;
	pub static mut rte_power_get_freq: rte_power_get_freq_t;
	pub static mut rte_power_set_freq: rte_power_set_freq_t;
	pub static mut rte_red_log2_1_minus_Wq: [uint16_t; 12usize];
	pub static mut rte_red_pow2_frac_inv: [uint16_t; 16usize];
	pub static mut rte_red_rand_seed: uint32_t;
	pub static mut rte_red_rand_val: uint32_t;
	pub static mut rte_rtm_supported: uint8_t;
	pub static mut rte_table_acl_ops: rte_table_ops;
	pub static mut rte_table_array_ops: rte_table_ops;
	pub static mut rte_table_hash_ext_dosig_ops: rte_table_ops;
	pub static mut rte_table_hash_ext_ops: rte_table_ops;
	pub static mut rte_table_hash_key16_ext_dosig_ops: rte_table_ops;
	pub static mut rte_table_hash_key16_ext_ops: rte_table_ops;
	pub static mut rte_table_hash_key16_lru_dosig_ops: rte_table_ops;
	pub static mut rte_table_hash_key16_lru_ops: rte_table_ops;
	pub static mut rte_table_hash_key32_ext_ops: rte_table_ops;
	pub static mut rte_table_hash_key32_lru_ops: rte_table_ops;
	pub static mut rte_table_hash_key8_ext_dosig_ops: rte_table_ops;
	pub static mut rte_table_hash_key8_ext_ops: rte_table_ops;
	pub static mut rte_table_hash_key8_lru_dosig_ops: rte_table_ops;
	pub static mut rte_table_hash_key8_lru_ops: rte_table_ops;
	pub static mut rte_table_hash_lru_dosig_ops: rte_table_ops;
	pub static mut rte_table_hash_lru_ops: rte_table_ops;
	pub static mut rte_table_lpm_ipv6_ops: rte_table_ops;
	pub static mut rte_table_lpm_ops: rte_table_ops;
	pub static mut rte_table_stub_ops: rte_table_ops;
}
