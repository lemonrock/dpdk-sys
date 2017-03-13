// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C, packed)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct marker
{
	pub subtype: uint8_t,
	pub version_number: uint8_t,
	pub tlv_type_marker: uint8_t,
	pub info_length: uint8_t,
	pub requester_port: uint16_t,
	pub requester_system: ether_addr,
	pub requester_transaction_id: uint32_t,
	pub reserved_2: [uint8_t; 2usize],
	pub tlv_type_terminator: uint8_t,
	pub terminator_length: uint8_t,
	pub reserved_90: [uint8_t; 90usize],
}

impl Clone for marker
{
	#[inline(always)]
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for marker
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
