//
// Created by Ethan Wong on 3/28/23.
//

#ifndef CS008MIDTERMPROJECT_MENUBAR_H
#define CS008MIDTERMPROJECT_MENUBAR_H

#include "Menu.h"

class MenuBar : public GUIComponent {
private:
    std::vector<Menu*> menu;
    std::string font;
    float width, height, textSize;
    sf::Color color;

public:
    MenuBar();
    MenuBar(std::string inputFont, float width, float height, sf::Color color, float size);

    void setSize(sf::Vector2f size);

    void addItem(unsigned int index, std::string str);
    void addItemList(std::string name);
    void popItemList();

    //void setPosition(float x, float y) const;
    //void setPosition(sf::Vector2f pos) const;

    Menu& at(int index);
    int size();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008MIDTERMPROJECT_MENUBAR_H
