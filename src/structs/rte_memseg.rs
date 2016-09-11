// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_memseg
{
	pub phys_addr: phys_addr_t,
	pub _bindgen_data_1_: [u64; 1usize],
	pub len: size_t,
	pub hugepage_sz: uint64_t,
	pub socket_id: int32_t,
	pub nchannel: uint32_t,
	pub nrank: uint32_t,
}
impl rte_memseg
{
	pub unsafe fn addr(&mut self) -> *mut *mut c_void
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
	pub unsafe fn addr_64(&mut self) -> *mut uint64_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
}
impl Default for rte_memseg
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
