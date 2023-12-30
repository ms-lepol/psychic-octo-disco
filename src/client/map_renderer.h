#include <gf/RenderWindow.h>
#include <gf/Texture.h>
#include <gf/TileLayer.h>
#include <gf/VectorOps.h>
#include <gf/Views.h>
#include <gf/ViewContainer.h>
#include <gf/Window.h>
#include <iostream>
#include <string>

#include "../maplogic/map.h"

namespace POD {
    class MapRenderer {
        private:
        
         gf::Texture texture;
         
        int MapWidth;
        int MapHeight;
        int TileSize;
        std::size_t id_tileset;
        

        public:
            void draw(gf::RenderTarget& target);
            gf::TileLayer tileLayer;
            MapRenderer(std::string path_to_texture,int MapWidth, int MapHeight, int TileSize);
            void changeTexture(std::string path_to_texture);
            void render(Map map);
    };
}