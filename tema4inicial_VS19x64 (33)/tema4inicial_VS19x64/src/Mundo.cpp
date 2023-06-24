#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include <iostream>

using namespace std;


 
void Mundo::dibuja()

{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		x_ojo, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

//aqui es donde hay que poner el codigo de dibujo
	glEnable(GL_TEXTURE_2D);


	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/madera.png").id);

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-14.5, -3.4, -0.1);
	glTexCoord2d(1, 1); glVertex3f(14.5, -3.4, -0.1);
	glTexCoord2d(1, 0); glVertex3f(14.5, 18.5, -0.1);
	glTexCoord2d(0, 0); glVertex3f(-14.5, 18.5, -0.1);
	glEnd();
	glEnable(GL_LIGHTING);

	glDisable(GL_TEXTURE_2D);

	lt.Dibuja();
	//player.dibuja();
	//peones
	for (int i = 0; i < NUM_FIGURAS; i++)
		ListaFiguras[i]->dibuja();

}

void Mundo::mueve()
{
	
	

	//Introduces una pieza: alfil_blanco2
	
	

	

	if (turno) {
		
			do  {
				cout << "Introduzca la casilla de origen:";
				cin >> ident;
			} while (!lt.getColor(ident) || lt.getPiezaEnCasilla(ident) == NULL);
			 
		
		cout << "Introduzca la casilla que quieres llegar:";
		cin >> pos;

		if (lt.getPiezaEnCasilla(ident)->movLegal(pos, lt)) {
			lt.getPiezaEnCasilla(ident)->setPos(pos);
			lt.getPiezaEnCasilla(ident)->setIdent(pos);

			if (lt.getPiezaEnCasilla(pos) != NULL)
				lt.eliminarPieza(pos);

		}

		turno = !turno;
	}


	
/*	if (lt.getCasilla(ident) == true) {
		for (int i = 0; i < 32; i++) {
			if (ListaFiguras[i]->getIdent() == ident) {
				if (ListaFiguras[i]->movLegal(pos)) {
					if (ListaFiguras[i]->getName() == "a1" || ListaFiguras[i]->getName() == "a2" || ListaFiguras[i]->getName() == "t1" || ListaFiguras[i]->getName() == "t2" || ListaFiguras[i]->getName() == "q") {
						if (lt.piezasEnMedio(*ListaFiguras, (cont_blancas + cont_negras), ident, pos) == true) 
						{}
						else {
							if (lt.getCasillaOcupada(pos,(cont_blancas+cont_negras))==false) {
								//no se produce el movimiento
							}
							else {
								if (lt.compPiezaMismoColor(*ListaFiguras, i, ident, pos,(cont_blancas+cont_negras)) < 0){}
									//ListaFiguras[i]->setPos(pos); //esto se quita
								else {
									j_ = lt.compPiezaMismoColor(*ListaFiguras, i, ident,pos, (cont_blancas + cont_negras));
									ListaFiguras[i]->setPos(pos);
									if (j_>=0 && j_<16) {
										//ListaFiguras[i]->setPos(pos);//fuera de este if
										delete ListaFiguras[j_];
										cont_blancas--;
									}
									else
									{
										delete ListaFiguras[j_];
										cont_negras--;
									}
								}
							}

							//If(lt.getCasillaOcupada(pos)
						}
					}else{
						if (lt.getCasillaOcupada(pos, (cont_blancas + cont_negras)) == false) {
							//no se produce el movimiento
						}
						else {
							if (lt.compPiezaMismoColor(*ListaFiguras, i, ident, pos, (cont_blancas + cont_negras)) < 0){}
								//ListaFiguras[i]->setPos(pos);//esto lo quitamos
							else {
								j_ = lt.compPiezaMismoColor(*ListaFiguras, i, ident, pos, (cont_blancas + cont_negras));
								ListaFiguras[i]->setPos(pos);

								if (j_ >= 0 && j_ < 16) {
									delete ListaFiguras[j_];
									cont_blancas--;
								}
								else
								{
									delete ListaFiguras[j_];
									cont_negras--;
								}
							}
						}

					}

					}
				}
			}
		}
		*/


		}



void Mundo::inicializa()
{
	//impacto = false;
	x_ojo = 5.0;
	y_ojo = 4.5;
	z_ojo = 16.0;
	j_ = 0;
	//turno
	turno = false;
	
	//Negras
	ListaFiguras[0] = new Torre(false,"t1",18,true);
	ListaFiguras[1] = new Caballo(false,"c1",28,true);
	ListaFiguras[2] = new Alfil(false,"a1",38,true);
	ListaFiguras[3] = new Reina(false,"q",48, true);
	ListaFiguras[4] = new Rey(false,"k",58, true);
	ListaFiguras[5] = new Alfil(false,"a2",68, true);
	ListaFiguras[6] = new Caballo(false,"c2",78, true);
	ListaFiguras[7] = new Torre(false,"t2",88, true);
	ListaFiguras[8] = new Peon(false,"p1",17, true);
	ListaFiguras[9] = new Peon(false,"p2",27, true);
	ListaFiguras[10] = new Peon(false,"p3",37, true);
	ListaFiguras[11] = new Peon(false,"p4",47, true);
	ListaFiguras[12] = new Peon(false,"p5",57, true);
	ListaFiguras[13] = new Peon(false,"p6",67, true);
	ListaFiguras[14] = new Peon(false,"p7",77, true);
	ListaFiguras[15] = new Peon(false,"p8",87, true);

	//Blancas
	ListaFiguras[16] = new Torre(true, "t1",11, true);
	ListaFiguras[17] = new Caballo(true, "c1",21, true);
	ListaFiguras[18] = new Alfil(true, "a1",31, true);
	ListaFiguras[19] = new Reina(true, "q",41, true);
	ListaFiguras[20] = new Rey(true, "k",51, true);
	ListaFiguras[21] = new Alfil(true, "a2",61, true);
	ListaFiguras[22] = new Caballo(true, "c2",71, true);
	ListaFiguras[23] = new Torre(true, "t2",81, true);
	ListaFiguras[24] = new Peon(true, "p1",12, true);
	ListaFiguras[25] = new Peon(true, "p2",22, true);
	ListaFiguras[26] = new Peon(true, "p3",32, true);
	ListaFiguras[27] = new Peon(true, "p4",42, true);
	ListaFiguras[28] = new Peon(true, "p5",52, true);
	ListaFiguras[29] = new Peon(true, "p6",62, true);
	ListaFiguras[30] = new Peon(true, "p7",72, true);
	ListaFiguras[31] = new Peon(true, "p8",82, true);
	

	//Posicionar
	//torres negras
	
	for (int i = 0; i < NUM_FIGURAS / 2; i++) {
     if(i<8)
		 ListaFiguras[i]->setPos(1.0 + ((float)i),8.0);
	 else
		 ListaFiguras[i]->setPos(1.0 + ((float)i-8.0),7.0);
	}
	
	for (int i = NUM_FIGURAS/2; i < NUM_FIGURAS; i++) {
		if (i < 24)
			ListaFiguras[i]->setPos(1.0 + ((float)i-16.0),1.0);
		else
			ListaFiguras[i]->setPos(1.0 + ((float)i - 24.0),2.0);
	}

	lt.setIndent();
	lt.setPos();
	
	
	
}

void Mundo::tecla(unsigned char key)
{
	
}

void Mundo::teclaEspecial(unsigned char key)
{
	
}


Mundo::~Mundo()
{
	//esferas.destruirContenido();
}

