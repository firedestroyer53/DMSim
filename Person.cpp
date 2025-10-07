//
// Created by gusw1 on 9/30/2025.
//

#include "Person.h"

Person::Person() {
    file = 0;
    rank = 0;
    facing = HTs;
}

Person::Person(const int file, const int rank, const Facing facing) {
    this->rank = rank;
    this->file = file;
    this->facing = facing;
}

int Person::getRank() const {
    return rank;
}

int Person::getFile() const {
    return file;
}

Facing Person::getFacing() const {
    return facing;
}

void Person::executeNext() {
    Command *command = this->commandQueue.front();
    commandQueue.pop();
    const std::pair<Facing, std::pair<int, int> > newCoords = command->executeCommand(this->facing);
    this->facing = newCoords.first;
    this->file += newCoords.second.first;
    this->rank += newCoords.second.second;
}

bool Person::hasCommands() const {
    if (this->commandQueue.empty()) {
        return false;
    }
    return true;
}


void Person::addCommand(Command *command) {
    this->commandQueue.push(command);
}

void Person::addCommands(const std::vector<Command *> &commands) {
    for (Command *command: commands) {
        addCommand(command);
    }
}

void Person::setFile(int f) {
    this->file = f;
}

void Person::setRank(int r) {
    this->rank = r;
}

