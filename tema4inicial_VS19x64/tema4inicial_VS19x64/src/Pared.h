#pragma once
#include "Vector2D.h"
class Pared
{
public:
    Pared();
   // virtual ~Pared();
    unsigned char rojo;
    unsigned char verde;
    unsigned char azul;
    Vector2D limite1;
    Vector2D limite2;
    void dibuja();
    void SetColor(unsigned char r, unsigned char v, unsigned char a);
    //void setPos(float x1, float y1, float x2, float y2);
};
