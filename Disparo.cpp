#include "Disparo.h"
#include "freeglut.h"

Disparo::Disparo() {
    
    radio = 0.25f;
    velocidad.y = 3.0f;
}
Disparo::~Disparo()
{

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
   
    posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
    velocidad = velocidad + aceleracion * t;
}
//
void Disparo::setPos(float ix, float iy) {

    posicion.x = ix;
    posicion.y = iy;
    origen = posicion;

}