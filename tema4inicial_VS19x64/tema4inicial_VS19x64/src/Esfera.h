#pragma once
#include "Vector2D.h"
class Esfera
{
private:
    unsigned char rojo;
    unsigned char verde;
    unsigned char azul;
    float radio;
    Vector2D posicion;
    Vector2D velocidad;
    Vector2D aceleracion;
public:
    Esfera();
    //virtual ~Esfera();
    
    void dibuja();
    void mueve(float t);
    void SetColor(unsigned char r, unsigned char v, unsigned char a);
    void SetRadio(float r);
    void SetPos(float ix, float iy);
};
