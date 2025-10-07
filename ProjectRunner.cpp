#define SDL_MAIN_HANDLED

#include <vector>
#include "Person.h"
#include "GraphicsRunner.h"

// ReSharper disable CppParameterNeverUsed
int main(int argc, char * argv[]) {

    auto* gr = new GraphicsRunner();

    gr->initialize();


    // Create people
    std::vector<Person*> people;
    for (int r = 0; r < 7; ++r) {
        for (int f = 0; f < 15; ++f) {
            people.push_back(new Person(r, f, HTs));
        }
    }

    std::vector<Command*> commands;
    for (int i = 0; i < 5; ++i) {
        auto* command = new Command(march, forward);
        commands.push_back(command);
    }

    for (const auto person : people) {
        person->addCommands(commands);
    }

    while (true) {
        bool shouldStop = false;
        for (const auto person : people) {
            if (!person->hasCommands()) {
                shouldStop = true;
            }
            else {
                person->executeNext();
            }
        }
        if (shouldStop) {
            break;
        }
    }

    // Clean up
    for (const auto* p : people) delete p;

    gr->close();

    return 0;
}
