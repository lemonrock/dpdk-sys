// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#![allow(non_snake_case)]
#![allow(non_upper_case_globals)]


extern crate c;


use ::std::env;
use ::std::fs::metadata;
use ::std::fs::read_dir;
use ::std::process::Command;
use ::std::path::Path;


const SupportedTarget: &'static str = "x86_64-unknown-linux-musl";

// const Libraries: [&'static str; 42] =
// [
// 	"ethdev",
// 	"rte_acl",
// 	"rte_cfgfile",
// 	"rte_cmdline",
// 	"rte_cryptodev",
// 	"rte_distributor",
// 	"rte_eal",
// 	"rte_hash",
// 	"rte_ip_frag",
// 	"rte_jobstats",
// 	"rte_kni",
// 	"rte_kvargs",
// 	"rte_lpm",
// 	"rte_mbuf",
// 	"rte_mempool",
// 	"rte_meter",
// 	"rte_pdump",
// 	"rte_pipeline",
// 	"rte_pmd_af_packet",
// 	"rte_pmd_bnxt",
// 	"rte_pmd_bond",
// 	"rte_pmd_cxgbe",
// 	"rte_pmd_e1000",
// 	"rte_pmd_ena",
// 	"rte_pmd_enic",
// 	"rte_pmd_fm10k",
// 	"rte_pmd_i40e",
// 	"rte_pmd_ixgbe",
// 	"rte_pmd_null",
// 	"rte_pmd_null_crypto",
// 	"rte_pmd_ring",
// 	"rte_pmd_vhost",
// 	"rte_pmd_virtio",
// 	"rte_pmd_vmxnet3_uio",
// 	"rte_port",
// 	"rte_power",
// 	"rte_reorder",
// 	"rte_ring",
// 	"rte_sched",
// 	"rte_table",
// 	"rte_timer",
// 	"rte_vhost",
// ];

fn main()
{
	let absoluteHomeFolderPath = env::var("CARGO_MANIFEST_DIR").unwrap();
	
	reRunIfChanged(&absoluteHomeFolderPath, "bindgen-wrapper.conf.d");
	reRunIfChanged(&absoluteHomeFolderPath, "compile-dpdk.conf.d");
	reRunIfChanged(&absoluteHomeFolderPath, "lib/dpdk");
	reRunIfChanged(&absoluteHomeFolderPath, "src/build.rs");
	reRunIfChanged(&absoluteHomeFolderPath, "src/lib.rs");
	reRunIfChanged(&absoluteHomeFolderPath, "tools/bindgen-wrapper");
	reRunIfChanged(&absoluteHomeFolderPath, "tools/compile-dpdk");
	reRunIfChanged(&absoluteHomeFolderPath, "tools/generate-bindings");
	
	let rootFolderPath = compileALocalCopyOfDpdkIfRequired(&absoluteHomeFolderPath);
	
	let includeFolderPath = format!("{}/include/dpdk", rootFolderPath);
	let libFolderPath = format!("{}/lib", rootFolderPath);
	
	// for library in Libraries.iter()
	// {
	// 	println!("cargo:rustc-link-lib=static={}", library);
	// }
	println!("cargo:rustc-link-lib=static=dpdk");
	println!("cargo:rustc-link-search=native={}", libFolderPath);
	
	// Not used by us, but useful for downstream potentially
	println!("cargo:root={}", rootFolderPath);
	println!("cargo:include={}", includeFolderPath);
	println!("cargo:libdir={}", libFolderPath);
	
	generatingRustBindingsToDpdkIfRquired(&absoluteHomeFolderPath);
	
	compileEmbeddedCCode(&includeFolderPath, &absoluteHomeFolderPath);
}

fn compileALocalCopyOfDpdkIfRequired(absoluteHomeFolderPath: &str)
{
	// Example values	
	// RTE_SDK='compile-dpdk.conf.d/temporary/destdir/usr/local/share/dpdk'
	// RTE_TARGET='x86_64-native-linuxapp-gcc'
	match env::var("RTE_SDK")
	{
		Ok(rteSdkPath) =>
		{
			if !Path::new(rteSdkPath).is_dir()
			{
				println!("cargo:warning=RTE_SDK environment variable '{}' is not a folder path", rteSdkPath);
				return;
			}
		
			match env::var("RTE_TARGET")
			{
				Err(_) => println!("cargo:warning=Please specify a value for the environment variable RTE_TARGET if RTE_SDK is specified"),
				Ok(rteTarget) =>
				{
					let path = format!("{}", rteSdkPath, rteTarget);

					if !Path::new(path).is_dir()
					{
						println!("cargo:warning=RTE_SDK ('{}') with RTE_TARGET ('{}') environment variable is not a folder path", rteSdkPath, rteTarget);
						return;
					}
				
					path
				},
			}
		},
		Err(_) =>
		{
			let target = env::var("TARGET").unwrap();
			if target != SupportedTarget
			{
				let message = format!("The target '{}' is unsupported by tools/compile-dpdk. Currently, the only supported target is '{}'; override the use of tools/compile-dpdk by setting the environment variables RTE_TARGET and RTE_SDK", target, SupportedTarget);
				println!("cargo:warning={}", message);
				return;
			}
			run(&absoluteHomeFolderPath, "compile-dpdk");
			format!("{}/compile-dpdk.conf.d/temporary/destdir/usr/local", absoluteHomeFolderPath.to_owned())
		},
	}
}

// This is extremely brittle, mostly because of bindgen being brittle
fn generatingRustBindingsToDpdkIfRquired(absoluteHomeFolderPath: &str)
{
	let generatedCodeFolderPath = format!("{}/src/bindgen", absoluteHomeFolderPath);
	if !Path::new(generatedCodeFolderPath).is_dir()
	{
		run(&absoluteHomeFolderPath, "bindgen-wrapper/bindgen-wrapper");
	}
}

fn compileEmbeddedCCode(includeFolderPath: &str, absoluteHomeFolderPath: &str)
{
	let path = format!("{}/src/lib.rs", absoluteHomeFolderPath);
	c::build(path, "dpdk_sys_c", |gcc_config|
	{
		gcc_config.flag("-Werror");
		gcc_config.define("_GNU_SOURCE", None);
		gcc_config.define("_BSD_SOURCE", None);
		gcc_config.flag(&format!("-isystem{}", includeFolderPath)); // can't use .include() as warnings then occur in system headers
		gcc_config.opt_level(3); // DPDK code only compiles with optimisation enabled; we can't inherit OPT_LEVEL from the environment
	});
}

fn run(absoluteHomeFolderPath: &str, programName: &'static str) -> String
{
	let fullPath = format!("{}/tools/{}", absoluteHomeFolderPath.to_owned(), programName.to_owned());
	panicIfProcessNotSuccesful(programName, Command::new(fullPath))
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
	panic!("Command '{}' failed with exit code '{}' (standard out was '{}'; standard error was '{}')", programName, code, standardOut.into_owned(), standardError.into_owned());
}

fn reRunIfChanged(absoluteHomeFolderPath: &str, folderAndContents: &'static str)
{
	let folderPath = format!("{}/{}", absoluteHomeFolderPath.to_owned(), folderAndContents.to_owned());
	visitFileOrFolderRecursivelyToAddToReRunIfChangedList(Path::new(&folderPath));
}

fn visitFileOrFolderRecursivelyToAddToReRunIfChangedList(folderPath: &Path)
{
	println!("cargo:rerun-if-changed={}", folderPath.to_str().expect("Could not convert a Path to use with cargo:rerun-if-changed={}"));
	
	if !isFolder(folderPath)
	{
		return;
	}
	
	if let Ok(iterator) = read_dir(folderPath)
	{
		for entry in iterator
		{
			if let Ok(entry) = entry
			{
				visitFileOrFolderRecursivelyToAddToReRunIfChangedList(&entry.path())
			}
		}
	}
	else
	{
		return;
	}
}

fn isFolder(folderPath: &Path) -> bool
{
	metadata(folderPath).map(|s| s.is_dir()).unwrap_or(false)
}
