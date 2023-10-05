//
// Created by Ethan Wong on 4/25/23.
//

#include "MenuInterface.h"

void MenuInterface::pushMaker() {
    if (objects.count(currentMake->getText()) == 1) {
        objects.at(currentMake->getText()) = currentMake;
        return;
    }
    objects[currentMake->getText()] = currentMake;
    if (currentMake->getMake() == logo)
        files->push("Projects", currentMake->getText(), file);
    else {
        files->push("Projects", currentMake->getText(), folder);
        for (int pageNum = 0; pageNum < dynamic_cast<AnimationMaker*>(currentMake)->size(); pageNum++) {
            files->push(currentMake->getText(), currentMake->getText() + " - " +
            std::to_string(pageNum + 1), file);
        }
    }
    files->setPosition({400, 0});
}

MenuInterface::MenuInterface() {
    files = new FileTree;

    menu.addItemList("File");
    menu.addItem(0, "Close Project");
    menu.addItem(0, "New Logo");
    menu.addItem(0, "New Animation");
    menu.addItem(0, "Open Project");
    menu.addItem(0, "Save Project");
    menu.addItem(0, "Quit");

    menu.setSize({350, 50});
}

void MenuInterface::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (checkStates(ENABLED)) {
        window.draw(*files);
        return;
    }
    if (currentMake != nullptr) {
        window.draw(*currentMake);
    }
    window.draw(menu);
}

void MenuInterface::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (checkStates(ENABLED)) {
        files->addEventHandler(window, event);
        for (int i = 0; i < files->getRoot()->size(); i++) {
            if (files->getRoot()->at(i).getIcon() == file) {
                if (MouseEvents<FileNode>::mouseClicked(files->getRoot()->at(i), window, event)) {
                    currentMake = objects[files->getRoot()->at(i).getText()];
                    disableState(ENABLED);
                }
            }
            if (!files->getRoot()->at(i).isChildrenHidden() /*&& files->getRoot()->at(i).getIcon() == folder*/) {
                for (int j = 0; j < files->getRoot()->at(i).size(); j++)
                    if (MouseEvents<FileNode>::mouseClicked(files->getRoot()->at(i).at(j), window, event)) {
                        std::string text = files->getRoot()->at(i).at(j).getText();
                        currentMake = objects[text.substr(0, text.length()-4)];
                        dynamic_cast<AnimationMaker*>(currentMake)->setPagePos(static_cast<int>(text[text.length()-1]) - 49);
                        disableState(ENABLED);
                    }
            }
        }
    }
    if (currentMake != nullptr) {
        currentMake->addEventHandler(window, event);
    }
    menu.addEventHandler(window, event);

    if (MouseEvents<Item>::mouseClicked(menu.at(0).at(0), window, event)) {
        currentMake = nullptr;
    }
    else if (MouseEvents<Item>::mouseClicked(menu.at(0).at(1), window, event)) {
        currentMake = new LogoMaker;
    }
    else if (MouseEvents<Item>::mouseClicked(menu.at(0).at(2), window, event)) {
        currentMake = new AnimationMaker;
    }
    else if (MouseEvents<Item>::mouseClicked(menu.at(0).at(3), window, event)) {
        if (!files->empty())
            enableState(ENABLED);
    }
    else if (MouseEvents<Item>::mouseClicked(menu.at(0).at(4), window, event)) {
        if (currentMake != nullptr)
            pushMaker();
    }
    else if (MouseEvents<Item>::mouseClicked(menu.at(0).at(5), window, event)) {
        window.close();
    }
}

void MenuInterface::update() {
    menu.update();
    if (currentMake != nullptr) {
        currentMake->update();
    }
    if (checkStates(ENABLED))
        files->update();
}

Snapshot *MenuInterface::getSnapshot() {
    return nullptr;
}

void MenuInterface::applySnapshot(const Snapshot *snapshot) {

}