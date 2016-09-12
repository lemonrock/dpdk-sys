// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_ip_frag_free_death_row(dr: *mut rte_ip_frag_death_row, prefetch: uint32_t);
	pub fn rte_ip_frag_table_create(bucket_num: uint32_t, bucket_entries: uint32_t, max_entries: uint32_t, max_cycles: uint64_t, socket_id: c_int) -> *mut rte_ip_frag_tbl;
	pub fn rte_ip_frag_table_statistics_dump(f: *mut FILE, tbl: *const rte_ip_frag_tbl);
	pub fn rte_ipv4_frag_reassemble_packet(tbl: *mut rte_ip_frag_tbl, dr: *mut rte_ip_frag_death_row, mb: *mut rte_mbuf, tms: uint64_t, ip_hdr: *mut ipv4_hdr) -> *mut rte_mbuf;
	pub fn rte_ipv4_fragment_packet(pkt_in: *mut rte_mbuf, pkts_out: *mut *mut rte_mbuf, nb_pkts_out: uint16_t, mtu_size: uint16_t, pool_direct: *mut rte_mempool, pool_indirect: *mut rte_mempool) -> int32_t;
	pub fn rte_ipv6_frag_reassemble_packet(tbl: *mut rte_ip_frag_tbl, dr: *mut rte_ip_frag_death_row, mb: *mut rte_mbuf, tms: uint64_t, ip_hdr: *mut ipv6_hdr, frag_hdr: *mut ipv6_extension_fragment) -> *mut rte_mbuf;
	pub fn rte_ipv6_fragment_packet(pkt_in: *mut rte_mbuf, pkts_out: *mut *mut rte_mbuf, nb_pkts_out: uint16_t, mtu_size: uint16_t, pool_direct: *mut rte_mempool, pool_indirect: *mut rte_mempool) -> int32_t;
}
