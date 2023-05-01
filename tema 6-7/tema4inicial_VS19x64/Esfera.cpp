#include "Esfera.h"
#include "freeglut.h"
Esfera::Esfera()
{
    
    radio = 1.0f;
    aceleracion.y = -9.8f;
    velocidad.x = 3;
    velocidad.y = 3;
}
Esfera::Esfera(float rad, float x, float y, float vx, float vy)
{
    radio = rad;
    posicion.x = x;
    posicion.y = y;
    velocidad.x = vx;
    velocidad.y = vy;
    aceleracion.y = -9.8;
    setColor(255, 255, 100);
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

Vector2D Esfera::getPos() {

    Vector2D res;

    res.x = posicion.x;
    res.y = posicion.y;

    return res;
}