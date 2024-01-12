#include "map.h"
#include <iostream>
#include <map>
#include <string>
#include <sys/types.h>
#include <utility>

namespace POD {

Map::Map() {
    for (int i = 0; i < M_WIDTH*M_HEIGHT; i++) {
        map_values[i] = 0;
    }


    //Initialize the land_orientation map
    Map::land_orientation_map["S"] = 1;
    Map::land_orientation_map["L"] = 2;
    Map::land_orientation_map["R"] = 3;
    Map::land_orientation_map["U"] = 4;
    Map::land_orientation_map["D"] = 5;
    Map::land_orientation_map["LU"] = 6;
    Map::land_orientation_map["LD"] = 7;
    Map::land_orientation_map["RU"] = 8;
    Map::land_orientation_map["RD"] = 9;
    Map::land_orientation_map["LR"] = 10;
    Map::land_orientation_map["UD"] = 11;
    Map::land_orientation_map["LRU"] = 12;
    Map::land_orientation_map["LUD"] = 13;
    Map::land_orientation_map["LRD"] = 14;
    Map::land_orientation_map["RUD"] = 15;
    Map::land_orientation_map["LRUD"] = 16;
}

u_int16_t Map::linearize(u_int8_t x, u_int8_t y) {
    if (x >= M_WIDTH || y >= M_HEIGHT) {
        std::cerr << "Error: linearize() called with x or y out of bounds" << std::endl;
        return -1;
    }
    return (u_int16_t) (x + y*M_WIDTH);
}

std::pair<u_int8_t, u_int8_t> Map::delinearize(u_int16_t v) {
    if (v >= M_WIDTH*M_HEIGHT) {
        std::cerr << "Error: delinearize() called with v out of bounds" << std::endl;
        return std::make_pair(-1, -1);
    }
    return std::make_pair(v % M_WIDTH, v / M_WIDTH);
}

void Map::setMap(int x, int y, u_int8_t v) {
    if (x >= M_WIDTH || y >= M_HEIGHT) {
        std::cerr << "Error: setMap() called with x or y out of bounds" << std::endl;
        return;
    }
    map_values[linearize(x, y)] = v;
}

u_int8_t const Map::getMap(int x, int y) {
    if (x >= M_WIDTH || y >= M_HEIGHT) {
        std::cerr << "Error: getMap() called with x or y out of bounds" << std::endl;
        return -1;
    }
    return map_values[linearize(x, y)];
}

void Map::printMap() {
    for (int y = 0; y < M_HEIGHT; y++) {
        for (int x = 0; x < M_WIDTH; x++) {
            std::cout << (int) getMap(x, y) << " ";
        }
        std::cout << std::endl;
    }
}

void Map::placeLand(int x, int y, u_int8_t land_type_id) {
    // TODO: check if land_id is valid
    if (land_type_id == 0) {
        std::cerr << "Error: placeLand() called with land_id 0" << std::endl;
        return;
    }

    setMap(x, y, land_type_id);
    update(x, y);
}

void Map::deleteLand(int x, int y) {
    setMap(x, y, 0);
    //Update the neighbors
    if (x>0 && getMap(x-1, y) != 0){
        update(x-1, y);
    }
    if (x<M_WIDTH-1 && getMap(x+1, y) != 0){
        update(x+1, y);
    }
    if (y>0 && getMap(x, y-1) != 0){
        update(x, y-1);
    }
    if (y<M_HEIGHT-1 && getMap(x, y+1) != 0){
        update(x, y+1);
    }
}

void Map::update(int x, int y) {
    //Check if the neighbors are the same land
    u_int8_t land_id = getMap(x, y);
    std::string land_orientation = "";


    //Protection against 0 - no land
    if (land_id == 0) {
        std::cerr << "Error: update() called with land_id 0" << std::endl;
        return;
    }

    //Check if the neighbors are the same land
    std::map<std::pair<u_int8_t,u_int8_t>, u_int8_t> neighbors;
    //Left
    if (x > 0) {
        std::pair <u_int8_t,u_int8_t> key = std::make_pair(x-1, y);
        u_int8_t value = getMap(x-1, y);
        if (value != 0) {
            neighbors[key] = value;
            land_orientation += "L";
        }
    }
    //Right
    if (x < M_WIDTH-1) {
        std::pair <u_int8_t,u_int8_t> key = std::make_pair(x+1, y);
        u_int8_t value = getMap(x+1, y);
        if (value != 0) {
            neighbors[key] = value;
            land_orientation += "R";
        }
    }
    //Up
    if (y > 0) {
        std::pair <u_int8_t,u_int8_t> key = std::make_pair(x, y-1);
        u_int8_t value = getMap(x, y-1);
        if (value != 0) {
            neighbors[key] = value;
            land_orientation += "U";
        }
    }
    //Down
    if (y < M_HEIGHT-1) {
        std::pair <u_int8_t,u_int8_t> key = std::make_pair(x, y+1);
        u_int8_t value = getMap(x, y+1);
        if (value != 0) {
            neighbors[key] = value;
            land_orientation += "D";
        }
    }
    //Determining the new land shape
    if (neighbors.size() == 0) {
        land_orientation = "S"; //Single
    }

    //Determining the new land orientation

    u_int8_t land_id_orientation = land_id % 16;
    if (land_id_orientation == 0) {
        land_id_orientation = 16;
    }

    u_int8_t new_land_id_orientation = Map::land_orientation_map[land_orientation];

    if (new_land_id_orientation != land_id_orientation) {
        std::cout << "Land orientation changed from " << (int) land_id_orientation << " to " << (int) new_land_id_orientation << std::endl;
         u_int8_t land_id_type = land_id / 16;
        u_int8_t new_land_id = land_id_type * 16 + new_land_id_orientation;
        setMap(x, y, new_land_id);
         //update the neighbors if they are not 0
        for (auto const& neighbor : neighbors) {
            std::pair<u_int8_t,u_int8_t> key = neighbor.first;
            u_int8_t value = neighbor.second;

            if (value != 0) {
                update(key.first, key.second);
            }
        }
    }
}
}