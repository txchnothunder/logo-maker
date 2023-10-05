//
// Created by Ethan Wong on 3/25/23.
//

#include "ItemList.h"

ItemList::ItemList() : ItemList("OpenSans-Bold.ttf", 300, 75, sf::Color::Black, 36) {

}

ItemList::ItemList(std::string inputFont, float width, float height, sf::Color color, float size) {
    font = inputFont;
    this->width = width;
    this->height = height;
    this->color = color;
    this->size = size;
}

void ItemList::addItem(std::string str) {
    list.push_back(new Item(str, font, width, height, color, size));
}

void ItemList::popItem() {
    if (!list.empty())
        list.pop_back();
}

void ItemList::setPosition(float x, float y) const {
    if (!list.empty())
        list[0]->setPosition(x, y);
}

void ItemList::setSize(sf::Vector2f size) {
    for (Item *i : list)
        i->setSize(size);
}

/*
void ItemList::setInfo(sf::RectangleShape inputRect, sf::Text inputText) {
    for (Item *i : list) {
        i->setInfo(inputRect, inputText);
    }
    width = inputRect.getGlobalBounds().width;
    height = inputRect.getGlobalBounds().height;
    size = inputText.getCharacterSize();
    color = inputRect.getFillColor();
}
 */

void ItemList::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (!list.empty()) {
        sf::Vector2f v = {list[0]->getGlobalBounds().left,list[0]->getGlobalBounds().top};
        for (Item *i : list) {
            i->setPosition(v);
            v = {v.x, v.y += i->getGlobalBounds().height};
            window.draw(*i);
        }
    }
}

void ItemList::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    for (Item *i : list) {
        i->addEventHandler(window, event);
    }
}

void ItemList::update() {

}

Snapshot *ItemList::getSnapshot() {
    return nullptr;
}

void ItemList::applySnapshot(const Snapshot *snapshot) {

}

const std::vector<Item *> &ItemList::getList() const {
    return list;
}

Item& ItemList::at(int pos) {
    return *list.at(pos);
}
