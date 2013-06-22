/*
 * Copyright (c) 2012, 2013, Joel Bodenmann aka Tectu <joel@unormal.org>
 * Copyright (c) 2012, 2013, Andrew Hannam aka inmarket
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the <organization> nor the
 *      names of its contributors may be used to endorse or promote products
 *      derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "gfx.h"

#ifdef WIN32
	#define USE_MEMORY_FILE		FALSE				// Can be true or false for Win32
#else
	#define USE_MEMORY_FILE		TRUE				// Non-Win32 - use the compiled in image
#endif

#if USE_MEMORY_FILE
	#include "test-pal8.h"
#endif

static gdispImage myImage;

int main(void) {
	coord_t			swidth, sheight;

	gfxInit();		// Initialize the display

	// Get the display dimensions
	swidth = gdispGetWidth();
	sheight = gdispGetHeight();

	// Set up IO for our image
#if USE_MEMORY_FILE
	gdispImageSetMemoryReader(&myImage, test_pal8);
#else
	gdispImageSetSimulFileReader(&myImage, "test-pal8.bmp");
#endif

	gdispImageOpen(&myImage);
	gdispImageDraw(&myImage, 0, 0, swidth, sheight, 0, 0);
	gdispImageClose(&myImage);

	while(1) {
		gfxSleepMilliseconds(1000);
	}

	return 0;
}
