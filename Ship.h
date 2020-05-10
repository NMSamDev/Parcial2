#ifndef SHIP
#define SHIP


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>
#include "iostream"

#include "3D_bib.h"

using namespace std;


class Ship{
private:
	//Aquí van todas las variables y funciones de control del
	//Objeto
    float points[8][3]={{-2,-2,2},{2,-2,2},{2,-2,-2},{-2,-2,-2},{-2,2,2},{2,2,2},{2,2,-2},{-2,2,-2}};
//    Punto hojas[][]={3,4,3,4,1,3,1};
	//...

    //matriz de control local del objeto
    float myA[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
	//variables de control local del objeto
    bool edo_rotate, edo_translate,state;
    float axis_rotation[3] = {0.0,0.0,1.0};
    float delta_axis_rotation[3] = {0.0,0.0,0.0};
    float deg_rotation = 0.0;
    float delta_deg_rotation = 0.0;
    float axis_translation[3] = {0,0,0};
    float delta_axis_translation[3] = {0.0,0.0,0.0};
	//...

    //control-state variable
    Operaciones3D *Op3D;

    //funciones de la clase
    void squeleton_reset(); //para reiniciar valores por default del objeto
    void updateAnimation(); //para actualizar cuadro por cuadro el edo del objeto
public:
    //funciones publicas de la clase
	//...

    //general functions
    Ship(Operaciones3D *);
    ~Ship();
    void draw();
    void setRotation(bool);
    void setTranslation(bool);
    void setRotation(float axis[3], float deg);
    void setAxisRotation(float axis[3]);
    void setDeltaAxisRotation(float delta[3]);
    void setDegRotation(float deg);
    void setDeltaDegRotation(float delta);
    void setAxisTranslation(float axis[3]);
    void setDeltaAxisTranslation(float delta[3]);
    void setAnimation(bool value);
};

#endif
