// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct rte_lpm_v20
{
	pub name: [c_char; 32usize],
	pub max_rules: uint32_t,
	pub rule_info: [rte_lpm_rule_info; 32usize],
	pub tbl24: [rte_lpm_tbl_entry_v20; 16777216usize],
	pub tbl8: [rte_lpm_tbl_entry_v20; 65536usize],
	pub rules_tbl: [rte_lpm_rule_v20; 0usize],
}

impl Clone for rte_lpm_v20
{
	#[inline(always)]
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for rte_lpm_v20
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
