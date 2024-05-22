#include "block.h"


Block::Block() : cellSize(30), rotationState(0), rowOffset(0), colOffset(0) {
   colors = {sf::Color::Black, sf::Color::Blue, sf::Color::Green, sf::Color::Red,
             sf::Color::Yellow, sf::Color::Cyan, sf::Color::Magenta, sf::Color::White};
}


void Block::draw(sf::RenderWindow& window) {
   std::vector<Position> tiles = getCellPositions();
   for (Position item : tiles) {
       sf::RectangleShape rectangle(sf::Vector2f(cellSize - 1, cellSize - 1));
       rectangle.setPosition(item.column * cellSize + 1, item.row * cellSize + 1);
       rectangle.setFillColor(colors[id]);
       window.draw(rectangle);
   }
}


void Block::move(int rows, int columns) {
   rowOffset += rows;
   colOffset += columns;
}


std::vector<Position> Block::getCellPositions() {
   std::vector<Position> tiles = cells[rotationState];
   std::vector<Position> movedTiles;
   for (Position item : tiles) {
       Position newPosition(item.row + rowOffset, item.column + colOffset);
       movedTiles.push_back(newPosition);
   }
   return movedTiles;
}


void Block::rotate() {
   rotationState++;
   if (rotationState == static_cast<int>(cells.size())) {
       rotationState = 0;
   }
}


void Block::undoRotation() {
   rotationState--;
   if (rotationState == -1) {
       rotationState = cells.size() - 1;
   }
}
