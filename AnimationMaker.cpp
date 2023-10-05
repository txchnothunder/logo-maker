//
// Created by Ethan Wong on 4/27/23.
//

#include "AnimationMaker.h"

void AnimationMaker::addPage() {
    currentPagePos = pages.size();
    pages.push_back(new LogoMaker);
    currentPage = pages[currentPagePos];
}

void AnimationMaker::nextPage() {
    if (currentPagePos >= pages.size() - 1)
        currentPagePos = 0;
    else
        currentPagePos++;
}

void AnimationMaker::prevPage() {
    if (currentPagePos <= 0)
        currentPagePos = pages.size()-1;
    else
        currentPagePos--;
}

AnimationMaker::AnimationMaker() : addButton("Add Page") {
    leftTexture.loadFromFile("leftArrow.png");
    leftArrow.setTexture(leftTexture);
    leftArrow.setPosition({1250, 935});
    leftArrow.setScale(0.2, 0.2);

    rightTexture.loadFromFile("rightArrow.png");
    rightArrow.setTexture(rightTexture);
    rightArrow.setPosition({1350, 935});
    rightArrow.setScale(0.2, 0.2);

    playTexture.loadFromFile("play.png");
    pauseTexture.loadFromFile("pause.png");
    playButton.setTexture(playTexture);
    playButton.setPosition(1150, 935);
    playButton.setScale(0.2, 0.2);

    addButton.setPosition(850, 910);

    //label.center();
    label.setPosition((leftArrow.getGlobalBounds().left + leftArrow.getGlobalBounds().width +
                       rightArrow.getGlobalBounds().left) / 2, 935);

    addPage();
}

Maker *AnimationMaker::at(int pos) {
    if (pos <= pages.size() - 1)
        return pages[pos];
    else
        return pages[currentPagePos];
}

int AnimationMaker::size() {
    return pages.size();
}

std::string AnimationMaker::getText() {
    return pages[0]->getText();
}

std::string AnimationMaker::getText(int pos) {
    return std::string();
}

Make AnimationMaker::getMake() {
    return make;
}

void AnimationMaker::setPagePos(int pos) {
    currentPagePos = pos;
}

void AnimationMaker::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (playing) {
        currentPage = pages[playingPagePos];
        playingPagePos++;
        if (playingPagePos >= pages.size())
            playingPagePos = 0;
        currentPage->disableState(ENABLED);
    }
    else {
        currentPage = pages[currentPagePos];
        currentPage->enableState(ENABLED);
    }
    window.draw(label);
    window.draw(leftArrow);
    window.draw(rightArrow);
    window.draw(playButton);
    window.draw(addButton);

    window.draw(*currentPage);
}

void AnimationMaker::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    currentPage->addEventHandler(window, event);
    addButton.addEventHandler(window, event);
    if (MouseEvents<sf::Sprite>::mouseClicked(leftArrow, window, event))
        prevPage();
    if (MouseEvents<sf::Sprite>::mouseClicked(rightArrow, window, event))
        nextPage();
    if (MouseEvents<sf::Sprite>::mouseClicked(playButton, window, event)) {
        if (playing) {
            playButton.setTexture(playTexture);
        }
        else {
            playButton.setTexture(pauseTexture);
        }
        playing = !playing;
    }
    if (MouseEvents<Item>::mouseClicked(addButton, window, event))
        addPage();
}

void AnimationMaker::update() {
    currentPage->update();
    addButton.update();
    label.setString(std::to_string(currentPagePos + 1));
}

Snapshot *AnimationMaker::getSnapshot() {
    return nullptr;
}

void AnimationMaker::applySnapshot(const Snapshot *snapshot) {

}
