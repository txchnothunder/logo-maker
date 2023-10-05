//
// Created by Ethan Wong on 4/23/23.
//

#ifndef CS008FINALPROJECT_SLIDERCOMPONENT_H
#define CS008FINALPROJECT_SLIDERCOMPONENT_H

#include "GUIComponent.h"
#include "MouseEvents.h"

class SliderComponent : public GUIComponent {
private:
    sf::CircleShape knob;
    sf::RectangleShape line;
    int min, max;
public:
    SliderComponent();
    SliderComponent(int min, int max, float length);

    int getValue();
    void setPosition(sf::Vector2f pos);
    sf::FloatRect getGlobalBounds();
    sf::Vector2f getPosition();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008FINALPROJECT_SLIDERCOMPONENT_H
