#include "Rey.h"


Rey::Rey() {

	lado = 0.1f;
	for (int i = 0; i < NUM; i++) {
		posicionesLegales[i] = 0;
	}


}

void Rey::dibuja() {
    if (color == 1) {
        /*ETSIDI::setTextColor(250, 250, 250);
        ETSIDI::setFont("bin/fuentes/CHEQ_TT.TTF", 32);
        ETSIDI::printxy("w", posicion.x, posicion.y);*/
        sprite1.setCenter(0, 0);
        sprite1.setSize(0.8, 0.8);
        glPushMatrix();
        glTranslatef(posicion.x - 0.25, posicion.y - 0.25, 0.2);
        glColor3f(1.0f, 0.0f, 0.0f);
        sprite1.setState(5);
        sprite1.draw();
        glPopMatrix();
    }
    else {

        /*ETSIDI::setTextColor(0, 0, 0);
        ETSIDI::setFont("bin/fuentes/CHEQ_TT.TTF", 32);
        ETSIDI::printxy("t", posicion.x, posicion.y);*/
        sprite2.setCenter(0, 0);
        sprite2.setSize(0.8, 0.8);
        glPushMatrix();
        glTranslatef(posicion.x - 0.25, posicion.y - 0.25, 0.2);
        glColor3f(1.0f, 0.0f, 0.0f);
        sprite2.setState(5);
        sprite2.draw();
        glPopMatrix();

    }
}

std::string Rey::getName() {
    return tipo;
}
bool Rey::movLegal(int ident_, ListaTableros lt) {
    Vector2D pos, pos_ini;

    pos_ini.x = this->getPos().x;
    pos_ini.y = this->getPos().y;


    pos.x = ident_ / 10;
    pos.y = ident_ % 10;

    int cont = 0;
    //arriba
    if(pos_ini.y<max.y)
        posicionesLegales[cont++] = new Tablero(pos_ini.x, pos_ini.y + 1);
    //abajo
    if (pos_ini.y > min.y)
        posicionesLegales[cont++] = new Tablero(pos_ini.x, pos_ini.y - 1);
    //izquierda
    if (pos_ini.x < max.x)
        posicionesLegales[cont++] = new Tablero(pos_ini.x+1, pos_ini.y);
    //derecha
    if (pos_ini.x > min.x)
        posicionesLegales[cont++] = new Tablero(pos_ini.x-1, pos_ini.y);

    //diagonal-> ++
    if (pos_ini.x < max.x && pos_ini.y<max.y)
        posicionesLegales[cont++] = new Tablero(pos_ini.x+1, pos_ini.y + 1);
    //diagonal-> +-
    if (pos_ini.x < max.x && pos_ini.y > min.y)
        posicionesLegales[cont++] = new Tablero(pos_ini.x+1, pos_ini.y - 1);
    //diagonal-> --
    if (pos_ini.x > min.x && pos_ini.y > min.y)
        posicionesLegales[cont++] = new Tablero(pos_ini.x-1, pos_ini.y - 1);
    //diagonal-> -+
    if (pos_ini.x > min.x && pos_ini.y < max.y)
        posicionesLegales[cont++] = new Tablero(pos_ini.x-1, pos_ini.y + 1);

    
    bool bandera2 = false;

    for (int i = 0; i < cont; i++) {
        if (posicionesLegales[i]->getPosX() == pos.x && posicionesLegales[i]->getPosY() == pos.y)
            bandera2 = true;
    }

    //if (bandera2 == true)
     //   this->setPos(pos.x, pos.y);

    return bandera2;
}

