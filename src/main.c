#include "../include/raylib.h"
#include <stdio.h>

int main(void) {

    InitWindow(800, 600, "Game");

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Hello, World!", 10, 10, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}