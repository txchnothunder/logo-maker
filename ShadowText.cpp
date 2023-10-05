//
// Created by Ethan Wong on 4/30/23.
//

#include "ShadowText.h"

ShadowText::ShadowText() : ShadowText("OpenSans-Bold.ttf", 48, {0,0}) {

}

ShadowText::ShadowText(std::string text) : ShadowText(text, 48, {0,0}) {

}

ShadowText::ShadowText(std::string text, int fontSize) : ShadowText(text, fontSize, {0,0}) {

}

ShadowText::ShadowText(std::string text, int fontSize, sf::Vector2f pos) {
    setText(text);
    setFontSize(fontSize);
    setPos(pos);
    color.a = 50;
    shadow.setFillColor(color);
}

void ShadowText::setText(std::string text) {
    shadow.setString(text);
}

void ShadowText::setFont(std::string font) {
    this->font.loadFromFile(font);
    shadow.setFont(this->font);
}

void ShadowText::setFontSize(int fontSize) {
    shadow.setCharacterSize(fontSize);
}

void ShadowText::setPos(sf::Vector2f pos) {
    shadow.setScale(1.f, -1.f);
    shadow.setPosition(pos.x, shadow.getGlobalBounds().height + pos.y);
}

sf::FloatRect ShadowText::getGlobalBounds() {
    return shadow.getGlobalBounds();
}

void ShadowText::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(shadow);
}

void ShadowText::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void ShadowText::update() {

}

Snapshot *ShadowText::getSnapshot() {
    return nullptr;
}

void ShadowText::applySnapshot(const Snapshot *snapshot) {

}
