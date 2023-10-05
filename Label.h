//
// Created by Ethan Wong on 3/18/23.
//

#ifndef CS008MIDTERMPROJECT_LABEL_H
#define CS008MIDTERMPROJECT_LABEL_H

#include <SFML/Graphics.hpp>
#include <string>

class Label : public sf::Drawable {
private:
    sf::Text text;
    sf::Font font;
public:
    Label();
    Label(const std::string &str);
    sf::FloatRect getGlobalBounds();
    void setLabelSize(float size);
    void setPosition(float x, float y);
    void setString(std::string str);
    void center();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //CS008MIDTERMPROJECT_LABEL_H
