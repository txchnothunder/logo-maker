//
// Created by Ethan Wong on 3/23/23.
//

#ifndef CS008MIDTERMPROJECT_SUGGESTION_H
#define CS008MIDTERMPROJECT_SUGGESTION_H

#include "Word.h"
#include "FileReader.h"
#include "GUIComponent.h"
#include "Heap.h"
#include "TextInput.h"
#include <vector>
#include <iostream>
#include <cstring>

class Suggestion : public GUIComponent {
private:
    std::vector<Word*> words;
    std::vector<Word*> sortedWords;
    sf::Font font;
    TextInput* textInput;

    int heuristicFunction(std::string word, std::string input);    //Determines priority of word
    void setPriority(Word& word, std::string input);
public:
    Suggestion();
    Suggestion(std::string filename, TextInput &textInput);
    Suggestion(std::string filename, TextInput &textInput, const sf::Color &color, const std::string &inputFont, float size);
    void prioritize(std::string input);
    const std::vector<Word*> &getSortedWords() const;

    void setPosition(sf::Vector2f pos) const;

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008MIDTERMPROJECT_SUGGESTION_H
