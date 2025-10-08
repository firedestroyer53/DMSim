#define SDL_MAIN_HANDLED

#include "ProjectRunner.h"

#include <iostream>


// ReSharper disable CppParameterNeverUsed
int main(int argc, char *argv[]) {
    auto *gr = new GraphicsRunner();

    gr->initialize();


    // Pre-processing of commands

    // Create people
    std::vector<Person *> people;
    for (int r = 0; r < NUM_RANKS; ++r) {
        for (int f = 0; f < NUM_FILES; ++f) {
            int spacedRank = RANK_OFFSET + r * 4;  // 4 units apart vertically
            int spacedFile = FILE_OFFSET + f * 4;  // 4 units apart horizontally
            people.push_back(new Person(spacedFile, spacedRank, HTs));
        }
    }


    BigCommands::counterMarch(&people);
    auto * command = new Command(march, forward, false);
    for (auto* person : people) {
        for (int i = 0; i < 40; i++) {
            person->addCommand(command);
        }
    }


    // display commands
    while (true) {
        bool shouldStop = false;
        for (const auto person: people) {
            if (!person->hasCommands()) {
                shouldStop = true;
            } else {
                person->executeNext();
            }
        }
        if (shouldStop) {
            break;
        }
    }

    bool quit = false;
    SDL_Event e;
    int counter = 0;


    // Main loop
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        gr->draw(counter, people);

        if (counter < people[0]->getHistory()->size()) {
            counter++;
        }

        SDL_Delay(400); // ~10 fps
    }

    // Clean up
    for (const auto *p: people) delete p;

    gr->close();

    return 0;
}

void update(const int counter, const std::vector<Person*>& people) {

}
