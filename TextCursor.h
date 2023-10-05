//
// Created by Ethan Wong on 3/20/23.
//

#ifndef CS008MIDTERMPROJECT_TEXTCURSOR_H
#define CS008MIDTERMPROJECT_TEXTCURSOR_H

#include "Letter.h"
#include "States.h"
#include "GUIComponent.h"

class TextCursor : public GUIComponent {
private:
    Letter letter;
    sf::Text text;
    sf::Font font;
    sf::Clock clock;
public:
    TextCursor();
    TextCursor(const sf::Color& color, const std::string& inputFont, float size);

    void setPosition(float x, float y);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot* getSnapshot();
    virtual void applySnapshot(const Snapshot* snapshot);
};


#endif //CS008MIDTERMPROJECT_TEXTCURSOR_H
