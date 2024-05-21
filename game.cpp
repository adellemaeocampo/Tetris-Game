#include <random>
#include <iostream>
#include "game.h"
#include "board.h"
#include "block.h"
#include "grid.h"
#include "position.h"

Game::Game() : window(sf::VideoMode(800, 600), "Tetris Game") {
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    score = 0;

    if (!font.loadFromFile("path/to/font.ttf")) {
        std::cerr << "Error loading font from path/to/font.ttf" << std::endl;
        exit(EXIT_FAILURE);
    }

    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);
}

Game::~Game() {
    if (window.isOpen()) {
        window.close();
    }
}

Block Game::GetRandomBlock() {
    if (blocks.empty()) {
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetAllBlocks() {
    return {IBlock(), JBlock(), OBlock(), TBlock(), ZBlock(), LBlock()};
}

void Game::Draw() {
    window.clear();

    grid.Draw(window);  // Ensure Grid class has a Draw method that accepts sf::RenderWindow
    currentBlock.Draw(window);  // Ensure Block class has a Draw method that accepts sf::RenderWindow

    scoreText.setString("Score: " + std::to_string(score));
    window.draw(scoreText);

    window.display();
}

void Game::HandleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }

    if (gameOver) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::AnyKey)) {
            gameOver = false;
            Reset();
        }
        return;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        MoveBlockLeft();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        MoveBlockRight();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        MoveBlockDown();
        UpdateScore(0, 1);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        RotateBlock();
    }
}

void Game::MoveBlockLeft() {
    if (!gameOver) {
        currentBlock.Move(0, -1);
        if (IsBlockOutside() || !BlockFits()) {
            currentBlock.Move(0, 1);
        }
    }
}

void Game::MoveBlockRight() {
    if (!gameOver) {
        currentBlock.Move(0, 1);
        if (IsBlockOutside() || !BlockFits()) {
            currentBlock.Move(0, -1);
        }
    }
}

void Game::MoveBlockDown() {
    if (!gameOver) {
        currentBlock.Move(1, 0);
        if (IsBlockOutside() || !BlockFits()) {
            currentBlock.Move(-1, 0);
            LockBlock();
        }
    }
}

void Game::LockBlock() {
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for (const Position& item : tiles) {
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if (!BlockFits()) {
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
    int rowsCleared = grid.ClearFullRows();
    UpdateScore(rowsCleared, 0);
}

void Game::RotateBlock() {
    if (!gameOver) {
        currentBlock.Rotate();
        if (IsBlockOutside() || !BlockFits()) {
            currentBlock.UndoRotation();
        }
    }
}

void Game::Reset() {
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints) {
    switch (linesCleared) {
        case 1:
            score += 100;
            break;
        case 2:
            score += 200;
            break;
        case 3:
            score += 300;
            break;
        default:
            break;
    }
    score += moveDownPoints;
}

bool Game::IsBlockOutside() {
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for (const Position& item : tiles) {
        if (grid.IsCellOutside(item.row, item.column)) {
            return true;
        }
    }
    return false;
}


// #include "game.h"
// #include <random>
// #include <SFML/Graphics.hpp>

// Game::Game() : window(sf::VideoMode(800, 600), "Tetris Game"){
//     gird = Grid();
//     blocks = GetAllBlocks;
//     currentBlock = GetRandomBlock();
//     nextBlock = GetRandomBlock(); 
//     gameOver = false;
//     score = 0; 
// }

//     if (!font.loadFromFile("path/to/font.ttf")) {
//         // Handle error
//         std::cerr << "Error loading font from path/to/font.ttf" << std::endl;
//         // Handle error appropriately, e.g., exit the application or set a default font
//         exit(EXIT_FAILURE);
//     }
//     scoreText.setFont(font);
//     scoreText.setCharacterSize(24);
//     scoreText.setFillColor(sf::Color::White);
//     scoreText.setPosition(10, 10);



// Block Game::GetRandomBlock() {
//     if (blocks.empty()){
//         blocks = GetAllBlocks();
//     }
//     int randomIndex = rand() % blocks.size();
//     Block block = blocks[randomIndex];
//     blocks.erase(blocks.begin() + randomIndex); 
//     return block;
// } 

// std::vector<Block> Game::GetAllBlocks() {
//     return{IBlock(), JBlock(), OBlock(), TBlock(), ZBlock(), LBlock()};
// }

// void Game::Draw() {
//     window.clear();

//     // Draw grid and current block here using SFML
//     grid.Draw(window);  // Modify Grid class to draw using SFML
//     currentBlock.Draw(window);  // Modify Block class to draw using SFML

//     // Update and draw score
//     scoreText.setString("Score: " + std::to_string(score));
//     window.draw(scoreText);

//     window.display();
// }

// void Game::HandleInput() {
//     int keyPressed = GetKeyPressed();
//     if (gameOver && keyPress != 0) {
//         gameOver = false;
//         Reset();
//     }
//     switch(keyPressed){
//         case KEY_LEFT;
//             MoveBlockLeft();
//             break;
//         case KEY_RIGHT;
//             MoveBlockRight();
//             break;
//         case KEY_DOWN;
//             MoveBlockDown();
//             UpdateScore(0, 1);
//             break;
//         case KEY_UP:
//             RotateBlock();
//             break;
//     }
// }

// void Game::MoveBlockLeft() {
//     if (!gameOver) {
//     currentBlock.Move(0, -1);
//     if (IsBlockOutside() || !BlockFits() == false) {
//         currentBlock.Move(0, 1);
//     }
//     }
// }
// void Game::MoveBlockRight() {
//     if (!gameOver) {
//     currentBlock.Move(0, 1); 
//     if (IsBlockOutside() || BlockFits() == false){
//         currentBlock.Move(0, -1);
//     }
//     }
// }
// void Game::MoveBlockDown() {
//     if (!gameOver) {
//     currentBlock.Move(1, 0);
//     if (IsBlockOutside() || BlockFits() == false) {
//         currentBlock(-1, 0);
//         LockBlock();
//     }
//     }
// }

// void Game::LockBlock() {
//     std::vector<Position> titles = currentBlock.getCellPositions();
//     for (Position item : titles){
//         grid.grid[item.row][item.column] = currentBlock.id;
//     }
//     currentBlock = nextBlock;
//     if (BlockFits() == false) {
//         gameOver = true;
//     }
//     nextBlock = GetRandomBlock();
//     int rowCleared = grid.ClearFullRows();
//     UpdateScore(rowsCleared, 0);
// }

// void Game::RotateBlock() {
//     if(!gameOver) {
//         currentBlock.rotate();
//         if(IsBlockOutside()){
//             currentBlock.UndoRotation();
//         }



//     }
// }

// void Game::Reset() {
//     grid.Initialize();
//     blocks = GetAllBlocks();
//     currentBlock = GetRandomBlock;
//     nextBlock = GetRandomBlock; 
//     score = 0; 
// }

// void Game::UpdateScore(int linesCleared, int moveDownPoints) {
//     switch(linesCleared) {
//         case 1:
//             score += 100;
//             break;
//         case 2:
//             score += 200;
//             break;
//         case 3:
//             score += 300;
//             break;
//         default:
//             break;
//     }

//     score += moveDownPoints; 
// }


// bool Game:: IsBlockOutside(){
//     std::vector<Position> tiles = currentBlock.getCellPositions();
//     for(Position item: tiles){
//         if(Grid.IsCellOutside(item.row, item.cols)){
//             return true;
//         }
//     }
//     return false;
// }