//
// Created by Ethan Wong on 4/4/23.
//

#include "FileItem.h"

FileItem::FileItem() : FileItem(file, "Empty",  {0,0}, sf::Color::Black) {

}

FileItem::FileItem(image icon) : FileItem(icon, "Empty",  {0,0}, sf::Color::Black) {
    enableState(HIDDEN);
    disableState(ENABLED);
}

FileItem::FileItem(image icon, std::string text,  sf::Vector2f position, sf::Color color) {
    setIcon(icon);
    this->icon.setPosition(position);

    font.loadFromFile("OpenSans-Bold.ttf");
    this->text.setString(text);
    this->text.setFont(font);
    this->text.setPosition(position.x + padding + this->icon.getGlobalBounds().left
    + this->icon.getGlobalBounds().width, position.y);
    this->text.setCharacterSize(38);

    rect.setSize({this->text.getGlobalBounds().width + this->icon.getGlobalBounds().width + padding * 3,
                  this->icon.getGlobalBounds().height + padding});
    rect.setPosition(position);
    this->color = color;
    rect.setFillColor(color);
}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(rect);
    window.draw(icon);
    window.draw(text);
}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<FileItem>::hovered(*this, window))
        rect.setFillColor(sf::Color::Blue);
    else
        rect.setFillColor(color);
}

sf::FloatRect FileItem::getGlobalBounds() {
    //std::cout << rect.getGlobalBounds().height << '\n';
    return rect.getGlobalBounds();
}

sf::FloatRect FileItem::getGlobalBounds() const {
    return rect.getGlobalBounds();
}

sf::Vector2f FileItem::getPosition() const {
    return rect.getPosition();
}

void FileItem::setPosition(sf::Vector2f pos) {
    rect.setPosition(pos);
    icon.setPosition(pos);
    text.setPosition(pos.x + padding + icon.getGlobalBounds().width, pos.y);
}

void FileItem::setIcon(image icon) {
    _icon = icon;
    if (icon == file) {
        texture.loadFromFile("file.png");
        this->icon.setScale(0.1, 0.1);
    }
    else if (icon == folder) {
        texture.loadFromFile("folder.png");
        this->icon.setScale(0.05, 0.05);
    }
    this->icon.setTexture(texture);
}

image FileItem::getIcon() {
    return _icon;
}

std::string FileItem::getText() {
    return text.getString();
}

std::string FileItem::getText() const {
    return text.getString();
}

void FileItem::update() {
    Item::update();
}

Snapshot *FileItem::getSnapshot() {
    return Item::getSnapshot();
}

void FileItem::applySnapshot(const Snapshot *snapshot) {
    Item::applySnapshot(snapshot);
}
