// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_eth_txmode
{
	pub mq_mode: rte_eth_tx_mq_mode,
	pub pvid: uint16_t,
	pub _bindgen_bitfield_1_: uint8_t,
	pub _bindgen_bitfield_2_: uint8_t,
	pub _bindgen_bitfield_3_: uint8_t,
}

impl Default for rte_eth_txmode
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
