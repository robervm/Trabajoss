#include "Hombre.h"
#include "Caja.h" 
#include "Esfera.h"
#include "Disparo.h"
class Interaccion
{
public:
    Interaccion();
    virtual ~Interaccion();
    
    static void rebote(Hombre& h, Caja c);
    static bool rebote(Esfera& e, Pared p);
    static  void rebote(Esfera& e, Caja c);
    static bool rebote(Esfera& esfera1, Esfera& esfera2);
     static bool colision(Esfera e, Hombre h);
     static bool colision(Disparo d, Pared p);
     static bool colision(Disparo d, Caja c);
};
