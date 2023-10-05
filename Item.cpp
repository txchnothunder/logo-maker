//
// Created by Ethan Wong on 3/25/23.
//

#include "Item.h"

Item::Item() : Item("", "OpenSans-Bold.ttf", 300, 75, sf::Color::Black, 36) {

}

Item::Item(std::string str) : Item(str, "OpenSans-Bold.ttf", 300, 75, sf::Color::Black, 36){

}

Item::Item(std::string str, std::string inputFont, float width, float height, sf::Color color, float size) {
    font.loadFromFile(inputFont);

    rect.setSize({width, height});
    this->color = color;
    rect.setFillColor(color);

    text.setString(str);
    text.setFont(font);
    text.setCharacterSize(size);
    text.setPosition(rect.getPosition().x + rect.getSize().x / 2 -
    text.getGlobalBounds().width / 2, rect.getPosition().y + rect.getSize().y / 2 -
    text.getGlobalBounds().height / 2);
}

void Item::setPosition(float x, float y) {
    rect.setPosition({x,y});
    text.setPosition(rect.getPosition().x + rect.getSize().x / 2 -
                     text.getGlobalBounds().width / 2, rect.getPosition().y + rect.getSize().y / 2 -
                                                      text.getGlobalBounds().height / 2);
}

void Item::setPosition(sf::Vector2f v) {
    setPosition(v.x, v.y);
}

void Item::setSize(sf::Vector2f size) {
    rect.setSize(size);
}

sf::FloatRect Item::getGlobalBounds() {
    return rect.getGlobalBounds();
}

/*
void Item::setInfo(sf::RectangleShape inputRect, sf::Text inputText) {
    rect = inputRect;
    text = inputText;
    //font = inputText.getFont();
    color = inputRect.getFillColor();
} */



void Item::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(rect);
    window.draw(text);
}

std::string Item::getText() {
    return text.getString();
}

void Item::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<Item>::hovered(*this, window)) {
        rect.setFillColor(sf::Color::Blue);
    }
    else {
        rect.setFillColor(color);
    }
}

void Item::update() {

}

Snapshot *Item::getSnapshot() {
    return nullptr;
}

void Item::applySnapshot(const Snapshot *snapshot) {

}
