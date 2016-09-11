// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_pipeline_table_entry
{
	pub action: rte_pipeline_action,

	pub _bindgen_data_1_: [u32; 1usize],

	pub action_data: [uint8_t; 0usize],

}

impl rte_pipeline_table_entry
{
	pub unsafe fn port_id(&mut self) -> *mut uint32_t

	{

		let raw: *mut u8 = transmute(&self._bindgen_data_1_);

		transmute(raw.offset(0))

	}

	pub unsafe fn table_id(&mut self) -> *mut uint32_t

	{

		let raw: *mut u8 = transmute(&self._bindgen_data_1_);

		transmute(raw.offset(0))

	}

}

impl Default for rte_pipeline_table_entry
{
	fn default() -> Self

	{

		unsafe { zeroed() }

	}

}

