//
// Created by Ethan Wong on 4/27/23.
//

#ifndef CS008FINALPROJECT_ANIMATIONMAKER_H
#define CS008FINALPROJECT_ANIMATIONMAKER_H

#include <vector>

#include "Maker.h"
#include "LogoMaker.h"
#include "Item.h"

class AnimationMaker : public Maker {
private:
    std::vector<LogoMaker*> pages;
    mutable LogoMaker* currentPage;
    int currentPagePos;
    mutable int playingPagePos = 0;
    Item addButton;

    bool playing = false;

    sf::Texture leftTexture, rightTexture, playTexture, pauseTexture;
    sf::Sprite leftArrow, rightArrow, playButton;
    Label label;

    Make make = animation;

    void addPage();
    void nextPage();
    void prevPage();
public:
    AnimationMaker();

    Maker* at(int pos);
    int size();

    virtual std::string getText();
    std::string getText(int pos);
    virtual Make getMake();
    void setPagePos(int pos);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008FINALPROJECT_ANIMATIONMAKER_H
