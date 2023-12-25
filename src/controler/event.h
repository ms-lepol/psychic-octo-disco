#include <sys/types.h>
namespace POD {
   
enum TYPE_EVENT {
    PLACING,
    REMOVING
};

class Event {
    private:
        int x;
        int y;
        u_int8_t land_type_id;
        TYPE_EVENT type_event;
    public:
        Event();
        Event(int x, int y, u_int8_t land_type_id, bool is_placing);
        Event(int x, int y, TYPE_EVENT type_event);
        int getX();
        int getY();
        u_int8_t getLandTypeId();
        TYPE_EVENT getType();
        
};

}