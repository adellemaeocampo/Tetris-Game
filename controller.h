#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "board.h"

class Controller {
public:
    Controller();
    void startGame();
private:
    Board board;
    void gameLoop();
    void handleInput();
    bool isGameOver();
};

#endif
