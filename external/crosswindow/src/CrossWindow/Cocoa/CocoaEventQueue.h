#pragma once

#include "../Common/Event.h"
#include "../Common/Init.h"
#include <queue>

namespace xwin
{
    struct MacEvent
    {

    };

    /**
     * 
     * Events - https://developer.apple.com/documentation/appkit/nsevent
     */ 
    class MacOSEventQueue
    {
    public:
        void update();

        const Event &front();

        void pop();

        bool empty();

    protected:
        void pushEvent(MacEvent me);

        std::queue<Event> mQueue;
    };

    typedef MacOSEventQueue EventQueueDelegate;
}
