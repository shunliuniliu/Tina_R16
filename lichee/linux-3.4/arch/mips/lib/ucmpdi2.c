/*
 * arch/mips/lib/ucmpdi2.c
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#include <linux/module.h>

#include "libgcc.h"

word_type __ucmpdi2(unsigned long long a, unsigned long long b)
{
	const DWunion au = {.ll = a};
	const DWunion bu = {.ll = b};

	if ((unsigned int) au.s.high < (unsigned int) bu.s.high)
		return 0;
	else if ((unsigned int) au.s.high > (unsigned int) bu.s.high)
		return 2;
	if ((unsigned int) au.s.low < (unsigned int) bu.s.low)
		return 0;
	else if ((unsigned int) au.s.low > (unsigned int) bu.s.low)
		return 2;
	return 1;
}

EXPORT_SYMBOL(__ucmpdi2);