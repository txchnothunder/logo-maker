//
// Created by Ethan Wong on 4/25/23.
//

#include "Logo.h"

Logo::Logo(float width, float height) {
    /*
    text.setPosition(0,0);

    background.setPosition(0, 0);
    background.setSize({(float)window.getSize().x, (float)window.getSize().y});
        //Y needs to be edited so it's only part of the screen
        //Position should be adjusted too
    */

    text.setPosition(0,0);
    font.loadFromFile("OpenSans-Bold.ttf");
    text.setFont(font);

    background.setPosition(0, 0);
    background.setSize({width, height});
    setBackgroundColor(sf::Color::Black);

    shadowText.setPos({0, 0});
    shadowText.setFont("OpenSans-Bold.ttf");
}

void Logo::setText(std::string text) {
    this->text.setString(text);
}

void Logo::setTextSize(int size) {
    text.setCharacterSize(size);
}

void Logo::setTextColor(sf::Color color) {
    text.setFillColor(color);
}

void Logo::setFont(std::string font) {
    this->font.loadFromFile(font);
    text.setFont(this->font);
}

void Logo::setFont(sf::Font font) {
    this->font = font;
    text.setFont(font);
}

void Logo::setTextPos(sf::Vector2f pos) {
    text.setPosition(pos);
}

void Logo::setTextPos(float x, float y) {
    setTextPos({x,y});
}

void Logo::setShadowText(std::string text) {
    shadowText.setText(text);
}

void Logo::setShadowTextSize(int size) {
    shadowText.setFontSize(size);
}

void Logo::setShadowFont(std::string font) {
    this->font.loadFromFile(font);
    shadowText.setFont(font);
}

void Logo::setShadowTextPos(sf::Vector2f pos) {
    shadowText.setPos(pos);
}

void Logo::setShadowTextPos(float x, float y) {
    shadowText.setPos({x, y});
}

void Logo::setBackgroundColor(sf::Color color) {
    background.setFillColor(color);
}

void Logo::setPosition(sf::Vector2f pos) {
    background.setPosition(pos);
}

void Logo::setPosition(float x, float y) {
    setPosition({x, y});
}

void Logo::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(background);
    window.draw(text);
    shadowText.draw(window, states);
}

void Logo::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void Logo::update() {
    shadowText.update();
}

Snapshot *Logo::getSnapshot() {
    return nullptr;
}

void Logo::applySnapshot(const Snapshot *snapshot) {

}
