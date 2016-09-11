// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.



#![allow(non_camel_case_types)]

extern crate core;
use ::core::default::Default;
use ::core::option::Option;
use ::core::mem::zeroed;
use ::core::mem::transmute;
use ::core::clone::Clone;

use ::std::os::raw::c_char;
use ::std::os::raw::c_int;
use ::std::os::raw::c_longlong;
use ::std::os::raw::c_uint;
use ::std::os::raw::c_void;

extern crate libc;
use ::libc::size_t;
use ::libc::ssize_t;
use ::libc::uint8_t;
use ::libc::uint16_t;
use ::libc::uint32_t;
use ::libc::uint64_t;
use ::libc::int16_t;
use ::libc::int32_t;
use ::libc::int64_t;
use ::libc::FILE;
use ::libc::in_addr;
use ::libc::in6_addr;
use ::libc::termios;
use ::libc::pthread_t;
use ::libc::cpu_set_t;


#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct __m128i
{
	a: u64,
	b: u64,
}

pub type va_list = __builtin_va_list;

pub type __builtin_va_list = [__va_list_tag; 1usize];

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct __va_list_tag
{
	pub gp_offset: c_uint,
	pub fp_offset: c_uint,
	pub overflow_arg_area: *mut c_void,
	pub reg_save_area: *mut c_void,
}

impl Default for __va_list_tag
{
    fn default() -> Self
	{
		unsafe { zeroed() }
	}
}


#[link(name = "dpdk")]
extern "C"
{
}

#[link(name = "ethdev")]
extern "C"
{
}

#[link(name = "rte_acl")]
extern "C"
{
}

#[link(name = "rte_cfgfile")]
extern "C"
{
}

#[link(name = "rte_cmdline")]
extern "C"
{
}

#[link(name = "rte_cryptodev")]
extern "C"
{
}

#[link(name = "rte_distributor")]
extern "C"
{
}

#[link(name = "rte_eal")]
extern "C"
{
}

#[link(name = "rte_hash")]
extern "C"
{
}

#[link(name = "rte_ip_frag")]
extern "C"
{
}

#[link(name = "rte_jobstats")]
extern "C"
{
}

#[link(name = "rte_kvargs")]
extern "C"
{
}

#[link(name = "rte_lpm")]
extern "C"
{
}

#[link(name = "rte_mbuf")]
extern "C"
{
}

#[link(name = "rte_mempool")]
extern "C"
{
}

#[link(name = "rte_meter")]
extern "C"
{
}

#[link(name = "rte_pdump")]
extern "C"
{
}

#[link(name = "rte_pipeline")]
extern "C"
{
}

#[link(name = "rte_pmd_af_packet")]
extern "C"
{
}

#[link(name = "rte_pmd_bond")]
extern "C"
{
}

#[link(name = "rte_pmd_null")]
extern "C"
{
}

#[link(name = "rte_pmd_null_crypto")]
extern "C"
{
}

#[link(name = "rte_pmd_ring")]
extern "C"
{
}

#[link(name = "rte_port")]
extern "C"
{
}

#[link(name = "rte_power")]
extern "C"
{
}

#[link(name = "rte_reorder")]
extern "C"
{
}

#[link(name = "rte_ring")]
extern "C"
{
}

#[link(name = "rte_sched")]
extern "C"
{
}

#[link(name = "rte_table")]
extern "C"
{
}

#[link(name = "rte_timer")]
extern "C"
{
}


// Constants
include!("constants.rs");


// Statics
include!("statics.rs");


// Functions
include!("functions.rs");


// Types
include!("types/MARKER.rs");
include!("types/MARKER64.rs");
include!("types/MARKER8.rs");
include!("types/arg_handler_t.rs");
include!("types/cmdline_fixed_string_t.rs");
include!("types/cmdline_ipaddr_t.rs");
include!("types/cmdline_multi_string_t.rs");
include!("types/cmdline_parse_ctx_t.rs");
include!("types/cmdline_parse_inst_t.rs");
include!("types/cmdline_parse_token_etheraddr_t.rs");
include!("types/cmdline_parse_token_hdr_t.rs");
include!("types/cmdline_parse_token_ipaddr_t.rs");
include!("types/cmdline_parse_token_num_t.rs");
include!("types/cmdline_parse_token_portlist_t.rs");
include!("types/cmdline_parse_token_string_t.rs");
include!("types/cmdline_portlist_t.rs");
include!("types/hash_sig_t.rs");
include!("types/lcore_function_t.rs");
include!("types/phys_addr_t.rs");
include!("types/rdline_complete_t.rs");
include!("types/rdline_validate_t.rs");
include!("types/rdline_write_char_t.rs");
include!("types/rte_cpuset_t.rs");
include!("types/rte_dev_init_t.rs");
include!("types/rte_dev_uninit_t.rs");
include!("types/rte_eal_alarm_callback.rs");
include!("types/rte_fbk_hash_fn.rs");
include!("types/rte_hash_cmp_eq_t.rs");
include!("types/rte_hash_function.rs");
include!("types/rte_intr_callback_fn.rs");
include!("types/rte_intr_event_cb_t.rs");
include!("types/rte_job_update_period_cb_t.rs");
include!("types/rte_keepalive_failure_callback_t.rs");
include!("types/rte_keepalive_relay_callback_t.rs");
include!("types/rte_mempool_alloc_t.rs");
include!("types/rte_mempool_ctor_t.rs");
include!("types/rte_mempool_dequeue_t.rs");
include!("types/rte_mempool_enqueue_t.rs");
include!("types/rte_mempool_free_t.rs");
include!("types/rte_mempool_get_count.rs");
include!("types/rte_mempool_mem_cb_t.rs");
include!("types/rte_mempool_memchunk_free_cb_t.rs");
include!("types/rte_mempool_obj_cb_t.rs");
include!("types/rte_mempool_obj_ctor_t.rs");
include!("types/rte_pipeline_port_in_action_handler.rs");
include!("types/rte_pipeline_port_out_action_handler.rs");
include!("types/rte_pipeline_table_action_handler_hit.rs");
include!("types/rte_pipeline_table_action_handler_miss.rs");
include!("types/rte_port_in_op_create.rs");
include!("types/rte_port_in_op_free.rs");
include!("types/rte_port_in_op_rx.rs");
include!("types/rte_port_in_op_stats_read.rs");
include!("types/rte_port_out_op_create.rs");
include!("types/rte_port_out_op_flush.rs");
include!("types/rte_port_out_op_free.rs");
include!("types/rte_port_out_op_stats_read.rs");
include!("types/rte_port_out_op_tx.rs");
include!("types/rte_port_out_op_tx_bulk.rs");
include!("types/rte_power_freq_change_t.rs");
include!("types/rte_power_freqs_t.rs");
include!("types/rte_power_get_freq_t.rs");
include!("types/rte_power_set_freq_t.rs");
include!("types/rte_table_hash_op_hash.rs");
include!("types/rte_table_op_create.rs");
include!("types/rte_table_op_entry_add.rs");
include!("types/rte_table_op_entry_add_bulk.rs");
include!("types/rte_table_op_entry_delete.rs");
include!("types/rte_table_op_entry_delete_bulk.rs");
include!("types/rte_table_op_free.rs");
include!("types/rte_table_op_lookup.rs");
include!("types/rte_table_op_stats_read.rs");
include!("types/rte_timer_cb_t.rs");
include!("types/rte_usage_hook_t.rs");
include!("types/rte_xmm_t.rs");
include!("types/unaligned_uint16_t.rs");
include!("types/unaligned_uint32_t.rs");
include!("types/unaligned_uint64_t.rs");
include!("types/xmm_t.rs");


// Enums
include!("enums/AnonymousEnum20.rs");
include!("enums/AnonymousEnum21.rs");
include!("enums/AnonymousEnum23.rs");
include!("enums/AnonymousEnum24.rs");
include!("enums/AnonymousEnum26.rs");
include!("enums/AnonymousEnum27.rs");
include!("enums/AnonymousEnum28.rs");
include!("enums/cmdline_numtype.rs");
include!("enums/cmdline_vt100_parser_state.rs");
include!("enums/malloc_elem.rs");
include!("enums/pmd_type.rs");
include!("enums/power_management_env.rs");
include!("enums/rdline_status.rs");
include!("enums/rte_acl_classify_alg.rs");
include!("enums/rte_acl_ctx.rs");
include!("enums/rte_cfgfile.rs");
include!("enums/rte_cpu_flag_t.rs");
include!("enums/rte_crypto_auth_algorithm.rs");
include!("enums/rte_crypto_auth_operation.rs");
include!("enums/rte_crypto_cipher_algorithm.rs");
include!("enums/rte_crypto_cipher_operation.rs");
include!("enums/rte_crypto_op_status.rs");
include!("enums/rte_crypto_op_type.rs");
include!("enums/rte_crypto_sym_op_sess_type.rs");
include!("enums/rte_crypto_sym_xform_type.rs");
include!("enums/rte_cryptodev_sym_session.rs");
include!("enums/rte_distributor.rs");
include!("enums/rte_hash.rs");
include!("enums/rte_intr_handle_type.rs");
include!("enums/rte_intr_mode.rs");
include!("enums/rte_keepalive.rs");
include!("enums/rte_keepalive_state.rs");
include!("enums/rte_lcore_role_t.rs");
include!("enums/rte_lcore_state_t.rs");
include!("enums/rte_lpm6.rs");
include!("enums/rte_mempool_objtlr.rs");
include!("enums/rte_meter_color.rs");
include!("enums/rte_page_sizes.rs");
include!("enums/rte_pdump_socktype.rs");
include!("enums/rte_pipeline.rs");
include!("enums/rte_pipeline_action.rs");
include!("enums/rte_proc_type_t.rs");
include!("enums/rte_reorder_buffer.rs");
include!("enums/rte_ring_queue_behavior.rs");
include!("enums/rte_rmt_call_master_t.rs");
include!("enums/rte_sched_port.rs");
include!("enums/rte_timer_type.rs");
include!("enums/timer_source.rs");


// Structs
include!("structs/AnonymousStruct10.rs");
include!("structs/AnonymousStruct11.rs");
include!("structs/AnonymousStruct12.rs");
include!("structs/AnonymousStruct13.rs");
include!("structs/AnonymousStruct14.rs");
include!("structs/AnonymousStruct15.rs");
include!("structs/AnonymousStruct16.rs");
include!("structs/AnonymousStruct17.rs");
include!("structs/AnonymousStruct18.rs");
include!("structs/AnonymousStruct19.rs");
include!("structs/AnonymousStruct2.rs");
include!("structs/AnonymousStruct22.rs");
include!("structs/AnonymousStruct25.rs");
include!("structs/AnonymousStruct3.rs");
include!("structs/AnonymousStruct5.rs");
include!("structs/AnonymousStruct6.rs");
include!("structs/AnonymousStruct7.rs");
include!("structs/AnonymousStruct8.rs");
include!("structs/AnonymousStruct9.rs");
include!("structs/AnonymousUnion1.rs");
include!("structs/AnonymousUnion4.rs");
include!("structs/arp_hdr.rs");
include!("structs/arp_ipv4.rs");
include!("structs/cirbuf.rs");
include!("structs/cmdline.rs");
include!("structs/cmdline_inst.rs");
include!("structs/cmdline_ipaddr.rs");
include!("structs/cmdline_portlist.rs");
include!("structs/cmdline_token_etheraddr.rs");
include!("structs/cmdline_token_hdr.rs");
include!("structs/cmdline_token_ipaddr.rs");
include!("structs/cmdline_token_ipaddr_data.rs");
include!("structs/cmdline_token_num.rs");
include!("structs/cmdline_token_num_data.rs");
include!("structs/cmdline_token_ops.rs");
include!("structs/cmdline_token_portlist.rs");
include!("structs/cmdline_token_string.rs");
include!("structs/cmdline_token_string_data.rs");
include!("structs/cmdline_vt100.rs");
include!("structs/cons.rs");
include!("structs/ether_addr.rs");
include!("structs/ether_hdr.rs");
include!("structs/icmp_hdr.rs");
include!("structs/ip_frag.rs");
include!("structs/ip_frag_key.rs");
include!("structs/ip_frag_pkt.rs");
include!("structs/ip_frag_tbl_stat.rs");
include!("structs/ip_pkt_list.rs");
include!("structs/ipv4_hdr.rs");
include!("structs/ipv6_extension_fragment.rs");
include!("structs/ipv6_hdr.rs");
include!("structs/lcore_config.rs");
include!("structs/malloc_heap.rs");
include!("structs/prod.rs");
include!("structs/rdline.rs");
include!("structs/rte_acl_config.rs");
include!("structs/rte_acl_field.rs");
include!("structs/rte_acl_field_def.rs");
include!("structs/rte_acl_field_types.rs");
include!("structs/rte_acl_param.rs");
include!("structs/rte_acl_rule.rs");
include!("structs/rte_acl_rule_data.rs");
include!("structs/rte_atomic16_t.rs");
include!("structs/rte_atomic32_t.rs");
include!("structs/rte_atomic64_t.rs");
include!("structs/rte_cfgfile_entry.rs");
include!("structs/rte_config.rs");
include!("structs/rte_crypto_auth_xform.rs");
include!("structs/rte_crypto_cipher_xform.rs");
include!("structs/rte_crypto_op.rs");
include!("structs/rte_crypto_op_pool_private.rs");
include!("structs/rte_crypto_sym_op.rs");
include!("structs/rte_crypto_sym_xform.rs");
include!("structs/rte_dev_eeprom_info.rs");
include!("structs/rte_dev_reg_info.rs");
include!("structs/rte_driver.rs");
include!("structs/rte_driver_list.rs");
include!("structs/rte_epoll_data.rs");
include!("structs/rte_epoll_event.rs");
include!("structs/rte_eth_vhost_queue_event.rs");
include!("structs/rte_fbk_hash_entry.rs");
include!("structs/rte_fbk_hash_params.rs");
include!("structs/rte_fbk_hash_table.rs");
include!("structs/rte_hash_parameters.rs");
include!("structs/rte_intr_handle.rs");
include!("structs/rte_ip_frag_death_row.rs");
include!("structs/rte_ip_frag_tbl.rs");
include!("structs/rte_ipv4_tuple.rs");
include!("structs/rte_ipv6_tuple.rs");
include!("structs/rte_jobstats.rs");
include!("structs/rte_jobstats_context.rs");
include!("structs/rte_kvargs.rs");
include!("structs/rte_kvargs_pair.rs");
include!("structs/rte_logs.rs");
include!("structs/rte_lpm.rs");
include!("structs/rte_lpm6_config.rs");
include!("structs/rte_lpm_config.rs");
include!("structs/rte_lpm_rule.rs");
include!("structs/rte_lpm_rule_info.rs");
include!("structs/rte_lpm_rule_v20.rs");
include!("structs/rte_lpm_tbl_entry.rs");
include!("structs/rte_lpm_tbl_entry_v20.rs");
include!("structs/rte_lpm_v20.rs");
include!("structs/rte_malloc_socket_stats.rs");
include!("structs/rte_mbuf.rs");
include!("structs/rte_mem_config.rs");
include!("structs/rte_mempool.rs");
include!("structs/rte_mempool_cache.rs");
include!("structs/rte_mempool_memhdr.rs");
include!("structs/rte_mempool_memhdr_list.rs");
include!("structs/rte_mempool_objhdr.rs");
include!("structs/rte_mempool_objhdr_list.rs");
include!("structs/rte_mempool_objsz.rs");
include!("structs/rte_mempool_ops.rs");
include!("structs/rte_mempool_ops_table.rs");
include!("structs/rte_memseg.rs");
include!("structs/rte_memzone.rs");
include!("structs/rte_meter_srtcm.rs");
include!("structs/rte_meter_srtcm_params.rs");
include!("structs/rte_meter_trtcm.rs");
include!("structs/rte_meter_trtcm_params.rs");
include!("structs/rte_pipeline_params.rs");
include!("structs/rte_pipeline_port_in_params.rs");
include!("structs/rte_pipeline_port_in_stats.rs");
include!("structs/rte_pipeline_port_out_params.rs");
include!("structs/rte_pipeline_port_out_stats.rs");
include!("structs/rte_pipeline_table_entry.rs");
include!("structs/rte_pipeline_table_params.rs");
include!("structs/rte_pipeline_table_stats.rs");
include!("structs/rte_pktmbuf_pool_private.rs");
include!("structs/rte_port_ethdev_reader_params.rs");
include!("structs/rte_port_ethdev_writer_nodrop_params.rs");
include!("structs/rte_port_ethdev_writer_params.rs");
include!("structs/rte_port_in_ops.rs");
include!("structs/rte_port_in_stats.rs");
include!("structs/rte_port_out_ops.rs");
include!("structs/rte_port_out_stats.rs");
include!("structs/rte_port_ring_reader_frag_params.rs");
include!("structs/rte_port_ring_reader_params.rs");
include!("structs/rte_port_ring_writer_nodrop_params.rs");
include!("structs/rte_port_ring_writer_params.rs");
include!("structs/rte_port_ring_writer_ras_params.rs");
include!("structs/rte_port_sched_reader_params.rs");
include!("structs/rte_port_sched_writer_params.rs");
include!("structs/rte_port_sink_params.rs");
include!("structs/rte_port_source_params.rs");
include!("structs/rte_reciprocal.rs");
include!("structs/rte_red.rs");
include!("structs/rte_red_config.rs");
include!("structs/rte_red_params.rs");
include!("structs/rte_ring.rs");
include!("structs/rte_rwlock_t.rs");
include!("structs/rte_sched_pipe_params.rs");
include!("structs/rte_sched_port_params.rs");
include!("structs/rte_sched_queue_stats.rs");
include!("structs/rte_sched_subport_params.rs");
include!("structs/rte_sched_subport_stats.rs");
include!("structs/rte_spinlock_recursive_t.rs");
include!("structs/rte_spinlock_t.rs");
include!("structs/rte_table_acl_params.rs");
include!("structs/rte_table_acl_rule_add_params.rs");
include!("structs/rte_table_acl_rule_delete_params.rs");
include!("structs/rte_table_array_key.rs");
include!("structs/rte_table_array_params.rs");
include!("structs/rte_table_hash_ext_params.rs");
include!("structs/rte_table_hash_key16_ext_params.rs");
include!("structs/rte_table_hash_key16_lru_params.rs");
include!("structs/rte_table_hash_key32_ext_params.rs");
include!("structs/rte_table_hash_key32_lru_params.rs");
include!("structs/rte_table_hash_key8_ext_params.rs");
include!("structs/rte_table_hash_key8_lru_params.rs");
include!("structs/rte_table_hash_lru_params.rs");
include!("structs/rte_table_lpm_ipv6_key.rs");
include!("structs/rte_table_lpm_ipv6_params.rs");
include!("structs/rte_table_lpm_key.rs");
include!("structs/rte_table_lpm_params.rs");
include!("structs/rte_table_ops.rs");
include!("structs/rte_table_stats.rs");
include!("structs/rte_tailq_elem.rs");
include!("structs/rte_tailq_entry.rs");
include!("structs/rte_tailq_entry_head.rs");
include!("structs/rte_tailq_head.rs");
include!("structs/rte_thash_tuple.rs");
include!("structs/rte_timecounter.rs");
include!("structs/rte_timer.rs");
include!("structs/rte_timer_status.rs");
include!("structs/rte_xmm.rs");
include!("structs/sctp_hdr.rs");
include!("structs/tcp_hdr.rs");
include!("structs/udp_hdr.rs");
include!("structs/virtio_net_device_ops.rs");
include!("structs/vlan_hdr.rs");
include!("structs/vxlan_hdr.rs");
