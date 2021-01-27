/*
 * This file is part of the OpenMV project.
 *
 * Copyright (c) 2013-2019 Ibrahim Abdelkader <iabdalkader@openmv.io>
 * Copyright (c) 2013-2019 Kwabena W. Agyeman <kwagyeman@openmv.io>
 *
 * This work is licensed under the MIT license, see the file LICENSE for details.
 *
 * Framebuffer functions.
 */
#include <stdio.h>

#include "mpprint.h"
#include "py/mpthread.h"

#include "framebuffer.h"
#include "omv_boardconfig.h"

extern framebuffer_t g_sPacketPipeFrame;
framebuffer_t *framebuffer = (framebuffer_t *) &g_sPacketPipeFrame;

static jpegbuffer_t s_sJpegBuff;
static __attribute__((section("no_init"), aligned(32))) uint8_t _jpeg_buf[OMV_JPEG_BUF_SIZE];
jpegbuffer_t *jpeg_framebuffer = (jpegbuffer_t *) &s_sJpegBuff;
static mp_thread_mutex_t s_sJpegMutex; 

#define CONSERVATIVE_JPEG_BUF_SIZE  (OMV_JPEG_BUF_SIZE-64)

void framebuffer_init0()
{
    // Save fb_enabled flag state
    int fb_enabled = JPEG_FB()->enabled;

    // Clear framebuffers
    memset(JPEG_FB(), 0, sizeof(*JPEG_FB()));

    // Skip the first frame.
    MAIN_FB()->bpp = -1;

    // Enable streaming.
    MAIN_FB()->streaming_enabled = true; // controlled by the OpenMV Cam.

    // Set default quality
    JPEG_FB()->quality = ((JPEG_QUALITY_HIGH - JPEG_QUALITY_LOW) / 2) + JPEG_QUALITY_LOW;

    // Set fb_enabled
    JPEG_FB()->enabled = fb_enabled; // controlled by the IDE.

    JPEG_FB()->pixels = _jpeg_buf; // controlled by the IDE.

	//init jpeg mutex
	mp_thread_mutex_init(&s_sJpegMutex);
}

void framebuffer_initialize_image(image_t *img)
{
    img->w = framebuffer->w;
    img->h = framebuffer->h;
    img->bpp = framebuffer->bpp;
    img->data = framebuffer->pixels;
}

void fb_set_streaming_enabled(bool enable)
{
    framebuffer->streaming_enabled = enable;
}

bool fb_get_streaming_enabled()
{
    return framebuffer->streaming_enabled;
}

int fb_encode_for_ide_new_size(image_t *img)
{
    return (((img->bpp * 8) + 5) / 6) + 2;
}

void fb_encode_for_ide(uint8_t *ptr, image_t *img)
{
    *ptr++ = 0xFE;

    for(int i = 0, j = (img->bpp / 3) * 3; i < j; i += 3) {
        int x = 0;
        x |= img->data[i + 0] << 0;
        x |= img->data[i + 1] << 8;
        x |= img->data[i + 2] << 16;
        *ptr++ = 0x80 | ((x >> 0) & 0x3F);
        *ptr++ = 0x80 | ((x >> 6) & 0x3F);
        *ptr++ = 0x80 | ((x >> 12) & 0x3F);
        *ptr++ = 0x80 | ((x >> 18) & 0x3F);
    }

    if((img->bpp % 3) == 2) { // 2 bytes -> 16-bits -> 24-bits sent
        int x = 0;
        x |= img->data[img->bpp - 2] << 0;
        x |= img->data[img->bpp - 1] << 8;
        *ptr++ = 0x80 | ((x >> 0) & 0x3F);
        *ptr++ = 0x80 | ((x >> 6) & 0x3F);
        *ptr++ = 0x80 | ((x >> 12) & 0x3F);
    }

    if((img->bpp % 3) == 1) { // 1 byte -> 8-bits -> 16-bits sent
        int x = 0;
        x |= img->data[img->bpp - 1] << 0;
        *ptr++ = 0x80 | ((x >> 0) & 0x3F);
        *ptr++ = 0x80 | ((x >> 6) & 0x3F);
    }

    *ptr++ = 0xFE;
}

int32_t framebuffer_get_x()
{
    return framebuffer->x;
}

int32_t framebuffer_get_y()
{
    return framebuffer->y;
}

int32_t framebuffer_get_u()
{
    return framebuffer->u;
}

int32_t framebuffer_get_v()
{
    return framebuffer->v;
}

int32_t framebuffer_get_width()
{
    return framebuffer->w;
}

int32_t framebuffer_get_height()
{
    return framebuffer->h;
}

int32_t framebuffer_get_depth()
{
    return framebuffer->bpp;
}

uint32_t framebuffer_get_frame_size()
{
    image_t img;
    framebuffer_initialize_image(&img);
    return image_size(&img);
}

uint32_t framebuffer_get_buffer_size()
{
    uint32_t size = VIN_CONFIG_PORT0_PACKET_WIDTH * VIN_CONFIG_PORT0_PACKET_HEIGHT * 2;
    return (size / 32) * 32;
}

uint8_t *framebuffer_get_buffer()
{
    return framebuffer->pixels;
}

void framebuffer_set(int32_t w, int32_t h, int32_t bpp)
{
    framebuffer->w = w;
    framebuffer->h = h;
    framebuffer->bpp = bpp;
}

static void initialize_jpeg_buf_from_image(image_t *img)
{
    if (!img) {
        jpeg_framebuffer->w = 0;
        jpeg_framebuffer->h = 0;
        jpeg_framebuffer->size = 0;
    } else {
        jpeg_framebuffer->w = img->w;
        jpeg_framebuffer->h = img->h;
        jpeg_framebuffer->size = img->bpp;
    }
}

void fb_update_jpeg_buffer()
{
    static int overflow_count = 0;

    image_t src;
    framebuffer_initialize_image(&src);

    if (framebuffer->streaming_enabled && jpeg_framebuffer->enabled) {
        if (src.bpp > 3) {
            bool does_not_fit = false;

            if (mp_thread_mutex_lock(&s_sJpegMutex, 1)) {
                if(CONSERVATIVE_JPEG_BUF_SIZE < src.bpp) {
                    initialize_jpeg_buf_from_image(NULL);
                    does_not_fit = true;
                } else {
                    initialize_jpeg_buf_from_image(&src);
                    memcpy(jpeg_framebuffer->pixels, src.pixels, src.bpp);
                }

                mp_thread_mutex_unlock(&s_sJpegMutex);
            }

            if (does_not_fit) {
                printf("Warning: JPEG too big! Trying framebuffer transfer using fallback method!\n");
                int new_size = fb_encode_for_ide_new_size(&src);
                fb_alloc_mark();
                uint8_t *temp = fb_alloc(new_size, FB_ALLOC_NO_HINT);
                fb_encode_for_ide(temp, &src);
                (MP_PYTHON_PRINTER)->print_strn((MP_PYTHON_PRINTER)->data, (const char *) temp, new_size);
                fb_alloc_free_till_mark();
            }
        } else if (src.bpp >= 0) {
            if (mp_thread_mutex_lock(&s_sJpegMutex, 1)) {
                image_t dst = {.w=src.w, .h=src.h, .bpp=CONSERVATIVE_JPEG_BUF_SIZE, .pixels=jpeg_framebuffer->pixels};
                // Note: lower quality saves USB bandwidth and results in a faster IDE FPS.
                bool overflow = jpeg_compress(&src, &dst, jpeg_framebuffer->quality, false);

                if (overflow) {
                    // JPEG buffer overflowed, reduce JPEG quality for the next frame
                    // and skip the current frame. The IDE doesn't receive this frame.
                    if (jpeg_framebuffer->quality > 1) {
                        // Keep this quality for the next n frames
                        overflow_count = 60;
                        jpeg_framebuffer->quality = IM_MAX(1, (jpeg_framebuffer->quality/2));
                    }

                    initialize_jpeg_buf_from_image(NULL);
                } else {
                    if (overflow_count) {
                        overflow_count--;
                    }

                    // Dynamically adjust our quality if the image is huge.
                    bool big_frame_buffer = image_size(&src) > JPEG_QUALITY_THRESH;
                    int jpeg_quality_max = big_frame_buffer ? JPEG_QUALITY_LOW : JPEG_QUALITY_HIGH;

                    // No buffer overflow, increase quality up to max quality based on frame size...
                    if ((!overflow_count) && (jpeg_framebuffer->quality < jpeg_quality_max)) {
                        jpeg_framebuffer->quality++;
                    }

                    initialize_jpeg_buf_from_image(&dst);
                }

                mp_thread_mutex_unlock(&s_sJpegMutex);
            }
        }
    }
}

