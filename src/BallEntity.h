#ifndef BALL_H__
#define BALL_H__

struct BallEntity {
    // 结构体的`字段`
    float posX;
    float posY;
    float moveSpeed;
};

typedef struct BallEntity BallEntity;

#endif
// .h 标准写法, 先照着写就行, 以后会讲解