//
//  Object.h
//  ObjectReader
//
//  Created by Domenic DiPasquale on 12/16/2013.
//  Copyright (c) 2013 Domenic DiPasquale. All rights reserved.
//

#ifndef __ObjectReader__Object__
#define __ObjectReader__Object__

#include <iostream>
#include <vector>
#include <stdlib.h>

#include "Math3DLibrary.h"

using namespace std;


class object{
public:
    object();

    point3D Translate;
    point3D Rotate;
    point3D Scale;
    vec3D Vector;
    
    vector<point3D> PointList;
    vector<face3D> FaceList;
    
    void addPoint(point3D nextPoint);
    void addFace(point3D X, point3D Y, point3D Z);
    void addFace(point3D X, point3D Y, point3D Z, point3D W);
    
    vector<vec3D> NormalList;
    
    void drawFace(vector<face3D> FaceList, int FaceListCounter);
    void drawObject();
    
    void setObjectTranslate(float X, float Y, float Z);
    void setObjectScale(float X, float Y, float Z);
    void setObjectRotate(float X, float Y, float Z);
    
    void ChangeMaterial(int MaterialNumber);
    void ReInitializeMaterial();
	float ambient[4];
	float diffuse[4];
	float specular[4];
	float shininess;
    
};

#endif /* defined(__ObjectReader__Object__) */
