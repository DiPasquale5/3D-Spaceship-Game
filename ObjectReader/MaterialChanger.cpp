//
//  MaterialChanger.cpp
//  ObjectReader
//
//  Created by Domenic DiPasquale on 12/17/2013.
//  Copyright (c) 2013 Domenic DiPasquale. All rights reserved.
//

#include "MaterialChanger.h"
#include "Object.h"
#include <stdlib.h>

using namespace std;

//#2 - Obsidian
float UserShipMaterialAmbient[4] = {0.05375, 0.05, 0.06625, 1.0};
float UserShipMaterialDiffuse[4] = {0.18275, 0.17, 0.22525, 1.0};
float UserShipMaterialSpecular[4] = {0.332741,0.328634,0.346435,1.0};
float UserShipMaterialShininess = 38.4;

//#9 - Copper
float UserShipWindowMaterialAmbient[4] = {0.19125, 0.0735, 0.0225, 1.0};
float UserShipWindowMaterialDiffuse[4] = {0.7038, 0.27048, 0.0828, 1.0};
float UserShipWindowMaterialSpecular[4] = {0.256777, 0.137622, 0.086014,1.0};
float UserShipWindowMaterialShininess = 12.8;

//#0 - Emerald
float UserBulletMaterialAmbient[4] = {0.0215, 0.1745, 0.0215, 1.0};
float UserBulletMaterialDiffuse[4] = {0.07568, 0.61424, 0.07568, 1.0};
float UserBulletMaterialSpecular[4] = {0.633, 0.727811, 0.633, 1.0};
float UserBulletMaterialShininess = 76.8;

//#16 - Pastic (White)
float EnemyShipMaterialAmbient[4] = {0.0,   0.0,     0.0,  1.0};
float EnemyShipMaterialDiffuse[4] = {0.55,  0.55,    0.55, 1.0};
float EnemyShipMaterialSpecular[4] = {0.70,  0.70,    0.70, 1.0};
float EnemyShipMaterialShininess = 32;

////#8 - Chrome
//float EnemyShipMaterialAmbient[4] = {0.25, 0.25, 0.25, 1.0};
//float EnemyShipMaterialDiffuse[4] = {0.4, 0.4, 0.4, 1.0};
//float EnemyShipMaterialSpecular[4] = {0.774597,0.774597, 0.774597, 1.0};
//float EnemyShipMaterialShininess = 76.8;

//#19 - Rubber (Cyan)
float EnemyShipWindowMaterialAmbient[4] = {0.0, 0.05, 0.05, 1.0};
float EnemyShipWindowMaterialDiffuse[4] = {0.4, 0.5, 0.5, 1.0};
float EnemyShipWindowMaterialSpecular[4] = {0.04, 0.7, 0.7, 1.0};
float EnemyShipWindowMaterialShininess = 10.0;

////#13 - Plastic (Cyan)
//float EnemyShipWindowMaterialAmbient[4] = {0.0, 0.1, 0.06, 1.0};
//float EnemyShipWindowMaterialDiffuse[4] = {0.0, 0.50980392, 0.50980392, 1.0};
//float EnemyShipWindowMaterialSpecular[4] = {0.50196078, 0.50196078, 0.50196078, 1.0};
//float EnemyShipWindowMaterialShininess = 32;

//#4 - Ruby
float EnemyBulletMaterialAmbient[4] = {0.1745,   0.01175,  0.01175,   1.0};
float EnemyBulletMaterialDiffuse[4] = {0.61424,  0.04136,  0.04136,   1.0};
float EnemyBulletMaterialSpecular[4] = {0.727811, 0.626959, 0.626959,  1.0};
float EnemyBulletMaterialShininess = 76.8;

////#4 - Ruby
//float AsteroidMaterialAmbient[4] = {0.1745,   0.01175,  0.01175,   1.0};
//float AsteroidMaterialDiffuse[4] = {0.61424,  0.04136,  0.04136,   1.0};
//float AsteroidMaterialSpecular[4] = {0.727811, 0.626959, 0.626959,  1.0};
//float AsteroidMaterialShininess = 76.8;

object ChangeMaterial(object CurrentObject, string ObjectFileName){
    if (ObjectFileName == "UserShip.obj"){
        CurrentObject.ambient[0] = UserShipMaterialAmbient[0];
        CurrentObject.ambient[1] = UserShipMaterialAmbient[1];
        CurrentObject.ambient[2] = UserShipMaterialAmbient[2];
        CurrentObject.ambient[3] = UserShipMaterialAmbient[3];
        
        CurrentObject.diffuse[0] = UserShipMaterialDiffuse[0];
        CurrentObject.diffuse[1] = UserShipMaterialDiffuse[1];
        CurrentObject.diffuse[2] = UserShipMaterialDiffuse[2];
        CurrentObject.diffuse[3] = UserShipMaterialDiffuse[3];
        
        CurrentObject.specular[0] = UserShipMaterialSpecular[0];
        CurrentObject.specular[1] = UserShipMaterialSpecular[1];
        CurrentObject.specular[2] = UserShipMaterialSpecular[2];
        CurrentObject.specular[3] = UserShipMaterialSpecular[3];
        
        CurrentObject.shininess = UserShipMaterialShininess;
    }
    if (ObjectFileName == "UserShipWindow.obj"){
        CurrentObject.ambient[0] = UserShipWindowMaterialAmbient[0];
        CurrentObject.ambient[1] = UserShipWindowMaterialAmbient[1];
        CurrentObject.ambient[2] = UserShipWindowMaterialAmbient[2];
        CurrentObject.ambient[3] = UserShipWindowMaterialAmbient[3];
        
        CurrentObject.diffuse[0] = UserShipWindowMaterialDiffuse[0];
        CurrentObject.diffuse[1] = UserShipWindowMaterialDiffuse[1];
        CurrentObject.diffuse[2] = UserShipWindowMaterialDiffuse[2];
        CurrentObject.diffuse[3] = UserShipWindowMaterialDiffuse[3];
        
        CurrentObject.specular[0] = UserShipWindowMaterialSpecular[0];
        CurrentObject.specular[1] = UserShipWindowMaterialSpecular[1];
        CurrentObject.specular[2] = UserShipWindowMaterialSpecular[2];
        CurrentObject.specular[3] = UserShipWindowMaterialSpecular[3];
        
        CurrentObject.shininess = UserShipWindowMaterialShininess;
    }
    if (ObjectFileName == "UserBullet.obj"){
        CurrentObject.ambient[0] = UserBulletMaterialAmbient[0];
        CurrentObject.ambient[1] = UserBulletMaterialAmbient[1];
        CurrentObject.ambient[2] = UserBulletMaterialAmbient[2];
        CurrentObject.ambient[3] = UserBulletMaterialAmbient[3];
        
        CurrentObject.diffuse[0] = UserBulletMaterialDiffuse[0];
        CurrentObject.diffuse[1] = UserBulletMaterialDiffuse[1];
        CurrentObject.diffuse[2] = UserBulletMaterialDiffuse[2];
        CurrentObject.diffuse[3] = UserBulletMaterialDiffuse[3];
        
        CurrentObject.specular[0] = UserBulletMaterialSpecular[0];
        CurrentObject.specular[1] = UserBulletMaterialSpecular[1];
        CurrentObject.specular[2] = UserBulletMaterialSpecular[2];
        CurrentObject.specular[3] = UserBulletMaterialSpecular[3];
        
        CurrentObject.shininess = UserBulletMaterialShininess;
    }
    if (ObjectFileName == "EnemyShip.obj"){
        CurrentObject.ambient[0] = EnemyShipMaterialAmbient[0];
        CurrentObject.ambient[1] = EnemyShipMaterialAmbient[1];
        CurrentObject.ambient[2] = EnemyShipMaterialAmbient[2];
        CurrentObject.ambient[3] = EnemyShipMaterialAmbient[3];
        
        CurrentObject.diffuse[0] = EnemyShipMaterialDiffuse[0];
        CurrentObject.diffuse[1] = EnemyShipMaterialDiffuse[1];
        CurrentObject.diffuse[2] = EnemyShipMaterialDiffuse[2];
        CurrentObject.diffuse[3] = EnemyShipMaterialDiffuse[3];
        
        CurrentObject.specular[0] = EnemyShipMaterialSpecular[0];
        CurrentObject.specular[1] = EnemyShipMaterialSpecular[1];
        CurrentObject.specular[2] = EnemyShipMaterialSpecular[2];
        CurrentObject.specular[3] = EnemyShipMaterialSpecular[3];
        
        CurrentObject.shininess = EnemyShipMaterialShininess;
    }
    if (ObjectFileName == "EnemyShipWindow.obj"){
        CurrentObject.ambient[0] = EnemyShipWindowMaterialAmbient[0];
        CurrentObject.ambient[1] = EnemyShipWindowMaterialAmbient[1];
        CurrentObject.ambient[2] = EnemyShipWindowMaterialAmbient[2];
        CurrentObject.ambient[3] = EnemyShipWindowMaterialAmbient[3];
        
        CurrentObject.diffuse[0] = EnemyShipWindowMaterialDiffuse[0];
        CurrentObject.diffuse[1] = EnemyShipWindowMaterialDiffuse[1];
        CurrentObject.diffuse[2] = EnemyShipWindowMaterialDiffuse[2];
        CurrentObject.diffuse[3] = EnemyShipWindowMaterialDiffuse[3];
        
        CurrentObject.specular[0] = EnemyShipWindowMaterialSpecular[0];
        CurrentObject.specular[1] = EnemyShipWindowMaterialSpecular[1];
        CurrentObject.specular[2] = EnemyShipWindowMaterialSpecular[2];
        CurrentObject.specular[3] = EnemyShipWindowMaterialSpecular[3];
        
        CurrentObject.shininess = EnemyShipWindowMaterialShininess;
    }
    if (ObjectFileName == "EnemyBullet.obj"){
        CurrentObject.ambient[0] = EnemyBulletMaterialAmbient[0];
        CurrentObject.ambient[1] = EnemyBulletMaterialAmbient[1];
        CurrentObject.ambient[2] = EnemyBulletMaterialAmbient[2];
        CurrentObject.ambient[3] = EnemyBulletMaterialAmbient[3];
        
        CurrentObject.diffuse[0] = EnemyBulletMaterialDiffuse[0];
        CurrentObject.diffuse[1] = EnemyBulletMaterialDiffuse[1];
        CurrentObject.diffuse[2] = EnemyBulletMaterialDiffuse[2];
        CurrentObject.diffuse[3] = EnemyBulletMaterialDiffuse[3];
        
        CurrentObject.specular[0] = EnemyBulletMaterialSpecular[0];
        CurrentObject.specular[1] = EnemyBulletMaterialSpecular[1];
        CurrentObject.specular[2] = EnemyBulletMaterialSpecular[2];
        CurrentObject.specular[3] = EnemyBulletMaterialSpecular[3];
        
        CurrentObject.shininess = EnemyBulletMaterialShininess;
    }
    if (ObjectFileName == "Asteroid.obj"){
        CurrentObject.ambient[0] = UserShipMaterialAmbient[0];
        CurrentObject.ambient[1] = UserShipMaterialAmbient[1];
        CurrentObject.ambient[2] = UserShipMaterialAmbient[2];
        CurrentObject.ambient[3] = UserShipMaterialAmbient[3];
        
        CurrentObject.diffuse[0] = UserShipMaterialDiffuse[0];
        CurrentObject.diffuse[1] = UserShipMaterialDiffuse[1];
        CurrentObject.diffuse[2] = UserShipMaterialDiffuse[2];
        CurrentObject.diffuse[3] = UserShipMaterialDiffuse[3];
        
        CurrentObject.specular[0] = UserShipMaterialSpecular[0];
        CurrentObject.specular[1] = UserShipMaterialSpecular[1];
        CurrentObject.specular[2] = UserShipMaterialSpecular[2];
        CurrentObject.specular[3] = UserShipMaterialSpecular[3];
        
        CurrentObject.shininess = UserShipMaterialShininess;
    }
    
    return CurrentObject;
}