// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(u32)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub enum rte_eth_rx_mq_mode
{
	ETH_MQ_RX_NONE = 0,
	ETH_MQ_RX_RSS = 1,
	ETH_MQ_RX_DCB = 2,
	ETH_MQ_RX_DCB_RSS = 3,
	ETH_MQ_RX_VMDQ_ONLY = 4,
	ETH_MQ_RX_VMDQ_RSS = 5,
	ETH_MQ_RX_VMDQ_DCB = 6,
	ETH_MQ_RX_VMDQ_DCB_RSS = 7,
}
