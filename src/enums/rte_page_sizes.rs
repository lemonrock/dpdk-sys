// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[derive(Copy, Clone)]
#[repr(u64)]
#[derive(Debug)]
pub enum rte_page_sizes
{
	RTE_PGSIZE_4K = 4096,
	RTE_PGSIZE_64K = 65536,
	RTE_PGSIZE_256K = 262144,
	RTE_PGSIZE_2M = 2097152,
	RTE_PGSIZE_16M = 16777216,
	RTE_PGSIZE_256M = 268435456,
	RTE_PGSIZE_512M = 536870912,
	RTE_PGSIZE_1G = 1073741824,
	RTE_PGSIZE_4G = 4294967296,
	RTE_PGSIZE_16G = 17179869184,
}
