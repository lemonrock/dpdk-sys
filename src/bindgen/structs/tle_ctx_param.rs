// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct tle_ctx_param
{
	pub socket_id: int32_t,
	pub proto: uint32_t,
	pub max_streams: uint32_t,
	pub max_stream_rbufs: uint32_t,
	pub max_stream_sbufs: uint32_t,
	pub send_bulk_size: uint32_t,
	pub lookup4: Option<unsafe extern "C" fn(opaque: *mut c_void, addr: *const in_addr, res: *mut tle_dest) -> c_int>,
	pub lookup4_data: *mut c_void,
	pub lookup6: Option<unsafe extern "C" fn(opaque: *mut c_void, addr: *const in6_addr, res: *mut tle_dest) -> c_int>,
	pub lookup6_data: *mut c_void,
}

impl Default for tle_ctx_param
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
