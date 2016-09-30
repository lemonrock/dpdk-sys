// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_port_ring_reader_frag_params
{
	pub ring: *mut rte_ring,
	pub mtu: uint32_t,
	pub metadata_size: uint32_t,
	pub pool_direct: *mut rte_mempool,
	pub pool_indirect: *mut rte_mempool,
}
impl Default for rte_port_ring_reader_frag_params
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}