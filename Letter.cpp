//
// Created by Ethan Wong on 3/18/23.
//

#include "Letter.h"

Letter::Letter() : Letter('A', sf::Color::White, "OpenSans-Bold.ttf", 64){

}

Letter::Letter(char letter) : Letter(letter, sf::Color::White, "OpenSans-Bold.ttf", 64) {

}

Letter::Letter(char letter, const sf::Color &color, const std::string &inputFont, float size) {
    font.loadFromFile(inputFont);

    text.setString(letter);
    text.setFillColor(color);
    text.setFont(font);
    text.setCharacterSize(size);
}

void Letter::setPosition(float x, float y) {
    text.setPosition(x, y);
}

void Letter::setColor(const sf::Color &color) {
    text.setFillColor(color);
}

sf::FloatRect Letter::getGlobalBounds() {
    return text.getGlobalBounds();
}

void Letter::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(text);
}
