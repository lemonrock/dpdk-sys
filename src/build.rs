// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#![allow(non_snake_case)]
#![allow(non_upper_case_globals)]


use ::std::env;
use ::std::fs::metadata;
use ::std::fs::read_dir;
use ::std::process::Command;
use ::std::path::Path;


const Libraries: [&'static str; 42] =
[
	"ethdev",
	"rte_acl",
	"rte_cfgfile",
	"rte_cmdline",
	"rte_cryptodev",
	"rte_distributor",
	"rte_eal",
	"rte_hash",
	"rte_ip_frag",
	"rte_jobstats",
	"rte_kni",
	"rte_kvargs",
	"rte_lpm",
	"rte_mbuf",
	"rte_mempool",
	"rte_meter",
	"rte_pdump",
	"rte_pipeline",
	"rte_pmd_af_packet",
	"rte_pmd_bnxt",
	"rte_pmd_bond",
	"rte_pmd_cxgbe",
	"rte_pmd_e1000",
	"rte_pmd_ena",
	"rte_pmd_enic",
	"rte_pmd_fm10k",
	"rte_pmd_i40e",
	"rte_pmd_ixgbe",
	"rte_pmd_null",
	"rte_pmd_null_crypto",
	"rte_pmd_ring",
	"rte_pmd_vhost",
	"rte_pmd_virtio",
	"rte_pmd_vmxnet3_uio",
	"rte_port",
	"rte_power",
	"rte_reorder",
	"rte_ring",
	"rte_sched",
	"rte_table",
	"rte_timer",
	"rte_vhost",
];

fn main()
{
	let outputFolderPath = env::var("OUT_DIR").unwrap();
	let absoluteHomeFolderPath = env::var("CARGO_MANIFEST_DIR").unwrap();
	let target = env::var("TARGET").unwrap();
	
	if target != "x86_64-unknown-linux-musl"
	{
		return;
	}
	
	run(&absoluteHomeFolderPath, "compile-dpdk");
	run(&absoluteHomeFolderPath, "bindgen-wrapper");
	
	for library in Libraries.iter()
	{
		println!("cargo:rustc-link-lib=static={}", library);
	}
	
	let dpdkTempPath = format!("{}/dpdk-temp", outputFolderPath);
	
	let rootFolderPath = format!("{}/destdir/usr/local", dpdkTempPath);
	println!("cargo:root={}", rootFolderPath);
	
	let libFolderPath = format!("{}/lib", rootFolderPath);
	println!("cargo:rustc-link-search=native={}", libFolderPath);
	println!("cargo:libdir={}", libFolderPath);
	
	let includeFolderPath = format!("{}/include", rootFolderPath);
	println!("cargo:include={}", includeFolderPath);
	
	reRunIfChanged(&absoluteHomeFolderPath, "src/build.rs");
	reRunIfChanged(&absoluteHomeFolderPath, "bindgen-wrapper.conf.d");
	reRunIfChanged(&absoluteHomeFolderPath, "tools/bindgen-wrapper");
	reRunIfChanged(&absoluteHomeFolderPath, "lib/dpdk");
}

fn run(absoluteHomeFolderPath: &str, programName: &'static str) -> String
{
	let fullPath = format!("{}/{}", absoluteHomeFolderPath.to_owned(), programName.to_owned());
	panicIfProcessNotSuccesful(Command::new(fullPath))
}

fn panicIfProcessNotSuccesful(mut command: Command) -> String
{
	let output = command.output().unwrap_or_else(|error|
	{
		panic!("Failed to execute command '{}'", error);
	});
		
	let code = output.status.code().unwrap_or_else(||
	{
		panic!("Failed to retrieve exit status from command - was it killed by a signal?");
	});
	
	if code == 0
	{
		let standardOut = String::from_utf8_lossy(&output.stdout);
		return standardOut.into_owned();
	}
	
	let standardError = String::from_utf8_lossy(&output.stderr);
	panic!("Command failed with exit code '{}' (standard error was '{}')", code, standardError.into_owned());
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
