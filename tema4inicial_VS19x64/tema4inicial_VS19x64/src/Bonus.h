#pragma once
#include "Vector2D.h"
class Bonus
{
/*private:
    float lado;
    unsigned char rojo;
    unsigned char verde;
    unsigned char azul;*/
public:
    Bonus();
    //virtual ~Bonus();
    float lado;
    unsigned char rojo;
    unsigned char verde;
    unsigned char azul;
    Vector2D posicion;
    Vector2D velocidad;
    Vector2D aceleracion;
    void dibuja();
    void mueve(float t);
    //void setPos(float ix, float iy);
};

