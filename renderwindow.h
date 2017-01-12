#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include "eventhandler.h"
#include "renderarea.h"

#include <QWidget>
#include <QPushButton>

// The Window that holds the draw area & control buttons

class RenderWindow : public QWidget
{
   Q_OBJECT

public:
   RenderWindow(RenderArea *ra, EventHandler *evh);
   ~RenderWindow();

private:
   RenderArea *renderArea;
   EventHandler *evHandler;

   QPushButton *renderButton;

private slots:
   void handleRenderButton();

};

#endif // RENDER_WINDOW_H
