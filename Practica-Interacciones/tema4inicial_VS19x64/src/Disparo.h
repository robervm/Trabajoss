#pragma once
#include "Vector2D.h"
class Disparo
{
private:
    float radio;
    Vector2D origen;
    Vector2D posicion;
    Vector2D velocidad;
    Vector2D aceleracion;
public:
    Disparo();
    virtual ~Disparo();
    void dibuja();
    void mueve(float t);
    void setPos(float ix, float iy);
};


