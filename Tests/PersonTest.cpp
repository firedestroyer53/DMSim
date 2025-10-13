//
// Created by gusw1 on 10/8/2025.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "../Person.h"

Person *setup(const bool withCommands = false, const bool withExecute = false) {
    auto *person = new Person(5, 50, HTs);
    if (withCommands) {
        const auto *command = new Command(march, forward, false);
        for (int i = 0; i < 5; i++) {
            person->addCommand(command);
        }
    }
    if (withExecute) {
        while (person->hasCommands()) {
            person->executeNext();
        }
    }
    return person;
}

TEST_CASE (
"testGetFile"
)
 {
    const Person *person = setup();
    CHECK((person->getFile() == 5));
}

TEST_CASE (
"testGetRank"
)
 {
    const Person *person = setup();
    CHECK((person->getRank() == 50));
}

TEST_CASE (
"testGetLocalFile"
)
 {
    const Person *person = setup();
    CHECK((person->getLocalFile() == 0));
}

TEST_CASE (
"testGetLocalRank"
)
 {
    const Person *person = setup();
    CHECK((person->getLocalRank() == 0));
}

TEST_CASE (
"testGetFacing"
)
 {
    const Person *person = setup();
    CHECK((person->getFacing() == HTs));
}

TEST_CASE (
"testGetNumCommands"
)
 {
    const Person *person = setup();
    CHECK((person->getNumCommands() == 0));
}

TEST_CASE (
"testGetHistoryAt"
)
 {
    Person *person = setup(true, true);
    const std::vector<std::pair<int, int> > *history = person->getHistory();
    const std::pair<int, int> indexed = history->at(0);
    CHECK((indexed == person->getHistoryAt(0)));
}

TEST_CASE (
"testGetHistory"
)
 {
    Person *person = setup(true, true);
    const std::vector<std::pair<int, int> > *history = person->getHistory();
    std::vector<std::pair<int, int> > expected;
    expected.emplace_back(5, 50);
    expected.emplace_back(5, 48);
    expected.emplace_back(5, 46);
    expected.emplace_back(5, 44);
    expected.emplace_back(5, 42);
    expected.emplace_back(5, 40);
    CHECK((expected == *history));
}

TEST_CASE (
"testExecuteNext"
)
 {
    Person *person = setup(true);
    person->executeNext();
    CHECK((person->getFile() == 5));
    CHECK((person->getRank() == 48));
    CHECK((person->getFacing() == HTs));
    CHECK((person->getNumCommands() == 4));
    std::vector<std::pair<int, int> > *history = person->getHistory();
    CHECK((history->size() == 2));
}

TEST_CASE (
"testHasCommands"
)
 {
    const Person *person = setup();
    const Person *person2 = setup(true);
    CHECK(!person->hasCommands());
    CHECK(person2->hasCommands());

}

TEST_CASE (
"testAddCommand"
)
 {
    Person *person = setup();
    const auto* command = new Command(march, forward, false);
    person->addCommand(command);
    CHECK((person->getNumCommands() == 1));
}

TEST_CASE (
"testAddCommands"
)
 {
    Person *person = setup();
    std::vector<Command*> commands;
    for (int i = 0; i < 5; i++) {
        commands.push_back(new Command(march, forward, false));
    }
    person->addCommands(commands);
    CHECK((person->getNumCommands() == 5));
}

TEST_CASE (
"testSetFile"
)
 {
    Person *person = setup();
    person->setFile(20);
    CHECK((person->getFile() == 20));
}

TEST_CASE (
"testSetRank"
)
 {
    Person *person = setup();
    person->setRank(20);
    CHECK((person->getRank() == 20));
}