// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


include!("types/MARKER.rs");
include!("types/MARKER64.rs");
include!("types/MARKER8.rs");
include!("types/arg_handler_t.rs");
include!("types/buffer_tx_error_fn.rs");
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
include!("types/cryptodev_close_t.rs");
include!("types/cryptodev_configure_t.rs");
include!("types/cryptodev_info_get_t.rs");
include!("types/cryptodev_init_t.rs");
include!("types/cryptodev_queue_pair_count_t.rs");
include!("types/cryptodev_queue_pair_release_t.rs");
include!("types/cryptodev_queue_pair_setup_t.rs");
include!("types/cryptodev_queue_pair_start_t.rs");
include!("types/cryptodev_queue_pair_stop_t.rs");
include!("types/cryptodev_start_t.rs");
include!("types/cryptodev_stats_get_t.rs");
include!("types/cryptodev_stats_reset_t.rs");
include!("types/cryptodev_stop_t.rs");
include!("types/cryptodev_sym_configure_session_t.rs");
include!("types/cryptodev_sym_create_session_pool_t.rs");
include!("types/cryptodev_sym_free_session_t.rs");
include!("types/cryptodev_sym_get_session_private_size_t.rs");
include!("types/cryptodev_sym_initialize_session_t.rs");
include!("types/cryptodev_uninit_t.rs");
include!("types/dequeue_pkt_burst_t.rs");
include!("types/enqueue_pkt_burst_t.rs");
include!("types/eth_allmulticast_disable_t.rs");
include!("types/eth_allmulticast_enable_t.rs");
include!("types/eth_dev_close_t.rs");
include!("types/eth_dev_configure_t.rs");
include!("types/eth_dev_infos_get_t.rs");
include!("types/eth_dev_init_t.rs");
include!("types/eth_dev_led_off_t.rs");
include!("types/eth_dev_led_on_t.rs");
include!("types/eth_dev_set_link_down_t.rs");
include!("types/eth_dev_set_link_up_t.rs");
include!("types/eth_dev_start_t.rs");
include!("types/eth_dev_stop_t.rs");
include!("types/eth_dev_supported_ptypes_get_t.rs");
include!("types/eth_dev_uninit_t.rs");
include!("types/eth_filter_ctrl_t.rs");
include!("types/eth_get_dcb_info.rs");
include!("types/eth_get_eeprom_length_t.rs");
include!("types/eth_get_eeprom_t.rs");
include!("types/eth_get_reg_t.rs");
include!("types/eth_l2_tunnel_eth_type_conf_t.rs");
include!("types/eth_l2_tunnel_offload_set_t.rs");
include!("types/eth_link_update_t.rs");
include!("types/eth_mac_addr_add_t.rs");
include!("types/eth_mac_addr_remove_t.rs");
include!("types/eth_mac_addr_set_t.rs");
include!("types/eth_mirror_rule_reset_t.rs");
include!("types/eth_mirror_rule_set_t.rs");
include!("types/eth_promiscuous_disable_t.rs");
include!("types/eth_promiscuous_enable_t.rs");
include!("types/eth_queue_release_t.rs");
include!("types/eth_queue_start_t.rs");
include!("types/eth_queue_stats_mapping_set_t.rs");
include!("types/eth_queue_stop_t.rs");
include!("types/eth_rx_burst_t.rs");
include!("types/eth_rx_descriptor_done_t.rs");
include!("types/eth_rx_disable_intr_t.rs");
include!("types/eth_rx_enable_intr_t.rs");
include!("types/eth_rx_queue_count_t.rs");
include!("types/eth_rx_queue_setup_t.rs");
include!("types/eth_rxq_info_get_t.rs");
include!("types/eth_set_eeprom_t.rs");
include!("types/eth_set_mc_addr_list_t.rs");
include!("types/eth_set_queue_rate_limit_t.rs");
include!("types/eth_set_vf_rate_limit_t.rs");
include!("types/eth_set_vf_rx_mode_t.rs");
include!("types/eth_set_vf_rx_t.rs");
include!("types/eth_set_vf_tx_t.rs");
include!("types/eth_set_vf_vlan_filter_t.rs");
include!("types/eth_stats_get_t.rs");
include!("types/eth_stats_reset_t.rs");
include!("types/eth_timesync_adjust_time.rs");
include!("types/eth_timesync_disable_t.rs");
include!("types/eth_timesync_enable_t.rs");
include!("types/eth_timesync_read_rx_timestamp_t.rs");
include!("types/eth_timesync_read_time.rs");
include!("types/eth_timesync_read_tx_timestamp_t.rs");
include!("types/eth_timesync_write_time.rs");
include!("types/eth_tx_burst_t.rs");
include!("types/eth_tx_queue_setup_t.rs");
include!("types/eth_txq_info_get_t.rs");
include!("types/eth_uc_all_hash_table_set_t.rs");
include!("types/eth_uc_hash_table_set_t.rs");
include!("types/eth_udp_tunnel_port_add_t.rs");
include!("types/eth_udp_tunnel_port_del_t.rs");
include!("types/eth_xstats_get_names_t.rs");
include!("types/eth_xstats_get_t.rs");
include!("types/eth_xstats_reset_t.rs");
include!("types/flow_ctrl_get_t.rs");
include!("types/flow_ctrl_set_t.rs");
include!("types/hash_sig_t.rs");
include!("types/lcore_function_t.rs");
include!("types/mtu_set_t.rs");
include!("types/pci_devinit_t.rs");
include!("types/pci_devuninit_t.rs");
include!("types/phys_addr_t.rs");
include!("types/priority_flow_ctrl_set_t.rs");
include!("types/rdline_complete_t.rs");
include!("types/rdline_validate_t.rs");
include!("types/rdline_write_char_t.rs");
include!("types/reta_query_t.rs");
include!("types/reta_update_t.rs");
include!("types/rss_hash_conf_get_t.rs");
include!("types/rss_hash_update_t.rs");
include!("types/rte_cpuset_t.rs");
include!("types/rte_cryptodev_cb_fn.rs");
include!("types/rte_dev_init_t.rs");
include!("types/rte_dev_uninit_t.rs");
include!("types/rte_eal_alarm_callback.rs");
include!("types/rte_eth_bond_8023ad_ext_slowrx_fn.rs");
include!("types/rte_eth_dev_cb_fn.rs");
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
include!("types/rte_rx_callback_fn.rs");
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
include!("types/rte_tx_callback_fn.rs");
include!("types/rte_usage_hook_t.rs");
include!("types/rte_xmm_t.rs");
include!("types/unaligned_uint16_t.rs");
include!("types/unaligned_uint32_t.rs");
include!("types/unaligned_uint64_t.rs");
include!("types/vlan_filter_set_t.rs");
include!("types/vlan_offload_set_t.rs");
include!("types/vlan_pvid_set_t.rs");
include!("types/vlan_strip_queue_set_t.rs");
include!("types/vlan_tpid_set_t.rs");
include!("types/xmm_t.rs");
