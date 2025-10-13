//
// Created by gusw1 on 10/8/2025.
//


#include "doctest.h"
#include "../Command.h"

Command *setup(const bool isMarch, const bool isHalf = false, const Direction dir = right) {
    Command *command;

    if (isMarch) {
        command = new Command(march, forward, isHalf);;
    } else {
        command = new Command(pivot, dir, isHalf);
    }
    return command;
}

TEST_CASE (
"testExecuteCommand"
)
 {
    Command* march1 = setup(true);
    Command* march2 = setup(true, true);
    Command* pivot1 = setup(false, false);
    Command* pivot2 = setup(false, true);
    Command* pivot3 = setup(false, false, left);
    Command* pivot4 = setup(false, true, left);

    std::pair<Facing, std::pair<int, int>> result = march1->executeCommand(HTs);
    std::pair<Facing, std::pair<int, int> > expected = {HTs, {0, -2}};
    CHECK((result == expected));
    result = march2->executeCommand(HTs);
    expected.second.second = -1;
    CHECK((result == expected));
    result = pivot1->executeCommand(HTs);
    expected = {PB, {-2, 0}};
    CHECK((result == expected));
    result = pivot2->executeCommand(HTs);
    expected = {PB, {-1, 0}};
    CHECK((result == expected));
    result = pivot3->executeCommand(HTs);
    expected = {SS, {2, 0}};
    CHECK((result == expected));
    result = pivot4->executeCommand(HTs);
    expected = {SS, {1, 0}};
    CHECK((result == expected));

}