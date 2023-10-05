//
// Created by Ethan Wong on 3/18/23.
//

#include "Label.h"

Label::Label() : Label("") {

}

Label::Label(const std::string &str) {
    font.loadFromFile("OpenSans-Bold.ttf");
    text.setFont(font);

    text.setString(str);
    text.setFillColor(sf::Color::White);
    text.setPosition(0, 0);

}

sf::FloatRect Label::getGlobalBounds() {
    return text.getGlobalBounds();
}

void Label::setLabelSize(float size) {
    text.setCharacterSize(size);
}

void Label::setPosition(float x, float y) {
    text.setPosition(x, y);
}

void Label::setString(std::string str) {
    text.setString(str);
}

void Label::center() {
    text.setOrigin(text.getGlobalBounds().left + text.getGlobalBounds().width/2.0f,
                    text.getGlobalBounds().top  + text.getGlobalBounds().height/2.0f);
}

void Label::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(text);
}

