#ifndef RENDER_AREA_H
#define RENDER_AREA_H

#include <QWidget>

// The draw region. Provides the low-level functions "setPixel" and "getPixel"

class RenderArea : public QWidget
{
   Q_OBJECT

public:
   const static int PICTURE_SIZE = 800;

   RenderArea();

   void setPixel(int x, int y, uint color);
   uint getPixel(int x, int y) const;
   void updateScreen();

protected:
   void paintEvent(QPaintEvent*);

private:
   QImage image;

};

#endif // RENDER_AREA_H
