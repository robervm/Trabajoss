#include "Mundo.h"
class CoordinadorPang
{
public:
	CoordinadorPang();
	virtual ~CoordinadorPang();
	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
protected:
	Mundo mundo;
	enum Estado { INICIO, JUEGO,GAMEOVER,FIN,PAUSE };
	Estado estado;

};

