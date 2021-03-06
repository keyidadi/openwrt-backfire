/*
 * (C) Copyright 2003-2005
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*
 * This file contains the configuration parameters for the Danube reference board.
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/* #define DEBUG */

#define CONFIG_MIPS32		1	/* MIPS32 CPU compatible		*/
#define CONFIG_MIPS24KEC	1	/* MIPS 24KEc CPU core			*/
#define CONFIG_DANUBE		1	/* in a Danube/Twinpass Chip		*/
#define CONFIG_EASY50712	1	/* on the Danube Reference Board	*/

#define CONFIG_SYS_MIPS_MULTI_CPU	1	/* This is a multi cpu system */

#define CONFIG_SYS_MAX_RAM	32*1024*1024

#define CONFIG_FLASH_CFI_DRIVER	1

#define CONFIG_SYS_INIT_RAM_LOCK_MIPS
#ifdef CONFIG_SYS_RAMBOOT
	//#warning CONFIG_SYS_RAMBOOT
	#define CONFIG_SKIP_LOWLEVEL_INIT
#else /* CONFIG_SYS_RAMBOOT */

	#define CONFIG_SYS_EBU_BOOT

	#ifdef CONFIG_USE_DDR_RAM
		/* FIXME: should not need these workarounds */
		#define DANUBE_DDR_RAM_SIZE	32	/* 32M DDR-DRAM for reference board */
	#endif

	#define INFINEON_EBU_BOOTCFG	0x688C688C	/* CMULT = 8 for 150 MHz */

#endif /* CONFIG_SYS_RAMBOOT */

#if 1
#ifndef	CPU_CLOCK_RATE
#define CPU_CLOCK_RATE	(ifx_get_cpuclk())
#endif
#endif

#define	CONFIG_SYS_PROMPT	"DANUBE => "	/* Monitor Command Prompt */

#undef CONFIG_SYS_HUSH_PARSER		/* Use the HUSH parser		*/

/*
 * Include common defines/options for all Infineon boards
 */
#include "ifx-common.h"

/*
 * Cache Configuration (cpu/chip specific, Danube)
 */
#define CONFIG_SYS_DCACHE_SIZE		16384
#define CONFIG_SYS_ICACHE_SIZE		16384
#define CONFIG_SYS_CACHELINE_SIZE	32
#define CONFIG_SYS_MIPS_CACHE_OPER_MODE	CONF_CM_CACHABLE_NO_WA

#define CONFIG_NET_MULTI
#if 0
#define CONFIG_M4530_ETH
#define CONFIG_M4530_FPGA
#endif

#define CONFIG_IFX_ETOP
#define CLK_OUT2_25MHZ
#define CONFIG_EXTRA_SWITCH

#define CONFIG_RMII			/*  use interface in RMII mode */

#define CONFIG_MII
#define CONFIG_CMD_MII

#define CONFIG_IFX_ASC

#ifdef CONFIG_USE_ASC0
#define CONFIG_SYS_IFX_ASC_BASE		0x1E100400
#else
#define CONFIG_SYS_IFX_ASC_BASE		0x1E100C00
#endif

#ifdef CONFIG_SYS_RAMBOOT
/* Configuration of EBU: */
/* starting address from 0xb0000000 */
/* make the flash available from RAM boot */
#	define CONFIG_EBU_ADDSEL0		0x10000031
#	define CONFIG_EBU_BUSCON0		0x0001D7FF
#endif

#define CONFIG_CMD_HTTPD		/* enable upgrade via HTTPD */

#endif	/* __CONFIG_H */
