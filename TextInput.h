//
// Created by Ethan Wong on 3/18/23.
//

#ifndef CS008MIDTERMPROJECT_TEXTINPUT_H
#define CS008MIDTERMPROJECT_TEXTINPUT_H

#include <SFML/Graphics.hpp>
#include "Label.h"
#include "Textbox.h"
#include "GUIComponent.h"
#include "States.h"
#include <string>

class TextInput : public GUIComponent {
private:
    Label label;
    Textbox textbox;

    float labelMargin = 20;
public:
    TextInput();
    TextInput(const std::string &str);

    void setLabelSize(float size);
    void setLabelMargin(float margin);
    void setPosition(sf::Vector2f pos);
    void setSize(sf::Vector2f size);
    void setString(std::string text);

    const std::string& getText();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008MIDTERMPROJECT_TEXTINPUT_H
