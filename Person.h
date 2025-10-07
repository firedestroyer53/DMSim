//
// Created by gusw1 on 9/30/2025.
//

#ifndef DMSIM_PERSON_H
#define DMSIM_PERSON_H
#include <queue>

#include "Command.h"


class Person {
    int rank;
    int file;
    Facing facing;
    std::queue<Command *> commandQueue;

public:
    /// Creates a new Person object with rank and file initialized to 0
    Person();

    /// Creates a new Person object with specified rank and file
    /// @param file the file of the person on the field
    /// @param rank the rank of the person on the field
    /// @param facing where the person is facing
    Person(int file, int rank, Facing facing);

    /// @return the rank of the person on the field
    [[nodiscard]] int getRank() const;

    /// @return the file of the person on the field
    [[nodiscard]] int getFile() const;

    /// @return the facing of the person
    [[nodiscard]] Facing getFacing() const;


    /// Sets the rank of the person
    void setRank(int r);

    /// Sets the file of the person
    void setFile(int f);


    /// Executes the next command in the queue
    void executeNext();

    /// Checks if the person has a command left in the queue
    [[nodiscard]] bool hasCommands() const;

    /// Adds a command to the queue
    /// @param command the command to be added
    void addCommand(Command *command);

    /// Adds a list of commands to the queue
    /// @param commands the list of commands to be added
    void addCommands(const std::vector<Command *> &commands);
};

#endif //DMSIM_PERSON_H
