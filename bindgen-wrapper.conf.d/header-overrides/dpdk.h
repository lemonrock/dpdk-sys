// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


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
#include <rte_ethdev.h>
#include <rte_ether.h>
#include <rte_fbk_hash.h>
#include <rte_hash.h>
#include <rte_hash_crc.h>
#include <rte_hexdump.h>
#include <rte_icmp.h>
#include <rte_interrupts.h>
#include <rte_ip.h>
#include <rte_ip_frag.h>
#include <rte_jhash.h>
#include <rte_jobstats.h>
#include <rte_keepalive.h>
#include <rte_kvargs.h>
#include <rte_launch.h>
#include <rte_lcore.h>
#include <rte_log.h>
#include <rte_lpm.h>
#include <rte_lpm6.h>
#include <rte_lpm_sse.h>
#include <rte_lru.h>
#include <rte_malloc.h>
#include <rte_malloc_heap.h>
#include <rte_mbuf.h>
#include <rte_memcpy.h>
#include <rte_memory.h>
#include <rte_mempool.h>
#include <rte_memzone.h>
#include <rte_meter.h>
#include <rte_pci_dev_feature_defs.h>
#include <rte_pci_dev_features.h>
#include <rte_pdump.h>
#include <rte_per_lcore.h>
#include <rte_pipeline.h>
#include <rte_port.h>
#include <rte_port_ethdev.h>
#include <rte_port_frag.h>
#include <rte_port_ras.h>
#include <rte_port_ring.h>
#include <rte_port_sched.h>
#include <rte_port_source_sink.h>
#include <rte_power.h>
#include <rte_prefetch.h>
#include <rte_random.h>
#include <rte_reciprocal.h>
#include <rte_red.h>
#include <rte_reorder.h>
#include <rte_ring.h>
#include <rte_rtm.h>
#include <rte_rwlock.h>
#include <rte_sched.h>
#include <rte_sched_common.h>
#include <rte_sctp.h>
#include <rte_spinlock.h>
#include <rte_string_fns.h>
#include <rte_table.h>
#include <rte_table_acl.h>
#include <rte_table_array.h>
#include <rte_table_hash.h>
#include <rte_table_lpm.h>
#include <rte_table_lpm_ipv6.h>
#include <rte_table_stub.h>
#include <rte_tailq.h>
#include <rte_tcp.h>
#include <rte_thash.h>
#include <rte_time.h>
#include <rte_timer.h>
#include <rte_udp.h>
#include <rte_version.h>
#include <rte_virtio_net.h>
