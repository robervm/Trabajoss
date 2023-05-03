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
    float getAltura();
    friend class Interaccion;
};