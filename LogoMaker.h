//
// Created by Ethan Wong on 4/25/23.
//

#ifndef CS008FINALPROJECT_LOGOMAKER_H
#define CS008FINALPROJECT_LOGOMAKER_H

#include "GUIComponent.h"
#include "Logo.h"
#include "TextInput.h"
#include "ColorPicker.h"
#include "DropdownMenu.h"
#include "Slider.h"
#include "Maker.h"

class LogoMaker : public Maker {
private:
    Logo logo;
    TextInput textInput;
    ColorPicker fontColorPicker;
    DropdownMenu dropdownMenu;
    ColorPicker backgroundColorPicker;
    Slider fontSize;
    Slider textXPos;
    Slider textYPos;
    Slider shadowTextXPos;
    Slider shadowTextYPos;

    Label textInputLabel;
    Label fontSettingsLabel;
    Label backgroundColorLabel;

    bool colorOrDropdownEnabled = false;

    Make make = Make::logo;

    void setLabel(Label& label, std::string str, sf::Vector2f pos);
public:
    LogoMaker();

    virtual std::string getText();
    virtual Make getMake();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008FINALPROJECT_LOGOMAKER_H
