// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_eth_fdir_info
{
	pub mode: rte_fdir_mode,
	pub mask: rte_eth_fdir_masks,
	pub flex_conf: rte_eth_fdir_flex_conf,
	pub guarant_spc: uint32_t,
	pub best_spc: uint32_t,
	pub flow_types_mask: [uint32_t; 1usize],
	pub max_flexpayload: uint32_t,
	pub flex_payload_unit: uint32_t,
	pub max_flex_payload_segment_num: uint32_t,
	pub flex_payload_limit: uint16_t,
	pub flex_bitmask_unit: uint32_t,
	pub max_flex_bitmask_num: uint32_t,
}

impl Default for rte_eth_fdir_info
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
