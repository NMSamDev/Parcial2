
#include "Ship.h"


 //---------------------------------------------------------------
Ship::Ship(Operaciones3D *data)
 {
     Op3D = data;
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
    glBegin(GL_LINE_LOOP);
      for(int i=0;i<4;i++)
        glVertex3f(points[i][0],points[i][1],points[i][2]);
    glEnd();
    glBegin(GL_LINES);
      for(int i=0;i<4;i++){
        glVertex3f(points[4][0],points[4][1],points[4][2]);
        glVertex3f(points[i][0],points[i][1],points[i][2]);
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
