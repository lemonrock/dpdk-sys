// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C, packed)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct lacpdu
{
	pub subtype: uint8_t,
	pub version_number: uint8_t,
	pub actor: lacpdu_actor_partner_params,
	pub partner: lacpdu_actor_partner_params,
	pub tlv_type_collector_info: uint8_t,
	pub collector_info_length: uint8_t,
	pub collector_max_delay: uint16_t,
	pub reserved_12: [uint8_t; 12usize],
	pub tlv_type_terminator: uint8_t,
	pub terminator_length: uint8_t,
	pub reserved_50: [uint8_t; 50usize],
}

impl Clone for lacpdu
{
	#[inline(always)]
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for lacpdu
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
