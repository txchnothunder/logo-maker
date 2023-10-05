//
// Created by Ethan Wong on 3/16/23.
//

#include "History.h"

void History::push(HistoryNode &node) {
    stack.push(node);
}

void History::pop() {
    if (!empty())
    {
        Snapshot* p = stack.top().snapshot;
        applySnapshot();
        stack.pop();
        //delete p;     ERROR NEEDS VIRTUAL DESTRUCTOR
    }
}

HistoryNode &History::top() {
    return stack.top();
}

bool History::empty() {
    return stack.empty();
}

void History::applySnapshot() {
    stack.top().component->applySnapshot(stack.top().snapshot);
}

