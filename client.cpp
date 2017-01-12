// Author:
// Curtis Babnik
// cbabnik@sfu.ca
// 301235515

#include "client.h"

#include <cstdlib>
#include <cstdio>

// Construction
Client::Client(RenderArea *ra) {
   this->renderer = new Renderer(ra);
}
Client::~Client(){
   delete renderer;
}

// Responding to events
void Client::handleEvent(std::string eventType) {

   uint color = 0xff0000;

   if( eventType.compare( "renderClicked" ) == 0 )
      // placeholder -> set some pixels red
      for(int i = 0; i < 100; i++)
         for(int j = 0; j < 100; j++)
            renderer->draw_pixel(i,j,color);

   renderer->update();
}
