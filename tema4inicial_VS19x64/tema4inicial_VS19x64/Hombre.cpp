#include "Hombre.h"
#include "freeglut.h"

Hombre::Hombre() {
    rojo = verde = azul = 255; //blanco
    altura = 1.80f;
}

void Hombre::dibuja()
{
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0);
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidSphere(altura, 20, 20);
    glPopMatrix();
}

void Hombre::mueve(float t)
{
    posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
    posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
    velocidad.x = velocidad.x + aceleracion.x * t;
    velocidad.y = velocidad.y + aceleracion.y * t;
}

void Hombre::setPos(float x1, float y1)
{
    posicion.x = x1;
    posicion.y = y1;
}