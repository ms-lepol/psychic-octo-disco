#include <cstdlib>
#include <gf/Color.h>
#include <gf/Event.h>
#include <gf/Font.h>
#include <gf/RenderWindow.h>
#include <gf/Sprite.h>
#include <gf/Text.h>
#include <gf/Vector.h>
#include <gf/VectorOps.h>
#include <gf/Polygon.h>
#include <gf/Shapes.h>
#include <gf/Window.h>
#include <gf/TileLayer.h>
#include <gf/Tileset.h>
#include <gf/Grid.h>
#include <iostream>
#include "../controler/event_handler.h"
#include "map_renderer.h"

#define t_size 16

int main() {
    int x_mouse = 0;
    int y_mouse = 0;
    int x_mouse_grid = 0;
    int y_mouse_grid = 0;

    // Create the main window and the renderer
    
    gf::Window window("POD - Level Editor", {M_WIDTH*t_size , M_HEIGHT*t_size});
    gf::RenderWindow renderer(window);
    POD::MapRenderer map_renderer("../data/assets/tileset_land_1.png", M_WIDTH, M_HEIGHT, t_size);
    POD::Map map;
    gf::Vector2f windows_size = window.getSize();
    
    // Load a sprite to display
    
    
    // Create a graphical text to display

    // Testing a display for the map
    gf::Grid grid = gf::Grid::createOrthogonal(gf::Vector2f(640,480), gf::Vector2f(8,8));

    renderer.clear(gf::Color::Blue);
    
    gf::RectangleShape rectangle;
    rectangle.setSize({ t_size, t_size });
    rectangle.setColor(gf::Color::Transparent);
    rectangle.setOutlineColor(gf::Color::White);
    rectangle.setOutlineThickness(1);
    rectangle.setPosition({ 0, 0 });


    srand(time(NULL));
    // Start the game loop

    while (window.isOpen()) {
        
        gf::Event event;
    
        while (window.pollEvent(event)) {
        switch (event.type) {
            case gf::EventType::Closed:
            window.close();
            break;
            case gf::EventType::MouseMoved:
                x_mouse = (event.mouseCursor.coords.x / t_size) * t_size;
                y_mouse = event.mouseCursor.coords.y / t_size * t_size;
                rectangle.setPosition({(float)x_mouse, (float) y_mouse});
            break;
            case gf::EventType::MouseButtonPressed:
                if (event.mouseButton.button == gf::MouseButton::Left) {
                    x_mouse_grid = event.mouseButton.coords.x / t_size;
                    y_mouse_grid = event.mouseButton.coords.y / t_size;
                    std::cout << "(VUE) click on : x: " << x_mouse_grid << " y: " << y_mouse_grid << std::endl;
                    
                    map.placeLand(x_mouse_grid, y_mouse_grid, 1);

                    map.printMap();
                }

            default:
            break;
        }
        }

        // Update the scene

        // Draw the entities

        renderer.clear();
        renderer.draw(rectangle);
        map_renderer.render(map);
        renderer.draw(map_renderer.tileLayer);
        renderer.display();
    }
        
    return 0;
}