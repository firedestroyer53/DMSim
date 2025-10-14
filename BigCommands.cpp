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
                for (int r = numRanks; r > 0; r--) {
                    auto *list = new LinkedList<Person *>();
                    for (int f = numFiles; f > 0; f--) {
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
        const auto *marchForward = new Command(march, forward, false);
        for (int i = 0; i < persons->size(); i++) {
            LinkedList<Person *> rank = persons->at(i);
            Node<Person *> *currentNode = rank.getFront();

            while (currentNode != nullptr) {
                Person *currentPerson = currentNode->getData();
                currentPerson->addCommandRepeated(marchForward, i * 2 + 1);
                currentPerson->addCommands(commands);
                currentNode = currentNode->getNext();
            }
        }
    }

    void cascade(const std::vector<LinkedList<Person *> > *persons, Direction direction) {
        const auto* marchForward = new Command(march, forward, false);
        const auto* marktime = new Command();
        const auto* stepLeft = new Command(pivot, direction, false);
        for (int r = 0; r < persons->size(); ++r) { // loops thru ranks
            LinkedList<Person *> rank = persons->at(r);
            Node<Person *> *currentNode = rank.getFront();
            for (int f = 0; f < rank.getSize(); ++f) { // loops thru files
                if (direction == left) {
                    // when dir is left, leftmost file needs to stop for NUM_FILES * 2
                    Person* currentPerson = currentNode->getData();
                    currentPerson->addCommandRepeated(marchForward, f * 2);
                    currentPerson->addCommandRepeated(marktime, (NUM_FILES * 2 - f * 2 + 1) * 2);
                    // still have to wait more for the step to get to you
                    currentPerson->addCommandRepeated(marchForward, 2 * r);

                    currentPerson->addCommand(stepLeft);
                }
                currentNode = currentNode->getNext();
            }
        }
    }

    void column(std::vector<LinkedList<Person *> > *persons, Direction direction) {

    }

    void oblique(std::vector<LinkedList<Person *> > *persons, Direction direction) {
    }
}
