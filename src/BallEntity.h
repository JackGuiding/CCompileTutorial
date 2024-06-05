#ifndef BALL_H__
#define BALL_H__

// 一个小球占12bytes字节
struct BallEntity {
    // 结构体的`字段`
    float posX; // 4bytes == 32bits
    float posY; // 4bytes == 32bits
    float moveSpeed; // 4bytes == 32bits
};

typedef struct BallEntity BallEntity;

#endif
// .h 标准写法, 先照着写就行, 以后会讲解