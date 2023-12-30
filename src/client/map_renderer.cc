#include "map_renderer.h"
#include <iostream>



namespace POD {


    MapRenderer::MapRenderer(std::string path_to_texture,int MapWidth, int MapHeight, int TileSize){
        this->texture = gf::Texture(path_to_texture);
        this->TileSize = TileSize;
        this->MapWidth = MapWidth;
        this->MapHeight = MapHeight;
        
        //texture.setSmooth();
        this->tileLayer = gf::TileLayer::createOrthogonal({ MapWidth, MapHeight }, { TileSize, TileSize });

        this->id_tileset = tileLayer.createTilesetId();
        gf::Tileset tileset = tileLayer.getTileset(id_tileset);

        tileset.setTileSize({ TileSize, TileSize });
        tileset.setSpacing(2);
        tileset.setTexture(texture);
    }

    void MapRenderer::changeTexture(std::string path_to_texture){
        gf::Texture texture("assets/tilelayer.png");

    }
    void MapRenderer::render(Map map){
        tileLayer.clear();
          for (int y = 0; y < MapHeight; ++y) {
            for (int x = 0; x < MapWidth; ++x) {
                int tile = map.getMap(x,y);
                if (tile != 0) {
                    std::cout << "x: " << x << " y: " << y << " tile: " << tile << std::endl;
                    tileLayer.setTile({ x, y }, id_tileset, tile-1);
                }
            }
        };
    }
    void MapRenderer::draw(gf::RenderTarget& target){
        gf::RenderStates states;
        tileLayer.draw(target, states);
    }

};
