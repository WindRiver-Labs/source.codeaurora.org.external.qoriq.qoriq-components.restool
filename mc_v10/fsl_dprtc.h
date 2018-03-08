/* Copyright 2013-2016 Freescale Semiconductor Inc.
 * Copyright 2017-2018 NXP
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
#ifndef __FSL_DPRTC_V10_H
#define __FSL_DPRTC_V10_H

#include "../mc_v9/fsl_dprtc.h"

/* Data Path Real Time Counter API
 * Contains initialization APIs and runtime control APIs for RTC
 */

struct fsl_mc_io;

/**
 * Number of irq's
 */
#define DPRTC_MAX_IRQ_NUM			1
#define DPRTC_IRQ_INDEX				0

/**
 * Interrupt event masks:
 */

/**
 * Interrupt event mask indicating alarm event had occurred
 */
#define DPRTC_EVENT_ALARM			0x40000000
/**
 * Interrupt event mask indicating periodic pulse event had occurred
 */
#define DPRTC_EVENT_PPS				0x08000000

int dprtc_open_v10(struct fsl_mc_io *mc_io,
		   uint32_t cmd_flags,
		   int dprtc_id,
		   uint16_t *token);

int dprtc_close_v10(struct fsl_mc_io *mc_io,
		    uint32_t cmd_flags,
		    uint16_t token);

int dprtc_create_v10(struct fsl_mc_io *mc_io,
		     uint16_t dprc_token,
		     uint32_t cmd_flags,
		     const struct dprtc_cfg *cfg,
		     uint32_t *obj_id);

int dprtc_destroy_v10(struct fsl_mc_io *mc_io,
		      uint16_t dprc_token,
		      uint32_t cmd_flags,
		      uint32_t object_id);

int dprtc_get_irq_mask_v10(struct fsl_mc_io *mc_io,
			   uint32_t cmd_flags,
			   uint16_t token,
			   uint8_t irq_index,
			   uint32_t *mask);

int dprtc_get_irq_status_v10(struct fsl_mc_io *mc_io,
			     uint32_t cmd_flags,
			     uint16_t token,
			     uint8_t irq_index,
			     uint32_t *status);

/**
 * struct dprtc_attr_v10 - Structure representing DPRTC attributes
 * @id:		DPRTC object ID
 */
struct dprtc_attr_v10 {
	int id;
};

int dprtc_get_attributes_v10(struct fsl_mc_io *mc_io,
			     uint32_t cmd_flags,
			     uint16_t token,
			     struct dprtc_attr_v10 *attr);

int dprtc_get_api_version_v10(struct fsl_mc_io *mc_io,
			      uint32_t cmd_flags,
			      uint16_t *major_ver,
			      uint16_t *minor_ver);

#endif /* __FSL_DPRTC_H */
