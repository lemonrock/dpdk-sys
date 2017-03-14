// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn tle_tcp_process(ctx: *mut tle_ctx, num: uint32_t) -> c_int;
	pub fn tle_tcp_rx_bulk(dev: *mut tle_dev, pkt: *mut *mut rte_mbuf, rp: *mut *mut rte_mbuf, rc: *mut int32_t, num: uint16_t) -> uint16_t;
	pub fn tle_tcp_stream_accept(s: *mut tle_stream, rs: *mut *mut tle_stream, num: uint32_t) -> uint16_t;
	pub fn tle_tcp_stream_close(s: *mut tle_stream) -> c_int;
	pub fn tle_tcp_stream_close_bulk(ts: *mut *mut tle_stream, num: uint32_t) -> uint32_t;
	pub fn tle_tcp_stream_connect(s: *mut tle_stream, addr: *const sockaddr) -> c_int;
	pub fn tle_tcp_stream_get_addr(s: *const tle_stream, addr: *mut tle_tcp_stream_addr) -> c_int;
	pub fn tle_tcp_stream_listen(s: *mut tle_stream) -> c_int;
	pub fn tle_tcp_stream_open(ctx: *mut tle_ctx, prm: *const tle_tcp_stream_param) -> *mut tle_stream;
	pub fn tle_tcp_stream_recv(s: *mut tle_stream, pkt: *mut *mut rte_mbuf, num: uint16_t) -> uint16_t;
	pub fn tle_tcp_stream_send(s: *mut tle_stream, pkt: *mut *mut rte_mbuf, num: uint16_t) -> uint16_t;
	pub fn tle_tcp_stream_update_cfg(ts: *mut *mut tle_stream, prm: *mut tle_tcp_stream_cfg, num: uint32_t) -> uint32_t;
	pub fn tle_tcp_tx_bulk(dev: *mut tle_dev, pkt: *mut *mut rte_mbuf, num: uint16_t) -> uint16_t;
}
