//
// Created by Ethan Wong on 4/30/23.
//

#ifndef CS008FINALPROJECT_SHADOWTEXT_H
#define CS008FINALPROJECT_SHADOWTEXT_H

#include "GUIComponent.h"
#include <iostream>

class ShadowText : public GUIComponent {
private:
    sf::Text shadow;
    sf::Font font;
    sf::Color color = sf::Color::White;
    sf::Vector2f pos;
public:
    ShadowText();
    ShadowText(std::string text);
    ShadowText(std::string text, int fontSize);
    ShadowText(std::string text, int fontSize, sf::Vector2f pos);

    void setText(std::string text);
    void setFont(std::string font);
    void setFontSize(int fontSize);
    void setPos(sf::Vector2f pos);

    sf::FloatRect getGlobalBounds();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008FINALPROJECT_SHADOWTEXT_H
