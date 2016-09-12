// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_table_hash_key8_lru_params
{
	pub n_entries: uint32_t,
	pub f_hash: rte_table_hash_op_hash,
	pub seed: uint64_t,
	pub signature_offset: uint32_t,
	pub key_offset: uint32_t,
	pub key_mask: *mut uint8_t,
}

impl Default for rte_table_hash_key8_lru_params
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
