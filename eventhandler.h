#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <string>

class EventHandler
{
public:
   virtual void handleEvent(std::string eventType) = 0;

};

#endif // EVENTHANDLER_H
