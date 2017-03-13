// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.



use ::core::default::Default;
use ::core::option::Option;
use ::core::mem::zeroed;
use ::core::mem::transmute;
use ::core::clone::Clone;

#[allow(unused_extern_crates)] #[macro_use] extern crate c;
extern crate libc;
use ::libc::c_char;
use ::libc::c_int;
use ::libc::c_longlong;
use ::libc::c_uint;
use ::libc::c_void;
use ::libc::size_t;
use ::libc::ssize_t;
use ::libc::uint8_t;
use ::libc::uint16_t;
use ::libc::uint32_t;
use ::libc::uint64_t;
use ::libc::int16_t;
use ::libc::int32_t;
use ::libc::int64_t;
use ::libc::off_t;
use ::libc::FILE;
#[cfg(unix)] use ::libc::in_addr;
#[cfg(unix)] use ::libc::in6_addr;
#[cfg(unix)] use ::libc::termios;
#[cfg(unix)] use ::libc::pthread_t;
#[cfg(any(target_os = "android", target_os = "linux"))] use ::libc::cpu_set_t;
#[cfg(target_os = "freebsd")] use ::libc::cpuset_t;
use ::libc::timespec;


#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct __m128i
{
	a: u64,
	b: u64,
}

c!
{
	#include "rust_types.h"
	#include <rte_cycles.h>
	#include <rte_errno.h>
	#include <rte_ethdev.h>
	#include <rte_ether.h>
	#include <rte_lcore.h>
	#include <rte_mbuf.h>
	#include <rte_ring.h>
	#include <rte_time.h>
	#include <stdlib.h>
}

c!
{
	#[inline(always)]
	fn rust_rte_errno() -> c_int as "int"
	{
		return rte_errno;
	}

	#[inline(always)]
	fn rust_rte_reset_errno()
	{
		rte_errno = 0;
	}

	#[inline(always)]
	fn rust_rte_lcore_id() -> c_uint as "unsigned"
	{
		return rte_lcore_id();
	}

	#[inline(always)]
	fn rust_rte_get_master_lcore() -> c_uint as "unsigned"
	{
		return rte_get_master_lcore();
	}

	#[inline(always)]
	fn rust_rte_lcore_count() -> c_uint as "unsigned"
	{
		return rte_lcore_count();
	}

	#[inline(always)]
	fn rust_rte_lcore_index(lcore_id: c_uint as "unsigned") -> c_int as "int"
	{
		return rte_lcore_index(lcore_id);
	}

	#[inline(always)]
	fn rust_rte_get_next_lcore(i: c_uint as "unsigned", skip_master: c_int as "int", wrap: c_int as "int") -> c_uint as "unsigned"
	{
		return rte_get_next_lcore(i, skip_master, wrap);
	}
}

c!
{
	#[inline(always)]
	fn rust_packetBufferOverhead() -> size_t as "size_t"
	{
		sizeof(struct rte_mbuf) + RTE_PKTMBUF_HEADROOM;
	}
}

c!
{
	#[inline(always)]
	fn rust_rte_eth_txmode_setBitFields(txmode: *mut rte_eth_txmode as "struct rte_eth_txmode *", hw_vlan_reject_tagged: bool as "bool_", hw_vlan_reject_untagged: bool as "bool_", hw_vlan_insert_pvid: bool as "bool_")
	{
		txmode->hw_vlan_reject_tagged = hw_vlan_reject_tagged;
		txmode->hw_vlan_reject_untagged = hw_vlan_reject_untagged;
		txmode->hw_vlan_insert_pvid = hw_vlan_insert_pvid;
	}
	
	#[inline(always)]
	fn rust_rte_eth_rxmode_setBitFields(rxmode: *mut rte_eth_rxmode as "struct rte_eth_rxmode *", header_split: bool as "bool_", hw_ip_checksum: bool as "bool_", hw_vlan_filter: bool as "bool_", hw_vlan_strip: bool as "bool_", hw_vlan_extend: bool as "bool_", jumbo_frame: bool as "bool_", hw_strip_crc: bool as "bool_", enable_scatter: bool as "bool_", enable_lro: bool as "bool_")
	{
		rxmode->header_split = header_split;
		rxmode->hw_ip_checksum = hw_ip_checksum;
		rxmode->hw_vlan_filter = hw_vlan_filter;
		rxmode->hw_vlan_strip = hw_vlan_strip;
		rxmode->hw_vlan_extend = hw_vlan_extend;
		rxmode->jumbo_frame = jumbo_frame;
		rxmode->hw_strip_crc = hw_strip_crc;
		rxmode->enable_scatter = enable_scatter;
		rxmode->enable_lro = enable_lro;
	}
	
	#[inline(always)]
	fn rust_rte_eth_link_getBitField_link_duplex(link: *const rte_eth_link as "const struct rte_eth_link *") -> uint16_t as "uint16_t"
	{
		return link->link_duplex;
	}
	
	#[inline(always)]
	fn rust_rte_eth_link_getBitField_link_autoneg(link: *const rte_eth_link as "const struct rte_eth_link *") -> uint16_t as "uint16_t"
	{
		return link->link_autoneg;
	}
	
	#[inline(always)]
	fn rust_rte_eth_link_getBitField_link_status(link: *const rte_eth_link as "const struct rte_eth_link *") -> uint16_t as "uint16_t"
	{
		return link->link_status;
	}
}

c!
{
	#[inline(always)]
	fn rust_rte_eth_rx_burst(port_id: uint8_t as "uint8_t", queue_id: uint16_t as "uint16_t", rx_pkts: *mut *mut rte_mbuf as "struct rte_mbuf **", nb_pkts: uint16_t as "const uint16_t") -> uint16_t as "uint16_t"
	{
		return rte_eth_rx_burst(port_id, queue_id, rx_pkts, nb_pkts);
	}
	
	#[inline(always)]
	fn rust_rte_eth_rx_queue_count(port_id: uint8_t as "uint8_t", queue_id: uint16_t as "uint16_t") -> c_int as "int"
	{
		return rte_eth_rx_queue_count(port_id, queue_id);
	}
	
	#[inline(always)]
	fn rust_rte_eth_rx_descriptor_done(port_id: uint8_t as "uint8_t", queue_id: uint16_t as "uint16_t", offset: uint16_t as "uint16_t") -> c_int as "int"
	{
		return rte_eth_rx_descriptor_done(port_id, queue_id, offset);
	}
	
	#[inline(always)]
	fn rust_rte_eth_tx_burst(port_id: uint8_t as "uint8_t", queue_id: uint16_t as "uint16_t", tx_pkts: *mut *mut rte_mbuf as "struct rte_mbuf **", nb_pkt: uint16_t as "uint16_t") -> uint16_t as "uint16_t"
	{
		return rte_eth_tx_burst(port_id, queue_id, tx_pkts, nb_pkt);
	}
	
	#[inline(always)]
	fn rust_RTE_ETH_TX_BUFFER_SIZE(sz: uint16_t as "uint16_t") -> size_t as "size_t"
	{
		return RTE_ETH_TX_BUFFER_SIZE(sz);
	}
	
	#[inline(always)]
	fn rust_rte_eth_tx_buffer_flush(port_id: uint8_t as "uint8_t", queue_id: uint16_t as "uint16_t", buffer: *mut rte_eth_dev_tx_buffer as "struct rte_eth_dev_tx_buffer *") -> uint16_t as "uint16_t"
	{
		return rte_eth_tx_buffer_flush(port_id, queue_id, buffer);
	}
	
	#[inline(always)]
	fn rust_rte_eth_tx_buffer(port_id: uint8_t as "uint8_t", queue_id: uint16_t as "uint16_t", buffer: *mut rte_eth_dev_tx_buffer as "struct rte_eth_dev_tx_buffer *", tx_pkt: *mut rte_mbuf as "struct rte_mbuf *") -> uint16_t as "uint16_t"
	{
		return rte_eth_tx_buffer(port_id, queue_id, buffer, tx_pkt);
	}

	#[inline(always)]
	fn rust_is_zero_ether_addr(ea: *const ether_addr as "const struct ether_addr *") -> c_int as "int"
	{
		return is_zero_ether_addr(ea);
	}

	#[inline(always)]
	fn rust_is_unicast_ether_addr(ea: *const ether_addr as "const struct ether_addr *") -> c_int as "int"
	{
		return is_unicast_ether_addr(ea);
	}

	#[inline(always)]
	fn rust_is_multicast_ether_addr(ea: *const ether_addr as "const struct ether_addr *") -> c_int as "int"
	{
		return is_multicast_ether_addr(ea);
	}

	#[inline(always)]
	fn rust_is_broadcast_ether_addr(ea: *const ether_addr as "const struct ether_addr *") -> c_int as "int"
	{
		return is_broadcast_ether_addr(ea);
	}

	#[inline(always)]
	fn rust_is_universal_ether_addr(ea: *const ether_addr as "const struct ether_addr *") -> c_int as "int"
	{
		return is_universal_ether_addr(ea);
	}

	#[inline(always)]
	fn rust_is_local_admin_ether_addr(ea: *const ether_addr as "const struct ether_addr *") -> c_int as "int"
	{
		return is_local_admin_ether_addr(ea);
	}

	#[inline(always)]
	fn rust_is_valid_assigned_ether_addr(ea: *const ether_addr as "const struct ether_addr *") -> c_int as "int"
	{
		return is_valid_assigned_ether_addr(ea);
	}
	
	#[inline(always)]
	fn rust_eth_random_addr(addr: *mut uint8_t as "uint8_t *")
	{
		eth_random_addr(addr);
	}

	#[inline(always)]
	fn rust_rte_pktmbuf_data_room_size(mp: *mut rte_mempool as "struct rte_mempool *") -> uint16_t as "uint16_t"
	{
		return rte_pktmbuf_data_room_size(mp);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_alloc(mp: *mut rte_mempool as "struct rte_mempool *") -> *mut rte_mbuf as "struct rte_mbuf *"
	{
		return rte_pktmbuf_alloc(mp);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_alloc_bulk(pool: *mut rte_mempool as "struct rte_mempool *", mbufs: *mut *mut rte_mbuf as "struct rte_mbuf **", count: u32 as "unsigned") -> c_int as "int"
	{
		return rte_pktmbuf_alloc_bulk(pool, mbufs, count);
	}
		
	#[inline(always)]
	fn rust_rte_pktmbuf_clone(md: *mut rte_mbuf as "struct rte_mbuf *", mp: *mut rte_mempool as "struct rte_mempool *") -> *mut rte_mbuf as "struct rte_mbuf *"
	{
		return rte_pktmbuf_clone(md, mp);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_reset(m: *mut rte_mbuf as "struct rte_mbuf *")
	{
		rte_pktmbuf_reset(m);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_attach(mi: *mut rte_mbuf as "struct rte_mbuf *", m: *mut rte_mbuf as "struct rte_mbuf *")
	{
		rte_pktmbuf_attach(mi, m);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_detach(m: *mut rte_mbuf as "struct rte_mbuf *")
	{
		rte_pktmbuf_detach(m);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_free_seg(m: *mut rte_mbuf as "struct rte_mbuf *")
	{
		rte_pktmbuf_free_seg(m);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_free(m: *mut rte_mbuf as "struct rte_mbuf *")
	{
		rte_pktmbuf_free(m);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_refcnt_update(m: *mut rte_mbuf as "struct rte_mbuf *", v: int16_t as "int16_t")
	{
		rte_pktmbuf_refcnt_update(m, v);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_headroom(m: *const rte_mbuf as "const struct rte_mbuf *") -> uint16_t as "uint16_t"
	{
		return rte_pktmbuf_headroom(m);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_tailroom(m: *const rte_mbuf as "const struct rte_mbuf *") -> uint16_t as "uint16_t"
	{
		return rte_pktmbuf_tailroom(m);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_lastseg(m: *mut rte_mbuf as "struct rte_mbuf *") -> *mut rte_mbuf as "struct rte_mbuf *"
	{
		return rte_pktmbuf_lastseg(m);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_prepend(m: *const rte_mbuf as "struct rte_mbuf *", len: uint16_t as "uint16_t") -> *mut c_char as "char *"
	{
		return rte_pktmbuf_prepend(m, len);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_append(m: *const rte_mbuf as "struct rte_mbuf *", len: uint16_t as "uint16_t") -> *mut c_char as "char *"
	{
		return rte_pktmbuf_append(m, len);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_adj(m: *const rte_mbuf as "struct rte_mbuf *", len: uint16_t as "uint16_t") -> *mut c_char as "char *"
	{
		return rte_pktmbuf_adj(m, len);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_trim(m: *const rte_mbuf as "struct rte_mbuf *", len: uint16_t as "uint16_t") -> c_int as "int"
	{
		return rte_pktmbuf_trim(m, len);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_is_contiguous(m: *const rte_mbuf as "const struct rte_mbuf *") -> c_int as "int"
	{
		return rte_pktmbuf_is_contiguous(m);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_chain(head: *mut rte_mbuf as "struct rte_mbuf *", tail: *mut rte_mbuf as "struct rte_mbuf *") -> c_int as "int"
	{
		return rte_pktmbuf_chain(head, tail);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_mtophys_mtod_offset(m: *mut rte_mbuf as "struct rte_mbuf *", o: size_t as "size_t") -> *mut c_void as "void *"
	{
		return m->buf_addr + m->data_off + o;
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_mtophys_mtod(m: *mut rte_mbuf as "struct rte_mbuf *") -> *mut c_void as "void *"
	{
		return m->buf_addr + m->data_off;
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_mtophys_offset(m: *mut rte_mbuf as "struct rte_mbuf *", o: size_t as "size_t") -> phys_addr_t as "phys_addr_t"
	{
		return rte_pktmbuf_mtophys_offset(m, o);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_mtophys(m: *mut rte_mbuf as "struct rte_mbuf *") -> phys_addr_t as "phys_addr_t"
	{
		return rte_pktmbuf_mtophys(m);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_pkt_len(m: *mut rte_mbuf as "struct rte_mbuf *") -> uint32_t as "uint32_t"
	{
		return rte_pktmbuf_pkt_len(m);
	}
	
	#[inline(always)]
	fn rust_rte_pktmbuf_data_len(m: *mut rte_mbuf as "struct rte_mbuf *") -> uint16_t as "uint16_t"
	{
		return rte_pktmbuf_data_len(m);
	}
	
	#[inline(always)]
	fn rust_rte_timespec_to_ns(ts: *const timespec as "const struct timespec *") -> uint64_t as "uint64_t"
	{
		return rte_timespec_to_ns(ts);
	}
	
	#[inline(always)]
	fn rust_rte_ns_to_timespec(nsec: uint64_t as "uint64_t") -> timespec as "struct timespec"
	{
		return rte_ns_to_timespec(nsec);
	}
	
	#[inline(always)]
	fn rust_rte_rdtsc() -> uint64_t as "uint64_t"
	{
		return rte_rdtsc();
	}
	
	#[inline(always)]
	fn rust_rte_rdtsc_precise() -> uint64_t as "uint64_t"
	{
		return rte_rdtsc_precise();
	}
	
	#[inline(always)]
	fn rust_rte_get_tsc_cycles() -> uint64_t as "uint64_t"
	{
		return rte_get_tsc_cycles();
	}
	
	#[inline(always)]
	fn rust_rte_get_timer_cycles() -> uint64_t as "uint64_t"
	{
		return rte_get_timer_cycles();
	}
		
	#[inline(always)]
	fn rust_rte_get_timer_hz() -> uint64_t as "uint64_t"
	{
		return rte_get_timer_hz();
	}
	
	#[inline(always)]
	fn rust_rte_delay_ms(ms: c_uint as "unsigned")
	{
		rte_delay_ms(ms);
	}
}

c!
{
	#[inline(always)]
	fn rust_rte_ring_full(r: *const rte_ring as "const struct rte_ring *") -> c_int as "int"
	{
		return rte_ring_full(r);
	}

	#[inline(always)]
	fn rust_rte_ring_empty(r: *const rte_ring as "const struct rte_ring *") -> c_int as "int"
	{
		return rte_ring_empty(r);
	}

	#[inline(always)]
	fn rust_rte_ring_count(r: *const rte_ring as "const struct rte_ring *") -> c_uint as "unsigned"
	{
		return rte_ring_count(r);
	}

	#[inline(always)]
	fn rust_rte_ring_free_count(r: *const rte_ring as "const struct rte_ring *") -> c_uint as "unsigned"
	{
		return rte_ring_free_count(r);
	}
	
	#[inline(always)]
	fn rust_rte_ring_mp_enqueue(r: *mut rte_ring as "struct rte_ring *", obj: *mut c_void as "void *") -> c_int as "int"
	{
		return rte_ring_mp_enqueue(r, obj);
	}
		  
	#[inline(always)]
	fn rust_rte_ring_sp_enqueue(r: *mut rte_ring as "struct rte_ring *", obj: *mut c_void as "void *") -> c_int as "int"
	{
		return rte_ring_sp_enqueue(r, obj);
	}
	
	#[inline(always)]
	fn rust_rte_ring_enqueue(r: *mut rte_ring as "struct rte_ring *", obj: *mut c_void as "void *") -> c_int as "int"
	{
		return rte_ring_enqueue(r, obj);
	}
}

c!
{
	#[inline(always)]
	fn rust_rte_ring_mp_enqueue_bulk(r: *mut rte_ring as "struct rte_ring *", obj_table: *mut *const c_void as "void * const *", n: c_uint as "unsigned") -> c_int as "int"
	{
		return rte_ring_mp_enqueue_bulk(r, obj_table, n);
	}
	
	#[inline(always)]
	fn rust_rte_ring_sp_enqueue_bulk(r: *mut rte_ring as "struct rte_ring *", obj_table: *mut *const c_void as "void * const *", n: c_uint as "unsigned") -> c_int as "int"
	{
		return rte_ring_sp_enqueue_bulk(r, obj_table, n);
	}
	
	#[inline(always)]
	fn rust_rte_ring_enqueue_bulk(r: *mut rte_ring as "struct rte_ring *", obj_table: *mut *const c_void as "void * const *", n: c_uint as "unsigned") -> c_int as "int"
	{
		return rte_ring_enqueue_bulk(r, obj_table, n);
	}
	
	#[inline(always)]
	fn rust_rte_ring_mp_enqueue_burst(r: *mut rte_ring as "struct rte_ring *", obj_table: *mut *const c_void as "void * const *", n: c_uint as "unsigned") -> c_uint as "unsigned"
	{
		return rte_ring_mp_enqueue_burst(r, obj_table, n);
	}
	
	#[inline(always)]
	fn rust_rte_ring_sp_enqueue_burst(r: *mut rte_ring as "struct rte_ring *", obj_table: *mut *const c_void as "void * const *", n: c_uint as "unsigned") -> c_uint as "unsigned"
	{
		return rte_ring_sp_enqueue_burst(r, obj_table, n);
	}
	
	#[inline(always)]
	fn rust_rte_ring_enqueue_burst(r: *mut rte_ring as "struct rte_ring *", obj_table: *mut *const c_void as "void * const *", n: c_uint as "unsigned") -> c_uint as "unsigned"
	{
		return rte_ring_enqueue_burst(r, obj_table, n);
	}
	
	#[inline(always)]
	fn rust_rte_ring_mc_dequeue(r: *mut rte_ring as "struct rte_ring *", obj_p: *mut *mut c_void as "void * *") -> c_int as "int"
	{
		return rte_ring_mc_dequeue(r, obj_p);
	}

	#[inline(always)]
	fn rust_rte_ring_sc_dequeue(r: *mut rte_ring as "struct rte_ring *", obj_p: *mut *mut c_void as "void * *") -> c_int as "int"
	{
		return rte_ring_sc_dequeue(r, obj_p);
	}
	
	#[inline(always)]
	fn rust_rte_ring_dequeue(r: *mut rte_ring as "struct rte_ring *", obj_p: *mut *mut c_void as "void * *") -> c_int as "int"
	{
		return rte_ring_dequeue(r, obj_p);
	}
	
	#[inline(always)]
	fn rust_rte_ring_mc_dequeue_bulk(r: *mut rte_ring as "struct rte_ring *", obj_table: *mut *mut c_void as "void * *", n: c_uint as "unsigned") -> c_int as "int"
	{
		return rte_ring_mc_dequeue_bulk(r, obj_table, n);
	}

	#[inline(always)]
	fn rust_rte_ring_sc_dequeue_bulk(r: *mut rte_ring as "struct rte_ring *", obj_table: *mut *mut c_void as "void * *", n: c_uint as "unsigned") -> c_int as "int"
	{
		return rte_ring_sc_dequeue_bulk(r, obj_table, n);
	}
	
	#[inline(always)]
	fn rust_rte_ring_dequeue_bulk(r: *mut rte_ring as "struct rte_ring *", obj_table: *mut *mut c_void as "void * *", n: c_uint as "unsigned") -> c_int as "int"
	{
		return rte_ring_dequeue_bulk(r, obj_table, n);
	}

	#[inline(always)]
	fn rust_rte_ring_mc_dequeue_burst(r: *mut rte_ring as "struct rte_ring *", obj_table: *mut *mut c_void as "void * *", n: c_uint as "unsigned") -> c_uint as "unsigned"
	{
		return rte_ring_mc_dequeue_burst(r, obj_table, n);
	}

	#[inline(always)]
	fn rust_rte_ring_sc_dequeue_burst(r: *mut rte_ring as "struct rte_ring *", obj_table: *mut *mut c_void as "void * *", n: c_uint as "unsigned") -> c_uint as "unsigned"
	{
		return rte_ring_sc_dequeue_burst(r, obj_table, n);
	}
	
	#[inline(always)]
	fn rust_rte_ring_dequeue_burst(r: *mut rte_ring as "struct rte_ring *", obj_table: *mut *mut c_void as "void * *", n: c_uint as "unsigned") -> c_uint as "unsigned"
	{
		return rte_ring_dequeue_burst(r, obj_table, n);
	}
}

#[link(name = "ethdev")]
#[link(name = "rte_acl")]
#[link(name = "rte_cfgfile")]
#[link(name = "rte_cmdline")]
#[link(name = "rte_cryptodev")]
#[link(name = "rte_distributor")]
#[link(name = "rte_eal")]
#[link(name = "rte_hash")]
#[link(name = "rte_ip_frag")]
#[link(name = "rte_jobstats")]
#[link(name = "rte_kni")]
#[link(name = "rte_kvargs")]
#[link(name = "rte_lpm")]
#[link(name = "rte_mbuf")]
#[link(name = "rte_mempool")]
#[link(name = "rte_meter")]
#[link(name = "rte_pdump")]
#[link(name = "rte_pipeline")]
#[link(name = "rte_pmd_af_packet")]
#[link(name = "rte_pmd_bnxt")]
#[link(name = "rte_pmd_bond")]
#[link(name = "rte_pmd_cxgbe")]
#[link(name = "rte_pmd_e1000")]
#[link(name = "rte_pmd_ena")]
#[link(name = "rte_pmd_enic")]
#[link(name = "rte_pmd_fm10k")]
#[link(name = "rte_pmd_i40e")]
#[link(name = "rte_pmd_ixgbe")]
#[link(name = "rte_pmd_null")]
#[link(name = "rte_pmd_null_crypto")]
#[link(name = "rte_pmd_ring")]
#[link(name = "rte_pmd_vhost")]
#[link(name = "rte_pmd_virtio")]
#[link(name = "rte_pmd_vmxnet3_uio")]
#[link(name = "rte_port")]
#[link(name = "rte_power")]
#[link(name = "rte_reorder")]
#[link(name = "rte_ring")]
#[link(name = "rte_sched")]
#[link(name = "rte_table")]
#[link(name = "rte_timer")]
#[link(name = "rte_vhost")]
extern "C"
{
}

include!("bindgen/constants.rs");
include!("bindgen/types.rs");
include!("bindgen/enums.rs");
include!("bindgen/structs.rs");
include!("bindgen/statics.rs");
include!("bindgen/functions.rs");