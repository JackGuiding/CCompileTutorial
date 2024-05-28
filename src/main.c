// 什么是 #include
// 它的作用是引入外部的头文件

// <> 代表引入的是系统的头文件
// - stdio.h stdlib.h -> libc.a(.c)

// "" 代自定义的头文件

#include "../include/raylib.h" // ../ 表示上一级目录 ../../上上级目录
#include "a.h"                 // 同级
#include "child/b.h"           // 子目录
#include <stdio.h>

int main(void) {

    // 程序一定是按顺序运行的
    printf("456\r\n");
    printf("Hello\r\n");
    printf("123");

    // 初始化窗口
    InitWindow(800, 450, "raylib [core] example - basic window");

    float x = 400;
    float y = 225;

    // 保持窗口不关闭
    while (!WindowShouldClose()) {

        float deltaTime = GetFrameTime();
        x += deltaTime * 100;

        BeginDrawing();

        // 清空上一帧画面
        ClearBackground(RAYWHITE);

        DrawCircle((int)x, (int)y, 50, YELLOW);

        EndDrawing();

    }

    // 关闭窗口
    CloseWindow();

    return 0;

}