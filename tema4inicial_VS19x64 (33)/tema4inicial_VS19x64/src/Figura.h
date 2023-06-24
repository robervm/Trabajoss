#pragma once
#include "Vector2D.h"
#define NUM 50
#include "Tablero.h"
#include "ListaTableros.h"
#include "ETSIDI.h"
#include <iostream>
#include<cmath>
using ETSIDI::SpriteSequence;

class Figura
{
protected:
    //float altura;
    //
    //
    Vector2D posicion;
    int identidad;
    Tablero* posicionesLegales[NUM];
    bool color;
    bool vida;
    //char *tipo;
    std::string tipo;
    SpriteSequence sprite1{ "bin/imagenes/piezas_blancas.png", 6 };
    SpriteSequence sprite2{ "bin/imagenes/piezas_negras.png", 6 };
    Vector2D max, min;
public:
    Figura();
    Figura(bool color_, const std::string& tipo_, int identidad,bool vida_);
    virtual ~Figura();
    virtual void dibuja()=0;
    virtual bool movLegal(int ident_,ListaTableros lt) = 0;
    virtual std::string getName()=0;
   
    Vector2D getPos();
    void setPos(float x, float y);
    void setPos(Vector2D pos);
    void setPos(int ident);
    //
    void setIdent(int identi);
    int getIdent();
    bool getColor() { return color; }
    //
    

   
    friend class ListaTableros;
    friend class Tablero;
};

