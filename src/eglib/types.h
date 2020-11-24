#ifndef EGLIB_TYPES_H
#define EGLIB_TYPES_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * Pixel format used in-memory by displays.
 */
typedef enum {
	/**
	 * 1bit per pixel where each number of bytes equal to the display width
	 * is a page: MSB bits are the upper line, LSB bits are the lower line.
	 */
	PIXEL_FORMAT_1BIT_BW_PAGED,
	/** RRRRGGGG BBBBRRRR GGGGBBBB */
	PIXEL_FORMAT_12BIT_RGB,
	/** RRRRRGGG GGGBBBBB */
	PIXEL_FORMAT_16BIT_RGB,
	/** RRRRRRxx GGGGGGxx BBBBBBxx */
	PIXEL_FORMAT_18BIT_RGB_24BIT,
	/** RRRRRRRR GGGGGGGG BBBBBBBB */
	PIXEL_FORMAT_24BIT_RGB,
	PIXEL_FORMAT_COUNT,
} pixel_format_t;

/** Data type for each color channel: red, green, blue. */
typedef uint8_t color_channel_t;

/**
 * A color specification used by various drawing functions.
 */
typedef struct {
	/** Red */
	color_channel_t r;
	/** Green */
	color_channel_t g;
	/** Blue */
	color_channel_t b;
} color_t;

/** Data type for display coordinates used by various drawing functions. */
typedef int16_t coordinate_t;

struct _eglib_struct;

/**
 * Handle used by all eglib functions. It wraps the HAL driver, Display driver
 * and internal library state.
 */
typedef struct _eglib_struct eglib_t;

struct _hal;
typedef struct _hal hal_t;

struct _display_struct;
typedef struct _display_struct display_t;

#endif