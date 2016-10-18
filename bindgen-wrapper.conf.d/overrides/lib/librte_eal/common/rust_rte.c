// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#include <rust_rte.h>
#include <rte_errno.h>
#include <rte_lcore.h>

int rust_rte_errno()
{
	return rte_errno;
}

void rust_rte_reset_errno(void)
{
	rte_errno = 0;
}

rte_cpuset_t rust_rte_cpuset(void)
{
	return per_lcore__cpuset;
}

unsigned rust_rte_lcore_id(void)
{
	return rte_lcore_id();
}

unsigned rust_rte_get_master_lcore(void)
{
	return rte_get_master_lcore();
}

unsigned rust_rte_lcore_count(void)
{
	return rte_lcore_count();
}

int rust_rte_lcore_index(unsigned lcore_id)
{
	return rte_lcore_index(lcore_id);
}

unsigned rust_rte_get_next_lcore(unsigned i, int skip_master, int wrap)
{
	return rte_get_next_lcore(i, skip_master, wrap);
}
