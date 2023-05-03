#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
class Disparo :public ObjetoMovil
{
    friend class Interaccion;
protected:
    float radio;
    Vector2D origen;
public:
    Disparo();
    virtual ~Disparo();
    void dibuja();
    void setPos(float ix, float iy);
    float getRadio();


};


