// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


pub type rte_table_op_lookup = Option<unsafe extern "C" fn(table: *mut c_void, pkts: *mut *mut rte_mbuf, pkts_mask: uint64_t, lookup_hit_mask: *mut uint64_t, entries: *mut *mut c_void) -> c_int>;
