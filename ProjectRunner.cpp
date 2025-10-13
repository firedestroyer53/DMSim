#define SDL_MAIN_HANDLED

#include "ProjectRunner.h"

#include <iostream>


// ReSharper disable CppParameterNeverUsed
int main(int argc, char *argv[]) {
    auto *gr = new GraphicsRunner();

    gr->initialize();


    // Pre-processing of commands

    // Create people
    const std::vector<LinkedList<Person *> > people = BigCommands::setup(NUM_FILES, NUM_RANKS, MVs);

    BigCommands::counterMarch(&people);

    const auto *command = new Command(march, forward, false);
    for (auto rank: people) {
        Node<Person *> *currentNode = rank.getFront();
        while (currentNode != nullptr) {
            Person *currentPerson = currentNode->getData();
            while (currentPerson->getNumCommands() < 40) {
                currentPerson->addCommand(command);
            }
            currentNode = currentNode->getNext();
        }
    }


    // display commands
    while (true) {
        bool shouldStop = false;
        for (auto rank: people) {
            Node<Person *> *currentNode = rank.getFront();
            while (currentNode != nullptr) {
                Person *person = currentNode->getData();
                if (!person->hasCommands()) {
                    shouldStop = true;
                } else {
                    person->executeNext();
                }
                currentNode = currentNode->getNext();
            }
        }
        if (shouldStop) {
            break;
        }
    }

    bool quit = false;
    SDL_Event e;
    int counter = 0;

    // after done processing, can turn into vector for graphics.
    std::vector<Person *> persons;
    for (auto rank: people) {
        std::vector<Person *> v1 = rank.toVector();
        persons.insert(persons.end(), v1.begin(), v1.end());
    }


    // Main loop
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        gr->draw(counter, persons);

        if (counter < persons[0]->getHistory()->size()) {
            counter++;
        }

        SDL_Delay(600);
    }

    // Clean up
    for (const auto *p: persons) delete p;

    gr->close();

    return 0;
}

void update(const int counter, const std::vector<Person *> &people) {
}
