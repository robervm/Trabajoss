#pragma once
#include "Tablero.h"
#include "Figura.h"
#define MAX_TABLEROS 8
#define NUM 14
#define MAX_FIGURAS 32
#define CAS 64
class ListaTableros
{
private:
    Tablero **listaa;
    Tablero* posicionesLegales[NUM];
    Tablero* casillasOcupadas[CAS];
    Figura* ListaPiezas[MAX_FIGURAS];
public:
    ListaTableros();
    virtual ~ListaTableros();
    void Dibuja();
    void setPos();
    Vector2D getMin();
    Vector2D getMax();
    bool getCasilla(int ident);
    void setIndent();
    bool piezasEnMedio(Figura *ListaFiguras, int cont, int origen, int destino);
    bool getCasillaOcupada(int destino,int cont);
    int compPiezaMismoColor(Figura* ListaFiguras, int i_, int origen, int destino, int cont);
    void setListaPiezas(Figura* ListaFiguras);
    Tablero getCasilla(int i, int j);
    Tablero getCasillaPos(int ident);
    bool getColor(int ident);
    Figura *getPiezaEnCasilla(int ident);
    void copiaListaFiguras(Figura* ListaFiguras[]);
    void eliminarPieza(int ident);

    friend class Interaccion;
    friend class Figura;
    friend class Tablero;
};

