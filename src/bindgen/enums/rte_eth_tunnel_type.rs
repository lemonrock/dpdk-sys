// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(u32)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub enum rte_eth_tunnel_type
{
	RTE_TUNNEL_TYPE_NONE = 0,
	RTE_TUNNEL_TYPE_VXLAN = 1,
	RTE_TUNNEL_TYPE_GENEVE = 2,
	RTE_TUNNEL_TYPE_TEREDO = 3,
	RTE_TUNNEL_TYPE_NVGRE = 4,
	RTE_TUNNEL_TYPE_IP_IN_GRE = 5,
	RTE_L2_TUNNEL_TYPE_E_TAG = 6,
	RTE_TUNNEL_TYPE_MAX = 7,
}
