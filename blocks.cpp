#include "blocks.h"

// LBlock
LBlock::LBlock() {
    id = 1;
    color = sf::Color::Blue;
    cells = {
        {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)},
        {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)},
        {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)},
        {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)}
    };
    rowOffset = 0;
    colOffset = 3;
}

// JBlock
JBlock::JBlock() {
    id = 2;
    color = sf::Color::Magenta;
    cells = {
        {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)},
        {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)},
        {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)},
        {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)}
    };
    rowOffset = 0;
    colOffset = 3;
}

// IBlock
IBlock::IBlock() {
    id = 3;
    color = sf::Color::Cyan;
    cells = {
        {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)},
        {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)},
        {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)},
        {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)}
    };
    rowOffset = 0;
    colOffset = 3;
}

// OBlock
OBlock::OBlock() {
    id = 4;
    color = sf::Color::Yellow;
    cells = {
        {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)}
    };
    rowOffset = 0;
    colOffset = 4;
}

// SBlock
SBlock::SBlock() {
    id = 5;
    color = sf::Color::Green;
    cells = {
        {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)},
        {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)},
        {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)},
        {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)}
    };
    rowOffset = 0;
    colOffset = 3;
}

// TBlock
TBlock::TBlock() {
    id = 6;
    color = sf::Color::Red;
    cells = {
        {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)},
        {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)},
        {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)},
        {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)}
    };
    rowOffset = 0;
    colOffset = 3;
}

// ZBlock
ZBlock::ZBlock() {
    id = 7;
    color = sf::Color::White;
    cells = {
        {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)},
        {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)},
        {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)},
        {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)}
    };
    rowOffset = 0;
    colOffset = 3;
}
