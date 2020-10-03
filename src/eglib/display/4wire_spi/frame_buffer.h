#ifndef EGLIB_DISPLAY_4WIRE_SPI_FRAME_BUFFER_H
#define EGLIB_DISPLAY_4WIRE_SPI_FRAME_BUFFER_H

#include "../4wire_spi.h"
#include "../../../eglib.h"

void eglib_display_4wire_spi_frame_buffer_send_buffer_18bit_565_rgb(
	eglib_t *eglib,
	void *buffer_ptr,
	eglib_coordinate_t x, eglib_coordinate_t y,
	eglib_coordinate_t width, eglib_coordinate_t height
);

void eglib_display_4wire_spi_frame_buffer_send_buffer_24bit_rgb(
	eglib_t *eglib,
	void *buffer_ptr,
	eglib_coordinate_t x, eglib_coordinate_t y,
	eglib_coordinate_t width, eglib_coordinate_t height
);

typedef struct {
	eglib_t *eglib_buffered;
	void *buffer;
} eglib_display_4wire_spi_frame_buffer_config_t;

void eglib_4WireSPI_FrameBuffer_Init(
	eglib_t *eglib_frame_buffer,
	eglib_display_4wire_spi_t *frame_buffer,
	eglib_display_4wire_spi_frame_buffer_config_t *frame_buffer_config,
	eglib_t *eglib_buffered
);

void eglib_4WireSPI_FrameBuffer_Send(
	eglib_t *eglib,
	eglib_coordinate_t x, eglib_coordinate_t y,
	eglib_coordinate_t width, eglib_coordinate_t height
);

#endif