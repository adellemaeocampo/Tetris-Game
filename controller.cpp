#include "controller.h"
#include <iostream>
#include <thread>
#include <chrono>

Controller::Controller() : board() {}

void Controller::startGame() {
    std::cout << "Starting Tetris..." << std::endl;
    gameLoop();
}

void Controller::gameLoop() {
    while (!isGameOver()) {
        board.spawnBlock();
        while (board.moveBlockDown()) {
            board.display();
            handleInput();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        board.fixBlock();
        board.clearFullLines();
        board.display();
    }
    std::cout << "Game Over!" << std::endl;
}

void Controller::handleInput() {
    if (std::cin.rdbuf()->in_avail() > 0) {
        char input;
        std::cin >> input;
        switch (input) {
            case 'a': board.moveBlockLeft(); break;
            case 'd': board.moveBlockRight(); break;
            case 's': board.moveBlockDown(); break;
            case 'w': board.rotateBlock(); break;
            default: break;
        }
    }
}

bool Controller::isGameOver() {
    return board.isGameOver();
}
