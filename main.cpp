
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

#include "3D_bib.h"
#include "Ship.h"


//Declaracion de variables

//Variables dimensiones de la pantalla
int WIDTH=500;
int HEIGTH=500;
//Variables para establecer los valores de gluPerspective
float FOVY=60.0;
float ZNEAR=0.01;
float ZFAR=100.0;
//Variables para definir la posicion del observador
//gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z)
float EYE_X=10.0;
float EYE_Y=5.0;
float EYE_Z=10.0;
float CENTER_X=0;
float CENTER_Y=0;
float CENTER_Z=0;
float UP_X=0;
float UP_Y=1;
float UP_Z=0;
//Variables para dibujar los ejes del sistema
float X_MIN=-20;
float X_MAX=20;
float Y_MIN=-20;
float Y_MAX=20;
float Z_MIN=-100;
float Z_MAX=20;

//Se declara el objeto para utilizar las operaciones 3D
Operaciones3D Op3D;
Ship myShip(&Op3D);
//Carro micarro(&Op3D);
//Chofer michofer(&Op3D);
//Llantas llanta1(&Op3D); llanta2(&Op3D);


//funciones de control generales
//...
void dibujaCarro(){
    Op3D.push();
    Op3D.translate(5,40,20);

    myShip.draw();
    Op3D.push(); //Carro push
    Op3D.translate(2,3,1);
    //ship.draw(); //Conductor

    Op3D.pop(); //Carro pop
    //Dibujar llanta
    Op3D.push();
    Op3D.translate(-2,-3,-1);

    Op3D.pop();

    Op3D.pop();
}

//-------------------------------------------------------------------------
//funciones callbacks
void idle(void)
{
 }

void reshape(int width, int height)
{
}

static void keys(unsigned char key, int x, int y)
{
    switch(key){

    }
    glutPostRedisplay();
}
//--------------------------------------------------------------------------

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    Op3D.LoadIdentity();

    glColor3f(1.0f,1.0f,1.0f);
    Op3D.push();
    Op3D.translate(-20.0,-20.0,-80.0);
    //Op3D.rotateXYZ(180.0,P1,P2);
    myShip.draw();
    Op3D.pop();
    glutSwapBuffers();
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOVY, (GLfloat)WIDTH/HEIGTH, ZNEAR, ZFAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z);
	//prepara los parametros de ajuste del objeto
    //myShip.setDeltaDegRotation(30.0);
    //myShip.setRotation(TRUE);
    //myShip.setDeltaAxisTranslation(vT);
    //myShip.setTranslation(TRUE);
    //myShip.setAnimation(TRUE);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(WIDTH, HEIGTH);
    glutCreateWindow("Parcial");
    init();
    glutDisplayFunc(display);
    //glutIdleFunc(idle);
    glutKeyboardFunc(keys);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
