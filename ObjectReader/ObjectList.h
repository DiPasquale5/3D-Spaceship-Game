//
//  ObjectList.h
//  ObjectReader
//
//  Created by Domenic DiPasquale on 12/18/2013.
//  Copyright (c) 2013 Domenic DiPasquale. All rights reserved.
//

#ifndef __ObjectReader__ObjectList__
#define __ObjectReader__ObjectList__

#include <iostream>
#include <vector>
#include <stdlib.h>

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include "Math3DLibrary.h"
#include "ObjectLoader.h"
#include "Object.h"

using namespace std;

// Functions that can be used on the list of particles

void InitializeShipList();
int getObjectListSize();
void updateObjects();
void moveShip(string Direction);
void shootBullet();

#endif /* defined(__ObjectReader__ObjectList__) */


