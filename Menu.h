//
// Created by Ethan Wong on 3/30/23.
//

#ifndef CS008MIDTERMPROJECT_MENU_H
#define CS008MIDTERMPROJECT_MENU_H

#include "GUIComponent.h"
#include "InputBox.h"
#include "ItemList.h"

class Menu : public GUIComponent {
private:
    InputBox inputBox;
    ItemList itemList;
    bool itemListHidden = true;

public:
    Menu();
    Menu(const std::string &str);
    Menu(const std::string &str, std::string inputFont, float width, float height, sf::Color color, float size);

    void addMenuItem(const std::string &str);
    void setPosition(sf::Vector2f pos);
    void setSize(sf::Vector2f size);

    Item& at(int pos);
    sf::FloatRect getGlobalBounds();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};

#endif //CS008MIDTERMPROJECT_MENU_H
