// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_port_in_ops
{
	pub f_create: rte_port_in_op_create,

	pub f_free: rte_port_in_op_free,

	pub f_rx: rte_port_in_op_rx,

	pub f_stats: rte_port_in_op_stats_read,

}

impl Default for rte_port_in_ops
{
	fn default() -> Self

	{

		unsafe { zeroed() }

	}

}

