// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(u32)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub enum rte_eth_hash_filter_info_type
{
	RTE_ETH_HASH_FILTER_INFO_TYPE_UNKNOWN = 0,
	RTE_ETH_HASH_FILTER_SYM_HASH_ENA_PER_PORT = 1,
	RTE_ETH_HASH_FILTER_GLOBAL_CONFIG = 2,
	RTE_ETH_HASH_FILTER_INPUT_SET_SELECT = 3,
	RTE_ETH_HASH_FILTER_INFO_TYPE_MAX = 4,
}
