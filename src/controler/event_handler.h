#include <queue>
#include "event.h"
#include "../maplogic/map.h"


namespace POD {

enum Tool {
    PLACE_LAND,
    DELETE_LAND
};


class EventHandler {
    public:
        static void handleEvent(Map *map);
        static EventHandler getInstance();
    private:
        static EventHandler instance;
        std::queue<Event> queue;

        Tool tool;
        EventHandler();
};

}
