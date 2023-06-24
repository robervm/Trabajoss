#include "Tablero.h"
#include "freeglut.h"
#include "ETSIDI.h"
Tablero::Tablero() {
    //rojo = verde = azul = 255; //blanco
}
/*Tablero::Tablero(int identi, float x1, float y1) {
    ident = identi;
    this->pos.x =x1;
    this->pos.y = y1;
}*/
Tablero::Tablero(float x1, float y1) {
    this->pos.x = x1;
    this->pos.y = y1;
}
Tablero::Tablero(Vector2D pos) {
    this->pos = pos;
}
Tablero::~Tablero()
{

}
Vector2D Tablero::getPos() {
    Vector2D pos;
    
    pos.x = (limite1.x + limite2.x) / 2.0;
    pos.y= (limite1.y + limite2.y) / 2.0;


        return pos;
}
Vector2D Tablero::getPos1() {
    


    return this->pos;
}

float Tablero::getPosX() {
    return this->pos.x;
}
float Tablero::getPosY() {
    return this->pos.y;
}
void Tablero::dibuja()
{
    //FUENTES
    ETSIDI::setTextColor(233, 190, 107);
    ETSIDI::setFont("bin/fuentes/Classica-BoldOblique.ttf", 28);
    ETSIDI::printxy("  A", 0, -1); ETSIDI::printxy("  1", -1, 1);
    ETSIDI::printxy("   B", 1, -1); ETSIDI::printxy("  2", -1, 2);
    ETSIDI::printxy("   C", 2, -1); ETSIDI::printxy("  3", -1, 3);
    ETSIDI::printxy("   D", 3, -1); ETSIDI::printxy("  4", -1, 4);
    ETSIDI::printxy("   E", 4, -1); ETSIDI::printxy("  5", -1, 5);
    ETSIDI::printxy("   F", 5, -1); ETSIDI::printxy("  6", -1, 6);
    ETSIDI::printxy("   G", 6, -1); ETSIDI::printxy("  7", -1, 7);
    ETSIDI::printxy("   H", 7, -1); ETSIDI::printxy("  8", -1, 8);

    //TABLERO
    glDisable(GL_LIGHTING);
    color.ponColor();
    glBegin(GL_POLYGON);
    glVertex3d(limite1.x, limite1.y, 0);
    glVertex3d(limite2.x, limite1.y, 0);
    glVertex3d(limite2.x, limite2.y, 0);
    glVertex3d(limite1.x, limite2.y, 0);
    glEnd();
    glEnable(GL_LIGHTING);

    //MARCO TABLERO

    glBegin(GL_POLYGON);
    glColor3ub(98, 24, 8);
    glVertex3f(limite1.x - 0.1, limite1.y - 0.1, -0.05);
    glVertex3f(limite2.x + 0.1, limite1.y - 0.1, -0.05);
    glVertex3f(limite2.x + 0.1, limite2.y + 0.1, -0.05);
    glVertex3f(limite1.x - 0.1, limite2.y + 0.1, -0.05);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(233, 190, 107);
    glVertex3f(limite1.x - 0.2, limite1.y - 0.2, -0.06);
    glVertex3f(limite2.x + 0.2, limite1.y - 0.2, -0.06);
    glVertex3f(limite2.x + 0.2, limite2.y + 0.2, -0.06);
    glVertex3f(limite1.x - 0.2, limite2.y + 0.2, -0.06);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(98, 24, 8);
    glVertex3f(limite1.x - 0.3, limite1.y - 0.3, -0.07);
    glVertex3f(limite2.x + 0.3, limite1.y - 0.3, -0.07);
    glVertex3f(limite2.x + 0.3, limite2.y + 0.3, -0.07);
    glVertex3f(limite1.x - 0.3, limite2.y + 0.3, -0.07);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(233, 190, 107);
    glVertex3f(limite1.x - 0.4, limite1.y - 0.4, -0.08);
    glVertex3f(limite2.x + 0.4, limite1.y - 0.4, -0.08);
    glVertex3f(limite2.x + 0.4, limite2.y + 0.4, -0.08);
    glVertex3f(limite1.x - 0.4, limite2.y + 0.4, -0.08);
    glEnd();


}

void Tablero::setColor(Byte r, Byte v, Byte a)
{
    color.set(r, v, a);
}

void Tablero::setPos(float x1, float y1, float x2, float y2)
{
    limite1.x = x1;
    limite1.y = y1;
    limite2.x = x2;
    limite2.y = y2;
}

void Tablero::identi(int i, int j) {
    ident = ((i + 1) * 10) + (j + 1);
}

int Tablero::getIdent() {
    return ident;
}



void Tablero::setPieza(Figura* sp) {
    this->Pieza->identidad = p->identidad;
    this->Pieza->color = p->color;
    this->Pieza->vida = p->vida;
    this->Pieza->tipo = p->tipo;
}

Figura* Tablero::getPieza() {

    return Pieza;
}


