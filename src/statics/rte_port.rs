// This file is part of dpdk-sys. It is subject to the license terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT. No part of dpdk-sys, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of dpdk-sys. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/dpdk-sys/master/COPYRIGHT.


extern "C"
{
	pub static mut rte_port_ethdev_reader_ops: rte_port_in_ops;
	pub static mut rte_port_ethdev_writer_nodrop_ops: rte_port_out_ops;
	pub static mut rte_port_ethdev_writer_ops: rte_port_out_ops;
	pub static mut rte_port_ring_multi_reader_ops: rte_port_in_ops;
	pub static mut rte_port_ring_multi_writer_nodrop_ops: rte_port_out_ops;
	pub static mut rte_port_ring_multi_writer_ops: rte_port_out_ops;
	pub static mut rte_port_ring_reader_ipv4_frag_ops: rte_port_in_ops;
	pub static mut rte_port_ring_reader_ipv6_frag_ops: rte_port_in_ops;
	pub static mut rte_port_ring_reader_ops: rte_port_in_ops;
	pub static mut rte_port_ring_writer_ipv4_ras_ops: rte_port_out_ops;
	pub static mut rte_port_ring_writer_ipv6_ras_ops: rte_port_out_ops;
	pub static mut rte_port_ring_writer_nodrop_ops: rte_port_out_ops;
	pub static mut rte_port_ring_writer_ops: rte_port_out_ops;
	pub static mut rte_port_sched_reader_ops: rte_port_in_ops;
	pub static mut rte_port_sched_writer_ops: rte_port_out_ops;
	pub static mut rte_port_sink_ops: rte_port_out_ops;
	pub static mut rte_port_source_ops: rte_port_in_ops;
}
