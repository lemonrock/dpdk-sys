// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct tcp_hdr
{
	pub src_port: uint16_t,

	pub dst_port: uint16_t,

	pub sent_seq: uint32_t,

	pub recv_ack: uint32_t,

	pub data_off: uint8_t,

	pub tcp_flags: uint8_t,

	pub rx_win: uint16_t,

	pub cksum: uint16_t,

	pub tcp_urp: uint16_t,

}

impl Default for tcp_hdr
{
	fn default() -> Self

	{

		unsafe { zeroed() }

	}

}

