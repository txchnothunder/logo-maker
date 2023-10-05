//
// Created by Ethan Wong on 3/23/23.
//

#include "Suggestion.h"

int Suggestion::heuristicFunction(std::string word, std::string input) {
    int priority = 0;
    if (input.length() > word.length())
        return priority;
    for (int i = 0; i < input.length(); i++) {
        if (i >= word.length())
            break;
        else if (tolower(word[i]) == tolower(input[i])){
            priority++;
        }
        else {
            priority = 0;
            break;
        }
    }
    return priority;
}

Suggestion::Suggestion() {
    //EMPTY
}

Suggestion::Suggestion(std::string filename, TextInput &textInput) : Suggestion(filename, textInput, sf::Color::White, "OpenSans-Bold.ttf", 32) {

}

Suggestion::Suggestion(std::string filename, TextInput &textInput, const sf::Color &color, const std::string &inputFont, float size) {
    FileReader<std::string> read(filename);
    for (int i = 0; i < read.size(); i++) {
        words.push_back(new Word(read.at(i)));
        words[i]->setFillColor(color);
        font.loadFromFile(inputFont);
        words[i]->setFont(inputFont);
        words[i]->setCharacterSize(size);
    }
    this->textInput = &textInput;
}

void Suggestion::setPriority(Word& word, std::string input) {
    word.setPriority(heuristicFunction(word.getText(), input));
}

void Suggestion::prioritize(std::string input) {
    sortedWords.clear();
    if (input.length() <= 0)
        return;
    setPriority(*words[0], input);
    Heap<Word> heap(*words[0]);
    for (int i = 1; i < words.size(); i++) {
        setPriority(*words[i], input);
        if (words[i]->getPriority() > 0)
            heap.push(*words[i]);
    }
    if (heap.size() == 1) {
        if (words[0]->getPriority() == 0)
            heap.pop();
    }
    while (!heap.empty()) {
        sortedWords.push_back(new Word(heap.top().getText()));
        heap.pop();
    }
}

const std::vector<Word*> &Suggestion::getSortedWords() const {
    return sortedWords;
}

void Suggestion::setPosition(sf::Vector2f pos) const {
    for (Word *w : sortedWords) {
        w->setPosition(pos.x, pos.y);
        pos.y += w->getGlobalBounds().height + 5;
    }
}

void Suggestion::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    setPosition({200, 200});        //ERROR HERE
    if (!sortedWords.empty()) {
        for (int i = 0; i < sortedWords.size(); i++)
            window.draw(*sortedWords[i]);
    }
}

void Suggestion::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void Suggestion::update() {
    prioritize(textInput->getText());
}

Snapshot *Suggestion::getSnapshot() {
    return nullptr;
}

void Suggestion::applySnapshot(const Snapshot *snapshot) {

}
