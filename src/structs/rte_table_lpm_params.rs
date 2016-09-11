// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_table_lpm_params
{
	pub name: *const c_char,
	pub n_rules: uint32_t,
	pub number_tbl8s: uint32_t,
	pub flags: c_int,
	pub entry_unique_size: uint32_t,
	pub offset: uint32_t,
	_bindgen_padding_0_: [u8; 4usize],
}

impl Default for rte_table_lpm_params
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
