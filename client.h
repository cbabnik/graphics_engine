#ifndef CLIENT_H
#define CLIENT_H

#include "eventhandler.h"
#include "renderarea.h"
#include "renderer.h"

#include <string>

class Client : public EventHandler
{
public:
   Client(RenderArea *ra);
   ~Client();

   void handleEvent(std::string eventType);

private:
   Renderer *renderer;

};

#endif // CLIENT_H
