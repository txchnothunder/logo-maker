//
// Created by Ethan Wong on 3/18/23.
//

#ifndef CS008MIDTERMPROJECT_MULTITEXT_H
#define CS008MIDTERMPROJECT_MULTITEXT_H


#include <SFML/Graphics.hpp>

#include "Letter.h"
#include "GUIComponent.h"
#include <list>
#include <string>
#include "MultitextSnapshot.h"
#include "History.h"

#include <iostream>


class Multitext : public GUIComponent {
private:
    std::list<Letter*> objects;
    sf::Color color;
    std::string font;
    float size;
    sf::Vector2f pos = {0,0};
    std::string text;

    Letter* at(int pos);
    void changeColorWord(int start, const std::string& word, sf::Color color);

public:
    Multitext();
    Multitext(sf::Color color, std::string font, float size);

    void addLetter(char letter, sf::Color color, std::string font, float size);
    void removeLetter();
    std::list<Letter*>::iterator begin();
    std::list<Letter*>::iterator end();

    void colorKeywords();

    sf::FloatRect getLastGlobalBounds();
    void setPosition(float x, float y);
    void setString(std::string text);
    bool empty();

    const std::string &getText() const;

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);

};


#endif //CS008MIDTERMPROJECT_MULTITEXT_H
