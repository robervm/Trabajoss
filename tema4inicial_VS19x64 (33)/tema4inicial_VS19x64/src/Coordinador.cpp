#include "Coordinador.h"
#include "ETSIDI.h"
Coordinador::Coordinador()
{
    estado = INICIO;
    aux = false;
}

Coordinador::~Coordinador()
{
}
void Coordinador::dibuja()
{
    if (estado == INICIO) {
        gluLookAt(0, 7.5, 30, // posicion del ojo
            0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
            0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fondo.png").id);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glTexCoord2d(0, 1); glVertex3f(-14.5, -3.4, -0.1);
        glTexCoord2d(1, 1); glVertex3f(14.5, -3.4, -0.1);
        glTexCoord2d(1, 0); glVertex3f(14.5, 18.5, -0.1);
        glTexCoord2d(0, 0); glVertex3f(-14.5, 18.5, -0.1);
        glEnd();
        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
        ETSIDI::setTextColor(1, 1, 0);
        ETSIDI::setFont("bin/fuentes/Classica-Book.ttf", 36);
        ETSIDI::printxy("CHECKMATE", -13, 15);
        ETSIDI::setTextColor(1, 1, 0);
        ETSIDI::setFont("bin/fuentes/Classica-Book.ttf", 12);
        ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", 1, 16);
        ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", 1, 15);
        ETSIDI::setFont("bin/fuentes/Classica-BoldOblique.ttf", 8);
        ETSIDI::printxy("Roberto Vázquez, Alejandro Mayor, Borja García, Joaquin Huirse", -13, -3);
    }
    else if (estado == JUEGO)
    {
        mundo.dibuja();
        aux = true;
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

void Coordinador::tecla(unsigned char key)
{
    if (estado == INICIO)
    {
        ETSIDI::play("bin/sonidos/audio.mp3");
        ETSIDI::playMusica("bin/sonidos/CancionDeFondo.mp3", 1);
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
        ETSIDI::playMusica("bin/sonidos/CancionDeFondo.mp3", 1);
        if (key == 'p')
        {
            estado = PAUSE;
            ETSIDI::play("bin/sonidos/Pause.mp3");
        }
        if (key == 'f') estado = FIN;
        if (key == 'g')
        {
            estado = GAMEOVER;
            ETSIDI::play("bin/sonidos/GameOver.mp3");
        }
    }
    else if (estado == GAMEOVER)
    {
        //ETSIDI::stopMusica();
        if (key == 'c')
        {
            estado = INICIO; 
       
        }
    }
    else if (estado == FIN)
    {
        ETSIDI::stopMusica();
        if (key == 'c')
            estado = INICIO;
    }
    else if (estado == PAUSE)
        if (key == 'c')
        {
            estado = JUEGO;
            ETSIDI::play("bin/sonidos/Continue.mp3");
        }
}

void Coordinador::teclaEspecial(unsigned char key)
{
    if (estado == JUEGO)
        mundo.teclaEspecial(key);
}
void Coordinador::mueve()
{
    if (estado == JUEGO && aux==true)
    {
        mundo.mueve();
    }

}
