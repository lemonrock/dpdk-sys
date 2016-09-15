// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(u32)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub enum rte_fdir_mode
{
	RTE_FDIR_MODE_NONE = 0,
	RTE_FDIR_MODE_SIGNATURE = 1,
	RTE_FDIR_MODE_PERFECT = 2,
	RTE_FDIR_MODE_PERFECT_MAC_VLAN = 3,
	RTE_FDIR_MODE_PERFECT_TUNNEL = 4,
}
