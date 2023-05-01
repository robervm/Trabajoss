#include "Mundo.h"
#include "freeglut.h"
#include <math.h>


void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    


	esfera.dibuja();
	esfera2.dibuja();
	caja.Dibuja();
	hombre.dibuja();
	disparo.dibuja();
	plataforma.dibuja();
	bonus.dibuja();
	esferas.dibuja();
	disparos.dibuja();
	esferaPulsante.dibuja();
	disparoEspecial.dibuja();

}

void Mundo::mueve()
{
	hombre.mueve(0.025f);
	esfera.mueve(0.025f);
	esfera2.mueve(0.025f);
	bonus.mueve(0.025f);
	disparo.mueve(0.025f);
	esferas.mueve(0.025f);
	esferas.rebote(); // rebote de las esferas entre sí
	esferas.rebote(caja); // rebote de las esferas con la caja
	esferas.rebote(plataforma); // rebote con la plataforma
	Esfera* aux = esferas.colision(hombre);
	if (aux != 0)//si alguna esfera ha chocado
	{
		esferas.eliminar(aux);
		ETSIDI::play("bin/sonidos/impacto.wav"); //linea agregada 
	}
	disparos.mueve(0.025f);
	disparos.colision(caja);
	disparos.colision(plataforma);

	Interaccion::rebote(hombre, caja);
	Interaccion::rebote(esfera, caja);
	Interaccion::rebote(esfera, plataforma);
	Interaccion::rebote(esfera2, caja);
	Interaccion::rebote(esfera2, plataforma);
	Interaccion::rebote(esfera, esfera2);

	esferaPulsante.mueve(0.025f);
	Interaccion::rebote(esferaPulsante, plataforma);
	Interaccion::rebote(esferaPulsante, caja);
	for (int i = 0; i < esferas.getNumero(); i++)
		Interaccion::rebote(esferaPulsante, *esferas[i]);


	disparoEspecial.mueve(0.025f);

}

void Mundo::inicializa()
{

	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;




	

	Esfera* e1 = new Esfera(1, 2, 4, 5, 15); // esfera1
	e1->setColor(200, 0, 0);
	esferas.agregar(e1); // esfera1 a la lista
	Esfera* e2 = new Esfera(2, -2, 4, -5, 15); // esfera2
	e2->setColor(255, 255, 255);
	esferas.agregar(e2); //esfera2 a la lista 

	bonus.setPos(5.0f, 5.0f);
	disparo.setPos(-5.0f, 0.0f);
	disparoEspecial.setPos(5.0f, 0.0f);
	plataforma.setPos(-5.0f, 9.0f, 5.0f, 9.0f);

	for (int i = 0; i < 6; i++)
	{
		Esfera* aux = new Esfera(0.75 + i * 0.25, i, 1 + i, i, i);
		esferas.agregar(aux);
	}
}

void Mundo::tecla(unsigned char key)
{
	switch (key)
	{
	case '1':
		esferas.agregar(new Esfera(0.5f, 0, 10));
		break;

	case '2':
		esferas.agregar(new Esfera(1.0f, 0, 10));
		break;
	case '3':
		esferas.agregar(new Esfera(1.5f, 0, 10));
		break;
	case '4':
		esferas.agregar(new Esfera(2.0f, 0, 10));
		break;
	case ' ':
	{
		Disparo* d = new Disparo();
		Vector2D pos = hombre.getPos();
		d->setPos(pos.x, pos.y);
		if (disparos.agregar(d))
			hombre.setVel(0, 0);
		else delete d;
		break;
	}
	}
}

void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		hombre.setVel(-5.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		hombre.setVel(5.0f, 0.0f);
		break;
	}
}

Mundo::~Mundo()
{
	esferas.destruirContenido();
}

