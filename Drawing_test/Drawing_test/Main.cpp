/******************************************************************************
 * Drawing.h
 * Testing the library for drawing pictures.
 *
 * (c) 2010-, Wolfgang Schreiner <Wolfgang.Schreiner@risc.jku.at>
 *****************************************************************************/
#include "Drawing.h"

#if defined(_WIN32) || defined (_WIN64)
#include <windows.h>
#else
#include <time.h>
static void Sleep(int ms)
{
  struct timespec ts;
  ts.tv_sec = ms/1000;
  ts.tv_nsec = (ms%1000)*1000000;
  nanosleep(&ts, NULL);
}
#endif

using namespace compsys;

const unsigned int BLACK = 0x000000;
const unsigned int WHITE = 0xFFFFFF;
const unsigned int ORANGE = 0xFFA000;
const unsigned int GREEN = 0x00FF00;
const unsigned int BLUE = 0x0000FF;

int main()
{
  beginDrawing(400, 300, "A Graphical Program");
     drawLine(20, 20, 220, 120);
   drawRectangle(20, 20, 200, 200, BLUE);
   fillRectangle(60, 60, 120, 120, BLUE);
   drawEllipse(21, 21, 198, 198, GREEN);
   fillEllipse (getWidth()/3, getHeight()*2/3, 500, 300, ORANGE);
   int xs[] = { 300, 350, 250 };
   int ys[] = { 20, 100, 100 };
   drawPolygon(3, xs, ys, GREEN);
   int xs0[] = { 300, 350, 250 };
   int ys0[] = { 100, 20, 20 };
   fillPolygon(3, xs0, ys0, WHITE, BLACK);
   drawText(10, 280, "My Picture");
   int w = getWidth();
   for (int i=0; i<w; i++)
   {
     drawPoint(i, 10);
     Sleep(5);
   }
  endDrawing();
}
