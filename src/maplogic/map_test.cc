#include "map.h"

int main(){
    Map map;

    map.placeLand(1, 1, 1);
    map.placeLand(1, 2, 1);
    map.placeLand(3, 3, 1);
    map.placeLand(4, 4, 1);

    map.placeLand(2, 2, 1);

    map.placeLand(5, 5, 1);

    map.printMap();
    
    return 0;
}