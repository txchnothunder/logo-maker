//
// Created by Ethan Wong on 3/25/23.
//

#ifndef CS008MIDTERMPROJECT_ITEM_H
#define CS008MIDTERMPROJECT_ITEM_H

#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "MouseEvents.h"
#include "TextCursor.h"
#include <string>

class Item : public GUIComponent {
private:
    sf::RectangleShape rect;
    sf::Text text;
    sf::Font font;
    sf::Color color;
public:
    Item();
    Item(std::string str);
    Item(std::string str, std::string inputFont, float width, float height, sf::Color color, float size);
    void setPosition(float x, float y);
    void setPosition(sf::Vector2f);
    void setSize(sf::Vector2f size);

    sf::FloatRect getGlobalBounds();
    //void setInfo(sf::RectangleShape inputRect, sf::Text inputText);
    std::string getText();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008MIDTERMPROJECT_ITEM_H
