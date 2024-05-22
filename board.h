#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>


class Board {
private:
  sf::RenderWindow window;
  sf::Font font;
  sf::Text scoreText;
  sf::Text title;




  int score;




public:
  Board();
  void draw();
  void increaseScore(int points);
  sf::RenderWindow& getWindow();  // Getter for window
};




#endif /* BOARD_H */