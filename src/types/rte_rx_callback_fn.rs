// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


pub type rte_rx_callback_fn = Option<unsafe extern "C" fn(port: uint8_t, queue: uint16_t, pkts: *mut *mut rte_mbuf, nb_pkts: uint16_t, max_pkts: uint16_t, user_param: *mut c_void) -> uint16_t>;
