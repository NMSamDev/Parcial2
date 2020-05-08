
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

void draw(){
}

void setRotation(bool){
}

void setTranslation(bool){
}

void setRotation(float axis[3], float deg){
}

void setAxisRotation(float axis[3]){
}

void setDeltaAxisRotation(float delta[3]){
}

void setDegRotation(float deg){
}

void setDeltaDegRotation(float delta){
}

void setAxisTranslation(float axis[3]){
}

void setDeltaAxisTranslation(float delta[3]){
}

void setAnimation(bool value){
}
