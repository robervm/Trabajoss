
#include "Tablero.h"
#include "ListaTableros.h"
#include "Figura.h"
#include "ETSIDI.h"
#include "Peon.h"
#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"
#define NUM_FIGURAS 32
class Mundo
{
public:
	
	virtual ~Mundo();
	
	Tablero tablero;
	ListaTableros lt;
	//Figura player;
	Peon p1b, p2b, p3b, p4b, p5b, p6b, p7b, p8b;
	Torre t1b, t2b;
	Caballo cb1, cb2;
	Alfil ab1, ab2;
	Reina qb;
	Rey kb;
	Figura* ListaFiguras[NUM_FIGURAS];
	int ident,pos,j_;
	int cont_blancas = 16, cont_negras = 16;
	bool turno;


	
	void tecla(unsigned char key);
	void inicializa();
	//void rotarOjo();
	void mueve();
	void dibuja();
	void teclaEspecial(unsigned char key);
	//void detectCas(Vector2D pos);

	float x_ojo;
	float y_ojo;
	float z_ojo;
};
