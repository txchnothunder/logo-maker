//
// Created by Ethan Wong on 3/15/23.
//

#ifndef SFMLTUTORIAL_STATES_H
#define SFMLTUTORIAL_STATES_H

#include <map>

enum statesEnum
{
    HIDDEN,
    ENABLED,
    LAST_STATE
};

class States {
private:
    std::map<statesEnum, bool> bools;
    /*
     * Maps have key-value pairs
     * Keys have to be unique
     *      Each key is associated with a value
     * You can iterate through a map
     * First in <> is key data type, second is value data type
     */
public:
    States();

    void enableState(statesEnum state);
    void disableState(statesEnum state);
    bool checkStates(statesEnum state) const;
    void toggleState(statesEnum state);

};


#endif //SFMLTUTORIAL_STATES_H
