//
// Created by Ethan Wong on 3/28/23.
//

#include "MenuBar.h"

MenuBar::MenuBar() : MenuBar("OpenSans-Bold.ttf", 300, 75, sf::Color::Black, 36) {

}

MenuBar::MenuBar(std::string inputFont, float width, float height, sf::Color color, float size) {
    font = inputFont;
    this->width = width;
    this->height = height;
    this->color = color;
    textSize = size;
}

void MenuBar::setSize(sf::Vector2f size) {
    for (Menu *i : menu)
        i->setSize(size);
}

void MenuBar::addItem(unsigned int index, std::string str) {
    if (index < menu.size())
        menu[index]->addMenuItem(str);
}

void MenuBar::addItemList(std::string name) {
    menu.push_back(new Menu(name,font, width, height, color, textSize));
}

void MenuBar::popItemList() {
    if (!menu.empty())
        menu.pop_back();
}

/*
void MenuBar::setPosition(float x, float y) const {
    setPosition({x, y});
}

void MenuBar::setPosition(sf::Vector2f pos) const {
    if (!menu.empty())
        menu[0]->setPosition(pos);
}
 */

Menu &MenuBar::at(int index) {
    return *menu[index];
}

int MenuBar::size() {
    return menu.size();
}

void MenuBar::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    /*
    if (!menu.empty()) {
        sf::Vector2f v = {menu[0]->getGlobalBounds().left,menu[0]->getGlobalBounds().top};
        for (DropdownMenu *i : menu) {
            i->setPosition(v);
            v = {v.x += menu[0]->getGlobalBounds().width, v.y};
            window.draw(*i);
        }
    } */

    if (!menu.empty()) {
        float spacing = menu[0]->getGlobalBounds().width;
        float startingX = 0;
        for (Menu *i : menu) {
            window.draw(*i);
            i->setPosition({startingX, 0});
            startingX += spacing;
        }
    }
}

void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    for (Menu *m : menu) {
        m->addEventHandler(window, event);
    }
}

void MenuBar::update() {
    for (Menu *i : menu) {
        i->update();
    }
}

Snapshot *MenuBar::getSnapshot() {
    return nullptr;
}

void MenuBar::applySnapshot(const Snapshot *snapshot) {

}
