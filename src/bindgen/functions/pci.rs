// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub fn pci_get_sysfs_path() -> *const c_char;
	pub fn pci_map_resource(requested_addr: *mut c_void, fd: c_int, offset: off_t, size: size_t, additional_flags: c_int) -> *mut c_void;
	pub fn pci_unmap_resource(requested_addr: *mut c_void, size: size_t);
}
