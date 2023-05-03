#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "ObjetoMovil.h"
class Esfera :public ObjetoMovil
{
protected:
    
    float radio;
    ColorRGB color;
public:
    Esfera();
    Esfera(float rad, float x = 0.0f, float y = 0.0f,
        float vx = 0.0f, float vy = 0.0f);
    virtual ~Esfera();
    void dibuja();
    void setColor(Byte r, Byte v, Byte a);
    void SetRadio(float r);
    virtual Esfera* dividir();

    friend class Interaccion;
};