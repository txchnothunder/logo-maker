//
// Created by Ethan Wong on 3/20/23.
//

#include "TextCursor.h"

TextCursor::TextCursor() : TextCursor(sf::Color::White, "OpenSans-Bold.ttf", 48) {

}

TextCursor::TextCursor(const sf::Color &color, const std::string &inputFont, float size) {
    font.loadFromFile(inputFont);

    text.setString("|");
    text.setFillColor(color);
    text.setFont(font);
    text.setCharacterSize(size);
}

void TextCursor::setPosition(float x, float y) {
    text.setPosition({x, y});
}

void TextCursor::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(text);
}

void TextCursor::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void TextCursor::update() {
    if (clock.getElapsedTime() >= sf::milliseconds(500))
    {
        clock.restart();
        this->toggleState(ENABLED);
    }
}

Snapshot *TextCursor::getSnapshot() {
    return nullptr;
}

void TextCursor::applySnapshot(const Snapshot *snapshot) {

}
