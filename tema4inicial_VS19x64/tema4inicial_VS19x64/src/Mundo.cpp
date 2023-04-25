#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

/*void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}*/
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0,y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	esfera.dibuja();
	caja.Dibuja();
	hombre.dibuja();
	disparo.dibuja();
	plataforma.dibuja();
	bonus.dibuja();
	
}

void Mundo::mueve()
{
	hombre.mueve(0.025f);
	esfera.mueve(0.025f);
	bonus.mueve(0.025f);
	disparo.mueve(0.025f);
}

void Mundo::inicializa()
{
	
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	


	bonus.posicion.x = 5.0f;
	bonus.posicion.y = 5.0f;
	
	plataforma.limite1.x = -5.0f;
	plataforma.limite2.x = 5.0f;
	plataforma.limite1.y = 9.0f;
	plataforma.limite2.y = 9.0f;
	
	esfera.SetColor(0, 0, 255);
	esfera.SetRadio(1.5f);
	esfera.SetPos(2, 4);
	//bonus.setPos(5.0f, 5.0f);
	disparo.setPos(-5.0f, 0.0f);
	//plataforma.setPos(-5.0f, 9.0f, 5.0f, 9.0f);
}

void Mundo::tecla(unsigned char key)
{

}
