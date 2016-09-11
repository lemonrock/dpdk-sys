// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_fbk_hash_table
{
	pub name: [c_char; 32usize],
	pub entries: uint32_t,
	pub entries_per_bucket: uint32_t,
	pub used_entries: uint32_t,
	pub bucket_mask: uint32_t,
	pub bucket_shift: uint32_t,
	pub hash_func: rte_fbk_hash_fn,
	pub init_val: uint32_t,
	pub t: [rte_fbk_hash_entry; 0usize],
}
impl Default for rte_fbk_hash_table
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
