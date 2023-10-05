//
// Created by Ethan Wong on 4/22/23.
//

#ifndef CS008FINALPROJECT_SLIDER_H
#define CS008FINALPROJECT_SLIDER_H

#include "GUIComponent.h"
#include "SliderComponent.h"

class Slider : public GUIComponent {
private:
    sf::Text text;
    sf::Text number;
    sf::Font font;
    SliderComponent slider;
public:
    Slider();
    Slider(std::string text, int min, int max, float length, sf::Vector2f pos);

    int getValue();
    void setPosition(sf::Vector2f pos);
    sf::FloatRect getGlobalBounds();
    sf::Vector2f getPosition();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();    //Slider should have snapshot
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008FINALPROJECT_SLIDER_H
