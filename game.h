# pragma once
#include "grid.h"
#include "block.cpp"

class Game 
{
    public: 
        Game();
        ~Game();
        void Draw();
        void HandleInput();
        void MoveBlockDown();
        boot gameOver; 
        int score;

    private:
        void MoveBlockLeft();
        void MoveBlockRight();
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
}

