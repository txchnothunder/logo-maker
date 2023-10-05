//
// Created by Ethan Wong on 3/18/23.
//

#include "Multitext.h"

Multitext::Multitext() : Multitext(sf::Color::White, "OpenSans-Bold.ttf", 48) {

}

Multitext::Multitext(sf::Color color, std::string font, float size) {
    this->color = color;
    this->font = font;
    this->size = size;
}

Letter *Multitext::at(int pos) {
    int count = 0;
    for (Letter* letter : objects) {
        if (count == pos)
            return letter;
        count++;
    }
    return nullptr;
}

void Multitext::addLetter(char letter, sf::Color color, std::string font, float size) {
    text += letter;
    objects.push_back(new Letter(letter, color, font, size));
}

void Multitext::removeLetter() {
    if (!objects.empty()) {
        text = text.substr(0, text.length()-1);
        objects.pop_back();
    }
}

std::list<Letter*>::iterator Multitext::begin() {
    return objects.begin();
}

std::list<Letter*>::iterator Multitext::end() {
    return objects.end();
}

sf::FloatRect Multitext::getLastGlobalBounds() {
    if (!objects.empty())
        return (at(text.length()-1)->getGlobalBounds());
}

void Multitext::setPosition(float x, float y) {
    pos = {x, y};
}

void Multitext::setString(std::string text) {
    this->text = text;
    for (int i = 0; i < text.length(); i++) {
        objects.push_back(new Letter(text[i]));
    }
}

bool Multitext::empty() {
    return objects.empty();
}


void Multitext::changeColorWord(int start, const std::string& word, sf::Color color) {
    std::string textCopy = text.substr(start, text.length()-start-1);
    if (textCopy.find(word) != std::string::npos) {
        for (int i = textCopy.find(word) + start; i < textCopy.find(word) + word.length() + start; i++) {
            at(i)->setColor(color);
        }
    }
}


void Multitext::colorKeywords() {
    for (int i = 0; i < text.length(); i++) {
        if (text.at(i) == '+' || text.at(i) == '-' || text.at(i) == '*' || text.at(i) == '/'
        || text.at(i) == '=' || text.at(i) == '%' || text.at(i) == '^')
            at(i)->setColor(sf::Color::Green);
        else if (isdigit(text.at(i)))
            at(i)->setColor(sf::Color::Red);
        changeColorWord(i, "int", sf::Color::Blue);
        changeColorWord(i, "char", sf::Color::Blue);
        changeColorWord(i, "double", sf::Color::Blue);
        changeColorWord(i, "float", sf::Color::Blue);
    }
}

void Multitext::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode == 8) {  //Special Case: Backspace
            getSnapshot();
            removeLetter();
        }
        else if (event.text.unicode == 10) {    //Special Case: Enter
            getSnapshot();
            addLetter('\n', color, font, size);
        }
        else if (event.text.unicode < 128) {
            getSnapshot();
            addLetter(static_cast<char>(event.text.unicode), color, font, size);
        }
    }
}

void Multitext::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    float totalLetterSpacing = pos.x;
    for (Letter *letter : objects) {
        letter->setPosition(totalLetterSpacing, pos.y);
        window.draw(*letter);
        totalLetterSpacing += letter->getGlobalBounds().width + 5;
    }
}

void Multitext::update() {
    colorKeywords();
}


Snapshot *Multitext::getSnapshot() {
    Snapshot* returnSnapshot = dynamic_cast<Snapshot*>(new MultitextSnapshot(objects, color, font, size, pos, text));
    HistoryNode node = {this, returnSnapshot};
    History::push(node);
    return returnSnapshot;
}

void Multitext::applySnapshot(const Snapshot *snapshot) {
    const MultitextSnapshot *newSnapshot = dynamic_cast<const MultitextSnapshot*>(snapshot);
    objects = newSnapshot->getObjects();
    color = newSnapshot->getColor();
    font = newSnapshot->getFont();
    size = newSnapshot->getSize();
    pos = newSnapshot->getPos();
    text = newSnapshot->getText();
}

const std::string &Multitext::getText() const {
    return text;
}
