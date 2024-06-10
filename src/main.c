#include "../include/raylib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    // 变量必有两个属性: 地址, 值
    // 0x1000 = 0000 0000 | 0000 0000 | 0000 0000 | 0000 0011 = 3
    // 4byte = 32bit
    int a = 3; // 栈 32G --

    int size = 16; // 16 byte
    
    // pointer 也是变量: 地址, 值(存的是别人的地址)
    // 0x500 = 0x1000
    int* aptr = &a;
    int value = *aptr; // 0x500 ->(*) 0x1000 -> 3

    // 0x600 = 0x500
    int** apptr = &aptr;
    int v2 = **apptr; // 0x600 ->(*) 0x500 ->(*) 0x1000 -> 3

    void* pointer = malloc(size); // 堆 0G ++

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