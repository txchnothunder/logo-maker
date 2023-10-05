//
// Created by Ethan Wong on 3/18/23.
//

#ifndef CS008MIDTERMPROJECT_MOUSEEVENTS_CPP
#define CS008MIDTERMPROJECT_MOUSEEVENTS_CPP

#include "MouseEvents.h"

template<class T>
bool MouseEvents<T>::mouseClicked(T &object, sf::RenderWindow &window, sf::Event event) {
    return (mouseClicked(window, event) && hovered(object, window));
}

template<class T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow &window, sf::Event event) {
    return (sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left);
}

template<class T>
bool MouseEvents<T>::hovered(T &object, sf::RenderWindow &window) {
    sf::Vector2f mpos = (sf::Vector2f)sf::Mouse::getPosition(window);
    return object.getGlobalBounds().contains(mpos);
}

#endif //CS008MIDTERMPROJECT_MOUSEEVENTS_CPP
