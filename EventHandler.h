//
// Created by Ethan Wong on 3/18/23.
//

#ifndef CS008MIDTERMPROJECT_EVENTHANDLER_H
#define CS008MIDTERMPROJECT_EVENTHANDLER_H

#include <SFML/Graphics.hpp>

class EventHandler
{
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};

#endif //CS008MIDTERMPROJECT_EVENTHANDLER_H
