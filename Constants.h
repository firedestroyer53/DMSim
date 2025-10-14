//
// Created by gusw1 on 9/30/2025.
//

#ifndef DMSIM_ENUMS_H
#define DMSIM_ENUMS_H

constexpr int NUM_RANKS = 12;
constexpr int NUM_FILES = 7;
constexpr int RANK_OFFSET = 50;
constexpr int FILE_OFFSET = 25;

enum Facing {
    HTs, MVs, SS, PB, HTsSS, HTsPB, MVsSS, MVsPB,
};

enum StepType {
    march, pivot, halt
};

enum Direction {
    left, right, backward, forward, leftForward, rightForward, leftBackward, rightBackward,
};

#endif //DMSIM_ENUMS_H
