//
// Created by gusw1 on 9/30/2025.
//

#include "Person.h"

#include <iostream>
#include <ostream>

Person::Person() {
    globalFile = 0;
    globalRank = 0;
    localFile = 0;
    localRank = 0;
    facing = HTs;
    history.emplace_back(globalFile, globalRank);
    numCommands = 0;
}

Person::Person(const int file, const int rank, const Facing facing) {
    this->globalFile = file;
    this->globalRank = rank;
    this->facing = facing;
    this->localFile = file - FILE_OFFSET;
    switch (facing) {
        case HTs:
            this->localRank = NUM_RANKS - (rank - RANK_OFFSET);
            break;
        case MVs:
            this->localRank = (rank - RANK_OFFSET);
        default:
            break;
    }
    history.emplace_back(file, rank);
    numCommands = 0;
}

int Person::getFile() const {
    return globalFile;
}

int Person::getRank() const {
    return globalRank;
}

int Person::getLocalFile() const {
    return localFile;
}

int Person::getLocalRank() const {
    return localRank;
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

std::vector<std::pair<int, int> > *Person::getHistory() {
    return &history;
}

void Person::executeNext() {
    const Command *command = this->commandQueue.front();
    commandQueue.pop();
    const auto [fst, snd] = command->executeCommand(this->facing);
    this->facing = fst;
    this->globalFile += snd.first;
    this->globalRank += snd.second;
    this->history.emplace_back(globalFile, globalRank);
    numCommands--;
}

bool Person::hasCommands() const {
    return numCommands > 0;
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

void Person::setFile(const int f) {
    this->globalFile = f;
}

void Person::setRank(const int r) {
    this->globalRank = r;
}

