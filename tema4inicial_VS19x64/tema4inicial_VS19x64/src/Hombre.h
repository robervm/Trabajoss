#pragma once
#include "Vector2D.h" 
class Hombre
{
/*private:
    float altura;
    unsigned char rojo;
    unsigned char verde;
    unsigned char azul;*/
public:
    Hombre();
    //virtual ~Hombre();
    float altura;
    unsigned char rojo;
    unsigned char verde;
    unsigned char azul;
    Vector2D posicion;
    Vector2D velocidad;
    Vector2D aceleracion;
    void dibuja();
    void mueve(float t);
    void setPos(float x1, float y1);
};
