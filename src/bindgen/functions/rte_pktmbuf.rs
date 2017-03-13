// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_pktmbuf_dump(f: *mut FILE, m: *const rte_mbuf, dump_len: c_uint);
	pub fn rte_pktmbuf_init(mp: *mut rte_mempool, opaque_arg: *mut c_void, m: *mut c_void, i: c_uint);
	pub fn rte_pktmbuf_pool_create(name: *const c_char, n: c_uint, cache_size: c_uint, priv_size: uint16_t, data_room_size: uint16_t, socket_id: c_int) -> *mut rte_mempool;
	pub fn rte_pktmbuf_pool_init(mp: *mut rte_mempool, opaque_arg: *mut c_void);
}
