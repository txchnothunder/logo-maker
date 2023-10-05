//
// Created by Ethan Wong on 4/25/23.
//

#include "LogoMaker.h"

void LogoMaker::setLabel(Label &label, std::string str, sf::Vector2f pos) {
    label.setString(str);
    label.setLabelSize(24);
    label.setPosition(pos.x, pos.y);
}

LogoMaker::LogoMaker() : logo(1500, 500),
    fontSize("Font Size", 0, 256, 200, {50, 700}),
    textXPos("Text X-Axis", 0, 1400, 200, {50, 800}),
    textYPos("Text Y-Axis", 0, 500, 200, {50, 900}),
    shadowTextXPos("Shadow Text Y-Axis", 0, 1400, 200, {600, 700}),
    shadowTextYPos("Shadow Text Y-Axis", 0, 500, 200, {600, 800})
{
    textInput.setPosition({50, 600});
    textInput.setSize({400, 50});

    fontColorPicker.setPosition({600, 600});
    fontColorPicker.setSize({50, 50});

    dropdownMenu.setPosition({700, 600});
    dropdownMenu.addDropdownMenuItem("Open Sans");
    dropdownMenu.addDropdownMenuItem("Arial");
    dropdownMenu.addDropdownMenuItem("Arcade");
    dropdownMenu.addDropdownMenuItem("Agent");
    dropdownMenu.setSize({300, 50});

    backgroundColorPicker.setSize({50, 50});
    backgroundColorPicker.setPosition({1050, 600});

    setLabel(textInputLabel, "Text Input", {50, 550});
    setLabel(fontSettingsLabel, "Font Settings", {600, 550});
    setLabel(backgroundColorLabel, "Background Color", {1150, 600});

    enableState(ENABLED);
}

std::string LogoMaker::getText() {
    return textInput.getText();
}

Make LogoMaker::getMake() {
    return make;
}

void LogoMaker::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(logo);

    if (checkStates(ENABLED)) {
        window.draw(textInput);
        window.draw(fontColorPicker);
        window.draw(dropdownMenu);
        window.draw(backgroundColorPicker);
        window.draw(fontSize);
        window.draw(textXPos);
        window.draw(textYPos);

        window.draw(textInputLabel);
        window.draw(fontSettingsLabel);
        window.draw(backgroundColorLabel);

        if (!colorOrDropdownEnabled) {
            window.draw(shadowTextXPos);
            window.draw(shadowTextYPos);
        }
    }
}

void LogoMaker::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    logo.addEventHandler(window, event);
    textInput.addEventHandler(window, event);
    fontColorPicker.addEventHandler(window, event);
    dropdownMenu.addEventHandler(window, event);
    backgroundColorPicker.addEventHandler(window, event);
    fontSize.addEventHandler(window, event);
    textXPos.addEventHandler(window, event);
    textYPos.addEventHandler(window, event);
    if (!colorOrDropdownEnabled) {
        shadowTextXPos.addEventHandler(window, event);
        shadowTextYPos.addEventHandler(window, event);
    }
}

void LogoMaker::update() {
    logo.update();
    textInput.update();
    fontColorPicker.update();
    dropdownMenu.update();
    backgroundColorPicker.update();
    fontSize.update();
    textXPos.update();
    textYPos.update();
    if (!colorOrDropdownEnabled) {
        shadowTextXPos.update();
        shadowTextYPos.update();
    }

    logo.setText(textInput.getText());
    logo.setShadowText(textInput.getText());
    logo.setTextColor(fontColorPicker.getColor());
    if (dropdownMenu.getItem() != "") {
        std::string fontName = dropdownMenu.getItem();
        if (fontName == "Arial") {
            logo.setFont("arial.ttf");
            logo.setShadowFont("arial.ttf");
        }
        else if (fontName == "Arcade") {
            logo.setFont("Arcade.ttf");
            logo.setShadowFont("Arcade.ttf");
        }
        else if (fontName == "Agent") {
            logo.setFont("Agent.ttf");
            logo.setShadowFont("Agent.ttf");
        }
        else {
            logo.setFont("OpenSans-Bold.ttf");
            logo.setShadowFont("OpenSans-Bold.ttf");
        }
    }
    logo.setBackgroundColor(backgroundColorPicker.getColor());
    logo.setTextSize(fontSize.getValue());
    logo.setShadowTextSize(fontSize.getValue());
    logo.setTextPos(textXPos.getValue(), textYPos.getValue());
    logo.setShadowTextPos(shadowTextXPos.getValue(), shadowTextYPos.getValue());

    if (backgroundColorPicker.checkStates(ENABLED) || fontColorPicker.checkStates(ENABLED)
        || !dropdownMenu.isItemListHidden())
        colorOrDropdownEnabled = true;
    else
        colorOrDropdownEnabled = false;
}

Snapshot *LogoMaker::getSnapshot() {
    return nullptr;
}

void LogoMaker::applySnapshot(const Snapshot *snapshot) {

}
