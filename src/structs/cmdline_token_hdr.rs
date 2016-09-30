// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct cmdline_token_hdr
{
	pub ops: *mut cmdline_token_ops,
	pub offset: c_uint,
	_bindgen_padding_0_: [u8; 4usize],
}
impl Default for cmdline_token_hdr
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}