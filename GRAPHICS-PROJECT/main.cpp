#include<windows.h>
#include<cstdio>
#include<GL/glut.h>
#include<GL/gl.h>
#include<stdlib.h>
#include<math.h>
#include<bits/stdc++.h>
#define PI 3.14159265358979323846

void morning();
void day();
void night();
void morningSky();
void daySky();
void nightSky();
void cloud();
void night_cloud();
void sun();
void snow();
void moon();
void ground();
void tree();
void plane();
void rail_line();
void train();
void night_train();
void road();
void car();
void bus();
void microbus();
void night_car();
void night_bus();
void buildings();
void night_buildings();
void windmill_on();
void windmill_off();
void lake();
void night_lake();
void boat();
void morningsound();
void daysound();
void nightsound();

GLfloat snowSpeed = 0.01f;
GLfloat snowPosition = 0.0f;
GLfloat planeSpeed = 0.04f;
GLfloat planePosition = 0.0f;
GLfloat rightSpeed = 0.05f;
GLfloat rightPosition = 0.0f;
GLfloat leftSpeed = 0.05f;
GLfloat leftPosition = 0.0f;
GLfloat trainSpeed = 0.1f;
GLfloat trainPosition = 0.0f;
GLfloat windmillSpeed=0.0f;
GLfloat boatSpeed = 0.02f;
GLfloat boatPosition = 0.0f;

void init()
{
    glLoadIdentity();
}

void controlkeyboard(unsigned char key, int x, int y){

	switch(key){

        case 'm':
            glutDisplayFunc(morning);
            morningsound();
            break;

        case 'd':
            glutDisplayFunc(day);
            daysound();
            break;

        case 'n':
            glutDisplayFunc(night);
            nightsound();
            break;

    glutPostRedisplay();
	}
}

void morningsound()
{
    PlaySound("morning_sound.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void daysound()
{
    PlaySound("day.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void nightsound()
{
    PlaySound("night.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void snowup(int value)
{
       if(snowPosition < -1.5)
       {
         snowPosition = 2.0f;
       }

       if(snowPosition>2.0)
       {
          snowPosition=-1.5;
       }

       snowPosition -= snowSpeed;
       glutPostRedisplay();
       glutTimerFunc(25, snowup, 0);
}

void planeup(int value)
{
    if(planePosition > 1.5)
    {
        planePosition = -1.5f;
    }

    planePosition += planeSpeed;
	glutPostRedisplay();
	glutTimerFunc(100, planeup, 0);
}

void trainup(int value)
{
    if(trainPosition > 1.5)
    {
        trainPosition = -2.0f;
    }

    trainPosition += trainSpeed;
	glutPostRedisplay();
	glutTimerFunc(100, trainup, 0);
}

void boatup(int value)
{
    if(boatPosition <- 1.5)
    {
        boatPosition = 1.0;
    }

    boatPosition -= boatSpeed;
	glutPostRedisplay();
	glutTimerFunc(100, boatup, 0);
}

void rightup(int value)
{
    if(rightPosition > 1.5)
    {
        rightPosition = -1.5f;
    }

    rightPosition += rightSpeed;
	glutPostRedisplay();
	glutTimerFunc(100, rightup, 0);
}

void leftup(int value)
{
    if(leftPosition <- 1.5)
    {
        leftPosition = 2.0;
    }

    leftPosition -= leftSpeed;
	glutPostRedisplay();
	glutTimerFunc(100, leftup, 0);
}

void FilledCircle(GLfloat cx,GLfloat cy, GLfloat r, int amount)//sharpness
{
    int i;
    GLfloat twicePi=2.0f*PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);
    for(i=0;i<=amount;i++){
        glVertex2f(
            cx+(r*cos(i*twicePi/amount)),
            cy+(r*sin(i*twicePi/amount))
        );
    }
    glEnd();
}

void LineCircle(GLfloat cx,GLfloat cy, GLfloat r, int amount)
{
    int i;
    GLfloat twicePi=2.0f*PI;
	glBegin(GL_LINE_LOOP);
    for(i = 0; i <= amount;i++) {
        glVertex2f(
            cx + (r*cos(i*twicePi/amount)),
            cy + (r*sin(i*twicePi/amount))
        );
    }
    glEnd();
}

void HalfCircle(GLfloat cx,GLfloat cy,GLfloat r)
{
	int i;
	int lineAmount = 100;
	GLfloat twicePi=2.0f*PI;
	glBegin(GL_TRIANGLE_FAN);
    for(i = 50; i <= lineAmount;i++)
    {
        glVertex2f(cx + (r*cos(i*twicePi/lineAmount)),cy+(r*sin(i*twicePi/lineAmount)));
    }
	glEnd();
}

void morningSky()
{
    glBegin(GL_QUADS);
    glColor3ub(180, 235, 245);
    glVertex2f(1.0,1.0);
    glVertex2f(-1.0,1.0);
    glColor3ub(200, 240, 250);
    glVertex2f(-1.0,.2);
    glVertex2f(1.0,.2);
    glEnd();
}

void daySky()
{
    glBegin(GL_QUADS);
    glColor3ub(100, 200, 220);
    glVertex2f(1.0,1.0);
    glVertex2f(-1.0,1.0);
    glColor3ub(150, 240, 240);
    glVertex2f(-1.0,.2);
    glVertex2f(1.0,.2);
    glEnd();
}

void nightSky()
{
    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex2f(1.0,1.0);
    glVertex2f(-1.0,1.0);
    glColor3ub(150, 150, 150);
    glVertex2f(-1.0,.2);
    glVertex2f(1.0,.2);
    glEnd();
}

void cloud()
{
    glColor3ub(253, 255, 137);
    FilledCircle(-.78,.75,.06,100);
    glColor3ub(242, 242, 242);
    FilledCircle(.7,.8,.05,100);
    glColor3ub(255, 242, 242);
    FilledCircle(.75,.75,.05,100);

    glColor3ub(242, 242, 242);
    FilledCircle(.18,.7,.05,100);
    glColor3ub(242, 242, 242);
    FilledCircle(.1,.7,.05,100);
    glColor3ub(242, 242, 242);
    FilledCircle(.15,.65,.05,100);

    glColor3ub(242, 242, 242);
    FilledCircle(-.38,.85,.05,100);
    glColor3ub(242, 242, 242);
    FilledCircle(-.3,.85,.05,100);
    glColor3ub(242, 242, 242);
    FilledCircle(-.35,.8,.05,100);

    glColor3ub(242, 242, 242);
    FilledCircle(-.88,.9,.05,100);
    glColor3ub(242, 242, 242);
    FilledCircle(-.8,.9,.05,100);
    glColor3ub(242, 242, 242);
    FilledCircle(-.85,.85,.05,100);
}

void night_cloud()
{
    glColor3ub(225, 225, 225);
    FilledCircle(.18,.7,.05,100);
    glColor3ub(220, 220, 220);
    FilledCircle(.1,.7,.05,100);
    glColor3ub(220, 220, 220);
    FilledCircle(.15,.65,.05,100);

    glColor3ub(220, 220, 220);
    FilledCircle(-.48,.85,.05,100);
    glColor3ub(220, 220, 220);
    FilledCircle(-.4,.85,.05,100);
    glColor3ub(220, 220, 220);
    FilledCircle(-.45,.8,.05,100);

    glColor3ub(220, 220, 220);
    FilledCircle(-.88,.9,.05,100);
    glColor3ub(220, 220, 220);
    FilledCircle(-.8,.9,.05,100);
    glColor3ub(220, 220, 220);
    FilledCircle(-.85,.85,.05,100);
}

void sun()
{
    glColor3ub(252, 209, 77);
    FilledCircle(-.78,.75,.06,100);
}

void snow()
{
    glPushMatrix();

    glTranslatef(-snowPosition,snowPosition, 0.0f);
    glColor3ub(255,255,255);
    FilledCircle(0,0,0.025,100);
    FilledCircle(-0.6,0.7,0.025,100);
    FilledCircle(-0,0.9,0.025,100);
    FilledCircle(-0.86,0.7,0.025,100);
    FilledCircle(-0.65,0.87,0.025,100);
    FilledCircle(-0.57,0.34,0.025,100);
    FilledCircle(0,0,0.025,100);
    FilledCircle(0.54,0.52,0.025,100);
    FilledCircle(0.67,0.67,0.025,100);
    FilledCircle(0.82,0.35,0.025,100);
    FilledCircle(0.38,0.2,0.025,100);
    FilledCircle(0.9,0.6,0.025,100);
    FilledCircle(0.2,0.5,0.025,100);
    FilledCircle(-0.32,0.5,0.025,100);
    FilledCircle(-0.65,0.25,0.025,100);
    FilledCircle(-0.7,0.3,0.025,100);

    glTranslatef(snowPosition,snowPosition, 0.0f);
    glColor3ub(255,255,255);
    glTranslatef(-0.2,1,0);
    FilledCircle(0,0,0.025,100);
    FilledCircle(-0.6,0.7,0.025,100);
    FilledCircle(-0,0.9,0.025,100);
    FilledCircle(-0.86,0.7,0.025,100);
    FilledCircle(-0.65,0.87,0.025,100);
    FilledCircle(-0.57,0.34,0.025,100);
    FilledCircle(0,0,0.025,100);
    FilledCircle(0.54,0.52,0.025,100);
    FilledCircle(0.67,0.67,0.025,100);
    FilledCircle(0.82,0.35,0.025,100);
    FilledCircle(0.38,0.2,0.025,100);
    FilledCircle(0.9,0.6,0.025,100);
    FilledCircle(0.2,0.5,0.025,100);
    FilledCircle(-0.32,0.5,0.025,100);
    FilledCircle(-0.65,0.25,0.025,100);
    FilledCircle(-0.7,0.3,0.025,100);

    glTranslatef(0.0f,snowPosition, 0.0f);
    glColor3ub(255,255,255);
    glTranslatef(0.2,0,0);
    FilledCircle(0,0,0.025,100);
    FilledCircle(-0.6,0.7,0.025,100);
    FilledCircle(-0,0.9,0.025,100);
    FilledCircle(-0.86,0.7,0.025,100);
    FilledCircle(-0.65,0.87,0.025,100);
    FilledCircle(-0.57,0.34,0.025,100);
    FilledCircle(0,0,0.025,100);
    FilledCircle(0.54,0.52,0.025,100);
    FilledCircle(0.67,0.67,0.025,100);
    FilledCircle(0.82,0.35,0.025,100);
    FilledCircle(0.38,0.2,0.025,100);
    FilledCircle(0.9,0.6,0.025,100);
    FilledCircle(0.2,0.5,0.025,100);
    FilledCircle(-0.32,0.5,0.025,100);
    FilledCircle(-0.65,0.25,0.025,100);
    FilledCircle(-0.7,0.3,0.025,100);

    glPopMatrix();
}

void moon()
{
    glColor3ub(255, 255, 255);
    FilledCircle(-.78,.75,.06,100);
}

void ground()
{
    glBegin(GL_QUADS);
    glColor3ub(13, 198, 47);
    glVertex2f(-1,.09);
    glVertex2f(1,.09);
    glVertex2f(1,.2);
    glVertex2f(-1,.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(-1,.1);
    glVertex2f(1,0.1);
    glVertex2f(1,0.09);
    glVertex2f(-1,0.09);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(201, 201, 201);
    glVertex2f(-1,.09);
    glVertex2f(1,0.09);
    glVertex2f(1,0);
    glVertex2f(-1,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 153, 102);
    glVertex2f(-1,-.18);
    glVertex2f(1,-.18);
    glVertex2f(1,-.04);
    glVertex2f(-1,-.04);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(15, 153, 110);
    glVertex2f(-1,-.005);
    glVertex2f(1,-.005);
    glVertex2f(1,-.035);
    glVertex2f(-1,-.035);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(81, 80, 93);
    glVertex2f(-1,-.8);
    glVertex2f(1,-.8);
    glVertex2f(1,-.65);
    glVertex2f(-1,-.65);
    glEnd();
}

void tree()
{
    //tree-1
    glBegin(GL_QUADS);
    glColor3ub(165, 49, 0);
    glVertex2f(-.02,.1);
    glVertex2f(-.00,.1);
    glVertex2f(-.00,.25);
    glVertex2f(-.02,.25);
    glEnd();

    glColor3ub(45,140,0);
    FilledCircle(-.04,.2,.05,100);
    glColor3ub(45,140,0);
    FilledCircle(.02,.2,.05,100);
    glColor3ub(45,140,0);
    FilledCircle(-.01,.25,.05,100);

    //tree-2
    glTranslatef(-.38,0,0);
    glBegin(GL_QUADS);
    glColor3ub(165, 49, 0);
    glVertex2f(-.02,.1);
    glVertex2f(-.00,.1);
    glVertex2f(-.00,.25);
    glVertex2f(-.02,.25);
    glEnd();

    glColor3ub(45,140,0);
    FilledCircle(-.04,.2,.05,100);
    glColor3ub(45,140,0);
    FilledCircle(.02,.2,.05,100);
    glColor3ub(45,140,0);
    FilledCircle(-.01,.25,.05,100);

    init();

    //tree-3
    glBegin(GL_QUADS);
    glColor3ub(165, 49, 0);
    glVertex2f(-.58,.1);
    glVertex2f(-.56,.1);
    glVertex2f(-.56,.25);
    glVertex2f(-.58,.25);
    glEnd();

    glColor3ub(45,140,0);
    FilledCircle(-.6,.2,.05,100);
    glColor3ub(45,140,0);
    FilledCircle(-.54,.2,.05,100);
    glColor3ub(45,140,0);
    FilledCircle(-.57,.25,.05,100);
}

void plane()
{
    glPushMatrix();

    glTranslatef(planePosition,0.0, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(187,223,146);
    glVertex2f(.005,.80);
    glVertex2f(-.23,.80);
    glVertex2f(-.28,.84);
    glVertex2f(-.28,.94);
    glVertex2f(-.25,.88);
    glVertex2f(-.08,.88);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(188, 150, 223);
    glVertex2f(-.2,.75);
    glVertex2f(-.25,.78);
    glVertex2f(-.15,.84);
    glVertex2f(-.1,.84);
    glEnd();

    //windows
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-.08,.85);
    glVertex2f(-.1,.85);
    glVertex2f(-.1,.87);
    glVertex2f(-.08,.87);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-.12,.85);
    glVertex2f(-.14,.85);
    glVertex2f(-.14,.87);
    glVertex2f(-.12,.87);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-.16,.85);
    glVertex2f(-.18,.85);
    glVertex2f(-.18,.87);
    glVertex2f(-.16,.87);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-.2,.85);
    glVertex2f(-.22,.85);
    glVertex2f(-.22,.87);
    glVertex2f(-.2,.87);
    glEnd();

    glPopMatrix();
}

void railway()
{
    glTranslatef(0,.74, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(-1.0,-.9);
    glVertex2f(1.0,-.9);
    glVertex2f(1.0,-.875);
    glVertex2f(-1.0,-.875);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(-1.0,-.825);
    glVertex2f(1.0,-.825);
    glVertex2f(1.0,-.8);
    glVertex2f(-1.0,-.8);
    glEnd();

    //middle lines
    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(-.9,-.875);
    glVertex2f(-.88,-.875);
    glVertex2f(-.88,-.8);
    glVertex2f(-.9,-.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(-.8,-.875);
    glVertex2f(-.78,-.875);
    glVertex2f(-.78,-.8);
    glVertex2f(-.8,-.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(-.7,-.875);
    glVertex2f(-.68,-.875);
    glVertex2f(-.68,-.8);
    glVertex2f(-.7,-.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(-.6,-.875);
    glVertex2f(-.58,-.875);
    glVertex2f(-.58,-.8);
    glVertex2f(-.6,-.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(-.5,-.875);
    glVertex2f(-.48,-.875);
    glVertex2f(-.48,-.8);
    glVertex2f(-.5,-.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(-.4,-.875);
    glVertex2f(-.38,-.875);
    glVertex2f(-.38,-.8);
    glVertex2f(-.4,-.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(-.3,-.875);
    glVertex2f(-.28,-.875);
    glVertex2f(-.28,-.8);
    glVertex2f(-.3,-.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(-.2,-.875);
    glVertex2f(-.18,-.875);
    glVertex2f(-.18,-.8);
    glVertex2f(-.2,-.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(-.1,-.875);
    glVertex2f(-.08,-.875);
    glVertex2f(-.08,-.8);
    glVertex2f(-.1,-.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(.0,-.875);
    glVertex2f(.02,-.875);
    glVertex2f(.02,-.8);
    glVertex2f(.0,-.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(.1,-.875);
    glVertex2f(.12,-.875);
    glVertex2f(.12,-.8);
    glVertex2f(.1,-.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(.2,-.875);
    glVertex2f(.22,-.875);
    glVertex2f(.22,-.8);
    glVertex2f(.2,-.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(.3,-.875);
    glVertex2f(.32,-.875);
    glVertex2f(.32,-.8);
    glVertex2f(.3,-.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(.4,-.875);
    glVertex2f(.42,-.875);
    glVertex2f(.42,-.8);
    glVertex2f(.4,-.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(.5,-.875);
    glVertex2f(.52,-.875);
    glVertex2f(.52,-.8);
    glVertex2f(.5,-.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(.6,-.875);
    glVertex2f(.62,-.875);
    glVertex2f(.62,-.8);
    glVertex2f(.6,-.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(.7,-.875);
    glVertex2f(.72,-.875);
    glVertex2f(.72,-.8);
    glVertex2f(.7,-.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(.8,-.875);
    glVertex2f(.82,-.875);
    glVertex2f(.82,-.8);
    glVertex2f(.8,-.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(87, 87, 87);
    glVertex2f(.9,-.875);
    glVertex2f(.92,-.875);
    glVertex2f(.92,-.8);
    glVertex2f(.9,-.8);
    glEnd();

    init();
}

void train()
{
    glPushMatrix();

    glTranslatef(trainPosition,.74, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(205, 112, 126);
    glVertex2f(.78,-.89);
    glVertex2f(.5,-.89);
    glVertex2f(.5,-.68);
    glVertex2f(.65,-.68);
    glVertex2f(.78,-.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(104,255,153);
    glVertex2f(.5,-.89);
    glVertex2f(.48,-.89);
    glVertex2f(.48,-.83);
    glVertex2f(.5,-.83);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 112, 26);
    glVertex2f(-.48,-.89);
    glVertex2f(-.18,-.89);
    glVertex2f(-.18,-.68);
    glVertex2f(-.48,-.68);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(104,255,153);
    glVertex2f(-.18,-.89);
    glVertex2f(-.16,-.89);
    glVertex2f(-.16,-.83);
    glVertex2f(-.18,-.83);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 112, 26);
    glVertex2f(-.16,-.89);
    glVertex2f(.16,-.89);
    glVertex2f(.16,-.68);
    glVertex2f(-.16,-.68);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(104,255,153);
    glVertex2f(.16,-.89);
    glVertex2f(.18,-.89);
    glVertex2f(.18,-.83);
    glVertex2f(.16,-.83);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 112, 26);
    glVertex2f(.18,-.89);
    glVertex2f(.48,-.89);
    glVertex2f(.48,-.68);
    glVertex2f(.18,-.68);
    glEnd();

    //windows
    glBegin(GL_QUADS);
    glColor3ub(55, 44, 67);
    glVertex2f(.65,-.8);
    glVertex2f(.53,-.8);
    glVertex2f(.53,-.7);
    glVertex2f(.65,-.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(55, 44, 67);
    glVertex2f(-.46,-.8);
    glVertex2f(-.4,-.8);
    glVertex2f(-.4,-.7);
    glVertex2f(-.46,-.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(55, 44, 67);
    glVertex2f(-.36,-.8);
    glVertex2f(-.3,-.8);
    glVertex2f(-.3,-.7);
    glVertex2f(-.36,-.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(55, 44, 67);
    glVertex2f(-.26,-.8);
    glVertex2f(-.2,-.8);
    glVertex2f(-.2,-.7);
    glVertex2f(-.26,-.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(55, 44, 67);
    glVertex2f(-.14,-.8);
    glVertex2f(-.08,-.8);
    glVertex2f(-.08,-.7);
    glVertex2f(-.14,-.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(55, 44, 67);
    glVertex2f(-.04,-.8);
    glVertex2f(.02,-.8);
    glVertex2f(.02,-.7);
    glVertex2f(-.04,-.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(55, 44, 67);
    glVertex2f(.06,-.8);
    glVertex2f(.12,-.8);
    glVertex2f(.12,-.7);
    glVertex2f(.06,-.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(55, 44, 67);
    glVertex2f(.2,-.8);
    glVertex2f(.26,-.8);
    glVertex2f(.26,-.7);
    glVertex2f(.2,-.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(55, 44, 67);
    glVertex2f(.3,-.8);
    glVertex2f(.36,-.8);
    glVertex2f(.36,-.7);
    glVertex2f(.3,-.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(55, 44, 67);
    glVertex2f(.4,-.8);
    glVertex2f(.46,-.8);
    glVertex2f(.46,-.7);
    glVertex2f(.4,-.7);
    glEnd();

    glPopMatrix();
}

void night_train()
{
    glPushMatrix();

    glTranslatef(trainPosition,.74, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(205, 112, 126);
    glVertex2f(.78,-.89);
    glVertex2f(.5,-.89);
    glVertex2f(.5,-.68);
    glVertex2f(.65,-.68);
    glVertex2f(.78,-.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(104,255,153);
    glVertex2f(.5,-.89);
    glVertex2f(.48,-.89);
    glVertex2f(.48,-.83);
    glVertex2f(.5,-.83);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 112, 26);
    glVertex2f(-.48,-.89);
    glVertex2f(-.18,-.89);
    glVertex2f(-.18,-.68);
    glVertex2f(-.48,-.68);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(104,255,153);
    glVertex2f(-.18,-.89);
    glVertex2f(-.16,-.89);
    glVertex2f(-.16,-.83);
    glVertex2f(-.18,-.83);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 112, 26);
    glVertex2f(-.16,-.89);
    glVertex2f(.16,-.89);
    glVertex2f(.16,-.68);
    glVertex2f(-.16,-.68);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(104,255,153);
    glVertex2f(.16,-.89);
    glVertex2f(.18,-.89);
    glVertex2f(.18,-.83);
    glVertex2f(.16,-.83);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(252, 112, 26);
    glVertex2f(.18,-.89);
    glVertex2f(.48,-.89);
    glVertex2f(.48,-.68);
    glVertex2f(.18,-.68);
    glEnd();

    //windows
    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.65,-.8);
    glVertex2f(.53,-.8);
    glVertex2f(.53,-.7);
    glVertex2f(.65,-.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(-.46,-.8);
    glVertex2f(-.4,-.8);
    glVertex2f(-.4,-.7);
    glVertex2f(-.46,-.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(-.36,-.8);
    glVertex2f(-.3,-.8);
    glVertex2f(-.3,-.7);
    glVertex2f(-.36,-.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(-.26,-.8);
    glVertex2f(-.2,-.8);
    glVertex2f(-.2,-.7);
    glVertex2f(-.26,-.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(-.14,-.8);
    glVertex2f(-.08,-.8);
    glVertex2f(-.08,-.7);
    glVertex2f(-.14,-.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(-.04,-.8);
    glVertex2f(.02,-.8);
    glVertex2f(.02,-.7);
    glVertex2f(-.04,-.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.06,-.8);
    glVertex2f(.12,-.8);
    glVertex2f(.12,-.7);
    glVertex2f(.06,-.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.2,-.8);
    glVertex2f(.26,-.8);
    glVertex2f(.26,-.7);
    glVertex2f(.2,-.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.3,-.8);
    glVertex2f(.36,-.8);
    glVertex2f(.36,-.7);
    glVertex2f(.3,-.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.4,-.8);
    glVertex2f(.46,-.8);
    glVertex2f(.46,-.7);
    glVertex2f(.4,-.7);
    glEnd();

    glPopMatrix();
}

void road()
{
    glBegin(GL_QUADS);
    glColor3ub(119, 136, 153);
    glVertex2f(-1.0,-.63);
    glVertex2f(1.0,-.63);
    glVertex2f(1.0,-.2);
    glVertex2f(-1.0,-.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(47, 79, 79);
    glVertex2f(-1.0,-.2);
    glVertex2f(1.0,-.2);
    glVertex2f(1.0,-.18);
    glVertex2f(-1.0,-.18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(192, 192, 192);
    glVertex2f(-1.0,-.41);
    glVertex2f(1.0,-.41);
    glVertex2f(1.0,-.4);
    glVertex2f(-1.0,-.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(47, 79, 79);
    glVertex2f(-1.0,-.65);
    glVertex2f(1.0,-.65);
    glVertex2f(1.0,-.63);
    glVertex2f(-1.0,-.63);
    glEnd();

    //middle lines
    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex2f(-.8,-.32);
    glVertex2f(-.7,-.32);
    glVertex2f(-.7,-.3);
    glVertex2f(-.8,-.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex2f(-.5,-.32);
    glVertex2f(-.4,-.32);
    glVertex2f(-.4,-.3);
    glVertex2f(-.5,-.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex2f(-.1,-.32);
    glVertex2f(.0,-.32);
    glVertex2f(.0,-.3);
    glVertex2f(-.1,-.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex2f(.3,-.32);
    glVertex2f(.4,-.32);
    glVertex2f(.4,-.3);
    glVertex2f(0.3,-.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex2f(.7,-.32);
    glVertex2f(.8,-.32);
    glVertex2f(.8,-.3);
    glVertex2f(.7,-.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex2f(-.8,-.52);
    glVertex2f(-.7,-.52);
    glVertex2f(-.7,-.5);
    glVertex2f(-.8,-.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex2f(-.5,-.52);
    glVertex2f(-.4,-.52);
    glVertex2f(-.4,-.5);
    glVertex2f(-.5,-.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex2f(-.1,-.52);
    glVertex2f(.0,-.52);
    glVertex2f(.0,-.5);
    glVertex2f(-.1,-.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex2f(.3,-.52);
    glVertex2f(.4,-.52);
    glVertex2f(.4,-.5);
    glVertex2f(0.3,-.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex2f(.7,-.52);
    glVertex2f(.8,-.52);
    glVertex2f(.8,-.5);
    glVertex2f(.7,-.5);
    glEnd();
}

void car()
{
    glPushMatrix();

    //body
    glTranslatef(leftPosition,0.02, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(51,51,153);
    glVertex2f(.25,-.55);
    glVertex2f(.6,-.55);
    glVertex2f(.6,-.46);
    glVertex2f(.55,-.46);
    glVertex2f(.5,-.42);
    glVertex2f(.4,-.42);
    glVertex2f(.35,-.47);
    glVertex2f(.25,-.47);
    glEnd();

    //windows
    glBegin(GL_QUADS);
    glColor3ub(159, 159, 223);
    glVertex2f(.35,-.47);
    glVertex2f(.45,-.47);
    glVertex2f(.45,-.43);
    glVertex2f(.4,-.43);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(159, 159, 223);
    glVertex2f(.46,-.47);
    glVertex2f(.53,-.47);
    glVertex2f(.5,-.43);
    glVertex2f(.46,-.43);
    glEnd();

    //tires
    glColor3ub(0,0,0);
    FilledCircle(.35,-.54,.035,100);
    glColor3ub(255,255,255);
    FilledCircle(.35,-.54,.02,100);

    glColor3ub(0,0,0);
    FilledCircle(.5,-.54,.035,100);
    glColor3ub(255,255,255);
    FilledCircle(.5,-.54,.02,100);

    //head_light
    glBegin(GL_QUADS);
    glColor3ub(255,255 ,220);
    glVertex2f(.25,-.53);
    glVertex2f(.27,-.53);
    glVertex2f(.27,-.5);
    glVertex2f(.25,-.5);
    glEnd();

    glPopMatrix();
}

void bus()
{
    glPushMatrix();

    //body
    glTranslatef(rightPosition,0.06, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(255, 102, 153);
    glVertex2f(0.0,-.37);
    glVertex2f(.4,-.37);
    glVertex2f(.4,-.18);
    glVertex2f(0.0,-.18);
    glEnd();

    //windows
    glBegin(GL_QUADS);
    glColor3ub(255, 204, 153);
    glVertex2f(.4,-.3);
    glVertex2f(.4,-.2);
    glVertex2f(.35,-.2);
    glVertex2f(.35,-.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 204, 153);
    glVertex2f(.32,-.28);
    glVertex2f(.32,-.2);
    glVertex2f(.27,-.2);
    glVertex2f(.27,-.28);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 204, 153);
    glVertex2f(.25,-.28);
    glVertex2f(.25,-.2);
    glVertex2f(.20,-.2);
    glVertex2f(.20,-.28);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 204, 153);
    glVertex2f(.18,-.28);
    glVertex2f(.18,-.2);
    glVertex2f(.13,-.2);
    glVertex2f(.13,-.28);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 204, 153);
    glVertex2f(.11,-.28);
    glVertex2f(.11,-.2);
    glVertex2f(.06,-.2);
    glVertex2f(.06,-.28);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 204, 153);
    glVertex2f(.02,-.25);
    glVertex2f(.02,-.2);
    glVertex2f(.0,-.2);
    glVertex2f(.0,-.25);
    glEnd();

    //tires
    glColor3ub(0,0,0);
    FilledCircle(.1,-.35,.04,100);
    glColor3ub(255,255,255);
    FilledCircle(.1,-.35,.015,100);

    glColor3ub(0,0,0);
    FilledCircle(.3,-.35,.04,100);
    glColor3ub(255,255,255);
    FilledCircle(.3,-.35,.015,100);

    //head_light
    glBegin(GL_QUADS);
    glColor3ub(255,255 ,255);
    glVertex2f(.4,-.35);
    glVertex2f(.4,-.32);
    glVertex2f(.38,-.32);
    glVertex2f(.38,-.35);
    glEnd();

    glPopMatrix();
}

void microbus()
{
    glPushMatrix();

    //body
    glTranslatef(leftPosition,0.05, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(68,0,204);
    glVertex2f(-.4,-.6);
    glVertex2f(-.05,-.6);
    glVertex2f(-.05,-.45);
    glVertex2f(-.3,-.45);
    glVertex2f(-.4,-.52);
    glEnd();

    //windows
    glBegin(GL_QUADS);
    glColor3ub(153, 102, 255);
    glVertex2f(-.38,-.53);
    glVertex2f(-.25,-.53);
    glVertex2f(-.25,-.46);
    glVertex2f(-.29,-.46);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 102, 255);
    glVertex2f(-.23,-.53);
    glVertex2f(-.16,-.53);
    glVertex2f(-.16,-.46);
    glVertex2f(-.23,-.46);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 102, 255);
    glVertex2f(-.14,-.53);
    glVertex2f(-.07,-.53);
    glVertex2f(-.07,-.46);
    glVertex2f(-.14,-.46);
    glEnd();

    //tires
    glColor3ub(0,0,0);
    FilledCircle(-.28,-.58,.035,100);
    glColor3ub(255,255,255);
    FilledCircle(-.28,-.58,.02,100);

    glColor3ub(0,0,0);
    FilledCircle(-.12,-.58,.035,100);
    glColor3ub(255,255,255);
    FilledCircle(-.12,-.58,.02,100);

    //head_light
    glBegin(GL_QUADS);
    glColor3ub(255,255 ,220);
    glVertex2f(-.4,-.58);
    glVertex2f(-.4,-.55);
    glVertex2f(-.38,-.55);
    glVertex2f(-.38,-.58);
    glEnd();

    glPopMatrix();
}

void night_car()
{
    glPushMatrix();

    //body
    glTranslatef(leftPosition,0.02, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(51,51,153);
    glVertex2f(.25,-.55);
    glVertex2f(.6,-.55);
    glVertex2f(.6,-.46);
    glVertex2f(.55,-.46);
    glVertex2f(.5,-.42);
    glVertex2f(.4,-.42);
    glVertex2f(.35,-.47);
    glVertex2f(.25,-.47);
    glEnd();

    //windows
    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.35,-.47);
    glVertex2f(.45,-.47);
    glVertex2f(.45,-.43);
    glVertex2f(.4,-.43);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.46,-.47);
    glVertex2f(.53,-.47);
    glVertex2f(.5,-.43);
    glVertex2f(.46,-.43);
    glEnd();

    //tires
    glColor3ub(0,0,0);
    FilledCircle(.35,-.54,.035,100);
    glColor3ub(255,255,255);
    FilledCircle(.35,-.54,.02,100);

    glColor3ub(0,0,0);
    FilledCircle(.5,-.54,.035,100);
    glColor3ub(255,255,255);
    FilledCircle(.5,-.54,.02,100);

    //head_light
    glBegin(GL_QUADS);
    glColor3ub(255,255 ,220);
    glVertex2f(.25,-.53);
    glVertex2f(.27,-.53);
    glVertex2f(.27,-.5);
    glVertex2f(.25,-.5);
    glEnd();

    glPopMatrix();
}

void night_bus()
{
    glPushMatrix();

    //body
    glTranslatef(rightPosition,0.06, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(255, 102, 153);
    glVertex2f(0.0,-.37);
    glVertex2f(.4,-.37);
    glVertex2f(.4,-.18);
    glVertex2f(0.0,-.18);
    glEnd();

    //windows
    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.4,-.3);
    glVertex2f(.4,-.2);
    glVertex2f(.35,-.2);
    glVertex2f(.35,-.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.32,-.28);
    glVertex2f(.32,-.2);
    glVertex2f(.27,-.2);
    glVertex2f(.27,-.28);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.25,-.28);
    glVertex2f(.25,-.2);
    glVertex2f(.20,-.2);
    glVertex2f(.20,-.28);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.18,-.28);
    glVertex2f(.18,-.2);
    glVertex2f(.13,-.2);
    glVertex2f(.13,-.28);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.11,-.28);
    glVertex2f(.11,-.2);
    glVertex2f(.06,-.2);
    glVertex2f(.06,-.28);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.02,-.25);
    glVertex2f(.02,-.2);
    glVertex2f(.0,-.2);
    glVertex2f(.0,-.25);
    glEnd();

    //tires
    glColor3ub(0,0,0);
    FilledCircle(.1,-.35,.04,100);
    glColor3ub(255,255,255);
    FilledCircle(.1,-.35,.015,100);

    glColor3ub(0,0,0);
    FilledCircle(.3,-.35,.04,100);
    glColor3ub(255,255,255);
    FilledCircle(.3,-.35,.015,100);

    //head_light
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(.4,-.35);
    glVertex2f(.4,-.32);
    glVertex2f(.38,-.32);
    glVertex2f(.38,-.35);
    glEnd();

    glPopMatrix();
}

void buildings()
{
    //building-1
    //structure
    glBegin(GL_QUADS);
    glColor3ub(180,180,255);
    glVertex2f(.65,.1);
    glVertex2f(.9,.1);
    glVertex2f(.9,.6);
    glVertex2f(.65,.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(125,55,0);
    glVertex2f(.65,.6);
    glVertex2f(.9,.6);
    glVertex2f(.9,.62);
    glVertex2f(.65,.62);
    glEnd();

    //door
    glBegin(GL_QUADS);
    glColor3ub(102, 18, 50);
    glVertex2f(.72,.16);
    glVertex2f(.82,.16);
    glVertex2f(.82,.1);
    glVertex2f(.72,.1);
    glEnd();

    //windows
    glBegin(GL_QUADS);
    glColor3ub(70,90,25);
    glVertex2f(.76,.16);
    glVertex2f(.78,.16);
    glVertex2f(.78,.6);
    glVertex2f(.76,.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,40,25);
    glVertex2f(.68,.48);
    glVertex2f(.73,.48);
    glVertex2f(.73,.55);
    glVertex2f(.68,.55);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,40,25);
    glVertex2f(.68,.33);
    glVertex2f(.73,.33);
    glVertex2f(.73,.4);
    glVertex2f(.68,.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,40,25);
    glVertex2f(.68,.18);
    glVertex2f(.73,.18);
    glVertex2f(.73,.25);
    glVertex2f(.68,.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,40,25);
    glVertex2f(.81,.48);
    glVertex2f(.86,.48);
    glVertex2f(.86,.55);
    glVertex2f(.81,.55);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,40,25);
    glVertex2f(.81,.33);
    glVertex2f(.86,.33);
    glVertex2f(.86,.4);
    glVertex2f(.81,.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(30,40,25);
    glVertex2f(.81,.18);
    glVertex2f(.86,.18);
    glVertex2f(.86,.25);
    glVertex2f(.81,.25);
    glEnd();

    //building-2
    //structure
    glBegin(GL_QUADS);
    glColor3ub(255,200,140);
    glVertex2f(.3,.1);
    glVertex2f(.53,.1);
    glVertex2f(.53,.55);
    glVertex2f(.3,.55);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(125,55,0);
    glVertex2f(.3,.55);
    glVertex2f(.53,.55);
    glVertex2f(.53,.57);
    glVertex2f(.3,.57);
    glEnd();

    //windows
    glBegin(GL_QUADS);
    glColor3ub(50,70,125);
    glVertex2f(.32,.18);
    glVertex2f(.51,.18);
    glVertex2f(.51,.25);
    glVertex2f(.32,.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,70,125);
    glVertex2f(.32,.27);
    glVertex2f(.51,.27);
    glVertex2f(.51,.34);
    glVertex2f(.32,.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,70,125);
    glVertex2f(.32,.36);
    glVertex2f(.51,.36);
    glVertex2f(.51,.43);
    glVertex2f(.32,.43);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,70,125);
    glVertex2f(.32,.45);
    glVertex2f(.51,.45);
    glVertex2f(.51,.52);
    glVertex2f(.32,.52);
    glEnd();

    //door
    glBegin(GL_QUADS);
    glColor3ub(112, 48, 70);
    glVertex2f(.35,.16);
    glVertex2f(.48,.16);
    glVertex2f(.48,.1);
    glVertex2f(.35,.1);
    glEnd();


    //building-3
    //structure
    glBegin(GL_QUADS);
    glColor3ub(255, 155, 60);
    glVertex2f(.08,.1);
    glVertex2f(.27,.1);
    glVertex2f(.27,.3);
    glVertex2f(.08,.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(125,55,0);
    glVertex2f(.08,.3);
    glVertex2f(.27,.3);
    glVertex2f(.27,.32);
    glVertex2f(.08,.32);
    glEnd();

    //windows
    glBegin(GL_QUADS);
    glColor3ub(50,80,225);
    glVertex2f(.09,.17);
    glVertex2f(.14,.17);
    glVertex2f(.14,.29);
    glVertex2f(.09,.29);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,80,225);
    glVertex2f(.15,.17);
    glVertex2f(.2,.17);
    glVertex2f(.2,.29);
    glVertex2f(.15,.29);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(50,80,225);
    glVertex2f(.21,.17);
    glVertex2f(.26,.17);
    glVertex2f(.26,.29);
    glVertex2f(.21,.29);
    glEnd();

    //door
    glBegin(GL_QUADS);
    glColor3ub(112, 48, 0);
    glVertex2f(.13,.15);
    glVertex2f(.22,.15);
    glVertex2f(.22,.1);
    glVertex2f(.13,.1);
    glEnd();

    //flag
    glBegin(GL_QUADS);
    glColor3ub(200,120,0);
    glVertex2f(.12,.32);
    glVertex2f(.11,.32);
    glVertex2f(.11,.45);
    glVertex2f(.12,.45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(7,100,0);
    glVertex2f(.22,.36);
    glVertex2f(.12,.36);
    glVertex2f(.12,.45);
    glVertex2f(.22,.45);
    glEnd();

    glColor3ub(255,0,0);
    FilledCircle(.165,.405,.025,100);

    //building-4
    //structure
    glBegin(GL_QUADS);
    glColor3ub(255,200,140);
    glVertex2f(-.7,.1);
    glVertex2f(-.93,.1);
    glVertex2f(-.93,.45);
    glVertex2f(-.7,.45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25,55,0);
    glVertex2f(-.7,.45);
    glVertex2f(-.93,.45);
    glVertex2f(-.93,.47);
    glVertex2f(-.7,.47);
    glEnd();

    //windows
    glBegin(GL_QUADS);
    glColor3ub(70,90,150);
    glVertex2f(-.72,.18);
    glVertex2f(-.91,.18);
    glVertex2f(-.91,.25);
    glVertex2f(-.72,.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(70,90,150);
    glVertex2f(-.72,.27);
    glVertex2f(-.91,.27);
    glVertex2f(-.91,.34);
    glVertex2f(-.72,.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(70,90,150);
    glVertex2f(-.72,.36);
    glVertex2f(-.91,.36);
    glVertex2f(-.91,.43);
    glVertex2f(-.72,.43);
    glEnd();

    //door
    glBegin(GL_QUADS);
    glColor3ub(112, 48, 0);
    glVertex2f(-.75,.16);
    glVertex2f(-.88,.16);
    glVertex2f(-.88,.1);
    glVertex2f(-.75,.1);
    glEnd();
}

void night_buildings()
{
    //building-1
    //structure
    glBegin(GL_QUADS);
    glColor3ub(180,180,255);
    glVertex2f(.65,.1);
    glVertex2f(.9,.1);
    glVertex2f(.9,.6);
    glVertex2f(.65,.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(125,55,0);
    glVertex2f(.65,.6);
    glVertex2f(.9,.6);
    glVertex2f(.9,.62);
    glVertex2f(.65,.62);
    glEnd();

    //door
    glBegin(GL_QUADS);
    glColor3ub(102, 18, 50);
    glVertex2f(.72,.16);
    glVertex2f(.82,.16);
    glVertex2f(.82,.1);
    glVertex2f(.72,.1);
    glEnd();

    //windows
    glBegin(GL_QUADS);
    glColor3ub(70,90,25);
    glVertex2f(.76,.16);
    glVertex2f(.78,.16);
    glVertex2f(.78,.6);
    glVertex2f(.76,.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.68,.48);
    glVertex2f(.73,.48);
    glVertex2f(.73,.55);
    glVertex2f(.68,.55);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.68,.33);
    glVertex2f(.73,.33);
    glVertex2f(.73,.4);
    glVertex2f(.68,.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.68,.18);
    glVertex2f(.73,.18);
    glVertex2f(.73,.25);
    glVertex2f(.68,.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.81,.48);
    glVertex2f(.86,.48);
    glVertex2f(.86,.55);
    glVertex2f(.81,.55);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.81,.33);
    glVertex2f(.86,.33);
    glVertex2f(.86,.4);
    glVertex2f(.81,.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.81,.18);
    glVertex2f(.86,.18);
    glVertex2f(.86,.25);
    glVertex2f(.81,.25);
    glEnd();

    //building-2
    //structure
    glBegin(GL_QUADS);
    glColor3ub(255,200,140);
    glVertex2f(.3,.1);
    glVertex2f(.53,.1);
    glVertex2f(.53,.55);
    glVertex2f(.3,.55);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(125,55,0);
    glVertex2f(.3,.55);
    glVertex2f(.53,.55);
    glVertex2f(.53,.57);
    glVertex2f(.3,.57);
    glEnd();

    //windows
    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.32,.18);
    glVertex2f(.51,.18);
    glVertex2f(.51,.25);
    glVertex2f(.32,.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.32,.27);
    glVertex2f(.51,.27);
    glVertex2f(.51,.34);
    glVertex2f(.32,.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.32,.36);
    glVertex2f(.51,.36);
    glVertex2f(.51,.43);
    glVertex2f(.32,.43);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.32,.45);
    glVertex2f(.51,.45);
    glVertex2f(.51,.52);
    glVertex2f(.32,.52);
    glEnd();

    //door
    glBegin(GL_QUADS);
    glColor3ub(112, 48, 70);
    glVertex2f(.35,.16);
    glVertex2f(.48,.16);
    glVertex2f(.48,.1);
    glVertex2f(.35,.1);
    glEnd();

    //building-3
    //structure
    glBegin(GL_QUADS);
    glColor3ub(255, 155, 60);
    glVertex2f(.08,.1);
    glVertex2f(.27,.1);
    glVertex2f(.27,.3);
    glVertex2f(.08,.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(125,55,0);
    glVertex2f(.08,.3);
    glVertex2f(.27,.3);
    glVertex2f(.27,.32);
    glVertex2f(.08,.32);
    glEnd();

    //windows
    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.09,.17);
    glVertex2f(.14,.17);
    glVertex2f(.14,.29);
    glVertex2f(.09,.29);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.15,.17);
    glVertex2f(.2,.17);
    glVertex2f(.2,.29);
    glVertex2f(.15,.29);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(.21,.17);
    glVertex2f(.26,.17);
    glVertex2f(.26,.29);
    glVertex2f(.21,.29);
    glEnd();

    //door
    glBegin(GL_QUADS);
    glColor3ub(112, 48, 0);
    glVertex2f(.13,.15);
    glVertex2f(.22,.15);
    glVertex2f(.22,.1);
    glVertex2f(.13,.1);
    glEnd();

    //flag
    glBegin(GL_QUADS);
    glColor3ub(200,120,0);
    glVertex2f(.12,.32);
    glVertex2f(.11,.32);
    glVertex2f(.11,.45);
    glVertex2f(.12,.45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(7,100,0);
    glVertex2f(.22,.36);
    glVertex2f(.12,.36);
    glVertex2f(.12,.45);
    glVertex2f(.22,.45);
    glEnd();

    glColor3ub(255,0,0);
    FilledCircle(.165,.405,.025,100);

    //building-4
    //structure
    glBegin(GL_QUADS);
    glColor3ub(255,200,140);
    glVertex2f(-.7,.1);
    glVertex2f(-.93,.1);
    glVertex2f(-.93,.45);
    glVertex2f(-.7,.45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25,55,0);
    glVertex2f(-.7,.45);
    glVertex2f(-.93,.45);
    glVertex2f(-.93,.47);
    glVertex2f(-.7,.47);
    glEnd();

    //windows
    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(-.72,.18);
    glVertex2f(-.91,.18);
    glVertex2f(-.91,.25);
    glVertex2f(-.72,.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(-.72,.27);
    glVertex2f(-.91,.27);
    glVertex2f(-.91,.34);
    glVertex2f(-.72,.34);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,102);
    glVertex2f(-.72,.36);
    glVertex2f(-.91,.36);
    glVertex2f(-.91,.43);
    glVertex2f(-.72,.43);
    glEnd();

    //door
    glBegin(GL_QUADS);
    glColor3ub(112, 48, 0);
    glVertex2f(-.75,.16);
    glVertex2f(-.88,.16);
    glVertex2f(-.88,.1);
    glVertex2f(-.75,.1);
    glEnd();
}

void windmill_on()
{
    glTranslatef(.23,0,0);
    glBegin(GL_QUADS);
    glColor3ub(180, 180, 180);
    glVertex2f(-.49,.1);
    glVertex2f(-.47,.1);
    glVertex2f(-.39,.4);
    glVertex2f(-.41,.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(180, 180, 180);
    glVertex2f(-.33,.1);
    glVertex2f(-.31,.1);
    glVertex2f(-.39,.4);
    glVertex2f(-.41,.4);
    glEnd();

    init();

    glPushMatrix();

    glTranslatef(-.17,.4,0);
    glRotatef(windmillSpeed,0,0,-1);
    glRotatef(120,0,0,1);

    glColor3ub(0, 0, 0);
    LineCircle(-.0,.0,.15,100);

    glColor3ub(0, 0, 255);
    LineCircle(0,0,.13,100);

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-.4f+.4,.4f-.4);
    glVertex2f(-.53f+.4,.4f-.4);
    glVertex2f(-.4f+.4,.4f-.4);
    glVertex2f(-.27f+.4,.4f-.4);
    glVertex2f(-.4f+.4,.4f-.4);
    glVertex2f(-.4f+.4,.27f-.4);
    glVertex2f(-.4f+.4,.4f-.4);
    glVertex2f(-.4f+.4,.53f-.4);
    glVertex2f(-.4f+.4,.4f-.4);
    glVertex2f(-.49f+.4,.31f-.4);
    glVertex2f(-.4f+.4,.4f-.4);
    glVertex2f(-.49f+.4,.5f-.4);
    glVertex2f(-.4f+.4,.4f-.4);
    glVertex2f(-.3f+.4,.31f-.4);
    glVertex2f(-.4f+.4,.4f-.4);
    glVertex2f(-.3f+.4,.48f-.4);
    glEnd();

    glColor3ub(185,50,50);
    FilledCircle(-.0,.0,.02,100);

    windmillSpeed+=.4;
    glPopMatrix();
}

void windmill_off()
{
    glTranslatef(.23,0,0);
    glBegin(GL_QUADS);
    glColor3ub(180, 180, 180);
    glVertex2f(-.49,.1);
    glVertex2f(-.47,.1);
    glVertex2f(-.39,.4);
    glVertex2f(-.41,.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(180, 180, 180);
    glVertex2f(-.33,.1);
    glVertex2f(-.31,.1);
    glVertex2f(-.39,.4);
    glVertex2f(-.41,.4);
    glEnd();

    glColor3ub(0, 0, 0);
    LineCircle(-.4,.4,.15,100);

    glColor3ub(0, 0, 255);
    LineCircle(-.4,.4,.13,100);

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-.4f,.4f);
    glVertex2f(-.53f,.4f);
    glVertex2f(-.4f,.4f);
    glVertex2f(-.27f,.4f);
    glVertex2f(-.4f,.4f);
    glVertex2f(-.4f,.27f);
    glVertex2f(-.4f,.4f);
    glVertex2f(-.4f,.53f);
    glVertex2f(-.4f,.4f);
    glVertex2f(-.49f,.31f);
    glVertex2f(-.4f,.4f);
    glVertex2f(-.49f,.5f);
    glVertex2f(-.4f,.4f);
    glVertex2f(-.3f,.31f);
    glVertex2f(-.4f,.4f);
    glVertex2f(-.3f,.48f);
    glEnd();

    glColor3ub(185,50,50);
    FilledCircle(-.4,.4,.02,100);

    init();
}

void lake()
{
    //water
    glTranslatef(0,-.82,0);
    glBegin(GL_QUADS);
    glColor3ub(111, 200, 228);
    glVertex2f(-1.0,-.18);
    glVertex2f(1.0,-.18);
    glVertex2f(1.0,.01);
    glVertex2f(-1.0,.01);
    glEnd();

    //opposite side
    glColor3ub(180,180,180);
    HalfCircle(-.9,-.18,-.1);
    HalfCircle(-.7,-.18,-.1);
    HalfCircle(-.5,-.18,-.1);
    HalfCircle(-.3,-.18,-.1);
    HalfCircle(-.1,-.18,-.1);
    HalfCircle(.1,-.18,-.1);
    HalfCircle(.3,-.18,-.1);
    HalfCircle(.5,-.18,-.1);
    HalfCircle(.7,-.18,-.1);
    HalfCircle(.9,-.18,-.1);

    glColor3ub(150,150,150);
    HalfCircle(-.9,-.18,-.07);
    HalfCircle(-.7,-.18,-.07);
    HalfCircle(-.5,-.18,-.07);
    HalfCircle(-.3,-.18,-.07);
    HalfCircle(-.1,-.18,-.07);
    HalfCircle(.1,-.18,-.07);
    HalfCircle(.3,-.18,-.07);
    HalfCircle(.5,-.18,-.07);
    HalfCircle(.7,-.18,-.07);
    HalfCircle(.9,-.18,-.07);

    //road side
    HalfCircle(-.95,.01,-.06);
    HalfCircle(-.83,.01,-.06);
    HalfCircle(-.71,.01,-.06);
    HalfCircle(-.59,.01,-.06);
    HalfCircle(-.47,.01,-.06);
    HalfCircle(-.35,.01,-.06);
    HalfCircle(-.23,.01,-.06);
    HalfCircle(-.11,.01,-.06);
    HalfCircle(.01,.01,-.06);
    HalfCircle(.13,.01,-.06);
    HalfCircle(.25,.01,-.06);
    HalfCircle(.37,.01,-.06);
    HalfCircle(.49,.01,-.06);
    HalfCircle(.61,.01,-.06);
    HalfCircle(.73,.01,-.06);
    HalfCircle(.85,.01,-.06);
    HalfCircle(.97,.01,-.06);

    init();
}

void night_lake()
{
    //water
    glTranslatef(0,-.82,0);
    glBegin(GL_QUADS);
    glColor3ub(50, 140, 180);
    glVertex2f(-1.0,-.18);
    glVertex2f(1.0,-.18);
    glVertex2f(1.0,.01);
    glVertex2f(-1.0,.01);
    glEnd();

    //opposite side
    glColor3ub(180,180,180);
    HalfCircle(-.9,-.18,-.1);
    HalfCircle(-.7,-.18,-.1);
    HalfCircle(-.5,-.18,-.1);
    HalfCircle(-.3,-.18,-.1);
    HalfCircle(-.1,-.18,-.1);
    HalfCircle(.1,-.18,-.1);
    HalfCircle(.3,-.18,-.1);
    HalfCircle(.5,-.18,-.1);
    HalfCircle(.7,-.18,-.1);
    HalfCircle(.9,-.18,-.1);

    glColor3ub(150,150,150);
    HalfCircle(-.9,-.18,-.07);
    HalfCircle(-.7,-.18,-.07);
    HalfCircle(-.5,-.18,-.07);
    HalfCircle(-.3,-.18,-.07);
    HalfCircle(-.1,-.18,-.07);
    HalfCircle(.1,-.18,-.07);
    HalfCircle(.3,-.18,-.07);
    HalfCircle(.5,-.18,-.07);
    HalfCircle(.7,-.18,-.07);
    HalfCircle(.9,-.18,-.07);

    //road side
    HalfCircle(-.95,.01,-.06);
    HalfCircle(-.83,.01,-.06);
    HalfCircle(-.71,.01,-.06);
    HalfCircle(-.59,.01,-.06);
    HalfCircle(-.47,.01,-.06);
    HalfCircle(-.35,.01,-.06);
    HalfCircle(-.23,.01,-.06);
    HalfCircle(-.11,.01,-.06);
    HalfCircle(.01,.01,-.06);
    HalfCircle(.13,.01,-.06);
    HalfCircle(.25,.01,-.06);
    HalfCircle(.37,.01,-.06);
    HalfCircle(.49,.01,-.06);
    HalfCircle(.61,.01,-.06);
    HalfCircle(.73,.01,-.06);
    HalfCircle(.85,.01,-.06);
    HalfCircle(.97,.01,-.06);

    init();
}

void boat()
{
    glPushMatrix();

    glTranslatef(boatPosition,-0.79f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(255,255,130);
    glVertex2f(.2,-.042);
    glVertex2f(.3,-.095);
    glVertex2f(.45,-.095);
    glVertex2f(.55,-.042);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 140, 220);
    glVertex2f(.3,-.042);
    glVertex2f(.34,-.042);
    glVertex2f(.34,0);
    glVertex2f(.3,.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 140, 220);
    glVertex2f(.35,-.042);
    glVertex2f(.39,-.042);
    glVertex2f(.39,0);
    glVertex2f(.35,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 140, 220);
    glVertex2f(.4,-.042);
    glVertex2f(.44,-.042);
    glVertex2f(.44,.1);
    glVertex2f(.4,0);
    glEnd();

    glPushMatrix();
}

void morning()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	init();

    morningSky();
    sun();
    ground();
    tree();
    railway();
    road();
    car();
    buildings();
    windmill_off();
    lake();
    snow();

	glFlush();
}

void day()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	init();

    daySky();
    cloud();
    ground();
    tree();
    buildings();
    windmill_on();
    railway();
    train();
    road();
    car();
    microbus();
    bus();
    lake();
    boat();

	glFlush();
}

void night()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	init();

    nightSky();
    moon();
    night_cloud();
    plane();
    ground();
    tree();
    night_buildings();
    windmill_off();
    railway();
    night_train();
    road();
    car();
    night_car();
    night_bus();
    night_lake();

	glFlush();
}

void idle()
{
   glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("HRIDOY'S City");
	glutReshapeWindow(1280,680);
	glutDisplayFunc(morning);
	morningsound();
    glutIdleFunc(idle);
    glutTimerFunc(30, snowup, 0);
    glutTimerFunc(30, planeup, 0);
    glutTimerFunc(30, trainup, 0);
    glutTimerFunc(30, boatup, 0);
    glutTimerFunc(30, rightup, 0);
    glutTimerFunc(30, leftup, 0);
    glutKeyboardFunc(controlkeyboard);

	glutMainLoop();
	return 0;
}
