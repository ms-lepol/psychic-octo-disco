#include "event_handler.h"

namespace POD {

    POD::EventHandler::EventHandler() {
        this->tool = Tool::PLACE_LAND;
    }

    void EventHandler::pushEvent(Event event) {
        getInstance().queue.push(event);
    }


    void EventHandler::handleEvent(Map *map) {
        POD::Event event = POD::EventHandler::getInstance().queue.front();
        getInstance().queue.pop();

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

    EventHandler& EventHandler::getInstance() {
        static EventHandler instance;
        return instance;
    }
    
}
