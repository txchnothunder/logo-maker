//
// Created by Ethan Wong on 3/25/23.
//

#ifndef CS008MIDTERMPROJECT_INPUTBOXSNAPSHOT_H
#define CS008MIDTERMPROJECT_INPUTBOXSNAPSHOT_H

#include "Snapshot.h"
#include <list>
#include <SFML/Graphics.hpp>

class InputBoxSnapshot : public Snapshot {
private:
    sf::RectangleShape rect;
    sf::Text text;
    sf::Font font;
    sf::Color color;
public:
    InputBoxSnapshot();
    InputBoxSnapshot(sf::RectangleShape rect, sf::Text text, sf::Font font, sf::Color color);

    const sf::RectangleShape &getRect() const;

    void setRect(const sf::RectangleShape &rect);

    const sf::Text &getText() const;

    void setText(const sf::Text &text);

    const sf::Font &getFont() const;

    void setFont(const sf::Font &font);

    const sf::Color &getColor() const;

    void setColor(const sf::Color &color);

    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008MIDTERMPROJECT_INPUTBOXSNAPSHOT_H
