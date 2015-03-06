//
//  ObjectLoader.h
//  ObjectReader
//
//  Created by Domenic DiPasquale on 12/16/2013.
//  Copyright (c) 2013 Domenic DiPasquale. All rights reserved.
//

#ifndef __ObjectReader__ObjectLoader__
#define __ObjectReader__ObjectLoader__

#include <iostream>
#include <vector>
#include <stdlib.h>

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#include "Math3DLibrary.h"
#include "Object.h"

using namespace std;

string ConvertFloatToString(float Number);
float ConvertStringToFloat(string Word);
void ParseObjectFile(string CurrentLine);
object LoadObjects(string ObjectFileName);

#endif /* defined(__ObjectReader__ObjectLoader__) */
