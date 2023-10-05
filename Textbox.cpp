//
// Created by Ethan Wong on 3/18/23.
//

#include "Textbox.h"

Textbox::Textbox() : Textbox(600, 50, sf::Color::Black) {

}

Textbox::Textbox(float width, float height, sf::Color color) {
    rect.setSize({width, height});
    rect.setFillColor(color);
    rect.setOutlineColor({static_cast<sf::Uint8>(255-color.r),
                          static_cast<sf::Uint8>(255-color.b),
                           static_cast<sf::Uint8>(255-color.g)});
    rect.setOutlineThickness(3);
}

void Textbox::setPosition(float x, float y) {
    rect.setPosition(x, y);
    text.setPosition(x, y);
}

sf::FloatRect Textbox::getGlobalBounds() {
    return rect.getGlobalBounds();
}

void Textbox::setSize(sf::Vector2f size) {
    rect.setSize(size);
}

void Textbox::setString(std::string text) {
    this->text.setString(text);
}

void Textbox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(rect);
    window.draw(text);
    if (cursor.checkStates(HIDDEN) && cursor.checkStates(ENABLED))
        window.draw(cursor);
}

void Textbox::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<Textbox>::mouseClicked(*this, window, event))
        clickedOn = true;
    else if (MouseEvents<Textbox>::mouseClicked(window, event))
        clickedOn = false;
    if (clickedOn)
        text.addEventHandler(window, event);
}

void Textbox::update() {
    text.update();
    cursor.update();
    if (clickedOn)
        cursor.enableState(HIDDEN);
    else
        cursor.disableState(HIDDEN);
    if (text.empty())
        cursor.setPosition(rect.getPosition().x, rect.getPosition().y);
    else
        cursor.setPosition(text.getLastGlobalBounds().left+text.getLastGlobalBounds().width, rect.getPosition().y);
}

Snapshot *Textbox::getSnapshot() {
    return nullptr;
}

void Textbox::applySnapshot(const Snapshot *snapshot) {

}

const std::string &Textbox::getText() const {
    return text.getText();
}
