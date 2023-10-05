//
// Created by Ethan Wong on 3/23/23.
//

#ifndef CS008MIDTERMPROJECT_WORD_H
#define CS008MIDTERMPROJECT_WORD_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "GUIComponent.h"

class Word : public GUIComponent {
private:
    std::string str;
    int priority = 0;
    sf::Text text;
    sf::Font font;
public:
    Word();
    Word(std::string str);
    Word(std::string str, std::string inputFont, sf::Color color, float size);

    const std::string &getText() const;
    void setText(const std::string &text);
    int getPriority() const;
    void setPriority(int priority);
    void setFillColor(sf::Color color);
    void setFont(std::string inputFont);
    void setCharacterSize(float size);

    sf::FloatRect getGlobalBounds();

    void setPosition(float x, float y);
    void setPosition(sf::Vector2f v);

    friend bool operator !=(const Word& lhs, const Word& rhs);
    friend bool operator ==(const Word& lhs, const Word& rhs);
    friend bool operator <(const Word& lhs, const Word& rhs);
    friend bool operator >(const Word& lhs, const Word& rhs);
    friend bool operator <=(const Word& lhs, const Word& rhs);
    friend bool operator >=(const Word& lhs, const Word& rhs);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008MIDTERMPROJECT_WORD_H
