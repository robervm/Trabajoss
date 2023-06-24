#pragma once
#include "Figura.h"
#define NUM 50
class Torre : public Figura {
private:
	float lado;
	Tablero* posicionesLegales[NUM];
	//Vector2D max, min;
public:
	Torre(bool color_, const std::string& tipo_,int identidad_,bool vida_) :Figura(color, tipo,identidad,vida) {
		lado = 0.1f;  color = color_; tipo = tipo_; identidad = identidad_;
		vida = vida_;
	}
	Torre();
	void dibuja();
	bool movLegal(int ident_, ListaTableros lt);
	std::string getName();
};

