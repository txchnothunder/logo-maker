//
// Created by Ethan Wong on 4/22/23.
//

#include "ColorPicker.h"

//HSV function is borrowed code:
    //Taken online from https://en.sfml-dev.org/forums/index.php?topic=7313.0
// hue: 0-360°; sat: 0.f-1.f; val: 0.f-1.f
sf::Color ColorPicker::hsv(int hue, float sat, float val)
{
    hue %= 360;
    while(hue<0)
        hue += 360;

    if(sat<0.f)
        sat = 0.f;
    if(sat>1.f)
        sat = 1.f;

    if(val<0.f)
        val = 0.f;
    if(val>1.f)
        val = 1.f;

    int h = hue/60;
    float f = float(hue)/60-h;
    float p = val*(1.f-sat);
    float q = val*(1.f-sat*f);
    float t = val*(1.f-sat*(1-f));

    switch(h)
    {
        default:
        case 0:
        case 6: return sf::Color(val*255, t*255, p*255);
        case 1: return sf::Color(q*255, val*255, p*255);
        case 2: return sf::Color(p*255, val*255, t*255);
        case 3: return sf::Color(p*255, q*255, val*255);
        case 4: return sf::Color(t*255, p*255, val*255);
        case 5: return sf::Color(val*255, p*255, q*255);
    }
}

ColorPicker::ColorPicker() : hueSlider("Hue: ", 0, 360, 200, {0,0}),
                            satSlider("Saturation: ", 0, 100, 200, {0,0}),
                            valSlider("Light: ", 0, 100, 200, {0,0})
{
    square.setSize({100, 100});
    square.setFillColor(sf::Color::Black);
    square.setOutlineColor(sf::Color::White);
    square.setOutlineThickness(2);

    hueSlider.enableState(HIDDEN);
    satSlider.enableState(HIDDEN);
    valSlider.enableState(HIDDEN);

    setPosition({100,100});
}

sf::Color ColorPicker::getColor() {
    return square.getFillColor();
}

void ColorPicker::setPosition(sf::Vector2f pos) {
    square.setPosition(pos);
    hueSlider.setPosition({pos.x, pos.y + square.getGlobalBounds().height});
    satSlider.setPosition({pos.x, hueSlider.getPosition().y + hueSlider.getGlobalBounds().height + 20});
    valSlider.setPosition({pos.x, satSlider.getPosition().y + satSlider.getGlobalBounds().height + 20});
}

void ColorPicker::setColor(int h, float s, float v) {
    square.setFillColor(hsv(h,s,v));
}

void ColorPicker::setSize(sf::Vector2f size) {
    square.setSize(size);
}

sf::FloatRect ColorPicker::getGlobalBounds() {
    return square.getGlobalBounds();
}

void ColorPicker::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(square);
    if (!hueSlider.checkStates(HIDDEN)) {
        window.draw(hueSlider);
        window.draw(satSlider);
        window.draw(valSlider);
    }
}

void ColorPicker::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<ColorPicker>::mouseClicked(*this, window, event)) {
        toggleState(ENABLED);
        hueSlider.toggleState(HIDDEN);
        satSlider.toggleState(HIDDEN);
        valSlider.toggleState(HIDDEN);
    }
    if (checkStates(ENABLED)) {
        hueSlider.addEventHandler(window, event);
        satSlider.addEventHandler(window, event);
        valSlider.addEventHandler(window, event);
    }
}

void ColorPicker::update() {
    if (checkStates(ENABLED)) {
        hueSlider.update();
        satSlider.update();
        valSlider.update();

        int hue = hueSlider.getValue();
        float sat = satSlider.getValue() / 100.f;
        float val = valSlider.getValue() / 100.f;

        setColor(hue, sat, val);
    }
}

Snapshot *ColorPicker::getSnapshot() {
    return nullptr;
}

void ColorPicker::applySnapshot(const Snapshot *snapshot) {

}
