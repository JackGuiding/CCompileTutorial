#include "../include/raylib.h" // ../ 表示上一级目录 ../../上上级目录
#include "Context.h"
#include "Physics2D.h"
#include <stdio.h>

void ProcssInput(Context *ctx) {}

void DoLogic(Context *ctx, float dt) {}

void Draw(Context *ctx) {
    for (int i = 0; i < ctx->ballCount; i++) {
        BallEntity *ball = &ctx->balls[i];
        // DrawCircle((int)ball->posX, (int)ball->posY, 10, RED);
        DrawCircleV(ball->pos, ball->radius, RED);
    }
}

int main(void) {

    Context ctx = {0}; // 1000
    ctx.ballCount = 5;
    ctx.ballLimitCount = 10;
    for (int i = 0; i < ctx.ballCount; i++) {
        BallEntity *ball = &ctx.balls[i];
        ball->pos.x = 50 + i * 50;
        ball->pos.y = 225;
        ball->radius = 10;
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
            // 左键点击生成小球
            Vector2 mousePos = GetMousePosition();
            // 设置小球的位置
            if (ctx.ballCount >= ctx.ballLimitCount) {
                printf("error");
            } else {
                BallEntity *newBall = &ctx.balls[ctx.ballCount];
                newBall->pos = mousePos;
                newBall->radius = 10;
                // 生成一个小球: 意味着 Count + 1
                ctx.ballCount += 1;
            }
        } else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            Vector2 mousePos = GetMousePosition();
            for (int i = 0; i < ctx.ballCount; i += 1) {
                BallEntity *ball = &ctx.balls[i];
                // 鼠标是否处于小球内部
                bool isInside =
                    IsPointInsideCircle(mousePos, ball->pos, ball->radius);
                if (isInside) {
                    // 移除小球:
                    // 1. 把当前小球和最后一个小球换位
                    ctx.balls[i] = ctx.balls[ctx.ballCount - 1]; // 最后小球换到当前小球的位置
                    ctx.ballCount -= 1;
                    printf("No. %d\r\n", i);
                } else {
                }
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