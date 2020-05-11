
#include "Ship.h"


 //---------------------------------------------------------------
Ship::Ship(Operaciones3D *data)
 {
     Op3D = data;
     Op3D->LoadIdentity(Op3D->A);
     Op3D->LoadIdentity(myA);


 }

Ship::~Ship()
 {
     Op3D = NULL;
 }


void Ship::updateAnimation()
{

}

void Ship::draw(){
    Matriz temp;
    if(state){
        Op3D->MultM(Op3D->A, myA, temp.M);
        Op3D->MatObject(temp.M,8,points);
    }
    else
        Op3D->MatObject(Op3D->A,8,points);
    //Op3D->MatObject(Op3D->A,8,points);
    int i;
    glBegin(GL_LINES);
      for(i=0;i<8;i++){
        if(i==3 || i==7){
            glVertex3f(points[i][0],points[i][1],points[i][2]);
            glVertex3f(points[i-3][0],points[i-3][1],points[i-3][2]);
        }
        else{
            glVertex3f(points[i][0],points[i][1],points[i][2]);
            glVertex3f(points[i+1][0],points[i+1][1],points[i+1][2]);
        }
        if(i<4){
            glVertex3f(points[i][0],points[i][1],points[i][2]);
            glVertex3f(points[i+4][0],points[i+4][1],points[i+4][2]);
        }
    }
    glEnd();

}

void Ship::setRotation(bool a){
    edo_rotate=a;
}

void Ship::setTranslation(bool a){
    edo_translate=a;
}

void Ship::setRotation(float axis[3], float deg){
    setAxisRotation(axis);
    setDegRotation(deg);
}

void Ship::setAxisRotation(float axis[3]){
    for(int i;i<3;i++)
        axis_rotation[i]=axis[i];
}

void Ship::setDeltaAxisRotation(float delta[3]){
    for(int i;i<3;i++)
        delta_axis_rotation[i]=delta[i];
}

void Ship::setDegRotation(float deg){
    deg_rotation=deg;
}

void Ship::setDeltaDegRotation(float delta){
    delta_deg_rotation=delta;
}

void Ship::setAxisTranslation(float axis[3]){
    for(int i;i<3;i++)
        axis_translation[i]=axis[i];
}

void Ship::setDeltaAxisTranslation(float delta[3]){
    for(int i;i<3;i++)
        delta_axis_translation[i]=delta[i];
}

void Ship::setAnimation(bool value){
    state = value;
}

void Ship::RotacionLibre(){
    setDegRotation(-10);
    Op3D->LoadIdentity(Op3D->R);
    float tmp[4][4];
    float V = sqrt(pow((delta_axis_rotation[0]-axis_rotation[0]),2) + pow((delta_axis_rotation[1]-axis_rotation[1]),2) + pow((delta_axis_rotation[2]-axis_rotation[2]),2));
    float a = (delta_axis_rotation[0]-axis_rotation[0]) / V;
    float b = (delta_axis_rotation[1]-axis_rotation[1]) / V;
    float c = (delta_axis_rotation[2]-axis_rotation[2]) / V;
    float d = sqrt(pow(b,2) + pow(c,2));
    if(d!=0){
        Op3D->translate(-axis_rotation[0],-axis_rotation[1],-axis_rotation[2]);
        Op3D->rotateX(-1*(b/d),(c/d));
        Op3D->MultM(Op3D->T,Op3D->R,myA);
        Op3D->rotateY(-1*a,d);
        Op3D->MultM(myA,Op3D->R,myA);
        Op3D->rotateZ(Op3D->DegToRad(deg_rotation));
        Op3D->MultM(myA,Op3D->R,myA);
        Op3D->rotateY(1*a,d);
        Op3D->MultM(myA,Op3D->R,myA);
        Op3D->rotateX(1*(b/d),(c/d));
        Op3D->MultM(myA,Op3D->R,myA);
        Op3D->translate(axis_rotation[0],axis_rotation[1],axis_rotation[2]);
        Op3D->MultM(myA,Op3D->T,myA);
    }
    else{
        Op3D->translate(-axis_rotation[0],-axis_rotation[1],-axis_rotation[2]);
        //se actualiza la matriz de rotacion con el angulo especificado
        Op3D->rotateX(Op3D->DegToRad(deg_rotation));
        //se multiplica la matriz de rotacion por la de traslacion actual
        //el resultado queda en la matriz A
        Op3D->MultM(Op3D->R,Op3D->T,myA);
        //se agrega la matriz de traslacion inversa a A
        Op3D->translate(axis_rotation[0],axis_rotation[1],axis_rotation[2]);
        //se multiplica la matriz de traslacion por la matriz A y se deja el resultado en A
        Op3D->MultM(Op3D->T,myA,myA);
    }
    Op3D->imprimeMatriz(myA);
    //Op3D-> rotateY(Op3D->DegToRad(deg_rotation));
    //Op3D->MultM(Op3D->R,myA,myA);
}
