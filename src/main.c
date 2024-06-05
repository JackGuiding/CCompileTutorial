#include "../include/raylib.h" // ../ 表示上一级目录 ../../上上级目录
#include "Context.h"
#include <stdio.h>

void ProcssInput(Context *ctx) {}

void DoLogic(Context *ctx, float dt) {}

void Draw(Context *ctx) {
    for (int i = 0; i < ctx->ballCount; i++) {
        BallEntity *ball = &ctx->balls[i];
        DrawCircle((int)ball->posX, (int)ball->posY, 10, RED);
    }
}

int main(void) {

    Context ctx = {0}; // 1000
    ctx.ballCount = 5;
    ctx.ballLimitCount = 10;
    for (int i = 0; i < ctx.ballCount; i++) {
        BallEntity *ball = &ctx.balls[i];
        ball->posX = 50 + i * 50;
        ball->posY = 225;
    }

    // 初始化窗口
    InitWindow(800, 450, "raylib [core] example - basic window");

    // ==== 1. 初始化(循环前) ====
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
        ProcssInput(&ctx);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePos = GetMousePosition();
            // 设置小球的位置
            if (ctx.ballCount >= ctx.ballLimitCount) {
                printf("error");
            } else {
                BallEntity *newBall = &ctx.balls[ctx.ballCount];
                newBall->posX = mousePos.x;
                newBall->posY = mousePos.y;
                // 生成一个小球: 意味着 Count + 1
                ctx.ballCount += 1;
            }
        }

        // ==== 2.2 DoLogic 处理逻辑 ====
        // 不可见的数据变化
        // 根据 move 移动小球
        DoLogic(&ctx, deltaTime);

        BeginDrawing();

        // 清空上一帧画面
        ClearBackground(RAYWHITE);

        // FPS: frame per second
        // 帧/s
        DrawFPS(10, 10);

        // ==== 2.3 Draw 表现(渲染) ====
        // `&ctx` 地址
        // `ctx` 值
        Draw(&ctx);

        EndDrawing(); // 等待一定秒数, 保持帧率. 正常情况下, 电脑都在等待

        // >>>> 一帧结束
    }

    // 关闭窗口
    CloseWindow();

    return 0;
}