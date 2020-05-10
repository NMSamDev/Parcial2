
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
    //float temp[4][4];
    Matriz temp;
    Op3D->MultM(Op3D->A, myA, temp.M);
    Op3D->MatObject(temp.M,8,points);
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

void Ship::setRotation(bool){

}

void Ship::setTranslation(bool){

}

void Ship::setRotation(float axis[3], float deg){

}

void Ship::setAxisRotation(float axis[3]){

}

void Ship::setDeltaAxisRotation(float delta[3]){
}

void Ship::setDegRotation(float deg){
}

void Ship::setDeltaDegRotation(float delta){
}

void Ship::setAxisTranslation(float axis[3]){
}

void Ship::setDeltaAxisTranslation(float delta[3]){
}

void Ship::setAnimation(bool value){
}
