// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_red_config_init(red_cfg: *mut rte_red_config, wq_log2: uint16_t, min_th: uint16_t, max_th: uint16_t, maxp_inv: uint16_t) -> c_int;
	pub fn rte_red_rt_data_init(red: *mut rte_red) -> c_int;
}
