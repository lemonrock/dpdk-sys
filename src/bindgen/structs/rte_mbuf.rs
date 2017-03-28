// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#[repr(C)]
#[derive(Copy, Clone, Debug, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub struct rte_mbuf
{
	pub cacheline0: MARKER,
	pub buf_addr: *mut c_void,
	pub buf_physaddr: phys_addr_t,
	pub buf_len: uint16_t,
	pub rearm_data: MARKER8,
	pub data_off: uint16_t,
	pub _bindgen_data_1_: [u16; 1usize],
	pub nb_segs: uint8_t,
	pub port: uint8_t,
	pub ol_flags: uint64_t,
	pub rx_descriptor_fields1: MARKER,
	pub _bindgen_data_2_: [u32; 1usize],
	pub pkt_len: uint32_t,
	pub data_len: uint16_t,
	pub vlan_tci: uint16_t,
	pub hash: rte_mbuf_AnonymousUnion_hash,
	pub seqn: uint32_t,
	pub vlan_tci_outer: uint16_t,
	pub cacheline1: MARKER,
	pub _bindgen_data_3_: [u64; 1usize],
	pub pool: *mut rte_mempool,
	pub next: *mut rte_mbuf,
	pub _bindgen_data_4_: [u64; 1usize],
	pub priv_size: uint16_t,
	pub timesync: uint16_t,
	_bindgen_padding_0_: [u8; 28usize],
}

impl rte_mbuf
{
	#[inline(always)]
#[allow(trivial_casts)]
	pub fn refcnt_atomic(&mut self) -> *mut rte_atomic16_t
	{
		let raw = &mut self._bindgen_data_1_ as *mut _ as *mut u8;
		raw as *mut _
	}

	#[inline(always)]
#[allow(trivial_casts)]
	pub fn refcnt(&mut self) -> *mut uint16_t
	{
		let raw = &mut self._bindgen_data_1_ as *mut _ as *mut u8;
		raw as *mut _
	}

	#[inline(always)]
#[allow(trivial_casts)]
	pub fn packet_type(&mut self) -> *mut uint32_t
	{
		let raw = &mut self._bindgen_data_2_ as *mut _ as *mut u8;
		raw as *mut _
	}

	#[inline(always)]
#[allow(trivial_casts)]
	pub fn userdata(&mut self) -> *mut *mut c_void
	{
		let raw = &mut self._bindgen_data_3_ as *mut _ as *mut u8;
		raw as *mut _
	}

	#[inline(always)]
#[allow(trivial_casts)]
	pub fn udata64(&mut self) -> *mut uint64_t
	{
		let raw = &mut self._bindgen_data_3_ as *mut _ as *mut u8;
		raw as *mut _
	}

	#[inline(always)]
#[allow(trivial_casts)]
	pub fn tx_offload(&mut self) -> *mut uint64_t
	{
		let raw = &mut self._bindgen_data_4_ as *mut _ as *mut u8;
		raw as *mut _
	}
}

impl Default for rte_mbuf
{
	#[inline(always)]
	fn default() -> Self
	{
		unsafe { zeroed() }
	}
}
