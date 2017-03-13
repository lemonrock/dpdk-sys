// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_cryptodev_ops
{
	pub dev_configure: cryptodev_configure_t,
	pub dev_start: cryptodev_start_t,
	pub dev_stop: cryptodev_stop_t,
	pub dev_close: cryptodev_close_t,
	pub dev_infos_get: cryptodev_info_get_t,
	pub stats_get: cryptodev_stats_get_t,
	pub stats_reset: cryptodev_stats_reset_t,
	pub queue_pair_setup: cryptodev_queue_pair_setup_t,
	pub queue_pair_release: cryptodev_queue_pair_release_t,
	pub queue_pair_start: cryptodev_queue_pair_start_t,
	pub queue_pair_stop: cryptodev_queue_pair_stop_t,
	pub queue_pair_count: cryptodev_queue_pair_count_t,
	pub session_get_size: cryptodev_sym_get_session_private_size_t,
	pub session_initialize: cryptodev_sym_initialize_session_t,
	pub session_configure: cryptodev_sym_configure_session_t,
	pub session_clear: cryptodev_sym_free_session_t,
}

impl Default for rte_cryptodev_ops
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
