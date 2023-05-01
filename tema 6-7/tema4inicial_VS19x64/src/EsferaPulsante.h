#pragma once
#include "Esfera.h"
class EsferaPulsante :public Esfera
{
public:
	EsferaPulsante();
	virtual ~EsferaPulsante();
	void mueve(float t);

private:
	float radio_max;
	float radio_min;
	float pulso;
};

