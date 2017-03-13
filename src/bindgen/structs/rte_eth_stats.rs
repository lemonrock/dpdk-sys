// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_eth_stats
{
	pub ipackets: uint64_t,
	pub opackets: uint64_t,
	pub ibytes: uint64_t,
	pub obytes: uint64_t,
	pub imissed: uint64_t,
	pub ierrors: uint64_t,
	pub oerrors: uint64_t,
	pub rx_nombuf: uint64_t,
	pub q_ipackets: [uint64_t; 16usize],
	pub q_opackets: [uint64_t; 16usize],
	pub q_ibytes: [uint64_t; 16usize],
	pub q_obytes: [uint64_t; 16usize],
	pub q_errors: [uint64_t; 16usize],
}

impl Default for rte_eth_stats
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
