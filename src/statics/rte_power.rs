// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub static mut rte_power_freq_down: rte_power_freq_change_t;
	pub static mut rte_power_freq_max: rte_power_freq_change_t;
	pub static mut rte_power_freq_min: rte_power_freq_change_t;
	pub static mut rte_power_freq_up: rte_power_freq_change_t;
	pub static mut rte_power_freqs: rte_power_freqs_t;
	pub static mut rte_power_get_freq: rte_power_get_freq_t;
	pub static mut rte_power_set_freq: rte_power_set_freq_t;
}
