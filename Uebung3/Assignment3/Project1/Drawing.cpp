/******************************************************************************
 * Drawing.cpp
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

// download from http://cimg.sourceforge.net
#include "CImg.h"

/*****************************************************************************
 * See the CImg documentation section 6.1.3 "How to compile?"
 * http://cimg.sourceforge.net/reference/group__cimg__overview.html
 *
 * For compiling, the header file "CImg.h" must be visible
 * (compiler option "-I <PATH>" if "Cimg.h" is installed in <PATH>).
 *
 * For linking, additional standard libraries may be needed:
 * - Linux and MacOS X: the libraries "X11" and "pthread".
 * - MS Windows: the library "gdi32".
 * (linker option "-lX11 -lXpthread" respectively "-lgdi32").
 *
 * Eclipse C++ on Linux and MacOS X: create "C++" project
 * - project "Properties" -> "C/C++ General" -> "Paths and Symbols"
 * - tab "Includes" -> "Languages: GNU C++" -> "Include directories"
 *   -> "Add" directory where "Cimg.h" is installed.
 * - tab "Libraries" -> "Add" X11 -> "Add" pthread.
 *
 * MS Visual C++ 2010: create "win32 console application" project
 * - project "Properties" -> "C/C++ General"
 * - row "Additional Include Directories"
 *   -> Add directory where "Cimg.h" is installed.
 * - "gdi32" is automatically linked.
*****************************************************************************/

#include <iostream>
#include "Drawing.h"

using namespace std;
using namespace cimg_library;

namespace compsys
{
  // a color component
  typedef unsigned char Color;

  // the image and the display
  static CImg<Color> *image = NULL;
  static CImgDisplay *display = NULL;
  static bool flushing = false;

  // conditionally flush output
  static void flush0()
  {
    if (flushing) display->display(*image);
  }

  // check for initialization
  static void checkImage(const char *call)
  {
    if (image != NULL) return;
    cout << "ERROR: " << call << "() is called without previous call of beginDrawing()" << endl;
    cout << "Program is aborted." << endl;
    exit(-1);
  }

  // translate color code to color structure
  // always returns address of carray
  static Color carray[3];
  static Color* getColor(unsigned int color)
  {
    carray[0] = (color >> 16) & 0xFF;
    carray[1] = (color >> 8) & 0xFF;
    carray[2] = color & 0xFF;
    return carray;
  }

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
      unsigned int color, bool flush)
  {
    if (image != NULL)
    {
      cout << "ERROR: beginDrawing() is called twice in sequence.";
      cout << "Program is aborted.";
      exit(-1);
    }
    image = new CImg<Color>(width, height, 1, 3);
    image->draw_rectangle(0, 0, width, height, getColor(color));
    display = new CImgDisplay(*image, title);
    flushing = flush;
  }

  /***************************************************************************
   * endDrawing()
   * Makes the effect of all drawing operations visible and waits until the
   * user closes the window previously created by endDrawing().
   *
   * May be called only after a previous call of beginDrawing(). Must not be
   * called twice unless beginDrawing() is called before the second call.
   **************************************************************************/
  void endDrawing()
  {
    checkImage("endDrawing");
    display->display(*image);
    while (!display->is_closed()) { display->wait(); }
    delete image;
    delete display;
    image = NULL;
    display = NULL;
    flushing = false;
  }

  /***************************************************************************
   * flush()
   * Flush any pending drawing output to the screen.
   *
   * May be called only after a previous call of beginDrawing().
   **************************************************************************/
  void flush()
  {
    checkImage("flush");
    display->display(*image);
  }

  /***************************************************************************
   * w = getWidth()
   * Get width w of current image.
   *
   * May be called only after a previous call of beginDrawing().
   **************************************************************************/
  int getWidth()
  {
    checkImage("getWidth");
    return image->width();
  }

  /***************************************************************************
   * h = getHeight()
   * Get height h of current image.
   *
   * May be called only after a previous call of beginDrawing().
   **************************************************************************/
  int getHeight()
  {
    checkImage("getHeight");
    return image->height();
  }

  /**************************************************************************
   * drawPoint(x, y, color)
   * Draws a point at position x,y in the denoted color (default black).
   *
   * May be called only after a call of beginDrawing().
   *************************************************************************/
  void drawPoint(int x, int y, unsigned int color)
  {
    checkImage("drawPoint");
    image->draw_point(x, y, getColor(color));
    flush0();
  }

  /**************************************************************************
   * drawLine(x0, y0, x1, y1, color)
   * Draws a line from x0,y0 to x1,y1 in the denoted color (default black).
   *
   * May be called only after a call of beginDrawing().
   *************************************************************************/
  void drawLine(int x0, int y0, int x1, int y1, unsigned int color)
  {
    checkImage("drawLine");
    image->draw_line(x0, y0, x1, y1, getColor(color));
    flush0();
  }

  /**************************************************************************
   * drawRectangle(x, y, w, h, color)
   * Draws an outlined rectangle with left upper corner at position x,y
   * and dimension w*h in the denoted color (default black).
   *
   * May be called only after a call of beginDrawing().
   *************************************************************************/
  void drawRectangle(int x, int y, int w, int h, unsigned int color)
  {
    checkImage("drawRectangle");
    Color* color0 = getColor(color);
    image->draw_line(x, y, x+w, y, color0);
    image->draw_line(x+w, y, x+w, y+h, color0);
    image->draw_line(x+w, y+h, x, y+h, color0);
    image->draw_line(x, y+h, x, y, color0);
    flush0();
  }

  /**************************************************************************
   * fillRectangle(x, y, w, h, fcolor, ocolor)
   * Draws an fill rectangle with left upper corner at position x,y
   * and dimension w*h in the denoted fill color (default black)
   * and outline color (default no outline).
   *
   * May be called only after a call of beginDrawing().
   *************************************************************************/
  void fillRectangle(int x, int y, int w, int h,
      unsigned int fcolor, unsigned int ocolor)
  {
    checkImage("fillRectangle");
    image->draw_rectangle(x, y, x+w, y+h, getColor(fcolor));
    if (ocolor != NO_COLOR) drawRectangle(x, y, w, h, ocolor);
    flush0();
  }

  /**************************************************************************
   * drawEllipse(x, y, w, h, color)
   * Draws an outlined ellipse whose bounding rectangle has left upper corner
   * at position x,y and dimension w*h in the denoted color (default black).
   *
   * May be called only after a call of beginDrawing().
   *************************************************************************/
  void drawEllipse(int x, int y, int w, int h, unsigned int color)
  {
    checkImage("drawEllipse");
    int w0 = w/2;
    int h0 = h/2;
    image->draw_ellipse(x+w0, y+h0, w0, h0, 0, getColor(color), 1, 1);
    flush0();
  }

  /**************************************************************************
   * fillEllipse(x, y, w, h, fcolor, ocolor)
   * Draws a filled ellipse whose bounding rectangle has left upper corner
   * at position x,y and dimension w*h in the denoted fill color
   * (default black) and outline color (default no outline).
   *
   * May be called only after a call of beginDrawing().
   *************************************************************************/
  void fillEllipse(int x, int y, int w, int h,
      unsigned int fcolor, unsigned int ocolor)
  {
    checkImage("fillEllipse");
    int w0 = w/2;
    int h0 = h/2;
    image->draw_ellipse(x+w0, y+h0, w0, h0, 0, getColor(fcolor));
    if (ocolor != NO_COLOR) drawEllipse(x, y, w, h, ocolor);
    flush0();
  }

  /**************************************************************************
   * drawPolygon(n, xs, ys, color)
   * Draws an outlined closed polygon with n points at position xs[i], ys[i]
   * in the denoted color (default black).
   *
   * May be called only after a call of beginDrawing().
   *************************************************************************/
  void drawPolygon(int n, int* xs, int *ys, unsigned int color)
  {
    checkImage("drawPolygon");
    Color* color0 = getColor(color);
    for (int i=0; i<n-1; i++)
    {
      image->draw_line(xs[i], ys[i], xs[i+1], ys[i+1], color0);
    }
    if (n > 0)
      image->draw_line(xs[n-1], ys[n-1], xs[0], ys[0], color0);
    flush0();
  }

  /**************************************************************************
   * fillPolygon(n, xs, ys, fcolor, ocolor)
   * Draws a filled closed polygon with n points at position xs[i], ys[i] in
   * the denoted fill color (default black) and outline color (default none).
   *
   * May be called only after a call of beginDrawing().
   *************************************************************************/
  void fillPolygon(int n, int* xs, int *ys,
      unsigned int fcolor, unsigned int ocolor)
  {
    checkImage("fillPolygon");
    CImg<int> npoints(n, 2);
    for (int i=0; i<n; i++)
    {
      npoints(i, 0) = xs[i];
      npoints(i, 1) = ys[i];
    }
    image->draw_polygon(npoints, getColor(fcolor));
    if (ocolor != NO_COLOR) drawPolygon(n, xs, ys, ocolor);
    flush0();
  }

  /**************************************************************************
   * drawText(x, y, text, size, color)
   * Draw text whose left upper corner has position x,y in denoted size
   * (default 14) and color (default black).
   *
   * May be called only after a call of beginDrawing().
   *************************************************************************/
  void drawText(int x, int y, const char *text,
                int size, unsigned int color)
  {
    checkImage("drawText");
    image->draw_text(x, y, text, getColor(color), 0, 1, size);
    flush0();
  }
}
