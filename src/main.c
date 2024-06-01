#include "../include/raylib.h" // ../ 表示上一级目录 ../../上上级目录
#include <stdio.h>

// 函数之间不可 `跨作用域` 访问 `变量`
// 因此我们需要一个能跨作用域的变量

float posX = 400;
float posY = 225;
float moveX = 0;
float moveY = 0;
float moveSpeed = 50.5f;

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
    {
        if (IsKeyDown(KEY_A)) {
            // moveX -= 1; // moveX = moveX - 1;
            moveX = -1;
        } else if (IsKeyDown(KEY_D)) {
            moveX = 1;
        }

        if (IsKeyDown(KEY_W)) {
            moveY = -1;
        } else if (IsKeyDown(KEY_S)) {
            moveY = +1;
        }
    }
}

void DoLogic(float dt) {
    posX = posX + moveX * moveSpeed * dt;
    posY = posY + moveY * moveSpeed * dt;
}

void Draw() {
    // 多种表现方式 1图像:
    DrawCircle((int)posX, (int)posY, 50, YELLOW);
    DrawCircle(800, 450, 10, RED);

    // 多种表现方式 2文字:
    // printf("posX: %f, posY: %f\n", posX, posY);
}

int main(void) {

    // 初始化窗口
    InitWindow(800, 450, "raylib [core] example - basic window");

    // ==== 1. 初始化(循环前) ====

    // 保持窗口不关闭
    // ==== 2. 主循环 ====
    while (!WindowShouldClose()) {

        float deltaTime = GetFrameTime();

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

        // ==== 2.3 Draw 表现(渲染) ====
        Draw(posX, posY);

        EndDrawing();
    }

    // 关闭窗口
    CloseWindow();

    return 0;
}