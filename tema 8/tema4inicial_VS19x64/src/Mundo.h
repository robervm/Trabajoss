#include "Caja.h"
#include "Hombre.h"
#include "Esfera.h"
#include "Bonus.h"
#include "Disparo.h" 
#include "Interaccion.h"
#include "ListaEsferas.h"
#include "ListaDisparos.h"
#include "EsferaPulsante.h"
#include "DisparoEspecial.h"
class Mundo
{
public:
	virtual ~Mundo();
	Disparo disparo;
	Esfera esfera, esfera2;
	Hombre hombre;
	Caja caja;
	Bonus bonus;
	Pared plataforma;
	ListaEsferas esferas;
	ListaDisparos disparos;
	EsferaPulsante esferaPulsante;
	DisparoEspecial disparoEspecial;
	int nivel;
	bool impacto;
	void tecla(unsigned char key);
	void inicializa();
	void mueve();
	void dibuja();
	void teclaEspecial(unsigned char key);
	bool getImpacto() { return impacto; }
	int getNumEsferas() { return esferas.getNumero(); }

	bool cargarNivel();

	float x_ojo;
	float y_ojo;
	float z_ojo;

};
