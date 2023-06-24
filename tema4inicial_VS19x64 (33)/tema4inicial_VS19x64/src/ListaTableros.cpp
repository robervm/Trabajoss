#include "ListaTableros.h"
#include <iostream>

using namespace std;
ListaTableros::ListaTableros() {

   

    listaa = new Tablero*[MAX_TABLEROS];
    for (int i = 0; i < MAX_TABLEROS; i++) {
        listaa[i] = new Tablero[MAX_TABLEROS];
    }
    
   

    for (int i = 0; i < NUM; i++) {
        casillasOcupadas[i] = 0;
    }
}


ListaTableros::~ListaTableros() {
    for (int i = 0; i < MAX_TABLEROS; i++) {
        for (int j = 0; j < MAX_TABLEROS; j++) {
            //listaa[i]->dibuja();
            delete (*(listaa + i) + j);
        }
    }
}
void ListaTableros::Dibuja()
{
   
    for (int i = 0; i < MAX_TABLEROS; i++) {
        for (int j = 0; j < MAX_TABLEROS; j++) {
            //listaa[i]->dibuja();
            (*(listaa + i) + j)->dibuja();
            if (listaa[i][j].getPieza() != NULL)
                listaa[i][j].getPieza()->dibuja();
        }
    }
}
void ListaTableros::setIndent() {
    for (int i = 0; i < MAX_TABLEROS; i++) {
        for (int j = 0; j < MAX_TABLEROS; j++) {
            //listaa[i]->dibuja();
            //(*(listaa + i) + j)->identi(i,j);
            listaa[i][j].identi(i, j);
        }
    }
}

Vector2D ListaTableros::getMin() {
    Vector2D pos;
    pos=(*(listaa))->getPos();

    return pos;
}

Vector2D ListaTableros::getMax() {
    Vector2D pos;
    pos=(*(listaa+7)+7)->getPos();
    return pos;
}

bool ListaTableros::getCasilla(int ident) {

    for (int i = 0; i < MAX_TABLEROS; i++) {
        for (int j = 0; j < MAX_TABLEROS; j++) {
            //listaa[i]->dibuja();
            // //lista[i][j]
           //delete (*(listaa + i) + j);
           /* if ((*(listaa + i) + j)->getIdent() == ident)
                return true;*/
            if (listaa[i][j].getIdent() == ident)
                return true;
        }
    }

    return false;
}
bool ListaTableros::piezasEnMedio(Figura* ListaFiguras, int cont, int origen, int destino) {
    //posible copia de lista Figuras
    int cont2 = 0;
    for (int i = 0; i < MAX_TABLEROS; i++) {
        for (int j = 0; j < MAX_TABLEROS; j++) {
            for (int k = 0; k < cont; k++) {
                if ((*(listaa + i) + j)->getPos().x == ListaFiguras[k].getPos().x && (*(listaa + i) + j)->getPos().y == ListaFiguras[k].getPos().y) {
                    casillasOcupadas[cont2++] = new Tablero(ListaFiguras[k].getPos());

                }
            }
        }

    }
    bool esTorre = false;
    int ud_o, ud_d, dec_o, dec_d;
    int contX, contY, cont1;



    dec_o = origen / 10;
    ud_o = origen % 10;

    dec_d = destino / 10;
    ud_d = destino % 10;

    if ((dec_d - dec_o == 0) || (ud_d - ud_o == 0))
        esTorre = true;

    if (esTorre == false) {
        if ((dec_d - dec_o > 0) && (ud_d - ud_o > 0))
        {
            contX = 1;
            contY = 1;
        }
        if ((dec_d - dec_o < 0) && (ud_d - ud_o > 0))
        {
            contX = 1;
            contY = -1;
        }
        //
        if ((dec_d - dec_o < 0) && (ud_d - ud_o < 0))
        {
            contX = -1;
            contY = -1;
        }
        if ((dec_d - dec_o > 0) && (ud_d - ud_o < 0))
        {
            contX = -1;
            contY = 1;
        }
    }

    if (esTorre == true) {
        //arriba
        if ((dec_d - dec_o == 0) && (ud_d - ud_o > 0))
        {
            contX = 0;
            contY = 1;
        }
        //abajo
        if ((dec_d - dec_o == 0) && (ud_d - ud_o < 0))
        {
            contX = 0;
            contY = -1;
        }
        //izquierda
        if ((dec_d - dec_o < 0) && (ud_d - ud_o == 0))
        {
            contX = -1;
            contY = 0;
        }
        //derecha
        if ((dec_d - dec_o > 0) && (ud_d - ud_o == 0))
        {
            contX = 1;
            contY = 0;
        }
    }

    bool PiezaEnMedio = false;

    //
    for (int i = 0; i < NUM; i++) {
        posicionesLegales[i] = 0;
    }

    //
    cont1 = origen;
    for (int i = origen + 1; i < destino; i++)
    {
        posicionesLegales[i - origen + 1] = new Tablero(dec_o + 1 + contX, ud_o + 1 + contY);
        for (int k = 0; k < cont; k++) {
            if (posicionesLegales[i - origen + 1]->getPosX() == casillasOcupadas[k]->getPosX() && posicionesLegales[i - origen + 1]->getPosY() == casillasOcupadas[k]->getPosY()) {
                PiezaEnMedio = true;
            }
        }

        
    }
    return PiezaEnMedio;
}
bool ListaTableros::getCasillaOcupada(int destino,int cont)
{
    for (int i = 0; i < cont; i++){
       /* if (casillasOcupadas[i].getPos() == destino)
            return true;*/
        if (casillasOcupadas[i]->getPosX() == (float)(destino / 10) && casillasOcupadas[i]->getPosY() == (float)(destino % 10)) {
            return true;
        }
    }

    return false;
}

int ListaTableros::compPiezaMismoColor(Figura* ListaFiguras, int i_, int origen, int destino, int cont) {
    bool bandera1;

    if (i_ >= 0 && i_ < 16)
        bandera1 = false;//pieza origen blanca
    else
        bandera1 = true;//pieza origen negra

    int j_=0;

    for (int i = 0; i < cont; i++) {
        if (ListaFiguras[i].getIdent() == destino)
            j_ = i;
    }

    bool bandera2;
    if (j_ >= 0 && j_ < 16)
        bandera2 = false;//pieza destino blanca
    else
        bandera2 = true;//pieza destino negra

    if (bandera1 != bandera2)
        return j_;
    else
        return -1;
}

/*



bool ListaTableros::compPiezaMismoColor(ListaFiguras,i_,origen,destino,)
bool bandera1;
if(i_>0 && i_<16)
//La pieza es blanca
bandera1=false;
else
//la pieza es negra
bandera1=true;
true;

Figura *ListaFigurasAux;
//copiamos ListaFiguras en ListaFigurasAux
int j_;

for(int i=0;i<32;i++)
{
if(ListaFigurasAux[i].getIdent()==destino)
j_=i;
}
bool bandera2=false;
if(j_>0 && j_<16)
//La pieza es blanca
bandera2=false;
else
//la pieza es negra
bandera2=true;

if(bandera1!=bandera2)
    return true

else return false;
*/
void ListaTableros::setPos() {

    
    for (int i = 0; i < MAX_TABLEROS; i++) {
        for (int j = 0; j < MAX_TABLEROS; j++) {
            //listaa[i]->dibuja();
            if ((i + j) % 2 == 0) {
                (*(listaa + i) + j)->setColor(101, 67, 33);
                
            }
            else{
                (*(listaa + i) + j)->setColor(225, 198, 153);
            }

            (*(listaa + i) + j)->setPos(0.5 + (float)j, 0.5 + (float)i, 1.5 + (float)j, 1.5 + (float)i);
        }
    }
}

void ListaTableros::setListaPiezas(Figura* ListaFiguras) {
    for (int i = 0; i < MAX_TABLEROS; i++) {
        for (int j = 0; j < MAX_TABLEROS; j++) {
            for (int k = 0; k <MAX_FIGURAS; k++) {
                if (listaa[i][j].getPos().x == ListaFiguras[k].getPos().x) {
                    listaa[i][j].setPieza((ListaFiguras+k));

                }    
           }
            
        }
    }
}//PREGUNTA TUTOR-->(LISTAFIGURA+K) Y For anidados
//setListaPiezas es valido ?

/*
for(int i=0;i<MAX_FIGURAS;i++)
    lista[i]=new (ListaFiguras[i].getTipo,..
    lista[i]=ListaFiguras[i]
    //VERIFICAR SI FUNCIONA-->IMPORTANTE
*/ 

Tablero ListaTableros::getCasilla(int i, int j) {

    return listaa[i][j];
}

Tablero ListaTableros::getCasillaPos(int ident)
{
    int i = ident / 10;
    int j = ident % 10;

    return listaa[i][j];
}

bool ListaTableros::getColor(int ident) {

    
    return getPiezaEnCasilla(ident)->getColor();
}

Figura* ListaTableros::getPiezaEnCasilla(int ident) {
    int i = ident / 10;
    int j = ident % 10;

    return listaa[i][j].getPieza();
}

void ListaTableros::copiaListaFiguras(Figura* ListaFiguras[])
{
    
    for(int i=0;i<MAX_FIGURAS;i++){
        //lista[i]=new (ListaFiguras[i].getTipo,..
        ListaPiezas[i] = ListaFiguras[i];
        //VERIFICAR SI FUNCIONA-->IMPORTANTE
        //tablero *ListaCasillasconPiezas
        //ListaCasillaconPiezas.getPieza()=ListaFiguras[i]
    }
}

void ListaTableros::eliminarPieza(int ident)
{
    int i = ident / 10;
    int j = ident % 10;

    listaa[i][j].setPieza(NULL);
}

