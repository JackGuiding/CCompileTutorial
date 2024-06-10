#include "../include/raylib.h"
#include <stdio.h>
#include <stdlib.h>

void Draw(int count, Vector2 *balls) {
    for (int i = 0; i < count; i++) {
        DrawCircleV(balls[i], 10, RED);
    }
}

void Test() {
    int arr[50] = {0};
    int a = 10; // 具体地址
    int b = 20;
    a = 43;
    b = a;
    b = 80;

    // 函数结束
    // arr、a和b的栈就会释放
}

int main(void) {

    Test();

    // 在栈上开数组时, 需要知道长度
    // 假如有个程序它可能有1~100000000元素
    // int arr[100000000] = {0};

    // 点击生成小球
    // x y = 32bit * 2 = 64bit
    int count = 50;                         // 当前小球数量
    int countMax = 100;                     // 小球最大数量
    Vector2 *balls = malloc(64 * countMax); // 不会清空内存
    for (int i = 0; i < count; i++) {
        balls[i] = (Vector2){i, 0};
    }

    InitWindow(800, 600, "Game");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            if (count >= countMax) {
                // 无限生成小球
                {
                    // - Realloc
                    balls = realloc(balls, 64 * countMax * 2);

                    // - 手写(Manual)
                    Vector2 *newBalls = malloc(64 * countMax * 2);
                    for (int i = 0; i < countMax; i++) {
                        // 拷贝数据
                        newBalls[i] = balls[i];
                    }
                    free(balls);
                    balls = newBalls;
                    
                    countMax *= 2;
                }
                printf("Extends%d\n", countMax);
            } else {
                balls[count] = mousePos;
                count += 1;
            }
        }

        // 画小球
        Draw(count, balls);

        EndDrawing();
    }

    // 程序退出可以释放内存
    free(balls);

    CloseWindow();

    return 0;
}