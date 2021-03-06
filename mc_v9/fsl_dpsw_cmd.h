/* Copyright 2013-2016 Freescale Semiconductor Inc.
 * Copyright 2017 NXP
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * * Neither the name of the above-listed copyright holders nor the
 * names of any contributors may be used to endorse or promote products
 * derived from this software without specific prior written permission.
 *
 *
 * ALTERNATIVELY, this software may be distributed under the terms of the
 * GNU General Public License ("GPL") as published by the Free Software
 * Foundation, either version 2 of that License or (at your option) any
 * later version.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef __FSL_DPSW_CMD_V9_H
#define __FSL_DPSW_CMD_V9_H

/* DPSW Version */
#define DPSW_VER_MAJOR				7
#define DPSW_VER_MINOR				0

/* Command IDs */
#define DPSW_CMDID_CLOSE			0x800
#define DPSW_CMDID_OPEN				0x802
#define DPSW_CMDID_CREATE			0x902
#define DPSW_CMDID_DESTROY			0x900

#define DPSW_CMDID_GET_ATTR			0x004
#define DPSW_CMDID_GET_IRQ_MASK			0x015
#define DPSW_CMDID_GET_IRQ_STATUS		0x016

/*                cmd, param, offset, width, type, arg_name */
#define DPSW_CMD_OPEN(cmd, dpsw_id) \
	MC_CMD_OP(cmd, 0, 0,  32, int,	 dpsw_id)

/*                cmd, param, offset, width, type, arg_name */
#define DPSW_CMD_CREATE_V9(cmd, cfg) \
do { \
	MC_CMD_OP(cmd, 0, 0,  16, uint16_t, cfg->num_ifs);\
	MC_CMD_OP(cmd, 0, 16,  8, uint8_t,  cfg->adv.max_fdbs);\
	MC_CMD_OP(cmd, 0, 24,  8, uint8_t,  cfg->adv.max_meters_per_if);\
	MC_CMD_OP(cmd, 0, 32,  4, enum dpsw_component_type,  \
			cfg->adv.component_type);\
	MC_CMD_OP(cmd, 1, 0,  16, uint16_t, cfg->adv.max_vlans);\
	MC_CMD_OP(cmd, 1, 16, 16, uint16_t, cfg->adv.max_fdb_entries);\
	MC_CMD_OP(cmd, 1, 32, 16, uint16_t, cfg->adv.fdb_aging_time);\
	MC_CMD_OP(cmd, 1, 48, 16, uint16_t, cfg->adv.max_fdb_mc_groups);\
	MC_CMD_OP(cmd, 2, 0,  64, uint64_t, cfg->adv.options);\
} while (0)

/*                cmd, param, offset, width, type, arg_name */
#define DPSW_CMD_GET_IRQ_MASK(cmd, irq_index) \
	MC_CMD_OP(cmd, 0, 32, 8,  uint8_t,  irq_index)

/*                cmd, param, offset, width, type, arg_name */
#define DPSW_RSP_GET_IRQ_MASK(cmd, mask) \
	MC_RSP_OP(cmd, 0, 0,  32, uint32_t, mask)

/*                cmd, param, offset, width, type, arg_name */
#define DPSW_CMD_GET_IRQ_STATUS(cmd, irq_index, status) \
do { \
	MC_CMD_OP(cmd, 0, 0,  32, uint32_t, status);\
	MC_CMD_OP(cmd, 0, 32, 8,  uint8_t,  irq_index);\
} while (0)

/*                cmd, param, offset, width, type, arg_name */
#define DPSW_RSP_GET_IRQ_STATUS(cmd, status) \
	MC_RSP_OP(cmd, 0, 0,  32, uint32_t, status)

/*                cmd, param, offset, width, type, arg_name */
#define DPSW_RSP_GET_ATTR_V9(cmd, attr) \
do { \
	MC_RSP_OP(cmd, 0, 0,  16, uint16_t, attr->num_ifs);\
	MC_RSP_OP(cmd, 0, 16, 8,  uint8_t,  attr->max_fdbs);\
	MC_RSP_OP(cmd, 0, 24, 8,  uint8_t,  attr->num_fdbs);\
	MC_RSP_OP(cmd, 0, 32, 16, uint16_t, attr->max_vlans);\
	MC_RSP_OP(cmd, 0, 48, 16, uint16_t, attr->num_vlans);\
	MC_RSP_OP(cmd, 1, 0,  16, uint16_t, attr->version.major);\
	MC_RSP_OP(cmd, 1, 16, 16, uint16_t, attr->version.minor);\
	MC_RSP_OP(cmd, 1, 32, 16, uint16_t, attr->max_fdb_entries);\
	MC_RSP_OP(cmd, 1, 48, 16, uint16_t, attr->fdb_aging_time);\
	MC_RSP_OP(cmd, 2, 0,  32, int,	 attr->id);\
	MC_RSP_OP(cmd, 2, 32, 16, uint16_t, attr->mem_size);\
	MC_RSP_OP(cmd, 2, 48, 16, uint16_t, attr->max_fdb_mc_groups);\
	MC_RSP_OP(cmd, 3, 0,  64, uint64_t, attr->options);\
	MC_RSP_OP(cmd, 4, 0,  8,  uint8_t, attr->max_meters_per_if);\
	MC_RSP_OP(cmd, 4, 8,  4,  enum dpsw_component_type, \
			attr->component_type);\
} while (0)

#endif /* __FSL_DPSW_CMD_H */
