#pragma once
#include "Vector2D.h"
class ObjetoMovil
{
public:
	ObjetoMovil();

	virtual ~ObjetoMovil();

	virtual void mueve(float t);

	Vector2D getPos();
	void setPos(float x, float y);
	void setPos(Vector2D pos);
	void setVel(float vx, float vy);
	void setVel(Vector2D vel);
protected:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
};

