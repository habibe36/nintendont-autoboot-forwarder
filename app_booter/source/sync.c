// Copyright 2008-2009  Segher Boessenkool  <segher@kernel.crashing.org>
// This code is licensed to you under the terms of the GNU GPL, version 2;
// see file COPYING or http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt

#include <gctypes.h>

void sync_before_exec(const void *p, u32 len)
{
	for(u32 a = (u32)p & ~0x1f, b = ((u32)p + len + 0x1f) & ~0x1f; a < b; a += 32)
		asm("dcbst 0,%0 ; sync ; icbi 0,%0" : : "b"(a));

	asm("sync ; isync");
}
