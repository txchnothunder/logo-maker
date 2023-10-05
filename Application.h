//
// Created by Ethan Wong on 3/18/23.
//

#ifndef CS008MIDTERMPROJECT_APPLICATION_H
#define CS008MIDTERMPROJECT_APPLICATION_H

#include <SFML/Graphics.hpp>

#include "GUIComponent.h"
#include <vector>
#include <string>

#include "TextInput.h"
#include "KeyboardShortcuts.h"

#include "LogoMaker.h"
#include "AnimationMaker.h"
#include "MenuInterface.h"

class Application {

private:
    sf::RenderWindow window;
    std::vector<GUIComponent*> objects;

    void runLoop();
    void eventListener();

public:
    Application();
    Application(sf::VideoMode videoMode, std::string title);

    void addDrawable(GUIComponent &object);
    void run();

    void runMaker();
};


#endif //CS008MIDTERMPROJECT_APPLICATION_H
