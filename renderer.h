#ifndef RENDERER_H
#define RENDERER_H

#include "renderarea.h"
#include "resources.h"

// A renderer base class wrapper for all drawing functions
// Accomplishes 3-D with depth cueing and z-buffer

class Renderer
{
public:
   Renderer(RenderArea *ra);
   Renderer(RenderArea *ra, int xMin, int yMin, int zMin, int width, int height,
            int depth);
   ~Renderer();
   // draw ( Wrapper adds pixel clipping and zBuffer support )
   //    returns true if pixel is successfully drawn
   bool draw_pixel(int x, int y, int z);
   bool draw_pixel(int x, int y, int z, uint color);
   bool draw_pixel(int x, int y, uint color);
   // get pixel color
   uint get_color(int x, int y) const;
   // updateScreen wrapper. So we don't need to keep a reference to renderArea
   void update();

protected:
   int xMin, xMax;
   int yMin, yMax;
   int zMin, zMax;

   Outcode outcode(int x, int y);
   Outcode outcode(int x, int y, int z);

private:
   uint *colorByDepth;
   int *zBuffer;

   RenderArea *renderArea;

};

#endif // RENDERER_H
