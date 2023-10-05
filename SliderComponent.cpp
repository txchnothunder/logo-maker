//
// Created by Ethan Wong on 4/23/23.
//

#include "SliderComponent.h"

SliderComponent::SliderComponent() {

}

SliderComponent::SliderComponent(int min, int max, float length) {
    line.setSize({length, 5});
    line.setFillColor(sf::Color::White);

    knob.setRadius(10);
    knob.setOrigin(knob.getRadius(), knob.getRadius());
    knob.setFillColor(sf::Color::White);

    this->min = min;
    this->max = max;

    disableState(ENABLED);
}

int SliderComponent::getValue() {
    int knobPos = knob.getPosition().x - line.getGlobalBounds().left;
    return max * (knobPos / line.getGlobalBounds().width);
}

void SliderComponent::setPosition(sf::Vector2f pos) {
    line.setPosition(pos);
    knob.setPosition(pos);
}

sf::FloatRect SliderComponent::getGlobalBounds() {
    sf::FloatRect bounds(line.getPosition(),
                         {line.getGlobalBounds().width, knob.getGlobalBounds().height});
    return bounds;
}

sf::Vector2f SliderComponent::getPosition() {
    return line.getPosition();
}

void SliderComponent::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(knob);
    window.draw(line);
}

void SliderComponent::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<SliderComponent>::mouseClicked(*this, window, event)) {
       sf::Vector2i mpos = sf::Mouse::getPosition(window);
       knob.setPosition(mpos.x, knob.getPosition().y);
    }
}

void SliderComponent::update() {

}

Snapshot *SliderComponent::getSnapshot() {
    return nullptr;
}

void SliderComponent::applySnapshot(const Snapshot *snapshot) {

}
