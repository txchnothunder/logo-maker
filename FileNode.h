//
// Created by Ethan Wong on 4/11/23.
//

#ifndef CS008FINALPROJECT_FILENODE_H
#define CS008FINALPROJECT_FILENODE_H

#include "FileItem.h"
#include <vector>

class FileNode : public GUIComponent
{
private:
    FileItem data;
    std::vector<FileNode*> children;
    bool childrenHidden = true;

    //this is called in the draw function to reposition the children so they
    //are indented and below the parent
    void reposition() const;
public:
    typedef typename std::vector<FileNode*>::iterator iterator;
    FileNode();
    FileNode(image icon, std::string text);
    FileNode(image icon, std::string text, sf::Vector2f position, sf::Color color);

    FileNode* clickedMe(sf::RenderWindow& window, sf::Event event);
    image getIcon();
    std::string getText();

    void setPosition(sf::Vector2f pos);
    sf::Vector2f getPosition();

    int size();
    FileNode& at(int pos);
    bool isChildrenHidden();

    //this draws the node. This is a recursive function to draw all the children nodes as well
    // this will only draw the node's children when it is in the proper state
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //This is not currently used
    virtual void applySnapshot(const Snapshot* snapshot);

    //This calls the addEventHandler for all the children. It calls the toggleChildren function
    // when the node's data (FileItem) is clicked on
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    //does nothing now
    virtual void update();
    //does nothing now
    virtual Snapshot* getSnapshot();
    //does nothing now
    sf::FloatRect getGlobalBounds();
    //returns true if the node has no children, otherwise false
    bool isLeaf() const;
    //getters and setters
    FileItem &getData();
    void setData(const FileItem &data);
    std::vector<FileNode*>& getChildren();

    //iterators
    iterator begin();
    iterator end();

};


#endif //CS008FINALPROJECT_FILENODE_H