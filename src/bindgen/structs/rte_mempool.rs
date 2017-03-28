// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_mempool
{
	pub name: [c_char; 32usize],
	pub _bindgen_data_1_: [u64; 1usize],
	pub pool_config: *mut c_void,
	pub mz: *const rte_memzone,
	pub flags: c_int,
	pub socket_id: c_int,
	pub size: uint32_t,
	pub cache_size: uint32_t,
	pub elt_size: uint32_t,
	pub header_size: uint32_t,
	pub trailer_size: uint32_t,
	pub private_data_size: c_uint,
	pub ops_index: int32_t,
	pub local_cache: *mut rte_mempool_cache,
	pub populated_size: uint32_t,
	pub elt_list: rte_mempool_objhdr_list,
	pub nb_mem_chunks: uint32_t,
	pub mem_list: rte_mempool_memhdr_list,
}

impl rte_mempool
{
	#[inline(always)]
#[allow(trivial_casts)]
	pub fn pool_data(&mut self) -> *mut *mut c_void
	{
		let raw = &mut self._bindgen_data_1_ as *mut _ as *mut u8;
		raw as *mut _
	}

	#[inline(always)]
#[allow(trivial_casts)]
	pub fn pool_id(&mut self) -> *mut uint64_t
	{
		let raw = &mut self._bindgen_data_1_ as *mut _ as *mut u8;
		raw as *mut _
	}
}

impl Default for rte_mempool
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
