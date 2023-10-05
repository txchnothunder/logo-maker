//
// Created by Ethan Wong on 4/11/23.
//

#include "FileNode.h"

void FileNode::reposition() const {
    sf::Vector2f pos = data.getPosition();
    pos.x += 25;    //Adding 25 for indentation
    pos.y = data.getGlobalBounds().top + data.getGlobalBounds().height;   //Finding the bottom of the icon

    if (!childrenHidden) {
        for (FileNode *c: children) {
            c->setPosition(pos);
            pos.y += c->getGlobalBounds().height;
            c->reposition();
        }
    }
}

FileNode::FileNode() : FileNode(file, "Empty",  {0,0}, sf::Color::Black){

}

FileNode::FileNode(image icon, std::string text) : FileNode(icon, text,  {0,0}, sf::Color::Black) {

}

FileNode::FileNode(image icon, std::string text, sf::Vector2f position, sf::Color color) : data(icon, text, position, color){
    enableState(HIDDEN);
    disableState(ENABLED);
}

void FileNode::setPosition(sf::Vector2f pos) {
    data.setPosition(pos);
}

sf::Vector2f FileNode::getPosition() {
    return data.getPosition();
}

int FileNode::size() {
    return children.size();
}

FileNode& FileNode::at(int pos) {
    return *children[pos];
}

bool FileNode::isChildrenHidden() {
    return false;
}

FileNode* FileNode::clickedMe(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<FileItem>::mouseClicked(data, window, event) && data.getIcon() == file)
        return this;
    if (!childrenHidden) {
        for (FileNode* c: children)
            c->clickedMe(window, event);
    }
}

image FileNode::getIcon() {
    return data.getIcon();
}

std::string FileNode::getText() {
    return data.getText();
}

void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(data);
    if (!childrenHidden) {
        for (const FileNode* child : children)
            child->draw(window, states);
    }
}

void FileNode::applySnapshot(const Snapshot *snapshot) {

}

void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    data.addEventHandler(window, event);
    if (MouseEvents<FileItem>::mouseClicked(data, window, event)) {
        childrenHidden = !childrenHidden;
    }
    if (!childrenHidden) {
        for (FileNode* c : children)
            c->addEventHandler(window, event);
    }
}

void FileNode::update() {
    reposition();
}

Snapshot *FileNode::getSnapshot() {
    return nullptr;
}

sf::FloatRect FileNode::getGlobalBounds() {
    sf::FloatRect b = data.getGlobalBounds();
    if (!childrenHidden) {
        for (FileNode* c : children) {
            b.height += c->getGlobalBounds().height;
        }
    }
    return b;
}

bool FileNode::isLeaf() const {
    if (children.empty())
        return true;
    return false;
}

FileItem &FileNode::getData() {
    return data;
}

void FileNode::setData(const FileItem &data) {
    this->data = data;
}

std::vector<FileNode *> &FileNode::getChildren() {
    return children;
}

FileNode::iterator FileNode::begin() {
    return children.begin();
}

FileNode::iterator FileNode::end() {
    return children.end();
}
