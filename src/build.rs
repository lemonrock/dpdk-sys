// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#![allow(non_snake_case)]
#![allow(non_upper_case_globals)]


extern crate c;


use ::std::env;
use ::std::process::Command;


fn main()
{
	let absoluteHomeFolderPath = env::var("CARGO_MANIFEST_DIR").unwrap();
	
	// We deliberately run as much as possible outside of cargo as it makes it far easier to debug a long, complex build which has little to do with Rust.
	// Of course, this script, being shell, won't run under Windows. But neither will DPDK. It won't even compile and bindgen won't with our essential changes.
	tool(&absoluteHomeFolderPath, "build-under-cargo");
	compileEmbeddedCCode(&absoluteHomeFolderPath);
}

fn tool(absoluteHomeFolderPath: &str, programName: &'static str)
{
	let fullPath = format!("{}/tools/{}", absoluteHomeFolderPath.to_owned(), programName.to_owned());
	print!("{}", panicIfProcessNotSuccesful(programName, Command::new(fullPath)));
}

fn panicIfProcessNotSuccesful(programName: &'static str, mut command: Command) -> String
{
	let output = command.output().unwrap_or_else(|error|
	{
		panic!("Failed to execute command '{}'", error);
	});
		
	let code = output.status.code().unwrap_or_else(||
	{
		panic!("Failed to retrieve exit status from command - was it killed by a signal?");
	});

	let standardOut = String::from_utf8_lossy(&output.stdout);
	if code == 0
	{
		return standardOut.into_owned();
	}
	
	let standardError = String::from_utf8_lossy(&output.stderr);
	panic!("Tool '{}' failed with exit code '{}' (standard out was '{}'; standard error was '{}')", programName, code, standardOut.into_owned(), standardError.into_owned());
}

fn compileEmbeddedCCode(absoluteHomeFolderPath: &str)
{
	match env::var("CROSS_COMPILE")
	{
		Ok(_) => (),
		Err(_) =>
		{
			println!("cargo:warning=Please specify CROSS_COMPILE=x86_64-linux-musl- cargo build --target=x86_64-unknown-linux-musl as the gcc crate incorrectly looks for musl-gcc");
			return;
		}
	};
	
	let includeFolderPath = format!("{}/src/include", absoluteHomeFolderPath.to_owned());
	
	let path = format!("{}/src/lib.rs", absoluteHomeFolderPath);
	c::build(path, "dpdk_sys_c", |gcc_config|
	{
		gcc_config.flag("-Werror");
		gcc_config.define("_GNU_SOURCE", None);
		gcc_config.define("_BSD_SOURCE", None);
		gcc_config.flag(&format!("-isystem{}", includeFolderPath)); // can't use .include() as warnings then occur in system headers
		gcc_config.flag("-msse4.1"); // Without this option, compilation fails on Mac OS X...
		gcc_config.opt_level(3); // DPDK code only compiles with optimisation enabled; we can't inherit OPT_LEVEL from the environment
	});
}
