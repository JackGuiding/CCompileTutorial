#ifndef INPUT_ENTITY_H__
#define INPUT_ENTITY_H__

#include "../include/raylib.h"

typedef struct InputEntity {
    bool isMouseLeftDown;
    bool isMouseRightDown;
    Vector2 mouseScreenPos;
} InputEntity;

#endif