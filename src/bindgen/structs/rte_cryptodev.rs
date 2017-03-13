// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_cryptodev
{
	pub dequeue_burst: dequeue_pkt_burst_t,
	pub enqueue_burst: enqueue_pkt_burst_t,
	pub driver: *const rte_cryptodev_driver,
	pub data: *mut rte_cryptodev_data,
	pub dev_ops: *mut rte_cryptodev_ops,
	pub feature_flags: uint64_t,
	pub device: *mut rte_device,
	pub dev_type: rte_cryptodev_type,
	pub link_intr_cbs: rte_cryptodev_cb_list,
	pub _bindgen_bitfield_1_: uint8_t,
	_bindgen_padding_0_: [u64; 5usize],
}

impl Default for rte_cryptodev
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
