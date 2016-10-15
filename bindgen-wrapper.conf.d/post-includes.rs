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
#[cfg(unix)] use ::libc::in_addr;
#[cfg(unix)] use ::libc::in6_addr;
#[cfg(unix)] use ::libc::termios;
#[cfg(unix)] use ::libc::pthread_t;
#[cfg(any(target_os = "android", target_os = "linux"))] use ::libc::cpu_set_t;
#[cfg(target_os = "freebsd")] use ::libc::cpuset_t;
use ::libc::timespec;


#[repr(C, packed)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct __m128i
{
	a: u64,
	b: u64,
}
