//
// Created by Ethan Wong on 3/18/23.
//

#include "MultitextSnapshot.h"

MultitextSnapshot::MultitextSnapshot() {

}

MultitextSnapshot::MultitextSnapshot(std::list<Letter *> objects, sf::Color color, std::string font, float size,
                                     sf::Vector2f pos, std::string text) {
    _objects = objects;
    _color = color;
    _font = font;
    _size = size;
    _pos = pos;
    _text = text;
}

Snapshot *MultitextSnapshot::getSnapshot() {
    return nullptr;
}

void MultitextSnapshot::applySnapshot(const Snapshot *snapshot) {

}

const std::list<Letter *> &MultitextSnapshot::getObjects() const {
    return _objects;
}

void MultitextSnapshot::setObjects(const std::list<Letter *> &objects) {
    _objects = objects;
}

const sf::Color &MultitextSnapshot::getColor() const {
    return _color;
}

void MultitextSnapshot::setColor(const sf::Color &color) {
    _color = color;
}

const std::string &MultitextSnapshot::getFont() const {
    return _font;
}

void MultitextSnapshot::setFont(const std::string &font) {
    _font = font;
}

float MultitextSnapshot::getSize() const {
    return _size;
}

void MultitextSnapshot::setSize(float size) {
    _size = size;
}

const sf::Vector2f &MultitextSnapshot::getPos() const {
    return _pos;
}

void MultitextSnapshot::setPos(const sf::Vector2f &pos) {
    _pos = pos;
}

const std::string &MultitextSnapshot::getText() const {
    return _text;
}

void MultitextSnapshot::setText(const std::string &text) {
    _text = text;
}
