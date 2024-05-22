#pragma once
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include "game.h"
#include "board.h"
#include "grid.h"
#include "position.h"


class Block {
private:
   int cellSize;
   int rotationState;
   std::vector<sf::Color> colors;  // Use SFML Color for colors
   int rowOffset;
   int colOffset;
   void rotate();
   void undoRotation();


public:
   Block();
   void draw(sf::RenderWindow &window);  // Accept RenderWindow for drawing
   int id;
   std::map<int, std::vector<Position>> cells;
};
