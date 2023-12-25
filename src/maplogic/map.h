#include <functional>
#include <map>
#include <string>
#include <sys/types.h>
#include <utility>
#define M_WIDTH 60
#define M_HEIGHT 80

class Map {
    private:
        //Attributes
        std::map<std::string, u_int8_t> land_orientation_map;
        u_int16_t map_values[M_WIDTH*M_HEIGHT];

        //Methods
        static u_int16_t linearize(u_int8_t x, u_int8_t y);
        static std::pair<u_int8_t, u_int8_t> delinearize(u_int16_t v);
        void setMap(int x, int y, u_int8_t v);
        u_int8_t getMap(int x, int y);
        void update(int x, int y);
        
    public:
        Map();
        void placeLand(int x, int y, u_int8_t land_id);
        void deleteLand(int x, int y);
        void printMap();
};