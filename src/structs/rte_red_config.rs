// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_red_config
{
	pub min_th: uint32_t,
	pub max_th: uint32_t,
	pub pa_const: uint32_t,
	pub maxp_inv: uint8_t,
	pub wq_log2: uint8_t,
	_bindgen_padding_0_: [u8; 2usize],
}
impl Default for rte_red_config
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
