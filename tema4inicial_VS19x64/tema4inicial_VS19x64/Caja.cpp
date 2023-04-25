#include "Caja.h"
#include "Pared.h"
Caja::Caja() {

    suelo.SetColor(0, 100, 0);
    //suelo.setPos(-10.0f, 0, 10.0f, 0);
    suelo.limite1.x = -10.0f;
    suelo.limite1.y = 0;
    suelo.limite2.x = 10.0f;
    suelo.limite2.y =0;
    techo.SetColor(0, 100, 0);
    //techo.setPos(-10.0f, 15.0f, 10.0f, 15.0f);
    techo.limite1.x = -10.0f;
    techo.limite1.y = 15.0f;
    techo.limite2.x = 10.0f;
    techo.limite2.y = 15.0f;
    pared_dcha.SetColor(0, 150, 0);
    //pared_dcha.setPos(-10.0f, 0, -10.0f, 15.0f);
    pared_dcha.limite1.x = -10.0f;
    pared_dcha.limite1.y = 0;
    pared_dcha.limite2.x = -10.0f;
    pared_dcha.limite2.y = 15.0f;
    pared_izq.SetColor(0, 150, 0);
    //pared_izq.setPos(10.0f, 0, 10.0f, 15.0f);
    pared_izq.limite1.x = 10.0f;
    pared_izq.limite1.y = 0;
    pared_izq.limite2.x = 10.0f;
    pared_izq.limite2.y = 15.0f;

}

void Caja::Dibuja()
{
    suelo.dibuja();
    techo.dibuja();
    pared_izq.dibuja();
    pared_dcha.dibuja();
}
void Caja::SetColor(unsigned char r, unsigned char v, unsigned char
    a)
{
    rojo = r;
    verde = v;
    azul = a;
}

