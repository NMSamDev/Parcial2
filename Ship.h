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
    float points[8][3]={{-1,-1,1},{1,-1,1},{1,-1,-1},{-1,-1,-1},{-1,1,1},{1,1,1},{1,1,-1},{-1,1,-1}};

    //matriz de control local del objeto
    float myA[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
	//variables de control local del objeto
    /*
    bool edo_rotate = true;
    bool edo_translate = true;
    bool state=true;
    */
    float axis_rotation[3] = {0.0,0.0,0.0};
    float delta_axis_rotation[3] = {0.0,0.0,0.0};
    float deg_rotation = 0.0;
    float delta_deg_rotation = 0.0;
    float axis_translation[3] = {0,0,0};
    float delta_axis_translation[3] = {0.0,0.0,0.0};

    //control-state variable
    Operaciones3D *Op3D;

    //funciones de la clase
    void squeleton_reset(); //para reiniciar valores por default del objeto
    void updateAnimation(); //para actualizar cuadro por cuadro el edo del objeto
public:
    //float p1[3]={0.0,0.0,0.0};
    //float p2[3]={0.0,5.0,0.0};
    //funciones publicas de la clase
bool edo_rotate = true;
    bool edo_translate = true;
    bool state=true;
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
    void RotacionLibre();
};

#endif
