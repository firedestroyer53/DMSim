//
// Created by gusw1 on 10/8/2025.
//

#include "doctest.h"
#include "../BigCommands.h"

std::vector<Person *> setup() {
    std::vector<Person *> people;
    for (int f = 0; f < 3; ++f) {
        for (int r = 0; r < 3; ++r) {
            const int spacedRank = RANK_OFFSET + r * 4; // 4 units apart vertically
            const int spacedFile = FILE_OFFSET + f * 4; // 4 units apart horizontally
            people.push_back(new Person(spacedFile, spacedRank, MVs));
        }
    }
    return people;
}


TEST_CASE (
"testCounterMarch"
)
 {
    std::vector<Person *> people = setup();
    BigCommands::counterMarch(&people);
    while (people[0]->hasCommands()) {
        people[0]->executeNext();
    }

}