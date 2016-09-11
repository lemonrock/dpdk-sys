// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct ipv4_hdr
{
	pub version_ihl: uint8_t,

	pub type_of_service: uint8_t,

	pub total_length: uint16_t,

	pub packet_id: uint16_t,

	pub fragment_offset: uint16_t,

	pub time_to_live: uint8_t,

	pub next_proto_id: uint8_t,

	pub hdr_checksum: uint16_t,

	pub src_addr: uint32_t,

	pub dst_addr: uint32_t,

}

impl Default for ipv4_hdr
{
	fn default() -> Self

	{

		unsafe { zeroed() }

	}

}

