//
// Created by Ethan Wong on 4/26/23.
//

#ifndef CS008FINALPROJECT_MAKER_H
#define CS008FINALPROJECT_MAKER_H

#include "GUIComponent.h"
#include <string>

enum Make {
    logo, animation
};

class Maker : public GUIComponent {
public:
    virtual std::string getText() = 0;
    virtual Make getMake() = 0;
};


#endif //CS008FINALPROJECT_MAKER_H
