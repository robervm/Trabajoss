#include "Peon.h"
#include "freeglut.h"
#include <iostream>



Peon::Peon() {

	altura = 0.1f;
	primerMov = false;
}


void Peon::dibuja() {
	
	if (color == 1) {
		/* ETSIDI::setTextColor(250, 250, 250);
		 ETSIDI::setFont("bin/fuentes/CHEQ_TT.TTF", 32);
		 ETSIDI::printxy("t", posicion.x, posicion.y);*/

		 /* glEnable(GL_TEXTURE_2D);
		  glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/tb.png").id);
		  glDisable(GL_LIGHTING);
		  glBegin(GL_POLYGON);
		  glTexCoord2d(0, 2); glVertex3f(posicion.x - lado/2, posicion.y + lado/2, 0.1f);
		  glTexCoord2d(2, 2); glVertex3f(posicion.x + lado/2, posicion.y + lado/2, 0.1f);
		  glTexCoord2d(2, 0); glVertex3f(posicion.x + lado/2, posicion.y - lado/2, 0.1f);
		  glTexCoord2d(0, 0); glVertex3f(posicion.x - lado/2, posicion.y - lado/2, 0.1f);
		  glEnd();
		  glEnable(GL_LIGHTING);
		  glDisable(GL_TEXTURE_2D);*/
		  //new Sprite("bin/imagenes/tb.png",posicion.x,posicion.y,1.0,1.0);
		 /* torreb.setCenter(posicion.x, posicion.y);
		  //torreb.setSize(0.5, 0.5);
		  torreb.draw();*/
		  /*piezasblancas.setState(1);
		  piezasblancas.setCenter(posicion.x+10, posicion.y+10);
		  glPushMatrix();
		 // piezasblancas.draw();
		  //glPopMatrix();*/
		  //Liberar memoria de la textura
		  //glBindTexture(GL_TEXTURE_2D, 0);
		sprite1.setCenter(0, 0);
		sprite1.setSize(0.8, 0.8);
		glPushMatrix();
		glTranslatef(posicion.x - 0.25, posicion.y - 0.25, 0.2);
		glColor3f(1.0f, 0.0f, 0.0f);
		sprite1.setState(0);
		sprite1.draw();
		glPopMatrix();
	}
	else {
		/*ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("bin/fuentes/CHEQ_TT.TTF", 32);
		ETSIDI::printxy("t", posicion.x, posicion.y);*/
		sprite2.setCenter(0, 0);
		sprite2.setSize(0.8, 0.8);
		glPushMatrix();
		glTranslatef(posicion.x - 0.25, posicion.y - 0.25, 0.2);
		glColor3f(1.0f, 0.0f, 0.0f);
		sprite2.setState(0);
		sprite2.draw();
		glPopMatrix();
	}


}
std::string Peon::getName() {
	return tipo;
}
bool Peon::movLegal(int ident_,ListaTableros lt) {
	Vector2D pos, pos_ini, dif, pos_var,dif_aux;
	Vector2D cont = {0,0};
	bool flag = true;

	pos_ini = this->getPos();

	pos_var = pos_ini;

	pos = { ident_ / 10,ident_ % 10 };

	//dif = pos - pos_ini;
	dif_aux=dif.absoluto(pos,pos_ini); //ojo

	//cont = { dif.x / abs(dif.x),dif.y / abs(dif.y) };

	if (this->color) //si es blanca
	{
		cont.y = 1;
	}
	else                //negra
	{
		cont.y = -1;
	}

	if (primerMov) //comprobar que la ident destino es realizable
	{

		flag = dif_aux.y < 3;
		//comprobar piezas en medio


	}
	else
	{
		flag = dif_aux.y < 2;
	}


	//if (primerMov == false && color == false){
	//	pos_final = this->posicion - 2.0;
	//    this->setPos(pos_final);
	//	primerMov = true;
	//	return true;
	//}
	//if (primerMov == false && color == true) {
	//	pos_final = this->posicion + 2.0;
	//	this->setPos(pos_final);
	//	primerMov = true;
	//	return true;
	//}
	//
	//if (primerMov == true && color == false) {
	//	pos_final = this->posicion - 1.0;
	//	this->setPos(pos_final);
	//	return true;
	//}
	///*if (primerMov && color)
	//	std::cout << "entra";*/
	//if (primerMov && color) {
	//	pos_final = this->posicion +1.0;
	//	this->setPos(pos_final);
	//	return true;
	//}

	//return false;
}





