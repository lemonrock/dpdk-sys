// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_eth_vhost_feature_disable(feature_mask: uint64_t) -> c_int;
	pub fn rte_eth_vhost_feature_enable(feature_mask: uint64_t) -> c_int;
	pub fn rte_eth_vhost_feature_get() -> uint64_t;
	pub fn rte_eth_vhost_get_queue_event(port_id: uint8_t, event: *mut rte_eth_vhost_queue_event) -> c_int;
}
