#include "../include/raylib.h" // ../ 表示上一级目录 ../../上上级目录
#include "Context.h"
#include <stdio.h>

// 函数之间不可 `跨作用域` 访问 `变量`
// 因此我们需要一个能跨作用域的变量

Context ctx;

void ProcssInput() {
    // ctrl + / 注释和反注释
    // 按住
    // if (IsKeyDown(KEY_SPACE)) {
    //     printf("Space key is down\n");
    // }

    // 按下的第一次
    // if (IsKeyPressed(KEY_SPACE)) {
    //     printf("Space key is pressed\n");
    // }

    // 弹起的第一次
    // if (IsKeyReleased(KEY_SPACE)) {
    //     printf("Space key is released\n");
    // }

    if (IsKeyDown(KEY_A)) {
        // moveX -= 1; // moveX = moveX - 1;
        ctx.moveX = -1;
    } else if (IsKeyDown(KEY_D)) {
        ctx.moveX = 1;
    }

    if (IsKeyDown(KEY_W)) {
        ctx.moveY = -1;
    } else if (IsKeyDown(KEY_S)) {
        ctx.moveY = +1;
    }
}

void DoLogic(float dt) {
    // 移动小球
    ctx.posX += ctx.moveX * ctx.moveSpeed * dt; // px/s
    ctx.posY += ctx.moveY * ctx.moveSpeed * dt;
}

void Draw() {
    // 多种表现方式 1图像:
    DrawCircle((int)ctx.posX, (int)ctx.posY, 50, YELLOW);
    DrawCircle(800, 450, 10, RED);

    // 多种表现方式 2文字:
    // printf("posX: %f, posY: %f\n", posX, posY);
}

int main(void) {

    // 1字节 = 1byte
    // 1byte = 8bit
    // 1bit = 1个开关(0或1)
    // 能表达的十进制: 2^8 - 1 = 255
    char v1 = 257; // % 256 (取模)
    // 0: 257
    v1 = 5;
    // 0: 5

    unsigned short v2 = 65536; // 2^16 - 1
    int v3 = 0; // 2^32 - 1
    printf("v1: %d\n", v2); // 0

    // 初始化窗口
    InitWindow(800, 450, "raylib [core] example - basic window");

    // ==== 1. 初始化(循环前) ====
    ctx.posX = 400;
    ctx.posY = 225;
    ctx.moveX = 0;
    ctx.moveY = 0;
    ctx.moveSpeed = 50.5f;

    SetTargetFPS(60); // 16.67ms

    // 保持窗口不关闭
    // ==== 2. 主循环 ====
    // 帧: 从while开始到while结束
    // 1秒内的 deltaTime 总和是 1秒
    // 10000秒内的 deltaTime 总和是 10000秒
    while (!WindowShouldClose()) {

        // <<<< 一帧开始

        float deltaTime = GetFrameTime(); // 1/60 * 60 = 1

        // ==== 2.1 ProcessInput 处理输入控制 ====
        // 输入控制: 按住 WSAD 移动小球
        ProcssInput();

        // ==== 2.2 DoLogic 处理逻辑 ====
        // 不可见的数据变化
        // 根据 move 移动小球
        DoLogic(deltaTime);

        BeginDrawing();

        // 清空上一帧画面
        ClearBackground(RAYWHITE);

        // FPS: frame per second
        // 帧/s
        DrawFPS(10, 10);

        // ==== 2.3 Draw 表现(渲染) ====
        Draw();

        EndDrawing(); // 等待一定秒数, 保持帧率. 正常情况下, 电脑都在等待

        // >>>> 一帧结束
    }

    // 关闭窗口
    CloseWindow();

    return 0;
}