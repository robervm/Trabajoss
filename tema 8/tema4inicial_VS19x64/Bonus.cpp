#include "Bonus.h"
#include <stdlib.h>

#include "freeglut.h"
Bonus::Bonus() {
    
    lado = 0.30f;
    
}

void Bonus::dibuja() {
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0);
    glRotatef(30, 1, 1, 1);
    glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
        rand() / (float)RAND_MAX);//color aleatorio
    glutSolidCube(lado);
    glPopMatrix();
}




Bonus::~Bonus()
{

}