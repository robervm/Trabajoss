#pragma once
#include "Vector2D.h" 
#include "ETSIDI.h"
#include "ObjetoMovil.h"

using ETSIDI::SpriteSequence;
class Hombre :public ObjetoMovil
{
private:
    float altura;
    SpriteSequence sprite1;
   
public:
    Hombre();
    virtual ~Hombre();
    void mueve(float t);
    void dibuja();
    void setPos(float x1, float y1);
    void setVel(float vx, float vy);
    Vector2D getPos();
    float getAltura();
    friend class Interaccion;
};