#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>
#include <vector>

class Piece {
private:
    sf::RectangleShape block;
    std::vector<sf::Vector2f> positions;
    float dropSpeed;
    sf::Clock dropClock;

public:
    Piece();
    void update();
    void draw(sf::RenderWindow& window);
};

#endif /* PIECE_H */
