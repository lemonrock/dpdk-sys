// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct ip_frag_key
{
	pub src_dst: [uint64_t; 4usize],
	pub id: uint32_t,
	pub key_len: uint32_t,
}
impl Default for ip_frag_key
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
