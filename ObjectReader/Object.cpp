//
//  Object.cpp
//  ObjectReader
//
//  Created by Domenic DiPasquale on 12/16/2013.
//  Copyright (c) 2013 Domenic DiPasquale. All rights reserved.
//

#include "Object.h"
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

int FaceListCounter;
int PointCounter;
float point[4][3] = {{0,0,0},{0,0,0},{0,0,0},{0,0,0}};

float defaultAmbient[4] = {0.33, 0.22, 0.03, 1.0};
float defaultDiffuse[4] = {0.78, 0.57, 0.11, 1.0};
float defaultSpecular[4] = {0.99, 0.91, 0.81, 1.0};
float defaultShininess = 27;

object::object(){
    
    object::Translate = point3D(0.0, 0.0, 0.0);
    object::Scale = point3D(1.0, 1.0, 1.0);
    object::Rotate = point3D(1.0, 1.0, 1.0);
    object::Vector = vec3D(0.0, 0.0, 0.0);
};

void object::addPoint(point3D nextPoint){
    PointList.emplace_back(nextPoint);
}

void object::addFace(point3D X, point3D Y, point3D Z){
    face3D nextFace;
    nextFace.X = X;
    nextFace.Y = Y;
    nextFace.Z = Z;
    nextFace.W = point3D();
    NormalList.emplace_back(normalize3D(vec3D(X.X,X.Y,X.Z), vec3D(Y.X,Y.Y,Y.Z), vec3D(Z.X,Z.Y,Z.Z)));
    FaceList.emplace_back(nextFace);
}

void object::addFace(point3D X, point3D Y, point3D Z, point3D W){
    face3D nextFace;
    nextFace.X = X;
    nextFace.Y = Y;
    nextFace.Z = Z;
    nextFace.W = W;
    NormalList.emplace_back(normalize3D(vec3D(X.X,X.Y,X.Z), vec3D(Y.X,Y.Y,Y.Z), vec3D(Z.X,Z.Y,Z.Z)));
    FaceList.emplace_back(nextFace);
}

void object::drawFace(vector<face3D> FaceList, int FaceListCounter){
    PointCounter=0;

    for (PointCounter; PointCounter < object::FaceList[FaceListCounter].FaceSize(); PointCounter++) {
    
        if (PointCounter == 0){
            point[PointCounter][0] = FaceList[FaceListCounter].X.X;
            point[PointCounter][1] = FaceList[FaceListCounter].X.Y;
            point[PointCounter][2] = FaceList[FaceListCounter].X.Z;
        }
        if (PointCounter == 1){
            point[PointCounter][0] = FaceList[FaceListCounter].Y.X;
            point[PointCounter][1] = FaceList[FaceListCounter].Y.Y;
            point[PointCounter][2] = FaceList[FaceListCounter].Y.Z;
        }
        if (PointCounter == 2){
            point[PointCounter][0] = FaceList[FaceListCounter].Z.X;
            point[PointCounter][1] = FaceList[FaceListCounter].Z.Y;
            point[PointCounter][2] = FaceList[FaceListCounter].Z.Z;
        }
        if (PointCounter == 3){
            point[PointCounter][0] = FaceList[FaceListCounter].W.X;
            point[PointCounter][1] = FaceList[FaceListCounter].W.Y;
            point[PointCounter][2] = FaceList[FaceListCounter].W.Z;
        }
    }
    
    if (object::FaceList[FaceListCounter].FaceSize() == 3){
        glBegin(GL_POLYGON);
        glNormal3f(NormalList[FaceListCounter].X, NormalList[FaceListCounter].Y, NormalList[FaceListCounter].Z);
        glVertex3fv(point[0]);
        glNormal3f(NormalList[FaceListCounter].X, NormalList[FaceListCounter].Y, NormalList[FaceListCounter].Z);
        glVertex3fv(point[1]);
        glNormal3f(NormalList[FaceListCounter].X, NormalList[FaceListCounter].Y, NormalList[FaceListCounter].Z);
        glVertex3fv(point[2]);
        glEnd();
    } else {
        glBegin(GL_POLYGON);
        glNormal3f(NormalList[FaceListCounter].X, NormalList[FaceListCounter].Y, NormalList[FaceListCounter].Z);
        glVertex3fv(point[0]);
        glNormal3f(NormalList[FaceListCounter].X, NormalList[FaceListCounter].Y, NormalList[FaceListCounter].Z);
        glVertex3fv(point[1]);
        glNormal3f(NormalList[FaceListCounter].X, NormalList[FaceListCounter].Y, NormalList[FaceListCounter].Z);
        glVertex3fv(point[2]);
        glNormal3f(NormalList[FaceListCounter].X, NormalList[FaceListCounter].Y, NormalList[FaceListCounter].Z);
        glVertex3fv(point[3]);
        glEnd();
    }
}

void object::drawObject(){
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, object::ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, object::diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, object::specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, object::shininess);
    
    object::Translate.X = object::Translate.X + object::Vector.X;
    object::Translate.Y = object::Translate.Y + object::Vector.Y;
    object::Translate.Z = object::Translate.Z + object::Vector.Z;
    
    glTranslatef(object::Translate.X, object::Translate.Y, object::Translate.Z);
    glScalef(object::Scale.X, object::Scale.Y, object::Scale.Z);
    glRotatef(object::Rotate.X, 1, 0, 0);
    glRotatef(object::Rotate.Y, 0, 1, 0);
    glRotatef(object::Rotate.Z, 0, 0, 1);
    
    FaceListCounter=0;
    for (FaceListCounter; FaceListCounter < object::FaceList.size(); FaceListCounter++) {
        drawFace(object::FaceList, FaceListCounter);
    }
}
