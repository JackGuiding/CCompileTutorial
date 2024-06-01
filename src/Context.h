#ifndef CONTEXT_H__
#define CONTEXT_H__

// 该程序的上下文: 球的位置、输入的方向, 即一个程序里的所有数据
// 我家的上下文: 沙发、门、电视
typedef struct Context {
    float posX;
    float posY;
    float moveX;
    float moveY;
    float moveSpeed;
} Context;

#endif