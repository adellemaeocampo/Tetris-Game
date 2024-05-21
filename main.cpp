#include <SFML/Graphics.hpp>
#include "game.h"
#include "board.h"
int main(){ 


    Color darkBlue = {44, 44, 127, 255};
    initWindow(300, 600, "tetris");
    SetTargetFPS(60);

     Board board;

    while (board.getWindow().isOpen()) {
        sf::Event event;
        while (board.getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                board.getWindow().close();
                }
        }

        board.draw();
    }


    Game game = Game();

    TBlock block = TBlock();
    

    while (windowShouldClose() == false) {
        game.HandleInput();
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }
    closeWindow();
    
    return 0;
}