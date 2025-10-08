//
// Created by gusw1 on 10/6/2025.
//

#include "GraphicsRunner.h"

#include <iostream>

void GraphicsRunner::drawCircle(const int centerX, const int centerY, const int radius) const {
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx*dx + dy*dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
            }
        }
    }
}


GraphicsRunner::GraphicsRunner() {
}

bool GraphicsRunner::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Particle Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void GraphicsRunner::draw(int counter, const std::vector<Person*>& people) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);


    for (auto* person : people) {
        std::pair<int, int> coords = person->getHistoryAt(counter);
        // convert grid coordinates to screen coordinates
        std::pair<int, int> screenCoords = std::make_pair(coords.first * SCREEN_WIDTH / GRID_WIDTH, coords.second * SCREEN_HEIGHT / GRID_HEIGHT);

        drawCircle(screenCoords.first, screenCoords.second, SCREEN_HEIGHT / 400);
    }

    SDL_RenderPresent(renderer);
}

void GraphicsRunner::close() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
