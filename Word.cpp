//
// Created by Ethan Wong on 3/23/23.
//

#include "Word.h"

Word::Word() : Word("") {

}

Word::Word(std::string str) : Word(str, "OpenSans-Bold.ttf", sf::Color::White, 32){

}

Word::Word(std::string str, std::string inputFont, sf::Color color, float size) {
    this->str = str;
    font.loadFromFile(inputFont);

    text.setString(str);
    text.setFont(font);
    text.setCharacterSize(size);
    text.setFillColor(color);
}

const std::string &Word::getText() const {
    return str;
}

void Word::setText(const std::string &text) {
    str = text;
    this->text.setString(text);
}

int Word::getPriority() const {
    return priority;
}

void Word::setPriority(int priority) {
    Word::priority = priority;
}

void Word::setFillColor(sf::Color color) {
    text.setFillColor(color);
}

void Word::setFont(std::string inputFont) {
    font.loadFromFile(inputFont);
    text.setFont(font);
}

void Word::setCharacterSize(float size) {
    text.setCharacterSize(size);
}

sf::FloatRect Word::getGlobalBounds() {
    return text.getGlobalBounds();
}

void Word::setPosition(float x, float y) {
    setPosition({x, y});
}

void Word::setPosition(sf::Vector2f v) {
    text.setPosition(v);
}

bool operator!=(const Word &lhs, const Word &rhs) {
    return lhs.priority != rhs.priority;
}

bool operator==(const Word &lhs, const Word &rhs) {
    return lhs.priority == rhs.priority;
}

bool operator<(const Word &lhs, const Word &rhs) {
    return lhs.priority < rhs.priority;
}

bool operator>(const Word &lhs, const Word &rhs) {
    return lhs.priority > rhs.priority;
}

bool operator<=(const Word &lhs, const Word &rhs) {
    return lhs.priority <= rhs.priority;
}

bool operator>=(const Word &lhs, const Word &rhs) {
    return lhs.priority >= rhs.priority;
}

void Word::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(text);
}

void Word::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void Word::update() {

}

Snapshot *Word::getSnapshot() {
    return nullptr;
}

void Word::applySnapshot(const Snapshot *snapshot) {

}
