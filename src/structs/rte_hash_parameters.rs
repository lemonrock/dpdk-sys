// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_hash_parameters
{
	pub name: *const c_char,
	pub entries: uint32_t,
	pub reserved: uint32_t,
	pub key_len: uint32_t,
	pub hash_func: rte_hash_function,
	pub hash_func_init_val: uint32_t,
	pub socket_id: c_int,
	pub extra_flag: uint8_t,
	_bindgen_padding_0_: [u8; 7usize],
}
impl Default for rte_hash_parameters
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
