#include "block.h"

block::block(){

    cellSize = 30; // sets the cell size
    rotationState = 0; // sets the rotation state to 0 initially
    colours = get_colours(); // calls the colours function
    rowOffset = 0;
    colOffset = 0;
};

void block:: draw(){

    std::vector<position> tiles = getCellPositions;
    for(position item: tiles){
        drawRectangle(item.column*cellSize+1, item.row*cellSize+1, cellSize-1,cellSize-1,colours[id]);
    }
}


void block :: Move(int rows, int column){

    rowOffset += rows;
    colOffset += column;
    
}

std::vector<Position> block::getCellPositions(){

    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for(Position item: tiles){

        Position newPosition = Position(item.row + rowOffset, item.cols + colsOffset);
        movedTiles.push_back(newPosition)
    }
    return movedTiles
}

void block:rotate(){

    rotationState ++;
    if(rotationState == (int)cells.size()){
        rotationState = 0;
    }
}

void block: UndoRotation(){
    rotationState --;
    if(rotationState == -1){
        rotationState = cells.size() - 1;
    }
}
