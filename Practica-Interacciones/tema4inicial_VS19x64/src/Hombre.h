#pragma once
#include "Vector2D.h" 
class Hombre
{
private:
    float altura;
    Vector2D posicion;
    Vector2D velocidad;
    Vector2D aceleracion;
public:
    Hombre();
    virtual ~Hombre();
    void dibuja();
    void mueve(float t);
    void setPos(float x1, float y1);
    void setVel(float vx, float vy);
    friend class Interaccion;
};