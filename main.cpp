#include <raylib.h>

int main(){ 
    Color darkBlue = {44, 44, 127, 255};
    initWindow(300, 600, "tetris");
    SetTargetFPS(6 0);

    while (windowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(darkBlue);
        EndDrawing();
    }
    closeWindow();
}