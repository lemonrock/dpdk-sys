// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct ip_frag_pkt
{
	pub lru: ip_frag_pkt_AnonymousStruct_lru,
	pub key: ip_frag_key,
	pub start: uint64_t,
	pub total_size: uint32_t,
	pub frag_size: uint32_t,
	pub last_idx: uint32_t,
	pub frags: [ip_frag; 4usize],
}

impl Default for ip_frag_pkt
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
