//
// Created by gusw1 on 9/30/2025.
//

#ifndef DMSIM_ENUMS_H
#define DMSIM_ENUMS_H


enum Facing {
    HTs, MVs, SS, PB, HTsSS, HTsPB, MVsSS, MVsPB,
};

enum StepType {
    march, pivot, turnStep, halfMarch, legato
};

enum Direction {
    left, right, backward, forward, leftForward, rightForward, leftBackward, rightBackward,
};

#endif //DMSIM_ENUMS_H