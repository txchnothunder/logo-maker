//
// Created by Ethan Wong on 3/18/23.
//

#include "TextInput.h"

TextInput::TextInput() : TextInput("") {

}

TextInput::TextInput(const std::string &str) : label(str) {
    textbox.setPosition(label.getGlobalBounds().left + label.getGlobalBounds().width + labelMargin, label.getGlobalBounds().top);
}

void TextInput::setLabelSize(float size) {
    label.setLabelSize(size);
}

void TextInput::setLabelMargin(float margin) {
    labelMargin = margin;
}

void TextInput::setPosition(sf::Vector2f pos) {
    label.setPosition(pos.x, pos.y);
}

void TextInput::setSize(sf::Vector2f size) {
    textbox.setSize(size);
}

void TextInput::setString(std::string text) {
    textbox.setString(text);
}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(label);
    window.draw(textbox);
}

void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    textbox.addEventHandler(window, event);
}

void TextInput::update() {
    textbox.setPosition(label.getGlobalBounds().left + label.getGlobalBounds().width + 20, label.getGlobalBounds().top);
    textbox.update();
}

Snapshot *TextInput::getSnapshot() {
    return nullptr;
}

void TextInput::applySnapshot(const Snapshot *snapshot) {

}

const std::string &TextInput::getText() {
    return textbox.getText();
}
