//
// Created by gusw1 on 10/6/2025.
//

#ifndef DMSIM_BIGCOMMANDS_H
#define DMSIM_BIGCOMMANDS_H
#include "Command.h"
#include "Person.h"
#include "LinkedList.h"

#include <vector>

namespace BigCommands {
    std::vector<LinkedList<Person *> > setup(int numFiles, int numRanks, Facing facing);

    void counterMarch(const std::vector<LinkedList<Person *> > *persons);

    void cascade(const std::vector<LinkedList<Person *> > *persons, Direction direction);

    void column(std::vector<LinkedList<Person *> > *persons, Direction direction);

    void oblique(std::vector<LinkedList<Person *> > *persons, Direction direction);
};


#endif //DMSIM_BIGCOMMANDS_H