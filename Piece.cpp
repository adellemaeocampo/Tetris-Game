#include "Piece.h"

Piece::Piece() : dropSpeed(0.5f) {
    block.setSize(sf::Vector2f(20, 20));
    block.setFillColor(sf::Color::Green);

    // Starting position for the piece
    positions.push_back(sf::Vector2f(180, 0));  // You can add more blocks for different shapes
}

void Piece::update() {
    if (dropClock.getElapsedTime().asSeconds() > dropSpeed) {
        for (auto& position : positions) {
            position.y += 20;  // Move the piece down by one block
        }
        dropClock.restart();
    }
}

void Piece::draw(sf::RenderWindow& window) {
    for (const auto& position : positions) {
        block.setPosition(position);
        window.draw(block);
    }
}
