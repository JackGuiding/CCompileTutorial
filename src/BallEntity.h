#ifndef BALL_H__
#define BALL_H__

#include "../include/raylib.h"

// 一个小球占12bytes字节
struct BallEntity {
    // 结构体的`字段`
    Vector2 pos;
    float radius;
    float moveSpeed; // 4bytes == 32bits
};

typedef struct BallEntity BallEntity;

#endif
// .h 标准写法, 先照着写就行, 以后会讲解