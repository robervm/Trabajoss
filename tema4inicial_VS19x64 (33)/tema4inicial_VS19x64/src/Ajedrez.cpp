//#include "Mundo.h"
#include "freeglut.h"
#include "Coordinador.h"

//Mundo mundo;
Coordinador coord;
//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla
void onSpecialKeyboardDown(int key, int x, int y);
//void MouseButton(int button, int x, int y, bool down, bool skey, bool ctrlKey);


int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutSpecialFunc(onSpecialKeyboardDown); //gestion de los cursores
	//Inicializacion de la escena
	//pang.Inicializa();

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	coord.dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	coord.tecla(key);

	glutPostRedisplay();
}

void OnTimer(int value)
{
	//poner aqui el código de animacion
	coord.mueve();

	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}


void onSpecialKeyboardDown(int key, int x, int y)
{
	coord.teclaEspecial(key);
}






/*
void MouseButton(int button, int x, int y, bool down, bool skey, bool ctrlKey)
{

	GLint viewport[4];

	GLdouble modelview[16];

	GLdouble projection[16];

	GLfloat winX, winY, winZ;

	GLdouble posX, posY, posZ;



	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);

	glGetDoublev(GL_PROJECTION_MATRIX, projection);

	glGetIntegerv(GL_VIEWPORT, viewport);



	winX = (float)x;

	winY = (float)viewport[3] - (float)y;

	glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);

	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);



	Vector2D posicion = { posX,posY };

	pang.setRaton(posicion);



	//finally cell coordinates




	///////////////////////////    

	//capture other mouse events



	/*if (down)

	{

		for (int j = 0; j < )

	}*/


//}







