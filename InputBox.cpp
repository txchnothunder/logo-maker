//
// Created by Ethan Wong on 3/25/23.
//

#include "InputBox.h"

InputBox::InputBox() : InputBox("", "OpenSans-Bold.ttf", 300, 75, sf::Color::Black, 36) {

}

InputBox::InputBox(std::string str) : InputBox(str, "OpenSans-Bold.ttf", 300, 75, sf::Color::Black, 36){

}

InputBox::InputBox(std::string str, std::string inputFont, float width, float height, sf::Color color, float size) {
    font.loadFromFile(inputFont);

    rect.setSize({width, height});
    this->color = color;
    rect.setFillColor(color);
    rect.setOutlineColor({static_cast<sf::Uint8>(255-color.r),
                          static_cast<sf::Uint8>(255-color.b),
                          static_cast<sf::Uint8>(255-color.g)});
    rect.setOutlineThickness(3);

    text.setString(str);
    text.setFont(font);
    text.setCharacterSize(size);
    text.setPosition(rect.getPosition().x + rect.getSize().x / 2 -
                     text.getGlobalBounds().width / 2, rect.getPosition().y + rect.getSize().y / 2 -
                                                       text.getGlobalBounds().height / 2);
}

void InputBox::setPosition(float x, float y) {
    rect.setPosition({x,y});
    text.setPosition(rect.getPosition().x + rect.getSize().x / 2 -
                     text.getGlobalBounds().width / 2, rect.getPosition().y + rect.getSize().y / 2 -
                                                       text.getGlobalBounds().height / 2);
}

void InputBox::setPosition(sf::Vector2f v) {
    setPosition(v.x, v.y);
}

void InputBox::setSize(sf::Vector2f size) {
    rect.setSize(size);
}


void InputBox::setText(std::string str) {
    getSnapshot();
    text.setString(str);
    text.setPosition(rect.getPosition().x + rect.getSize().x / 2 -
                     text.getGlobalBounds().width / 2, rect.getPosition().y + rect.getSize().y / 2 -
                                                       text.getGlobalBounds().height / 2);
}

std::string InputBox::getText() {
    return text.getString();
}

sf::FloatRect InputBox::getGlobalBounds() const {
    return rect.getGlobalBounds();
}

void InputBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(rect);
    window.draw(text);
}

void InputBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void InputBox::update() {

}

Snapshot *InputBox::getSnapshot() {
    Snapshot* returnSnapshot = dynamic_cast<Snapshot*>(new InputBoxSnapshot(rect, text, font, color));
    HistoryNode node = {this, returnSnapshot};
    History::push(node);
    return returnSnapshot;
}

void InputBox::applySnapshot(const Snapshot *snapshot) {
    const InputBoxSnapshot *newSnapshot = dynamic_cast<const InputBoxSnapshot*>(snapshot);
    rect = newSnapshot->getRect();
    text = newSnapshot->getText();
    //font = newSnapshot->getFont();
    color = newSnapshot->getColor();
}

/*
void InputBox::setInfo(sf::RectangleShape inputRect, sf::Text inputText) {
    rect = inputRect;
    text = inputText;
    //font = inputText.getFont();
    color = inputRect.getFillColor();
}
 */
