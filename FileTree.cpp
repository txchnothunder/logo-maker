//
// Created by Ethan Wong on 4/11/23.
//

#include "FileTree.h"

void FileTree::push(FileNode *&root, std::string parent, std::string item, image icon) {
    FileNode *found = nullptr;
    if (search(parent, root) != nullptr) {
        found = search(parent, root);
        found->getChildren().push_back(createNode(icon, item));
        return;
    }
    else {
        for (int i = 0; i < root->getChildren().size(); i++) {
            if (!root->getChildren()[i]->isLeaf()) {
                push(root->getChildren()[i], parent, item, icon);
            }
        }
    }
    if (search(parent, this->root) == nullptr) {
        this->root->getChildren().push_back(createNode(folder, parent));
        found = search(parent, this->root);
        found->getChildren().push_back(createNode(icon, item));
    }
}

void FileTree::traverse(FileNode *&root, sf::RenderWindow &window, sf::Event event) {
    root->addEventHandler(window, event);
    if (!root->isLeaf()) {
        for (FileNode* item : root->getChildren()) {
            traverse(item, window, event);
        }
    }
}

void FileTree::update(FileNode *&root) {
    root->update();
    if (!root->isLeaf()) {
        for (FileNode* item : root->getChildren()) {
            update(item);
        }
    }
}

FileNode *FileTree::search(std::string path, FileNode *node) {
    if (path == root->getData().getText()) {
        return root;
    }
    else {
        auto iter = node->begin();
        for (; iter != node->end(); ++iter) {
            if((*iter)->getData().getText() == path) {
                return *iter;
            }
        }
    }
    return nullptr;
}

FileNode *FileTree::createNode(image icon, std::string item) {
    auto* p = new FileNode(icon, item);
    p->enableState(HIDDEN);
    p->disableState(ENABLED);
    return p;
}

FileTree::FileTree() {

}

void FileTree::push(std::string parent, std::string item, image icon) {
    if (root == nullptr) {
        root = new FileNode(folder, parent);
        root->disableState(HIDDEN);
        this->root->getChildren().push_back(createNode(icon, item));
    }
    else
        push(root, parent, item, icon);
}

FileNode* FileTree::clickedMe(sf::RenderWindow &window, sf::Event event) {
    if (!empty())
        return root->clickedMe(window, event);
    return nullptr;
}

bool FileTree::empty() {
    return (root == nullptr);
}

FileNode *FileTree::getRoot() {
    return root;
}

void FileTree::setPosition(sf::Vector2f pos) {
    root->setPosition(pos);
}

void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    root->draw(window, states);
}

void FileTree::applySnapshot(const Snapshot *snapshot) {

}

void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    root->addEventHandler(window, event);
}

void FileTree::update() {
    update(root);
}

Snapshot *FileTree::getSnapshot() {
    return nullptr;
}

