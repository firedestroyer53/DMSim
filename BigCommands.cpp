//
// Created by gusw1 on 10/6/2025.
//

#include "BigCommands.h"

#include <iostream>
#include <ostream>

void BigCommands::counterMarch(const std::vector<Person *> *persons) {
    std::vector<Command*> commands;
    auto* counterCommand = new Command(pivot, right, true);
    commands.push_back(counterCommand);
    counterCommand = new Command(march, forward, true);
    commands.push_back(counterCommand);
    counterCommand = new Command(pivot, right, false);
    commands.push_back(counterCommand);
    for (auto *person : *persons) {
        const int stepsBeforeTurn = person->getLocalRank();
        const auto* marchForward = new Command(march, forward, true);
        for (int i = 0; i <= stepsBeforeTurn; i++) {
            person->addCommand(marchForward);
        }
        person->addCommands(commands);
    }
}

void BigCommands::cascade(std::vector<Person *> *persons, Direction direction) {
}

void BigCommands::column(std::vector<Person *> *persons, Direction direction) {
}

void BigCommands::oblique(std::vector<Person *> *persons, Direction direction) {
}
