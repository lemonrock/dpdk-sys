extern crate libc;
use ::libc::size_t;
use ::libc::ssize_t;
use ::libc::uint8_t;
use ::libc::uint16_t;
use ::libc::uint32_t;
use ::libc::uint64_t;
use ::libc::int8_t;
use ::libc::int16_t;
use ::libc::int32_t;
use ::libc::int64_t;
use ::libc::FILE;
use ::libc::in_addr;
use ::libc::in6_addr;
use ::libc::termios;
use ::libc::pthread_t;
use ::libc::cpu_set_t;


// pub type va_list = __builtin_va_list;
//
// pub type __builtin_va_list = [__va_list_tag; 1usize];
//
// #[repr(C)]
// #[derive(Copy, Clone)]
// #[derive(Debug)]
// pub struct __va_list_tag
// {
// 	pub gp_offset: c_uint,
// 	pub fp_offset: c_uint,
// 	pub overflow_arg_area: *mut c_void,
// 	pub reg_save_area: *mut c_void,
// }
//
// impl Default for __va_list_tag
// {
//     fn default() -> Self
// 	{
// 		unsafe { zeroed() }
// 	}
// }
