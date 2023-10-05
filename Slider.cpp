//
// Created by Ethan Wong on 4/22/23.
//

#include "Slider.h"


Slider::Slider() : Slider("Test", 0, 255, 255, {0,0} ){

}

Slider::Slider(std::string text, int min, int max, float length, sf::Vector2f pos) : slider(min, max, length) {
    font.loadFromFile("OpenSans-Bold.ttf");

    this->text.setString(text);
    this->text.setFont(font);
    this->text.setCharacterSize(32);
    this->text.setFillColor(sf::Color::White);

    number.setString(std::to_string(min));
    number.setFont(font);
    number.setCharacterSize(32);
    number.setFillColor(sf::Color::White);

    setPosition(pos);
}

int Slider::getValue() {
    return slider.getValue();
}

void Slider::setPosition(sf::Vector2f pos) {
    text.setPosition(pos);
    slider.setPosition({text.getPosition().x + text.getGlobalBounds().width + 20,
                        text.getPosition().y + (text.getGlobalBounds().height/2)});
    number.setPosition({slider.getPosition().x + slider.getGlobalBounds().width + 20, text.getPosition().y});
}

sf::FloatRect Slider::getGlobalBounds() {
    sf::FloatRect bounds(text.getPosition(),
                         {text.getGlobalBounds().width + slider.getGlobalBounds().width + number.getGlobalBounds().width,
                          text.getGlobalBounds().height + slider.getGlobalBounds().height + number.getGlobalBounds().height});
    return bounds;
}

sf::Vector2f Slider::getPosition() {
    return text.getPosition();
}

void Slider::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(text);
    window.draw(slider);
    window.draw(number);
}

void Slider::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    slider.addEventHandler(window, event);
}

void Slider::update() {
    number.setString(std::to_string(slider.getValue()));
}

Snapshot *Slider::getSnapshot() {
    return nullptr;
}

void Slider::applySnapshot(const Snapshot *snapshot) {

}
