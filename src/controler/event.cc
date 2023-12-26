#include "event.h"
namespace POD {

    Event::Event(){
        this->x = -1;
        this->y = -1;
        this->land_type_id = 0;
        this->type_event = PLACING;
    }
    Event::Event(int x, int y, u_int8_t land_type_id, bool is_placing){
        this->x = x;
        this->y = y;
        this->land_type_id = land_type_id;
        if (is_placing){
            this->type_event = PLACING;
        } else {
            this->type_event = REMOVING;
        }
    
    }
    Event::Event(int x, int y, TYPE_EVENT type_event){
        this->x = x;
        this->y = y;
        this->land_type_id = 1;
        this->type_event = type_event;
    }
    int Event::getX(){
        return this->x;
    }
    int Event::getY(){
        return this->y;
    }
    u_int8_t Event::getLandTypeId(){
        return this->land_type_id;
    }
    TYPE_EVENT Event::getType(){
        return this->type_event;
    }
}