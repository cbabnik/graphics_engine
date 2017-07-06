#include "renderer.h"

Renderer::Renderer(RenderArea *ra)
   :Renderer(ra, 0, 0, 0, RenderArea::PICTURE_SIZE, RenderArea::PICTURE_SIZE, 100) {}
Renderer::Renderer(RenderArea *ra, int xMin, int yMin, int zMin, int width,
                   int height, int depth){
   this->renderArea = ra;

   this->xMin = xMin;
   this->yMin = yMin;
   this->zMin = zMin;
   this->xMax = xMin+width;
   this->yMax = yMin+height;
   this->zMax = zMin+depth;

   this->zBuffer = new int[(width+1)*(height+1)];
   this->colorByDepth = new uint[depth+1];

   for(int i = 0; i < (width+1)*(height+1); i++)
      zBuffer[i] = zMax;
   for(int i = 0; i < depth+1; i++)
      colorByDepth[i] = 0x00ff00;
}
Renderer::~Renderer(){
   delete[] zBuffer;
   delete[] colorByDepth;
}

bool Renderer::draw_pixel(int x, int y, int z){
   if( z < zMin || z > zMax )
      return false;
   return draw_pixel(x, y, z, colorByDepth[ z - zMin ]);
}
bool Renderer::draw_pixel(int x, int y, int z, uint color){
   if( x < xMin || x > xMax )
      return false;
   if( y < yMin || y > yMax )
      return false;
   if( z < zMin || z > zMax )
      return false;
   if( zBuffer[x + y*(xMax-xMin+1)] < z )
      return false;
   zBuffer[x + y*(xMax-xMin+1)] = z;
   renderArea->setPixel(x, y, color);
   return true;
}
bool Renderer::draw_pixel(int x, int y, uint color){
   if( x < xMin || x > xMax )
      return false;
   if( y < yMin || y > yMax )
      return false;
   renderArea->setPixel(x, y, color);
   return true;
}

uint Renderer::get_color(int x, int y) const{
   if( x < xMin || x > xMax )
      return 0;
   if( y < yMin || y > yMax )
      return 0;
   return renderArea->getPixel(x, y);
}

void Renderer::update(){
   renderArea->updateScreen();
}

Outcode Renderer::outcode(int x, int y){
   Outcode o;
   o.out.left  = x < xMin;
   o.out.right = x > xMax;
   o.out.top   = y < yMin;
   o.out.bottom= y > yMax;
   return o;
}
Outcode Renderer::outcode(int x, int y, int z){
   Outcode o;
   o.out.left  = x < xMin;
   o.out.right = x > xMax;
   o.out.top   = y < yMin;
   o.out.bottom= y > yMax;
   o.out.front = z < zMin;
   o.out.back  = z > zMax;
   return o;
}
