#include "renderwindow.h"

#include <QGridLayout>

// This implementation is kept simple purposely.
// It will serve as a primitive basepoint to build a graphics engine upon.

// Construction
RenderWindow::RenderWindow(RenderArea *ra, EventHandler *evh){

   this->renderArea = ra;
   this->evHandler = evh;

   // create components
   renderButton = new QPushButton("render");
   connect( renderButton, SIGNAL(clicked()), this, SLOT(handleRenderButton()) );

   // setup layout
   QGridLayout *layout = new QGridLayout;
   layout->addWidget(renderArea, 0, 0);
   layout->addWidget(renderButton, 0, 1);
   setLayout(layout);

   setWindowTitle("Graphics Display Window");
}
RenderWindow::~RenderWindow() {
   delete renderArea;
   delete renderButton;
}

// Event handlers
void RenderWindow::handleRenderButton() {
   if( evHandler ) evHandler->handleEvent("renderClicked");
}

