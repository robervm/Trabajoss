#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "Figura.h"
class Tablero
{
private:
    
    Vector2D limite1;
    Vector2D limite2;
    ColorRGB color;
    Vector2D pos;
    int ident;
    Figura *Pieza = NULL;
public:
    Tablero();

    //Tablero(int identi,float x1,float y1);
    Tablero(float x1, float y1);
    Tablero(Vector2D pos);
     virtual ~Tablero();
    void dibuja();
    void setColor(Byte r, Byte v, Byte a);
    void setPos(float x1, float y1, float x2, float y2);
    void identi(int i,int j);
    int getIdent();
    void setPieza(Figura* p);
    Figura* getPieza();
    Vector2D getPos();
    Vector2D getPos1();
    float getPosX();
    float getPosY();
    friend class Interaccion;
};

