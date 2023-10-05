//
// Created by Ethan Wong on 3/18/23.
//

#include "Application.h"

Application::Application() : Application({720,420,32}, "Application") {

}

Application::Application(sf::VideoMode videoMode, std::string title) : window(videoMode, title) {
    window.setKeyRepeatEnabled(false);
}

void Application::runLoop() {
    while (window.isOpen())
    {
        eventListener();

        window.clear();
        for (GUIComponent* obj : objects)
        {
            window.draw(*obj);
            obj->update();
        }
        window.display();
    }
}

void Application::eventListener() {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
            window.close();
        if (KeyboardShortcuts::isUndo(window))
            History::pop();
        for (GUIComponent* obj: objects)
            obj->addEventHandler(window, event);
    }
}

void Application::addDrawable(GUIComponent &object) {
    objects.push_back(&object);
}

void Application::run() {
    runLoop();
}

void Application::runMaker() {
    MenuInterface menu;
    addDrawable(menu);

    run();
}

