// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub static mut cmdline_token_etheraddr_ops: cmdline_token_ops;
	pub static mut cmdline_token_ipaddr_ops: cmdline_token_ops;
	pub static mut cmdline_token_num_ops: cmdline_token_ops;
	pub static mut cmdline_token_portlist_ops: cmdline_token_ops;
	pub static mut cmdline_token_string_ops: cmdline_token_ops;
	pub static mut cmdline_vt100_commands: [*const c_char; 0usize];
}
