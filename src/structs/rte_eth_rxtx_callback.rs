// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_eth_rxtx_callback
{
	pub next: *mut rte_eth_rxtx_callback,
	pub fn_: AnonymousUnion39,
	pub param: *mut c_void,
}

impl Default for rte_eth_rxtx_callback
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
