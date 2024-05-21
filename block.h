#pragma once
#include <vector>
#include <map>
#include "game.h"
#include "board.h"
#include "block.h"
#include "grid.h"
#include "position.h"


class block{
    private:
        int cellSize;
        int rotationState;
        std::vector<colour> colours;
        int rowOffset;
        int colOffset;
        void rotate();
        void UndoRotation();

    public:
        block();
        void draw();
        int id; 
        std::map<int, std::vector<position>> cells;
        




}; 