//
// Created by Ethan Wong on 3/30/23.
//

#include "Menu.h"

Menu::Menu() : Menu("", "OpenSans-Bold.ttf", 300, 75, sf::Color::Black, 36) {

}

Menu::Menu(const std::string &str) : Menu(str, "OpenSans-Bold.ttf", 300, 75, sf::Color::Black, 36) {

}

Menu::Menu(const std::string &str, std::string inputFont, float width, float height, sf::Color color,
           float size) : inputBox(str, inputFont, width, height, color, size),
                         itemList(inputFont, width, height, color, size) {
}

void Menu::addMenuItem(const std::string &str) {
    itemList.addItem(str);
}

void Menu::setPosition(sf::Vector2f pos) {
    inputBox.setPosition(pos);
}

void Menu::setSize(sf::Vector2f size) {
    inputBox.setSize(size);
    itemList.setSize(size);
}

Item &Menu::at(int pos) {
    return itemList.at(pos);
}

sf::FloatRect Menu::getGlobalBounds() {
    return inputBox.getGlobalBounds();
}

void Menu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(inputBox);
    itemList.setPosition(inputBox.getGlobalBounds().left, inputBox.getGlobalBounds().top + inputBox.getGlobalBounds().height);
    if (!itemList.checkStates(HIDDEN))
        window.draw(itemList);
}

void Menu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    itemList.addEventHandler(window, event);
    if (MouseEvents<InputBox>::mouseClicked(inputBox, window, event)) {
        itemListHidden = false;
        itemList.enableState(ENABLED);
    }
    if (itemList.checkStates(ENABLED)) {
        for (Item *i : itemList.getList()) {
            if (MouseEvents<Item>::mouseClicked(*i, window, event)) {
                itemList.disableState(ENABLED);
                itemListHidden = true;
            }
        }
    }
}

void Menu::update() {
    if (itemListHidden) {
        itemList.enableState(HIDDEN);
    }
    else {
        itemList.disableState(HIDDEN);
    }
}

Snapshot *Menu::getSnapshot() {
    return nullptr;
}

void Menu::applySnapshot(const Snapshot *snapshot) {

}