// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(u32)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub enum rte_eth_payload_type
{
	RTE_ETH_PAYLOAD_UNKNOWN = 0,
	RTE_ETH_RAW_PAYLOAD = 1,
	RTE_ETH_L2_PAYLOAD = 2,
	RTE_ETH_L3_PAYLOAD = 3,
	RTE_ETH_L4_PAYLOAD = 4,
	RTE_ETH_PAYLOAD_MAX = 8,
}
