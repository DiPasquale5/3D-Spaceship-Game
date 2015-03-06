//
//  Particle.h
//  ObjectReader
//
//  Created by Domenic DiPasquale on 12/18/2013.
//  Copyright (c) 2013 Domenic DiPasquale. All rights reserved.
//

#ifndef __ObjectReader__Particle__
#define __ObjectReader__Particle__

#include <iostream>

class Particle {
	typedef struct _Vector{
		double x,y,z;
    } Vector;
	//All of this declares the attributes the particles are going to have
protected:
	Vector pos, vel, acc;
	float age;
	float alpha;
	float colour[3];
	float size;
public:
	Particle();
	~Particle();
    void Update(double time);
    void Render(float X, float Y);
    Particle(double _posX, double _posY, double _posZ, double _velX, double _velY, double _velZ, float colR, float colG, float colB, float colA);
    void wind(bool set);
};

#endif /* defined(__ObjectReader__Particle__) */
