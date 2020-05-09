
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

#include "3D_bib.h"
#include "Ship.h"
#include <stack>
#include <time.h>
unsigned int sleep(unsigned int seconds);


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
//Operaciones3D Op3D;
float Theta  = 0;
float ThetaX = 0;
float ThetaY = 0;
float ThetaZ = 0;
//Matriz e0;
//Ship myShip(&Op3D);
//Carro micarro(&Op3D);
//Chofer michofer(&Op3D);
//Llantas llanta1(&Op3D); llanta2(&Op3D);


//funciones de control generales


void dibujaCarro(){
    //Op3D.mystack.push(&Op3D.A1);
//    Op3D.translate(5,40,20);

//    myShip.draw();
    //Op3D.mystack.push(&Op3D.A1); //Carro push
    //Op3D.translate(2,3,1);

    //ship.draw(); //Conductor

    //Op3D.mystack.pop(); //Carro pop

    //Dibujar llanta
    //Op3D.mystack.push();
    //Op3D.translate(-2,-3,-1);

    //Op3D.mystack.pop();

    //Op3D.mystack.pop(&Op3D.A1);
}

//-------------------------------------------------------------------------
//funciones callbacks
void idle(void)
{
    glutPostRedisplay();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}

static void keys(unsigned char key, int x, int y)
{
    switch(key){
                case 'd':
                     Theta = 0;
                     ThetaX = 1;
                     ThetaY = 0;
                     ThetaZ = 0;
                     break;
                case 'a':
                     Theta = 0;
                     ThetaX =-1;
                     ThetaY = 0;
                     ThetaZ = 0;
                     break;
                default:
                     Theta = 0;
                     ThetaX = 0;
                     ThetaY = 0;
                     ThetaZ = 0;
                     break;
    }
    glutPostRedisplay();
}


void drawAxis()
{
     glShadeModel(GL_SMOOTH);
     glLineWidth(3.0);
     //X axis in red
     glBegin(GL_LINES);
       glColor3f(1.0f,0.0f,0.0f);
       glVertex3f(X_MIN,0.0,0.0);
       glColor3f(0.5f,0.0f,0.0f);
       glVertex3f(X_MAX,0.0,0.0);
     glEnd();
     //Y axis in green
     glColor3f(0.0f,1.0f,0.0f);
     glBegin(GL_LINES);
       glColor3f(0.0f,1.0f,0.0f);
       glVertex3f(0.0,Y_MIN,0.0);
       glColor3f(0.0f,0.5f,0.0f);
       glVertex3f(0.0,Y_MAX,0.0);
     glEnd();
     //Z axis in blue
     glBegin(GL_LINES);
       glColor3f(0.0f,0.0f,1.0f);
       glVertex3f(0.0,0.0,Z_MIN);
       glColor3f(0.0f,0.0f,0.5f);
       glVertex3f(0.0,0.0,Z_MAX);
     glEnd();
     glLineWidth(1.0);
 }

//--------------------------------------------------------------------------

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //Op3D.LoadIdentity();
    drawAxis();
    glColor3f(1.0f,1.0f,1.0f);
    //dibujaCarro();
    //Op3D.push();
    //Op3D.translate(-20.0,-20.0,-80.0);
    //Op3D.rotateXYZ(180.0,P1,P2);
    //myShip.draw();
    //Op3D.pop();
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
    glClearColor(0,0,0,0);

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
    glutCreateWindow("Parcial 2");
    init();
    glutDisplayFunc(display);
    //glutIdleFunc(idle);
    glutKeyboardFunc(keys);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
