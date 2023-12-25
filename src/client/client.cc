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

int main() {
    // Create the main window and the renderer
    
    gf::Window window("POD - Level Editor", { 640, 480});
    gf::RenderWindow renderer(window);
    gf::Vector2f windows_size = window.getSize();
    
    // Load a sprite to display
    
    
    // Create a graphical text to display

    // Testing a display for the map

    renderer.clear(gf::Color::Blue);
    
    
   
    
    gf::Vector2f text_mov = { 1, 1 };
    srand(time(NULL));
    // Start the game loop

    while (window.isOpen()) {
        
        gf::Event event;
    
        while (window.pollEvent(event)) {
        switch (event.type) {
            case gf::EventType::Closed:
            window.close();
            break;
    
            default:
            break;
        }
        }
    
        // Draw the entities
    
        renderer.clear();

        renderer.display();
    }
        
    return 0;
}