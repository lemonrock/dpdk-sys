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

#[link(name = "
rte_pmd_null")]
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

pub const CMDLINE_KEY_UP_ARR: c_int = 0;
pub const CMDLINE_KEY_DOWN_ARR: c_int = 1;
pub const CMDLINE_KEY_RIGHT_ARR: c_int = 2;
pub const CMDLINE_KEY_LEFT_ARR: c_int = 3;
pub const CMDLINE_KEY_BKSPACE: c_int = 4;
pub const CMDLINE_KEY_RETURN: c_int = 5;
pub const CMDLINE_KEY_CTRL_A: c_int = 6;
pub const CMDLINE_KEY_CTRL_E: c_int = 7;
pub const CMDLINE_KEY_CTRL_K: c_int = 8;
pub const CMDLINE_KEY_CTRL_Y: c_int = 9;
pub const CMDLINE_KEY_CTRL_C: c_int = 10;
pub const CMDLINE_KEY_CTRL_F: c_int = 11;
pub const CMDLINE_KEY_CTRL_B: c_int = 12;
pub const CMDLINE_KEY_SUPPR: c_int = 13;
pub const CMDLINE_KEY_TAB: c_int = 14;
pub const CMDLINE_KEY_CTRL_D: c_int = 15;
pub const CMDLINE_KEY_CTRL_L: c_int = 16;
pub const CMDLINE_KEY_RETURN2: c_int = 17;
pub const CMDLINE_KEY_META_BKSPACE: c_int = 18;
pub const CMDLINE_KEY_WLEFT: c_int = 19;
pub const CMDLINE_KEY_WRIGHT: c_int = 20;
pub const CMDLINE_KEY_HELP: c_int = 21;
pub const CMDLINE_KEY_CTRL_W: c_int = 22;
pub const CMDLINE_KEY_CTRL_P: c_int = 23;
pub const CMDLINE_KEY_CTRL_N: c_int = 24;
pub const CMDLINE_KEY_META_D: c_int = 25;
pub const CMDLINE_VT100_BUF_SIZE: c_int = 8;
pub const RDLINE_BUF_SIZE: c_int = 512;
pub const RDLINE_PROMPT_SIZE: c_int = 32;
pub const RDLINE_VT100_BUF_SIZE: c_int = 8;
pub const RDLINE_HISTORY_MAX_LINE: c_int = 64;
pub const RDLINE_RES_SUCCESS: c_int = 0;
pub const RDLINE_RES_VALIDATED: c_int = 1;
pub const RDLINE_RES_COMPLETE: c_int = 2;
pub const RDLINE_RES_NOT_RUNNING: c_int = -1;
pub const RDLINE_RES_EOF: c_int = -2;
pub const RDLINE_RES_EXITED: c_int = -3;
pub const CMDLINE_PARSE_SUCCESS: c_int = 0;
pub const CMDLINE_PARSE_AMBIGUOUS: c_int = -1;
pub const CMDLINE_PARSE_NOMATCH: c_int = -2;
pub const CMDLINE_PARSE_BAD_ARGS: c_int = -3;
pub const CMDLINE_PARSE_COMPLETE_FINISHED: c_int = 0;
pub const CMDLINE_PARSE_COMPLETE_AGAIN: c_int = 1;
pub const CMDLINE_PARSE_COMPLETED_BUFFER: c_int = 2;
pub const CMDLINE_PARSE_RESULT_BUFSIZE: c_int = 8192;
pub const CMDLINE_IPADDR_V4: c_int = 1;
pub const CMDLINE_IPADDR_V6: c_int = 2;
pub const CMDLINE_IPADDR_NETWORK: c_int = 4;
pub const PORTLIST_TOKEN_SIZE: c_int = 128;
pub const PORTLIST_MAX_TOKENS: c_int = 32;
pub const STR_TOKEN_SIZE: c_int = 128;
pub const STR_MULTI_TOKEN_SIZE: c_int = 4096;
pub const RTE_NEXT_ABI: c_int = 1;
pub const RTE_CACHE_LINE_SIZE: c_int = 64;
pub const RTE_LIBRTE_EAL: c_int = 1;
pub const RTE_MAX_LCORE: c_int = 128;
pub const RTE_MAX_NUMA_NODES: c_int = 8;
pub const RTE_MAX_MEMSEG: c_int = 256;
pub const RTE_MAX_MEMZONE: c_int = 2560;
pub const RTE_MAX_TAILQ: c_int = 32;
pub const RTE_LOG_HISTORY: c_int = 256;
pub const RTE_EAL_VFIO: c_int = 1;
pub const RTE_LIBRTE_EAL_VMWARE_TSC_MAP_SUPPORT: c_int = 1;
pub const RTE_LIBRTE_KVARGS: c_int = 1;
pub const RTE_LIBRTE_ETHER: c_int = 1;
pub const RTE_MAX_ETHPORTS: c_int = 32;
pub const RTE_MAX_QUEUES_PER_PORT: c_int = 1024;
pub const RTE_ETHDEV_QUEUE_STAT_CNTRS: c_int = 16;
pub const RTE_ETHDEV_RXTX_CALLBACKS: c_int = 1;
pub const RTE_LIBRTE_ENA_PMD: c_int = 1;
pub const RTE_LIBRTE_EM_PMD: c_int = 1;
pub const RTE_LIBRTE_IGB_PMD: c_int = 1;
pub const RTE_LIBRTE_IXGBE_PMD: c_int = 1;
pub const RTE_IXGBE_INC_VECTOR: c_int = 1;
pub const RTE_IXGBE_RX_OLFLAGS_ENABLE: c_int = 1;
pub const RTE_LIBRTE_I40E_PMD: c_int = 1;
pub const RTE_LIBRTE_I40E_RX_ALLOW_BULK_ALLOC: c_int = 1;
pub const RTE_LIBRTE_I40E_INC_VECTOR: c_int = 1;
pub const RTE_LIBRTE_I40E_RX_OLFLAGS_ENABLE: c_int = 1;
pub const RTE_LIBRTE_I40E_QUEUE_NUM_PER_PF: c_int = 64;
pub const RTE_LIBRTE_I40E_QUEUE_NUM_PER_VF: c_int = 4;
pub const RTE_LIBRTE_I40E_QUEUE_NUM_PER_VM: c_int = 4;
pub const RTE_LIBRTE_I40E_ITR_INTERVAL: c_int = -1;
pub const RTE_LIBRTE_FM10K_PMD: c_int = 1;
pub const RTE_LIBRTE_FM10K_RX_OLFLAGS_ENABLE: c_int = 1;
pub const RTE_LIBRTE_FM10K_INC_VECTOR: c_int = 1;
pub const RTE_LIBRTE_MLX4_SGE_WR_N: c_int = 4;
pub const RTE_LIBRTE_MLX4_MAX_INLINE: c_int = 0;
pub const RTE_LIBRTE_MLX4_TX_MP_CACHE: c_int = 8;
pub const RTE_LIBRTE_MLX4_SOFT_COUNTERS: c_int = 1;
pub const RTE_LIBRTE_MLX5_TX_MP_CACHE: c_int = 8;
pub const RTE_LIBRTE_CXGBE_PMD: c_int = 1;
pub const RTE_LIBRTE_ENIC_PMD: c_int = 1;
pub const RTE_LIBRTE_BNXT_PMD: c_int = 1;
pub const RTE_LIBRTE_PMD_SZEDATA2_AS: c_int = 0;
pub const RTE_LIBRTE_VIRTIO_PMD: c_int = 1;
pub const RTE_VIRTIO_USER: c_int = 1;
pub const RTE_LIBRTE_VMXNET3_PMD: c_int = 1;
pub const RTE_LIBRTE_PMD_RING: c_int = 1;
pub const RTE_PMD_RING_MAX_RX_RINGS: c_int = 16;
pub const RTE_PMD_RING_MAX_TX_RINGS: c_int = 16;
pub const RTE_LIBRTE_PMD_BOND: c_int = 1;
pub const RTE_LIBRTE_PMD_AF_PACKET: c_int = 1;
pub const RTE_LIBRTE_PMD_NULL: c_int = 1;
pub const RTE_PMD_PACKET_PREFETCH: c_int = 1;
pub const RTE_LIBRTE_CRYPTODEV: c_int = 1;
pub const RTE_CRYPTO_MAX_DEVS: c_int = 64;
pub const RTE_CRYPTODEV_NAME_LEN: c_int = 64;
pub const RTE_QAT_PMD_MAX_NB_SESSIONS: c_int = 2048;
pub const RTE_LIBRTE_PMD_NULL_CRYPTO: c_int = 1;
pub const RTE_LIBRTE_RING: c_int = 1;
pub const RTE_RING_PAUSE_REP_COUNT: c_int = 0;
pub const RTE_LIBRTE_MEMPOOL: c_int = 1;
pub const RTE_MEMPOOL_CACHE_MAX_SIZE: c_int = 512;
pub const RTE_LIBRTE_MBUF: c_int = 1;
pub const RTE_MBUF_REFCNT_ATOMIC: c_int = 1;
pub const RTE_PKTMBUF_HEADROOM: c_int = 128;
pub const RTE_LIBRTE_TIMER: c_int = 1;
pub const RTE_LIBRTE_CFGFILE: c_int = 1;
pub const RTE_LIBRTE_CMDLINE: c_int = 1;
pub const RTE_LIBRTE_HASH: c_int = 1;
pub const RTE_LIBRTE_JOBSTATS: c_int = 1;
pub const RTE_LIBRTE_LPM: c_int = 1;
pub const RTE_LIBRTE_ACL: c_int = 1;
pub const RTE_LIBRTE_POWER: c_int = 1;
pub const RTE_MAX_LCORE_FREQS: c_int = 64;
pub const RTE_LIBRTE_NET: c_int = 1;
pub const RTE_LIBRTE_IP_FRAG: c_int = 1;
pub const RTE_LIBRTE_IP_FRAG_MAX_FRAG: c_int = 4;
pub const RTE_LIBRTE_METER: c_int = 1;
pub const RTE_LIBRTE_SCHED: c_int = 1;
pub const RTE_SCHED_PORT_N_GRINDERS: c_int = 8;
pub const RTE_LIBRTE_DISTRIBUTOR: c_int = 1;
pub const RTE_LIBRTE_REORDER: c_int = 1;
pub const RTE_LIBRTE_PORT: c_int = 1;
pub const RTE_LIBRTE_TABLE: c_int = 1;
pub const RTE_LIBRTE_PIPELINE: c_int = 1;
pub const RTE_LIBRTE_KNI: c_int = 1;
pub const RTE_KNI_PREEMPT_DEFAULT: c_int = 1;
pub const RTE_KNI_VHOST_MAX_CACHE_SIZE: c_int = 1024;
pub const RTE_LIBRTE_PDUMP: c_int = 1;
pub const RTE_LIBRTE_VHOST: c_int = 1;
pub const RTE_LIBRTE_VHOST_USER: c_int = 1;
pub const RTE_LIBRTE_PMD_VHOST: c_int = 1;
pub const RTE_APP_TEST: c_int = 1;
pub const RTE_TEST_PMD: c_int = 1;
pub const RTE_EXEC_ENV_LINUXAPP: c_int = 1;
pub const RTE_ARCH_X86_64: c_int = 1;
pub const RTE_ARCH_X86: c_int = 1;
pub const RTE_ARCH_64: c_int = 1;
pub const RTE_TOOLCHAIN_GCC: c_int = 1;
pub const RTE_MAGIC: c_int = 19820526;
pub const RTE_MAX_THREAD_NAME_LEN: c_int = 16;
pub const _RTE_RTM_H_: c_int = 1;
pub const RTE_XBEGIN_STARTED: c_int = -1;
pub const RTE_XABORT_EXPLICIT: c_int = 1;
pub const RTE_XABORT_RETRY: c_int = 2;
pub const RTE_XABORT_CONFLICT: c_int = 4;
pub const RTE_XABORT_CAPACITY: c_int = 8;
pub const RTE_XABORT_DEBUG: c_int = 16;
pub const RTE_XABORT_NESTED: c_int = 32;
pub const RTE_RTM_MAX_RETRIES: c_int = 10;
pub const RTE_XABORT_LOCK_BUSY: c_int = 255;
pub const RTE_LOGTYPE_EAL: c_int = 1;
pub const RTE_LOGTYPE_MALLOC: c_int = 2;
pub const RTE_LOGTYPE_RING: c_int = 4;
pub const RTE_LOGTYPE_MEMPOOL: c_int = 8;
pub const RTE_LOGTYPE_TIMER: c_int = 16;
pub const RTE_LOGTYPE_PMD: c_int = 32;
pub const RTE_LOGTYPE_HASH: c_int = 64;
pub const RTE_LOGTYPE_LPM: c_int = 128;
pub const RTE_LOGTYPE_KNI: c_int = 256;
pub const RTE_LOGTYPE_ACL: c_int = 512;
pub const RTE_LOGTYPE_POWER: c_int = 1024;
pub const RTE_LOGTYPE_METER: c_int = 2048;
pub const RTE_LOGTYPE_SCHED: c_int = 4096;
pub const RTE_LOGTYPE_PORT: c_int = 8192;
pub const RTE_LOGTYPE_TABLE: c_int = 16384;
pub const RTE_LOGTYPE_PIPELINE: c_int = 32768;
pub const RTE_LOGTYPE_MBUF: c_int = 65536;
pub const RTE_LOGTYPE_CRYPTODEV: c_int = 131072;
pub const RTE_LOGTYPE_USER1: c_int = 16777216;
pub const RTE_LOGTYPE_USER2: c_int = 33554432;
pub const RTE_LOGTYPE_USER3: c_int = 67108864;
pub const RTE_LOGTYPE_USER4: c_int = 134217728;
pub const RTE_LOGTYPE_USER5: c_int = 268435456;
pub const RTE_LOGTYPE_USER6: c_int = 536870912;
pub const RTE_LOGTYPE_USER7: c_int = 1073741824;
pub const RTE_LOGTYPE_USER8: i64 = 2147483648;
pub const RTE_LOG_EMERG: c_int = 1;
pub const RTE_LOG_ALERT: c_int = 2;
pub const RTE_LOG_CRIT: c_int = 3;
pub const RTE_LOG_ERR: c_int = 4;
pub const RTE_LOG_WARNING: c_int = 5;
pub const RTE_LOG_NOTICE: c_int = 6;
pub const RTE_LOG_INFO: c_int = 7;
pub const RTE_LOG_DEBUG: c_int = 8;
pub const SOCKET_ID_ANY: c_int = -1;
pub const RTE_CACHE_LINE_MASK: c_int = 63;
pub const RTE_CACHE_LINE_SIZE_LOG2: c_int = 6;
pub const RTE_CACHE_LINE_MIN_SIZE: c_int = 64;
pub const RTE_MEMZONE_2MB: c_int = 1;
pub const RTE_MEMZONE_1GB: c_int = 2;
pub const RTE_MEMZONE_16MB: c_int = 256;
pub const RTE_MEMZONE_16GB: c_int = 512;
pub const RTE_MEMZONE_256KB: c_int = 65536;
pub const RTE_MEMZONE_256MB: c_int = 131072;
pub const RTE_MEMZONE_512MB: c_int = 262144;
pub const RTE_MEMZONE_4GB: c_int = 524288;
pub const RTE_MEMZONE_SIZE_HINT_ONLY: c_int = 4;
pub const RTE_MEMZONE_NAMESIZE: c_int = 32;
pub const RING_F_SP_ENQ: c_int = 1;
pub const RING_F_SC_DEQ: c_int = 2;
pub const RTE_RING_QUOT_EXCEED: i64 = 2147483648;
pub const RTE_MEMPOOL_HEADER_COOKIE1: c_longlong = -4982197544707871147;
pub const RTE_MEMPOOL_HEADER_COOKIE2: c_longlong = -941548164385788331;
pub const RTE_MEMPOOL_TRAILER_COOKIE: c_longlong = -5921418378119291987;
pub const MEMPOOL_PG_NUM_DEFAULT: c_int = 1;
pub const RTE_MEMPOOL_ALIGN: c_int = 64;
pub const RTE_MEMPOOL_ALIGN_MASK: c_int = 63;
pub const MEMPOOL_F_NO_SPREAD: c_int = 1;
pub const MEMPOOL_F_NO_CACHE_ALIGN: c_int = 2;
pub const MEMPOOL_F_SP_PUT: c_int = 4;
pub const MEMPOOL_F_SC_GET: c_int = 8;
pub const MEMPOOL_F_POOL_CREATED: c_int = 16;
pub const MEMPOOL_F_NO_PHYS_CONTIG: c_int = 32;
pub const RTE_MEMPOOL_OPS_NAMESIZE: c_int = 32;
pub const RTE_MEMPOOL_MAX_OPS_IDX: c_int = 16;
pub const PKT_RX_VLAN_PKT: c_int = 1;
pub const PKT_RX_RSS_HASH: c_int = 2;
pub const PKT_RX_FDIR: c_int = 4;
pub const PKT_RX_L4_CKSUM_BAD: c_int = 8;
pub const PKT_RX_IP_CKSUM_BAD: c_int = 16;
pub const PKT_RX_EIP_CKSUM_BAD: c_int = 32;
pub const PKT_RX_VLAN_STRIPPED: c_int = 64;
pub const PKT_RX_IEEE1588_PTP: c_int = 512;
pub const PKT_RX_IEEE1588_TMST: c_int = 1024;
pub const PKT_RX_FDIR_ID: c_int = 8192;
pub const PKT_RX_FDIR_FLX: c_int = 16384;
pub const PKT_RX_QINQ_STRIPPED: c_int = 32768;
pub const PKT_RX_QINQ_PKT: c_int = 32768;
pub const PKT_TX_QINQ_PKT: c_longlong = 562949953421312;
pub const PKT_TX_TCP_SEG: c_longlong = 1125899906842624;
pub const PKT_TX_IEEE1588_TMST: c_longlong = 2251799813685248;
pub const PKT_TX_L4_NO_CKSUM: c_int = 0;
pub const PKT_TX_TCP_CKSUM: c_longlong = 4503599627370496;
pub const PKT_TX_SCTP_CKSUM: c_longlong = 9007199254740992;
pub const PKT_TX_UDP_CKSUM: c_longlong = 13510798882111488;
pub const PKT_TX_L4_MASK: c_longlong = 13510798882111488;
pub const PKT_TX_IP_CKSUM: c_longlong = 18014398509481984;
pub const PKT_TX_IPV4: c_longlong = 36028797018963968;
pub const PKT_TX_IPV6: c_longlong = 72057594037927936;
pub const PKT_TX_VLAN_PKT: c_longlong = 144115188075855872;
pub const PKT_TX_OUTER_IP_CKSUM: c_longlong = 288230376151711744;
pub const PKT_TX_OUTER_IPV4: c_longlong = 576460752303423488;
pub const PKT_TX_OUTER_IPV6: c_longlong = 1152921504606846976;
pub const __RESERVED: c_longlong = 2305843009213693952;
pub const IND_ATTACHED_MBUF: c_longlong = 4611686018427387904;
pub const CTRL_MBUF_FLAG: c_longlong = -9223372036854775808;
pub const RTE_PTYPE_UNKNOWN: c_int = 0;
pub const RTE_PTYPE_L2_ETHER: c_int = 1;
pub const RTE_PTYPE_L2_ETHER_TIMESYNC: c_int = 2;
pub const RTE_PTYPE_L2_ETHER_ARP: c_int = 3;
pub const RTE_PTYPE_L2_ETHER_LLDP: c_int = 4;
pub const RTE_PTYPE_L2_ETHER_NSH: c_int = 5;
pub const RTE_PTYPE_L2_MASK: c_int = 15;
pub const RTE_PTYPE_L3_IPV4: c_int = 16;
pub const RTE_PTYPE_L3_IPV4_EXT: c_int = 48;
pub const RTE_PTYPE_L3_IPV6: c_int = 64;
pub const RTE_PTYPE_L3_IPV4_EXT_UNKNOWN: c_int = 144;
pub const RTE_PTYPE_L3_IPV6_EXT: c_int = 192;
pub const RTE_PTYPE_L3_IPV6_EXT_UNKNOWN: c_int = 224;
pub const RTE_PTYPE_L3_MASK: c_int = 240;
pub const RTE_PTYPE_L4_TCP: c_int = 256;
pub const RTE_PTYPE_L4_UDP: c_int = 512;
pub const RTE_PTYPE_L4_FRAG: c_int = 768;
pub const RTE_PTYPE_L4_SCTP: c_int = 1024;
pub const RTE_PTYPE_L4_ICMP: c_int = 1280;
pub const RTE_PTYPE_L4_NONFRAG: c_int = 1536;
pub const RTE_PTYPE_L4_MASK: c_int = 3840;
pub const RTE_PTYPE_TUNNEL_IP: c_int = 4096;
pub const RTE_PTYPE_TUNNEL_GRE: c_int = 8192;
pub const RTE_PTYPE_TUNNEL_VXLAN: c_int = 12288;
pub const RTE_PTYPE_TUNNEL_NVGRE: c_int = 16384;
pub const RTE_PTYPE_TUNNEL_GENEVE: c_int = 20480;
pub const RTE_PTYPE_TUNNEL_GRENAT: c_int = 24576;
pub const RTE_PTYPE_TUNNEL_MASK: c_int = 61440;
pub const RTE_PTYPE_INNER_L2_ETHER: c_int = 65536;
pub const RTE_PTYPE_INNER_L2_ETHER_VLAN: c_int = 131072;
pub const RTE_PTYPE_INNER_L2_MASK: c_int = 983040;
pub const RTE_PTYPE_INNER_L3_IPV4: c_int = 1048576;
pub const RTE_PTYPE_INNER_L3_IPV4_EXT: c_int = 2097152;
pub const RTE_PTYPE_INNER_L3_IPV6: c_int = 3145728;
pub const RTE_PTYPE_INNER_L3_IPV4_EXT_UNKNOWN: c_int = 4194304;
pub const RTE_PTYPE_INNER_L3_IPV6_EXT: c_int = 5242880;
pub const RTE_PTYPE_INNER_L3_IPV6_EXT_UNKNOWN: c_int = 6291456;
pub const RTE_PTYPE_INNER_L3_MASK: c_int = 15728640;
pub const RTE_PTYPE_INNER_L4_TCP: c_int = 16777216;
pub const RTE_PTYPE_INNER_L4_UDP: c_int = 33554432;
pub const RTE_PTYPE_INNER_L4_FRAG: c_int = 50331648;
pub const RTE_PTYPE_INNER_L4_SCTP: c_int = 67108864;
pub const RTE_PTYPE_INNER_L4_ICMP: c_int = 83886080;
pub const RTE_PTYPE_INNER_L4_NONFRAG: c_int = 100663296;
pub const RTE_PTYPE_INNER_L4_MASK: c_int = 251658240;
pub const RTE_MBUF_PRIV_ALIGN: c_int = 8;
pub const RTE_MBUF_DEFAULT_DATAROOM: c_int = 2048;
pub const RTE_MBUF_DEFAULT_BUF_SIZE: c_int = 2176;
pub const RTE_BIG_ENDIAN: c_int = 1;
pub const RTE_LITTLE_ENDIAN: c_int = 2;
pub const RTE_BYTE_ORDER: c_int = 2;
pub const ETHER_ADDR_LEN: c_int = 6;
pub const ETHER_TYPE_LEN: c_int = 2;
pub const ETHER_CRC_LEN: c_int = 4;
pub const ETHER_HDR_LEN: c_int = 14;
pub const ETHER_MIN_LEN: c_int = 64;
pub const ETHER_MAX_LEN: c_int = 1518;
pub const ETHER_MTU: c_int = 1500;
pub const ETHER_MAX_VLAN_FRAME_LEN: c_int = 1522;
pub const ETHER_MAX_JUMBO_FRAME_LEN: c_int = 16128;
pub const ETHER_MAX_VLAN_ID: c_int = 4095;
pub const ETHER_MIN_MTU: c_int = 68;
pub const ETHER_LOCAL_ADMIN_ADDR: c_int = 2;
pub const ETHER_GROUP_ADDR: c_int = 1;
pub const ETHER_ADDR_FMT_SIZE: c_int = 18;
pub const ETHER_TYPE_IPv4: c_int = 2048;
pub const ETHER_TYPE_IPv6: c_int = 34525;
pub const ETHER_TYPE_ARP: c_int = 2054;
pub const ETHER_TYPE_RARP: c_int = 32821;
pub const ETHER_TYPE_VLAN: c_int = 33024;
pub const ETHER_TYPE_1588: c_int = 35063;
pub const ETHER_TYPE_SLOW: c_int = 34825;
pub const ETHER_TYPE_TEB: c_int = 25944;
pub const ARP_HRD_ETHER: c_int = 1;
pub const ARP_OP_REQUEST: c_int = 1;
pub const ARP_OP_REPLY: c_int = 2;
pub const ARP_OP_REVREQUEST: c_int = 3;
pub const ARP_OP_REVREPLY: c_int = 4;
pub const ARP_OP_INVREQUEST: c_int = 8;
pub const ARP_OP_INVREPLY: c_int = 9;
pub const CFG_NAME_LEN: c_int = 64;
pub const CFG_VALUE_LEN: c_int = 256;
pub const RTE_DISTRIBUTOR_NAMESIZE: c_int = 32;
pub const RTE_TAILQ_NAMESIZE: c_int = 32;
pub const RTE_HEAP_NUM_FREELISTS: c_int = 13;
pub const __ELASTERROR: c_int = 1000;
pub const BONDING_MODE_ROUND_ROBIN: c_int = 0;
pub const BONDING_MODE_ACTIVE_BACKUP: c_int = 1;
pub const BONDING_MODE_BALANCE: c_int = 2;
pub const BONDING_MODE_BROADCAST: c_int = 3;
pub const BONDING_MODE_8023AD: c_int = 4;
pub const BONDING_MODE_TLB: c_int = 5;
pub const BONDING_MODE_ALB: c_int = 6;
pub const BALANCE_XMIT_POLICY_LAYER2: c_int = 0;
pub const BALANCE_XMIT_POLICY_LAYER23: c_int = 1;
pub const BALANCE_XMIT_POLICY_LAYER34: c_int = 2;
pub const RTE_VHOST_USER_CLIENT: c_int = 1;
pub const RTE_VHOST_USER_NO_RECONNECT: c_int = 2;
pub const RTE_JHASH_GOLDEN_RATIO: i64 = 3735928559;
pub const RTE_FBK_HASH_INIT_VAL_DEFAULT: i64 = 4294967295;
pub const RTE_FBK_HASH_ENTRIES_MAX: c_int = 1048576;
pub const RTE_FBK_HASH_ENTRIES_PER_BUCKET_MAX: c_int = 256;
pub const RTE_FBK_HASH_NAMESIZE: c_int = 32;
pub const RTE_HASH_ENTRIES_MAX: c_int = 1073741824;
pub const RTE_HASH_NAMESIZE: c_int = 32;
pub const RTE_HASH_LOOKUP_BULK_MAX: c_int = 64;
pub const RTE_HASH_LOOKUP_MULTI_MAX: c_int = 64;
pub const RTE_HASH_EXTRA_FLAGS_TRANS_MEM_SUPPORT: c_int = 1;
pub const RTE_HASH_EXTRA_FLAGS_MULTI_WRITER_ADD: c_int = 2;
pub const CRC32_SW: c_int = 1;
pub const CRC32_SSE42: c_int = 2;
pub const CRC32_x64: c_int = 4;
pub const CRC32_SSE42_x64: c_int = 6;
pub const CRC32_ARM64: c_int = 8;
pub const IP_ICMP_ECHO_REPLY: c_int = 0;
pub const IP_ICMP_ECHO_REQUEST: c_int = 8;
pub const RTE_MAX_RXTX_INTR_VEC_ID: c_int = 32;
pub const RTE_INTR_VEC_ZERO_OFFSET: c_int = 0;
pub const RTE_INTR_VEC_RXTX_OFFSET: c_int = 1;
pub const RTE_INTR_EVENT_ADD: c_int = 1;
pub const RTE_INTR_EVENT_DEL: c_int = 2;
pub const RTE_EPOLL_PER_THREAD: c_int = -1;
pub const IPV4_MAX_PKT_LEN: c_int = 65535;
pub const IPV4_HDR_IHL_MASK: c_int = 15;
pub const IPV4_IHL_MULTIPLIER: c_int = 4;
pub const IPV4_HDR_DF_SHIFT: c_int = 14;
pub const IPV4_HDR_MF_SHIFT: c_int = 13;
pub const IPV4_HDR_FO_SHIFT: c_int = 3;
pub const IPV4_HDR_DF_FLAG: c_int = 16384;
pub const IPV4_HDR_MF_FLAG: c_int = 8192;
pub const IPV4_HDR_OFFSET_MASK: c_int = 8191;
pub const IPV4_HDR_OFFSET_UNITS: c_int = 8;
pub const IP_FRAG_DEATH_ROW_LEN: c_int = 32;
pub const RTE_IPV6_EHDR_MF_SHIFT: c_int = 0;
pub const RTE_IPV6_EHDR_MF_MASK: c_int = 1;
pub const RTE_IPV6_EHDR_FO_SHIFT: c_int = 3;
pub const RTE_IPV6_EHDR_FO_MASK: c_int = -8;
pub const RTE_IPV6_FRAG_USED_MASK: c_int = -7;
pub const RTE_JOBSTATS_NAMESIZE: c_int = 32;
#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct cirbuf
{
	pub maxlen: c_uint,
	pub start: c_uint,
	pub end: c_uint,
	pub len: c_uint,
	pub buf: *mut c_char,
}

impl Default for cirbuf
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum cmdline_vt100_parser_state
{
	CMDLINE_VT100_INIT = 0,
	CMDLINE_VT100_ESCAPE = 1,
	CMDLINE_VT100_ESCAPE_CSI = 2,
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct cmdline_vt100
{
	pub bufpos: uint8_t,
	pub buf: [c_char; 8usize],
	pub state: cmdline_vt100_parser_state,
}

impl Default for cmdline_vt100
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum rdline_status
{
	RDLINE_INIT = 0,
	RDLINE_RUNNING = 1,
	RDLINE_EXITED = 2,
}

pub type rdline_write_char_t = Option<unsafe extern "C" fn(rdl: *mut rdline, arg1: c_char) -> c_int>;

pub type rdline_validate_t = Option<unsafe extern "C" fn(rdl: *mut rdline, buf: *const c_char, size: c_uint)>;

pub type rdline_complete_t = Option<unsafe extern "C" fn(rdl: *mut rdline, buf: *const c_char, dstbuf: *mut c_char, dstsize: c_uint, state: *mut c_int) -> c_int>;

#[repr(C)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct rdline
{
	pub status: rdline_status,
	pub left: cirbuf,
	pub right: cirbuf,
	pub left_buf: [c_char; 514usize],
	pub right_buf: [c_char; 512usize],
	pub prompt: [c_char; 32usize],
	pub prompt_size: c_uint,
	pub kill_buf: [c_char; 512usize],
	pub kill_size: c_uint,
	pub history: cirbuf,
	pub history_buf: [c_char; 1024usize],
	pub history_cur_line: c_int,
	pub write_char: rdline_write_char_t,
	pub validate: rdline_validate_t,
	pub complete: rdline_complete_t,
	pub vt100: cmdline_vt100,
	pub opaque: *mut c_void,
}

impl Clone for rdline
{
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for rdline
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct cmdline_token_hdr
{
	pub ops: *mut cmdline_token_ops,
	pub offset: c_uint,
	_bindgen_padding_0_: [u8; 4usize],
}

impl Default for cmdline_token_hdr
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

pub type cmdline_parse_token_hdr_t = cmdline_token_hdr;

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct cmdline_token_ops
{
	pub parse: Option<unsafe extern "C" fn(arg1: *mut cmdline_parse_token_hdr_t, arg2: *const c_char, arg3: *mut c_void, arg4: c_uint) -> c_int>,
	pub complete_get_nb: Option<unsafe extern "C" fn(arg1: *mut cmdline_parse_token_hdr_t) -> c_int>,
	pub complete_get_elt: Option<unsafe extern "C" fn(arg1: *mut cmdline_parse_token_hdr_t, arg2: c_int, arg3: *mut c_char, arg4: c_uint) -> c_int>,
	pub get_help: Option<unsafe extern "C" fn(arg1: *mut cmdline_parse_token_hdr_t, arg2: *mut c_char, arg3: c_uint) -> c_int>,
}

impl Default for cmdline_token_ops
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct cmdline_inst
{
	pub f: Option<unsafe extern "C" fn(arg1: *mut c_void, arg2: *mut cmdline, arg3: *mut c_void)>,
	pub data: *mut c_void,
	pub help_str: *const c_char,
	pub tokens: [*mut cmdline_parse_token_hdr_t; 0usize],
}

impl Default for cmdline_inst
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

pub type cmdline_parse_inst_t = cmdline_inst;

pub type cmdline_parse_ctx_t = *mut cmdline_parse_inst_t;

#[repr(C)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct cmdline
{
	pub s_in: c_int,
	pub s_out: c_int,
	pub ctx: *mut cmdline_parse_ctx_t,
	pub rdl: rdline,
	pub prompt: [c_char; 32usize],
	pub oldterm: termios,
}

impl Clone for cmdline
{
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for cmdline
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct cmdline_token_etheraddr
{
	pub hdr: cmdline_token_hdr,
}

impl Default for cmdline_token_etheraddr
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

pub type cmdline_parse_token_etheraddr_t = cmdline_token_etheraddr;

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct cmdline_ipaddr
{
	pub family: uint8_t,
	pub addr: Union_Unnamed1,
	pub prefixlen: c_uint,
}

impl Default for cmdline_ipaddr
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Union_Unnamed1
{
	pub _bindgen_data_: [u32; 4usize],
}

impl Union_Unnamed1
{
	pub unsafe fn ipv4(&mut self) -> *mut in_addr
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
	pub unsafe fn ipv6(&mut self) -> *mut in6_addr
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
}

impl Default for Union_Unnamed1
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

pub type cmdline_ipaddr_t = cmdline_ipaddr;

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct cmdline_token_ipaddr_data
{
	pub flags: uint8_t,
}

impl Default for cmdline_token_ipaddr_data
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct cmdline_token_ipaddr
{
	pub hdr: cmdline_token_hdr,
	pub ipaddr_data: cmdline_token_ipaddr_data,
	_bindgen_padding_0_: [u8; 7usize],
}

impl Default for cmdline_token_ipaddr
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

pub type cmdline_parse_token_ipaddr_t = cmdline_token_ipaddr;

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum cmdline_numtype
{
	UINT8 = 0,
	UINT16 = 1,
	UINT32 = 2,
	UINT64 = 3,
	INT8 = 4,
	INT16 = 5,
	INT32 = 6,
	INT64 = 7,
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct cmdline_token_num_data
{
	pub type_: cmdline_numtype,
}

impl Default for cmdline_token_num_data
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct cmdline_token_num
{
	pub hdr: cmdline_token_hdr,
	pub num_data: cmdline_token_num_data,
	_bindgen_padding_0_: [u8; 4usize],
}

impl Default for cmdline_token_num
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

pub type cmdline_parse_token_num_t = cmdline_token_num;

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct cmdline_portlist
{
	pub map: uint32_t,
}

impl Default for cmdline_portlist
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

pub type cmdline_portlist_t = cmdline_portlist;

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct cmdline_token_portlist
{
	pub hdr: cmdline_token_hdr,
}

impl Default for cmdline_token_portlist
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

pub type cmdline_parse_token_portlist_t = cmdline_token_portlist;

pub type cmdline_fixed_string_t = [c_char; 128usize];

pub type cmdline_multi_string_t = [c_char; 4096usize];

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct cmdline_token_string_data
{
	pub str: *const c_char,
}

impl Default for cmdline_token_string_data
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct cmdline_token_string
{
	pub hdr: cmdline_token_hdr,
	pub string_data: cmdline_token_string_data,
}

impl Default for cmdline_token_string
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

pub type cmdline_parse_token_string_t = cmdline_token_string;

pub type rte_eal_alarm_callback = Option<unsafe extern "C" fn(arg: *mut c_void)>;

pub type xmm_t = __m128i;

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_xmm
{
	pub _bindgen_data_: [u8; 16usize],
}

impl rte_xmm
{
	pub unsafe fn x(&mut self) -> *mut xmm_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
	pub unsafe fn u8_(&mut self) -> *mut [uint8_t; 16usize]
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
	pub unsafe fn u16_(&mut self) -> *mut [uint16_t; 8usize]
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
	pub unsafe fn u32_(&mut self) -> *mut [uint32_t; 4usize]
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
	pub unsafe fn u64_(&mut self) -> *mut [uint64_t; 2usize]
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
	pub unsafe fn pd(&mut self) -> *mut [f64; 2usize]
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
}

impl Default for rte_xmm
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

pub type rte_xmm_t = rte_xmm;

pub type unaligned_uint64_t = uint64_t;

pub type unaligned_uint32_t = uint32_t;

pub type unaligned_uint16_t = uint16_t;

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum rte_lcore_role_t
{
	ROLE_RTE = 0,
	ROLE_OFF = 1,
}

#[derive(Copy, Clone)]
#[repr(i32)]
#[derive(Debug)]
pub enum rte_proc_type_t
{
	RTE_PROC_AUTO = -1,
	RTE_PROC_PRIMARY = 0,
	RTE_PROC_SECONDARY = 1,
	RTE_PROC_INVALID = 2,
}

#[repr(C, packed)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct rte_config
{
	pub master_lcore: uint32_t,
	pub lcore_count: uint32_t,
	pub lcore_role: [rte_lcore_role_t; 128usize],
	pub process_type: rte_proc_type_t,
	pub mem_config: *mut rte_mem_config,
}

impl Clone for rte_config
{
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for rte_config
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

pub type rte_usage_hook_t = Option<unsafe extern "C" fn(prgname: *const c_char)>;

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum rte_lcore_state_t
{
	WAIT = 0,
	RUNNING = 1,
	FINISHED = 2,
}

pub type lcore_function_t = Option<unsafe extern "C" fn(arg1: *mut c_void) -> c_int>;

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum rte_rmt_call_master_t
{
	SKIP_MASTER = 0,
	CALL_MASTER = 1,
}

pub type rte_cpuset_t = cpu_set_t;

#[repr(C)]
#[derive(Copy, Clone)]
#[allow(missing_debug_implementations)]
pub struct lcore_config
{
	pub detected: c_uint,
	pub thread_id: pthread_t,
	pub pipe_master2slave: [c_int; 2usize],
	pub pipe_slave2master: [c_int; 2usize],
	pub f: lcore_function_t,
	pub arg: *mut c_void,
	pub ret: c_int,
	pub state: rte_lcore_state_t,
	pub socket_id: c_uint,
	pub core_id: c_uint,
	pub core_index: c_int,
	pub cpuset: rte_cpuset_t,
}

impl Default for lcore_config
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_spinlock_t
{
	pub locked: c_int,
}

impl Default for rte_spinlock_t
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_spinlock_recursive_t
{
	pub sl: rte_spinlock_t,
	pub user: c_int,
	pub count: c_int,
}

impl Default for rte_spinlock_recursive_t
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum rte_cpu_flag_t
{
	RTE_CPUFLAG_SSE3 = 0,
	RTE_CPUFLAG_PCLMULQDQ = 1,
	RTE_CPUFLAG_DTES64 = 2,
	RTE_CPUFLAG_MONITOR = 3,
	RTE_CPUFLAG_DS_CPL = 4,
	RTE_CPUFLAG_VMX = 5,
	RTE_CPUFLAG_SMX = 6,
	RTE_CPUFLAG_EIST = 7,
	RTE_CPUFLAG_TM2 = 8,
	RTE_CPUFLAG_SSSE3 = 9,
	RTE_CPUFLAG_CNXT_ID = 10,
	RTE_CPUFLAG_FMA = 11,
	RTE_CPUFLAG_CMPXCHG16B = 12,
	RTE_CPUFLAG_XTPR = 13,
	RTE_CPUFLAG_PDCM = 14,
	RTE_CPUFLAG_PCID = 15,
	RTE_CPUFLAG_DCA = 16,
	RTE_CPUFLAG_SSE4_1 = 17,
	RTE_CPUFLAG_SSE4_2 = 18,
	RTE_CPUFLAG_X2APIC = 19,
	RTE_CPUFLAG_MOVBE = 20,
	RTE_CPUFLAG_POPCNT = 21,
	RTE_CPUFLAG_TSC_DEADLINE = 22,
	RTE_CPUFLAG_AES = 23,
	RTE_CPUFLAG_XSAVE = 24,
	RTE_CPUFLAG_OSXSAVE = 25,
	RTE_CPUFLAG_AVX = 26,
	RTE_CPUFLAG_F16C = 27,
	RTE_CPUFLAG_RDRAND = 28,
	RTE_CPUFLAG_FPU = 29,
	RTE_CPUFLAG_VME = 30,
	RTE_CPUFLAG_DE = 31,
	RTE_CPUFLAG_PSE = 32,
	RTE_CPUFLAG_TSC = 33,
	RTE_CPUFLAG_MSR = 34,
	RTE_CPUFLAG_PAE = 35,
	RTE_CPUFLAG_MCE = 36,
	RTE_CPUFLAG_CX8 = 37,
	RTE_CPUFLAG_APIC = 38,
	RTE_CPUFLAG_SEP = 39,
	RTE_CPUFLAG_MTRR = 40,
	RTE_CPUFLAG_PGE = 41,
	RTE_CPUFLAG_MCA = 42,
	RTE_CPUFLAG_CMOV = 43,
	RTE_CPUFLAG_PAT = 44,
	RTE_CPUFLAG_PSE36 = 45,
	RTE_CPUFLAG_PSN = 46,
	RTE_CPUFLAG_CLFSH = 47,
	RTE_CPUFLAG_DS = 48,
	RTE_CPUFLAG_ACPI = 49,
	RTE_CPUFLAG_MMX = 50,
	RTE_CPUFLAG_FXSR = 51,
	RTE_CPUFLAG_SSE = 52,
	RTE_CPUFLAG_SSE2 = 53,
	RTE_CPUFLAG_SS = 54,
	RTE_CPUFLAG_HTT = 55,
	RTE_CPUFLAG_TM = 56,
	RTE_CPUFLAG_PBE = 57,
	RTE_CPUFLAG_DIGTEMP = 58,
	RTE_CPUFLAG_TRBOBST = 59,
	RTE_CPUFLAG_ARAT = 60,
	RTE_CPUFLAG_PLN = 61,
	RTE_CPUFLAG_ECMD = 62,
	RTE_CPUFLAG_PTM = 63,
	RTE_CPUFLAG_MPERF_APERF_MSR = 64,
	RTE_CPUFLAG_ACNT2 = 65,
	RTE_CPUFLAG_ENERGY_EFF = 66,
	RTE_CPUFLAG_FSGSBASE = 67,
	RTE_CPUFLAG_BMI1 = 68,
	RTE_CPUFLAG_HLE = 69,
	RTE_CPUFLAG_AVX2 = 70,
	RTE_CPUFLAG_SMEP = 71,
	RTE_CPUFLAG_BMI2 = 72,
	RTE_CPUFLAG_ERMS = 73,
	RTE_CPUFLAG_INVPCID = 74,
	RTE_CPUFLAG_RTM = 75,
	RTE_CPUFLAG_AVX512F = 76,
	RTE_CPUFLAG_LAHF_SAHF = 77,
	RTE_CPUFLAG_LZCNT = 78,
	RTE_CPUFLAG_SYSCALL = 79,
	RTE_CPUFLAG_XD = 80,
	RTE_CPUFLAG_1GB_PG = 81,
	RTE_CPUFLAG_RDTSCP = 82,
	RTE_CPUFLAG_EM64T = 83,
	RTE_CPUFLAG_INVTSC = 84,
	RTE_CPUFLAG_NUMFLAGS = 85,
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_logs
{
	pub type_: uint32_t,
	pub level: uint32_t,
	pub file: *mut FILE,
}

impl Default for rte_logs
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[derive(Copy, Clone)]
#[repr(u64)]
#[derive(Debug)]
pub enum rte_page_sizes
{
	RTE_PGSIZE_4K = 4096,
	RTE_PGSIZE_64K = 65536,
	RTE_PGSIZE_256K = 262144,
	RTE_PGSIZE_2M = 2097152,
	RTE_PGSIZE_16M = 16777216,
	RTE_PGSIZE_256M = 268435456,
	RTE_PGSIZE_512M = 536870912,
	RTE_PGSIZE_1G = 1073741824,
	RTE_PGSIZE_4G = 4294967296,
	RTE_PGSIZE_16G = 17179869184,
}

pub type phys_addr_t = uint64_t;

#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_memseg
{
	pub phys_addr: phys_addr_t,
	pub _bindgen_data_1_: [u64; 1usize],
	pub len: size_t,
	pub hugepage_sz: uint64_t,
	pub socket_id: int32_t,
	pub nchannel: uint32_t,
	pub nrank: uint32_t,
}

impl rte_memseg
{
	pub unsafe fn addr(&mut self) -> *mut *mut c_void
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
	pub unsafe fn addr_64(&mut self) -> *mut uint64_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
}

impl Default for rte_memseg
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_atomic16_t
{
	pub cnt: int16_t,
}

impl Default for rte_atomic16_t
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_atomic32_t
{
	pub cnt: int32_t,
}

impl Default for rte_atomic32_t
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_atomic64_t
{
	pub cnt: int64_t,
}

impl Default for rte_atomic64_t
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_memzone
{
	pub name: [c_char; 32usize],
	pub phys_addr: phys_addr_t,
	pub _bindgen_data_1_: [u64; 1usize],
	pub len: size_t,
	pub hugepage_sz: uint64_t,
	pub socket_id: int32_t,
	pub flags: uint32_t,
	pub memseg_id: uint32_t,
}

impl rte_memzone
{
	pub unsafe fn addr(&mut self) -> *mut *mut c_void
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
	pub unsafe fn addr_64(&mut self) -> *mut uint64_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
}

impl Default for rte_memzone
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum rte_ring_queue_behavior
{
	RTE_RING_QUEUE_FIXED = 0,
	RTE_RING_QUEUE_VARIABLE = 1,
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_ring
{
	pub name: [c_char; 32usize],
	pub flags: c_int,
	pub memzone: *const rte_memzone,
	pub prod: prod,
	pub cons: cons,
	pub ring: [*mut c_void; 0usize],
}

impl Default for rte_ring
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct prod
{
	pub watermark: uint32_t,
	pub sp_enqueue: uint32_t,
	pub size: uint32_t,
	pub mask: uint32_t,
	pub head: uint32_t,
	pub tail: uint32_t,
}

impl Default for prod
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct cons
{
	pub sc_dequeue: uint32_t,
	pub size: uint32_t,
	pub mask: uint32_t,
	pub head: uint32_t,
	pub tail: uint32_t,
}

impl Default for cons
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct rte_mempool_cache
{
	pub size: uint32_t,
	pub flushthresh: uint32_t,
	pub len: uint32_t,
	pub objs: [*mut c_void; 1536usize],
}

impl Clone for rte_mempool_cache
{
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for rte_mempool_cache
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_mempool_objsz
{
	pub elt_size: uint32_t,
	pub header_size: uint32_t,
	pub trailer_size: uint32_t,
	pub total_size: uint32_t,
}

impl Default for rte_mempool_objsz
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_mempool_objhdr
{
	pub next: Struct_Unnamed2,
	pub mp: *mut rte_mempool,
	pub physaddr: phys_addr_t,
}

impl Default for rte_mempool_objhdr
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed2
{
	pub stqe_next: *mut rte_mempool_objhdr,
}

impl Default for Struct_Unnamed2
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_mempool_objhdr_list
{
	pub stqh_first: *mut rte_mempool_objhdr,
	pub stqh_last: *mut *mut rte_mempool_objhdr,
}

impl Default for rte_mempool_objhdr_list
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_mempool_memhdr_list
{
	pub stqh_first: *mut rte_mempool_memhdr,
	pub stqh_last: *mut *mut rte_mempool_memhdr,
}

impl Default for rte_mempool_memhdr_list
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

pub type rte_mempool_memchunk_free_cb_t = Option<unsafe extern "C" fn(memhdr: *mut rte_mempool_memhdr, opaque: *mut c_void)>;

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_mempool_memhdr
{
	pub next: Struct_Unnamed3,
	pub mp: *mut rte_mempool,
	pub addr: *mut c_void,
	pub phys_addr: phys_addr_t,
	pub len: size_t,
	pub free_cb: rte_mempool_memchunk_free_cb_t,
	pub opaque: *mut c_void,
}

impl Default for rte_mempool_memhdr
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed3
{
	pub stqe_next: *mut rte_mempool_memhdr,
}

impl Default for Struct_Unnamed3
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_mempool
{
	pub name: [c_char; 32usize],
	pub _bindgen_data_1_: [u64; 1usize],
	pub pool_config: *mut c_void,
	pub mz: *const rte_memzone,
	pub flags: c_int,
	pub socket_id: c_int,
	pub size: uint32_t,
	pub cache_size: uint32_t,
	pub elt_size: uint32_t,
	pub header_size: uint32_t,
	pub trailer_size: uint32_t,
	pub private_data_size: c_uint,
	pub ops_index: int32_t,
	pub local_cache: *mut rte_mempool_cache,
	pub populated_size: uint32_t,
	pub elt_list: rte_mempool_objhdr_list,
	pub nb_mem_chunks: uint32_t,
	pub mem_list: rte_mempool_memhdr_list,
}

impl rte_mempool
{
	pub unsafe fn pool_data(&mut self) -> *mut *mut c_void
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
	pub unsafe fn pool_id(&mut self) -> *mut uint64_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
}

impl Default for rte_mempool
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[allow(missing_copy_implementations)]
#[derive(Debug)]
pub enum rte_mempool_objtlr
{
}

pub type rte_mempool_alloc_t = Option<unsafe extern "C" fn(mp: *mut rte_mempool) -> c_int>;

pub type rte_mempool_free_t = Option<unsafe extern "C" fn(mp: *mut rte_mempool)>;

pub type rte_mempool_enqueue_t = Option<unsafe extern "C" fn(mp: *mut rte_mempool, obj_table: *const *mut c_void, n: c_uint) -> c_int>;

pub type rte_mempool_dequeue_t = Option<unsafe extern "C" fn(mp: *mut rte_mempool, obj_table: *mut *mut c_void, n: c_uint) -> c_int>;

pub type rte_mempool_get_count = Option<unsafe extern "C" fn(mp: *const rte_mempool) -> c_uint>;

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_mempool_ops
{
	pub name: [c_char; 32usize],
	pub alloc: rte_mempool_alloc_t,
	pub free: rte_mempool_free_t,
	pub enqueue: rte_mempool_enqueue_t,
	pub dequeue: rte_mempool_dequeue_t,
	pub get_count: rte_mempool_get_count,
}

impl Default for rte_mempool_ops
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_mempool_ops_table
{
	pub sl: rte_spinlock_t,
	pub num_ops: uint32_t,
	_bindgen_padding_0_: [u64; 7usize],
	pub ops: [rte_mempool_ops; 16usize],
}

impl Default for rte_mempool_ops_table
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

pub type rte_mempool_obj_cb_t = Option<unsafe extern "C" fn(mp: *mut rte_mempool, opaque: *mut c_void, obj: *mut c_void, obj_idx: c_uint)>;

pub type rte_mempool_obj_ctor_t = rte_mempool_obj_cb_t;

pub type rte_mempool_mem_cb_t = Option<unsafe extern "C" fn(mp: *mut rte_mempool, opaque: *mut c_void, memhdr: *mut rte_mempool_memhdr, mem_idx: c_uint)>;

pub type rte_mempool_ctor_t = Option<unsafe extern "C" fn(arg1: *mut rte_mempool, arg2: *mut c_void)>;

pub type MARKER = [*mut c_void; 0usize];

pub type MARKER8 = [uint8_t; 0usize];

pub type MARKER64 = [uint64_t; 0usize];

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_mbuf
{
	pub cacheline0: MARKER,
	pub buf_addr: *mut c_void,
	pub buf_physaddr: phys_addr_t,
	pub buf_len: uint16_t,
	pub rearm_data: MARKER8,
	pub data_off: uint16_t,
	pub _bindgen_data_1_: [u16; 1usize],
	pub nb_segs: uint8_t,
	pub port: uint8_t,
	pub ol_flags: uint64_t,
	pub rx_descriptor_fields1: MARKER,
	pub _bindgen_data_2_: [u32; 1usize],
	pub pkt_len: uint32_t,
	pub data_len: uint16_t,
	pub vlan_tci: uint16_t,
	pub hash: Union_Unnamed4,
	pub seqn: uint32_t,
	pub vlan_tci_outer: uint16_t,
	pub cacheline1: MARKER,
	pub _bindgen_data_3_: [u64; 1usize],
	pub pool: *mut rte_mempool,
	pub next: *mut rte_mbuf,
	pub _bindgen_data_4_: [u64; 1usize],
	pub priv_size: uint16_t,
	pub timesync: uint16_t,
	_bindgen_padding_0_: [u64; 3usize],
}

impl rte_mbuf
{
	pub unsafe fn refcnt_atomic(&mut self) -> *mut rte_atomic16_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
	pub unsafe fn refcnt(&mut self) -> *mut uint16_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
	pub unsafe fn packet_type(&mut self) -> *mut uint32_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_2_);
		transmute(raw.offset(0))
	}
	pub unsafe fn userdata(&mut self) -> *mut *mut c_void
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_3_);
		transmute(raw.offset(0))
	}
	pub unsafe fn udata64(&mut self) -> *mut uint64_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_3_);
		transmute(raw.offset(0))
	}
	pub unsafe fn tx_offload(&mut self) -> *mut uint64_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_4_);
		transmute(raw.offset(0))
	}
}

impl Default for rte_mbuf
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Union_Unnamed4
{
	pub _bindgen_data_: [u32; 2usize],
}

impl Union_Unnamed4
{
	pub unsafe fn rss(&mut self) -> *mut uint32_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
	pub unsafe fn fdir(&mut self) -> *mut Struct_Unnamed5
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
	pub unsafe fn sched(&mut self) -> *mut Struct_Unnamed6
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
	pub unsafe fn usr(&mut self) -> *mut uint32_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
}

impl Default for Union_Unnamed4
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed5
{
	pub _bindgen_data_1_: [u32; 1usize],
	pub hi: uint32_t,
}

impl Struct_Unnamed5
{
	pub unsafe fn hash(&mut self) -> *mut uint16_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
	pub unsafe fn id(&mut self) -> *mut uint16_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(2))
	}
	pub unsafe fn lo(&mut self) -> *mut uint32_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
}

impl Default for Struct_Unnamed5
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed6
{
	pub lo: uint32_t,
	pub hi: uint32_t,
}

impl Default for Struct_Unnamed6
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_pktmbuf_pool_private
{
	pub mbuf_data_room_size: uint16_t,
	pub mbuf_priv_size: uint16_t,
}

impl Default for rte_pktmbuf_pool_private
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct ether_addr
{
	pub addr_bytes: [uint8_t; 6usize],
}

impl Default for ether_addr
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct ether_hdr
{
	pub d_addr: ether_addr,
	pub s_addr: ether_addr,
	pub ether_type: uint16_t,
}

impl Default for ether_hdr
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct vlan_hdr
{
	pub vlan_tci: uint16_t,
	pub eth_proto: uint16_t,
}

impl Default for vlan_hdr
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct vxlan_hdr
{
	pub vx_flags: uint32_t,
	pub vx_vni: uint32_t,
}

impl Default for vxlan_hdr
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct arp_ipv4
{
	pub arp_sha: ether_addr,
	pub arp_sip: uint32_t,
	pub arp_tha: ether_addr,
	pub arp_tip: uint32_t,
}

impl Default for arp_ipv4
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct arp_hdr
{
	pub arp_hrd: uint16_t,
	pub arp_pro: uint16_t,
	pub arp_hln: uint8_t,
	pub arp_pln: uint8_t,
	pub arp_op: uint16_t,
	pub arp_data: arp_ipv4,
}

impl Default for arp_hdr
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[allow(missing_copy_implementations)]
#[derive(Debug)]
pub enum rte_cfgfile
{
}

#[repr(C)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct rte_cfgfile_entry
{
	pub name: [c_char; 64usize],
	pub value: [c_char; 256usize],
}

impl Clone for rte_cfgfile_entry
{
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for rte_cfgfile_entry
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum rte_crypto_cipher_algorithm
{
	RTE_CRYPTO_CIPHER_NULL = 1,
	RTE_CRYPTO_CIPHER_3DES_CBC = 2,
	RTE_CRYPTO_CIPHER_3DES_CTR = 3,
	RTE_CRYPTO_CIPHER_3DES_ECB = 4,
	RTE_CRYPTO_CIPHER_AES_CBC = 5,
	RTE_CRYPTO_CIPHER_AES_CCM = 6,
	RTE_CRYPTO_CIPHER_AES_CTR = 7,
	RTE_CRYPTO_CIPHER_AES_ECB = 8,
	RTE_CRYPTO_CIPHER_AES_F8 = 9,
	RTE_CRYPTO_CIPHER_AES_GCM = 10,
	RTE_CRYPTO_CIPHER_AES_XTS = 11,
	RTE_CRYPTO_CIPHER_ARC4 = 12,
	RTE_CRYPTO_CIPHER_KASUMI_F8 = 13,
	RTE_CRYPTO_CIPHER_SNOW3G_UEA2 = 14,
	RTE_CRYPTO_CIPHER_ZUC_EEA3 = 15,
	RTE_CRYPTO_CIPHER_LIST_END = 16,
}

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum rte_crypto_cipher_operation
{
	RTE_CRYPTO_CIPHER_OP_ENCRYPT = 0,
	RTE_CRYPTO_CIPHER_OP_DECRYPT = 1,
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_crypto_cipher_xform
{
	pub op: rte_crypto_cipher_operation,
	pub algo: rte_crypto_cipher_algorithm,
	pub key: Struct_Unnamed7,
}

impl Default for rte_crypto_cipher_xform
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed7
{
	pub data: *mut uint8_t,
	pub length: size_t,
}

impl Default for Struct_Unnamed7
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum rte_crypto_auth_algorithm
{
	RTE_CRYPTO_AUTH_NULL = 1,
	RTE_CRYPTO_AUTH_AES_CBC_MAC = 2,
	RTE_CRYPTO_AUTH_AES_CCM = 3,
	RTE_CRYPTO_AUTH_AES_CMAC = 4,
	RTE_CRYPTO_AUTH_AES_GCM = 5,
	RTE_CRYPTO_AUTH_AES_GMAC = 6,
	RTE_CRYPTO_AUTH_AES_XCBC_MAC = 7,
	RTE_CRYPTO_AUTH_KASUMI_F9 = 8,
	RTE_CRYPTO_AUTH_MD5 = 9,
	RTE_CRYPTO_AUTH_MD5_HMAC = 10,
	RTE_CRYPTO_AUTH_SHA1 = 11,
	RTE_CRYPTO_AUTH_SHA1_HMAC = 12,
	RTE_CRYPTO_AUTH_SHA224 = 13,
	RTE_CRYPTO_AUTH_SHA224_HMAC = 14,
	RTE_CRYPTO_AUTH_SHA256 = 15,
	RTE_CRYPTO_AUTH_SHA256_HMAC = 16,
	RTE_CRYPTO_AUTH_SHA384 = 17,
	RTE_CRYPTO_AUTH_SHA384_HMAC = 18,
	RTE_CRYPTO_AUTH_SHA512 = 19,
	RTE_CRYPTO_AUTH_SHA512_HMAC = 20,
	RTE_CRYPTO_AUTH_SNOW3G_UIA2 = 21,
	RTE_CRYPTO_AUTH_ZUC_EIA3 = 22,
	RTE_CRYPTO_AUTH_LIST_END = 23,
}

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum rte_crypto_auth_operation
{
	RTE_CRYPTO_AUTH_OP_VERIFY = 0,
	RTE_CRYPTO_AUTH_OP_GENERATE = 1,
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_crypto_auth_xform
{
	pub op: rte_crypto_auth_operation,
	pub algo: rte_crypto_auth_algorithm,
	pub key: Struct_Unnamed8,
	pub digest_length: uint32_t,
	pub add_auth_data_length: uint32_t,
}

impl Default for rte_crypto_auth_xform
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed8
{
	pub data: *mut uint8_t,
	pub length: size_t,
}

impl Default for Struct_Unnamed8
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum rte_crypto_sym_xform_type
{
	RTE_CRYPTO_SYM_XFORM_NOT_SPECIFIED = 0,
	RTE_CRYPTO_SYM_XFORM_AUTH = 1,
	RTE_CRYPTO_SYM_XFORM_CIPHER = 2,
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_crypto_sym_xform
{
	pub next: *mut rte_crypto_sym_xform,
	pub type_: rte_crypto_sym_xform_type,
	pub _bindgen_data_1_: [u64; 4usize],
}

impl rte_crypto_sym_xform
{
	pub unsafe fn auth(&mut self) -> *mut rte_crypto_auth_xform
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
	pub unsafe fn cipher(&mut self) -> *mut rte_crypto_cipher_xform
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
}

impl Default for rte_crypto_sym_xform
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum rte_crypto_sym_op_sess_type
{
	RTE_CRYPTO_SYM_OP_WITH_SESSION = 0,
	RTE_CRYPTO_SYM_OP_SESSIONLESS = 1,
}

#[allow(missing_copy_implementations)]
#[derive(Debug)]
pub enum rte_cryptodev_sym_session
{
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_crypto_sym_op
{
	pub m_src: *mut rte_mbuf,
	pub m_dst: *mut rte_mbuf,
	pub sess_type: rte_crypto_sym_op_sess_type,
	pub _bindgen_data_1_: [u64; 1usize],
	pub cipher: Struct_Unnamed9,
	pub auth: Struct_Unnamed12,
	_bindgen_padding_0_: [u64; 1usize],
}

impl rte_crypto_sym_op
{
	pub unsafe fn session(&mut self) -> *mut *mut rte_cryptodev_sym_session
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
	pub unsafe fn xform(&mut self) -> *mut *mut rte_crypto_sym_xform
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
}

impl Default for rte_crypto_sym_op
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed9
{
	pub data: Struct_Unnamed10,
	pub iv: Struct_Unnamed11,
}

impl Default for Struct_Unnamed9
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed10
{
	pub offset: uint32_t,
	pub length: uint32_t,
}

impl Default for Struct_Unnamed10
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed11
{
	pub data: *mut uint8_t,
	pub phys_addr: phys_addr_t,
	pub length: uint16_t,
	_bindgen_padding_0_: [u8; 6usize],
}

impl Default for Struct_Unnamed11
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed12
{
	pub data: Struct_Unnamed13,
	pub digest: Struct_Unnamed14,
	pub aad: Struct_Unnamed15,
}

impl Default for Struct_Unnamed12
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed13
{
	pub offset: uint32_t,
	pub length: uint32_t,
}

impl Default for Struct_Unnamed13
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed14
{
	pub data: *mut uint8_t,
	pub phys_addr: phys_addr_t,
	pub length: uint16_t,
	_bindgen_padding_0_: [u8; 6usize],
}

impl Default for Struct_Unnamed14
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed15
{
	pub data: *mut uint8_t,
	pub phys_addr: phys_addr_t,
	pub length: uint16_t,
	_bindgen_padding_0_: [u8; 6usize],
}

impl Default for Struct_Unnamed15
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum rte_crypto_op_type
{
	RTE_CRYPTO_OP_TYPE_UNDEFINED = 0,
	RTE_CRYPTO_OP_TYPE_SYMMETRIC = 1,
}

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum rte_crypto_op_status
{
	RTE_CRYPTO_OP_STATUS_SUCCESS = 0,
	RTE_CRYPTO_OP_STATUS_NOT_PROCESSED = 1,
	RTE_CRYPTO_OP_STATUS_ENQUEUED = 2,
	RTE_CRYPTO_OP_STATUS_AUTH_FAILED = 3,
	RTE_CRYPTO_OP_STATUS_INVALID_SESSION = 4,
	RTE_CRYPTO_OP_STATUS_INVALID_ARGS = 5,
	RTE_CRYPTO_OP_STATUS_ERROR = 6,
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_crypto_op
{
	pub type_: rte_crypto_op_type,
	pub status: rte_crypto_op_status,
	pub mempool: *mut rte_mempool,
	pub phys_addr: phys_addr_t,
	pub opaque_data: *mut c_void,
	pub _bindgen_data_1_: [u64; 1usize],
	_bindgen_padding_0_: [u64; 3usize],
}

impl rte_crypto_op
{
	pub unsafe fn sym(&mut self) -> *mut *mut rte_crypto_sym_op
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
}

impl Default for rte_crypto_op
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_crypto_op_pool_private
{
	pub type_: rte_crypto_op_type,
	pub priv_size: uint16_t,
	_bindgen_padding_0_: [u8; 2usize],
}

impl Default for rte_crypto_op_pool_private
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_driver_list
{
	pub tqh_first: *mut rte_driver,
	pub tqh_last: *mut *mut rte_driver,
}

impl Default for rte_driver_list
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

pub type rte_dev_init_t = Option<unsafe extern "C" fn(name: *const c_char, args: *const c_char) -> c_int>;

pub type rte_dev_uninit_t = Option<unsafe extern "C" fn(name: *const c_char) -> c_int>;

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum pmd_type
{
	PMD_VDEV = 0,
	PMD_PDEV = 1,
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_driver
{
	pub next: Struct_Unnamed16,
	pub type_: pmd_type,
	pub name: *const c_char,
	pub init: rte_dev_init_t,
	pub uninit: rte_dev_uninit_t,
}

impl Default for rte_driver
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed16
{
	pub tqe_next: *mut rte_driver,
	pub tqe_prev: *mut *mut rte_driver,
}

impl Default for Struct_Unnamed16
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_dev_reg_info
{
	pub data: *mut c_void,
	pub offset: uint32_t,
	pub length: uint32_t,
	pub width: uint32_t,
	pub version: uint32_t,
}

impl Default for rte_dev_reg_info
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_dev_eeprom_info
{
	pub data: *mut c_void,
	pub offset: uint32_t,
	pub length: uint32_t,
	pub magic: uint32_t,
	_bindgen_padding_0_: [u8; 4usize],
}

impl Default for rte_dev_eeprom_info
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[allow(missing_copy_implementations)]
#[derive(Debug)]
pub enum rte_distributor
{
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_tailq_entry
{
	pub next: Struct_Unnamed17,
	pub data: *mut c_void,
}

impl Default for rte_tailq_entry
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed17
{
	pub tqe_next: *mut rte_tailq_entry,
	pub tqe_prev: *mut *mut rte_tailq_entry,
}

impl Default for Struct_Unnamed17
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_tailq_entry_head
{
	pub tqh_first: *mut rte_tailq_entry,
	pub tqh_last: *mut *mut rte_tailq_entry,
}

impl Default for rte_tailq_entry_head
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_tailq_head
{
	pub tailq_head: rte_tailq_entry_head,
	pub name: [c_char; 32usize],
}

impl Default for rte_tailq_head
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_tailq_elem
{
	pub head: *mut rte_tailq_head,
	pub next: Struct_Unnamed18,
	pub name: [c_char; 32usize],
}

impl Default for rte_tailq_elem
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed18
{
	pub tqe_next: *mut rte_tailq_elem,
	pub tqe_prev: *mut *mut rte_tailq_elem,
}

impl Default for Struct_Unnamed18
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[allow(missing_copy_implementations)]
#[derive(Debug)]
pub enum malloc_elem
{
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct malloc_heap
{
	pub lock: rte_spinlock_t,
	pub free_head: [Struct_Unnamed19; 13usize],
	pub alloc_count: c_uint,
	pub total_size: size_t,
}

impl Default for malloc_heap
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed19
{
	pub lh_first: *mut malloc_elem,
}

impl Default for Struct_Unnamed19
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_rwlock_t
{
	pub cnt: int32_t,
}

impl Default for rte_rwlock_t
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C, packed)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct rte_mem_config
{
	pub magic: uint32_t,
	pub nchannel: uint32_t,
	pub nrank: uint32_t,
	pub mlock: rte_rwlock_t,
	pub qlock: rte_rwlock_t,
	pub mplock: rte_rwlock_t,
	pub memzone_cnt: uint32_t,
	pub memseg: [rte_memseg; 256usize],
	pub memzone: [rte_memzone; 2560usize],
	pub tailq_head: [rte_tailq_head; 32usize],
	pub malloc_heaps: [malloc_heap; 8usize],
	pub mem_cfg_addr: uint64_t,
}

impl Clone for rte_mem_config
{
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for rte_mem_config
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum Enum_Unnamed20
{
	RTE_MIN_ERRNO = 1000,
	E_RTE_SECONDARY = 1001,
	E_RTE_NO_CONFIG = 1002,
	RTE_MAX_ERRNO = 1003,
}

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum Enum_Unnamed21
{
	VIRTIO_RXQ = 0,
	VIRTIO_TXQ = 1,
	VIRTIO_QNUM = 2,
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct virtio_net_device_ops
{
	pub new_device: Option<extern "C" fn(vid: c_int) -> c_int>,
	pub destroy_device: Option<extern "C" fn(vid: c_int)>,
	pub vring_state_changed: Option<extern "C" fn(vid: c_int, queue_id: uint16_t, enable: c_int) -> c_int>,
	pub reserved: [*mut c_void; 5usize],
}

impl Default for virtio_net_device_ops
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_eth_vhost_queue_event
{
	pub queue_id: uint16_t,
	pub rx: u8,
	pub enable: u8,
}

impl Default for rte_eth_vhost_queue_event
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

pub type rte_fbk_hash_fn = Option<extern "C" fn(key: uint32_t, init_val: uint32_t) -> uint32_t>;

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_fbk_hash_params
{
	pub name: *const c_char,
	pub entries: uint32_t,
	pub entries_per_bucket: uint32_t,
	pub socket_id: c_int,
	pub hash_func: rte_fbk_hash_fn,
	pub init_val: uint32_t,
	_bindgen_padding_0_: [u8; 4usize],
}

impl Default for rte_fbk_hash_params
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_fbk_hash_entry
{
	pub _bindgen_data_: [u64; 1usize],
}

impl rte_fbk_hash_entry
{
	pub unsafe fn whole_entry(&mut self) -> *mut uint64_t
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
	pub unsafe fn entry(&mut self) -> *mut Struct_Unnamed22
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_);
		transmute(raw.offset(0))
	}
}

impl Default for rte_fbk_hash_entry
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed22
{
	pub is_entry: uint16_t,
	pub value: uint16_t,
	pub key: uint32_t,
}

impl Default for Struct_Unnamed22
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_fbk_hash_table
{
	pub name: [c_char; 32usize],
	pub entries: uint32_t,
	pub entries_per_bucket: uint32_t,
	pub used_entries: uint32_t,
	pub bucket_mask: uint32_t,
	pub bucket_shift: uint32_t,
	pub hash_func: rte_fbk_hash_fn,
	pub init_val: uint32_t,
	pub t: [rte_fbk_hash_entry; 0usize],
}

impl Default for rte_fbk_hash_table
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

pub type hash_sig_t = uint32_t;

pub type rte_hash_function = Option<unsafe extern "C" fn(key: *const c_void, key_len: uint32_t, init_val: uint32_t) -> uint32_t>;

pub type rte_hash_cmp_eq_t = Option<unsafe extern "C" fn(key1: *const c_void, key2: *const c_void, key_len: size_t) -> c_int>;

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_hash_parameters
{
	pub name: *const c_char,
	pub entries: uint32_t,
	pub reserved: uint32_t,
	pub key_len: uint32_t,
	pub hash_func: rte_hash_function,
	pub hash_func_init_val: uint32_t,
	pub socket_id: c_int,
	pub extra_flag: uint8_t,
	_bindgen_padding_0_: [u8; 7usize],
}

impl Default for rte_hash_parameters
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[allow(missing_copy_implementations)]
#[derive(Debug)]
pub enum rte_hash
{
}

#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct icmp_hdr
{
	pub icmp_type: uint8_t,
	pub icmp_code: uint8_t,
	pub icmp_cksum: uint16_t,
	pub icmp_ident: uint16_t,
	pub icmp_seq_nb: uint16_t,
}

impl Default for icmp_hdr
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

pub type rte_intr_callback_fn = Option<unsafe extern "C" fn(intr_handle: *mut rte_intr_handle, cb_arg: *mut c_void)>;

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum rte_intr_handle_type
{
	RTE_INTR_HANDLE_UNKNOWN = 0,
	RTE_INTR_HANDLE_UIO = 1,
	RTE_INTR_HANDLE_UIO_INTX = 2,
	RTE_INTR_HANDLE_VFIO_LEGACY = 3,
	RTE_INTR_HANDLE_VFIO_MSI = 4,
	RTE_INTR_HANDLE_VFIO_MSIX = 5,
	RTE_INTR_HANDLE_ALARM = 6,
	RTE_INTR_HANDLE_EXT = 7,
	RTE_INTR_HANDLE_MAX = 8,
}

pub type rte_intr_event_cb_t = Option<unsafe extern "C" fn(fd: c_int, arg: *mut c_void)>;

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_epoll_data
{
	pub event: uint32_t,
	pub data: *mut c_void,
	pub cb_fun: rte_intr_event_cb_t,
	pub cb_arg: *mut c_void,
}

impl Default for rte_epoll_data
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum Enum_Unnamed23
{
	RTE_EPOLL_INVALID = 0,
	RTE_EPOLL_VALID = 1,
	RTE_EPOLL_EXEC = 2,
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_epoll_event
{
	pub status: uint32_t,
	pub fd: c_int,
	pub epfd: c_int,
	pub epdata: rte_epoll_data,
}

impl Default for rte_epoll_event
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_intr_handle
{
	pub _bindgen_data_1_: [u32; 1usize],
	pub fd: c_int,
	pub type_: rte_intr_handle_type,
	pub max_intr: uint32_t,
	pub nb_efd: uint32_t,
	pub efds: [c_int; 32usize],
	pub elist: [rte_epoll_event; 32usize],
	pub intr_vec: *mut c_int,
}

impl rte_intr_handle
{
	pub unsafe fn vfio_dev_fd(&mut self) -> *mut c_int
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
	pub unsafe fn uio_cfg_fd(&mut self) -> *mut c_int
	{
		let raw: *mut u8 = transmute(&self._bindgen_data_1_);
		transmute(raw.offset(0))
	}
}

impl Default for rte_intr_handle
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct ipv4_hdr
{
	pub version_ihl: uint8_t,
	pub type_of_service: uint8_t,
	pub total_length: uint16_t,
	pub packet_id: uint16_t,
	pub fragment_offset: uint16_t,
	pub time_to_live: uint8_t,
	pub next_proto_id: uint8_t,
	pub hdr_checksum: uint16_t,
	pub src_addr: uint32_t,
	pub dst_addr: uint32_t,
}

impl Default for ipv4_hdr
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct ipv6_hdr
{
	pub vtc_flow: uint32_t,
	pub payload_len: uint16_t,
	pub proto: uint8_t,
	pub hop_limits: uint8_t,
	pub src_addr: [uint8_t; 16usize],
	pub dst_addr: [uint8_t; 16usize],
}

impl Default for ipv6_hdr
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_malloc_socket_stats
{
	pub heap_totalsz_bytes: size_t,
	pub heap_freesz_bytes: size_t,
	pub greatest_free_size: size_t,
	pub free_count: c_uint,
	pub alloc_count: c_uint,
	pub heap_allocsz_bytes: size_t,
}

impl Default for rte_malloc_socket_stats
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum Enum_Unnamed24
{
	IP_LAST_FRAG_IDX = 0,
	IP_FIRST_FRAG_IDX = 1,
	IP_MIN_FRAG_NUM = 2,
	IP_MAX_FRAG_NUM = 4,
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct ip_frag
{
	pub ofs: uint16_t,
	pub len: uint16_t,
	pub mb: *mut rte_mbuf,
}

impl Default for ip_frag
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct ip_frag_key
{
	pub src_dst: [uint64_t; 4usize],
	pub id: uint32_t,
	pub key_len: uint32_t,
}

impl Default for ip_frag_key
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct ip_frag_pkt
{
	pub lru: Struct_Unnamed25,
	pub key: ip_frag_key,
	pub start: uint64_t,
	pub total_size: uint32_t,
	pub frag_size: uint32_t,
	pub last_idx: uint32_t,
	pub frags: [ip_frag; 4usize],
}

impl Default for ip_frag_pkt
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed25
{
	pub tqe_next: *mut ip_frag_pkt,
	pub tqe_prev: *mut *mut ip_frag_pkt,
}

impl Default for Struct_Unnamed25
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy)]
#[allow(missing_debug_implementations)]
pub struct rte_ip_frag_death_row
{
	pub cnt: uint32_t,
	pub row: [*mut rte_mbuf; 160usize],
}

impl Clone for rte_ip_frag_death_row
{
	fn clone(&self) -> Self
	{
		*self
	}
}

impl Default for rte_ip_frag_death_row
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct ip_pkt_list
{
	pub tqh_first: *mut ip_frag_pkt,
	pub tqh_last: *mut *mut ip_frag_pkt,
}

impl Default for ip_pkt_list
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct ip_frag_tbl_stat
{
	pub find_num: uint64_t,
	pub add_num: uint64_t,
	pub del_num: uint64_t,
	pub reuse_num: uint64_t,
	pub fail_total: uint64_t,
	pub fail_nospace: uint64_t,
	_bindgen_padding_0_: [u64; 2usize],
}

impl Default for ip_frag_tbl_stat
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_ip_frag_tbl
{
	pub max_cycles: uint64_t,
	pub entry_mask: uint32_t,
	pub max_entries: uint32_t,
	pub use_entries: uint32_t,
	pub bucket_entries: uint32_t,
	pub nb_entries: uint32_t,
	pub nb_buckets: uint32_t,
	pub last: *mut ip_frag_pkt,
	pub lru: ip_pkt_list,
	pub stat: ip_frag_tbl_stat,
	pub pkt: [ip_frag_pkt; 0usize],
}

impl Default for rte_ip_frag_tbl
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct ipv6_extension_fragment
{
	pub next_header: uint8_t,
	pub reserved: uint8_t,
	pub frag_data: uint16_t,
	pub id: uint32_t,
}

impl Default for ipv6_extension_fragment
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

pub type rte_job_update_period_cb_t = Option<unsafe extern "C" fn(job: *mut rte_jobstats, job_result: int64_t)>;

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_jobstats
{
	pub period: uint64_t,
	pub min_period: uint64_t,
	pub max_period: uint64_t,
	pub target: int64_t,
	pub update_period_cb: rte_job_update_period_cb_t,
	pub exec_time: uint64_t,
	pub min_exec_time: uint64_t,
	pub max_exec_time: uint64_t,
	pub exec_cnt: uint64_t,
	pub name: [c_char; 32usize],
	pub context: *mut rte_jobstats_context,
}

impl Default for rte_jobstats
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct rte_jobstats_context
{
	pub state_time: uint64_t,
	pub loop_executed_jobs: uint64_t,
	pub exec_time: uint64_t,
	pub min_exec_time: uint64_t,
	pub max_exec_time: uint64_t,
	pub management_time: uint64_t,
	pub min_management_time: uint64_t,
	pub max_management_time: uint64_t,
	pub start_time: uint64_t,
	pub job_exec_cnt: uint64_t,
	pub loop_cnt: uint64_t,
	_bindgen_padding_0_: [u64; 5usize],
}

impl Default for rte_jobstats_context
{
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}

extern "C"
{
	pub static mut cmdline_vt100_commands: [*const c_char; 0usize];
	pub static mut cmdline_token_etheraddr_ops: cmdline_token_ops;
	pub static mut cmdline_token_ipaddr_ops: cmdline_token_ops;
	pub static mut cmdline_token_num_ops: cmdline_token_ops;
	pub static mut cmdline_token_portlist_ops: cmdline_token_ops;
	pub static mut cmdline_token_string_ops: cmdline_token_ops;
	pub static mut lcore_config: [lcore_config; 128usize];
	pub static mut per_lcore__lcore_id: c_void;
	pub static mut per_lcore__cpuset: c_void;
	pub static mut rte_rtm_supported: uint8_t;
	pub static mut rte_logs: rte_logs;
	pub static mut eal_default_log_stream: *mut FILE;
	pub static mut rte_mempool_ops_table: rte_mempool_ops_table;
	pub static mut per_lcore__rte_errno: c_void;
}

extern "C"
{
	pub fn cirbuf_init(cbuf: *mut cirbuf, buf: *mut c_char, start: c_uint, maxlen: c_uint) -> c_int;
	pub fn cirbuf_add_head_safe(cbuf: *mut cirbuf, c: c_char) -> c_int;
	pub fn cirbuf_add_head(cbuf: *mut cirbuf, c: c_char);
	pub fn cirbuf_add_tail_safe(cbuf: *mut cirbuf, c: c_char) -> c_int;
	pub fn cirbuf_add_tail(cbuf: *mut cirbuf, c: c_char);
	pub fn cirbuf_del_head_safe(cbuf: *mut cirbuf) -> c_int;
	pub fn cirbuf_del_head(cbuf: *mut cirbuf);
	pub fn cirbuf_del_tail_safe(cbuf: *mut cirbuf) -> c_int;
	pub fn cirbuf_del_tail(cbuf: *mut cirbuf);
	pub fn cirbuf_get_head(cbuf: *mut cirbuf) -> c_char;
	pub fn cirbuf_get_tail(cbuf: *mut cirbuf) -> c_char;
	pub fn cirbuf_add_buf_head(cbuf: *mut cirbuf, c: *const c_char, n: c_uint) -> c_int;
	pub fn cirbuf_add_buf_tail(cbuf: *mut cirbuf, c: *const c_char, n: c_uint) -> c_int;
	pub fn cirbuf_del_buf_head(cbuf: *mut cirbuf, size: c_uint) -> c_int;
	pub fn cirbuf_del_buf_tail(cbuf: *mut cirbuf, size: c_uint) -> c_int;
	pub fn cirbuf_get_buf_head(cbuf: *mut cirbuf, c: *mut c_char, size: c_uint) -> c_int;
	pub fn cirbuf_get_buf_tail(cbuf: *mut cirbuf, c: *mut c_char, size: c_uint) -> c_int;
	pub fn cirbuf_align_left(cbuf: *mut cirbuf) -> c_int;
	pub fn cirbuf_align_right(cbuf: *mut cirbuf) -> c_int;
	pub fn vt100_init(vt: *mut cmdline_vt100);
	pub fn vt100_parser(vt: *mut cmdline_vt100, c: c_char) -> c_int;
	pub fn rdline_init(rdl: *mut rdline, write_char: rdline_write_char_t, validate: rdline_validate_t, complete: rdline_complete_t) -> c_int;
	pub fn rdline_newline(rdl: *mut rdline, prompt: *const c_char);
	pub fn rdline_stop(rdl: *mut rdline);
	pub fn rdline_quit(rdl: *mut rdline);
	pub fn rdline_restart(rdl: *mut rdline);
	pub fn rdline_redisplay(rdl: *mut rdline);
	pub fn rdline_reset(rdl: *mut rdline);
	pub fn rdline_char_in(rdl: *mut rdline, c: c_char) -> c_int;
	pub fn rdline_get_buffer(rdl: *mut rdline) -> *const c_char;
	pub fn rdline_add_history(rdl: *mut rdline, buf: *const c_char) -> c_int;
	pub fn rdline_clear_history(rdl: *mut rdline);
	pub fn rdline_get_history_item(rdl: *mut rdline, i: c_uint) -> *mut c_char;
	pub fn cmdline_parse(cl: *mut cmdline, buf: *const c_char) -> c_int;
	pub fn cmdline_complete(cl: *mut cmdline, buf: *const c_char, state: *mut c_int, dst: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_isendoftoken(c: c_char) -> c_int;
	pub fn cmdline_isendofcommand(c: c_char) -> c_int;
	pub fn cmdline_new(ctx: *mut cmdline_parse_ctx_t, prompt: *const c_char, s_in: c_int, s_out: c_int) -> *mut cmdline;
	pub fn cmdline_set_prompt(cl: *mut cmdline, prompt: *const c_char);
	pub fn cmdline_free(cl: *mut cmdline);
	pub fn cmdline_printf(cl: *const cmdline, fmt: *const c_char, ...);
	pub fn cmdline_in(cl: *mut cmdline, buf: *const c_char, size: c_int) -> c_int;
	pub fn cmdline_write_char(rdl: *mut rdline, c: c_char) -> c_int;
	pub fn cmdline_poll(cl: *mut cmdline) -> c_int;
	pub fn cmdline_interact(cl: *mut cmdline);
	pub fn cmdline_quit(cl: *mut cmdline);
	pub fn cmdline_parse_etheraddr(tk: *mut cmdline_parse_token_hdr_t, srcbuf: *const c_char, res: *mut c_void, ressize: c_uint) -> c_int;
	pub fn cmdline_get_help_etheraddr(tk: *mut cmdline_parse_token_hdr_t, dstbuf: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_parse_ipaddr(tk: *mut cmdline_parse_token_hdr_t, srcbuf: *const c_char, res: *mut c_void, ressize: c_uint) -> c_int;
	pub fn cmdline_get_help_ipaddr(tk: *mut cmdline_parse_token_hdr_t, dstbuf: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_parse_num(tk: *mut cmdline_parse_token_hdr_t, srcbuf: *const c_char, res: *mut c_void, ressize: c_uint) -> c_int;
	pub fn cmdline_get_help_num(tk: *mut cmdline_parse_token_hdr_t, dstbuf: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_parse_portlist(tk: *mut cmdline_parse_token_hdr_t, srcbuf: *const c_char, res: *mut c_void, ressize: c_uint) -> c_int;
	pub fn cmdline_get_help_portlist(tk: *mut cmdline_parse_token_hdr_t, dstbuf: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_parse_string(tk: *mut cmdline_parse_token_hdr_t, srcbuf: *const c_char, res: *mut c_void, ressize: c_uint) -> c_int;
	pub fn cmdline_complete_get_nb_string(tk: *mut cmdline_parse_token_hdr_t) -> c_int;
	pub fn cmdline_complete_get_elt_string(tk: *mut cmdline_parse_token_hdr_t, idx: c_int, dstbuf: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_get_help_string(tk: *mut cmdline_parse_token_hdr_t, dstbuf: *mut c_char, size: c_uint) -> c_int;
	pub fn cmdline_file_new(ctx: *mut cmdline_parse_ctx_t, prompt: *const c_char, path: *const c_char) -> *mut cmdline;
	pub fn cmdline_stdin_new(ctx: *mut cmdline_parse_ctx_t, prompt: *const c_char) -> *mut cmdline;
	pub fn cmdline_stdin_exit(cl: *mut cmdline);
	pub fn rte_eal_alarm_set(us: uint64_t, cb: rte_eal_alarm_callback, cb_arg: *mut c_void) -> c_int;
	pub fn rte_eal_alarm_cancel(cb_fn: rte_eal_alarm_callback, cb_arg: *mut c_void) -> c_int;
	pub fn rte_approx(alpha: f64, d: f64, p: *mut uint32_t, q: *mut uint32_t) -> c_int;
	pub fn rte_exit(exit_code: c_int, format: *const c_char, ...);
	pub fn rte_eal_get_configuration() -> *mut rte_config;
	pub fn rte_eal_lcore_role(lcore_id: c_uint) -> rte_lcore_role_t;
	pub fn rte_eal_process_type() -> rte_proc_type_t;
	pub fn rte_eal_iopl_init() -> c_int;
	pub fn rte_eal_init(argc: c_int, argv: *mut *mut c_char) -> c_int;
	pub fn rte_eal_primary_proc_alive(config_file_path: *const c_char) -> c_int;
	pub fn rte_set_application_usage_hook(usage_func: rte_usage_hook_t) -> rte_usage_hook_t;
	pub fn rte_eal_has_hugepages() -> c_int;
	pub fn rte_sys_gettid() -> c_int;
	pub fn rte_eal_remote_launch(f: lcore_function_t, arg: *mut c_void, slave_id: c_uint) -> c_int;
	pub fn rte_eal_mp_remote_launch(f: lcore_function_t, arg: *mut c_void, call_master: rte_rmt_call_master_t) -> c_int;
	pub fn rte_eal_get_lcore_state(slave_id: c_uint) -> rte_lcore_state_t;
	pub fn rte_eal_wait_lcore(slave_id: c_uint) -> c_int;
	pub fn rte_eal_mp_wait_lcore();
	pub fn rte_socket_id() -> c_uint;
	pub fn rte_thread_set_affinity(cpusetp: *mut rte_cpuset_t) -> c_int;
	pub fn rte_thread_get_affinity(cpusetp: *mut rte_cpuset_t);
	pub fn rte_thread_setname(id: pthread_t, name: *const c_char) -> c_int;
	pub fn rte_cpu_get_flag_name(feature: rte_cpu_flag_t) -> *const c_char;
	pub fn rte_cpu_get_flag_enabled(feature: rte_cpu_flag_t) -> c_int;
	pub fn rte_cpu_check_supported();
	pub fn rte_openlog_stream(f: *mut FILE) -> c_int;
	pub fn rte_set_log_level(level: uint32_t);
	pub fn rte_get_log_level() -> uint32_t;
	pub fn rte_set_log_type(type_: uint32_t, enable: c_int);
	pub fn rte_get_log_type() -> uint32_t;
	pub fn rte_log_cur_msg_loglevel() -> c_int;
	pub fn rte_log_cur_msg_logtype() -> c_int;
	pub fn rte_log(level: uint32_t, logtype: uint32_t, format: *const c_char, ...) -> c_int;
	pub fn rte_vlog(level: uint32_t, logtype: uint32_t, format: *const c_char, ap: va_list) -> c_int;
	pub fn rte_dump_stack();
	pub fn rte_dump_registers();
	pub fn __rte_panic(funcname: *const c_char, format: *const c_char, ...);
	pub fn rte_mem_lock_page(virt: *const c_void) -> c_int;
	pub fn rte_mem_virt2phy(virt: *const c_void) -> phys_addr_t;
	pub fn rte_eal_get_physmem_layout() -> *const rte_memseg;
	pub fn rte_dump_physmem_layout(f: *mut FILE);
	pub fn rte_eal_get_physmem_size() -> uint64_t;
	pub fn rte_memory_get_nchannel() -> c_uint;
	pub fn rte_memory_get_nrank() -> c_uint;
	pub fn rte_memzone_reserve(name: *const c_char, len: size_t, socket_id: c_int, flags: c_uint) -> *const rte_memzone;
	pub fn rte_memzone_reserve_aligned(name: *const c_char, len: size_t, socket_id: c_int, flags: c_uint, align: c_uint) -> *const rte_memzone;
	pub fn rte_memzone_reserve_bounded(name: *const c_char, len: size_t, socket_id: c_int, flags: c_uint, align: c_uint, bound: c_uint) -> *const rte_memzone;
	pub fn rte_memzone_free(mz: *const rte_memzone) -> c_int;
	pub fn rte_memzone_lookup(name: *const c_char) -> *const rte_memzone;
	pub fn rte_memzone_dump(f: *mut FILE);
	pub fn rte_memzone_walk(func: Option<unsafe extern "C" fn(arg1: *const rte_memzone, arg: *mut c_void)>, arg: *mut c_void);
	pub fn rte_ring_get_memsize(count: c_uint) -> ssize_t;
	pub fn rte_ring_init(r: *mut rte_ring, name: *const c_char, count: c_uint, flags: c_uint) -> c_int;
	pub fn rte_ring_create(name: *const c_char, count: c_uint, socket_id: c_int, flags: c_uint) -> *mut rte_ring;
	pub fn rte_ring_free(r: *mut rte_ring);
	pub fn rte_ring_set_water_mark(r: *mut rte_ring, count: c_uint) -> c_int;
	pub fn rte_ring_dump(f: *mut FILE, r: *const rte_ring);
	pub fn rte_ring_list_dump(f: *mut FILE);
	pub fn rte_ring_lookup(name: *const c_char) -> *mut rte_ring;
	pub fn rte_mempool_check_cookies(mp: *const rte_mempool, obj_table_const: *const *mut c_void, n: c_uint, free: c_int);
	pub fn rte_mempool_ops_alloc(mp: *mut rte_mempool) -> c_int;
	pub fn rte_mempool_ops_get_count(mp: *const rte_mempool) -> c_uint;
	pub fn rte_mempool_ops_free(mp: *mut rte_mempool);
	pub fn rte_mempool_set_ops_byname(mp: *mut rte_mempool, name: *const c_char, pool_config: *mut c_void) -> c_int;
	pub fn rte_mempool_register_ops(ops: *const rte_mempool_ops) -> c_int;
	pub fn rte_mempool_create(name: *const c_char, n: c_uint, elt_size: c_uint, cache_size: c_uint, private_data_size: c_uint, mp_init: rte_mempool_ctor_t, mp_init_arg: *mut c_void, obj_init: rte_mempool_obj_cb_t, obj_init_arg: *mut c_void, socket_id: c_int, flags: c_uint) -> *mut rte_mempool;
	pub fn rte_mempool_xmem_create(name: *const c_char, n: c_uint, elt_size: c_uint, cache_size: c_uint, private_data_size: c_uint, mp_init: rte_mempool_ctor_t, mp_init_arg: *mut c_void, obj_init: rte_mempool_obj_cb_t, obj_init_arg: *mut c_void, socket_id: c_int, flags: c_uint, vaddr: *mut c_void, paddr: *mut phys_addr_t, pg_num: uint32_t, pg_shift: uint32_t) -> *mut rte_mempool;
	pub fn rte_mempool_create_empty(name: *const c_char, n: c_uint, elt_size: c_uint, cache_size: c_uint, private_data_size: c_uint, socket_id: c_int, flags: c_uint) -> *mut rte_mempool;
	pub fn rte_mempool_free(mp: *mut rte_mempool);
	pub fn rte_mempool_populate_phys(mp: *mut rte_mempool, vaddr: *mut c_char, paddr: phys_addr_t, len: size_t, free_cb: rte_mempool_memchunk_free_cb_t, opaque: *mut c_void) -> c_int;
	pub fn rte_mempool_populate_phys_tab(mp: *mut rte_mempool, vaddr: *mut c_char, paddr: *mut phys_addr_t, pg_num: uint32_t, pg_shift: uint32_t, free_cb: rte_mempool_memchunk_free_cb_t, opaque: *mut c_void) -> c_int;
	pub fn rte_mempool_populate_virt(mp: *mut rte_mempool, addr: *mut c_char, len: size_t, pg_sz: size_t, free_cb: rte_mempool_memchunk_free_cb_t, opaque: *mut c_void) -> c_int;
	pub fn rte_mempool_populate_default(mp: *mut rte_mempool) -> c_int;
	pub fn rte_mempool_populate_anon(mp: *mut rte_mempool) -> c_int;
	pub fn rte_mempool_obj_iter(mp: *mut rte_mempool, obj_cb: rte_mempool_obj_cb_t, obj_cb_arg: *mut c_void) -> uint32_t;
	pub fn rte_mempool_mem_iter(mp: *mut rte_mempool, mem_cb: rte_mempool_mem_cb_t, mem_cb_arg: *mut c_void) -> uint32_t;
	pub fn rte_mempool_dump(f: *mut FILE, mp: *mut rte_mempool);
	pub fn rte_mempool_cache_create(size: uint32_t, socket_id: c_int) -> *mut rte_mempool_cache;
	pub fn rte_mempool_cache_free(cache: *mut rte_mempool_cache);
	pub fn rte_mempool_avail_count(mp: *const rte_mempool) -> c_uint;
	pub fn rte_mempool_count(mp: *const rte_mempool) -> c_uint;
	pub fn rte_mempool_in_use_count(mp: *const rte_mempool) -> c_uint;
	pub fn rte_mempool_audit(mp: *mut rte_mempool);
	pub fn rte_mempool_list_dump(f: *mut FILE);
	pub fn rte_mempool_lookup(name: *const c_char) -> *mut rte_mempool;
	pub fn rte_mempool_calc_obj_size(elt_size: uint32_t, flags: uint32_t, sz: *mut rte_mempool_objsz) -> uint32_t;
	pub fn rte_mempool_xmem_size(elt_num: uint32_t, total_elt_sz: size_t, pg_shift: uint32_t) -> size_t;
	pub fn rte_mempool_xmem_usage(vaddr: *mut c_void, elt_num: uint32_t, total_elt_sz: size_t, paddr: *mut phys_addr_t, pg_num: uint32_t, pg_shift: uint32_t) -> ssize_t;
	pub fn rte_mempool_walk(func: Option<unsafe extern "C" fn(arg1: *mut rte_mempool, arg: *mut c_void)>, arg: *mut c_void);
	pub fn rte_get_rx_ol_flag_name(mask: uint64_t) -> *const c_char;
	pub fn rte_get_tx_ol_flag_name(mask: uint64_t) -> *const c_char;
	pub fn rte_mbuf_sanity_check(m: *const rte_mbuf, is_header: c_int);
	pub fn rte_ctrlmbuf_init(mp: *mut rte_mempool, opaque_arg: *mut c_void, m: *mut c_void, i: c_uint);
	pub fn rte_pktmbuf_init(mp: *mut rte_mempool, opaque_arg: *mut c_void, m: *mut c_void, i: c_uint);
	pub fn rte_pktmbuf_pool_init(mp: *mut rte_mempool, opaque_arg: *mut c_void);
	pub fn rte_pktmbuf_pool_create(name: *const c_char, n: c_uint, cache_size: c_uint, priv_size: uint16_t, data_room_size: uint16_t, socket_id: c_int) -> *mut rte_mempool;
	pub fn rte_pktmbuf_dump(f: *mut FILE, m: *const rte_mbuf, dump_len: c_uint);
	pub fn rte_cfgfile_load(filename: *const c_char, flags: c_int) -> *mut rte_cfgfile;
	pub fn rte_cfgfile_num_sections(cfg: *mut rte_cfgfile, sec_name: *const c_char, length: size_t) -> c_int;
	pub fn rte_cfgfile_sections(cfg: *mut rte_cfgfile, sections: *mut *mut c_char, max_sections: c_int) -> c_int;
	pub fn rte_cfgfile_has_section(cfg: *mut rte_cfgfile, sectionname: *const c_char) -> c_int;
	pub fn rte_cfgfile_section_num_entries(cfg: *mut rte_cfgfile, sectionname: *const c_char) -> c_int;
	pub fn rte_cfgfile_section_entries(cfg: *mut rte_cfgfile, sectionname: *const c_char, entries: *mut rte_cfgfile_entry, max_entries: c_int) -> c_int;
	pub fn rte_cfgfile_section_entries_by_index(cfg: *mut rte_cfgfile, index: c_int, sectionname: *mut c_char, entries: *mut rte_cfgfile_entry, max_entries: c_int) -> c_int;
	pub fn rte_cfgfile_get_entry(cfg: *mut rte_cfgfile, sectionname: *const c_char, entryname: *const c_char) -> *const c_char;
	pub fn rte_cfgfile_has_entry(cfg: *mut rte_cfgfile, sectionname: *const c_char, entryname: *const c_char) -> c_int;
	pub fn rte_cfgfile_close(cfg: *mut rte_cfgfile) -> c_int;
	pub fn rte_crypto_op_pool_create(name: *const c_char, type_: rte_crypto_op_type, nb_elts: c_uint, cache_size: c_uint, priv_size: uint16_t, socket_id: c_int) -> *mut rte_mempool;
	pub fn rte_eal_driver_register(driver: *mut rte_driver);
	pub fn rte_eal_driver_unregister(driver: *mut rte_driver);
	pub fn rte_eal_dev_init() -> c_int;
	pub fn rte_eal_vdev_init(name: *const c_char, args: *const c_char) -> c_int;
	pub fn rte_eal_vdev_uninit(name: *const c_char) -> c_int;
	pub fn rte_distributor_create(name: *const c_char, socket_id: c_uint, num_workers: c_uint) -> *mut rte_distributor;
	pub fn rte_distributor_process(d: *mut rte_distributor, mbufs: *mut *mut rte_mbuf, num_mbufs: c_uint) -> c_int;
	pub fn rte_distributor_returned_pkts(d: *mut rte_distributor, mbufs: *mut *mut rte_mbuf, max_mbufs: c_uint) -> c_int;
	pub fn rte_distributor_flush(d: *mut rte_distributor) -> c_int;
	pub fn rte_distributor_clear_returns(d: *mut rte_distributor);
	pub fn rte_distributor_get_pkt(d: *mut rte_distributor, worker_id: c_uint, oldpkt: *mut rte_mbuf) -> *mut rte_mbuf;
	pub fn rte_distributor_return_pkt(d: *mut rte_distributor, worker_id: c_uint, mbuf: *mut rte_mbuf) -> c_int;
	pub fn rte_distributor_request_pkt(d: *mut rte_distributor, worker_id: c_uint, oldpkt: *mut rte_mbuf);
	pub fn rte_distributor_poll_pkt(d: *mut rte_distributor, worker_id: c_uint) -> *mut rte_mbuf;
	pub fn rte_dump_tailq(f: *mut FILE);
	pub fn rte_eal_tailq_lookup(name: *const c_char) -> *mut rte_tailq_head;
	pub fn rte_eal_tailq_register(t: *mut rte_tailq_elem) -> c_int;
	pub fn rte_strerror(errnum: c_int) -> *const c_char;
	pub fn rte_eth_bond_create(name: *const c_char, mode: uint8_t, socket_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_free(name: *const c_char) -> c_int;
	pub fn rte_eth_bond_slave_add(bonded_port_id: uint8_t, slave_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_slave_remove(bonded_port_id: uint8_t, slave_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_mode_set(bonded_port_id: uint8_t, mode: uint8_t) -> c_int;
	pub fn rte_eth_bond_mode_get(bonded_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_primary_set(bonded_port_id: uint8_t, slave_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_primary_get(bonded_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_slaves_get(bonded_port_id: uint8_t, slaves: *mut uint8_t, len: uint8_t) -> c_int;
	pub fn rte_eth_bond_active_slaves_get(bonded_port_id: uint8_t, slaves: *mut uint8_t, len: uint8_t) -> c_int;
	pub fn rte_eth_bond_mac_address_set(bonded_port_id: uint8_t, mac_addr: *mut ether_addr) -> c_int;
	pub fn rte_eth_bond_mac_address_reset(bonded_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_xmit_policy_set(bonded_port_id: uint8_t, policy: uint8_t) -> c_int;
	pub fn rte_eth_bond_xmit_policy_get(bonded_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_link_monitoring_set(bonded_port_id: uint8_t, internal_ms: uint32_t) -> c_int;
	pub fn rte_eth_bond_link_monitoring_get(bonded_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_link_down_prop_delay_set(bonded_port_id: uint8_t, delay_ms: uint32_t) -> c_int;
	pub fn rte_eth_bond_link_down_prop_delay_get(bonded_port_id: uint8_t) -> c_int;
	pub fn rte_eth_bond_link_up_prop_delay_set(bonded_port_id: uint8_t, delay_ms: uint32_t) -> c_int;
	pub fn rte_eth_bond_link_up_prop_delay_get(bonded_port_id: uint8_t) -> c_int;
	pub fn eth_dev_null_create(name: *const c_char, numa_node: c_uint, packet_size: c_uint, packet_copy: c_uint) -> c_int;
	pub fn rte_eth_from_rings(name: *const c_char, rx_queues: *mut *mut rte_ring, nb_rx_queues: c_uint, tx_queues: *mut *mut rte_ring, nb_tx_queues: c_uint, numa_node: c_uint) -> c_int;
	pub fn rte_eth_from_ring(r: *mut rte_ring) -> c_int;
	pub fn rte_vhost_feature_disable(feature_mask: uint64_t) -> c_int;
	pub fn rte_vhost_feature_enable(feature_mask: uint64_t) -> c_int;
	pub fn rte_vhost_feature_get() -> uint64_t;
	pub fn rte_vhost_enable_guest_notification(vid: c_int, queue_id: uint16_t, enable: c_int) -> c_int;
	pub fn rte_vhost_driver_register(path: *const c_char, flags: uint64_t) -> c_int;
	pub fn rte_vhost_driver_unregister(path: *const c_char) -> c_int;
	pub fn rte_vhost_driver_callback_register(arg1: *const virtio_net_device_ops) -> c_int;
	pub fn rte_vhost_driver_session_start() -> c_int;
	pub fn rte_vhost_get_numa_node(vid: c_int) -> c_int;
	pub fn rte_vhost_get_queue_num(vid: c_int) -> uint32_t;
	pub fn rte_vhost_get_ifname(vid: c_int, buf: *mut c_char, len: size_t) -> c_int;
	pub fn rte_vhost_avail_entries(vid: c_int, queue_id: uint16_t) -> uint16_t;
	pub fn rte_vhost_enqueue_burst(vid: c_int, queue_id: uint16_t, pkts: *mut *mut rte_mbuf, count: uint16_t) -> uint16_t;
	pub fn rte_vhost_dequeue_burst(vid: c_int, queue_id: uint16_t, mbuf_pool: *mut rte_mempool, pkts: *mut *mut rte_mbuf, count: uint16_t) -> uint16_t;
	pub fn rte_eth_vhost_feature_disable(feature_mask: uint64_t) -> c_int;
	pub fn rte_eth_vhost_feature_enable(feature_mask: uint64_t) -> c_int;
	pub fn rte_eth_vhost_feature_get() -> uint64_t;
	pub fn rte_eth_vhost_get_queue_event(port_id: uint8_t, event: *mut rte_eth_vhost_queue_event) -> c_int;
	pub fn rte_fbk_hash_find_existing(name: *const c_char) -> *mut rte_fbk_hash_table;
	pub fn rte_fbk_hash_create(params: *const rte_fbk_hash_params) -> *mut rte_fbk_hash_table;
	pub fn rte_fbk_hash_free(ht: *mut rte_fbk_hash_table);
	pub fn rte_hash_create(params: *const rte_hash_parameters) -> *mut rte_hash;
	pub fn rte_hash_set_cmp_func(h: *mut rte_hash, func: rte_hash_cmp_eq_t);
	pub fn rte_hash_find_existing(name: *const c_char) -> *mut rte_hash;
	pub fn rte_hash_free(h: *mut rte_hash);
	pub fn rte_hash_reset(h: *mut rte_hash);
	pub fn rte_hash_add_key_data(h: *const rte_hash, key: *const c_void, data: *mut c_void) -> c_int;
	pub fn rte_hash_add_key_with_hash_data(h: *const rte_hash, key: *const c_void, sig: hash_sig_t, data: *mut c_void) -> int32_t;
	pub fn rte_hash_add_key(h: *const rte_hash, key: *const c_void) -> int32_t;
	pub fn rte_hash_add_key_with_hash(h: *const rte_hash, key: *const c_void, sig: hash_sig_t) -> int32_t;
	pub fn rte_hash_del_key(h: *const rte_hash, key: *const c_void) -> int32_t;
	pub fn rte_hash_del_key_with_hash(h: *const rte_hash, key: *const c_void, sig: hash_sig_t) -> int32_t;
	pub fn rte_hash_get_key_with_position(h: *const rte_hash, position: int32_t, key: *mut *mut c_void) -> c_int;
	pub fn rte_hash_lookup_data(h: *const rte_hash, key: *const c_void, data: *mut *mut c_void) -> c_int;
	pub fn rte_hash_lookup_with_hash_data(h: *const rte_hash, key: *const c_void, sig: hash_sig_t, data: *mut *mut c_void) -> c_int;
	pub fn rte_hash_lookup(h: *const rte_hash, key: *const c_void) -> int32_t;
	pub fn rte_hash_lookup_with_hash(h: *const rte_hash, key: *const c_void, sig: hash_sig_t) -> int32_t;
	pub fn rte_hash_hash(h: *const rte_hash, key: *const c_void) -> hash_sig_t;
	pub fn rte_hash_lookup_bulk_data(h: *const rte_hash, keys: *mut *const c_void, num_keys: uint32_t, hit_mask: *mut uint64_t, data: *mut *mut c_void) -> c_int;
	pub fn rte_hash_lookup_bulk(h: *const rte_hash, keys: *mut *const c_void, num_keys: uint32_t, positions: *mut int32_t) -> c_int;
	pub fn rte_hash_iterate(h: *const rte_hash, key: *mut *const c_void, data: *mut *mut c_void, next: *mut uint32_t) -> int32_t;
	pub fn rte_hexdump(f: *mut FILE, title: *const c_char, buf: *const c_void, len: c_uint);
	pub fn rte_memdump(f: *mut FILE, title: *const c_char, buf: *const c_void, len: c_uint);
	pub fn rte_epoll_wait(epfd: c_int, events: *mut rte_epoll_event, maxevents: c_int, timeout: c_int) -> c_int;
	pub fn rte_epoll_ctl(epfd: c_int, op: c_int, fd: c_int, event: *mut rte_epoll_event) -> c_int;
	pub fn rte_intr_tls_epfd() -> c_int;
	pub fn rte_intr_rx_ctl(intr_handle: *mut rte_intr_handle, epfd: c_int, op: c_int, vec: c_uint, data: *mut c_void) -> c_int;
	pub fn rte_intr_efd_enable(intr_handle: *mut rte_intr_handle, nb_efd: uint32_t) -> c_int;
	pub fn rte_intr_efd_disable(intr_handle: *mut rte_intr_handle);
	pub fn rte_intr_dp_is_en(intr_handle: *mut rte_intr_handle) -> c_int;
	pub fn rte_intr_allow_others(intr_handle: *mut rte_intr_handle) -> c_int;
	pub fn rte_intr_cap_multiple(intr_handle: *mut rte_intr_handle) -> c_int;
	pub fn rte_intr_callback_register(intr_handle: *mut rte_intr_handle, cb: rte_intr_callback_fn, cb_arg: *mut c_void) -> c_int;
	pub fn rte_intr_callback_unregister(intr_handle: *mut rte_intr_handle, cb: rte_intr_callback_fn, cb_arg: *mut c_void) -> c_int;
	pub fn rte_intr_enable(intr_handle: *mut rte_intr_handle) -> c_int;
	pub fn rte_intr_disable(intr_handle: *mut rte_intr_handle) -> c_int;
	pub fn rte_malloc(type_: *const c_char, size: size_t, align: c_uint) -> *mut c_void;
	pub fn rte_zmalloc(type_: *const c_char, size: size_t, align: c_uint) -> *mut c_void;
	pub fn rte_calloc(type_: *const c_char, num: size_t, size: size_t, align: c_uint) -> *mut c_void;
	pub fn rte_realloc(ptr: *mut c_void, size: size_t, align: c_uint) -> *mut c_void;
	pub fn rte_malloc_socket(type_: *const c_char, size: size_t, align: c_uint, socket: c_int) -> *mut c_void;
	pub fn rte_zmalloc_socket(type_: *const c_char, size: size_t, align: c_uint, socket: c_int) -> *mut c_void;
	pub fn rte_calloc_socket(type_: *const c_char, num: size_t, size: size_t, align: c_uint, socket: c_int) -> *mut c_void;
	pub fn rte_free(ptr: *mut c_void);
	pub fn rte_malloc_validate(ptr: *const c_void, size: *mut size_t) -> c_int;
	pub fn rte_malloc_get_socket_stats(socket: c_int, socket_stats: *mut rte_malloc_socket_stats) -> c_int;
	pub fn rte_malloc_dump_stats(f: *mut FILE, type_: *const c_char);
	pub fn rte_malloc_set_limit(type_: *const c_char, max: size_t) -> c_int;
	pub fn rte_malloc_virt2phy(addr: *const c_void) -> phys_addr_t;
	pub fn rte_ip_frag_table_create(bucket_num: uint32_t, bucket_entries: uint32_t, max_entries: uint32_t, max_cycles: uint64_t, socket_id: c_int) -> *mut rte_ip_frag_tbl;
	pub fn rte_ipv6_fragment_packet(pkt_in: *mut rte_mbuf, pkts_out: *mut *mut rte_mbuf, nb_pkts_out: uint16_t, mtu_size: uint16_t, pool_direct: *mut rte_mempool, pool_indirect: *mut rte_mempool) -> int32_t;
	pub fn rte_ipv6_frag_reassemble_packet(tbl: *mut rte_ip_frag_tbl, dr: *mut rte_ip_frag_death_row, mb: *mut rte_mbuf, tms: uint64_t, ip_hdr: *mut ipv6_hdr, frag_hdr: *mut ipv6_extension_fragment) -> *mut rte_mbuf;
	pub fn rte_ipv4_fragment_packet(pkt_in: *mut rte_mbuf, pkts_out: *mut *mut rte_mbuf, nb_pkts_out: uint16_t, mtu_size: uint16_t, pool_direct: *mut rte_mempool, pool_indirect: *mut rte_mempool) -> int32_t;
	pub fn rte_ipv4_frag_reassemble_packet(tbl: *mut rte_ip_frag_tbl, dr: *mut rte_ip_frag_death_row, mb: *mut rte_mbuf, tms: uint64_t, ip_hdr: *mut ipv4_hdr) -> *mut rte_mbuf;
	pub fn rte_ip_frag_free_death_row(dr: *mut rte_ip_frag_death_row, prefetch: uint32_t);
	pub fn rte_ip_frag_table_statistics_dump(f: *mut FILE, tbl: *const rte_ip_frag_tbl);
	pub fn rte_jobstats_context_init(ctx: *mut rte_jobstats_context) -> c_int;
	pub fn rte_jobstats_context_start(ctx: *mut rte_jobstats_context);
	pub fn rte_jobstats_context_finish(ctx: *mut rte_jobstats_context);
	pub fn rte_jobstats_context_reset(ctx: *mut rte_jobstats_context);
	pub fn rte_jobstats_init(job: *mut rte_jobstats, name: *const c_char, min_period: uint64_t, max_period: uint64_t, initial_period: uint64_t, target: int64_t) -> c_int;
	pub fn rte_jobstats_set_target(job: *mut rte_jobstats, target: int64_t);
	pub fn rte_jobstats_start(ctx: *mut rte_jobstats_context, job: *mut rte_jobstats) -> c_int;
	pub fn rte_jobstats_abort(job: *mut rte_jobstats) -> c_int;
	pub fn rte_jobstats_finish(job: *mut rte_jobstats, job_value: int64_t) -> c_int;
	pub fn rte_jobstats_set_period(job: *mut rte_jobstats, period: uint64_t, saturate: uint8_t);
	pub fn rte_jobstats_set_min(job: *mut rte_jobstats, period: uint64_t);
	pub fn rte_jobstats_set_max(job: *mut rte_jobstats, period: uint64_t);
	pub fn rte_jobstats_set_update_period_function(job: *mut rte_jobstats, update_period_cb: rte_job_update_period_cb_t);
	pub fn rte_jobstats_reset(job: *mut rte_jobstats);
}

