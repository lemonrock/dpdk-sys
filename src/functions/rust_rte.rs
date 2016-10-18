// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rust_rte_cpuset() -> rte_cpuset_t;
	pub fn rust_rte_errno() -> c_int;
	pub fn rust_rte_get_master_lcore() -> c_uint;
	pub fn rust_rte_get_next_lcore(i: c_uint, skip_master: c_int, wrap: c_int) -> c_uint;
	pub fn rust_rte_lcore_count() -> c_uint;
	pub fn rust_rte_lcore_id() -> c_uint;
	pub fn rust_rte_lcore_index(lcore_id: c_uint) -> c_int;
	pub fn rust_rte_reset_errno();
}
