//
// Created by gusw1 on 10/6/2025.
//

#ifndef DMSIM_GRAPHICSRUNNER_H
#define DMSIM_GRAPHICSRUNNER_H

#include <SDL2/SDL.h>



class GraphicsRunner {
    SDL_Window* window{};
    SDL_Renderer* renderer{};
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
public:
    /// Creates a new GraphicsRunner object
    GraphicsRunner();
    /// Initializes the GraphicsRunner object with the default SDL initialization
    bool initialize();
    /// Updates the screen, is called before draw and runs every frame
    void update();
    /// Draws on the screen, runs every frame
    void draw();
    /// Closes the SDL instance
    void close() const;
};


#endif //DMSIM_GRAPHICSRUNNER_H