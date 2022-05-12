/******************************************************************************
 * Drawing.h
 * Interface to a small library for drawing pictures.
 *
 * (c) 2010-, Wolfgang Schreiner <Wolfgang.Schreiner@risc.jku.at>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/

#ifndef COMPSYS_DRAWING_H_
#define COMPSYS_DRAWING_H_

namespace compsys
{
  /***************************************************************************
   * The coordinate system is left to right and top to bottom, so for a
   * window of size width*height, the corners have the following coordinates:
   *
   * (0,0)       ... (width, 0)
   *   .                   .
   *   .                   .
   * (0, height) ... (width, height)
   *
   * Colors are unsigned 24 bit RGB values, so 0x000000 is black, 0xFFFFFF is
   * white, 0xFF000000 is red, 0x00FF00 is green, 0x0000FF is blue.
   *
   * The drawing functions support clipping, so drawing outside the
   * dimensions of the window is not harmful.
   **************************************************************************/

  // indicator for not a color
  const unsigned int NO_COLOR = 0x1000000;

  /***************************************************************************
   * beginDrawing(width, height, title, color, flush)
   * Open a window of size width*height with title and background color
   * (default white) and output flush potentially enabled (default yes).
   *
   * Must be called before calling one of the drawing functions. Must not be
   * called twice, unless endDrawing() is called before the second call.
   * If output flush is enabled, the effect of every drawing operation is
   * immediately  visible (otherwise only when flush() or endDrawing()
   * is called).
   *
   * Precondition: width and height must be non-negative;
   *               title must not be NULL.
   **************************************************************************/
  void beginDrawing(int width, int height, const char *title,
                    unsigned int color = 0xFFFFFF, bool flush = true);

  /***************************************************************************
   * endDrawing()
   * Makes the effect of all drawing operations visible and waits until the
   * user closes the window previously created by endDrawing().
   *
   * May be called only after a previous call of beginDrawing(). Must not be
   * called twice unless beginDrawing() is called before the second call.
   **************************************************************************/
  void endDrawing();

  /***************************************************************************
   * flush()
   * Flush any pending drawing output to the screen.
   *
   * May be called only after a previous call of beginDrawing().
   **************************************************************************/
  void flush();

  /***************************************************************************
   * w = getWidth()
   * Get width w of current image.
   *
   * May be called only after a previous call of beginDrawing().
   **************************************************************************/
  int getWidth();

  /***************************************************************************
   * h = getHeight()
   * Get height h of current image.
   *
   * May be called only after a previous call of beginDrawing().
   **************************************************************************/
  int getHeight();

  /**************************************************************************
   * drawPoint(x, y, color)
   * Draws a point at position x,y in the denoted color (default black).
   *
   * May be called only after a call of beginDrawing().
   *************************************************************************/
  void drawPoint(int x, int y, unsigned int color = 0);

  /**************************************************************************
   * drawLine(x0, y0, x1, y1, color)
   * Draws a line from x0,y0 to x1,y1 in the denoted color (default black).
   *
   * May be called only after a call of beginDrawing().
   *************************************************************************/
  void drawLine(int x0, int y0, int x1, int y1, unsigned int color = 0);

  /**************************************************************************
   * drawRectangle(x, y, w, h, color)
   * Draws an outlined rectangle with left upper corner at position x,y
   * and dimension w*h in the denoted color (default black).
   *
   * May be called only after a call of beginDrawing().
   *************************************************************************/
  void drawRectangle(int x, int y, int w, int h, unsigned int color = 0);

  /**************************************************************************
   * fillRectangle(x, y, w, h, fcolor, ocolor)
   * Draws an fill rectangle with left upper corner at position x,y
   * and dimension w*h in the denoted fill color (default black)
   * and outline color (default no outline).
   *
   * May be called only after a call of beginDrawing().
   *************************************************************************/
  void fillRectangle(int x, int y, int w, int h,
                     unsigned int fcolor = 0, unsigned int ocolor = NO_COLOR);

  /**************************************************************************
   * drawEllipse(x, y, w, h, color)
   * Draws an outlined ellipse whose bounding rectangle has left upper corner
   * at position x,y and dimension w*h in the denoted color (default black).
   *
   * May be called only after a call of beginDrawing().
   *************************************************************************/
  void drawEllipse(int x, int y, int w, int h, unsigned int color = 0);

  /**************************************************************************
   * fillEllipse(x, y, w, h, fcolor, ocolor)
   * Draws a filled ellipse whose bounding rectangle has left upper corner
   * at position x,y and dimension w*h in the denoted fill color
   * (default black) and outline color (default no outline).
   *
   * May be called only after a call of beginDrawing().
   *************************************************************************/
  void fillEllipse(int x, int y, int w, int h,
                   unsigned int fcolor = 0, unsigned int ocolor = NO_COLOR);

  /**************************************************************************
   * drawPolygon(n, xs, ys, color)
   * Draws an outlined closed polygon with n points at position xs[i], ys[i]
   * in the denoted color (default black).
   *
   * May be called only after a call of beginDrawing().
   *************************************************************************/
  void drawPolygon(int n, int* xs, int *ys, unsigned int color = 0);

  /**************************************************************************
   * fillPolygon(n, xs, ys, fcolor, ocolor)
   * Draws a filled closed polygon with n points at position xs[i], ys[i] in
   * the denoted fill color (default black) and outline color (default none).
   *
   * May be called only after a call of beginDrawing().
   *************************************************************************/
  void fillPolygon(int n, int* xs, int *ys,
                   unsigned int fcolor = 0, unsigned int ocolor = NO_COLOR);

  /**************************************************************************
   * drawText(x, y, text, size, color)
   * Draw text whose left upper corner has position x,y in denoted size
   * (default 14) and color (default black).
   *
   * May be called only after a call of beginDrawing().
   *************************************************************************/
  void drawText(int x, int y, const char *text,
                int size = 14, unsigned int color = 0);
}

#endif /* COMPSYS_DRAWING_H_ */
