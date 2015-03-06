//
//  main.cpp
//  ObjectReader
//
//  Created by Domenic DiPasquale on 12/16/2013.
//  Copyright (c) 2013 Domenic DiPasquale. All rights reserved.
//

//
//  main.cpp
//  Assignment3
//
//  Created by Domenic DiPasquale on 11/19/2013.
//  Copyright (c) 2013 Domenic DiPasquale. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdlib.h>

#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <time.h>
#include <Availability.h>


//#include "Tutorial.h"
#include "Particle.h"
#include "ObjectList.h"
#include "MaterialChanger.h"
#include "ObjectLoader.h"
#include "Object.h"
#include "Math3DLibrary.h"

//#if __MAC_OS_X_VERSION_MAX_REQUIRED >= 1090
//#include <GLKit/GLKit.h>
//#define Ortho(a,b,c,d) GLKMatrix4MakeOrtho(a,b,c,d,-1,1)
//#else
#include <OpenGL/glu.h>
#define Ortho(a,b,c,d) gluOrtho2D(a,b,c,d)
//#endif

// Initializing variables and objects
int createCounter = 1;

float GlobalLight0Postion[] = {25,10,25};
float GlobalLight1Postion[] = {-25,10,-25};
float pos[] = {0,1,0};

float cameraPosition[] = {-20, 10, 0};

int numberOfParticles = 8000;
Particle** part;
float updateSpeed = 0.08;

int Y = 2;
int X = 2;

int clickLocationX;
int clickLocationY;
bool leftClick = false;
bool rightClick = false;

string State = "Main";

int globalWindowX = 500;
int globalWindowY = 500;

//#0 - Emerald
float MaterialAmbient[4] = {0.0215, 0.1745, 0.0215, 1.0};
float MaterialDiffuse[4] = {0.07568, 0.61424, 0.07568, 1.0};
float MaterialSpecular[4] = {0.633, 0.727811, 0.633, 1.0};
float MaterialShininess = 76.8;

//char START[] = "START\0";
string START = "START\0";
char SlurmIndustries[] = "Slurm Industries\0";
char StarFox16[] = "Star Fox 16\0";
char GAMEOVER[] = "GAME OVER\0";
char RESTART[] = "RESTART\0";
char QUIT[] = "QUIT\0";
char WINNER[] = "WINNER\0";

void drawStrokeText(char* text, int x, int y, float scale)
{
    glPushMatrix();
    glLoadIdentity();
    
    Ortho(0, globalWindowX, 0, globalWindowY);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_CULL_FACE);
    glClear(GL_DEPTH_BUFFER_BIT);
    
    if (!(strcmp(text, START.c_str()))){
        glBegin(GL_LINE_LOOP);
        glVertex2f(175, 285);
        glVertex2f(175, 235);
        glVertex2f(325, 235);
        glVertex2f(325, 285);
        glEnd();
    } else if (text == "RESTART"){
        glBegin(GL_LINE_LOOP);
        glVertex2f(80, 285);
        glVertex2f(80, 235);
        glVertex2f(230, 235);
        glVertex2f(230, 285);
        glEnd();
    } else if (text == "QUIT"){
        glBegin(GL_LINE_LOOP);
        glVertex2f(270, 285);
        glVertex2f(270, 235);
        glVertex2f(420, 235);
        glVertex2f(420, 285);
        glEnd();
    }

    glTranslatef(x, y, 0);
    glScalef(scale, scale, scale);
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MaterialAmbient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, MaterialDiffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MaterialSpecular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, MaterialShininess);
    
    char* c;  //character iterator (ptr)
    //glDisable(GL_LIGHTING);
    glColor3f(0,1,0);
    for(c = text; *c != '\0'; c++) { //stop when we hit null character
        //glutStrokeCharacter(GLUT_STROKE_ROMAN, *c); //print one char
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    
    
}

void StateMachine(){
    if (State == "Main"){
        
        drawStrokeText((char*)(START.c_str()), globalWindowX/2.0 - 50, globalWindowY/2.0 - 3, 0.25);
        drawStrokeText(StarFox16, globalWindowX/2.0 - 160, globalWindowY/2.0 + 150, 0.4);
        drawStrokeText(SlurmIndustries, globalWindowX/2.0 - 100, globalWindowY/2.0 -200, 0.2);
        
    } else if (State == "InGame"){
        
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(cameraPosition[0], cameraPosition[1], cameraPosition[2], 0,0,0, 0,1,0);
        
        updateObjects();
        for (int i = 0; i < numberOfParticles; i++){
            glPushMatrix();
            part[i]->Render(X, Y);
            glPopMatrix();
        }
        
    } else if (State == "GameOver"){
        
        drawStrokeText(QUIT, globalWindowX/2.0 + 60, globalWindowY/2.0 - 3, 0.25);
        drawStrokeText(RESTART, globalWindowX/2.0 - 160, globalWindowY/2.0 - 3, 0.25);
        drawStrokeText(GAMEOVER, globalWindowX/2.0 - 160, globalWindowY/2.0 + 80, 0.4);
        drawStrokeText(StarFox16, globalWindowX/2.0 - 160, globalWindowY/2.0 + 150, 0.4);
        drawStrokeText(SlurmIndustries, globalWindowX/2.0 - 100, globalWindowY/2.0 -200, 0.2);
        
    } else if (State == "Winner"){
        
        drawStrokeText(QUIT, globalWindowX/2.0 + 60, globalWindowY/2.0 - 3, 0.25);
        drawStrokeText(RESTART, globalWindowX/2.0 - 160, globalWindowY/2.0 - 3, 0.25);
        drawStrokeText(WINNER, globalWindowX/2.0 - 90, globalWindowY/2.0 + 80, 0.4);
        drawStrokeText(StarFox16, globalWindowX/2.0 - 160, globalWindowY/2.0 + 150, 0.4);
        drawStrokeText(SlurmIndustries, globalWindowX/2.0 - 100, globalWindowY/2.0 -200, 0.2);
    }
}

/* display function - GLUT display callback function clears the screen, creates initial list, updates the objects and displays it */
void display(void) {
    
    float origin[] = {0,0,0};
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    StateMachine();
    
	glutSwapBuffers();
}

void update(int value){
	//Updates the location of every particle every interval
    for (int i = 0; i < numberOfParticles; i++){
        part[i]->Update(updateSpeed);
    }
    
    glutPostRedisplay();
    glutTimerFunc(10,update,0);
	
}

/* special keyboard function for moving the camera */
void mySpecialKeys(int key, int x, int y){
    if(key == GLUT_KEY_F1){
        cameraPosition[0]-=0.5;
    }
    if(key == GLUT_KEY_F2){
        cameraPosition[0]+=0.5;
    }
    if(key == GLUT_KEY_F3){
        cameraPosition[1] -= 0.5;
    }
    if(key == GLUT_KEY_F4){
        cameraPosition[1] += 0.5;
    }
    if(key == GLUT_KEY_F5){
        cameraPosition[2] -= 0.5;
    }
    if(key == GLUT_KEY_F6){
        cameraPosition[2] += 0.5;
    }
}

/* keyboard function for adding objects, deleting objects, exiting the program, and pausing, unpausing and reseting the simulation */
void kbd(unsigned char key, int x, int y) {
    if (State == "InGame"){
        if(key == 'a' || key == 'A'){
            moveShip("left");
            X--;
        }
        if(key == 's' || key == 'S'){
            moveShip("down");
            Y--;
        }
        if(key == 'd' || key == 'D'){
            moveShip("right");
            X++;
        }
        if(key == 'w' || key == 'W'){
            moveShip("up");
            Y++;
        }
        if(key == 'x' || key == 'X'){
            shootBullet();
        }
        if(key == 'g' || key == 'G'){
            State = "GameOver";
        }
        if(key == 'c' || key == 'C'){
            State = "Winner";
        }
    }

    if(key == 'q' || key == 'Q'){
		exit(0);
    }
}

/* mouse (button) function for attracting and repelling the particles due to a mouse click */
void mouse(int btn, int state, int x, int y) {
    y = 500 - y;
    clickLocationX = x;
    clickLocationY = y;
    if(btn == GLUT_LEFT_BUTTON && state==GLUT_DOWN){
        if (State == "Main"){
            if (clickLocationX > 175 and clickLocationX < 325 and clickLocationY < 285 and clickLocationY > 235){
                State = "InGame";
            }
        } else if (State == "GameOver" or State == "Winner"){
            if (clickLocationX > 80 and clickLocationX < 230 and clickLocationY < 285 and clickLocationY > 235){
                State = "InGame";
            } else if (clickLocationX > 270 and clickLocationX < 420 and clickLocationY < 285 and clickLocationY > 235){
                exit(0);
            }
        }
    }
	if(btn == GLUT_LEFT_BUTTON && state==GLUT_UP){
        leftClick = false;
	}
    if(btn == GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
        rightClick = true;
	}
	if(btn == GLUT_RIGHT_BUTTON && state==GLUT_UP){
        rightClick = false;
	}
    
    glutPostRedisplay();
}

/* idle function - for when nothing is happening */
void idle() {
    glutPostRedisplay();
}


void init(void)
{
	glClearColor(0, 0, 0, 0);
	glColor3f(1, 1, 1);
    
    glShadeModel(GL_FLAT);
    
    glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    
	float Light0Ambient[] = {1, 1, 1, 1};
	float Light0Diffuse[] = {1,1,1, 1};
	float Light0Specular[] = {1,1,1, 1};
    
    float Light1Ambient[] = {1,1, 1, 1};
	float Light1Diffuse[] = {1,1,1, 1};
	float Light1Specular[] = {1,1,1, 1};
    
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Light0Diffuse);
	glLightfv(GL_LIGHT0, GL_AMBIENT, Light0Ambient);
	glLightfv(GL_LIGHT0, GL_SPECULAR, Light0Specular);
    
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Light1Diffuse);
	glLightfv(GL_LIGHT1, GL_AMBIENT, Light1Ambient);
	glLightfv(GL_LIGHT1, GL_SPECULAR, Light1Specular);
    
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    glLightfv(GL_LIGHT0, GL_POSITION, GlobalLight0Postion);
    glLightfv(GL_LIGHT1, GL_POSITION, GlobalLight1Postion);
	gluPerspective(45, 1, 1, 100);
}

/* main function - program entry point */
int main(int argc, char** argv)
{
    //tutorial(); // Outputs simulation commands
    
    part = new Particle*[numberOfParticles];
	//creates all the particles
	for (int i = 0; i < numberOfParticles; i++){
		part[i] = new Particle	(0,0,0,//Position
                                 -1,-1,rand()/float(RAND_MAX)*14.f+10.f,//Velocity
                                 0.996,0.644,0,  //Colour
                                 1); // Alpha
    }
    
	glutInit(&argc, argv);		//starts up GLUT
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	
	
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
    
	glutCreateWindow("ObjectReader");	//creates the window
    
	glutDisplayFunc(display);	//registers "display" as the display callback function
    glutTimerFunc(25,update,0);
    glutKeyboardFunc(kbd);
    glutMouseFunc(mouse);
	glutSpecialFunc(mySpecialKeys);
    glutIdleFunc(idle);                  //registers "idle" as the idle callback function
    
    glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
	init();
    
	glutMainLoop();				//starts the event loop
    
	return(0);					//return may not be necessary on all compilers
}