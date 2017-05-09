#ifndef LINE_RENDERER_H
#define LINE_RENDERER_H

#include "renderer.h"
#include "resources.h"

class LineRenderer : public Renderer
{
public:
   LineRenderer(RenderArea* ra) : Renderer(ra) { };
   // transforms (x,y) co-ordinate to octant 1 before applying algorithm
   void draw_line(Point2D p1, Point2D p2, Color color=Color::WHITE);
   void draw_line(Point2D p1, Point2D p2, Color color1, Color color2);
   void draw_line(Point3D p1, Point3D p2);
   void draw_line(Point3D p1, Point3D p2, Color color1, Color color2);

private:
   // sorts points by x and returns whether they were resorted
   bool sortPoints(Point2D& p1, Point2D& p2);
   bool sortPoints(Point3D& p1, Point3D& p2);
   // returns the octant transformed from
   unsigned char transformOctant(Point2D& p1, Point2D& p2);
   unsigned char transformOctant(Point3D& p1, Point3D& p2);
   // reverses octant transformation before setting pixel
   void setPixel(int x, int y, Color color, unsigned char octant);
   void setPixel(int x, int y, int z, unsigned char octant);
   void setPixel(int x, int y, int z, Color color, unsigned char octant);
};

#endif // LINE_RENDERER_H
