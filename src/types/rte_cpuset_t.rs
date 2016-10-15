// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[cfg(any(target_os = "android", target_os = "linux"))] pub type rte_cpuset_t = cpu_set_t;
#[cfg(target_os = "freebsd")] pub type rte_cpuset_t = cpuset_t;
#[cfg(not(any(target_os = "android", target_os = "linux", target_os = "freebsd")))] pub type rte_cpuset_t = [u64; 16];
