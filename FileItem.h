//
// Created by Ethan Wong on 4/4/23.
//

#ifndef CS008MIDTERMPROJECT_FILEITEM_H
#define CS008MIDTERMPROJECT_FILEITEM_H

#include "Item.h"
#include "Image.h"
#include <iostream>

class FileItem : public Item
{
private:
    //this is the folder or file icon
    sf::Sprite icon;
    sf::Text text;
    sf::Font font;
    sf::Texture texture;
    sf::RectangleShape rect;
    sf::Color color;
    float padding = 5;

    image _icon;

    bool clickedOn = false;
public:
    FileItem();
    FileItem(image icon);
    FileItem(image icon, std::string text, sf::Vector2f position, sf::Color color);

    sf::FloatRect getGlobalBounds();
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f pos);
    void setIcon(image icon);
    image getIcon();
    std::string getText();
    std::string getText() const;

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008MIDTERMPROJECT_FILEITEM_H
