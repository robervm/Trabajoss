#include "Caja.h"
#include "Hombre.h"
#include "Esfera.h"
#include "Bonus.h"
#include "Disparo.h" 
#include "Interaccion.h"
class Mundo
{
public:
	Disparo disparo;
	Esfera esfera, esfera2;
	Hombre hombre;
	Caja caja;
	Bonus bonus;
	Pared plataforma;
	void tecla(unsigned char key);
	void inicializa();
	//void rotarOjo();
	void mueve();
	void dibuja();
	void teclaEspecial(unsigned char key);

	float x_ojo;
	float y_ojo;
	float z_ojo;

};
