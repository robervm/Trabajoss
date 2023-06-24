#include "Torre.h"
#include "freeglut.h"


Torre::Torre() {
	lado = 0.1f;
    for (int i = 0; i < NUM; i++) {
        posicionesLegales[i] = 0;
    }

    
}

void Torre::dibuja() {
    if (color == 1) {
        
        sprite1.setCenter(0, 0);
        sprite1.setSize(0.8, 0.8);
        glPushMatrix();
        glTranslatef(posicion.x - 0.25, posicion.y - 0.25, 0.2);
        glColor3f(1.0f, 0.0f, 0.0f);
        sprite1.setState(1);
        sprite1.draw();
        glPopMatrix();
    }
    else {
        sprite2.setCenter(0, 0);
        sprite2.setSize(0.8, 0.8);
        glPushMatrix();
        glTranslatef(posicion.x - 0.25, posicion.y - 0.25, 0.2);
        glColor3f(1.0f, 0.0f, 0.0f);
        sprite2.setState(1);
        sprite2.draw();
        glPopMatrix();
    }
}

std::string Torre::getName() {
    return tipo;
}
bool Torre::movLegal(int ident_, ListaTableros lt) {
    Vector2D pos, pos_ini;

    pos_ini.x = this->getPos().x;
    pos_ini.y = this->getPos().y;

    
    pos.x = ident_ / 10;
    pos.y = ident_ % 10;


    int cont = 0;
    float cont1, cont2, cont3, cont4;
    //subida
    int cont_global = 0;
    cont1 = pos_ini.y;
    int cont_1 = 1;
    while (cont1 < max.y) {

       posicionesLegales[cont_global] = new Tablero(pos_ini.x, pos_ini.y + cont_1);
        cont_global++;
        cont1++;
        cont_1++;
    }
    //cont += i;
    //bajada
    //int i = 0;
    cont2 = pos_ini.y;
    int cont_2 = 1;
    while (cont2 > min.y) {

        posicionesLegales[cont_global] = new Tablero(pos_ini.x, pos_ini.y - cont_2);
        cont_global++;
        cont2--;
        cont_2++;
    }
    // cont += i;
     //izquierda
     //int i = 0;
    cont3 = pos_ini.x;
    int cont_3 = 1;
    while (cont3 > min.x) {

        posicionesLegales[cont_global] = new Tablero(pos_ini.x - cont_3, pos_ini.y);
        cont_global++;
        cont3--;
        cont_3++;
    }
    //cont += i;
    //derecha
    //int i = 0;
    cont4 = pos_ini.x;
    int cont_4 = 1;
    while (cont4 < max.x) {

        posicionesLegales[cont_global] = new Tablero(pos_ini.x + cont_4, pos_ini.y);
        cont_global++;
        cont4++;
        cont_4++;
    }
    //cont += i;
    bool bandera2 = false;

    for (int i = 0; i < cont_global; i++) {
        if (posicionesLegales[i]->getPosX() == pos.x && posicionesLegales[i]->getPosY() == pos.y)
            bandera2 = true;
    }

    //if (bandera2 == true)
      //  this->setPos(pos.x, pos.y);

    return bandera2;
}

