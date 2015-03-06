//
//  Math3DLibrary.h
//  ObjectReader
//
//  Created by Domenic DiPasquale on 12/16/2013.
//  Copyright (c) 2013 Domenic DiPasquale. All rights reserved.
//

#ifndef __ObjectReader__Math3DLibrary__
#define __ObjectReader__Math3DLibrary__

#include <iostream>

// Creates a point class
class point3D{
public:
    float X;
	float Y;
    float Z;
	point3D();
	point3D(float X, float Y, float Z);
};

// Creates a face class
class face3D{
public:
    point3D X;
	point3D Y;
    point3D Z;
    point3D W;
	face3D();
	face3D(point3D X, point3D Y, point3D Z);
    face3D(point3D X, point3D Y, point3D Z, point3D W);
    int FaceSize();
};

// Creates a vector class
class vec3D{
public:
    float X;
	float Y;
    float Z;
    float M;
	vec3D();
	vec3D(float X, float Y, float Z);
	float magnitude3D();
    float length3D();
};

// Creates a colour class
class colour{
public:
    float Red;
    float Green;
	float Blue;
	colour();
	colour(float Red, float Green, float Blue);
};

// Functions that can be used on the point class, vector class and colour class
float distance3D(point3D Point1, point3D Point2);
float fastDistance3D(point3D Point1, point3D Point2);
vec3D vectorMultiply3D(vec3D Vector, float Scalar);
vec3D createVector3D(point3D Point1, point3D Point2);
vec3D addVector3D(vec3D Vector1, vec3D Vector2);
vec3D subVector3D(vec3D Vector1, vec3D Vector2);
vec3D crossProduct3D(vec3D Vector1, vec3D Vector2);
vec3D normalize3D(vec3D Vector1, vec3D Vector2, vec3D Vector3);
point3D movePoint3D(point3D Point, vec3D Vector);


// Creating specific Random Number Generators Functions
float ranNumGenObjects();
float ranNumGenVector();
float ranNumGenColour();
float ranNumGenSpeed();
float ranNumGenRange();
float ranNumGenSize();

// Calculates Initial Time and Difference In Time
clock_t initialTimeGen();
float changeInTimeGen(clock_t initialTime);

float randomNum();

#endif /* defined(__ObjectReader__Math3DLibrary__) */
