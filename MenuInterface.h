//
// Created by Ethan Wong on 4/25/23.
//

#ifndef CS008FINALPROJECT_MENUINTERFACE_H
#define CS008FINALPROJECT_MENUINTERFACE_H

#include <vector>
#include <map>

#include "GUIComponent.h"
#include "Maker.h"
#include "MouseEvents.h"
#include "MenuBar.h"
#include "LogoMaker.h"
#include "AnimationMaker.h"
#include "FileTree.h"

class MenuInterface : public GUIComponent {
private:
    MenuBar menu;
    FileTree* files;
    std::map<std::string, Maker*> objects;
        //Should contain only LogoMaker and AnimationMaker
    Maker* currentMake = nullptr;

    void pushMaker();
public:
    MenuInterface();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008FINALPROJECT_MENUINTERFACE_H
