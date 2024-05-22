#include "board.h"




Board::Board() : window(sf::VideoMode(400, 600), "Tetris"), score(20) {
  // Load font from the local directory
  if (!font.loadFromFile("Arial.ttf")) {
      throw std::runtime_error("Failed to load font");
  }




  // Initialize title text
  title.setFont(font);
  title.setCharacterSize(28);
  title.setString("TETRIS");
  title.setFillColor(sf::Color::White);
  title.setPosition(150, 10);




  // Initialize score text
  scoreText.setFont(font);
  scoreText.setCharacterSize(24);
  scoreText.setFillColor(sf::Color::White);
  scoreText.setPosition(300, 10);
}




void Board::draw() {
  window.clear(sf::Color::Black);




  // Update score text
  scoreText.setString("Score: " + std::to_string(score));




  // Draw title and score text
  window.draw(title);
  window.draw(scoreText);




  // Draw Tetris board (to be implemented)




  window.display();
}




void Board::increaseScore(int points) {
  score += points;
}




sf::RenderWindow& Board::getWindow() {
  return window;
}
