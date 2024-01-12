#include "map_renderer.h"
#include <iostream>



namespace POD {


    MapRenderer::MapRenderer(std::string path_to_texture,int MapWidth, int MapHeight, int TileSize){
        this->texture = gf::Texture(path_to_texture);
        this->TileSize = TileSize;
        this->MapWidth = MapWidth;
        this->MapHeight = MapHeight;
        
        texture.setSmooth();
        this->tileLayer = gf::TileLayer::createOrthogonal({ MapWidth, MapHeight }, { TileSize, TileSize });

        this->id_tileset = this->tileLayer.createTilesetId();
        this->tileset = &this->tileLayer.getTileset(this->id_tileset);
        this->tileset->setTileSize({ TileSize, TileSize });
        this->tileset->setTexture(texture);

    }

    void MapRenderer::changeTexture(std::string path_to_texture){
        gf::Texture texture("assets/tilelayer.png");

    }
    void MapRenderer::render(Map map){
        this->tileLayer.clear();
          
        for (int y = 0; y < this->MapHeight; ++y) {
            for (int x = 0; x < this->MapWidth; ++x) {
                int tile = map.getMap(x,y);
                if (tile != 0) {
                    //std::cout << "x: " << x << " y: " << y << " tile: " << tile << std::endl;
                    this->tileLayer.setTile({ x, y }, id_tileset, tile-1);
                }
            }
        };
        tileLayer.updateGeometry();
    }
    void MapRenderer::draw(gf::RenderTarget& target){
        gf::RenderStates states;
        tileLayer.draw(target, states);
    }

};
