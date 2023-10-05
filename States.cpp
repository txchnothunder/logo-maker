//
// Created by Ethan Wong on 3/15/23.
//

#include "States.h"

States::States() {
    for (int i = 0; i < LAST_STATE; i++)
    {
        bools[static_cast<statesEnum>(i)] = false;
    }
}

void States::enableState(statesEnum state) {
    bools[state] = true;
}

void States::disableState(statesEnum state) {
    bools[state] = false;
}

bool States::checkStates(statesEnum state) const {
    return bools.at(state);
}

void States::toggleState(statesEnum state) {
    bools[state] = !bools[state];
}
