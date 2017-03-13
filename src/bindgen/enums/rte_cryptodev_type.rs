// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(u32)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub enum rte_cryptodev_type
{
	RTE_CRYPTODEV_NULL_PMD = 1,
	RTE_CRYPTODEV_AESNI_GCM_PMD = 2,
	RTE_CRYPTODEV_AESNI_MB_PMD = 3,
	RTE_CRYPTODEV_QAT_SYM_PMD = 4,
	RTE_CRYPTODEV_SNOW3G_PMD = 5,
	RTE_CRYPTODEV_KASUMI_PMD = 6,
	RTE_CRYPTODEV_ZUC_PMD = 7,
	RTE_CRYPTODEV_OPENSSL_PMD = 8,
	RTE_CRYPTODEV_ARMV8_PMD = 9,
	RTE_CRYPTODEV_SCHEDULER_PMD = 10,
}
