
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
