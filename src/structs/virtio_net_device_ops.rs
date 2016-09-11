// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct virtio_net_device_ops
{
	pub new_device: Option<extern "C" fn(vid: c_int) -> c_int>,
	pub destroy_device: Option<extern "C" fn(vid: c_int)>,
	pub vring_state_changed: Option<extern "C" fn(vid: c_int, queue_id: uint16_t, enable: c_int) -> c_int>,
	pub reserved: [*mut c_void; 5usize],
}

impl Default for virtio_net_device_ops
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
