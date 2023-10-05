//
// Created by Ethan Wong on 3/18/23.
//

#ifndef CS008MIDTERMPROJECT_TEXTBOX_H
#define CS008MIDTERMPROJECT_TEXTBOX_H

#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "Multitext.h"
#include "MouseEvents.h"
#include "TextCursor.h"

class Textbox : public GUIComponent {
private:
    sf::RectangleShape rect;
    Multitext text;
    TextCursor cursor;
    bool clickedOn = false;
public:
    Textbox();
    Textbox(float width, float height, sf::Color color);
    void setPosition(float x, float y);

    sf::FloatRect getGlobalBounds();
    void setSize(sf::Vector2f size);
    void setString(std::string text);

    const std::string &getText() const;

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008MIDTERMPROJECT_TEXTBOX_H
