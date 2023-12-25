#include "event_handler.h"

namespace POD {

    POD::EventHandler::EventHandler() {
        this->tool = Tool::PLACE_LAND;
    }


    void EventHandler::handleEvent(Map *map) {
        POD::Event event = instance.queue.front();
        instance.queue.pop();

        switch (event.getType()) {
            case PLACING:
                map->placeLand(event.getX(), event.getY(), event.getLandTypeId());
                break;
            case REMOVING:
                map->deleteLand(event.getX(), event.getY());
                break;
            default:
                break;
        }
    }

    EventHandler EventHandler::getInstance() {
        instance = EventHandler();
        return instance;
    }
    
}
