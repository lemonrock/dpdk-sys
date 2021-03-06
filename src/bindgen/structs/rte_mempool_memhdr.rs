// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_mempool_memhdr
{
	pub next: rte_mempool_memhdr_AnonymousStruct_next,
	pub mp: *mut rte_mempool,
	pub addr: *mut c_void,
	pub phys_addr: phys_addr_t,
	pub len: size_t,
	pub free_cb: rte_mempool_memchunk_free_cb_t,
	pub opaque: *mut c_void,
}

impl Default for rte_mempool_memhdr
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
