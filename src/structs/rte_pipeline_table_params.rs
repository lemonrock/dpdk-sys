// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_pipeline_table_params
{
	pub ops: *mut rte_table_ops,

	pub arg_create: *mut c_void,

	pub f_action_hit: rte_pipeline_table_action_handler_hit,

	pub f_action_miss: rte_pipeline_table_action_handler_miss,

	pub arg_ah: *mut c_void,

	pub action_data_size: uint32_t,

	_bindgen_padding_0_: [u8; 4usize],

}

impl Default for rte_pipeline_table_params
{
	fn default() -> Self

	{

		unsafe { zeroed() }

	}

}

