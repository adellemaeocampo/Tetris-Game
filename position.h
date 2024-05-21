#pragma once 

#include "game.h"
#include "board.h"
#include "block.h"
#include "grid.h"
#include "position.h"

class Position 
{
    public: 
        Position(int row, int column);
        int row;
        int column;
};