#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
class Disparo :public ObjetoMovil
{
protected:
    float radio;
    Vector2D origen;
    
public:
    Disparo();
    virtual ~Disparo();
    void dibuja();
    void setPos(float ix, float iy);
    void setVel(float vx, float vy);
    float getRadio();
    Vector2D getPos();

};


