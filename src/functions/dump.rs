// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn rte_dump_physmem_layout(f: *mut FILE);
	pub fn rte_dump_registers();
	pub fn rte_dump_stack();
	pub fn rte_dump_tailq(f: *mut FILE);
	pub fn rte_hexdump(f: *mut FILE, title: *const c_char, buf: *const c_void, len: c_uint);
	pub fn rte_memdump(f: *mut FILE, title: *const c_char, buf: *const c_void, len: c_uint);
}
