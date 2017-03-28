// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_intr_handle
{
	pub _bindgen_data_1_: [u32; 1usize],
	pub fd: c_int,
	pub type_: rte_intr_handle_type,
	pub max_intr: uint32_t,
	pub nb_efd: uint32_t,
	pub efds: [c_int; 32usize],
	pub elist: [rte_epoll_event; 32usize],
	pub intr_vec: *mut c_int,
}

impl rte_intr_handle
{
	#[inline(always)]
	pub unsafe fn vfio_dev_fd(&mut self) -> *mut c_int
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw)
	}
	#[inline(always)]
	pub unsafe fn uio_cfg_fd(&mut self) -> *mut c_int
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw)
	}
}

impl Default for rte_intr_handle
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
