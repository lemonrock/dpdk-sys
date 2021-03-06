// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_sys_gettid() -> c_int;
	pub fn rte_thread_get_affinity(cpusetp: *mut rte_cpuset_t);
	pub fn rte_thread_set_affinity(cpusetp: *mut rte_cpuset_t) -> c_int;
	pub fn rte_thread_setname(id: pthread_t, name: *const c_char) -> c_int;
}
