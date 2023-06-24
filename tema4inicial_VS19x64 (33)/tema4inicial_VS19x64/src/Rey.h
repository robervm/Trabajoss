#pragma once
#include "Figura.h"
class Rey : public Figura {
private:
	float lado;
	Tablero* posicionesLegales[NUM];
	//Vector2D max, min;
public:
	Rey(bool color_, const std::string& tipo_, int identidad_, bool vida_) :Figura(color, tipo, identidad, vida) {
		lado = 0.1f;  color = color_; tipo = tipo_; identidad = identidad_;
		vida = vida_;
	}
	Rey();
	void dibuja();
	bool movLegal(int ident_, ListaTableros lt);
	std::string getName();
};

