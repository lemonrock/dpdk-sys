// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.



#![allow(non_camel_case_types)]

extern crate core;
use ::core::default::Default;
use ::core::option::Option;
use ::core::mem::zeroed;
use ::core::mem::transmute;
use ::core::clone::Clone;

use ::std::os::raw::c_char;
use ::std::os::raw::c_int;
use ::std::os::raw::c_longlong;
use ::std::os::raw::c_uint;
use ::std::os::raw::c_void;

extern crate libc;
use ::libc::size_t;
use ::libc::ssize_t;
use ::libc::uint8_t;
use ::libc::uint16_t;
use ::libc::uint32_t;
use ::libc::uint64_t;
use ::libc::int16_t;
use ::libc::int32_t;
use ::libc::int64_t;
use ::libc::FILE;
use ::libc::in_addr;
use ::libc::in6_addr;
use ::libc::termios;
use ::libc::pthread_t;
use ::libc::cpu_set_t;


#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct __m128i
{
	a: u64,
	b: u64,
}

pub type va_list = __builtin_va_list;

pub type __builtin_va_list = [__va_list_tag; 1usize];

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct __va_list_tag
{
	pub gp_offset: c_uint,
	pub fp_offset: c_uint,
	pub overflow_arg_area: *mut c_void,
	pub reg_save_area: *mut c_void,
}

impl Default for __va_list_tag
{
    fn default() -> Self
	{
		unsafe { zeroed() }
	}
}


#[link(name = "dpdk")]
extern "C"
{
}

#[link(name = "ethdev")]
extern "C"
{
}

#[link(name = "rte_acl")]
extern "C"
{
}

#[link(name = "rte_cfgfile")]
extern "C"
{
}

#[link(name = "rte_cmdline")]
extern "C"
{
}

#[link(name = "rte_cryptodev")]
extern "C"
{
}

#[link(name = "rte_distributor")]
extern "C"
{
}

#[link(name = "rte_eal")]
extern "C"
{
}

#[link(name = "rte_hash")]
extern "C"
{
}

#[link(name = "rte_ip_frag")]
extern "C"
{
}

#[link(name = "rte_jobstats")]
extern "C"
{
}

#[link(name = "rte_kvargs")]
extern "C"
{
}

#[link(name = "rte_lpm")]
extern "C"
{
}

#[link(name = "rte_mbuf")]
extern "C"
{
}

#[link(name = "rte_mempool")]
extern "C"
{
}

#[link(name = "rte_meter")]
extern "C"
{
}

#[link(name = "rte_pdump")]
extern "C"
{
}

#[link(name = "rte_pipeline")]
extern "C"
{
}

#[link(name = "rte_pmd_af_packet")]
extern "C"
{
}

#[link(name = "rte_pmd_bond")]
extern "C"
{
}

#[link(name = "rte_pmd_null")]
extern "C"
{
}

#[link(name = "rte_pmd_null_crypto")]
extern "C"
{
}

#[link(name = "rte_pmd_ring")]
extern "C"
{
}

#[link(name = "rte_port")]
extern "C"
{
}

#[link(name = "rte_power")]
extern "C"
{
}

#[link(name = "rte_reorder")]
extern "C"
{
}

#[link(name = "rte_ring")]
extern "C"
{
}

#[link(name = "rte_sched")]
extern "C"
{
}

#[link(name = "rte_table")]
extern "C"
{
}

#[link(name = "rte_timer")]
extern "C"
{
}


// Constants
pub const ARP_HRD_ETHER: c_int = 1;
pub const ARP_OP_INVREPLY: c_int = 9;
pub const ARP_OP_INVREQUEST: c_int = 8;
pub const ARP_OP_REPLY: c_int = 2;
pub const ARP_OP_REQUEST: c_int = 1;
pub const ARP_OP_REVREPLY: c_int = 4;
pub const ARP_OP_REVREQUEST: c_int = 3;
pub const BALANCE_XMIT_POLICY_LAYER23: c_int = 1;
pub const BALANCE_XMIT_POLICY_LAYER2: c_int = 0;
pub const BALANCE_XMIT_POLICY_LAYER34: c_int = 2;
pub const BONDING_MODE_8023AD: c_int = 4;
pub const BONDING_MODE_ACTIVE_BACKUP: c_int = 1;
pub const BONDING_MODE_ALB: c_int = 6;
pub const BONDING_MODE_BALANCE: c_int = 2;
pub const BONDING_MODE_BROADCAST: c_int = 3;
pub const BONDING_MODE_ROUND_ROBIN: c_int = 0;
pub const BONDING_MODE_TLB: c_int = 5;
pub const CFG_NAME_LEN: c_int = 64;
pub const CFG_VALUE_LEN: c_int = 256;
pub const CMDLINE_IPADDR_NETWORK: c_int = 4;
pub const CMDLINE_IPADDR_V4: c_int = 1;
pub const CMDLINE_IPADDR_V6: c_int = 2;
pub const CMDLINE_KEY_BKSPACE: c_int = 4;
pub const CMDLINE_KEY_CTRL_A: c_int = 6;
pub const CMDLINE_KEY_CTRL_B: c_int = 12;
pub const CMDLINE_KEY_CTRL_C: c_int = 10;
pub const CMDLINE_KEY_CTRL_D: c_int = 15;
pub const CMDLINE_KEY_CTRL_E: c_int = 7;
pub const CMDLINE_KEY_CTRL_F: c_int = 11;
pub const CMDLINE_KEY_CTRL_K: c_int = 8;
pub const CMDLINE_KEY_CTRL_L: c_int = 16;
pub const CMDLINE_KEY_CTRL_N: c_int = 24;
pub const CMDLINE_KEY_CTRL_P: c_int = 23;
pub const CMDLINE_KEY_CTRL_W: c_int = 22;
pub const CMDLINE_KEY_CTRL_Y: c_int = 9;
pub const CMDLINE_KEY_DOWN_ARR: c_int = 1;
pub const CMDLINE_KEY_HELP: c_int = 21;
pub const CMDLINE_KEY_LEFT_ARR: c_int = 3;
pub const CMDLINE_KEY_META_BKSPACE: c_int = 18;
pub const CMDLINE_KEY_META_D: c_int = 25;
pub const CMDLINE_KEY_RETURN2: c_int = 17;
pub const CMDLINE_KEY_RETURN: c_int = 5;
pub const CMDLINE_KEY_RIGHT_ARR: c_int = 2;
pub const CMDLINE_KEY_SUPPR: c_int = 13;
pub const CMDLINE_KEY_TAB: c_int = 14;
pub const CMDLINE_KEY_UP_ARR: c_int = 0;
pub const CMDLINE_KEY_WLEFT: c_int = 19;
pub const CMDLINE_KEY_WRIGHT: c_int = 20;
pub const CMDLINE_PARSE_AMBIGUOUS: c_int = -1;
pub const CMDLINE_PARSE_BAD_ARGS: c_int = -3;
pub const CMDLINE_PARSE_COMPLETED_BUFFER: c_int = 2;
pub const CMDLINE_PARSE_COMPLETE_AGAIN: c_int = 1;
pub const CMDLINE_PARSE_COMPLETE_FINISHED: c_int = 0;
pub const CMDLINE_PARSE_NOMATCH: c_int = -2;
pub const CMDLINE_PARSE_RESULT_BUFSIZE: c_int = 8192;
pub const CMDLINE_PARSE_SUCCESS: c_int = 0;
pub const CMDLINE_VT100_BUF_SIZE: c_int = 8;
pub const CRC32_ARM64: c_int = 8;
pub const CRC32_SSE42: c_int = 2;
pub const CRC32_SSE42_x64: c_int = 6;
pub const CRC32_SW: c_int = 1;
pub const CRC32_x64: c_int = 4;
pub const CTRL_MBUF_FLAG: c_longlong = -9223372036854775808;
pub const ETHER_ADDR_FMT_SIZE: c_int = 18;
pub const ETHER_ADDR_LEN: c_int = 6;
pub const ETHER_CRC_LEN: c_int = 4;
pub const ETHER_GROUP_ADDR: c_int = 1;
pub const ETHER_HDR_LEN: c_int = 14;
pub const ETHER_LOCAL_ADMIN_ADDR: c_int = 2;
pub const ETHER_MAX_JUMBO_FRAME_LEN: c_int = 16128;
pub const ETHER_MAX_LEN: c_int = 1518;
pub const ETHER_MAX_VLAN_FRAME_LEN: c_int = 1522;
pub const ETHER_MAX_VLAN_ID: c_int = 4095;
pub const ETHER_MIN_LEN: c_int = 64;
pub const ETHER_MIN_MTU: c_int = 68;
pub const ETHER_MTU: c_int = 1500;
pub const ETHER_TYPE_1588: c_int = 35063;
pub const ETHER_TYPE_ARP: c_int = 2054;
pub const ETHER_TYPE_IPv4: c_int = 2048;
pub const ETHER_TYPE_IPv6: c_int = 34525;
pub const ETHER_TYPE_LEN: c_int = 2;
pub const ETHER_TYPE_RARP: c_int = 32821;
pub const ETHER_TYPE_SLOW: c_int = 34825;
pub const ETHER_TYPE_TEB: c_int = 25944;
pub const ETHER_TYPE_VLAN: c_int = 33024;
pub const IND_ATTACHED_MBUF: c_longlong = 4611686018427387904;
pub const IPV4_HDR_DF_FLAG: c_int = 16384;
pub const IPV4_HDR_DF_SHIFT: c_int = 14;
pub const IPV4_HDR_FO_SHIFT: c_int = 3;
pub const IPV4_HDR_IHL_MASK: c_int = 15;
pub const IPV4_HDR_MF_FLAG: c_int = 8192;
pub const IPV4_HDR_MF_SHIFT: c_int = 13;
pub const IPV4_HDR_OFFSET_MASK: c_int = 8191;
pub const IPV4_HDR_OFFSET_UNITS: c_int = 8;
pub const IPV4_IHL_MULTIPLIER: c_int = 4;
pub const IPV4_MAX_PKT_LEN: c_int = 65535;
pub const IP_FRAG_DEATH_ROW_LEN: c_int = 32;
pub const IP_ICMP_ECHO_REPLY: c_int = 0;
pub const IP_ICMP_ECHO_REQUEST: c_int = 8;
pub const MAX_SKIPLIST_DEPTH: c_int = 10;
pub const MEMPOOL_F_NO_CACHE_ALIGN: c_int = 2;
pub const MEMPOOL_F_NO_PHYS_CONTIG: c_int = 32;
pub const MEMPOOL_F_NO_SPREAD: c_int = 1;
pub const MEMPOOL_F_POOL_CREATED: c_int = 16;
pub const MEMPOOL_F_SC_GET: c_int = 8;
pub const MEMPOOL_F_SP_PUT: c_int = 4;
pub const MEMPOOL_PG_NUM_DEFAULT: c_int = 1;
pub const MS_PER_S: c_int = 1000;
pub const NSEC_PER_SEC: c_int = 1000000000;
pub const NS_PER_S: c_int = 1000000000;
pub const PKT_RX_EIP_CKSUM_BAD: c_int = 32;
pub const PKT_RX_FDIR: c_int = 4;
pub const PKT_RX_FDIR_FLX: c_int = 16384;
pub const PKT_RX_FDIR_ID: c_int = 8192;
pub const PKT_RX_IEEE1588_PTP: c_int = 512;
pub const PKT_RX_IEEE1588_TMST: c_int = 1024;
pub const PKT_RX_IP_CKSUM_BAD: c_int = 16;
pub const PKT_RX_L4_CKSUM_BAD: c_int = 8;
pub const PKT_RX_QINQ_PKT: c_int = 32768;
pub const PKT_RX_QINQ_STRIPPED: c_int = 32768;
pub const PKT_RX_RSS_HASH: c_int = 2;
pub const PKT_RX_VLAN_PKT: c_int = 1;
pub const PKT_RX_VLAN_STRIPPED: c_int = 64;
pub const PKT_TX_IEEE1588_TMST: c_longlong = 2251799813685248;
pub const PKT_TX_IPV4: c_longlong = 36028797018963968;
pub const PKT_TX_IPV6: c_longlong = 72057594037927936;
pub const PKT_TX_IP_CKSUM: c_longlong = 18014398509481984;
pub const PKT_TX_L4_MASK: c_longlong = 13510798882111488;
pub const PKT_TX_L4_NO_CKSUM: c_int = 0;
pub const PKT_TX_OUTER_IPV4: c_longlong = 576460752303423488;
pub const PKT_TX_OUTER_IPV6: c_longlong = 1152921504606846976;
pub const PKT_TX_OUTER_IP_CKSUM: c_longlong = 288230376151711744;
pub const PKT_TX_QINQ_PKT: c_longlong = 562949953421312;
pub const PKT_TX_SCTP_CKSUM: c_longlong = 9007199254740992;
pub const PKT_TX_TCP_CKSUM: c_longlong = 4503599627370496;
pub const PKT_TX_TCP_SEG: c_longlong = 1125899906842624;
pub const PKT_TX_UDP_CKSUM: c_longlong = 13510798882111488;
pub const PKT_TX_VLAN_PKT: c_longlong = 144115188075855872;
pub const PORTLIST_MAX_TOKENS: c_int = 32;
pub const PORTLIST_TOKEN_SIZE: c_int = 128;
pub const RDLINE_BUF_SIZE: c_int = 512;
pub const RDLINE_HISTORY_MAX_LINE: c_int = 64;
pub const RDLINE_PROMPT_SIZE: c_int = 32;
pub const RDLINE_RES_COMPLETE: c_int = 2;
pub const RDLINE_RES_EOF: c_int = -2;
pub const RDLINE_RES_EXITED: c_int = -3;
pub const RDLINE_RES_NOT_RUNNING: c_int = -1;
pub const RDLINE_RES_SUCCESS: c_int = 0;
pub const RDLINE_RES_VALIDATED: c_int = 1;
pub const RDLINE_VT100_BUF_SIZE: c_int = 8;
pub const RING_F_SC_DEQ: c_int = 2;
pub const RING_F_SP_ENQ: c_int = 1;
pub const RTE_ACL_INVALID_USERDATA: c_int = 0;
pub const RTE_ACL_MAX_CATEGORIES: c_int = 16;
pub const RTE_ACL_MAX_FIELDS: c_int = 64;
pub const RTE_ACL_MAX_LEVELS: c_int = 64;
pub const RTE_ACL_MAX_PRIORITY: AnonymousEnum28 = AnonymousEnum28::RTE_ACL_MAX_INDEX;
pub const RTE_ACL_NAMESIZE: c_int = 32;
pub const RTE_APP_TEST: c_int = 1;
pub const RTE_ARCH_64: c_int = 1;
pub const RTE_ARCH_X86: c_int = 1;
pub const RTE_ARCH_X86_64: c_int = 1;
pub const RTE_BIG_ENDIAN: c_int = 1;
pub const RTE_BYTE_ORDER: c_int = 2;
pub const RTE_CACHE_LINE_MASK: c_int = 63;
pub const RTE_CACHE_LINE_MIN_SIZE: c_int = 64;
pub const RTE_CACHE_LINE_SIZE: c_int = 64;
pub const RTE_CACHE_LINE_SIZE_LOG2: c_int = 6;
pub const RTE_CRYPTODEV_NAME_LEN: c_int = 64;
pub const RTE_CRYPTO_MAX_DEVS: c_int = 64;
pub const RTE_DISTRIBUTOR_NAMESIZE: c_int = 32;
pub const RTE_EAL_VFIO: c_int = 1;
pub const RTE_EPOLL_PER_THREAD: c_int = -1;
pub const RTE_ETHDEV_QUEUE_STAT_CNTRS: c_int = 16;
pub const RTE_ETHDEV_RXTX_CALLBACKS: c_int = 1;
pub const RTE_EXEC_ENV_LINUXAPP: c_int = 1;
pub const RTE_FBK_HASH_ENTRIES_MAX: c_int = 1048576;
pub const RTE_FBK_HASH_ENTRIES_PER_BUCKET_MAX: c_int = 256;
pub const RTE_FBK_HASH_INIT_VAL_DEFAULT: i64 = 4294967295;
pub const RTE_FBK_HASH_NAMESIZE: c_int = 32;
pub const RTE_HASH_ENTRIES_MAX: c_int = 1073741824;
pub const RTE_HASH_EXTRA_FLAGS_MULTI_WRITER_ADD: c_int = 2;
pub const RTE_HASH_EXTRA_FLAGS_TRANS_MEM_SUPPORT: c_int = 1;
pub const RTE_HASH_LOOKUP_BULK_MAX: c_int = 64;
pub const RTE_HASH_LOOKUP_MULTI_MAX: c_int = 64;
pub const RTE_HASH_NAMESIZE: c_int = 32;
pub const RTE_HEAP_NUM_FREELISTS: c_int = 13;
pub const RTE_INTR_EVENT_ADD: c_int = 1;
pub const RTE_INTR_EVENT_DEL: c_int = 2;
pub const RTE_INTR_VEC_RXTX_OFFSET: c_int = 1;
pub const RTE_INTR_VEC_ZERO_OFFSET: c_int = 0;
pub const RTE_IPV6_EHDR_FO_MASK: c_int = -8;
pub const RTE_IPV6_EHDR_FO_SHIFT: c_int = 3;
pub const RTE_IPV6_EHDR_MF_MASK: c_int = 1;
pub const RTE_IPV6_EHDR_MF_SHIFT: c_int = 0;
pub const RTE_IPV6_FRAG_USED_MASK: c_int = -7;
pub const RTE_IXGBE_INC_VECTOR: c_int = 1;
pub const RTE_IXGBE_RX_OLFLAGS_ENABLE: c_int = 1;
pub const RTE_JHASH_GOLDEN_RATIO: i64 = 3735928559;
pub const RTE_JOBSTATS_NAMESIZE: c_int = 32;
pub const RTE_KEEPALIVE_MAXCORES: c_int = 128;
pub const RTE_KNI_PREEMPT_DEFAULT: c_int = 1;
pub const RTE_KNI_VHOST_MAX_CACHE_SIZE: c_int = 1024;
pub const RTE_KVARGS_MAX: c_int = 32;
pub const RTE_LIBRTE_ACL: c_int = 1;
pub const RTE_LIBRTE_BNXT_PMD: c_int = 1;
pub const RTE_LIBRTE_CFGFILE: c_int = 1;
pub const RTE_LIBRTE_CMDLINE: c_int = 1;
pub const RTE_LIBRTE_CRYPTODEV: c_int = 1;
pub const RTE_LIBRTE_CXGBE_PMD: c_int = 1;
pub const RTE_LIBRTE_DISTRIBUTOR: c_int = 1;
pub const RTE_LIBRTE_EAL: c_int = 1;
pub const RTE_LIBRTE_EAL_VMWARE_TSC_MAP_SUPPORT: c_int = 1;
pub const RTE_LIBRTE_EM_PMD: c_int = 1;
pub const RTE_LIBRTE_ENA_PMD: c_int = 1;
pub const RTE_LIBRTE_ENIC_PMD: c_int = 1;
pub const RTE_LIBRTE_ETHER: c_int = 1;
pub const RTE_LIBRTE_FM10K_INC_VECTOR: c_int = 1;
pub const RTE_LIBRTE_FM10K_PMD: c_int = 1;
pub const RTE_LIBRTE_FM10K_RX_OLFLAGS_ENABLE: c_int = 1;
pub const RTE_LIBRTE_HASH: c_int = 1;
pub const RTE_LIBRTE_I40E_INC_VECTOR: c_int = 1;
pub const RTE_LIBRTE_I40E_ITR_INTERVAL: c_int = -1;
pub const RTE_LIBRTE_I40E_PMD: c_int = 1;
pub const RTE_LIBRTE_I40E_QUEUE_NUM_PER_PF: c_int = 64;
pub const RTE_LIBRTE_I40E_QUEUE_NUM_PER_VF: c_int = 4;
pub const RTE_LIBRTE_I40E_QUEUE_NUM_PER_VM: c_int = 4;
pub const RTE_LIBRTE_I40E_RX_ALLOW_BULK_ALLOC: c_int = 1;
pub const RTE_LIBRTE_I40E_RX_OLFLAGS_ENABLE: c_int = 1;
pub const RTE_LIBRTE_IGB_PMD: c_int = 1;
pub const RTE_LIBRTE_IP_FRAG: c_int = 1;
pub const RTE_LIBRTE_IP_FRAG_MAX_FRAG: c_int = 4;
pub const RTE_LIBRTE_IXGBE_PMD: c_int = 1;
pub const RTE_LIBRTE_JOBSTATS: c_int = 1;
pub const RTE_LIBRTE_KNI: c_int = 1;
pub const RTE_LIBRTE_KVARGS: c_int = 1;
pub const RTE_LIBRTE_LPM: c_int = 1;
pub const RTE_LIBRTE_MBUF: c_int = 1;
pub const RTE_LIBRTE_MEMPOOL: c_int = 1;
pub const RTE_LIBRTE_METER: c_int = 1;
pub const RTE_LIBRTE_MLX4_MAX_INLINE: c_int = 0;
pub const RTE_LIBRTE_MLX4_SGE_WR_N: c_int = 4;
pub const RTE_LIBRTE_MLX4_SOFT_COUNTERS: c_int = 1;
pub const RTE_LIBRTE_MLX4_TX_MP_CACHE: c_int = 8;
pub const RTE_LIBRTE_MLX5_TX_MP_CACHE: c_int = 8;
pub const RTE_LIBRTE_NET: c_int = 1;
pub const RTE_LIBRTE_PDUMP: c_int = 1;
pub const RTE_LIBRTE_PIPELINE: c_int = 1;
pub const RTE_LIBRTE_PMD_AF_PACKET: c_int = 1;
pub const RTE_LIBRTE_PMD_BOND: c_int = 1;
pub const RTE_LIBRTE_PMD_NULL: c_int = 1;
pub const RTE_LIBRTE_PMD_NULL_CRYPTO: c_int = 1;
pub const RTE_LIBRTE_PMD_RING: c_int = 1;
pub const RTE_LIBRTE_PMD_SZEDATA2_AS: c_int = 0;
pub const RTE_LIBRTE_PMD_VHOST: c_int = 1;
pub const RTE_LIBRTE_PORT: c_int = 1;
pub const RTE_LIBRTE_POWER: c_int = 1;
pub const RTE_LIBRTE_REORDER: c_int = 1;
pub const RTE_LIBRTE_RING: c_int = 1;
pub const RTE_LIBRTE_SCHED: c_int = 1;
pub const RTE_LIBRTE_TABLE: c_int = 1;
pub const RTE_LIBRTE_TIMER: c_int = 1;
pub const RTE_LIBRTE_VHOST: c_int = 1;
pub const RTE_LIBRTE_VHOST_USER: c_int = 1;
pub const RTE_LIBRTE_VIRTIO_PMD: c_int = 1;
pub const RTE_LIBRTE_VMXNET3_PMD: c_int = 1;
pub const RTE_LITTLE_ENDIAN: c_int = 2;
pub const RTE_LOGTYPE_ACL: c_int = 512;
pub const RTE_LOGTYPE_CRYPTODEV: c_int = 131072;
pub const RTE_LOGTYPE_EAL: c_int = 1;
pub const RTE_LOGTYPE_HASH: c_int = 64;
pub const RTE_LOGTYPE_KNI: c_int = 256;
pub const RTE_LOGTYPE_LPM: c_int = 128;
pub const RTE_LOGTYPE_MALLOC: c_int = 2;
pub const RTE_LOGTYPE_MBUF: c_int = 65536;
pub const RTE_LOGTYPE_MEMPOOL: c_int = 8;
pub const RTE_LOGTYPE_METER: c_int = 2048;
pub const RTE_LOGTYPE_PIPELINE: c_int = 32768;
pub const RTE_LOGTYPE_PMD: c_int = 32;
pub const RTE_LOGTYPE_PORT: c_int = 8192;
pub const RTE_LOGTYPE_POWER: c_int = 1024;
pub const RTE_LOGTYPE_RING: c_int = 4;
pub const RTE_LOGTYPE_SCHED: c_int = 4096;
pub const RTE_LOGTYPE_TABLE: c_int = 16384;
pub const RTE_LOGTYPE_TIMER: c_int = 16;
pub const RTE_LOGTYPE_USER1: c_int = 16777216;
pub const RTE_LOGTYPE_USER2: c_int = 33554432;
pub const RTE_LOGTYPE_USER3: c_int = 67108864;
pub const RTE_LOGTYPE_USER4: c_int = 134217728;
pub const RTE_LOGTYPE_USER5: c_int = 268435456;
pub const RTE_LOGTYPE_USER6: c_int = 536870912;
pub const RTE_LOGTYPE_USER7: c_int = 1073741824;
pub const RTE_LOGTYPE_USER8: i64 = 2147483648;
pub const RTE_LOG_ALERT: c_int = 2;
pub const RTE_LOG_CRIT: c_int = 3;
pub const RTE_LOG_DEBUG: c_int = 8;
pub const RTE_LOG_EMERG: c_int = 1;
pub const RTE_LOG_ERR: c_int = 4;
pub const RTE_LOG_HISTORY: c_int = 256;
pub const RTE_LOG_INFO: c_int = 7;
pub const RTE_LOG_NOTICE: c_int = 6;
pub const RTE_LOG_WARNING: c_int = 5;
pub const RTE_LPM6_IPV6_ADDR_SIZE: c_int = 16;
pub const RTE_LPM6_MAX_DEPTH: c_int = 128;
pub const RTE_LPM6_NAMESIZE: c_int = 32;
pub const RTE_LPM_IPV6_ADDR_SIZE: c_int = 16;
pub const RTE_LPM_LOOKUP_SUCCESS: c_int = 16777216;
pub const RTE_LPM_MAX_DEPTH: c_int = 32;
pub const RTE_LPM_MAX_TBL8_NUM_GROUPS: c_int = 16777216;
pub const RTE_LPM_NAMESIZE: c_int = 32;
pub const RTE_LPM_TBL24_NUM_ENTRIES: c_int = 16777216;
pub const RTE_LPM_TBL8_GROUP_NUM_ENTRIES: c_int = 256;
pub const RTE_LPM_TBL8_NUM_ENTRIES: c_int = 65536;
pub const RTE_LPM_TBL8_NUM_GROUPS: c_int = 256;
pub const RTE_LPM_VALID_EXT_ENTRY_BITMASK: c_int = 50331648;
pub const RTE_MAGIC: c_int = 19820526;
pub const RTE_MAX_ETHPORTS: c_int = 32;
pub const RTE_MAX_LCORE: c_int = 128;
pub const RTE_MAX_LCORE_FREQS: c_int = 64;
pub const RTE_MAX_MEMSEG: c_int = 256;
pub const RTE_MAX_MEMZONE: c_int = 2560;
pub const RTE_MAX_NUMA_NODES: c_int = 8;
pub const RTE_MAX_QUEUES_PER_PORT: c_int = 1024;
pub const RTE_MAX_RXTX_INTR_VEC_ID: c_int = 32;
pub const RTE_MAX_TAILQ: c_int = 32;
pub const RTE_MAX_THREAD_NAME_LEN: c_int = 16;
pub const RTE_MBUF_DEFAULT_BUF_SIZE: c_int = 2176;
pub const RTE_MBUF_DEFAULT_DATAROOM: c_int = 2048;
pub const RTE_MBUF_PRIV_ALIGN: c_int = 8;
pub const RTE_MBUF_REFCNT_ATOMIC: c_int = 1;
pub const RTE_MEMPOOL_ALIGN: c_int = 64;
pub const RTE_MEMPOOL_ALIGN_MASK: c_int = 63;
pub const RTE_MEMPOOL_CACHE_MAX_SIZE: c_int = 512;
pub const RTE_MEMPOOL_HEADER_COOKIE1: c_longlong = -4982197544707871147;
pub const RTE_MEMPOOL_HEADER_COOKIE2: c_longlong = -941548164385788331;
pub const RTE_MEMPOOL_MAX_OPS_IDX: c_int = 16;
pub const RTE_MEMPOOL_OPS_NAMESIZE: c_int = 32;
pub const RTE_MEMPOOL_TRAILER_COOKIE: c_longlong = -5921418378119291987;
pub const RTE_MEMZONE_16GB: c_int = 512;
pub const RTE_MEMZONE_16MB: c_int = 256;
pub const RTE_MEMZONE_1GB: c_int = 2;
pub const RTE_MEMZONE_256KB: c_int = 65536;
pub const RTE_MEMZONE_256MB: c_int = 131072;
pub const RTE_MEMZONE_2MB: c_int = 1;
pub const RTE_MEMZONE_4GB: c_int = 524288;
pub const RTE_MEMZONE_512MB: c_int = 262144;
pub const RTE_MEMZONE_NAMESIZE: c_int = 32;
pub const RTE_MEMZONE_SIZE_HINT_ONLY: c_int = 4;
pub const RTE_NEXT_ABI: c_int = 1;
pub const RTE_PIPELINE_PORT_IN_MAX: c_int = 64;
pub const RTE_PIPELINE_PORT_OUT_MAX: c_int = 64;
pub const RTE_PIPELINE_TABLE_MAX: c_int = 64;
pub const RTE_PKTMBUF_HEADROOM: c_int = 128;
pub const RTE_PMD_PACKET_PREFETCH: c_int = 1;
pub const RTE_PMD_RING_MAX_RX_RINGS: c_int = 16;
pub const RTE_PMD_RING_MAX_TX_RINGS: c_int = 16;
pub const RTE_PORT_IN_BURST_SIZE_MAX: c_int = 64;
pub const RTE_PTYPE_INNER_L2_ETHER: c_int = 65536;
pub const RTE_PTYPE_INNER_L2_ETHER_VLAN: c_int = 131072;
pub const RTE_PTYPE_INNER_L2_MASK: c_int = 983040;
pub const RTE_PTYPE_INNER_L3_IPV4: c_int = 1048576;
pub const RTE_PTYPE_INNER_L3_IPV4_EXT: c_int = 2097152;
pub const RTE_PTYPE_INNER_L3_IPV4_EXT_UNKNOWN: c_int = 4194304;
pub const RTE_PTYPE_INNER_L3_IPV6: c_int = 3145728;
pub const RTE_PTYPE_INNER_L3_IPV6_EXT: c_int = 5242880;
pub const RTE_PTYPE_INNER_L3_IPV6_EXT_UNKNOWN: c_int = 6291456;
pub const RTE_PTYPE_INNER_L3_MASK: c_int = 15728640;
pub const RTE_PTYPE_INNER_L4_FRAG: c_int = 50331648;
pub const RTE_PTYPE_INNER_L4_ICMP: c_int = 83886080;
pub const RTE_PTYPE_INNER_L4_MASK: c_int = 251658240;
pub const RTE_PTYPE_INNER_L4_NONFRAG: c_int = 100663296;
pub const RTE_PTYPE_INNER_L4_SCTP: c_int = 67108864;
pub const RTE_PTYPE_INNER_L4_TCP: c_int = 16777216;
pub const RTE_PTYPE_INNER_L4_UDP: c_int = 33554432;
pub const RTE_PTYPE_L2_ETHER: c_int = 1;
pub const RTE_PTYPE_L2_ETHER_ARP: c_int = 3;
pub const RTE_PTYPE_L2_ETHER_LLDP: c_int = 4;
pub const RTE_PTYPE_L2_ETHER_NSH: c_int = 5;
pub const RTE_PTYPE_L2_ETHER_TIMESYNC: c_int = 2;
pub const RTE_PTYPE_L2_MASK: c_int = 15;
pub const RTE_PTYPE_L3_IPV4: c_int = 16;
pub const RTE_PTYPE_L3_IPV4_EXT: c_int = 48;
pub const RTE_PTYPE_L3_IPV4_EXT_UNKNOWN: c_int = 144;
pub const RTE_PTYPE_L3_IPV6: c_int = 64;
pub const RTE_PTYPE_L3_IPV6_EXT: c_int = 192;
pub const RTE_PTYPE_L3_IPV6_EXT_UNKNOWN: c_int = 224;
pub const RTE_PTYPE_L3_MASK: c_int = 240;
pub const RTE_PTYPE_L4_FRAG: c_int = 768;
pub const RTE_PTYPE_L4_ICMP: c_int = 1280;
pub const RTE_PTYPE_L4_MASK: c_int = 3840;
pub const RTE_PTYPE_L4_NONFRAG: c_int = 1536;
pub const RTE_PTYPE_L4_SCTP: c_int = 1024;
pub const RTE_PTYPE_L4_TCP: c_int = 256;
pub const RTE_PTYPE_L4_UDP: c_int = 512;
pub const RTE_PTYPE_TUNNEL_GENEVE: c_int = 20480;
pub const RTE_PTYPE_TUNNEL_GRE: c_int = 8192;
pub const RTE_PTYPE_TUNNEL_GRENAT: c_int = 24576;
pub const RTE_PTYPE_TUNNEL_IP: c_int = 4096;
pub const RTE_PTYPE_TUNNEL_MASK: c_int = 61440;
pub const RTE_PTYPE_TUNNEL_NVGRE: c_int = 16384;
pub const RTE_PTYPE_TUNNEL_VXLAN: c_int = 12288;
pub const RTE_PTYPE_UNKNOWN: c_int = 0;
pub const RTE_QAT_PMD_MAX_NB_SESSIONS: c_int = 2048;
pub const RTE_RED_2POW16: c_int = 65536;
pub const RTE_RED_MAXP_INV_MAX: c_int = 255;
pub const RTE_RED_MAXP_INV_MIN: c_int = 1;
pub const RTE_RED_MAX_TH_MAX: c_int = 1023;
pub const RTE_RED_S: c_int = 4194304;
pub const RTE_RED_SCALING: c_int = 10;
pub const RTE_RED_WQ_LOG2_MAX: c_int = 12;
pub const RTE_RED_WQ_LOG2_MIN: c_int = 1;
pub const RTE_RED_WQ_LOG2_NUM: c_int = 12;
pub const RTE_RING_PAUSE_REP_COUNT: c_int = 0;
pub const RTE_RING_QUOT_EXCEED: i64 = 2147483648;
pub const RTE_RTM_MAX_RETRIES: c_int = 10;
pub const RTE_SCHED_FRAME_OVERHEAD_DEFAULT: c_int = 24;
pub const RTE_SCHED_PIPE_PROFILES_PER_PORT: c_int = 256;
pub const RTE_SCHED_PORT_N_GRINDERS: c_int = 8;
pub const RTE_SCHED_QUEUES_PER_PIPE: c_int = 16;
pub const RTE_SCHED_QUEUES_PER_TRAFFIC_CLASS: c_int = 4;
pub const RTE_SCHED_TRAFFIC_CLASSES_PER_PIPE: c_int = 4;
pub const RTE_TABLE_HASH_LRU_STRATEGY: c_int = 1;
pub const RTE_TAILQ_NAMESIZE: c_int = 32;
pub const RTE_TEST_PMD: c_int = 1;
pub const RTE_TIMER_CONFIG: c_int = 3;
pub const RTE_TIMER_NO_OWNER: c_int = -2;
pub const RTE_TIMER_PENDING: c_int = 1;
pub const RTE_TIMER_RUNNING: c_int = 2;
pub const RTE_TIMER_STOP: c_int = 0;
pub const RTE_TOOLCHAIN_GCC: c_int = 1;
pub const RTE_VER_MINOR: c_int = 0;
pub const RTE_VER_MONTH: c_int = 11;
pub const RTE_VER_RELEASE: c_int = 0;
pub const RTE_VER_YEAR: c_int = 16;
pub const RTE_VHOST_USER_CLIENT: c_int = 1;
pub const RTE_VHOST_USER_NO_RECONNECT: c_int = 2;
pub const RTE_VIRTIO_USER: c_int = 1;
pub const RTE_XABORT_CAPACITY: c_int = 8;
pub const RTE_XABORT_CONFLICT: c_int = 4;
pub const RTE_XABORT_DEBUG: c_int = 16;
pub const RTE_XABORT_EXPLICIT: c_int = 1;
pub const RTE_XABORT_LOCK_BUSY: c_int = 255;
pub const RTE_XABORT_NESTED: c_int = 32;
pub const RTE_XABORT_RETRY: c_int = 2;
pub const RTE_XBEGIN_STARTED: c_int = -1;
pub const SOCKET_ID_ANY: c_int = -1;
pub const STR_MULTI_TOKEN_SIZE: c_int = 4096;
pub const STR_TOKEN_SIZE: c_int = 128;
pub const US_PER_S: c_int = 1000000;


// Statics
extern "C"
{
	pub static mut cmdline_token_etheraddr_ops: cmdline_token_ops;
	pub static mut cmdline_token_ipaddr_ops: cmdline_token_ops;
	pub static mut cmdline_token_num_ops: cmdline_token_ops;
	pub static mut cmdline_token_portlist_ops: cmdline_token_ops;
	pub static mut cmdline_token_string_ops: cmdline_token_ops;
	pub static mut cmdline_vt100_commands: [*const c_char; 0usize];
	pub static mut eal_default_log_stream: *mut FILE;
	pub static mut eal_timer_source: timer_source;
	pub static mut lcore_config: [lcore_config; 128usize];
	pub static mut per_lcore__cpuset: c_void;
	pub static mut per_lcore__lcore_id: c_void;
	pub static mut per_lcore__rte_errno: c_void;
	pub static mut rte_cycles_vmware_tsc_map: c_int;
	pub static mut rte_logs: rte_logs;
	pub static mut rte_mempool_ops_table: rte_mempool_ops_table;
	pub static mut rte_port_ethdev_reader_ops: rte_port_in_ops;
	pub static mut rte_port_ethdev_writer_nodrop_ops: rte_port_out_ops;
	pub static mut rte_port_ethdev_writer_ops: rte_port_out_ops;
	pub static mut rte_port_ring_multi_reader_ops: rte_port_in_ops;
	pub static mut rte_port_ring_multi_writer_nodrop_ops: rte_port_out_ops;
	pub static mut rte_port_ring_multi_writer_ops: rte_port_out_ops;
	pub static mut rte_port_ring_reader_ipv4_frag_ops: rte_port_in_ops;
	pub static mut rte_port_ring_reader_ipv6_frag_ops: rte_port_in_ops;
	pub static mut rte_port_ring_reader_ops: rte_port_in_ops;
	pub static mut rte_port_ring_writer_ipv4_ras_ops: rte_port_out_ops;
	pub static mut rte_port_ring_writer_ipv6_ras_ops: rte_port_out_ops;
	pub static mut rte_port_ring_writer_nodrop_ops: rte_port_out_ops;
	pub static mut rte_port_ring_writer_ops: rte_port_out_ops;
	pub static mut rte_port_sched_reader_ops: rte_port_in_ops;
	pub static mut rte_port_sched_writer_ops: rte_port_out_ops;
	pub static mut rte_port_sink_ops: rte_port_out_ops;
	pub static mut rte_port_source_ops: rte_port_in_ops;
	pub static mut rte_power_freq_down: rte_power_freq_change_t;
	pub static mut rte_power_freq_max: rte_power_freq_change_t;
	pub static mut rte_power_freq_min: rte_power_freq_change_t;
	pub static mut rte_power_freq_up: rte_power_freq_change_t;
	pub static mut rte_power_freqs: rte_power_freqs_t;
	pub static mut rte_power_get_freq: rte_power_get_freq_t;
	pub static mut rte_power_set_freq: rte_power_set_freq_t;
	pub static mut rte_red_log2_1_minus_Wq: [uint16_t; 12usize];
	pub static mut rte_red_pow2_frac_inv: [uint16_t; 16usize];
	pub static mut rte_red_rand_seed: uint32_t;
	pub static mut rte_red_rand_val: uint32_t;
	pub static mut rte_rtm_supported: uint8_t;
	pub static mut rte_table_acl_ops: rte_table_ops;
	pub static mut rte_table_array_ops: rte_table_ops;
	pub static mut rte_table_hash_ext_dosig_ops: rte_table_ops;
	pub static mut rte_table_hash_ext_ops: rte_table_ops;
	pub static mut rte_table_hash_key16_ext_dosig_ops: rte_table_ops;
	pub static mut rte_table_hash_key16_ext_ops: rte_table_ops;
	pub static mut rte_table_hash_key16_lru_dosig_ops: rte_table_ops;
	pub static mut rte_table_hash_key16_lru_ops: rte_table_ops;
	pub static mut rte_table_hash_key32_ext_ops: rte_table_ops;
	pub static mut rte_table_hash_key32_lru_ops: rte_table_ops;
	pub static mut rte_table_hash_key8_ext_dosig_ops: rte_table_ops;
	pub static mut rte_table_hash_key8_ext_ops: rte_table_ops;
	pub static mut rte_table_hash_key8_lru_dosig_ops: rte_table_ops;
	pub static mut rte_table_hash_key8_lru_ops: rte_table_ops;
	pub static mut rte_table_hash_lru_dosig_ops: rte_table_ops;
	pub static mut rte_table_hash_lru_ops: rte_table_ops;
	pub static mut rte_table_lpm_ipv6_ops: rte_table_ops;
	pub static mut rte_table_lpm_ops: rte_table_ops;
	pub static mut rte_table_stub_ops: rte_table_ops;
}


// Functions
extern "C"
{
	pub fn __rte_panic(funcname: *const c_char, format: *const c_char, ...);
	pub fn cirbuf_add_buf_head(cbuf: *mut cirbuf, c: *const c_char, n: c_uint) -> c_int;
	pub fn cirbuf_add_buf_tail(cbuf: *mut cirbuf, c: *const c_char, n: c_uint) -> c_int;
	pub fn cirbuf_add_head(cbuf: *mut cirbuf, c: c_char);
	pub fn cirbuf_add_head_safe(cbuf: *mut cirbuf, c: c_char) -> c_int;
	pub fn cirbuf_add_tail(cbuf: *mut cirbuf, c: c_char);
	pub fn cirbuf_add_tail_safe(cbuf: *mut cirbuf, c: c_char) -> c_int;
	pub fn cirbuf_align_left(cbuf: *mut cirbuf) -> c_int;
	pub fn cirbuf_align_right(cbuf: *mut cirbuf) -> c_int;
	pub fn cirbuf_del_buf_head(cbuf: *mut cirbuf, size: c_uint) -> c_int;
	pub fn cirbuf_del_buf_tail(cbuf: *mut cirbuf, size: c_uint) -> c_int;
	pub fn cirbuf_del_head(cbuf: *mut cirbuf);
	pub fn cirbuf_del_head_safe(cbuf: *mut cirbuf) -> c_int;
	pub fn cirbuf_del_tail(cbuf: *mut cirbuf);
	pub fn cirbuf_del_tail_safe(cbuf: *mut cirbuf) -> c_int;
	pub fn cirbuf_get_buf_head(cbuf: *mut cirbuf, c: *mut c_char, size: c_uint) -> c_int;
	pub fn cirbuf_get_buf_tail(cbuf: *mut cirbuf, c: *mut c_char, size: c_uint) -> c_int;
	pub fn cirbuf_get_head(cbuf: *mut cirbuf) -> c_char;
	pub fn cirbuf_get_tail(cbuf: *mut cirbuf) -> c_char;
	pub fn cirbuf_init(cbuf: *mut cirbuf, buf: *mut c_char, start: c_uint, maxlen: c_uint) -> c_int;
	pub fn cmdline_complete(cl: *mut cmdline, buf: *const c_char, state: *mut c_int, dst: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_complete_get_elt_string(tk: *mut cmdline_parse_token_hdr_t, idx: c_int, dstbuf: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_complete_get_nb_string(tk: *mut cmdline_parse_token_hdr_t) -> c_int;
	pub fn cmdline_file_new(ctx: *mut cmdline_parse_ctx_t, prompt: *const c_char, path: *const c_char) -> *mut cmdline;
	pub fn cmdline_free(cl: *mut cmdline);
	pub fn cmdline_get_help_etheraddr(tk: *mut cmdline_parse_token_hdr_t, dstbuf: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_get_help_ipaddr(tk: *mut cmdline_parse_token_hdr_t, dstbuf: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_get_help_num(tk: *mut cmdline_parse_token_hdr_t, dstbuf: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_get_help_portlist(tk: *mut cmdline_parse_token_hdr_t, dstbuf: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_get_help_string(tk: *mut cmdline_parse_token_hdr_t, dstbuf: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_in(cl: *mut cmdline, buf: *const c_char, size: c_int) -> c_int;
	pub fn cmdline_interact(cl: *mut cmdline);
	pub fn cmdline_isendofcommand(c: c_char) -> c_int;
	pub fn cmdline_isendoftoken(c: c_char) -> c_int;
	pub fn cmdline_new(ctx: *mut cmdline_parse_ctx_t, prompt: *const c_char, s_in: c_int, s_out: c_int) -> *mut cmdline;
	pub fn cmdline_parse(cl: *mut cmdline, buf: *const c_char) -> c_int;
	pub fn cmdline_parse_etheraddr(tk: *mut cmdline_parse_token_hdr_t, srcbuf: *const c_char, res: *mut c_void, ressize: c_uint) -> c_int;
	pub fn cmdline_parse_ipaddr(tk: *mut cmdline_parse_token_hdr_t, srcbuf: *const c_char, res: *mut c_void, ressize: c_uint) -> c_int;
	pub fn cmdline_parse_num(tk: *mut cmdline_parse_token_hdr_t, srcbuf: *const c_char, res: *mut c_void, ressize: c_uint) -> c_int;
	pub fn cmdline_parse_portlist(tk: *mut cmdline_parse_token_hdr_t, srcbuf: *const c_char, res: *mut c_void, ressize: c_uint) -> c_int;
	pub fn cmdline_parse_string(tk: *mut cmdline_parse_token_hdr_t, srcbuf: *const c_char, res: *mut c_void, ressize: c_uint) -> c_int;
	pub fn cmdline_poll(cl: *mut cmdline) -> c_int;
	pub fn cmdline_printf(cl: *const cmdline, fmt: *const c_char, ...);
	pub fn cmdline_quit(cl: *mut cmdline);
	pub fn cmdline_set_prompt(cl: *mut cmdline, prompt: *const c_char);
	pub fn cmdline_stdin_exit(cl: *mut cmdline);
	pub fn cmdline_stdin_new(ctx: *mut cmdline_parse_ctx_t, prompt: *const c_char) -> *mut cmdline;
	pub fn cmdline_write_char(rdl: *mut rdline, c: c_char) -> c_int;
	pub fn eth_dev_null_create(name: *const c_char, numa_node: c_uint, packet_size: c_uint, packet_copy: c_uint) -> c_int;
	pub fn rdline_add_history(rdl: *mut rdline, buf: *const c_char) -> c_int;
	pub fn rdline_char_in(rdl: *mut rdline, c: c_char) -> c_int;
	pub fn rdline_clear_history(rdl: *mut rdline);
	pub fn rdline_get_buffer(rdl: *mut rdline) -> *const c_char;
	pub fn rdline_get_history_item(rdl: *mut rdline, i: c_uint) -> *mut c_char;
	pub fn rdline_init(rdl: *mut rdline, write_char: rdline_write_char_t, validate: rdline_validate_t, complete: rdline_complete_t) -> c_int;
	pub fn rdline_newline(rdl: *mut rdline, prompt: *const c_char);
	pub fn rdline_quit(rdl: *mut rdline);
	pub fn rdline_redisplay(rdl: *mut rdline);
	pub fn rdline_reset(rdl: *mut rdline);
	pub fn rdline_restart(rdl: *mut rdline);
	pub fn rdline_stop(rdl: *mut rdline);
	pub fn rte_acl_add_rules(ctx: *mut rte_acl_ctx, rules: *const rte_acl_rule, num: uint32_t) -> c_int;
	pub fn rte_acl_build(ctx: *mut rte_acl_ctx, cfg: *const rte_acl_config) -> c_int;
	pub fn rte_acl_classify(ctx: *const rte_acl_ctx, data: *mut *const uint8_t, results: *mut uint32_t, num: uint32_t, categories: uint32_t) -> c_int;
	pub fn rte_acl_classify_alg(ctx: *const rte_acl_ctx, data: *mut *const uint8_t, results: *mut uint32_t, num: uint32_t, categories: uint32_t, alg: rte_acl_classify_alg) -> c_int;
	pub fn rte_acl_create(param: *const rte_acl_param) -> *mut rte_acl_ctx;
	pub fn rte_acl_dump(ctx: *const rte_acl_ctx);
	pub fn rte_acl_find_existing(name: *const c_char) -> *mut rte_acl_ctx;
	pub fn rte_acl_free(ctx: *mut rte_acl_ctx);
	pub fn rte_acl_list_dump();
	pub fn rte_acl_reset(ctx: *mut rte_acl_ctx);
	pub fn rte_acl_reset_rules(ctx: *mut rte_acl_ctx);
	pub fn rte_acl_set_ctx_classify(ctx: *mut rte_acl_ctx, alg: rte_acl_classify_alg) -> c_int;
	pub fn rte_approx(alpha: f64, d: f64, p: *mut uint32_t, q: *mut uint32_t) -> c_int;
	pub fn rte_calloc(type_: *const c_char, num: size_t, size: size_t, align: c_uint) -> *mut c_void;
	pub fn rte_calloc_socket(type_: *const c_char, num: size_t, size: size_t, align: c_uint, socket: c_int) -> *mut c_void;
	pub fn rte_cfgfile_close(cfg: *mut rte_cfgfile) -> c_int;
	pub fn rte_cfgfile_get_entry(cfg: *mut rte_cfgfile, sectionname: *const c_char, entryname: *const c_char) -> *const c_char;
	pub fn rte_cfgfile_has_entry(cfg: *mut rte_cfgfile, sectionname: *const c_char, entryname: *const c_char) -> c_int;
	pub fn rte_cfgfile_has_section(cfg: *mut rte_cfgfile, sectionname: *const c_char) -> c_int;
	pub fn rte_cfgfile_load(filename: *const c_char, flags: c_int) -> *mut rte_cfgfile;
	pub fn rte_cfgfile_num_sections(cfg: *mut rte_cfgfile, sec_name: *const c_char, length: size_t) -> c_int;
	pub fn rte_cfgfile_section_entries(cfg: *mut rte_cfgfile, sectionname: *const c_char, entries: *mut rte_cfgfile_entry, max_entries: c_int) -> c_int;
	pub fn rte_cfgfile_section_entries_by_index(cfg: *mut rte_cfgfile, index: c_int, sectionname: *mut c_char, entries: *mut rte_cfgfile_entry, max_entries: c_int) -> c_int;
	pub fn rte_cfgfile_section_num_entries(cfg: *mut rte_cfgfile, sectionname: *const c_char) -> c_int;
	pub fn rte_cfgfile_sections(cfg: *mut rte_cfgfile, sections: *mut *mut c_char, max_sections: c_int) -> c_int;
	pub fn rte_cpu_check_supported();
	pub fn rte_cpu_get_flag_enabled(feature: rte_cpu_flag_t) -> c_int;
	pub fn rte_cpu_get_flag_name(feature: rte_cpu_flag_t) -> *const c_char;
	pub fn rte_crypto_op_pool_create(name: *const c_char, type_: rte_crypto_op_type, nb_elts: c_uint, cache_size: c_uint, priv_size: uint16_t, socket_id: c_int) -> *mut rte_mempool;
	pub fn rte_ctrlmbuf_init(mp: *mut rte_mempool, opaque_arg: *mut c_void, m: *mut c_void, i: c_uint);
	pub fn rte_delay_us(us: c_uint);
	pub fn rte_distributor_clear_returns(d: *mut rte_distributor);
	pub fn rte_distributor_create(name: *const c_char, socket_id: c_uint, num_workers: c_uint) -> *mut rte_distributor;
	pub fn rte_distributor_flush(d: *mut rte_distributor) -> c_int;
	pub fn rte_distributor_get_pkt(d: *mut rte_distributor, worker_id: c_uint, oldpkt: *mut rte_mbuf) -> *mut rte_mbuf;
	pub fn rte_distributor_poll_pkt(d: *mut rte_distributor, worker_id: c_uint) -> *mut rte_mbuf;
	pub fn rte_distributor_process(d: *mut rte_distributor, mbufs: *mut *mut rte_mbuf, num_mbufs: c_uint) -> c_int;
	pub fn rte_distributor_request_pkt(d: *mut rte_distributor, worker_id: c_uint, oldpkt: *mut rte_mbuf);
	pub fn rte_distributor_return_pkt(d: *mut rte_distributor, worker_id: c_uint, mbuf: *mut rte_mbuf) -> c_int;
	pub fn rte_distributor_returned_pkts(d: *mut rte_distributor, mbufs: *mut *mut rte_mbuf, max_mbufs: c_uint) -> c_int;
	pub fn rte_dump_physmem_layout(f: *mut FILE);
	pub fn rte_dump_registers();
	pub fn rte_dump_stack();
	pub fn rte_dump_tailq(f: *mut FILE);
	pub fn rte_eal_alarm_cancel(cb_fn: rte_eal_alarm_callback, cb_arg: *mut c_void) -> c_int;
	pub fn rte_eal_alarm_set(us: uint64_t, cb: rte_eal_alarm_callback, cb_arg: *mut c_void) -> c_int;
	pub fn rte_eal_dev_init() -> c_int;
	pub fn rte_eal_driver_register(driver: *mut rte_driver);
	pub fn rte_eal_driver_unregister(driver: *mut rte_driver);
	pub fn rte_eal_get_configuration() -> *mut rte_config;
	pub fn rte_eal_get_lcore_state(slave_id: c_uint) -> rte_lcore_state_t;
	pub fn rte_eal_get_physmem_layout() -> *const rte_memseg;
	pub fn rte_eal_get_physmem_size() -> uint64_t;
	pub fn rte_eal_has_hugepages() -> c_int;
	pub fn rte_eal_init(argc: c_int, argv: *mut *mut c_char) -> c_int;
	pub fn rte_eal_iopl_init() -> c_int;
	pub fn rte_eal_lcore_role(lcore_id: c_uint) -> rte_lcore_role_t;
	pub fn rte_eal_mp_remote_launch(f: lcore_function_t, arg: *mut c_void, call_master: rte_rmt_call_master_t) -> c_int;
	pub fn rte_eal_mp_wait_lcore();
	pub fn rte_eal_primary_proc_alive(config_file_path: *const c_char) -> c_int;
	pub fn rte_eal_process_type() -> rte_proc_type_t;
	pub fn rte_eal_remote_launch(f: lcore_function_t, arg: *mut c_void, slave_id: c_uint) -> c_int;
	pub fn rte_eal_tailq_lookup(name: *const c_char) -> *mut rte_tailq_head;
	pub fn rte_eal_tailq_register(t: *mut rte_tailq_elem) -> c_int;
	pub fn rte_eal_vdev_init(name: *const c_char, args: *const c_char) -> c_int;
	pub fn rte_eal_vdev_uninit(name: *const c_char) -> c_int;
	pub fn rte_eal_wait_lcore(slave_id: c_uint) -> c_int;
	pub fn rte_epoll_ctl(epfd: c_int, op: c_int, fd: c_int, event: *mut rte_epoll_event) -> c_int;
	pub fn rte_epoll_wait(epfd: c_int, events: *mut rte_epoll_event, maxevents: c_int, timeout: c_int) -> c_int;
	pub fn rte_eth_bond_active_slaves_get(bonded_port_id: uint8_t, slaves: *mut uint8_t, len: uint8_t) -> c_int;
	pub fn rte_eth_bond_create(name: *const c_char, mode: uint8_t, socket_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_free(name: *const c_char) -> c_int;
	pub fn rte_eth_bond_link_down_prop_delay_get(bonded_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_link_down_prop_delay_set(bonded_port_id: uint8_t, delay_ms: uint32_t) -> c_int;
	pub fn rte_eth_bond_link_monitoring_get(bonded_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_link_monitoring_set(bonded_port_id: uint8_t, internal_ms: uint32_t) -> c_int;
	pub fn rte_eth_bond_link_up_prop_delay_get(bonded_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_link_up_prop_delay_set(bonded_port_id: uint8_t, delay_ms: uint32_t) -> c_int;
	pub fn rte_eth_bond_mac_address_reset(bonded_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_mac_address_set(bonded_port_id: uint8_t, mac_addr: *mut ether_addr) -> c_int;
	pub fn rte_eth_bond_mode_get(bonded_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_mode_set(bonded_port_id: uint8_t, mode: uint8_t) -> c_int;
	pub fn rte_eth_bond_primary_get(bonded_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_primary_set(bonded_port_id: uint8_t, slave_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_slave_add(bonded_port_id: uint8_t, slave_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_slave_remove(bonded_port_id: uint8_t, slave_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_slaves_get(bonded_port_id: uint8_t, slaves: *mut uint8_t, len: uint8_t) -> c_int;
	pub fn rte_eth_bond_xmit_policy_get(bonded_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_xmit_policy_set(bonded_port_id: uint8_t, policy: uint8_t) -> c_int;
	pub fn rte_eth_from_ring(r: *mut rte_ring) -> c_int;
	pub fn rte_eth_from_rings(name: *const c_char, rx_queues: *mut *mut rte_ring, nb_rx_queues: c_uint, tx_queues: *mut *mut rte_ring, nb_tx_queues: c_uint, numa_node: c_uint) -> c_int;
	pub fn rte_eth_vhost_feature_disable(feature_mask: uint64_t) -> c_int;
	pub fn rte_eth_vhost_feature_enable(feature_mask: uint64_t) -> c_int;
	pub fn rte_eth_vhost_feature_get() -> uint64_t;
	pub fn rte_eth_vhost_get_queue_event(port_id: uint8_t, event: *mut rte_eth_vhost_queue_event) -> c_int;
	pub fn rte_exit(exit_code: c_int, format: *const c_char, ...);
	pub fn rte_fbk_hash_create(params: *const rte_fbk_hash_params) -> *mut rte_fbk_hash_table;
	pub fn rte_fbk_hash_find_existing(name: *const c_char) -> *mut rte_fbk_hash_table;
	pub fn rte_fbk_hash_free(ht: *mut rte_fbk_hash_table);
	pub fn rte_free(ptr: *mut c_void);
	pub fn rte_get_log_level() -> uint32_t;
	pub fn rte_get_log_type() -> uint32_t;
	pub fn rte_get_rx_ol_flag_name(mask: uint64_t) -> *const c_char;
	pub fn rte_get_tsc_hz() -> uint64_t;
	pub fn rte_get_tx_ol_flag_name(mask: uint64_t) -> *const c_char;
	pub fn rte_hash_add_key(h: *const rte_hash, key: *const c_void) -> int32_t;
	pub fn rte_hash_add_key_data(h: *const rte_hash, key: *const c_void, data: *mut c_void) -> c_int;
	pub fn rte_hash_add_key_with_hash(h: *const rte_hash, key: *const c_void, sig: hash_sig_t) -> int32_t;
	pub fn rte_hash_add_key_with_hash_data(h: *const rte_hash, key: *const c_void, sig: hash_sig_t, data: *mut c_void) -> int32_t;
	pub fn rte_hash_create(params: *const rte_hash_parameters) -> *mut rte_hash;
	pub fn rte_hash_del_key(h: *const rte_hash, key: *const c_void) -> int32_t;
	pub fn rte_hash_del_key_with_hash(h: *const rte_hash, key: *const c_void, sig: hash_sig_t) -> int32_t;
	pub fn rte_hash_find_existing(name: *const c_char) -> *mut rte_hash;
	pub fn rte_hash_free(h: *mut rte_hash);
	pub fn rte_hash_get_key_with_position(h: *const rte_hash, position: int32_t, key: *mut *mut c_void) -> c_int;
	pub fn rte_hash_hash(h: *const rte_hash, key: *const c_void) -> hash_sig_t;
	pub fn rte_hash_iterate(h: *const rte_hash, key: *mut *const c_void, data: *mut *mut c_void, next: *mut uint32_t) -> int32_t;
	pub fn rte_hash_lookup(h: *const rte_hash, key: *const c_void) -> int32_t;
	pub fn rte_hash_lookup_bulk(h: *const rte_hash, keys: *mut *const c_void, num_keys: uint32_t, positions: *mut int32_t) -> c_int;
	pub fn rte_hash_lookup_bulk_data(h: *const rte_hash, keys: *mut *const c_void, num_keys: uint32_t, hit_mask: *mut uint64_t, data: *mut *mut c_void) -> c_int;
	pub fn rte_hash_lookup_data(h: *const rte_hash, key: *const c_void, data: *mut *mut c_void) -> c_int;
	pub fn rte_hash_lookup_with_hash(h: *const rte_hash, key: *const c_void, sig: hash_sig_t) -> int32_t;
	pub fn rte_hash_lookup_with_hash_data(h: *const rte_hash, key: *const c_void, sig: hash_sig_t, data: *mut *mut c_void) -> c_int;
	pub fn rte_hash_reset(h: *mut rte_hash);
	pub fn rte_hash_set_cmp_func(h: *mut rte_hash, func: rte_hash_cmp_eq_t);
	pub fn rte_hexdump(f: *mut FILE, title: *const c_char, buf: *const c_void, len: c_uint);
	pub fn rte_intr_allow_others(intr_handle: *mut rte_intr_handle) -> c_int;
	pub fn rte_intr_callback_register(intr_handle: *mut rte_intr_handle, cb: rte_intr_callback_fn, cb_arg: *mut c_void) -> c_int;
	pub fn rte_intr_callback_unregister(intr_handle: *mut rte_intr_handle, cb: rte_intr_callback_fn, cb_arg: *mut c_void) -> c_int;
	pub fn rte_intr_cap_multiple(intr_handle: *mut rte_intr_handle) -> c_int;
	pub fn rte_intr_disable(intr_handle: *mut rte_intr_handle) -> c_int;
	pub fn rte_intr_dp_is_en(intr_handle: *mut rte_intr_handle) -> c_int;
	pub fn rte_intr_efd_disable(intr_handle: *mut rte_intr_handle);
	pub fn rte_intr_efd_enable(intr_handle: *mut rte_intr_handle, nb_efd: uint32_t) -> c_int;
	pub fn rte_intr_enable(intr_handle: *mut rte_intr_handle) -> c_int;
	pub fn rte_intr_rx_ctl(intr_handle: *mut rte_intr_handle, epfd: c_int, op: c_int, vec: c_uint, data: *mut c_void) -> c_int;
	pub fn rte_intr_tls_epfd() -> c_int;
	pub fn rte_ip_frag_free_death_row(dr: *mut rte_ip_frag_death_row, prefetch: uint32_t);
	pub fn rte_ip_frag_table_create(bucket_num: uint32_t, bucket_entries: uint32_t, max_entries: uint32_t, max_cycles: uint64_t, socket_id: c_int) -> *mut rte_ip_frag_tbl;
	pub fn rte_ip_frag_table_statistics_dump(f: *mut FILE, tbl: *const rte_ip_frag_tbl);
	pub fn rte_ipv4_frag_reassemble_packet(tbl: *mut rte_ip_frag_tbl, dr: *mut rte_ip_frag_death_row, mb: *mut rte_mbuf, tms: uint64_t, ip_hdr: *mut ipv4_hdr) -> *mut rte_mbuf;
	pub fn rte_ipv4_fragment_packet(pkt_in: *mut rte_mbuf, pkts_out: *mut *mut rte_mbuf, nb_pkts_out: uint16_t, mtu_size: uint16_t, pool_direct: *mut rte_mempool, pool_indirect: *mut rte_mempool) -> int32_t;
	pub fn rte_ipv6_frag_reassemble_packet(tbl: *mut rte_ip_frag_tbl, dr: *mut rte_ip_frag_death_row, mb: *mut rte_mbuf, tms: uint64_t, ip_hdr: *mut ipv6_hdr, frag_hdr: *mut ipv6_extension_fragment) -> *mut rte_mbuf;
	pub fn rte_ipv6_fragment_packet(pkt_in: *mut rte_mbuf, pkts_out: *mut *mut rte_mbuf, nb_pkts_out: uint16_t, mtu_size: uint16_t, pool_direct: *mut rte_mempool, pool_indirect: *mut rte_mempool) -> int32_t;
	pub fn rte_jobstats_abort(job: *mut rte_jobstats) -> c_int;
	pub fn rte_jobstats_context_finish(ctx: *mut rte_jobstats_context);
	pub fn rte_jobstats_context_init(ctx: *mut rte_jobstats_context) -> c_int;
	pub fn rte_jobstats_context_reset(ctx: *mut rte_jobstats_context);
	pub fn rte_jobstats_context_start(ctx: *mut rte_jobstats_context);
	pub fn rte_jobstats_finish(job: *mut rte_jobstats, job_value: int64_t) -> c_int;
	pub fn rte_jobstats_init(job: *mut rte_jobstats, name: *const c_char, min_period: uint64_t, max_period: uint64_t, initial_period: uint64_t, target: int64_t) -> c_int;
	pub fn rte_jobstats_reset(job: *mut rte_jobstats);
	pub fn rte_jobstats_set_max(job: *mut rte_jobstats, period: uint64_t);
	pub fn rte_jobstats_set_min(job: *mut rte_jobstats, period: uint64_t);
	pub fn rte_jobstats_set_period(job: *mut rte_jobstats, period: uint64_t, saturate: uint8_t);
	pub fn rte_jobstats_set_target(job: *mut rte_jobstats, target: int64_t);
	pub fn rte_jobstats_set_update_period_function(job: *mut rte_jobstats, update_period_cb: rte_job_update_period_cb_t);
	pub fn rte_jobstats_start(ctx: *mut rte_jobstats_context, job: *mut rte_jobstats) -> c_int;
	pub fn rte_keepalive_create(callback: rte_keepalive_failure_callback_t, data: *mut c_void) -> *mut rte_keepalive;
	pub fn rte_keepalive_dispatch_pings(ptr_timer: *mut c_void, ptr_data: *mut c_void);
	pub fn rte_keepalive_mark_alive(keepcfg: *mut rte_keepalive);
	pub fn rte_keepalive_mark_sleep(keepcfg: *mut rte_keepalive);
	pub fn rte_keepalive_register_core(keepcfg: *mut rte_keepalive, id_core: c_int);
	pub fn rte_keepalive_register_relay_callback(keepcfg: *mut rte_keepalive, callback: rte_keepalive_relay_callback_t, data: *mut c_void);
	pub fn rte_kvargs_count(kvlist: *const rte_kvargs, key_match: *const c_char) -> c_uint;
	pub fn rte_kvargs_free(kvlist: *mut rte_kvargs);
	pub fn rte_kvargs_parse(args: *const c_char, valid_keys: *mut *const c_char) -> *mut rte_kvargs;
	pub fn rte_kvargs_process(kvlist: *const rte_kvargs, key_match: *const c_char, handler: arg_handler_t, opaque_arg: *mut c_void) -> c_int;
	pub fn rte_log(level: uint32_t, logtype: uint32_t, format: *const c_char, ...) -> c_int;
	pub fn rte_log_cur_msg_loglevel() -> c_int;
	pub fn rte_log_cur_msg_logtype() -> c_int;
	pub fn rte_lpm6_add(lpm: *mut rte_lpm6, ip: *mut uint8_t, depth: uint8_t, next_hop: uint8_t) -> c_int;
	pub fn rte_lpm6_create(name: *const c_char, socket_id: c_int, config: *const rte_lpm6_config) -> *mut rte_lpm6;
	pub fn rte_lpm6_delete(lpm: *mut rte_lpm6, ip: *mut uint8_t, depth: uint8_t) -> c_int;
	pub fn rte_lpm6_delete_all(lpm: *mut rte_lpm6);
	pub fn rte_lpm6_delete_bulk_func(lpm: *mut rte_lpm6, ips: *mut [uint8_t; 16usize], depths: *mut uint8_t, n: c_uint) -> c_int;
	pub fn rte_lpm6_find_existing(name: *const c_char) -> *mut rte_lpm6;
	pub fn rte_lpm6_free(lpm: *mut rte_lpm6);
	pub fn rte_lpm6_is_rule_present(lpm: *mut rte_lpm6, ip: *mut uint8_t, depth: uint8_t, next_hop: *mut uint8_t) -> c_int;
	pub fn rte_lpm6_lookup(lpm: *const rte_lpm6, ip: *mut uint8_t, next_hop: *mut uint8_t) -> c_int;
	pub fn rte_lpm6_lookup_bulk_func(lpm: *const rte_lpm6, ips: *mut [uint8_t; 16usize], next_hops: *mut int16_t, n: c_uint) -> c_int;
	pub fn rte_lpm_add(lpm: *mut rte_lpm, ip: uint32_t, depth: uint8_t, next_hop: uint32_t) -> c_int;
	pub fn rte_lpm_add_v1604(lpm: *mut rte_lpm, ip: uint32_t, depth: uint8_t, next_hop: uint32_t) -> c_int;
	pub fn rte_lpm_add_v20(lpm: *mut rte_lpm_v20, ip: uint32_t, depth: uint8_t, next_hop: uint8_t) -> c_int;
	pub fn rte_lpm_create(name: *const c_char, socket_id: c_int, config: *const rte_lpm_config) -> *mut rte_lpm;
	pub fn rte_lpm_create_v1604(name: *const c_char, socket_id: c_int, config: *const rte_lpm_config) -> *mut rte_lpm;
	pub fn rte_lpm_create_v20(name: *const c_char, socket_id: c_int, max_rules: c_int, flags: c_int) -> *mut rte_lpm_v20;
	pub fn rte_lpm_delete(lpm: *mut rte_lpm, ip: uint32_t, depth: uint8_t) -> c_int;
	pub fn rte_lpm_delete_all(lpm: *mut rte_lpm);
	pub fn rte_lpm_delete_all_v1604(lpm: *mut rte_lpm);
	pub fn rte_lpm_delete_all_v20(lpm: *mut rte_lpm_v20);
	pub fn rte_lpm_delete_v1604(lpm: *mut rte_lpm, ip: uint32_t, depth: uint8_t) -> c_int;
	pub fn rte_lpm_delete_v20(lpm: *mut rte_lpm_v20, ip: uint32_t, depth: uint8_t) -> c_int;
	pub fn rte_lpm_find_existing(name: *const c_char) -> *mut rte_lpm;
	pub fn rte_lpm_find_existing_v1604(name: *const c_char) -> *mut rte_lpm;
	pub fn rte_lpm_find_existing_v20(name: *const c_char) -> *mut rte_lpm_v20;
	pub fn rte_lpm_free(lpm: *mut rte_lpm);
	pub fn rte_lpm_free_v1604(lpm: *mut rte_lpm);
	pub fn rte_lpm_free_v20(lpm: *mut rte_lpm_v20);
	pub fn rte_lpm_is_rule_present(lpm: *mut rte_lpm, ip: uint32_t, depth: uint8_t, next_hop: *mut uint32_t) -> c_int;
	pub fn rte_lpm_is_rule_present_v1604(lpm: *mut rte_lpm, ip: uint32_t, depth: uint8_t, next_hop: *mut uint32_t) -> c_int;
	pub fn rte_lpm_is_rule_present_v20(lpm: *mut rte_lpm_v20, ip: uint32_t, depth: uint8_t, next_hop: *mut uint8_t) -> c_int;
	pub fn rte_malloc(type_: *const c_char, size: size_t, align: c_uint) -> *mut c_void;
	pub fn rte_malloc_dump_stats(f: *mut FILE, type_: *const c_char);
	pub fn rte_malloc_get_socket_stats(socket: c_int, socket_stats: *mut rte_malloc_socket_stats) -> c_int;
	pub fn rte_malloc_set_limit(type_: *const c_char, max: size_t) -> c_int;
	pub fn rte_malloc_socket(type_: *const c_char, size: size_t, align: c_uint, socket: c_int) -> *mut c_void;
	pub fn rte_malloc_validate(ptr: *const c_void, size: *mut size_t) -> c_int;
	pub fn rte_malloc_virt2phy(addr: *const c_void) -> phys_addr_t;
	pub fn rte_mbuf_sanity_check(m: *const rte_mbuf, is_header: c_int);
	pub fn rte_mem_lock_page(virt: *const c_void) -> c_int;
	pub fn rte_mem_virt2phy(virt: *const c_void) -> phys_addr_t;
	pub fn rte_memdump(f: *mut FILE, title: *const c_char, buf: *const c_void, len: c_uint);
	pub fn rte_memory_get_nchannel() -> c_uint;
	pub fn rte_memory_get_nrank() -> c_uint;
	pub fn rte_mempool_audit(mp: *mut rte_mempool);
	pub fn rte_mempool_avail_count(mp: *const rte_mempool) -> c_uint;
	pub fn rte_mempool_cache_create(size: uint32_t, socket_id: c_int) -> *mut rte_mempool_cache;
	pub fn rte_mempool_cache_free(cache: *mut rte_mempool_cache);
	pub fn rte_mempool_calc_obj_size(elt_size: uint32_t, flags: uint32_t, sz: *mut rte_mempool_objsz) -> uint32_t;
	pub fn rte_mempool_check_cookies(mp: *const rte_mempool, obj_table_const: *const *mut c_void, n: c_uint, free: c_int);
	pub fn rte_mempool_count(mp: *const rte_mempool) -> c_uint;
	pub fn rte_mempool_create(name: *const c_char, n: c_uint, elt_size: c_uint, cache_size: c_uint, private_data_size: c_uint, mp_init: rte_mempool_ctor_t, mp_init_arg: *mut c_void, obj_init: rte_mempool_obj_cb_t, obj_init_arg: *mut c_void, socket_id: c_int, flags: c_uint) -> *mut rte_mempool;
	pub fn rte_mempool_create_empty(name: *const c_char, n: c_uint, elt_size: c_uint, cache_size: c_uint, private_data_size: c_uint, socket_id: c_int, flags: c_uint) -> *mut rte_mempool;
	pub fn rte_mempool_dump(f: *mut FILE, mp: *mut rte_mempool);
	pub fn rte_mempool_free(mp: *mut rte_mempool);
	pub fn rte_mempool_in_use_count(mp: *const rte_mempool) -> c_uint;
	pub fn rte_mempool_list_dump(f: *mut FILE);
	pub fn rte_mempool_lookup(name: *const c_char) -> *mut rte_mempool;
	pub fn rte_mempool_mem_iter(mp: *mut rte_mempool, mem_cb: rte_mempool_mem_cb_t, mem_cb_arg: *mut c_void) -> uint32_t;
	pub fn rte_mempool_obj_iter(mp: *mut rte_mempool, obj_cb: rte_mempool_obj_cb_t, obj_cb_arg: *mut c_void) -> uint32_t;
	pub fn rte_mempool_ops_alloc(mp: *mut rte_mempool) -> c_int;
	pub fn rte_mempool_ops_free(mp: *mut rte_mempool);
	pub fn rte_mempool_ops_get_count(mp: *const rte_mempool) -> c_uint;
	pub fn rte_mempool_populate_anon(mp: *mut rte_mempool) -> c_int;
	pub fn rte_mempool_populate_default(mp: *mut rte_mempool) -> c_int;
	pub fn rte_mempool_populate_phys(mp: *mut rte_mempool, vaddr: *mut c_char, paddr: phys_addr_t, len: size_t, free_cb: rte_mempool_memchunk_free_cb_t, opaque: *mut c_void) -> c_int;
	pub fn rte_mempool_populate_phys_tab(mp: *mut rte_mempool, vaddr: *mut c_char, paddr: *mut phys_addr_t, pg_num: uint32_t, pg_shift: uint32_t, free_cb: rte_mempool_memchunk_free_cb_t, opaque: *mut c_void) -> c_int;
	pub fn rte_mempool_populate_virt(mp: *mut rte_mempool, addr: *mut c_char, len: size_t, pg_sz: size_t, free_cb: rte_mempool_memchunk_free_cb_t, opaque: *mut c_void) -> c_int;
	pub fn rte_mempool_register_ops(ops: *const rte_mempool_ops) -> c_int;
	pub fn rte_mempool_set_ops_byname(mp: *mut rte_mempool, name: *const c_char, pool_config: *mut c_void) -> c_int;
	pub fn rte_mempool_walk(func: Option<unsafe extern "C" fn(arg1: *mut rte_mempool, arg: *mut c_void)>, arg: *mut c_void);
	pub fn rte_mempool_xmem_create(name: *const c_char, n: c_uint, elt_size: c_uint, cache_size: c_uint, private_data_size: c_uint, mp_init: rte_mempool_ctor_t, mp_init_arg: *mut c_void, obj_init: rte_mempool_obj_cb_t, obj_init_arg: *mut c_void, socket_id: c_int, flags: c_uint, vaddr: *mut c_void, paddr: *mut phys_addr_t, pg_num: uint32_t, pg_shift: uint32_t) -> *mut rte_mempool;
	pub fn rte_mempool_xmem_size(elt_num: uint32_t, total_elt_sz: size_t, pg_shift: uint32_t) -> size_t;
	pub fn rte_mempool_xmem_usage(vaddr: *mut c_void, elt_num: uint32_t, total_elt_sz: size_t, paddr: *mut phys_addr_t, pg_num: uint32_t, pg_shift: uint32_t) -> ssize_t;
	pub fn rte_memzone_dump(f: *mut FILE);
	pub fn rte_memzone_free(mz: *const rte_memzone) -> c_int;
	pub fn rte_memzone_lookup(name: *const c_char) -> *const rte_memzone;
	pub fn rte_memzone_reserve(name: *const c_char, len: size_t, socket_id: c_int, flags: c_uint) -> *const rte_memzone;
	pub fn rte_memzone_reserve_aligned(name: *const c_char, len: size_t, socket_id: c_int, flags: c_uint, align: c_uint) -> *const rte_memzone;
	pub fn rte_memzone_reserve_bounded(name: *const c_char, len: size_t, socket_id: c_int, flags: c_uint, align: c_uint, bound: c_uint) -> *const rte_memzone;
	pub fn rte_memzone_walk(func: Option<unsafe extern "C" fn(arg1: *const rte_memzone, arg: *mut c_void)>, arg: *mut c_void);
	pub fn rte_meter_srtcm_config(m: *mut rte_meter_srtcm, params: *mut rte_meter_srtcm_params) -> c_int;
	pub fn rte_meter_trtcm_config(m: *mut rte_meter_trtcm, params: *mut rte_meter_trtcm_params) -> c_int;
	pub fn rte_openlog_stream(f: *mut FILE) -> c_int;
	pub fn rte_pdump_disable(port: uint8_t, queue: uint16_t, flags: uint32_t) -> c_int;
	pub fn rte_pdump_disable_by_deviceid(device_id: *mut c_char, queue: uint16_t, flags: uint32_t) -> c_int;
	pub fn rte_pdump_enable(port: uint8_t, queue: uint16_t, flags: uint32_t, ring: *mut rte_ring, mp: *mut rte_mempool, filter: *mut c_void) -> c_int;
	pub fn rte_pdump_enable_by_deviceid(device_id: *mut c_char, queue: uint16_t, flags: uint32_t, ring: *mut rte_ring, mp: *mut rte_mempool, filter: *mut c_void) -> c_int;
	pub fn rte_pdump_init(path: *const c_char) -> c_int;
	pub fn rte_pdump_set_socket_dir(path: *const c_char, type_: rte_pdump_socktype) -> c_int;
	pub fn rte_pdump_uninit() -> c_int;
	pub fn rte_pipeline_ah_packet_drop(p: *mut rte_pipeline, pkts_mask: uint64_t) -> c_int;
	pub fn rte_pipeline_ah_packet_hijack(p: *mut rte_pipeline, pkts_mask: uint64_t) -> c_int;
	pub fn rte_pipeline_check(p: *mut rte_pipeline) -> c_int;
	pub fn rte_pipeline_create(params: *mut rte_pipeline_params) -> *mut rte_pipeline;
	pub fn rte_pipeline_flush(p: *mut rte_pipeline) -> c_int;
	pub fn rte_pipeline_free(p: *mut rte_pipeline) -> c_int;
	pub fn rte_pipeline_port_in_connect_to_table(p: *mut rte_pipeline, port_id: uint32_t, table_id: uint32_t) -> c_int;
	pub fn rte_pipeline_port_in_create(p: *mut rte_pipeline, params: *mut rte_pipeline_port_in_params, port_id: *mut uint32_t) -> c_int;
	pub fn rte_pipeline_port_in_disable(p: *mut rte_pipeline, port_id: uint32_t) -> c_int;
	pub fn rte_pipeline_port_in_enable(p: *mut rte_pipeline, port_id: uint32_t) -> c_int;
	pub fn rte_pipeline_port_in_stats_read(p: *mut rte_pipeline, port_id: uint32_t, stats: *mut rte_pipeline_port_in_stats, clear: c_int) -> c_int;
	pub fn rte_pipeline_port_out_create(p: *mut rte_pipeline, params: *mut rte_pipeline_port_out_params, port_id: *mut uint32_t) -> c_int;
	pub fn rte_pipeline_port_out_packet_insert(p: *mut rte_pipeline, port_id: uint32_t, pkt: *mut rte_mbuf) -> c_int;
	pub fn rte_pipeline_port_out_stats_read(p: *mut rte_pipeline, port_id: uint32_t, stats: *mut rte_pipeline_port_out_stats, clear: c_int) -> c_int;
	pub fn rte_pipeline_run(p: *mut rte_pipeline) -> c_int;
	pub fn rte_pipeline_table_create(p: *mut rte_pipeline, params: *mut rte_pipeline_table_params, table_id: *mut uint32_t) -> c_int;
	pub fn rte_pipeline_table_default_entry_add(p: *mut rte_pipeline, table_id: uint32_t, default_entry: *mut rte_pipeline_table_entry, default_entry_ptr: *mut *mut rte_pipeline_table_entry) -> c_int;
	pub fn rte_pipeline_table_default_entry_delete(p: *mut rte_pipeline, table_id: uint32_t, entry: *mut rte_pipeline_table_entry) -> c_int;
	pub fn rte_pipeline_table_entry_add(p: *mut rte_pipeline, table_id: uint32_t, key: *mut c_void, entry: *mut rte_pipeline_table_entry, key_found: *mut c_int, entry_ptr: *mut *mut rte_pipeline_table_entry) -> c_int;
	pub fn rte_pipeline_table_entry_add_bulk(p: *mut rte_pipeline, table_id: uint32_t, keys: *mut *mut c_void, entries: *mut *mut rte_pipeline_table_entry, n_keys: uint32_t, key_found: *mut c_int, entries_ptr: *mut *mut rte_pipeline_table_entry) -> c_int;
	pub fn rte_pipeline_table_entry_delete(p: *mut rte_pipeline, table_id: uint32_t, key: *mut c_void, key_found: *mut c_int, entry: *mut rte_pipeline_table_entry) -> c_int;
	pub fn rte_pipeline_table_entry_delete_bulk(p: *mut rte_pipeline, table_id: uint32_t, keys: *mut *mut c_void, n_keys: uint32_t, key_found: *mut c_int, entries: *mut *mut rte_pipeline_table_entry) -> c_int;
	pub fn rte_pipeline_table_stats_read(p: *mut rte_pipeline, table_id: uint32_t, stats: *mut rte_pipeline_table_stats, clear: c_int) -> c_int;
	pub fn rte_pktmbuf_dump(f: *mut FILE, m: *const rte_mbuf, dump_len: c_uint);
	pub fn rte_pktmbuf_init(mp: *mut rte_mempool, opaque_arg: *mut c_void, m: *mut c_void, i: c_uint);
	pub fn rte_pktmbuf_pool_create(name: *const c_char, n: c_uint, cache_size: c_uint, priv_size: uint16_t, data_room_size: uint16_t, socket_id: c_int) -> *mut rte_mempool;
	pub fn rte_pktmbuf_pool_init(mp: *mut rte_mempool, opaque_arg: *mut c_void);
	pub fn rte_power_exit(lcore_id: c_uint) -> c_int;
	pub fn rte_power_get_env() -> power_management_env;
	pub fn rte_power_init(lcore_id: c_uint) -> c_int;
	pub fn rte_power_set_env(env: power_management_env) -> c_int;
	pub fn rte_power_unset_env();
	pub fn rte_realloc(ptr: *mut c_void, size: size_t, align: c_uint) -> *mut c_void;
	pub fn rte_reciprocal_value(d: uint32_t) -> rte_reciprocal;
	pub fn rte_red_config_init(red_cfg: *mut rte_red_config, wq_log2: uint16_t, min_th: uint16_t, max_th: uint16_t, maxp_inv: uint16_t) -> c_int;
	pub fn rte_red_rt_data_init(red: *mut rte_red) -> c_int;
	pub fn rte_reorder_create(name: *const c_char, socket_id: c_uint, size: c_uint) -> *mut rte_reorder_buffer;
	pub fn rte_reorder_drain(b: *mut rte_reorder_buffer, mbufs: *mut *mut rte_mbuf, max_mbufs: c_uint) -> c_uint;
	pub fn rte_reorder_find_existing(name: *const c_char) -> *mut rte_reorder_buffer;
	pub fn rte_reorder_free(b: *mut rte_reorder_buffer);
	pub fn rte_reorder_init(b: *mut rte_reorder_buffer, bufsize: c_uint, name: *const c_char, size: c_uint) -> *mut rte_reorder_buffer;
	pub fn rte_reorder_insert(b: *mut rte_reorder_buffer, mbuf: *mut rte_mbuf) -> c_int;
	pub fn rte_reorder_reset(b: *mut rte_reorder_buffer);
	pub fn rte_ring_create(name: *const c_char, count: c_uint, socket_id: c_int, flags: c_uint) -> *mut rte_ring;
	pub fn rte_ring_dump(f: *mut FILE, r: *const rte_ring);
	pub fn rte_ring_free(r: *mut rte_ring);
	pub fn rte_ring_get_memsize(count: c_uint) -> ssize_t;
	pub fn rte_ring_init(r: *mut rte_ring, name: *const c_char, count: c_uint, flags: c_uint) -> c_int;
	pub fn rte_ring_list_dump(f: *mut FILE);
	pub fn rte_ring_lookup(name: *const c_char) -> *mut rte_ring;
	pub fn rte_ring_set_water_mark(r: *mut rte_ring, count: c_uint) -> c_int;
	pub fn rte_sched_pipe_config(port: *mut rte_sched_port, subport_id: uint32_t, pipe_id: uint32_t, pipe_profile: int32_t) -> c_int;
	pub fn rte_sched_port_config(params: *mut rte_sched_port_params) -> *mut rte_sched_port;
	pub fn rte_sched_port_dequeue(port: *mut rte_sched_port, pkts: *mut *mut rte_mbuf, n_pkts: uint32_t) -> c_int;
	pub fn rte_sched_port_enqueue(port: *mut rte_sched_port, pkts: *mut *mut rte_mbuf, n_pkts: uint32_t) -> c_int;
	pub fn rte_sched_port_free(port: *mut rte_sched_port);
	pub fn rte_sched_port_get_memory_footprint(params: *mut rte_sched_port_params) -> uint32_t;
	pub fn rte_sched_port_pkt_read_color(pkt: *const rte_mbuf) -> rte_meter_color;
	pub fn rte_sched_port_pkt_read_tree_path(pkt: *const rte_mbuf, subport: *mut uint32_t, pipe: *mut uint32_t, traffic_class: *mut uint32_t, queue: *mut uint32_t);
	pub fn rte_sched_port_pkt_write(pkt: *mut rte_mbuf, subport: uint32_t, pipe: uint32_t, traffic_class: uint32_t, queue: uint32_t, color: rte_meter_color);
	pub fn rte_sched_queue_read_stats(port: *mut rte_sched_port, queue_id: uint32_t, stats: *mut rte_sched_queue_stats, qlen: *mut uint16_t) -> c_int;
	pub fn rte_sched_subport_config(port: *mut rte_sched_port, subport_id: uint32_t, params: *mut rte_sched_subport_params) -> c_int;
	pub fn rte_sched_subport_read_stats(port: *mut rte_sched_port, subport_id: uint32_t, stats: *mut rte_sched_subport_stats, tc_ov: *mut uint32_t) -> c_int;
	pub fn rte_set_application_usage_hook(usage_func: rte_usage_hook_t) -> rte_usage_hook_t;
	pub fn rte_set_log_level(level: uint32_t);
	pub fn rte_set_log_type(type_: uint32_t, enable: c_int);
	pub fn rte_socket_id() -> c_uint;
	pub fn rte_strerror(errnum: c_int) -> *const c_char;
	pub fn rte_strsplit(string: *mut c_char, stringlen: c_int, tokens: *mut *mut c_char, maxtokens: c_int, delim: c_char) -> c_int;
	pub fn rte_sys_gettid() -> c_int;
	pub fn rte_thread_get_affinity(cpusetp: *mut rte_cpuset_t);
	pub fn rte_thread_set_affinity(cpusetp: *mut rte_cpuset_t) -> c_int;
	pub fn rte_thread_setname(id: pthread_t, name: *const c_char) -> c_int;
	pub fn rte_timer_dump_stats(f: *mut FILE);
	pub fn rte_timer_init(tim: *mut rte_timer);
	pub fn rte_timer_manage();
	pub fn rte_timer_pending(tim: *mut rte_timer) -> c_int;
	pub fn rte_timer_reset(tim: *mut rte_timer, ticks: uint64_t, type_: rte_timer_type, tim_lcore: c_uint, fct: rte_timer_cb_t, arg: *mut c_void) -> c_int;
	pub fn rte_timer_reset_sync(tim: *mut rte_timer, ticks: uint64_t, type_: rte_timer_type, tim_lcore: c_uint, fct: rte_timer_cb_t, arg: *mut c_void);
	pub fn rte_timer_stop(tim: *mut rte_timer) -> c_int;
	pub fn rte_timer_stop_sync(tim: *mut rte_timer);
	pub fn rte_timer_subsystem_init();
	pub fn rte_vhost_avail_entries(vid: c_int, queue_id: uint16_t) -> uint16_t;
	pub fn rte_vhost_dequeue_burst(vid: c_int, queue_id: uint16_t, mbuf_pool: *mut rte_mempool, pkts: *mut *mut rte_mbuf, count: uint16_t) -> uint16_t;
	pub fn rte_vhost_driver_callback_register(arg1: *const virtio_net_device_ops) -> c_int;
	pub fn rte_vhost_driver_register(path: *const c_char, flags: uint64_t) -> c_int;
	pub fn rte_vhost_driver_session_start() -> c_int;
	pub fn rte_vhost_driver_unregister(path: *const c_char) -> c_int;
	pub fn rte_vhost_enable_guest_notification(vid: c_int, queue_id: uint16_t, enable: c_int) -> c_int;
	pub fn rte_vhost_enqueue_burst(vid: c_int, queue_id: uint16_t, pkts: *mut *mut rte_mbuf, count: uint16_t) -> uint16_t;
	pub fn rte_vhost_feature_disable(feature_mask: uint64_t) -> c_int;
	pub fn rte_vhost_feature_enable(feature_mask: uint64_t) -> c_int;
	pub fn rte_vhost_feature_get() -> uint64_t;
	pub fn rte_vhost_get_ifname(vid: c_int, buf: *mut c_char, len: size_t) -> c_int;
	pub fn rte_vhost_get_numa_node(vid: c_int) -> c_int;
	pub fn rte_vhost_get_queue_num(vid: c_int) -> uint32_t;
	pub fn rte_vlog(level: uint32_t, logtype: uint32_t, format: *const c_char, ap: va_list) -> c_int;
	pub fn rte_zmalloc(type_: *const c_char, size: size_t, align: c_uint) -> *mut c_void;
	pub fn rte_zmalloc_socket(type_: *const c_char, size: size_t, align: c_uint, socket: c_int) -> *mut c_void;
	pub fn vt100_init(vt: *mut cmdline_vt100);
	pub fn vt100_parser(vt: *mut cmdline_vt100, c: c_char) -> c_int;
}


// Types
include!("types/MARKER.rs");
include!("types/MARKER64.rs");
include!("types/MARKER8.rs");
include!("types/arg_handler_t.rs");
include!("types/cmdline_fixed_string_t.rs");
include!("types/cmdline_ipaddr_t.rs");
include!("types/cmdline_multi_string_t.rs");
include!("types/cmdline_parse_ctx_t.rs");
include!("types/cmdline_parse_inst_t.rs");
include!("types/cmdline_parse_token_etheraddr_t.rs");
include!("types/cmdline_parse_token_hdr_t.rs");
include!("types/cmdline_parse_token_ipaddr_t.rs");
include!("types/cmdline_parse_token_num_t.rs");
include!("types/cmdline_parse_token_portlist_t.rs");
include!("types/cmdline_parse_token_string_t.rs");
include!("types/cmdline_portlist_t.rs");
include!("types/hash_sig_t.rs");
include!("types/lcore_function_t.rs");
include!("types/phys_addr_t.rs");
include!("types/rdline_complete_t.rs");
include!("types/rdline_validate_t.rs");
include!("types/rdline_write_char_t.rs");
include!("types/rte_cpuset_t.rs");
include!("types/rte_dev_init_t.rs");
include!("types/rte_dev_uninit_t.rs");
include!("types/rte_eal_alarm_callback.rs");
include!("types/rte_fbk_hash_fn.rs");
include!("types/rte_hash_cmp_eq_t.rs");
include!("types/rte_hash_function.rs");
include!("types/rte_intr_callback_fn.rs");
include!("types/rte_intr_event_cb_t.rs");
include!("types/rte_job_update_period_cb_t.rs");
include!("types/rte_keepalive_failure_callback_t.rs");
include!("types/rte_keepalive_relay_callback_t.rs");
include!("types/rte_mempool_alloc_t.rs");
include!("types/rte_mempool_ctor_t.rs");
include!("types/rte_mempool_dequeue_t.rs");
include!("types/rte_mempool_enqueue_t.rs");
include!("types/rte_mempool_free_t.rs");
include!("types/rte_mempool_get_count.rs");
include!("types/rte_mempool_mem_cb_t.rs");
include!("types/rte_mempool_memchunk_free_cb_t.rs");
include!("types/rte_mempool_obj_cb_t.rs");
include!("types/rte_mempool_obj_ctor_t.rs");
include!("types/rte_pipeline_port_in_action_handler.rs");
include!("types/rte_pipeline_port_out_action_handler.rs");
include!("types/rte_pipeline_table_action_handler_hit.rs");
include!("types/rte_pipeline_table_action_handler_miss.rs");
include!("types/rte_port_in_op_create.rs");
include!("types/rte_port_in_op_free.rs");
include!("types/rte_port_in_op_rx.rs");
include!("types/rte_port_in_op_stats_read.rs");
include!("types/rte_port_out_op_create.rs");
include!("types/rte_port_out_op_flush.rs");
include!("types/rte_port_out_op_free.rs");
include!("types/rte_port_out_op_stats_read.rs");
include!("types/rte_port_out_op_tx.rs");
include!("types/rte_port_out_op_tx_bulk.rs");
include!("types/rte_power_freq_change_t.rs");
include!("types/rte_power_freqs_t.rs");
include!("types/rte_power_get_freq_t.rs");
include!("types/rte_power_set_freq_t.rs");
include!("types/rte_table_hash_op_hash.rs");
include!("types/rte_table_op_create.rs");
include!("types/rte_table_op_entry_add.rs");
include!("types/rte_table_op_entry_add_bulk.rs");
include!("types/rte_table_op_entry_delete.rs");
include!("types/rte_table_op_entry_delete_bulk.rs");
include!("types/rte_table_op_free.rs");
include!("types/rte_table_op_lookup.rs");
include!("types/rte_table_op_stats_read.rs");
include!("types/rte_timer_cb_t.rs");
include!("types/rte_usage_hook_t.rs");
include!("types/rte_xmm_t.rs");
include!("types/unaligned_uint16_t.rs");
include!("types/unaligned_uint32_t.rs");
include!("types/unaligned_uint64_t.rs");
include!("types/xmm_t.rs");


// Enums
include!("enums/AnonymousEnum20.rs");
include!("enums/AnonymousEnum21.rs");
include!("enums/AnonymousEnum23.rs");
include!("enums/AnonymousEnum24.rs");
include!("enums/AnonymousEnum26.rs");
include!("enums/AnonymousEnum27.rs");
include!("enums/AnonymousEnum28.rs");
include!("enums/cmdline_numtype.rs");
include!("enums/cmdline_vt100_parser_state.rs");
include!("enums/malloc_elem.rs");
include!("enums/pmd_type.rs");
include!("enums/power_management_env.rs");
include!("enums/rdline_status.rs");
include!("enums/rte_acl_classify_alg.rs");
include!("enums/rte_acl_ctx.rs");
include!("enums/rte_cfgfile.rs");
include!("enums/rte_cpu_flag_t.rs");
include!("enums/rte_crypto_auth_algorithm.rs");
include!("enums/rte_crypto_auth_operation.rs");
include!("enums/rte_crypto_cipher_algorithm.rs");
include!("enums/rte_crypto_cipher_operation.rs");
include!("enums/rte_crypto_op_status.rs");
include!("enums/rte_crypto_op_type.rs");
include!("enums/rte_crypto_sym_op_sess_type.rs");
include!("enums/rte_crypto_sym_xform_type.rs");
include!("enums/rte_cryptodev_sym_session.rs");
include!("enums/rte_distributor.rs");
include!("enums/rte_hash.rs");
include!("enums/rte_intr_handle_type.rs");
include!("enums/rte_intr_mode.rs");
include!("enums/rte_keepalive.rs");
include!("enums/rte_keepalive_state.rs");
include!("enums/rte_lcore_role_t.rs");
include!("enums/rte_lcore_state_t.rs");
include!("enums/rte_lpm6.rs");
include!("enums/rte_mempool_objtlr.rs");
include!("enums/rte_meter_color.rs");
include!("enums/rte_page_sizes.rs");
include!("enums/rte_pdump_socktype.rs");
include!("enums/rte_pipeline.rs");
include!("enums/rte_pipeline_action.rs");
include!("enums/rte_proc_type_t.rs");
include!("enums/rte_reorder_buffer.rs");
include!("enums/rte_ring_queue_behavior.rs");
include!("enums/rte_rmt_call_master_t.rs");
include!("enums/rte_sched_port.rs");
include!("enums/rte_timer_type.rs");
include!("enums/timer_source.rs");


// Structs
include!("structs/AnonymousStruct10.rs");
include!("structs/AnonymousStruct11.rs");
include!("structs/AnonymousStruct12.rs");
include!("structs/AnonymousStruct13.rs");
include!("structs/AnonymousStruct14.rs");
include!("structs/AnonymousStruct15.rs");
include!("structs/AnonymousStruct16.rs");
include!("structs/AnonymousStruct17.rs");
include!("structs/AnonymousStruct18.rs");
include!("structs/AnonymousStruct19.rs");
include!("structs/AnonymousStruct2.rs");
include!("structs/AnonymousStruct22.rs");
include!("structs/AnonymousStruct25.rs");
include!("structs/AnonymousStruct3.rs");
include!("structs/AnonymousStruct5.rs");
include!("structs/AnonymousStruct6.rs");
include!("structs/AnonymousStruct7.rs");
include!("structs/AnonymousStruct8.rs");
include!("structs/AnonymousStruct9.rs");
include!("structs/AnonymousUnion1.rs");
include!("structs/AnonymousUnion4.rs");
include!("structs/arp_hdr.rs");
include!("structs/arp_ipv4.rs");
include!("structs/cirbuf.rs");
include!("structs/cmdline.rs");
include!("structs/cmdline_inst.rs");
include!("structs/cmdline_ipaddr.rs");
include!("structs/cmdline_portlist.rs");
include!("structs/cmdline_token_etheraddr.rs");
include!("structs/cmdline_token_hdr.rs");
include!("structs/cmdline_token_ipaddr.rs");
include!("structs/cmdline_token_ipaddr_data.rs");
include!("structs/cmdline_token_num.rs");
include!("structs/cmdline_token_num_data.rs");
include!("structs/cmdline_token_ops.rs");
include!("structs/cmdline_token_portlist.rs");
include!("structs/cmdline_token_string.rs");
include!("structs/cmdline_token_string_data.rs");
include!("structs/cmdline_vt100.rs");
include!("structs/cons.rs");
include!("structs/ether_addr.rs");
include!("structs/ether_hdr.rs");
include!("structs/icmp_hdr.rs");
include!("structs/ip_frag.rs");
include!("structs/ip_frag_key.rs");
include!("structs/ip_frag_pkt.rs");
include!("structs/ip_frag_tbl_stat.rs");
include!("structs/ip_pkt_list.rs");
include!("structs/ipv4_hdr.rs");
include!("structs/ipv6_extension_fragment.rs");
include!("structs/ipv6_hdr.rs");
include!("structs/lcore_config.rs");
include!("structs/malloc_heap.rs");
include!("structs/prod.rs");
include!("structs/rdline.rs");
include!("structs/rte_acl_config.rs");
include!("structs/rte_acl_field.rs");
include!("structs/rte_acl_field_def.rs");
include!("structs/rte_acl_field_types.rs");
include!("structs/rte_acl_param.rs");
include!("structs/rte_acl_rule.rs");
include!("structs/rte_acl_rule_data.rs");
include!("structs/rte_atomic16_t.rs");
include!("structs/rte_atomic32_t.rs");
include!("structs/rte_atomic64_t.rs");
include!("structs/rte_cfgfile_entry.rs");
include!("structs/rte_config.rs");
include!("structs/rte_crypto_auth_xform.rs");
include!("structs/rte_crypto_cipher_xform.rs");
include!("structs/rte_crypto_op.rs");
include!("structs/rte_crypto_op_pool_private.rs");
include!("structs/rte_crypto_sym_op.rs");
include!("structs/rte_crypto_sym_xform.rs");
include!("structs/rte_dev_eeprom_info.rs");
include!("structs/rte_dev_reg_info.rs");
include!("structs/rte_driver.rs");
include!("structs/rte_driver_list.rs");
include!("structs/rte_epoll_data.rs");
include!("structs/rte_epoll_event.rs");
include!("structs/rte_eth_vhost_queue_event.rs");
include!("structs/rte_fbk_hash_entry.rs");
include!("structs/rte_fbk_hash_params.rs");
include!("structs/rte_fbk_hash_table.rs");
include!("structs/rte_hash_parameters.rs");
include!("structs/rte_intr_handle.rs");
include!("structs/rte_ip_frag_death_row.rs");
include!("structs/rte_ip_frag_tbl.rs");
include!("structs/rte_ipv4_tuple.rs");
include!("structs/rte_ipv6_tuple.rs");
include!("structs/rte_jobstats.rs");
include!("structs/rte_jobstats_context.rs");
include!("structs/rte_kvargs.rs");
include!("structs/rte_kvargs_pair.rs");
include!("structs/rte_logs.rs");
include!("structs/rte_lpm.rs");
include!("structs/rte_lpm6_config.rs");
include!("structs/rte_lpm_config.rs");
include!("structs/rte_lpm_rule.rs");
include!("structs/rte_lpm_rule_info.rs");
include!("structs/rte_lpm_rule_v20.rs");
include!("structs/rte_lpm_tbl_entry.rs");
include!("structs/rte_lpm_tbl_entry_v20.rs");
include!("structs/rte_lpm_v20.rs");
include!("structs/rte_malloc_socket_stats.rs");
include!("structs/rte_mbuf.rs");
include!("structs/rte_mem_config.rs");
include!("structs/rte_mempool.rs");
include!("structs/rte_mempool_cache.rs");
include!("structs/rte_mempool_memhdr.rs");
include!("structs/rte_mempool_memhdr_list.rs");
include!("structs/rte_mempool_objhdr.rs");
include!("structs/rte_mempool_objhdr_list.rs");
include!("structs/rte_mempool_objsz.rs");
include!("structs/rte_mempool_ops.rs");
include!("structs/rte_mempool_ops_table.rs");
include!("structs/rte_memseg.rs");
include!("structs/rte_memzone.rs");
include!("structs/rte_meter_srtcm.rs");
include!("structs/rte_meter_srtcm_params.rs");
include!("structs/rte_meter_trtcm.rs");
include!("structs/rte_meter_trtcm_params.rs");
include!("structs/rte_pipeline_params.rs");
include!("structs/rte_pipeline_port_in_params.rs");
include!("structs/rte_pipeline_port_in_stats.rs");
include!("structs/rte_pipeline_port_out_params.rs");
include!("structs/rte_pipeline_port_out_stats.rs");
include!("structs/rte_pipeline_table_entry.rs");
include!("structs/rte_pipeline_table_params.rs");
include!("structs/rte_pipeline_table_stats.rs");
include!("structs/rte_pktmbuf_pool_private.rs");
include!("structs/rte_port_ethdev_reader_params.rs");
include!("structs/rte_port_ethdev_writer_nodrop_params.rs");
include!("structs/rte_port_ethdev_writer_params.rs");
include!("structs/rte_port_in_ops.rs");
include!("structs/rte_port_in_stats.rs");
include!("structs/rte_port_out_ops.rs");
include!("structs/rte_port_out_stats.rs");
include!("structs/rte_port_ring_reader_frag_params.rs");
include!("structs/rte_port_ring_reader_params.rs");
include!("structs/rte_port_ring_writer_nodrop_params.rs");
include!("structs/rte_port_ring_writer_params.rs");
include!("structs/rte_port_ring_writer_ras_params.rs");
include!("structs/rte_port_sched_reader_params.rs");
include!("structs/rte_port_sched_writer_params.rs");
include!("structs/rte_port_sink_params.rs");
include!("structs/rte_port_source_params.rs");
include!("structs/rte_reciprocal.rs");
include!("structs/rte_red.rs");
include!("structs/rte_red_config.rs");
include!("structs/rte_red_params.rs");
include!("structs/rte_ring.rs");
include!("structs/rte_rwlock_t.rs");
include!("structs/rte_sched_pipe_params.rs");
include!("structs/rte_sched_port_params.rs");
include!("structs/rte_sched_queue_stats.rs");
include!("structs/rte_sched_subport_params.rs");
include!("structs/rte_sched_subport_stats.rs");
include!("structs/rte_spinlock_recursive_t.rs");
include!("structs/rte_spinlock_t.rs");
include!("structs/rte_table_acl_params.rs");
include!("structs/rte_table_acl_rule_add_params.rs");
include!("structs/rte_table_acl_rule_delete_params.rs");
include!("structs/rte_table_array_key.rs");
include!("structs/rte_table_array_params.rs");
include!("structs/rte_table_hash_ext_params.rs");
include!("structs/rte_table_hash_key16_ext_params.rs");
include!("structs/rte_table_hash_key16_lru_params.rs");
include!("structs/rte_table_hash_key32_ext_params.rs");
include!("structs/rte_table_hash_key32_lru_params.rs");
include!("structs/rte_table_hash_key8_ext_params.rs");
include!("structs/rte_table_hash_key8_lru_params.rs");
include!("structs/rte_table_hash_lru_params.rs");
include!("structs/rte_table_lpm_ipv6_key.rs");
include!("structs/rte_table_lpm_ipv6_params.rs");
include!("structs/rte_table_lpm_key.rs");
include!("structs/rte_table_lpm_params.rs");
include!("structs/rte_table_ops.rs");
include!("structs/rte_table_stats.rs");
include!("structs/rte_tailq_elem.rs");
include!("structs/rte_tailq_entry.rs");
include!("structs/rte_tailq_entry_head.rs");
include!("structs/rte_tailq_head.rs");
include!("structs/rte_thash_tuple.rs");
include!("structs/rte_timecounter.rs");
include!("structs/rte_timer.rs");
include!("structs/rte_timer_status.rs");
include!("structs/rte_xmm.rs");
include!("structs/sctp_hdr.rs");
include!("structs/tcp_hdr.rs");
include!("structs/udp_hdr.rs");
include!("structs/virtio_net_device_ops.rs");
include!("structs/vlan_hdr.rs");
include!("structs/vxlan_hdr.rs");
