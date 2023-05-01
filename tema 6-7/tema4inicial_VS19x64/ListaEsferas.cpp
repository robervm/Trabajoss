#include "ListaEsferas.h"
#include "Interaccion.h" 
ListaEsferas::ListaEsferas()
{
    numero = 0;
    for (int i = 0; i < MAX_ESFERAS; i++)
        lista[i] = 0;
}
ListaEsferas::~ListaEsferas()
{

}
bool ListaEsferas::agregar(Esfera* e)
{
    for (int i = 0; i < numero; i++)
        if (lista[i] == e)
            return false;

    if (numero < MAX_ESFERAS)
        lista[numero++] = e; // �ltimo puesto sin rellenar
    else
        return false; // capacidad m�xima alcanzada
    return true;
}

void ListaEsferas::dibuja()
{
    for (int i = 0; i < numero; i++)
        lista[i]->dibuja();
}

void ListaEsferas::mueve(float t)
{
    for (int i = 0; i < numero; i++)
        lista[i]->mueve(t);
}

void ListaEsferas::rebote(Caja caja)
{
    for (int i = 0; i < numero; i++)
        Interaccion::rebote(*(lista[i]), caja);
}

void ListaEsferas::rebote(Pared p)
{
    for (int i = 0; i < numero; i++)
        Interaccion::rebote(*(lista[i]), p);
}

void ListaEsferas::rebote()
{
    for (int i = 0; i < numero - 1; i++)
        for (int j = i + 1; j < numero; j++)
            Interaccion::rebote(*(lista[i]), *(lista[j]));
}

void ListaEsferas::destruirContenido()
{
    for (int i = 0; i < numero; i++) // destrucci�n de esferas contenidas
        delete lista[i];
    numero = 0; // inicializa lista
}

void ListaEsferas::eliminar(int index)
{
    if ((index < 0) || (index >= numero))
        return;
    delete lista[index];
    numero--;
    for (int i = index; i < numero; i++)
        lista[i] = lista[i + 1];
}

void ListaEsferas::eliminar(Esfera* e)
{
    for (int i = 0; i < numero; i++)
        if (lista[i] == e)
        {
            eliminar(i);
            return;
        }
}

Esfera* ListaEsferas::colision(Hombre &h)
{
    for (int i = 0; i < numero; i++)
    {
        if (Interaccion::colision(*(lista[i]), h))
            return lista[i];
    }
    return 0; //no hay colisi�n
}

Esfera* ListaEsferas::operator [](int i)
{
    if (i >= numero)
        i = numero - 1;
    if (i < 0) 
        i = 0;
    return lista[i];
}