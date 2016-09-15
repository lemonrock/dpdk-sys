// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


pub const DEV_TX_OFFLOAD_IPV4_CKSUM: c_int = 2;
pub const DEV_TX_OFFLOAD_OUTER_IPV4_CKSUM: c_int = 128;
pub const DEV_TX_OFFLOAD_QINQ_INSERT: c_int = 256;
pub const DEV_TX_OFFLOAD_SCTP_CKSUM: c_int = 16;
pub const DEV_TX_OFFLOAD_TCP_CKSUM: c_int = 8;
pub const DEV_TX_OFFLOAD_TCP_TSO: c_int = 32;
pub const DEV_TX_OFFLOAD_UDP_CKSUM: c_int = 4;
pub const DEV_TX_OFFLOAD_UDP_TSO: c_int = 64;
pub const DEV_TX_OFFLOAD_VLAN_INSERT: c_int = 1;
