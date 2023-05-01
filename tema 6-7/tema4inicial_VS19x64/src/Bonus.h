#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "ObjetoMovil.h"
class Bonus :public ObjetoMovil
{
   
private:
    float lado;
    
  
public:
    Bonus();
    virtual ~Bonus();
    void dibuja();
    void setPos(float ix, float iy);
};

