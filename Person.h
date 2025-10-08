//
// Created by gusw1 on 9/30/2025.
//

#ifndef DMSIM_PERSON_H
#define DMSIM_PERSON_H
#include <queue>

#include "Command.h"


class Person {
    int globalRank;
    int globalFile;
    int localRank;
    int localFile;
    int numCommands;
    Facing facing;
    std::queue<Command *> commandQueue;
    std::vector<std::pair<int, int>> history;

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

    /// @return the local rank of the person on the field
    [[nodiscard]] int getLocalRank() const;

    /// @return the local file of the person on the field
    [[nodiscard]] int getLocalFile() const;

    /// @return the facing of the person
    [[nodiscard]] Facing getFacing() const;

    /// @return the number of commands a person has
    [[nodiscard]] int getNumCommands() const;

    /// @return the indexed history of a person
    [[nodiscard]] std::pair<int, int> getHistoryAt(int counter);

    /// @return a reference to the history vector
    [[nodiscard]] std::vector<std::pair<int, int>>* getHistory();

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
    void addCommand(const Command *command);

    /// Adds a list of commands to the queue
    /// @param commands the list of commands to be added
    void addCommands(const std::vector<Command *> &commands);
};

#endif //DMSIM_PERSON_H
