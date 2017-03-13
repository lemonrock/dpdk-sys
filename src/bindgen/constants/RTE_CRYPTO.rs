// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


pub const RTE_CRYPTODEV_ATTACHED: c_int = 1;
pub const RTE_CRYPTODEV_DETACHED: c_int = 0;
pub const RTE_CRYPTODEV_FF_ASYMMETRIC_CRYPTO: c_int = 2;
pub const RTE_CRYPTODEV_FF_CPU_AESNI: c_int = 64;
pub const RTE_CRYPTODEV_FF_CPU_AVX2: c_int = 32;
pub const RTE_CRYPTODEV_FF_CPU_AVX: c_int = 16;
pub const RTE_CRYPTODEV_FF_CPU_SSE: c_int = 8;
pub const RTE_CRYPTODEV_FF_HW_ACCELERATED: c_int = 128;
pub const RTE_CRYPTODEV_FF_SYMMETRIC_CRYPTO: c_int = 1;
pub const RTE_CRYPTODEV_FF_SYM_OPERATION_CHAINING: c_int = 4;
pub const RTE_CRYPTODEV_NAME_LEN: c_int = 64;
pub const RTE_CRYPTODEV_NAME_MAX_LEN: c_int = 64;
pub const RTE_CRYPTODEV_VDEV_DEFAULT_MAX_NB_QUEUE_PAIRS: c_int = 8;
pub const RTE_CRYPTODEV_VDEV_DEFAULT_MAX_NB_SESSIONS: c_int = 2048;
pub const RTE_CRYPTO_MAX_DEVS: c_int = 64;
