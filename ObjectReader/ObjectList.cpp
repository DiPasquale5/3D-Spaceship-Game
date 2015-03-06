//
//  ObjectList.cpp
//  ObjectReader
//
//  Created by Domenic DiPasquale on 12/18/2013.
//  Copyright (c) 2013 Domenic DiPasquale. All rights reserved.
//

#include <list>

#include "Particle.h"
#include "ObjectList.h"
#include "Object.h"
#include "Math3DLibrary.h"

using namespace std;
vector<object> ShipList;
vector<object> AsteroidList;

int InitializerCounter = 0;
int ShipListCounter = 0;

//Creates the initial variables and objects
void InitializeShipList(){
    object UserShip = LoadObjects("UserShip.obj");
    object UserShipWindow = LoadObjects("UserShipWindow.obj");

//    object Asteroid1 = LoadObjects("Asteroid.obj");

    ShipList.emplace_back(UserShip);
    ShipList.emplace_back(UserShipWindow);
//    ObjectList.emplace_back(Asteroid1);
}

// Updates the Objects location and colour in the window
void updateObjects(){
    ShipListCounter = 0;
    glClear(GL_COLOR_BUFFER_BIT);
    if (InitializerCounter == 0){
        InitializeShipList();
        InitializerCounter++;
    }
    for (ShipListCounter; ShipListCounter < ShipList.size(); ShipListCounter++) {
        
        glPushMatrix();
        
        ShipList[ShipListCounter].drawObject();
        
        glPopMatrix();
    }
}

void moveShip(string Direction){
    if (Direction == "up"){
        
        ShipList[0].Vector.Y = ShipList[0].Vector.Y + 0.1;
        ShipList[1].Vector.Y = ShipList[1].Vector.Y + 0.1;
    }
    if (Direction == "down"){
        ShipList[0].Vector.Y = ShipList[0].Vector.Y - 0.1;
        ShipList[1].Vector.Y = ShipList[1].Vector.Y - 0.1;
    }
    if (Direction == "left"){
        ShipList[0].Vector.Z = ShipList[0].Vector.Z - 0.1;
        ShipList[1].Vector.Z = ShipList[1].Vector.Z - 0.1;
    }
    if (Direction == "right"){
        ShipList[0].Vector.Z = ShipList[0].Vector.Z + 0.1;
        ShipList[1].Vector.Z = ShipList[1].Vector.Z + 0.1;
    }
}

void shootBullet(){
    object UserBullet = LoadObjects("UserBullet.obj");
    
    UserBullet.Translate.X = ShipList[0].Translate.X;
    UserBullet.Translate.Y = ShipList[0].Translate.Y;
    UserBullet.Translate.Z = ShipList[0].Translate.Z;
    
    UserBullet.Vector.X = 1;
    ShipList.emplace_back(UserBullet);
}
