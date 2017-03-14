// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct tle_tcp_stream_cfg
{
	pub nb_retries: uint8_t,
	pub err_ev: *mut tle_event,
	pub err_cb: tle_stream_cb,
	pub recv_ev: *mut tle_event,
	pub recv_cb: tle_stream_cb,
	pub send_ev: *mut tle_event,
	pub send_cb: tle_stream_cb,
}

impl Default for tle_tcp_stream_cfg
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
