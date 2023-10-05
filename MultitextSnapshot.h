//
// Created by Ethan Wong on 3/18/23.
//

#ifndef CS008MIDTERMPROJECT_MULTITEXTSNAPSHOT_H
#define CS008MIDTERMPROJECT_MULTITEXTSNAPSHOT_H

#include "Snapshot.h"
#include "Letter.h"
#include <list>
#include <SFML/Graphics.hpp>

class MultitextSnapshot : public Snapshot {
private:
    std::list<Letter*> _objects;
    sf::Color _color;
    std::string _font;
    float _size;
    sf::Vector2f _pos ;
    std::string _text;
public:
    MultitextSnapshot();
    MultitextSnapshot(std::list<Letter *> objects, sf::Color color, std::string font, float size,
                      sf::Vector2f pos, std::string text);

    const std::list<Letter *> &getObjects() const;
    void setObjects(const std::list<Letter *> &objects);
    const sf::Color &getColor() const;
    void setColor(const sf::Color &color);
    const std::string &getFont() const;
    void setFont(const std::string &font);
    float getSize() const;
    void setSize(float size);
    const sf::Vector2f &getPos() const;
    void setPos(const sf::Vector2f &pos);
    const std::string &getText() const;
    void setText(const std::string &text);

    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008MIDTERMPROJECT_MULTITEXTSNAPSHOT_H
