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
