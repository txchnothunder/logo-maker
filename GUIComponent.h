//
// Created by Ethan Wong on 3/18/23.
//

#ifndef CS008MIDTERMPROJECT_GUICOMPONENT_H
#define CS008MIDTERMPROJECT_GUICOMPONENT_H

#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include "States.h"
#include "Snapshot.h"

class GUIComponent : public sf::Drawable, public EventHandler, public States, public Snapshot {
public:
    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

    //from Snapshot
    virtual Snapshot* getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot* snapshot) = 0;
};


#endif //CS008MIDTERMPROJECT_GUICOMPONENT_H
