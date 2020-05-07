
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include "3D_bib.h"
#include "Ship.h"


//Declaracion de variables
//...

//Se declara el objeto para utilizar las operaciones 3D
Operaciones3D Op3D;
Ship myShip(&Op3D);
Carro micarro(&Op3D);
Chofer michofer(&Op3D);
Llantas llanta1(&Op3D); llanta2(&Op3D);
//funciones de control generales
//...
void dibujaCarro(){
    Op3D.push();
    Op3D.translate(5,40,20);

    micarro.draw();
    Op3D.push(); //Carro push
    Op3D.translate(2,3,1);
    michofer.draw();

    Op3D.pop(); //Carro pop
    //Dibujar llanta
    Op3D.push();
    Op3D.translate();

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
    Op3D.rotateXYZ(180.0,P1,P2);
    myShip.draw();
    Op3D.pop();
    glutSwapBuffers();
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(...);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(...);
	//prepara los parametros de ajuste del objeto
    myShip.setDeltaDegRotation(30.0);
    myShip.setRotation(TRUE);
    myShip.setDeltaAxisTranslation(vT);
    myShip.setTranslation(TRUE);
    myShip.setAnimation(TRUE);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(...);
    glutCreateWindow("Ejemplo idea");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(keys);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
