#pragma once
#include "Figura.h"
#include <iostream>
#include <string>
#include "ListaTableros.h"

//using namespace ETSIDI;
class Peon : public Figura {
public:
	//Peon(bool _color,char _tipo);
	Peon(bool color_, const std::string& tipo_, int identidad_, bool vida_) :Figura(color, tipo, identidad, vida) {
		altura = 0.1f;  color = color_; tipo = tipo_; identidad = identidad_;
		vida = vida_;
	}
	//{ altura = 0.1f; }
	Peon();
		//altura = 0.1f;
	
	void dibuja();
	bool movLegal(int ident_,ListaTableros lt);
	std::string getName();
private:
	float altura;
	bool primerMov;
	Tablero* posicionesLegales[NUM];
	//Vector2D max, min;
};

