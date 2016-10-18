// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#ifndef _RUST_RTE_H_
#define _RUST_RTE_H_

#include <rte_errno.h>
#include <rte_lcore.h>

#ifdef __cplusplus
extern "C" {
#endif

int rust_rte_errno(void);
void rust_rte_reset_errno(void);
rte_cpuset_t rust_rte_cpuset(void);
unsigned rust_rte_lcore_id(void);
unsigned rust_rte_get_master_lcore(void);
unsigned rust_rte_lcore_count(void);
int rust_rte_lcore_index(unsigned lcore_id);
unsigned rust_rte_get_next_lcore(unsigned i, int skip_master, int wrap);

#ifdef __cplusplus
}
#endif

#endif
