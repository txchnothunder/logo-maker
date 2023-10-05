//
// Created by Ethan Wong on 3/25/23.
//

#ifndef CS008MIDTERMPROJECT_INPUTBOX_H
#define CS008MIDTERMPROJECT_INPUTBOX_H

#include "GUIComponent.h"
#include "InputBoxSnapshot.h"
#include "History.h"

class InputBox : public GUIComponent {
private:
    sf::RectangleShape rect;
    sf::Text text;
    sf::Font font;
    sf::Color color;
public:
    InputBox();
    InputBox(std::string str);
    InputBox(std::string str, std::string inputFont, float width, float height, sf::Color color, float size);

    void setPosition(float x, float y);
    void setPosition(sf::Vector2f);
    void setSize(sf::Vector2f size);

    void setText(std::string str);
    std::string getText();
    sf::FloatRect getGlobalBounds() const;

    //void setInfo(sf::RectangleShape inputRect, sf::Text inputText);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008MIDTERMPROJECT_INPUTBOX_H
