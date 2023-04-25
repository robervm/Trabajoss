#include "Bonus.h"
#include <stdlib.h>
//#include <freeglut.h>
#include "freeglut.h"
Bonus::Bonus() {
	//rojo = verde = azul = 255; //blanco
    lado = 0.30f;
}

void Bonus::dibuja(){
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0);
    glRotatef(30, 1, 1, 1);
    glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
        rand() / (float)RAND_MAX);//color aleatorio
    glutSolidCube(lado);
    glPopMatrix();
}

void Bonus::mueve(float t)
{
    posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
    posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
    velocidad.x = velocidad.x + aceleracion.x * t;
    velocidad.y = velocidad.y + aceleracion.y * t;
}

//
/*void Bonus::setPos(float ix, float iy) {

    posicion.x = ix;
    posicion.y = iy;

}*/