#pragma once
//IMPLEMENTACION DE LA RELACION DE COMPOSICION
#include "Pared.h"

class Caja
{

public:
    Caja();
    //virtual ~Caja();
    void Dibuja();
    void SetColor(unsigned char r, unsigned char v, unsigned char a);
    Pared suelo;
    Pared techo;
    Pared pared_izq;
    Pared pared_dcha;
    unsigned char rojo;
    unsigned char verde;
    unsigned char azul;
};

