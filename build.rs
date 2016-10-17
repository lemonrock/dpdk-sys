// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


#![allow(non_snake_case)]
#![allow(non_upper_case_globals)]


use ::std::process::Command;
use ::std::env;


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
	let target = env::var("TARGET").unwrap();
	if target != "x86_64-unknown-linux-musl"
	{
		return;
	}
	
	let absoluteHomeFolderPath = env::var("CARGO_MANIFEST_DIR").unwrap();
	let outputFolderPath = env::var("OUT_DIR").unwrap();
	
	let dpdkTempPath = format!("{}/dpdk-temp", outputFolderPath);
	
	for library in Libraries.iter()
	{
		println!("cargo:rustc-link-lib=static={}", library);
	}
	
	let rootFolderPath = format!("{}/destdir/usr/local", dpdkTempPath);
	println!("cargo:root={}", rootFolderPath);
	
	let libFolderPath = format!("{}/lib", rootFolderPath);
	println!("cargo:rustc-link-search=native={}", libFolderPath);
	println!("cargo:libdir={}", libFolderPath);
	
	let includeFolderPath = format!("{}/include", rootFolderPath);
	println!("cargo:include={}", includeFolderPath);
	
	let compile_dpdk = format!("{}/compile-dpdk", absoluteHomeFolderPath);
	Command::new(compile_dpdk).status().unwrap();
		
	let bindgen_wrapper = format!("{}/tools/bindgen-wrapper/bindgen-wrapper", absoluteHomeFolderPath);
	Command::new(bindgen_wrapper).status().unwrap();
	
	//println!("cargo:rerun-if-changed={}", doNotBuildFilePath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/configuration.sh", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/constant.mapping", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/constant.types", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/function.mapping", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/post-includes.rs", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/pre-includes.rs", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/preamble.rs", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/static.mapping", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/suppress-debug-warnings", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/suppress-debug-warnings", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/header-overrides", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/header-overrides/dpdk.h", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/musl-fixes", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/musl-fixes/io.extra.h", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/musl-fixes/queue.h", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/overrides", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/overrides/buildtools", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/overrides/buildtools/pmdinfogen", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/overrides/buildtools/pmdinfogen/elf.h", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/overrides/buildtools/pmdinfogen/endian.h", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/overrides/lib", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/overrides/lib/librte_eal", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/overrides/lib/librte_eal/linuxapp", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/overrides/lib/librte_eal/linuxapp/eal", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/overrides/lib/librte_eal/linuxapp/eal/eal_debug.c", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/overrides/lib/librte_eal/linuxapp/eal/eal_log.c", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/bindgen-wrapper.conf.d/overrides/lib/librte_eal/linuxapp/eal/eal_vfio_mp_sync.c", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/lib", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/lib/dpdk", absoluteHomeFolderPath);
	println!("cargo:rerun-if-changed={}/lib/dpdk/pkg/dpdk.spec", absoluteHomeFolderPath);
}
