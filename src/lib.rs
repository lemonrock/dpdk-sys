// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.



#![allow(non_camel_case_types)]

extern crate core;
use ::core::default::Default;
use ::core::option::Option;
use ::core::mem::zeroed;
use ::core::mem::transmute;
use ::core::clone::Clone;

use ::std::os::raw::c_char;
use ::std::os::raw::c_int;
use ::std::os::raw::c_longlong;
use ::std::os::raw::c_uint;
use ::std::os::raw::c_void;

extern crate libc;
use ::libc::size_t;
use ::libc::ssize_t;
use ::libc::uint8_t;
use ::libc::uint16_t;
use ::libc::uint32_t;
use ::libc::uint64_t;
use ::libc::int16_t;
use ::libc::int32_t;
use ::libc::int64_t;
use ::libc::FILE;
use ::libc::in_addr;
use ::libc::in6_addr;
use ::libc::termios;
use ::libc::pthread_t;
use ::libc::cpu_set_t;


#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct __m128i
{
	a: u64,
	b: u64,
}

pub type va_list = __builtin_va_list;

pub type __builtin_va_list = [__va_list_tag; 1usize];

#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct __va_list_tag
{
	pub gp_offset: c_uint,
	pub fp_offset: c_uint,
	pub overflow_arg_area: *mut c_void,
	pub reg_save_area: *mut c_void,
}

impl Default for __va_list_tag
{
    fn default() -> Self
	{
		unsafe { zeroed() }
	}
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


// Constants
include!("constants.rs");


// Statics
include!("statics.rs");


// Functions
include!("functions.rs");


// Types
include!("types.rs");


// Enums
include!("enums.rs");


// Structs
include!("structs.rs");
