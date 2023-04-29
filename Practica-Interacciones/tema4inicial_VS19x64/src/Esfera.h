#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
class Esfera
{
private:
    
    float radio;
    Vector2D posicion;
    Vector2D velocidad;
    Vector2D aceleracion;
    ColorRGB color;
public:
    Esfera();
    virtual ~Esfera();

    void dibuja();
    void mueve(float t);
    void setColor(Byte r, Byte v, Byte a);
    void SetRadio(float r);
    void SetPos(float ix, float iy);
    void setVel(float vx, float vy);
    friend class Interaccion;
};