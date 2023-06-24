#include "Figura.h"

#include "freeglut.h"
#include <iostream>
#include <string>

Figura::Figura() {

	max.x = 8.0;
	max.y = 8.0;
	min.x = 1.0;
	min.y = 1.0;
}
Figura::Figura(bool color_, const std::string& tipo_, int identidad_,bool vida_) {
   
    //altura = 0.1f;
	//color = color_;
	//tipo = tipo_;
	//tipo = tipo_;
	color = color_;
	//tipo = tipo_;

	tipo = tipo_;
	identidad = identidad_;
	vida = vida_;
}



Figura::~Figura()
{

}
//void Figura::dibuja()
//{
//    glPushMatrix();
//    glTranslatef(posicion.x, posicion.y, 0);
//    glColor3f(1.0f, 0.0f, 0.0f);
//    glutSolidSphere(altura, 20, 20);
//    glPopMatrix();
//}






//void Figura::mueveex(float x1) {
//    posicion.x += x1;
//    printf("(%f,%f)\n", posicion.x,posicion.y);
//}
//
//void Figura::mueveey(float y1) {
//    posicion.y += y1;
//    printf("(%f,%f)\n", posicion.x, posicion.y);
//}


//void Figura::moveIdentx(int x) {
//    ident += x;
//    printf("%d\n", ident);
//}
//
//void Figura::moveIdenty(int y) {
//    ident += 10*y;
//    printf("%d\n", ident);
//}



Vector2D Figura::getPos()
{
	return posicion;
}

void Figura::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}
void Figura::setPos(Vector2D pos)
{
	posicion = pos;
}

void Figura::setPos(int ident) {
	posicion.x = ident / 10;
	posicion.y = ident % 10;
}



void Figura::setIdent(int identi) {
	identidad = identi;
}

int Figura::getIdent() {
	return identidad;
}