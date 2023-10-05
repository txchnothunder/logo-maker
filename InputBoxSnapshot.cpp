//
// Created by Ethan Wong on 3/25/23.
//

#include "InputBoxSnapshot.h"

InputBoxSnapshot::InputBoxSnapshot() {

}

InputBoxSnapshot::InputBoxSnapshot(sf::RectangleShape rect, sf::Text text, sf::Font font, sf::Color color) {
    this->rect = rect;
    this->text = text;
    this->font = font;
    this->color = color;
}

Snapshot *InputBoxSnapshot::getSnapshot() {
    return nullptr;
}

void InputBoxSnapshot::applySnapshot(const Snapshot *snapshot) {

}

const sf::RectangleShape &InputBoxSnapshot::getRect() const {
    return rect;
}

void InputBoxSnapshot::setRect(const sf::RectangleShape &rect) {
    InputBoxSnapshot::rect = rect;
}

const sf::Text &InputBoxSnapshot::getText() const {
    return text;
}

void InputBoxSnapshot::setText(const sf::Text &text) {
    InputBoxSnapshot::text = text;
}

const sf::Font &InputBoxSnapshot::getFont() const {
    return font;
}

void InputBoxSnapshot::setFont(const sf::Font &font) {
    InputBoxSnapshot::font = font;
}

const sf::Color &InputBoxSnapshot::getColor() const {
    return color;
}

void InputBoxSnapshot::setColor(const sf::Color &color) {
    InputBoxSnapshot::color = color;
}
