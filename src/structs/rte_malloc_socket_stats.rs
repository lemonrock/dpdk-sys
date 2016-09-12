// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_malloc_socket_stats
{
	pub heap_totalsz_bytes: size_t,
	pub heap_freesz_bytes: size_t,
	pub greatest_free_size: size_t,
	pub free_count: c_uint,
	pub alloc_count: c_uint,
	pub heap_allocsz_bytes: size_t,
}

impl Default for rte_malloc_socket_stats
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
