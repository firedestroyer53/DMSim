//
// Created by gusw1 on 10/6/2025.
//

#ifndef DMSIM_BIGCOMMANDS_H
#define DMSIM_BIGCOMMANDS_H
#include "Command.h"
#include "Person.h"

#include <vector>

class BigCommands {
public:
    static void counterMarch(const std::vector<Person *> *persons);

    static void cascade(std::vector<Person *> *persons, Direction direction);

    static void column(std::vector<Person *> *persons, Direction direction);

    static void oblique(std::vector<Person *> *persons, Direction direction);
};


#endif //DMSIM_BIGCOMMANDS_H