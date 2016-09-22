// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.



#![allow(non_camel_case_types)]

#![no_std]

use ::core::default::Default;
use ::core::option::Option;
use ::core::mem::zeroed;
use ::core::mem::transmute;
use ::core::clone::Clone;

extern crate libc;
use ::libc::c_char;
use ::libc::c_int;
use ::libc::c_longlong;
use ::libc::c_uint;
use ::libc::c_void;
use ::libc::size_t;
use ::libc::ssize_t;
use ::libc::uint8_t;
use ::libc::uint16_t;
use ::libc::uint32_t;
use ::libc::uint64_t;
use ::libc::int16_t;
use ::libc::int32_t;
use ::libc::int64_t;
use ::libc::off_t;
use ::libc::FILE;
use ::libc::in_addr;
use ::libc::in6_addr;
use ::libc::termios;
use ::libc::pthread_t;
use ::libc::cpu_set_t;
use ::libc::timespec;


#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct __m128i
{
	a: u64,
	b: u64,
}

#[link(name = "dpdk")]
#[link(name = "ethdev")]
#[link(name = "rte_acl")]
#[link(name = "rte_cfgfile")]
#[link(name = "rte_cmdline")]
#[link(name = "rte_cryptodev")]
#[link(name = "rte_distributor")]
#[link(name = "rte_eal")]
#[link(name = "rte_hash")]
#[link(name = "rte_ip_frag")]
#[link(name = "rte_jobstats")]
#[link(name = "rte_kvargs")]
#[link(name = "rte_lpm")]
#[link(name = "rte_mbuf")]
#[link(name = "rte_mempool")]
#[link(name = "rte_meter")]
#[link(name = "rte_pdump")]
#[link(name = "rte_pipeline")]
#[link(name = "rte_pmd_af_packet")]
#[link(name = "rte_pmd_bond")]
#[link(name = "rte_pmd_null")]
#[link(name = "rte_pmd_null_crypto")]
#[link(name = "rte_pmd_ring")]
#[link(name = "rte_port")]
#[link(name = "rte_power")]
#[link(name = "rte_reorder")]
#[link(name = "rte_ring")]
#[link(name = "rte_sched")]
#[link(name = "rte_table")]
#[link(name = "rte_timer")]
extern "C"
{
}

include!("constants.rs");
include!("types.rs");
include!("enums.rs");
include!("structs.rs");
include!("statics.rs");
include!("functions.rs");
