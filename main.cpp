#include <SFML/Graphics.hpp>

#include "Application.h"

int main()
{
    Application app({1500, 1000, 32}, "CS008 Final Project");

    app.runMaker();

    return 0;
}

/*
 *  MIDTERM PROJECT
 *  Application app({1400, 1000, 32}, "CS008 Midterm Project");

    TextInput text1("First Name: ");
    text1.setLabelSize(52);
    TextInput text2("Last Name: ");
    text2.setLabelSize(52);
    text2.setPosition({0, 200});

    app.addDrawable(text1);
    app.addDrawable(text2);
    app.run();


 *  Suggestion
 *  Application app({1400, 1000, 32}, "CS008 Midterm Project");
    TextInput t("First Name: ");
    t.setPosition({0, 100});
    Suggestion ws("5000-baby-girl-names.txt", t);
    ws.setPosition({200, 200});
    app.addDrawable(t);
    app.addDrawable(ws);
    app.run();


 *  Dropdown Menu
 *  Application app({1400, 1000, 32}, "CS008 Midterm Project");

    DropdownMenu drop("Test");
    DropdownMenu drop2("Hai", "OpenSans-Bold.ttf", 500, 100, sf::Color::Black, 72);
    drop.addDropdownMenuItem("Test1");
    drop.addDropdownMenuItem("Test2");
    drop.addDropdownMenuItem("Test3");
    drop.setPosition({10, 10});
    drop2.addDropdownMenuItem("Apple");
    drop2.addDropdownMenuItem("Grapes");
    drop2.setPosition({500, 500});
    app.addDrawable(drop);
    app.addDrawable(drop2);
    app.run();

 *  Menu Bar
 *  Application app({1400, 1000, 32}, "CS008 Midterm Project");

    MenuBar menu;
    menu.addItemList("Menu 1");
    menu.addItemList("Menu 2");
    menu.addItemList("Menu 3");

    menu.addItem(0, "Menu 1 Item 1");
    menu.addItem(0, "Menu 1 Item 2");
    menu.addItem(0, "Menu 1 Item 3");

    menu.addItem(1, "Menu 2 Item 1");
    menu.addItem(1, "Menu 2 Item 2");
    menu.addItem(1, "Menu 2 Item 3");

    menu.addItem(2, "Menu 3 Item 1");
    menu.addItem(2, "Menu 3 Item 2");
    menu.addItem(2, "Menu 3 Item 3");

    app.addDrawable(menu);
    app.run();
 */