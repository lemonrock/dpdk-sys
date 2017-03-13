// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


pub const DEV_TX_OFFLOAD_GENEVE_TNL_TSO: c_int = 4096;
pub const DEV_TX_OFFLOAD_GRE_TNL_TSO: c_int = 1024;
pub const DEV_TX_OFFLOAD_IPIP_TNL_TSO: c_int = 2048;
pub const DEV_TX_OFFLOAD_IPV4_CKSUM: u32 = 2;
pub const DEV_TX_OFFLOAD_MACSEC_INSERT: c_int = 8192;
pub const DEV_TX_OFFLOAD_OUTER_IPV4_CKSUM: u32 = 128;
pub const DEV_TX_OFFLOAD_QINQ_INSERT: u32 = 256;
pub const DEV_TX_OFFLOAD_SCTP_CKSUM: u32 = 16;
pub const DEV_TX_OFFLOAD_TCP_CKSUM: u32 = 8;
pub const DEV_TX_OFFLOAD_TCP_TSO: u32 = 32;
pub const DEV_TX_OFFLOAD_UDP_CKSUM: u32 = 4;
pub const DEV_TX_OFFLOAD_UDP_TSO: u32 = 64;
pub const DEV_TX_OFFLOAD_VLAN_INSERT: u32 = 1;
pub const DEV_TX_OFFLOAD_VXLAN_TNL_TSO: c_int = 512;
