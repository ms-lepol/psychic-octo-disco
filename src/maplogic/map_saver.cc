#include "map.h"
#include <string>

class Map_Saver {
    private:
        static std::string src;
        static Map_Saver instance;
        Map_Saver();
    public:
        static Map_Saver getInstance();        

        void saveMap(Map map);
        Map loadMap();
};