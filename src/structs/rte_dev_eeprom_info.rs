// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_dev_eeprom_info
{
	pub data: *mut c_void,
	pub offset: uint32_t,
	pub length: uint32_t,
	pub magic: uint32_t,
	_bindgen_padding_0_: [u8; 4usize],
}

impl Default for rte_dev_eeprom_info
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
