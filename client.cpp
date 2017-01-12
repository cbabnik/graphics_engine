// Author:
// Curtis Babnik
// cbabnik@sfu.ca
// 301235515

#include "client.h"

#include <cstdlib>
#include <cstdio>

// Construction
Client::Client(RenderArea *ra) {
   this->renderArea = ra;
}
Client::~Client(){

}

// Responding to events
void Client::handleEvent(std::string eventType) {

   if( eventType.compare( "renderClicked" ) == 0 )
      // placeholder -> set some pixels red
      for(int i = 0; i < 100; i++)
         for(int j = 0; j < 100; j++)
            renderArea->setPixel(i,j,0xff0000);

   renderArea->updateScreen();
}
