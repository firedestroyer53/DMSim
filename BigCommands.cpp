//
// Created by gusw1 on 10/6/2025.
//

#include "BigCommands.h"

#include <iostream>
#include <ostream>

namespace BigCommands {
    std::vector<LinkedList<Person *> > setup(const int numFiles, const int numRanks, const Facing facing) {
        std::vector<LinkedList<Person *> > people;
        switch (facing) {
            case MVs:
                for (int r = numRanks; r >= 0; r--) {
                    auto *list = new LinkedList<Person *>();
                    for (int f = numFiles; f >= 0; f--) {
                        list->pushFront(new Node(new Person(FILE_OFFSET + (f * 4), RANK_OFFSET + (r * 4), facing)));
                    }
                    people.push_back(*list);
                    delete list;
                }
                break;
            case HTs:
                for (int r = 0; r < numRanks; r++) {
                    auto *list = new LinkedList<Person *>();
                    for (int f = 0; f < numFiles; f++) {
                        list->pushBack(new Node(new Person(FILE_OFFSET + (f * 4), RANK_OFFSET + (r * 4), facing)));
                    }
                    people.push_back(*list);
                    delete list;
                }
                break;
            default:
                break;
        }

        return people;
    }

    void counterMarch(const std::vector<LinkedList<Person *> > *persons) {
        std::vector<Command *> commands;
        auto *counterCommand = new Command(pivot, right, true);
        commands.push_back(counterCommand);
        counterCommand = new Command(march, forward, true);
        commands.push_back(counterCommand);
        counterCommand = new Command(pivot, right, false);
        commands.push_back(counterCommand);
        auto *marchForward = new Command(march, forward, false);
        for (int i = 0; i < persons->size(); i++) {
            LinkedList<Person *> rank = persons->at(i);
            Node<Person *> *currentNode = rank.getFront();
            std::vector<Command *> preCommands;
            for (int step = 0; step <= i * 2; step++) {
                preCommands.push_back(marchForward);
            }

            while (currentNode != nullptr) {
                Person *currentPerson = currentNode->getData();
                currentPerson->addCommands(preCommands);
                currentPerson->addCommands(commands);
                currentNode = currentNode->getNext();
            }
        }
    }

    void cascade(std::vector<Person *> *persons, Direction direction) {
    }

    void column(std::vector<Person *> *persons, Direction direction) {
    }

    void oblique(std::vector<Person *> *persons, Direction direction) {
    }
}
