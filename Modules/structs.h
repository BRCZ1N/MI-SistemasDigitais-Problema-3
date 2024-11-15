#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include "prototype.h"

typedef struct
{
    int ballPositionX;
    int ballPositionY;
    int ballSpeedX;
    int ballSpeedY;
    int collision;
} Ball;

typedef struct
{

    int coordX;
    int coordY;
    int typeCollision;

} Bar;

typedef struct
{

    int red;
    int green;
    int blue;

} Color;

#endif
