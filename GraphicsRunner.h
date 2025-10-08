//
// Created by gusw1 on 10/6/2025.
//

#ifndef DMSIM_GRAPHICSRUNNER_H
#define DMSIM_GRAPHICSRUNNER_H

#include <SDL2/SDL.h>

#include "Person.h"


class GraphicsRunner {
    SDL_Window *window{};
    SDL_Renderer *renderer{};
    const int GRID_WIDTH = 60;
    const int GRID_HEIGHT = 120;
    const int SCREEN_WIDTH = GRID_WIDTH * 10;
    const int SCREEN_HEIGHT = GRID_HEIGHT * 10;


    void drawCircle(int centerX, int centerY, int radius) const;

public:
    /// Creates a new GraphicsRunner object
    GraphicsRunner();

    /// Initializes the GraphicsRunner object with the default SDL initialization
    bool initialize();

    /// Draws on the screen, runs every frame
    void draw(int counter, const std::vector<Person*>& people);

    /// Closes the SDL instance
    void close();
};


#endif //DMSIM_GRAPHICSRUNNER_H
