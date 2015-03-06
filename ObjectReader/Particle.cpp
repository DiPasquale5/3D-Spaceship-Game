//
//  Particle.cpp
//  ObjectReader
//
//  Created by Domenic DiPasquale on 12/18/2013.
//  Copyright (c) 2013 Domenic DiPasquale. All rights reserved.
//

#include "Particle.h"
#include "Math3DLibrary.h"

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

using namespace std;
//randomizer randy2;

//#4 - Ruby
float ParticleFireMaterialAmbient[4] = {0.1745,   0.01175,  0.01175,   1.0};
float ParticleFireMaterialDiffuse[4] = {0.61424,  0.04136,  0.04136,   1.0};
float ParticleFireMaterialSpecular[4] = {0.727811, 0.626959, 0.626959,  1.0};
float ParticleFireMaterialShininess = 76.8;


Particle::~Particle(){
}

Particle::Particle(double posX, double posY, double posZ, double velX, double velY, double velZ, float colR, float colG, float colB, float colA){
	//Creates the particle with given attributes
	size = 1;
    
	pos.x = posX;
	pos.y = posY;
	pos.z = posZ;
    
	vel.x = velX;
	vel.y = velY;
	vel.z = velZ;
    
	colour[0]=colR;
	colour[1]=colG;
	colour[2]=colB;
    
	alpha = colA;
	age = 0;
    
}

void Particle::Update(double time){
	//Moves the particle based on its given values
	pos.x -= (vel.x * time);
	pos.y += (vel.y * time);
	pos.z += (vel.z * time);
    
	age+=0.003;
    
	
	if (age >= 0.04 || pos.x<=-10 ){
		//resets a particle if it is too old
		pos.x = -1.3; pos.y = -1.77; pos.z = -1.8;
		vel.x = rand()/float(RAND_MAX)*14.f+10.f;
		vel.y = (rand()%10+1)/10.0 - (rand()%10+1)/10.0;
		vel.z = (rand()%10+1)/10.0 - (rand()%10+1)/10.0;
		age = 0;
        
	}
}

void Particle::Render(float X, float Y){
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ParticleFireMaterialAmbient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, ParticleFireMaterialDiffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ParticleFireMaterialSpecular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, ParticleFireMaterialShininess);
	glTranslated(pos.x,pos.y,pos.z);
    glTranslatef(0, Y, X);
	glBegin(GL_POINTS);
    glPointSize(5);
    glVertex3f(0, 0, 0);
	glEnd();
}

