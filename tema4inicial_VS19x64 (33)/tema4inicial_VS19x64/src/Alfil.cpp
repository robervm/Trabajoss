#include "Alfil.h"

Alfil::Alfil() {

	lado = 0.1f;
}

void Alfil::dibuja() {
   
    if (color == 1) {
        sprite1.setCenter(0, 0);
        sprite1.setSize(0.8, 0.8);
        glPushMatrix();
        glTranslatef(posicion.x - 0.25, posicion.y - 0.25, 0.2);
        glColor3f(1.0f, 0.0f, 0.0f);
        sprite1.setState(2);
        sprite1.draw();
        glPopMatrix();
    }
    else {
        sprite2.setCenter(0, 0);
        sprite2.setSize(0.8, 0.8);
        glPushMatrix();
        glTranslatef(posicion.x - 0.25, posicion.y - 0.25, 0.2);
        glColor3f(1.0f, 0.0f, 0.0f);
        sprite2.setState(2);
        sprite2.draw();
        glPopMatrix();
    }
}

std::string Alfil::getName() {
    return tipo;
}
bool Alfil::movLegal(int ident_,ListaTableros lt) {
    Vector2D pos, pos_ini,dif,pos_var;
    Vector2D cont;
    bool flag = true;

    pos_ini = this->getPos();

    pos_var = pos_ini;

    pos = { ident_ / 10,ident_ % 10 };

    dif = pos - pos_ini;

    cont = { dif.x / abs(dif.x),dif.y / abs(dif.y) };

    if (pos.x < 1 || pos.x>8 || pos.y < 1 || pos.y>8) {
        flag = false;
        return flag;
    }

    if (abs(dif.x) != abs(dif.y) && dif.x != 0 && dif.y != 0)
    {
        flag = false;
        return flag;
    }
   
    //sobrecarga != IMPORTANTE
    while (pos_var!=pos && flag==true) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (pos_var.x==lt.getCasilla(i, j).getPieza()->getPos().x
                    && pos_var.y == lt.getCasilla(i, j).getPieza()->getPos().y){
                    flag = false;
                    return flag;
                }
                
            }
        }
        pos_var += cont;
    }
    
    if (lt.getCasillaPos(ident_).getPieza() != NULL &&
        this->color == lt.getCasillaPos(ident_).getPieza()->getColor())
    {
        flag = false;

    }

    
    return flag;
    /*

    int cont = 0;
    int contX, contY;

    //1 arriba derecha 
    int cont_global = 0;
    contY = pos_ini.y;
    contX = pos_ini.x;
    int cont_1 = 1;
    while (contY <= max.y && contX<=max.x) {

        posicionesLegales[cont_global] = new Tablero(pos_ini.x+cont_1, pos_ini.y + cont_1);
        cont_global++;
        contX++;
        contY++;
        cont_1++;
    }
    //2 arriba izquierda
    contY = pos_ini.y;
    contX = pos_ini.x;
    int cont_2 = 1;
    while (contY <= max.y && contX >= min.x) {

        posicionesLegales[cont_global] = new Tablero(pos_ini.x - cont_2, pos_ini.y + cont_2);
        cont_global++;
        contX--;
        contY++;
        cont_2++;
    }
    //3 abajo izquierda
    contY = pos_ini.y;
    contX = pos_ini.x;
    int cont_3 = 1;
    while (contY >= min.y && contX >= min.x) {

        posicionesLegales[cont_global] = new Tablero(pos_ini.x - cont_3, pos_ini.y - cont_3);
        cont_global++;
        contX--;
        contY--;
        cont_3++;
    }
    //4 abajo derecha
    contY = pos_ini.y;
    contX = pos_ini.x;
    int cont_4 = 1;
    while (contY >= min.y && contX <= max.x) {

        posicionesLegales[cont_global] = new Tablero(pos_ini.x + cont_4, pos_ini.y - cont_4);
        cont_global++;
        contX++;
        contY--;
        cont_4++;
    }

    
    bool bandera2 = false;

    for (int i = 0; i < cont_global; i++) {
        if (posicionesLegales[i]->getPosX() == pos.x && posicionesLegales[i]->getPosY() == pos.y)
            bandera2 = true;
    }

    //if (bandera2 == true)
        //this->setPos(pos.x, pos.y);

    return bandera2;
    */
}
