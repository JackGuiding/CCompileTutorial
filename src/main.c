#include "../include/raylib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    // 192.168.0.1
    // 0.0.0.0 ~ 255.255.255.255
    // 8bit, 8bit, 8bit, 8bit = 32bit
    unsigned char ip1 = 192;
    unsigned char ip2 = 168;
    unsigned char ip3 = 0;
    unsigned char ip4 = 255;

    unsigned int ipFullValue;
    ipFullValue = ip1;
    ipFullValue = ipFullValue << 8;
    ipFullValue = ipFullValue | ip2;

    ipFullValue = ipFullValue << 8;
    ipFullValue = ipFullValue | ip3;

    ipFullValue = ipFullValue << 8;
    ipFullValue = ipFullValue | ip4;
    printf("int full value: %d\r\n", ipFullValue);

    unsigned char ip1b = ipFullValue >> 24;
    unsigned char ip2b = (ipFullValue >> 16) & 0xFF;
    unsigned char ip3b = (ipFullValue >> 8) & 0xFF;
    unsigned char ip4b = ipFullValue & 0xFF;

    printf("ip1b: %d\r\n", ip1b);
    printf("ip2b: %d\r\n", ip2b);
    printf("ip3b: %d\r\n", ip3b);
    printf("ip4b: %d\r\n", ip4b);

    Color color = { ip1, ip2, ip3, ip4 };

    InitWindow(800, 600, "Game");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(color);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}