//
// Created by Ethan Wong on 4/22/23.
//

#ifndef CS008FINALPROJECT_COLORPICKER_H
#define CS008FINALPROJECT_COLORPICKER_H

#include "GUIComponent.h"
#include "Slider.h"

class ColorPicker : public GUIComponent {
private:
    sf::RectangleShape square;
    sf::Color color;
    Slider hueSlider;
    Slider satSlider;
    Slider valSlider;

    sf::Color hsv(int hue, float sat, float val); //This code is copied from online
                                                  // Source: https://en.sfml-dev.org/forums/index.php?topic=7313.0

public:
    ColorPicker();

    sf::Color getColor();
    void setPosition(sf::Vector2f pos);
    void setColor(int h, float s, float v);
    void setSize(sf::Vector2f size);
    sf::FloatRect getGlobalBounds();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008FINALPROJECT_COLORPICKER_H
