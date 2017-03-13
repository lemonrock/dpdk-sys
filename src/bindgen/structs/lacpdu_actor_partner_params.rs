// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C, packed)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct lacpdu_actor_partner_params
{
	pub tlv_type_info: uint8_t,
	pub info_length: uint8_t,
	pub port_params: port_params,
	pub state: uint8_t,
	pub reserved_3: [uint8_t; 3usize],
}

impl Default for lacpdu_actor_partner_params
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
