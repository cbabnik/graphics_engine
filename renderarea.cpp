#include "renderarea.h"

#include <QImage>
#include <QPainter>
#include <QPaintEvent>

// This implementation is kept simple purposely.
// It will serve as a primitive basepoint to build a graphics engine upon.

// Construction
RenderArea::RenderArea() :QWidget((QWidget *)0) {

   setFixedSize(PICTURE_SIZE, PICTURE_SIZE);

   image = QImage(PICTURE_SIZE, PICTURE_SIZE, QImage::Format_RGB888);
   image.fill(0xaaaaaa);

   this->update();
}

// Drawing functions
void RenderArea::setPixel(int x, int y, uint color) {
   image.setPixel(x, y, color);
}
uint RenderArea::getPixel(int x, int y) const {
   return (uint)(image.pixel(x, y));
}
void RenderArea::updateScreen() {
   this->update();
}
void RenderArea::paintEvent(QPaintEvent*) {
   QPainter painter(this);
   painter.drawImage(0, 0, image);
}

