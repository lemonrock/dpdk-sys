// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_table_ops
{
	pub f_create: rte_table_op_create,
	pub f_free: rte_table_op_free,
	pub f_add: rte_table_op_entry_add,
	pub f_delete: rte_table_op_entry_delete,
	pub f_add_bulk: rte_table_op_entry_add_bulk,
	pub f_delete_bulk: rte_table_op_entry_delete_bulk,
	pub f_lookup: rte_table_op_lookup,
	pub f_stats: rte_table_op_stats_read,
}

impl Default for rte_table_ops
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
