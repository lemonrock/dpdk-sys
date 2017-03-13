// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(u32)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub enum rte_filter_op
{
	RTE_ETH_FILTER_NOP = 0,
	RTE_ETH_FILTER_ADD = 1,
	RTE_ETH_FILTER_UPDATE = 2,
	RTE_ETH_FILTER_DELETE = 3,
	RTE_ETH_FILTER_FLUSH = 4,
	RTE_ETH_FILTER_GET = 5,
	RTE_ETH_FILTER_SET = 6,
	RTE_ETH_FILTER_INFO = 7,
	RTE_ETH_FILTER_STATS = 8,
	RTE_ETH_FILTER_OP_MAX = 9,
}
