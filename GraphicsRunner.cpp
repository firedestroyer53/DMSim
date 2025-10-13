//
// Created by gusw1 on 10/6/2025.
//

#include "GraphicsRunner.h"

#include <iostream>

void GraphicsRunner::drawCircle(const int centerX, const int centerY, const int radius) const {
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            const int dx = radius - w; // horizontal offset
            const int dy = radius - h; // vertical offset
            if (dx * dx + dy * dy <= radius * radius) {
                SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
            }
        }
    }
}

GraphicsRunner::GraphicsRunner() = default;

bool GraphicsRunner::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Drum Major Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
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

void GraphicsRunner::draw(const int counter, const std::vector<Person *> &people) const {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    for (int i = 0; i < people.size(); i++) {
        auto* person = people[i];
        const std::pair<int, int> coords = person->getHistoryAt(counter);

        // convert grid coordinates to screen coordinates
        const int screenX = coords.first * SCREEN_WIDTH / GRID_WIDTH;

        // Flip Y so origin is bottom-left instead of top-left
        const int screenY = SCREEN_HEIGHT - (coords.second * SCREEN_HEIGHT / GRID_HEIGHT);
        if (i < 3) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        }
        else {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        }
        drawCircle(screenX, screenY, SCREEN_HEIGHT / 400);
    }

    SDL_RenderPresent(renderer);
}


void GraphicsRunner::close() const {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
