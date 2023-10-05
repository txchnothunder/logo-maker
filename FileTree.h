//
// Created by Ethan Wong on 4/11/23.
//

#ifndef CS008FINALPROJECT_FILETREE_H
#define CS008FINALPROJECT_FILETREE_H

#include "FileNode.h"

class FileTree : public GUIComponent
{
private:
    //the root node of the tree
    FileNode* root = nullptr;

    //finds the parent and add the item to the parent.
    // If the parent isn't found, a new parent is created
    void push(FileNode*& root, std::string parent, std::string item, image icon);

    //traverses the tree and adds the eventhandlers for each of the nodes
    void traverse(FileNode* &root, sf::RenderWindow& window, sf::Event event);
    void update(FileNode* &root);
    sf::Vector2f initPosition = {0, 0};

    FileNode* search(std::string item, FileNode* node);
    FileNode* createNode(image icon, std::string item);

    mutable float drawPadding = 0;

public:
    //constructors
    FileTree();

    //this is the public version of push
    void push(std::string parent, std::string item, image icon);

    FileNode* clickedMe(sf::RenderWindow& window, sf::Event event);

    bool empty();

    FileNode* getRoot();

    void setPosition(sf::Vector2f pos);

    //draws the root node of the tree
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //does nothing now
    virtual void applySnapshot(const Snapshot* snapshot);

    //calls the traverse function to add the event handlers to each node
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

    //does nothing now
    virtual void update();
    //does nothing now
    virtual Snapshot* getSnapshot();
};


#endif //CS008FINALPROJECT_FILETREE_H