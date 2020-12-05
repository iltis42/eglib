#ifndef EGLIB_DRAWING_H
#define EGLIB_DRAWING_H

#include "../eglib.h"
#include <wchar.h>

/**
 * These are generic drawing functions.
 *
 * :See also: :c:func:`eglib_Init` or :c:func:`eglib_Init_FrameBuffer`.
 */

/**
 * Clipping
 * ========
 *
 * These functions allows restricting drawing functions to only work inside
 * a specified box.
 */

/**
 * Defines a rectangle to clip all drawing functions to.
 *
 * Any drawing function outside of these boundaries will have no effect.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_SetClipRange.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_SetClipRange.png
 *   :width: 200
 */
void eglib_SetClipRange(
	eglib_t *eglib,
	coordinate_t x, coordinate_t y,
	coordinate_t width, coordinate_t height
);

/**
 * Disable clipping.
 *
 * :See also: :c:func:`eglib_SetClipRange`.
 */
void eglib_SetNoClip(eglib_t *eglib);

/**
 * Returns whether the pixel at given coordinate is clipped. See :c:func:`eglib_SetClipRange`.
 */
bool eglib_IsPixelClipped(
	eglib_t *eglib,
	coordinate_t x, coordinate_t y
);

/**
 * Whole Screen
 * ============
 */

/**
 * Clear screen, all pixels black, just like after :c:func:`eglib_Init`.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_ClearScreen.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_ClearScreen.png
 *   :width: 200
 */
void eglib_ClearScreen(eglib_t *eglib);

/**
 * Color
 * =====
 *
 * Various drawing functions do not take a color argument and instead use the
 * color from a previously defined index.
 */

/** Set color for given index, which other drawing functions may use. */
void eglib_SetIndexColor(
	eglib_t *eglib,
	size_t idx,
	color_channel_t r,
	color_channel_t g,
	color_channel_t b
);

/**
 * Pixel
 * =====
 */

/**
 * Draw given pixel coordinates with given color.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawPixelColor.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawPixelColor.png
 *   :width: 200
 */
void eglib_DrawPixelColor(eglib_t *eglib, coordinate_t x, coordinate_t y, color_t color);

/**
 * Draw given pixel coordinates using color from index 0.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawPixel.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawPixel.png
 *   :width: 200
 *
 * :See also: :c:func:`eglib_SetIndexColor`.
 */
void eglib_DrawPixel(eglib_t *eglib, coordinate_t x, coordinate_t y);

/**
 * Lines
 * =====
 */

/**
 * Draw line from coordinates (`x1`, `y1`) to (`x2`, `y2`) using color from
 * index 0.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawLine.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawLine.png
 *   :width: 200
 *
 * :See also: :c:func:`eglib_SetIndexColor`.
 */
void eglib_DrawLine(eglib_t *eglib, coordinate_t x1, coordinate_t y1, coordinate_t x2, coordinate_t y2);

/**
 * Draw horizontal line starting at (`x`, `y`) with length `len` using color from
 * index 0.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawHLine.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawHLine.png
 *   :width: 200
 *
 * :See also: :c:func:`eglib_SetIndexColor`.
 */
#define eglib_DrawHLine(eglib, x, y, len) eglib_DrawLine(eglib, x, y, x + len, y);

/**
 * Draw vertical line starting at (`x`, `y`) with length `len` using color from
 * index 0.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawVLine.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawVLine.png
 *   :width: 200
 *
 * :See also: :c:func:`eglib_SetIndexColor`.
 */
#define eglib_DrawVLine(eglib, x, y, len) eglib_DrawLine(eglib, x, y, x, y + len);

/**
 * Draw line from coordinates (`x1`, `y1`) to (`x2`, `y2`).
 *
 * Line color will be a gradient from index 0 at (`x1`, `y1`) to color from index
 * 1 at (`x2`, `y2`).
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawGradientLine.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawGradientLine.png
 *   :width: 200
 *
 * :See also: :c:func:`eglib_SetIndexColor`.
 */
void eglib_DrawGradientLine(
	eglib_t *eglib,
	coordinate_t x1, coordinate_t y1,
	coordinate_t x2, coordinate_t y2
);

/**
 * Draw horizontal gradient line from coordinates (`x`, `y`) to (`x + len`, `y`).
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawGradientHLine.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawGradientHLine.png
 *   :width: 200
 *
 * :See also: :c:func:`eglib_DrawGradientLine`.
 */
#define eglib_DrawGradientHLine(eglib, x, y, len) eglib_DrawGradientLine( \
	eglib, \
	x, y, \
	x + len, y \
)

/**
 * Draw vertical gradient line from coordinates (`x`, `y`) to (`x`, `y + len`).
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawGradientVLine.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawGradientVLine.png
 *   :width: 200
 *
 * :See also: :c:func:`eglib_DrawGradientLine`.
 */
#define eglib_DrawGradientVLine(eglib, x, y, len) eglib_DrawGradientLine( \
	eglib, \
	x, y, \
	x, y + len \
)

/**
 * Frames
 * ======
 */

/**
 * Draw frame starting at ``(x, y)`` with ``width`` and ``height`` using color
 * from index 0.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawFrame.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawFrame.png
 *   :width: 200
 *
 * :See also: :c:func:`eglib_SetIndexColor`.
 */
void eglib_DrawFrame(
	eglib_t *eglib,
	coordinate_t x, coordinate_t y,
	coordinate_t width, coordinate_t height
);

/**
 * Draw frame starting at ``(x, y)`` with ``width`` and ``height``.
 *
 * Its colors will be a gradient:
 *
 * - Top left: color index 0.
 * - Top right: color index 1.
 * - Bottom left: color index 2.
 * - Bottom right: color index 3.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawGradientFrame.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawGradientFrame.png
 *   :width: 200
 *
 * :See also: :c:func:`eglib_SetIndexColor`.
 */
void eglib_DrawGradientFrame(
	eglib_t *eglib,
	coordinate_t x, coordinate_t y,
	coordinate_t width, coordinate_t height
);

/**
 * Draw frame starting at ``(x, y)``, with ``width`` and ``height`` and rounded
 * edges with ``radius``, using color from index 0.
 *
 * Both ``width`` and ``height`` must be greater than ``2 * radius``.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawRoundFrame.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawRoundFrame.png
 *   :width: 200
 *
 * :See also: :c:func:`eglib_SetIndexColor`.
 */
void eglib_DrawRoundFrame(
	eglib_t *eglib,
	coordinate_t x, coordinate_t y,
	coordinate_t width, coordinate_t height,
	coordinate_t radius
);

/**
 * Boxes
 * =====
 */

/**
 * Draw box starting at ``(x, y)`` with ``width`` and ``height`` using color
 * from index 0.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawBox.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawBox.png
 *   :width: 200
 *
 * :See also: :c:func:`eglib_SetIndexColor`.
 */
void eglib_DrawBox(
	eglib_t *eglib,
	coordinate_t x, coordinate_t y,
	coordinate_t width, coordinate_t height
);

/**
 * Draw box starting at ``(x, y)`` with ``width`` and ``height``.
 *
 * Its colors will be a gradient:
 *
 * - Top left: color index 0.
 * - Top right: color index 1.
 * - Bottom left: color index 2.
 * - Bottom right: color index 3.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawGradientBox.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawGradientBox.png
 *   :width: 200
 *
 * :See also: :c:func:`eglib_SetIndexColor`.
 */
void eglib_DrawGradientBox(
	eglib_t *eglib,
	coordinate_t x, coordinate_t y,
	coordinate_t width, coordinate_t height
);

/**
 * Draw frame starting at ``(x, y)``, with ``width`` and ``height`` and rounded
 * edges with ``radius``, using color from index 0.
 *
 * Both ``width`` and ``height`` must be greater than ``2 * radius``.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawRoundBox.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawRoundBox.png
 *   :width: 200
 *
 * :See also: :c:func:`eglib_SetIndexColor`.
 */
void eglib_DrawRoundBox(
	eglib_t *eglib,
	coordinate_t x, coordinate_t y,
	coordinate_t width, coordinate_t height,
	coordinate_t radius
);

/**
 * Round things
 * ============
 */

/**
 * Draw an arc with color from index 0
 *
 * :param x: Center x.
 * :param y: Center y.
 * :param radius: Radius.
 * :param start_angle: Start angle from 0 to 360, where 0 is "up" and 90 is "right".
 * :param end_angle: End angle, bigger than ``start_angle`` and less or equal to 360.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawArc.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawArc.png
 *   :width: 200
 */
void eglib_DrawArc(
	eglib_t *eglib,
	coordinate_t x, coordinate_t y,
	coordinate_t radius,
	float start_angle,
	float end_angle
);

/**
 * Draw an arc with color gradient from index 0 to index 1.
 *
 * :param x: Center x.
 * :param y: Center y.
 * :param radius: Radius.
 * :param start_angle: Start angle from 0 to 360, where 0 is "up" and 90 is "right".
 * :param end_angle: End angle, bigger than ``start_angle`` and less or equal to 360.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawGradientArc.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawGradientArc.png
 *   :width: 200
 */
void eglib_DrawGradientArc(
	eglib_t *eglib,
	coordinate_t x, coordinate_t y,
	coordinate_t radius,
	float start_angle,
	float end_angle
);

/**
 * Draw an arc with color from index 0
 *
 * :param x: Center x.
 * :param y: Center y.
 * :param radius: Radius.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawCircle.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawCircle.png
 *   :width: 200
 */
#define eglib_DrawCircle(eglib, x, y, radius) eglib_DrawArc(eglib, x, y, radius, 0, 360);

/**
 * Draw a filled arc with color from index 0
 *
 * :param x: Center x.
 * :param y: Center y.
 * :param radius: Radius.
 * :param start_angle: Start angle from 0 to 360, where 0 is "up" and 90 is "right".
 * :param end_angle: End angle, bigger than ``start_angle`` and less or equal to 360.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawFilledArc.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawFilledArc.png
 *   :width: 200
 */
void eglib_DrawFilledArc(
	eglib_t *eglib,
	coordinate_t x, coordinate_t y,
	coordinate_t radius,
	float start_angle,
	float end_angle
);

/**
 * Draw a filled arc with color gradient from index 0 at the center and index 1
 * at the radius.
 *
 * :param x: Center x.
 * :param y: Center y.
 * :param radius: Radius.
 * :param start_angle: Start angle from 0 to 360, where 0 is "up" and 90 is "right".
 * :param end_angle: End angle, bigger than ``start_angle`` and less or equal to 360.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawGradientFilledArc.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawGradientFilledArc.png
 *   :width: 200
 */
void eglib_DrawGradientFilledArc(
	eglib_t *eglib,
	coordinate_t x, coordinate_t y,
	coordinate_t radius,
	float start_angle,
	float end_angle
);

/**
 * Draw a disc with color from index 0
 *
 * :param x: Center x.
 * :param y: Center y.
 * :param radius: Radius.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawDisc.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawDisc.png
 *   :width: 200
 */
#define eglib_DrawDisc(eglib, x, y, radius) eglib_DrawFilledArc(eglib, x, y, radius, 0, 360)

/**
 * Draw a disc with color gradient from index 0 at the center and index 1 at the
 * radius.
 *
 * :param x: Center x.
 * :param y: Center y.
 * :param radius: Radius.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawGradientDisc.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawGradientDisc.png
 *   :width: 200
 */
#define eglib_DrawGradientDisc(eglib, x, y, radius) eglib_DrawGradientFilledArc(eglib, x, y, radius, 0, 360)

/**
 * Bitmaps
 * =======
 */

/**
 * Format of bitmap data.
 */
enum bitmap_format_t {
	/**
	 * 1 bit per pixel black and white.
	 *
	 * :Tip: this is the same data format as `XBM <https://en.wikipedia.org/wiki/X_BitMap>`_.
	 */
	BITMAP_BW,
	/** 8bit per channel RGB */
	BITMAP_RGB24,
};

/**
 * A bitmap definition.
 *
 * :See also: :c:func:`eglib_DrawBitmap`.
 */
struct bitmap_t {
	/** Width */
	coordinate_t width;
	/** Height */
	coordinate_t height;
	/** Data format */
	enum bitmap_format_t format;
	/** Pointer to bitmap data */
	uint8_t *data;
};

/**
 * Draw given bitmap at ``(x, y)``.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawBitmap.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawBitmap.png
 *   :width: 200
 */
void eglib_DrawBitmap(
	eglib_t *eglib,
	coordinate_t x,
	coordinate_t y,
	const struct bitmap_t *bitmap
);

#include "drawing/fonts.h"

/**
 * Text
 * ====
 */

/** A glyph from a :c:type:`font_t`. */
struct glyph_t {
	/** Bitmap width. */
	uint8_t width : 7;
	/** Bitmap height. */
	uint8_t height : 7;
	/** Left padding before bitmap. */
	int8_t left : 5;
	/** Distance to increment the pen position after rendering this glyph. */
	uint8_t advance : 7;
	/** Distance from baseline to glyph's highest pixel. */
	int8_t top : 7;
	/** Bitmap data. */
	uint8_t *data;
};

/**
 * A Font definition.
 */
struct font_t {
	/** Font pixel size. */
	uint8_t pixel_size;
	/** First unicode character code this font supports. */
	uint32_t charcode_start;
	/** Last unicode character code this font supports. */
	uint32_t charcode_end;
	/** Array of glyphs for each supported unicode character. */
	struct glyph_t **glyphs;
};

/**
 * Set font to be used by other font functions.
 *
 * :See also: :doc:`fonts`
 */
void eglib_SetFont(eglib_t *eglib, struct font_t *font);

/**
 * Return given unicode character's :c:type:`glyph_t`.
 */
struct glyph_t *eglib_GetGlyph(eglib_t *eglib, wchar_t unicode_char);

/**
 * Draw given :c:type:`glyph_t`, similar to :c:func:`eglib_DrawWChar`.
 */
void eglib_DrawGlyph(eglib_t *eglib, coordinate_t x, coordinate_t y, struct glyph_t *glyph);

/**
 * Draw given unicode character glyph at ``(x, y)``.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawWChar.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawWChar.png
 *   :width: 200
 */
void eglib_DrawWChar(eglib_t *eglib, coordinate_t x, coordinate_t y, wchar_t unicode_char);

/**
 * Draw given UTF-8 text starting at ``(x, y)``.
 *
 * Example:
 *
 * .. literalinclude:: ../../../tests/drawing/test_eglib_DrawText.c
 *   :language: C
 *
 * Output:
 *
 * .. image:: ../../../tests/drawing/test_eglib_DrawText.png
 *   :width: 200
 */
void eglib_DrawText(eglib_t *eglib, coordinate_t x, coordinate_t y, char *utf8_text);


#endif