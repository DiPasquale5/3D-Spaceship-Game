//
//  ObjectLoader.cpp
//  ObjectReader
//
//  Created by Domenic DiPasquale on 12/16/2013.
//  Copyright (c) 2013 Domenic DiPasquale. All rights reserved.
//

#include "ObjectLoader.h"
#include "MaterialChanger.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;
string currentLine;

int TextFileIndex = 0;
int ObjectCounter = 0;

int NumCounter;
string Num1;
string Num2;
string Num3;
string Num4;

point3D Point1;
point3D Point2;
point3D Point3;
point3D Point4;

string ConvertFloatToString(float Number){
    ostringstream NewString;
    NewString << Number;
    return NewString.str();
}

float ConvertStringToFloat(string Word){
    float NewFloat;
    istringstream(Word) >> NewFloat;
    return NewFloat;
}

void ParseObjectFile(string CurrentLine){
    string delimiter = " ";
    size_t pos = 0;
    string token;
    NumCounter = 0;
    Num1 = " ";
    Num2 = " ";
    Num3 = " ";
    Num4 = " ";
    while ((pos = CurrentLine.find(delimiter)) != string::npos) {
        token = CurrentLine.substr(0, pos);
        if (NumCounter == 1){
            Num1 = token;
        }
        if (NumCounter == 2){
            Num2 = token;
        }
        if (NumCounter == 3){
            Num3 = token;
        }
        if (NumCounter == 4){
            Num4 = token;
        }
        CurrentLine.erase(0, pos + delimiter.length());
        NumCounter++;
    }
    if (NumCounter == 3){
        Num3 = CurrentLine;
    }
    if (NumCounter == 4){
        Num4 = CurrentLine;
    }
}

object LoadObjects(string ObjectFileName) {
    object nextObject;
    ObjectCounter = 0;
    TextFileIndex = 0;
    string nextLine;
    fstream ObjectFile;
    ObjectFile.open(ObjectFileName);
    
    if (ObjectFile.is_open()){
        while(getline(ObjectFile, nextLine)){
            string currentLine = nextLine;
            ParseObjectFile(currentLine);
            if (currentLine[0] == 'v'){
                point3D nextPoint = point3D(ConvertStringToFloat(Num1), ConvertStringToFloat(Num2), ConvertStringToFloat(Num3));
                nextObject.addPoint(nextPoint);
            }
        }
    } else {
        cout << "Unable to open file";
    }
    ObjectFile.close();
    ObjectFile.open(ObjectFileName);
    
    if (ObjectFile.is_open()){
        while(getline(ObjectFile, nextLine)){
            Point1 = point3D();
            Point2 = point3D();
            Point3 = point3D();
            Point4 = point3D();
            string currentLine = nextLine;
            ParseObjectFile(currentLine);
            if (currentLine[0] == 'f'){
                if (Num4 == " "){
                    Point1 = nextObject.PointList[ConvertStringToFloat(Num1)-1];
                    Point2 = nextObject.PointList[ConvertStringToFloat(Num2)-1];
                    Point3 = nextObject.PointList[ConvertStringToFloat(Num3)-1];
                    nextObject.addFace(Point1, Point2, Point3);
                } else {
                    Point1 = nextObject.PointList[ConvertStringToFloat(Num1)-1];
                    Point2 = nextObject.PointList[ConvertStringToFloat(Num2)-1];
                    Point3 = nextObject.PointList[ConvertStringToFloat(Num3)-1];
                    Point4 = nextObject.PointList[ConvertStringToFloat(Num4)-1];
                    nextObject.addFace(Point1, Point2, Point3, Point4);
                }
            }
        }
    } else {
        cout << "Unable to open file";
    }
    ObjectFile.close();
    nextObject = ChangeMaterial(nextObject, ObjectFileName);
    return nextObject;
}