#pragma once

#ifndef GAME_H
#define GAME_H
#include "game.h"
#include "board.h"
#include "block.h"
#include "grid.h"
#include "position.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Game
{
public:
    Game();
    ~Game();
    
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    bool gameOver;
    int score;

private:
    void MoveBlockLeft();
    void MoveBlockRight();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);

    Grid grid;
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;

    sf::RenderWindow window;
    sf::Font font;
    sf::Text scoreText;
};

#endif