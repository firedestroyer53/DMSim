//
// Created by gusw1 on 9/30/2025.
//

#ifndef DMSIM_COMMAND_H
#define DMSIM_COMMAND_H
#include <utility>

#include "Enums.h"


class Command {
    StepType stepType;
    Direction direction;

    [[nodiscard]] Facing newFacing(Facing facing) const;

    [[nodiscard]] std::pair<int, int> deltaStep(Facing facing) const;

public:
    /// Creates a new command with a StepType and a Direction
    /// @param step the type of step the command uses
    /// @param dir the direction (if any) of the command. (forward by default)
    Command(StepType step, Direction dir);

    /// Executes the command based on the step type and direction, and then returns the displacement of the person
    /// @return the facing of the person and a pair of ints of the displacement of the person
    [[nodiscard]] std::pair<Facing, std::pair<int, int> > executeCommand(Facing) const;
};



#endif //DMSIM_COMMAND_H
