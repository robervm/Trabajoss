#pragma once
#include "Vector2D.h"
class Disparo
{
private:
    float radio;
    unsigned char rojo;
    unsigned char verde;
    unsigned char azul;
    Vector2D origen;
    Vector2D posicion;
    Vector2D velocidad;
    Vector2D aceleracion;
public:
    Disparo();
    //virtual ~Disparo();
    /*float radio;
    unsigned char rojo;
    unsigned char verde;
    unsigned char azul;
    Vector2D origen;
    Vector2D posicion;
    Vector2D velocidad;
    Vector2D aceleracion;*/
    void dibuja();
    void mueve(float t);
    void setPos(float ix, float iy);
};


