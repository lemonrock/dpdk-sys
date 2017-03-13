[](This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.)
[](Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.)

# dpdk-sys

[![Clippy Linting Result](https://clippy.bashy.io/github/lemonrock/dpdk-sys/master/badge.svg?style=plastic)](https://clippy.bashy.io/github/lemonrock/dpdk-sys/master/log) [![](https://img.shields.io/badge/Code%20Style-rustfmt-brightgreen.svg?style=plastic)](https://github.com/rust-lang-nursery/rustfmt#configuring-rustfmt)

[dpdk-sys] is a rust crate which has bindings for DPDK.


## Versioning

Bindings are currently built for DPDK 16.07. To rebuild the bindings, run `tools/generate-bindings`. The bindings are checked in, even though they can be generated. Building them as part of a Cargo build.rs has proven to be too fragile, not least because of the complexity of DPDK and the need to patch it to work with musl libc and to compile on Mac OS X.


## Notes

The function `rte_vlog` is not exported as it makes uses of `va_list`; this macro maps to different code for different platforms. When using musl on Linux, it can be supported with:-

```rust
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
```

Hopefully one day code like this might end up in the `libc` crate, but it's not likely as it's very difficult to make use of `va_list` in any event.

https://stackoverflow.com/questions/38156867/how-to-direct-packets-belonging-to-a-tcp-connection-to-a-specific-lcore-in-dpdk/39708686
https://galsagie.github.io/2015/02/26/dpdk-tips-1/

## Licensing

The license for this project is MIT.

[dpdk-sys]: https://github.com/lemonrock/dpdk-sys "dpdk-sys GitHub page"
