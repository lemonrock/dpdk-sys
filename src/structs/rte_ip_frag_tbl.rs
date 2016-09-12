// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_ip_frag_tbl
{
	pub max_cycles: uint64_t,
	pub entry_mask: uint32_t,
	pub max_entries: uint32_t,
	pub use_entries: uint32_t,
	pub bucket_entries: uint32_t,
	pub nb_entries: uint32_t,
	pub nb_buckets: uint32_t,
	pub last: *mut ip_frag_pkt,
	pub lru: ip_pkt_list,
	pub stat: ip_frag_tbl_stat,
	pub pkt: [ip_frag_pkt; 0usize],
}

impl Default for rte_ip_frag_tbl
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
