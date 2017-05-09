
// Line renderer implementation using bresenham's algorithm

#include "linerenderer.h"
#include <cmath>

void LineRenderer::draw_line(Point2D p1, Point2D p2, Color color /*white*/ ){
   unsigned char octant = transformOctant( p1, p2 );

   int dx = p2.x - p1.x;
   int two_dx = 2*dx;
   int two_dy = 2*(p2.y - p1.y);
   int t2 = two_dy - two_dx;

   int err = two_dy-dx;      // to determine rounding
   int y = p1.y;
   setPixel(p1.x, p1.y, color, octant);
   for( int x = p1.x+1; x <= p2.x; x++ ){
      if( err >= 0 ){        // if rounded would be at next y value
         err = err + t2;     // add the slope but subtract 1
         y++;
      }
      else
         err = err + two_dy; // add the slope
      setPixel(x, y, color, octant);
   }
}
void LineRenderer::draw_line(Point2D p1, Point2D p2, Color color1, Color color2){
   if( sortPoints( p1, p2 ) ){
      Color swap = color1;
      color1 = color2;
      color2 = swap;
   }
   unsigned char octant = transformOctant( p1, p2 );

   int dx = p2.x - p1.x;
   if(dx==0) // condition for line to be too small to draw
      return;
   int two_dx = 2*dx;

   int two_dy = 2*(p2.y - p1.y);
   int t2_y = two_dy - two_dx;
   int err_y = two_dy-dx; // to determine rounding
   int y = p1.y;

   // loop for red, green, blue
   int dcc[3], ppcc[3], rcc[3], two_rcc[3], t2_cc[3], err_cc[3];
   for( int i = 0; i < 3; i++ ){
      dcc[i] = (color2[i] - color1[i]);
      ppcc[i] = floor( float(dcc[i]) / dx );
      rcc[i] = (dcc[i] >= 0) ? (dcc[i] % dx) : (dcc[i] % dx) + dx;
      two_rcc[i] = 2*rcc[i];
      t2_cc[i] = two_rcc[i] - two_dx;
      err_cc[i] = two_rcc[i] - dx;
   }
   Color color = color1;
   int ppc = ppcc[0]*0x10000 + ppcc[1]*0x100 + ppcc[2];

   // draw line
   setPixel(p1.x, p1.y, color1, octant);
   for( int x = p1.x+1; x <= p2.x; x++ ){
      // handle y
      if( err_y >= 0 ){          // if rounded would be at next y value
         err_y = err_y + t2_y;   // add the slope but subtract 1
         y++;
      }
      else
         err_y = err_y + two_dy; // add the slope
      // handle color the same way as y ( but add the per pixel val)
      color.color += ppc;
      for( int i = 0; i < 3; i++ ){
         if( err_cc[i] >= 0 ){
            err_cc[i] += t2_cc[i];
            color[i]++;
         }
         else
            err_cc[i] += two_rcc[i];
      }
      setPixel(x, y, color, octant);
   }
}
void LineRenderer::draw_line(Point3D p1, Point3D p2){
   unsigned char octant = transformOctant( p1, p2 );

   // intermediates ( math modulo to find remainder)
   int dx = p2.x - p1.x;
   if(dx==0) // condition for line to exist
      return;
   int dz = (p2.z - p1.z);
   int rz = dz >= 0 ? (dz % dx) : (dz % dx) + dx;

   // constants
   int two_dx = 2*dx;

   int two_dy = 2*(p2.y - p1.y);
   int t2_y = two_dy - two_dx;

   int ppz = floor( float(dz)/dx ); // per pixel z
   int two_rz = 2*rz;               // twice remainder z
   int t2_z = two_rz - two_dx;

   // variables
   int err_y = two_dy-dx; // to determine rounding
   int err_z = two_rz-dx;
   int y = p1.y;
   int z = p1.z;

   // draw line
   setPixel(p1.x, p1.y, p1.z, octant);
   for( int x = p1.x+1; x <= p2.x; x++ ){
      // handle y
      if( err_y >= 0 ){          // if rounded would be at next y value
         err_y = err_y + t2_y;   // add the slope but subtract 1
         y++;
      }
      else
         err_y = err_y + two_dy; // add the slope
      // handle z the same as y (but add per pixel value)
      z += ppz;
      if( err_z >= 0 ){
         err_z = err_z + t2_z;
         z++;
      }
      else
         err_z = err_z + two_rz;

      setPixel(x, y, z, octant);
   }
}
void LineRenderer::draw_line(Point3D p1, Point3D p2, Color color1, Color color2){
   if( sortPoints( p1, p2 ) ){
      Color swap = color1;
      color1 = color2;
      color2 = swap;
   }
   unsigned char octant = transformOctant( p1, p2 );

   // intermediates ( math modulo to find remainder)
   int dx = p2.x - p1.x;
   if(dx==0) // condition for line to exist
      return;
   int dz = (p2.z - p1.z);
   int rz = dz >= 0 ? (dz % dx) : (dz % dx) + dx;

   // constants
   int two_dx = 2*dx;

   int two_dy = 2*(p2.y - p1.y);
   int t2_y = two_dy - two_dx;

   int ppz = floor( float(dz)/dx ); // per pixel z
   int two_rz = 2*rz;               // twice remainder z
   int t2_z = two_rz - two_dx;

   // variables
   int err_y = two_dy-dx; // to determine rounding
   int err_z = two_rz-dx;
   int y = p1.y;
   int z = p1.z;

   // loop for red, green, blue
   int dcc[3], ppcc[3], rcc[3], two_rcc[3], t2_cc[3], err_cc[3];
   for( int i = 0; i < 3; i++ ){
      dcc[i] = (color2[i] - color1[i]);
      ppcc[i] = floor( float(dcc[i]) / dx );
      rcc[i] = (dcc[i] >= 0) ? (dcc[i] % dx) : (dcc[i] % dx) + dx;
      two_rcc[i] = 2*rcc[i];
      t2_cc[i] = two_rcc[i] - two_dx;
      err_cc[i] = two_rcc[i] - dx;
   }
   Color color = color1;
   int ppc = ppcc[0]*0x10000 + ppcc[1]*0x100 + ppcc[2];

   // draw line
   setPixel(p1.x, p1.y, p1.z, octant);
   for( int x = p1.x+1; x <= p2.x; x++ ){
      // handle y
      if( err_y >= 0 ){          // if rounded would be at next y value
         err_y = err_y + t2_y;   // add the slope but subtract 1
         y++;
      }
      else
         err_y = err_y + two_dy; // add the slope
      // handle z the same as y (but add per pixel value)
      z += ppz;
      if( err_z >= 0 ){
         err_z = err_z + t2_z;
         z++;
      }
      else
         err_z = err_z + two_rz;
      // handle color the same way as y ( but add the per pixel val)
      color.color += ppc;
      for( int i = 0; i < 3; i++ ){
         if( err_cc[i] >= 0 ){
            err_cc[i] += t2_cc[i];
            color[i]++;
         }
         else
            err_cc[i] += two_rcc[i];
      }

      setPixel(x, y, z, color, octant);
   }

}

// sorts points by x and returns whether they were resorted
bool LineRenderer::sortPoints(Point2D& p1, Point2D& p2){
   // octants 1-4 to be below the x axis, 3-6 left of y axis
   if( p1.x > p2.x ) // octants 3,4,5,6
   {
      // convert octants 3,4,5,6 to 7,8,1,2 respectively by swapping p1 and p2
      Point2D swapP = p1;
      p1 = p2;
      p2 = swapP;
      return true;
   }
   return false;
}
bool LineRenderer::sortPoints(Point3D& p1, Point3D& p2){
   // octants 1-4 to be below the x axis, 3-6 left of y axis
   if( p1.x > p2.x ) // octants 3,4,5,6
   {
      // convert octants 3,4,5,6 to 7,8,1,2 respectively by swapping p1 and p2
      Point3D swapP = p1;
      p1 = p2;
      p2 = swapP;
      return true;
   }
   return false;

}
// returns the octant transformed from
unsigned char LineRenderer::transformOctant(Point2D& p1, Point2D& p2){
   sortPoints(p1, p2);
   if( p1.y <= p2.y ) // octants 1,2
   {
      if( p2.x-p1.x >= p2.y-p1.y )
         return 1;
      else{
         p1 = Point2D(p1.y, p1.x);
         p2 = Point2D(p2.y, p2.x);
         return 2;
      }
   }
   else // octants 7,8
   {
      if( p2.x - p1.x >= p1.y - p2.y ){
         p1 = Point2D(p1.x, -p1.y);
         p2 = Point2D(p2.x, -p2.y);
         return 8;
      }
      else{
         p1 = Point2D(-p1.y, p1.x);
         p2 = Point2D(-p2.y, p2.x);
         return 7;
      }
   }
}
unsigned char LineRenderer::transformOctant(Point3D& p1, Point3D& p2){
   sortPoints(p1, p2);
   if( p1.y <= p2.y ) // octants 1,2
   {
      if( p2.x-p1.x >= p2.y-p1.y )
         return 1;
      else{
         p1 = Point3D(p1.y, p1.x, p1.z);
         p2 = Point3D(p2.y, p2.x, p2.z);
         return 2;
      }
   }
   else // octants 7,8
   {
      if( p2.x - p1.x >= p1.y - p2.y ){
         p1 = Point3D(p1.x, -p1.y, p1.z);
         p2 = Point3D(p2.x, -p2.y, p2.z);
         return 8;
      }
      else{
         p1 = Point3D(-p1.y, p1.x, p1.z);
         p2 = Point3D(-p2.y, p2.x, p2.z);
         return 7;
      }
   }
}
// reverses octant transformation before setting pixel
void LineRenderer::setPixel(int x, int y, int z, unsigned char octant){
   switch( octant )
   {
   case 1:
      draw_pixel(x, y, z);
      break;
   case 2:
      draw_pixel(y, x, z);
      break;
   case 7:
      draw_pixel(y, -x, z);
      break;
   case 8:
      draw_pixel(x, -y, z);
      break;
   default:
      throw "Unrecognized octant";
   }
}
void LineRenderer::setPixel(int x, int y, Color color, unsigned char octant){
   switch( octant )
   {
   case 1:
      draw_pixel(x, y, color.color);
      break;
   case 2:
      draw_pixel(y, x, color.color);
      break;
   case 7:
      draw_pixel(y, -x, color.color);
      break;
   case 8:
      draw_pixel(x, -y, color.color);
      break;
   default:
      throw "Unrecognized octant";
   }
}
void LineRenderer::setPixel(int x, int y, int z, Color color, unsigned char octant){
   switch( octant )
   {
   case 1:
      draw_pixel(x, y, z, color.color);
      break;
   case 2:
      draw_pixel(y, x, z, color.color);
      break;
   case 7:
      draw_pixel(y, -x, z, color.color);
      break;
   case 8:
      draw_pixel(x, -y, z, color.color);
      break;
   default:
      throw "Unrecognized octant";
   }
}
