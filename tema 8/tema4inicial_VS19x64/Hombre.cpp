#include "Hombre.h"
#include "freeglut.h"


Hombre::Hombre() :sprite1("bin/imagenes/pangPlayer.png", 5)
{
    sprite1.setCenter(1, 0);
    sprite1.setSize(3, 3);
    altura = 2.8f;
}

Hombre::~Hombre()
{

}


void Hombre::dibuja()
{
    
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0.5);
    glColor3f(1.0f, 1.0f, 1.0f);
    

    //gestion de direccion y animacion
    if (velocidad.x > 0.01)sprite1.flip(false, false);
    if (velocidad.x < -0.01)sprite1.flip(true, false);
    if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
        sprite1.setState(0);
    else if (sprite1.getState() == 0)
        sprite1.setState(1, false);
    sprite1.draw();

    glPopMatrix();
}



float Hombre::getAltura() {


    return altura;
}

void Hombre::mueve(float t)
{
    ObjetoMovil::mueve(t);
    sprite1.loop();
}