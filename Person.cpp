//
// Created by gusw1 on 9/30/2025.
//

#include "Person.h"

#include <iostream>
#include <ostream>

Person::Person() {
    globalFile = 0;
    globalRank = 0;
    localRank = 0;
    localFile = 0;
    facing = HTs;
    numCommands = 0;
}

Person::Person(const int file, const int rank, const Facing facing) {
    this->globalRank = rank;
    this->globalFile = file;
    this->facing = facing;
    this->localRank = rank - RANK_OFFSET;
    this->localFile = file - FILE_OFFSET;
    numCommands = 0;
}

int Person::getRank() const {
    return globalRank;
}

int Person::getFile() const {
    return globalFile;
}

int Person::getLocalRank() const {
    return localRank;
}

int Person::getLocalFile() const {
    return localFile;
}

Facing Person::getFacing() const {
    return facing;
}

int Person::getNumCommands() const {
    return numCommands;
}

std::pair<int, int> Person::getHistoryAt(const int counter) {
    if (counter >= history.size()) {
        return history.back();
    }
    return history[counter];
}

std::vector<std::pair<int, int>> * Person::getHistory() {
    return &history;
}

void Person::executeNext() {
    const Command *command = this->commandQueue.front();
    commandQueue.pop();
    const std::pair<Facing, std::pair<int, int> > newCoords = command->executeCommand(this->facing);
    this->facing = newCoords.first;
    this->globalFile += newCoords.second.first;
    this->globalRank += newCoords.second.second;
    this->history.emplace_back(globalFile, globalRank);
    numCommands--;
}

bool Person::hasCommands() const {
    if (this->commandQueue.empty()) {
        return false;
    }
    return true;
}


void Person::addCommand(const Command *command) {
    this->commandQueue.push(new Command(*command));
    numCommands++;
}

void Person::addCommands(const std::vector<Command *> &commands) {
    for (const Command *command: commands) {
        addCommand(new Command(*command)); // make a copy per person
    }
}

void Person::setFile(int f) {
    this->globalFile = f;
}

void Person::setRank(int r) {
    this->globalRank = r;
}

