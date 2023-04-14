/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Configuration header file for K3 AM642 SoC family
 *
 * Copyright (C) 2020-2023 Texas Instruments Incorporated - https://www.ti.com/
 *	Keerthy <j-keerthy@ti.com>
 */

#ifndef __CONFIG_AM642_EVM_H
#define __CONFIG_AM642_EVM_H

#include <linux/sizes.h>

/* DDR Configuration */
#define CFG_SYS_SDRAM_BASE1		0x880000000

#if CONFIG_IS_ENABLED(CMD_MMC)
#define DISTRO_BOOT_DEV_MMC(func) func(MMC, mmc, 1) func(MMC, mmc, 0)
#else
#define DISTRO_BOOT_DEV_MMC(func)
#endif

#if CONFIG_IS_ENABLED(CMD_PXE)
#define DISTRO_BOOT_DEV_PXE(func) func(PXE, pxe, na)
#else
#define DISTRO_BOOT_DEV_PXE(func)
#endif

#if CONFIG_IS_ENABLED(CMD_DHCP)
#define DISTRO_BOOT_DEV_DHCP(func) func(DHCP, dhcp, na)
#else
#define DISTRO_BOOT_DEV_DHCP(func)
#endif

#if CONFIG_IS_ENABLED(CMD_USB)
# define BOOT_TARGET_USB(func)	func(USB, usb, 0)
#else
# define BOOT_TARGET_USB(func)
#endif

#define BOOT_TARGET_DEVICES(func) \
	BOOT_TARGET_USB(func) \
	DISTRO_BOOT_DEV_MMC(func) \
	DISTRO_BOOT_DEV_PXE(func) \
	DISTRO_BOOT_DEV_DHCP(func)

#include <config_distro_bootcmd.h>

/* Incorporate settings into the U-Boot environment */
#define CFG_EXTRA_ENV_SETTINGS					\
	BOOTENV

/* Now for the remaining common defines */
#include <configs/ti_armv7_common.h>

#endif /* __CONFIG_AM642_EVM_H */
