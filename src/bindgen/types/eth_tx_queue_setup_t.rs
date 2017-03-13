// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


pub type eth_tx_queue_setup_t = Option<unsafe extern "C" fn(dev: *mut rte_eth_dev, tx_queue_id: uint16_t, nb_tx_desc: uint16_t, socket_id: c_uint, tx_conf: *const rte_eth_txconf) -> c_int>;
