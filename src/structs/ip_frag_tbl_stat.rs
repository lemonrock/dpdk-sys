// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct ip_frag_tbl_stat
{
	pub find_num: uint64_t,
	pub add_num: uint64_t,
	pub del_num: uint64_t,
	pub reuse_num: uint64_t,
	pub fail_total: uint64_t,
	pub fail_nospace: uint64_t,
	_bindgen_padding_0_: [u64; 2usize],
}
impl Default for ip_frag_tbl_stat
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
