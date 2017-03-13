// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_delay_us(us: c_uint);
	pub fn rte_eal_alarm_cancel(cb_fn: rte_eal_alarm_callback, cb_arg: *mut c_void) -> c_int;
	pub fn rte_eal_alarm_set(us: uint64_t, cb: rte_eal_alarm_callback, cb_arg: *mut c_void) -> c_int;
	pub fn rte_get_tsc_hz() -> uint64_t;
	pub fn rte_timer_dump_stats(f: *mut FILE);
	pub fn rte_timer_init(tim: *mut rte_timer);
	pub fn rte_timer_manage();
	pub fn rte_timer_pending(tim: *mut rte_timer) -> c_int;
	pub fn rte_timer_reset(tim: *mut rte_timer, ticks: uint64_t, type_: rte_timer_type, tim_lcore: c_uint, fct: rte_timer_cb_t, arg: *mut c_void) -> c_int;
	pub fn rte_timer_reset_sync(tim: *mut rte_timer, ticks: uint64_t, type_: rte_timer_type, tim_lcore: c_uint, fct: rte_timer_cb_t, arg: *mut c_void);
	pub fn rte_timer_stop(tim: *mut rte_timer) -> c_int;
	pub fn rte_timer_stop_sync(tim: *mut rte_timer);
	pub fn rte_timer_subsystem_init();
}
