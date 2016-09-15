// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_fdir_conf
{
	pub mode: rte_fdir_mode,
	pub pballoc: rte_fdir_pballoc_type,
	pub status: rte_fdir_status_mode,
	pub drop_queue: uint8_t,
	pub mask: rte_eth_fdir_masks,
	pub flex_conf: rte_eth_fdir_flex_conf,
}

impl Default for rte_fdir_conf
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
