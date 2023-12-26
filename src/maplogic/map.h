#include <functional>
#include <map>
#include <string>
#include <sys/types.h>
#include <utility>
#pragma once

#define M_WIDTH 80 // 80
#define M_HEIGHT 60 // 60
namespace POD {
    class Map {
    private:
        //Attributes
        std::map<std::string, u_int8_t> land_orientation_map;
        u_int16_t map_values[M_WIDTH*M_HEIGHT];

        //Methods
        static u_int16_t linearize(u_int8_t x, u_int8_t y);
        static std::pair<u_int8_t, u_int8_t> delinearize(u_int16_t v);
        void setMap(int x, int y, u_int8_t v);
        void update(int x, int y);
        
    public:
        Map();
        u_int8_t const getMap(int x, int y);
        void placeLand(int x, int y, u_int8_t land_type_id);
        void deleteLand(int x, int y);
        void printMap();
};
}
