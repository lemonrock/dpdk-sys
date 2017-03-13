// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_eth_bond_8023ad_conf_get(port_id: uint8_t, conf: *mut rte_eth_bond_8023ad_conf) -> c_int;
	pub fn rte_eth_bond_8023ad_conf_get_v1607(port_id: uint8_t, conf: *mut rte_eth_bond_8023ad_conf) -> c_int;
	pub fn rte_eth_bond_8023ad_conf_get_v20(port_id: uint8_t, conf: *mut rte_eth_bond_8023ad_conf) -> c_int;
	pub fn rte_eth_bond_8023ad_ext_collect(port_id: uint8_t, slave_id: uint8_t, enabled: c_int) -> c_int;
	pub fn rte_eth_bond_8023ad_ext_collect_get(port_id: uint8_t, slave_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_8023ad_ext_distrib(port_id: uint8_t, slave_id: uint8_t, enabled: c_int) -> c_int;
	pub fn rte_eth_bond_8023ad_ext_distrib_get(port_id: uint8_t, slave_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_8023ad_ext_slowtx(port_id: uint8_t, slave_id: uint8_t, lacp_pkt: *mut rte_mbuf) -> c_int;
	pub fn rte_eth_bond_8023ad_setup(port_id: uint8_t, conf: *mut rte_eth_bond_8023ad_conf) -> c_int;
	pub fn rte_eth_bond_8023ad_setup_v1607(port_id: uint8_t, conf: *mut rte_eth_bond_8023ad_conf) -> c_int;
	pub fn rte_eth_bond_8023ad_setup_v20(port_id: uint8_t, conf: *mut rte_eth_bond_8023ad_conf) -> c_int;
	pub fn rte_eth_bond_8023ad_slave_info(port_id: uint8_t, slave_id: uint8_t, conf: *mut rte_eth_bond_8023ad_slave_info) -> c_int;
	pub fn rte_eth_bond_active_slaves_get(bonded_port_id: uint8_t, slaves: *mut uint8_t, len: uint8_t) -> c_int;
	pub fn rte_eth_bond_create(name: *const c_char, mode: uint8_t, socket_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_free(name: *const c_char) -> c_int;
	pub fn rte_eth_bond_link_down_prop_delay_get(bonded_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_link_down_prop_delay_set(bonded_port_id: uint8_t, delay_ms: uint32_t) -> c_int;
	pub fn rte_eth_bond_link_monitoring_get(bonded_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_link_monitoring_set(bonded_port_id: uint8_t, internal_ms: uint32_t) -> c_int;
	pub fn rte_eth_bond_link_up_prop_delay_get(bonded_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_link_up_prop_delay_set(bonded_port_id: uint8_t, delay_ms: uint32_t) -> c_int;
	pub fn rte_eth_bond_mac_address_reset(bonded_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_mac_address_set(bonded_port_id: uint8_t, mac_addr: *mut ether_addr) -> c_int;
	pub fn rte_eth_bond_mode_get(bonded_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_mode_set(bonded_port_id: uint8_t, mode: uint8_t) -> c_int;
	pub fn rte_eth_bond_primary_get(bonded_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_primary_set(bonded_port_id: uint8_t, slave_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_slave_add(bonded_port_id: uint8_t, slave_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_slave_remove(bonded_port_id: uint8_t, slave_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_slaves_get(bonded_port_id: uint8_t, slaves: *mut uint8_t, len: uint8_t) -> c_int;
	pub fn rte_eth_bond_xmit_policy_get(bonded_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_xmit_policy_set(bonded_port_id: uint8_t, policy: uint8_t) -> c_int;
}
