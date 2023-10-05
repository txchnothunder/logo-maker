//
// Created by Ethan Wong on 3/18/23.
//

#ifndef CS008MIDTERMPROJECT_LETTER_H
#define CS008MIDTERMPROJECT_LETTER_H

#include <SFML/Graphics.hpp>
#include <string>

class Letter : public sf::Text {
private:
    sf::Text text;
    sf::Font font;
public:
    Letter();
    Letter(char letter);
    Letter(char letter, const sf::Color& color, const std::string& inputFont, float size);

    void setPosition(float x, float y);
    void setColor(const sf::Color& color);
    sf::FloatRect getGlobalBounds();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //CS008MIDTERMPROJECT_LETTER_H
