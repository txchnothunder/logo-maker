//
// Created by Ethan Wong on 3/25/23.
//

#ifndef CS008MIDTERMPROJECT_DROPDOWNMENU_H
#define CS008MIDTERMPROJECT_DROPDOWNMENU_H

#include "GUIComponent.h"
#include "InputBox.h"
#include "ItemList.h"

class DropdownMenu : public GUIComponent {
private:
    InputBox inputBox;
    ItemList itemList;
    bool itemListHidden = true;
    bool allowChanges = true;

public:
    DropdownMenu();
    DropdownMenu(const std::string &str);
    DropdownMenu(const std::string &str, std::string inputFont, float width, float height, sf::Color color, float size);

    void addDropdownMenuItem(const std::string &str);
    void setPosition(sf::Vector2f pos);
    void setSize(sf::Vector2f size);

    bool isItemListHidden();

    std::string getItem();

    sf::FloatRect getGlobalBounds();

    void toggleChanges();
    void enableChanges();
    void disableChanges();


    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008MIDTERMPROJECT_DROPDOWNMENU_H
