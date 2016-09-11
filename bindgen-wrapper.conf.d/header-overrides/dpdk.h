// This file is part of mbedtls-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/mbedtls-sys/master/COPYRIGHT. No part of mbedtls-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of mbedtls-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/mbedtls-sys/master/COPYRIGHT.


#define _GNU_SOURCE
#define _BSD_SOURCE
#undef __SSE2__


#include <cmdline.h>
#include <cmdline_parse_etheraddr.h>
#include <cmdline_parse_ipaddr.h>
#include <cmdline_parse_num.h>
#include <cmdline_parse_portlist.h>
#include <cmdline_parse_string.h>
#include <cmdline_socket.h>
// #include <rte_acl.h>   error: unknown type name '__m128i' (rte_vect.h)
#include <rte_alarm.h>
#include <rte_approx.h>
#include <rte_arp.h>
#include <rte_atomic.h>
//#include <rte_bitmap.h>  All static inline methods
#include <rte_byteorder.h>
#include <rte_cfgfile.h>
#include <rte_config.h>
#include <rte_cpuflags.h>
#include <rte_crypto.h>
//#include <rte_cryptodev_pmd.h>  Out of memory
#include <rte_dev.h>
#include <rte_dev_info.h>
//#include <rte_devargs.h>  Out of memory
#include <rte_distributor.h>
#include <rte_eal.h>
#include <rte_eal_memconfig.h>
#include <rte_errno.h>
#include <rte_eth_bond.h>
//#include <rte_eth_bond_8023ad.h>  Out of memory, Illegal Instruction
//#include <rte_eth_ctrl.h>  Out of memory, Illegal Instruction
#include <rte_eth_null.h>
#include <rte_eth_ring.h>
#include <rte_eth_vhost.h>
//#include <rte_ethdev.h>  Out of memory, Illegal Instruction
#include <rte_ether.h>
