//
// Created by gusw1 on 9/30/2025.
//

#include "Command.h"

#include <ostream>

Facing Command::newFacing(const Facing facing) const {
    switch (facing) {
        case HTs:
            switch (this->direction) {
                case left:
                    return SS;
                case right:
                    return PB;
                case backward:
                    return MVs;
                default:
                    break;
            }
            break;
        case MVs:
            switch (this->direction) {
                case left:
                    return PB;
                case right:
                    return SS;
                case backward:
                    return HTs;
                default:
                    break;
            }
            break;
        case SS:
            switch (this->direction) {
                case left:
                    return MVs;
                case right:
                    return HTs;
                case backward:
                    return PB;
                default:
                    break;
            }
            break;
        case PB:
            switch (this->direction) {
                case left:
                    return HTs;
                case right:
                    return MVs;
                case backward:
                    return SS;
                default:
                    break;
            }
            break;
        default: ;
    }
    return facing;
}

std::pair<int, int> Command::deltaStep(const Facing facing) const {
    std::pair result{0, 0};

    // Default step size: 2, or 1 if half march/legato
    const int stepSize = this->isHalfMarch ? 1 : 2;

    switch (facing) {
        case HTs:
            result.first = 0;
            result.second = -stepSize;
            break;

        case MVs:
            result.first = 0;
            result.second = stepSize;
            break;

        case SS:
            result.first = stepSize;
            result.second = 0;
            break;

        case PB:
            result.first = -stepSize;
            result.second = 0;
            break;
        default: ;
    }

    return result;
}


Command::Command(const StepType step, const Direction dir, const bool half) {
    this->stepType = step;
    this->direction = dir;
    this->isHalfMarch = half;
}

std::pair<Facing, std::pair<int, int> > Command::executeCommand(Facing facing) const {
    std::pair<Facing, std::pair<int, int> > result;
    Facing newFace = newFacing(facing);
    std::pair<int, int> change = deltaStep(newFace);
    switch (this->stepType) {
        case march:
            // can just step in direction of facing, half steps are handled by the deltaStep function
            result = std::make_pair(facing, change);
            break;

        case pivot:
            // handle turning steps
            result = std::make_pair(newFace, change);
            break;

        default:
            // optional: handle unknown case
            break;
    }
    return result;
}