// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(u32)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub enum rte_eth_input_set_field
{
	RTE_ETH_INPUT_SET_UNKNOWN = 0,
	RTE_ETH_INPUT_SET_L2_SRC_MAC = 1,
	RTE_ETH_INPUT_SET_L2_DST_MAC = 2,
	RTE_ETH_INPUT_SET_L2_OUTER_VLAN = 3,
	RTE_ETH_INPUT_SET_L2_INNER_VLAN = 4,
	RTE_ETH_INPUT_SET_L2_ETHERTYPE = 5,
	RTE_ETH_INPUT_SET_L3_SRC_IP4 = 129,
	RTE_ETH_INPUT_SET_L3_DST_IP4 = 130,
	RTE_ETH_INPUT_SET_L3_SRC_IP6 = 131,
	RTE_ETH_INPUT_SET_L3_DST_IP6 = 132,
	RTE_ETH_INPUT_SET_L3_IP4_TOS = 133,
	RTE_ETH_INPUT_SET_L3_IP4_PROTO = 134,
	RTE_ETH_INPUT_SET_L3_IP6_TC = 135,
	RTE_ETH_INPUT_SET_L3_IP6_NEXT_HEADER = 136,
	RTE_ETH_INPUT_SET_L3_IP4_TTL = 137,
	RTE_ETH_INPUT_SET_L3_IP6_HOP_LIMITS = 138,
	RTE_ETH_INPUT_SET_L4_UDP_SRC_PORT = 257,
	RTE_ETH_INPUT_SET_L4_UDP_DST_PORT = 258,
	RTE_ETH_INPUT_SET_L4_TCP_SRC_PORT = 259,
	RTE_ETH_INPUT_SET_L4_TCP_DST_PORT = 260,
	RTE_ETH_INPUT_SET_L4_SCTP_SRC_PORT = 261,
	RTE_ETH_INPUT_SET_L4_SCTP_DST_PORT = 262,
	RTE_ETH_INPUT_SET_L4_SCTP_VERIFICATION_TAG = 263,
	RTE_ETH_INPUT_SET_TUNNEL_L2_INNER_DST_MAC = 385,
	RTE_ETH_INPUT_SET_TUNNEL_L2_INNER_SRC_MAC = 386,
	RTE_ETH_INPUT_SET_TUNNEL_L2_INNER_VLAN = 387,
	RTE_ETH_INPUT_SET_TUNNEL_L4_UDP_KEY = 388,
	RTE_ETH_INPUT_SET_TUNNEL_GRE_KEY = 389,
	RTE_ETH_INPUT_SET_FLEX_PAYLOAD_1ST_WORD = 641,
	RTE_ETH_INPUT_SET_FLEX_PAYLOAD_2ND_WORD = 642,
	RTE_ETH_INPUT_SET_FLEX_PAYLOAD_3RD_WORD = 643,
	RTE_ETH_INPUT_SET_FLEX_PAYLOAD_4TH_WORD = 644,
	RTE_ETH_INPUT_SET_FLEX_PAYLOAD_5TH_WORD = 645,
	RTE_ETH_INPUT_SET_FLEX_PAYLOAD_6TH_WORD = 646,
	RTE_ETH_INPUT_SET_FLEX_PAYLOAD_7TH_WORD = 647,
	RTE_ETH_INPUT_SET_FLEX_PAYLOAD_8TH_WORD = 648,
	RTE_ETH_INPUT_SET_DEFAULT = 65533,
	RTE_ETH_INPUT_SET_NONE = 65534,
	RTE_ETH_INPUT_SET_MAX = 65535,
}
