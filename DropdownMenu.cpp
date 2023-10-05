//
// Created by Ethan Wong on 3/25/23.
//

#include "DropdownMenu.h"

DropdownMenu::DropdownMenu() : DropdownMenu("", "OpenSans-Bold.ttf", 300, 75, sf::Color::Black, 36) {

}

DropdownMenu::DropdownMenu(const std::string &str) : DropdownMenu(str, "OpenSans-Bold.ttf", 300, 75, sf::Color::Black, 36) {

}

DropdownMenu::DropdownMenu(const std::string &str, std::string inputFont, float width, float height, sf::Color color,
                           float size) : inputBox(str, inputFont, width, height, color, size),
                           itemList(inputFont, width, height, color, size) {
}

void DropdownMenu::addDropdownMenuItem(const std::string &str) {
    itemList.addItem(str);
}

void DropdownMenu::setPosition(sf::Vector2f pos) {
    inputBox.setPosition(pos);
}

void DropdownMenu::setSize(sf::Vector2f size) {
    inputBox.setSize(size);
    itemList.setSize(size);
}

bool DropdownMenu::isItemListHidden() {
    return itemListHidden;
}

std::string DropdownMenu::getItem() {
    return inputBox.getText();
}

sf::FloatRect DropdownMenu::getGlobalBounds() {
    return inputBox.getGlobalBounds();
}

void DropdownMenu::toggleChanges() {
    if (allowChanges)
        disableChanges();
    else
        enableChanges();
}

void DropdownMenu::enableChanges() {
    allowChanges = true;
}

void DropdownMenu::disableChanges() {
    allowChanges = false;
}

void DropdownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(inputBox);
    itemList.setPosition(inputBox.getGlobalBounds().left, inputBox.getGlobalBounds().top + inputBox.getGlobalBounds().height);
    if (!itemList.checkStates(HIDDEN))
        window.draw(itemList);
}

void DropdownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    itemList.addEventHandler(window, event);
    if (MouseEvents<InputBox>::mouseClicked(inputBox, window, event)) {
        itemListHidden = false;
        itemList.enableState(ENABLED);
    }
    if (itemList.checkStates(ENABLED)) {
        for (Item *i : itemList.getList()) {
            if (MouseEvents<Item>::mouseClicked(*i, window, event)) {
                if (allowChanges)
                    inputBox.setText(i->getText());
                itemList.disableState(ENABLED);
                itemListHidden = true;
            }
        }
    }
}

void DropdownMenu::update() {
    if (itemListHidden) {
        itemList.enableState(HIDDEN);
    }
    else {
        itemList.disableState(HIDDEN);
    }
}

Snapshot *DropdownMenu::getSnapshot() {
    return nullptr;
}

void DropdownMenu::applySnapshot(const Snapshot *snapshot) {

}
