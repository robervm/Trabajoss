#include "Mundo.h"
#include "freeglut.h"
#include <math.h>


void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    


	caja.Dibuja();
	hombre.dibuja();
	plataforma.dibuja();
	bonus.dibuja();
	esferas.dibuja();
	disparos.dibuja();
	

}

void Mundo::mueve()
{
	for (int i = 0; i < esferas.getNumero(); i++)
	{
		for (int j = 0; j < disparos.getNum(); j++)
		{
			if (Interaccion::colision(*disparos[j], *esferas[i]))
			{
				Esfera* e = esferas[i]->dividir();
				if (e == 0)
					esferas.eliminar(esferas[i]);
				else
					esferas.agregar(e);

				disparos.eliminar(disparos[j]);

				ETSIDI::play("bin/sonidos/impacto.wav");
				break;
			}
		}
	}
	

	hombre.mueve(0.025f);
	bonus.mueve(0.025f);
	esferas.mueve(0.025f);
	esferas.rebote(); // rebote de las esferas entre sí
	esferas.rebote(caja); // rebote de las esferas con la caja
	esferas.rebote(plataforma); // rebote con la plataforma
	
	Esfera* aux = esferas.colision(hombre);
	if (aux != 0) {
		impacto = true;
		ETSIDI::play("bin/sonidos/impacto.wav");
	}
	disparos.mueve(0.025f);
	disparos.colision(caja);
	disparos.colision(plataforma);

	Interaccion::rebote(hombre, caja);
	

}

void Mundo::inicializa()
{
	impacto = false;
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	bonus.setPos(5.0f, 5.0f);
	nivel = 0;
	cargarNivel();


     
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
	case 'z':
	{
		DisparoEspecial* d_esp = new DisparoEspecial;
		Vector2D pos = hombre.getPos();
		d_esp->setPos(pos.x, pos.y);
		disparos.agregar(d_esp);
		ETSIDI::play("bin/sonidos/disparo.wav");
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

bool Mundo::cargarNivel()
{
	nivel++;
	hombre.setPos(0, 0);
	esferas.destruirContenido();
	disparos.destruirContenido();
	if (nivel == 1)
	{
		plataforma.setPos(-5.0f, 9.0f, 5.0f, 9.0f);
		Esfera* e1 = new Esfera(1.5f, 2, 4, 5, 15);
		e1->setColor(0, 0, 255);
		esferas.agregar(e1); //esfera
	}
	if (nivel == 2)
	{
		plataforma.setPos(-3.0f, 6.0f, 3.0f, 6.0f);
		plataforma.setColor(255, 0, 0);
		EsferaPulsante* e3 = new EsferaPulsante;
		e3->setPos(0, 12);
		e3->setVel(5, 3);
		esferas.agregar(e3);
		
	}
	if (nivel == 3)
	{
		plataforma.setPos(-10.0f, 12.0f, 4.0f, 10.0f);
		plataforma.setColor(255, 0, 255);
		for (int i = 0; i < 5; i++)
		{
			Esfera* aux = new Esfera(1.5, -5 + i, 12, i, 5);
			aux->setColor(i * 40, 0, 255 - i * 40);
			esferas.agregar(aux);
		}
	}
	if (nivel <= 3)
		return true;
	return false;
}

