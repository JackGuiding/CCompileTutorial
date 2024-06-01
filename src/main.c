#include <stdio.h>
#include "../include/raylib.h" // ../ 表示上一级目录 ../../上上级目录

int main(void) {

    // 初始化窗口
    InitWindow(800, 450, "raylib [core] example - basic window");

    float posX = 400;
    float posY = 225;
    float moveSpeed = 50.5f;

    // 保持窗口不关闭
    while (!WindowShouldClose()) {

        float deltaTime = GetFrameTime();

        // 输入控制: 按住 WSAD 移动小球
        float moveX = 0;
        float moveY = 0;
        {
            if (IsKeyDown(KEY_A)) {
                moveX -= 1;
            } else if (IsKeyDown(KEY_D)) {
                moveX += 1;
            }

            if (IsKeyDown(KEY_W)) {
                moveY -= 1;
            } else if (IsKeyDown(KEY_S)) {
                moveY += 1;
            }
        }

        // 根据 move 移动小球
        posX = posX + moveX * moveSpeed * deltaTime;
        posY = posY + moveY * moveSpeed * deltaTime;

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

        BeginDrawing();

        // 清空上一帧画面
        ClearBackground(RAYWHITE);

        DrawCircle((int)posX, (int)posY, 50, YELLOW);
        DrawCircle(800, 450, 10, RED);

        EndDrawing();

    }

    // 关闭窗口
    CloseWindow();

    return 0;

}