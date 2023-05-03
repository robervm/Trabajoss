#include "CoordinadorPang.h"
#include "ETSIDI.h"
CoordinadorPang::CoordinadorPang()
{
	estado = INICIO;
}

CoordinadorPang::~CoordinadorPang()
{
}
void CoordinadorPang::dibuja()
{
    if (estado == INICIO) {
        gluLookAt(0, 7.5, 30, // posicion del ojo
            0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
            0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
       ETSIDI::setTextColor(1, 1, 0);
        ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 16);
        ETSIDI::printxy("Pang 1.1", -5, 8);
        ETSIDI::setTextColor(1, 1, 1);
        ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 12);
        ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
        ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
        ETSIDI::printxy("Hernando & Rodriguez-Losada", 2, 1);
    }
    else if (estado == JUEGO)
    {
        mundo.dibuja();
    }
    else if (estado == GAMEOVER)
    {
        mundo.dibuja();
        ETSIDI::setTextColor(1, 0, 0);
        ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 16);
        ETSIDI::printxy("GAMEOVER: Has perdido", -5, 10);
        ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
    }
    else if (estado == FIN)
    {
        mundo.dibuja();
        ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 16);
        ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -5, 10);
        ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
    }
    else if (estado == PAUSE)
	{
		gluLookAt(0, 7.5, 30,  // posicion del ojo   
			0.0, 7.5, 0.0,      // hacia que punto mira  (0,7.5,0)   
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
		   //Colocamos una foto
		

	
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 32);
		ETSIDI::printxy("PAUSE", -8, 15);
		ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PRESS '-C-' TO CONTINUE ", -11, 8);
		
	}
    
}

void CoordinadorPang::tecla(unsigned char key)
{
    if (estado == INICIO)
    {
        if (key == 'e')
        {
            mundo.inicializa();
            estado = JUEGO;
        }
        if (key == 's')
            exit(0);
    }
    else if (estado == JUEGO)
    {
        mundo.tecla(key);
        if (key == 'p') estado = PAUSE;
    }
    else if (estado == GAMEOVER)
    {
        if (key == 'c')
            estado = INICIO;
    }
    else if (estado == FIN)
    {
        if (key == 'c')
            estado = INICIO;
    }
    else if (estado == PAUSE)
        if (key == 'c') estado = JUEGO;
}

void CoordinadorPang::teclaEspecial(unsigned char key)
{
    if (estado == JUEGO)
        mundo.teclaEspecial(key);
}
void CoordinadorPang::mueve()
{
    if (estado == JUEGO)
    {
        mundo.mueve();
        if (mundo.getNumEsferas() == 0)
        {
            if (!mundo.cargarNivel())
                estado = FIN;
        }
        if (mundo.getImpacto())
        {
            estado = GAMEOVER;
        }
    }

}
