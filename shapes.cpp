#include "block.h"
#include "position.h"

//setting class for each block, inheriting attributes from the block class
// these classes set the rotation states and the position of the blocks when rotated by the user


//The L block class and rotation states
class LBlock: public block{
    public: 
    LBlock(){
        id = 1;
        cells[0] = {position(0,2), position(1,0), position(1,1), position(1,2)};
        cells[1] = {position(0,1), position(1,1), position(2,1), position(2,2)};
        cells[2] = {position(1,0), position(1,1), position(1,2), position(2,0)};
        cells[3] = {position(0,0), position(0,1), position(1,1), position(2,1)};
        move(0,3);

    }
};

class JBlock:  public block{
    public:
    JBlock(){
        id = 2;
        cells[0] = {position(0,0), position(1,0), position(1,1), position(1,2)};
        cells[1] = {position(0,1), position(0,2), position(1,1), position(2,1)};
        cells[2] = {position(1,0), position(1,1), position(1,2), position(2,2)};
        cells[3] = {position(0,1), position(1,1), position(2,0), position(2,1)};
         move(0,3);
    }
};

class SBlock: public block{
    public:
    SBlock(){
        id = 3;
        cells[0] = {position(0,1), position(0,2), position(1,0), position(1,1)};
        cells[1] = {position(0,1), position(1,1), position(1,2), position(2,2)};
        cells[2] = {position(1,1), position(1,2), position(2,0), position(2,1)};
        cells[3] = {position(0,0), position(1,0), position(1,1), position(2,1)};
         move(0,3);
    }
};

class ZBlock: public block{
    public:
    ZBlock(){
        id = 4;
        cells[0] = {position(0,0), position(0,1), position(1,1), position(1,2)};
        cells[1] = {position(0,2), position(1,1), position(1,2), position(2,1)};
        cells[2] = {position(1,0), position(1,1), position(2,1), position(2,2)};
        cells[3] = {position(0,1), position(1,0), position(1,1), position(2,0)};
         move(0,3);
    }
};

class IBlock: public block{
    public:
    longBlock(){
        id = 5;
        cells[0] = {position(1,0), position(1,1), position(1,2), position(1,3)};
        cells[1] = {position(0,2), position(1,2), position(2,2), position(3,2)};
        cells[2] = {position(2,0), position(2,1), position(2,2), position(2,3)};
        cells[3] = {position(0,1), position(1,1), position(2,1), position(3,1)};
         move(0,3);
    }
};

class OBlock: public block{
    public:
    square(){
        id = 6;
        cells[0] = {position(0,0), position(0,1), position(1,0), position(1,1)};
         move(0,4);  
    }
};

class TBlock: public block{
    public:
    TBlock(){
        id = 7;
        cells[0] = {position(0,1), position(1,0), position(1,1), position(1,2)};
        cells[1] = {position(0,1), position(1,1), position(1,2), position(2,1)};
        cells[2] = {position(1,0), position(1,1), position(1,2), position(2,1)};
        cells[3] = {position(0,1), position(1,0), position(1,1), position(2,1)};
         move(0,3);
    }
};