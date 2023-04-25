#include "Disparo.h"
#include "freeglut.h"

Disparo::Disparo() {
    rojo = verde = azul = 255; //blanco
    radio = 0.25f;
    velocidad.y = 3.0f;
}

void Disparo::dibuja()
{
    glColor3f(0.0f, 1.0f, 1.0f);
    //estela
    glBegin(GL_LINES);
    glVertex3f(origen.x, origen.y, 0);
    glVertex3f(posicion.x, posicion.y, 0);
    glEnd();

    //
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0);
    glutSolidSphere(radio, 20, 20);
    glPopMatrix();
}

void Disparo::mueve(float t)
{
    posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
    posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
    velocidad.x = velocidad.x + aceleracion.x * t;
    velocidad.y = velocidad.y + aceleracion.y * t;
}
//
void Disparo::setPos(float ix, float iy) {

    posicion.x = ix;
    posicion.y = iy;
    origen = posicion;

}