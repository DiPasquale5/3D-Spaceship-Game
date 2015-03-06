//
//  Math3DLibrary.cpp
//  ObjectReader
//
//  Created by Domenic DiPasquale on 12/16/2013.
//  Copyright (c) 2013 Domenic DiPasquale. All rights reserved.
//

#include "Math3DLibrary.h"

#include <time.h>
#include <math.h>



// Initializes default point object
point3D::point3D(){
	point3D::X = NULL;
	point3D::Y = NULL;
    point3D::Z = NULL;
};

// Initializes point object based on input
point3D::point3D(float X, float Y, float Z){
    point3D::X = X;
    point3D::Y = Y;
    point3D::Z = Z;
    
};

// Initializes default point object
face3D::face3D(){
	face3D::X = point3D();
	face3D::Y = point3D();
    face3D::Z = point3D();
};

// Initializes point object based on input
face3D::face3D(point3D X, point3D Y, point3D Z){
    face3D::X = X;
    face3D::Y = Y;
    face3D::Z = Z;
    face3D::W = point3D();
    
};
// Initializes default point object
face3D::face3D(point3D X, point3D Y, point3D Z, point3D W){
    face3D::X = X;
    face3D::Y = Y;
    face3D::Z = Z;
    face3D::W = W;
};

int face3D::FaceSize(){
    int size;
    if (face3D::W.X == NULL) {
        size = 3;
    } else {
        size = 4;
    }
    return size;
}

// Initializes default vector object
vec3D::vec3D(){
    vec3D::X = 0;
	vec3D::Y = 0;
    vec3D::Z = 0;
};

// Initializes vector object based on input
vec3D::vec3D(float X, float Y, float Z){
	vec3D::X = X;
	vec3D::Y = Y;
    vec3D::Z = Z;
    vec3D::M = magnitude3D();
};

float vec3D::magnitude3D(){
	return sqrt(pow(X,2) + pow(Y,2));
};

// Initializes default colour object
colour::colour(){
	colour::Red = 1;
    colour::Green = 1;
    colour::Blue = 1;
    
};

// Initializes colour object based on input
colour::colour(float Red, float Green, float Blue){
	colour::Red = Red;
    colour::Green = Green;
    colour::Blue = Blue;
};

// Calculates the Distance between two points, returns the float
float distance3D(point3D Point1, point3D Point2){
    return abs(sqrt(pow((Point2.X - Point1.X),2) + pow((Point2.Y - Point1.Y),2) + pow((Point2.Z - Point1.Z),2)));
};

// Calculates the fast Distance between two points, returns the float
float fastDistance3D(point3D Point1, point3D Point2){
    return abs(pow((Point2.X - Point1.X),2) + pow((Point2.Y - Point1.Y),2) + pow((Point2.Z - Point1.Z),2));
};

// Calculates the length of a vector, returns the float
float vec3D::length3D(){
    vec3D::M = sqrt(pow(X,2) + pow(Y,2) + pow(Z,2));
    return M;
};

// Multiplies a vector by a scalar, returnng the resulting vector
vec3D vectorMultiply3D(vec3D Vector, float Scalar){
    return vec3D(Vector.X * Scalar, Vector.Y * Scalar, Vector.Z * Scalar);
};

// Takes two points, returns the vector between them
vec3D createVector3D(point3D Point1, point3D Point2){
    return vec3D(Point2.X - Point1.X,Point2.Y - Point1.Y, Point2.Z - Point1.Z);
};

vec3D addVector3D(vec3D Vector1, vec3D Vector2){
    return vec3D(Vector1.X + Vector2.X, Vector1.Y + Vector2.Y, Vector1.Z + Vector2.Z);
};

vec3D subVector3D(vec3D Vector1, vec3D Vector2){
    return vec3D(Vector1.X - Vector2.X, Vector1.Y - Vector2.Y, Vector1.Z - Vector2.Z);
};

vec3D crossProduct3D(vec3D Vector1, vec3D Vector2){
    return vec3D(Vector1.Y * Vector2.Z - Vector1.Z * Vector2.Y,
                 Vector1.Z * Vector2.X - Vector1.X * Vector2.Z,
                 Vector1.X * Vector2.Y - Vector1.Y * Vector2.X);
}

vec3D normalize3D(vec3D Vector1, vec3D Vector2, vec3D Vector3){
    vec3D temp1 = subVector3D(Vector2, Vector1);
    vec3D temp2 = subVector3D(Vector3, Vector1);
    return crossProduct3D(temp1, temp2);
};

// Moves a point in the direction of a vector and returns a point
point3D movePoint3D(point3D Point, vec3D Vector){
    return point3D(Point.X + Vector.X, Point.Y + Vector.Y, Point.Z + Vector.Z);
};

float num;

// Random Number Generator for the number of objects
float ranNumGenObjects(){
    return num = rand() % 1000 + 1;
};

//Random Number Generator for the point locations
float ranNumGenVector(){
    num = rand() % 100 + 1;
    num = num/10.0 - 5.0;
    return num;
};

// Random Number Generator for the colour
float ranNumGenColour(){
    return num = rand() % 255 + 1;
};

// Random Number Generator for the speed
float ranNumGenSpeed(){
    return num = (rand() % 10) + 1;
};

// Random Number Generator for the range
float ranNumGenRange(){
    return num = rand() % 250 + 50;
};

// Random Number Generator for the size
float ranNumGenSize(){
    return num = rand() % 10 + 1;
};

// Sets Inital Time
clock_t initialTimeGen(){
    return clock();
};

// Calaculates Difference In Time
float changeInTimeGen(clock_t initialTime){
    clock_t timeDifference = clock() - initialTime;
    return ((float) timeDifference)/CLOCKS_PER_SEC;
};

float randomNum(){
	//makes a random number between 0 and 1
	float desired;
	desired = (rand()%10+1)/10.0;
	desired = desired - (rand()%10+1)/10.0;
	return desired;
};
