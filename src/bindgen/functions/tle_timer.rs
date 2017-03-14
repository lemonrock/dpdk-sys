// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn tle_timer_create(prm: *mut tle_timer_wheel_args, now: uint64_t) -> *mut tle_timer_wheel;
	pub fn tle_timer_expire(tw: *mut tle_timer_wheel, now: uint64_t);
	pub fn tle_timer_free(tw: *mut tle_timer_wheel);
	pub fn tle_timer_get_expired_bulk(tw: *mut tle_timer_wheel, timers: *mut *mut c_void, num: uint32_t) -> c_int;
	pub fn tle_timer_start(tw: *mut tle_timer_wheel, obj: *mut c_void, interval: uint64_t) -> *mut c_void;
	pub fn tle_timer_stop(tw: *mut tle_timer_wheel, timer: *mut c_void);
}
