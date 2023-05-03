#include "Disparo.h"
#include "freeglut.h"

Disparo::Disparo() {
    
    radio = 0.25f;
    velocidad.y = 15.0f;
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


void Disparo::setPos(float ix, float iy) {

    
    ObjetoMovil::setPos(ix, iy);
    origen = posicion;

}



float Disparo::getRadio() {


    return radio;
}