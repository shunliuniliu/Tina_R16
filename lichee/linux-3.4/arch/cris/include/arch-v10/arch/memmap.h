/*
 * arch/cris/include/arch-v10/arch/memmap.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef _ASM_ARCH_MEMMAP_H
#define _ASM_ARCH_MEMMAP_H

#define MEM_CSE0_START (0x00000000)
#define MEM_CSE0_SIZE (0x04000000)
#define MEM_CSE1_START (0x04000000)
#define MEM_CSE1_SIZE (0x04000000)
#define MEM_CSR0_START (0x08000000)
#define MEM_CSR1_START (0x0c000000)
#define MEM_CSP0_START (0x10000000)
#define MEM_CSP1_START (0x14000000)
#define MEM_CSP2_START (0x18000000)
#define MEM_CSP3_START (0x1c000000)
#define MEM_CSP4_START (0x20000000)
#define MEM_CSP5_START (0x24000000)
#define MEM_CSP6_START (0x28000000)
#define MEM_CSP7_START (0x2c000000)
#define MEM_DRAM_START (0x40000000)

#define MEM_NON_CACHEABLE (0x80000000)

#endif