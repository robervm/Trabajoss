#include "Esfera.h"
#include "freeglut.h"
Esfera::Esfera()
{
    
    radio = 1.0f;
    aceleracion.y = -9.8f;
    velocidad.x = 3;
    velocidad.y = 3;
}

Esfera::~Esfera()
{

}
void Esfera::dibuja()
{
    
    color.ponColor();
    glTranslatef(posicion.x, posicion.y, 0);
    glutSolidSphere(radio, 20, 20);
    glTranslatef(-posicion.x, -posicion.y, 0);
}

void Esfera::mueve(float t)
{
    
    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    velocidad = velocidad + aceleracion * t;
}


void Esfera::setColor(Byte r, Byte v, Byte a)
{
    color.set(r, v, a);
}

void Esfera::SetRadio(float r)
{
    if (r < 0.1F)
        r = 0.1F;
    radio = r;
}

void Esfera::SetPos(float ix, float iy)
{
    posicion.x = ix;
    posicion.y = iy;
}

void Esfera::setVel(float vx, float vy)
{
    velocidad.x = vx;
    velocidad.y = vy;
}