//
// Created by Ethan Wong on 4/25/23.
//

#ifndef CS008FINALPROJECT_LOGO_H
#define CS008FINALPROJECT_LOGO_H

#include "GUIComponent.h"
#include "ShadowText.h"

class Logo : public GUIComponent {
private:
    sf::Text text;
    sf::Font font;
    ShadowText shadowText;
    sf::RectangleShape background;
public:
    Logo(float width, float height);

    void setText(std::string text);
    void setTextSize(int size);
    void setTextColor(sf::Color color);
    void setFont(std::string font);
    void setFont(sf::Font font);
    void setTextPos(sf::Vector2f pos);
    void setTextPos(float x, float y);

    void setShadowText(std::string text);
    void setShadowTextSize(int size);
    void setShadowFont(std::string font);
    void setShadowTextPos(sf::Vector2f pos);
    void setShadowTextPos(float x, float y);

    void setBackgroundColor(sf::Color color);

    void setPosition(sf::Vector2f pos);
    void setPosition(float x, float y);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008FINALPROJECT_LOGO_H
