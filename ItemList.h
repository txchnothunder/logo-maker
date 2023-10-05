//
// Created by Ethan Wong on 3/25/23.
//

#ifndef CS008MIDTERMPROJECT_ITEMLIST_H
#define CS008MIDTERMPROJECT_ITEMLIST_H

#include "Item.h"
#include <vector>

class ItemList : public GUIComponent {
private:
    std::vector<Item*> list;
    std::string font;
    float width, height, size;
    sf::Color color;
public:
    ItemList();
    ItemList(std::string inputFont, float width, float height, sf::Color color, float size);
    void addItem(std::string str);
    void popItem();
    void setPosition(float x, float y) const;
    void setSize(sf::Vector2f size);

    //void setInfo(sf::RectangleShape inputRect, sf::Text inputText);
    const std::vector<Item *> &getList() const;

    Item& at(int pos);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008MIDTERMPROJECT_ITEMLIST_H
