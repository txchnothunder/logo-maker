//
// Created by Ethan Wong on 3/18/23.
//

#ifndef CS008MIDTERMPROJECT_HISTORY_H
#define CS008MIDTERMPROJECT_HISTORY_H

#include "GUIComponent.h"
#include <stack>

struct HistoryNode
{
    GUIComponent* component;
    Snapshot* snapshot;
};

static std::stack<HistoryNode> stack;   //ERROR? Has to be initialized outside the class

class History  {
public:
    static void push(HistoryNode& node);
    static void pop();
    static HistoryNode& top();
    static bool empty();

    static void applySnapshot();

    //static void addEventHandler(sf::RenderWindow& window, sf::Event event);
};



#endif //CS008MIDTERMPROJECT_HISTORY_H
