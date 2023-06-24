#pragma once
#include "Mundo.h"
class Coordinador
{
public:
	Coordinador();
	virtual ~Coordinador();
	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
	void setRaton(Vector2D pos);

protected:
	Mundo mundo;
	bool aux;
	enum Estado { INICIO, JUEGO, GAMEOVER, FIN, PAUSE };
	Estado estado;
	Vector2D raton;

};

