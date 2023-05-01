#define MAX_DISPAROS 10
#include "Disparo.h"
#include "Caja.h"
#include "Pared.h"
class ListaDisparos
{
public:
    ListaDisparos();
    virtual ~ListaDisparos();

	bool agregar(Disparo* d);
	void eliminar(Disparo* d);
	void eliminar(int index);
	void destruirContenido();
	void mueve(float t);
	void dibuja();

	void colision(Pared p);
	void colision(Caja c);
	int getNum() { return numero; }
	Disparo* operator[](int index);
private:
    Disparo* lista[MAX_DISPAROS];
    int numero;
};

