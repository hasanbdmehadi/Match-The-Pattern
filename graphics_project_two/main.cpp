/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<windows.h>
#include<bits/stdc++.h>
#include<malloc.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
#include <stdlib.h>
using namespace std;

float angle=90, rotateFlag = 0, x_tran = 0, y_tran = 270,cnt=0;
int fl=0,cir_fl=1,pent_fl=1,star_fl=1,rect_fl=1,tri_fl=1,ttcnt=11,tccnt=1;
int cc=3,pp=4,ss=1,rr=2,tt=0;
int sct=0;
int hm=0,nm=1,sm=0;
int mcnt=5;
int res=0;
int up=0,start=1;


int isLeftKeyPressed,isRightKeyPressed;

void arrow()
{
     glLineWidth(2.0);
    glBegin(GL_LINE_STRIP) ;

		glVertex3f( -1.0 , -8.0 , 0.0 ) ;
		glVertex3f( 1.0 , -8.0 , 0.0 ) ;
		glVertex3f( 1.0 , 10.0 , 0.0 ) ;
		glVertex3f( 3.0 , 8.0 , 0.0 ) ;
		glVertex3f( 4.0 , 9.0 , 0.0 ) ;
		glVertex3f( 0.0 , 13.0 , 0.0 ) ;
		glVertex3f( -4.0 , 9.0 , 0.0 ) ;
		glVertex3f( -3.0 , 8.0 , 0.0 ) ;
		glVertex3f( -1.0 , 10.0 , 0.0 ) ;
		glVertex3f( -1.0 , -8.0 , 0.0 ) ;

	glEnd() ;
}


void drawRec(float on, float tw, float th, float ulx, float uly, float urx, float ury, float drx, float dry, float dlx, float dly){

	glBegin(GL_LINE_STRIP) ;

		glColor3f( on , tw , th ) ;
		glVertex3f( ulx , uly , 0.0 ) ;
		glVertex3f( urx , ury , 0.0 ) ;
		glVertex3f( drx , dry , 0.0 ) ;
		glVertex3f( dlx , dly , 0.0 ) ;
		glVertex3f( ulx , uly , 0.0) ;

	glEnd() ;

}

void circle(float cx=0.0, float cy=0.0, float r=60.0)
{
    int num=30;
    float pi=3.01416;
    glLineWidth(5.0);

    int red=1, bl=0, gr=0;

    glBegin(GL_TRIANGLE_FAN);
    for(int i=0;i<=num;i++)
    {
        float theta = 2.0*pi*float(i)/float(num);
        float x= r*cosf(theta);
        float y= r*sinf(theta);

        glVertex2d(x+cx,y+cy);
    }
    glEnd();
}

void triangle()
{
    glColor3f( 1.0 , 1.0 , 0.0 ) ;
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2d(-5,-10);
        glVertex2d(8,0);
        glVertex2d(-5,10);
    glEnd();
}

void star()
{
    glColor3f( 1.0 , 1.0 , 0.0 ) ;
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2d(-10,0);
        glVertex2d(5,-10);
        glVertex2d(5,10);
    glEnd();

    glColor3f( 1.0 , 1.0 , 0.0 ) ;
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2d(-5,-10);
        glVertex2d(10,0);
        glVertex2d(-5,10);
    glEnd();
}

void rectangle()
{
    glColor3f( 1.0 , 1.0 , 0.0 ) ;
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2d(-10,5);
        glVertex2d(-10,-5);
        glVertex2d(10,-5);
    glEnd();

    glColor3f( 1.0 , 1.0 , 0.0 ) ;
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2d(-10,5);
        glVertex2d(10,5);
        glVertex2d(10,-5);
    glEnd();

}

void pentagon()
{
    glColor3f( 1.0 , 1.0 , 0.0 ) ;
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2d(-10,10);
        glVertex2d(-10,-10);
        glVertex2d(0,10);
    glEnd();

    glColor3f( 1.0 , 1.0 , 0.0 ) ;
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2d(0,10);
        glVertex2d(-10,-10);
        glVertex2d(0,-10);
    glEnd();

    glColor3f( 1.0 , 1.0 , 0.0 ) ;
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2d(0,10);
        glVertex2d(0,-10);
        glVertex2d(12,0);
    glEnd();
}

void comtri()
{
    glPushMatrix();
	    glRotatef(angle,0,0,1);
        glTranslatef(cnt,0,0);
        glScaled(5.0,5.0,0.0);
        triangle();
    glPopMatrix();
}

void comstar()
{
    glPushMatrix();
	    glRotatef(angle,0,0,1);
        glTranslatef(cnt,0,0);
        glScaled(5.0,5.0,0.0);
        star();
    glPopMatrix();
}

void comrect()
{
    glPushMatrix();
	    glRotatef(angle,0,0,1);
        glTranslatef(cnt,0,0);
        glScaled(5.0,5.0,0.0);
        rectangle();
    glPopMatrix();
}

void comcir()
{
    glColor3f( 1.0 , 1.0 , 0.0 ) ;
    glPushMatrix();
	    glRotatef(angle,0,0,1);
        glTranslatef(cnt,0,0);
        //glScaled(5.0,5.0,0.0);
        circle(0,0,40);
        glColor3f( 1.0 , 0.0 , 0.0 ) ;
        circle(0,0,30);
    glPopMatrix();
}

void compent()
{
    glPushMatrix();
	    glRotatef(angle,0,0,1);
        glTranslatef(cnt,0,0);
        glScaled(4.0,4.0,0.0);
        pentagon();
    glPopMatrix();
}

void things(int num)
{
    if(num==0)comtri();
    if(num==1)comstar();
    if(num==2)comrect();
    if(num==3)comcir();
    if(num==4)compent();
}

void mouth(float x, float y, float radius){
    int i=10;
    double twicePi = 2.0 * 3.142;
    float dx , dy ;
    int seg = 100;
    int j=seg-30;
    glPointSize(4);
    glBegin(GL_POINTS); //BEGIN CIRCLE
    //glVertex2f(x, y); // center of circle
    while(i<j)
        {
            dx=radius * cos(i * twicePi / seg);
            dy=radius * sin(i * twicePi / seg);
            glVertex2f (x + dx, y + dy);
            i++;
            j--;
        }
    glEnd();
}

void ques()
{
    glLineWidth(2.0);
    glBegin(GL_LINE_STRIP);
        glVertex2d(-2,1);
        glVertex2d(-2,2);
        glVertex2d(-1,3);
        glVertex2d(1,3);
        glVertex2d(2,2);
        glVertex2d(2,1);
        glVertex2d(-1,-2);
        glVertex2d(-1,-4);
        glVertex2d(1,-4);
        glVertex2d(1,-2);
        glVertex2d(4,1);
        glVertex2d(4,3);
        glVertex2d(2,5);
        glVertex2d(-2,5);
        glVertex2d(-4,3);
        glVertex2d(-4,1);
        glVertex2d(-2,1);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex2d(-1,-5);
        glVertex2d(-1,-7);
        glVertex2d(1,-7);
        glVertex2d(1,-5);
        glVertex2d(-1,-5);
    glEnd();
}

void hmouth()
{
    glPushMatrix();
        glTranslatef(300,-335,0);
	    glRotatef(90+90,0,0,1);
        mouth(0,0,100);
    glPopMatrix();
}

void smouth()
{
    mouth(300,-520,100);
}

void normouth()
{
    glBegin(GL_LINE_STRIP) ;
		glColor3f( 1.0 , -1.0 , 0.0 ) ;
		glVertex3f( 260 , -415 , 0 ) ;
		glVertex3f( 340 , -415 , 0 ) ;
	glEnd() ;

	glPushMatrix();
        glTranslatef(300,-145,0);
        glScaled(7,7,0);
        ques();
    glPopMatrix();

}

void smiley()
{
    //full face
    circle(300,-365,150);
    glColor3f( 1.0 , 0.0 , 0.0 ) ;
    //eye
    circle(220,-320,17);
    circle(380,-320,17);
    //mouth
    if(sm==0)normouth();
    if(sm==2)smouth();
    if(sm==1)hmouth();

}

void score()
{
    //S
    glBegin(GL_LINE_STRIP) ;
		glVertex2f( -13 , 2 ) ;
		glVertex2f( -15 , 4 ) ;
		glVertex2f( -17 , 4 ) ;
		glVertex2f( -19 , 2 ) ;
		glVertex2f( -13 , -2 ) ;
		glVertex2f( -15 , -4 ) ;
		glVertex2f( -17 , -4 ) ;
		glVertex2f( -19 , -2 ) ;
	glEnd() ;

	//C
	glBegin(GL_LINE_STRIP) ;
		glVertex2f( -5 , 2 ) ;
		glVertex2f( -6 , 2 ) ;
		glVertex2f( -6 , 1 ) ;
		glVertex2f( -5 , 1 ) ;
		glVertex2f( -5 , 2 ) ;
		glVertex2f( -7 , 4 ) ;
		glVertex2f( -9 , 4 ) ;
		glVertex2f( -11 , 2 ) ;
		glVertex2f( -11 , -2 ) ;
		glVertex2f( -9 , -4 ) ;
		glVertex2f( -7 , -4 ) ;
		glVertex2f( -5 , -2 ) ;
	glEnd() ;

	//O
	glBegin(GL_LINE_STRIP) ;
		glVertex2f( 1 , 4 ) ;
		glVertex2f( -1 , 4 ) ;
		glVertex2f( -3 , 2 ) ;
		glVertex2f( -3 , -2 ) ;
		glVertex2f( -1 , -4 ) ;
		glVertex2f( 1 , -4 ) ;
		glVertex2f( 3 , -2 ) ;
		glVertex2f( 3 , 2 ) ;
		glVertex2f( 1 , 4 ) ;
	glEnd() ;

	//R
	glBegin(GL_LINE_STRIP) ;
		glVertex2f( 5 , -4 ) ;
		glVertex2f( 5 , 4 ) ;
		glVertex2f( 8 , 4 ) ;
		glVertex2f( 9 , 3 ) ;
		glVertex2f( 9 , 1 ) ;
		glVertex2f( 8 , 0 ) ;
		glVertex2f( 5 , 0 ) ;
		glVertex2f( 6 , 0 ) ;
		glVertex2f( 10 , -4 ) ;
	glEnd() ;

	//E
	glBegin(GL_LINE_STRIP) ;
		glVertex2f( 15 , 4 ) ;
		glVertex2f( 11 , 4 ) ;
		glVertex2f( 11 , -4 ) ;
		glVertex2f( 15 , -4 ) ;
		glVertex2f( 11 , -4 ) ;
		glVertex2f( 11 , 0 ) ;
		glVertex2f( 13 , 0 ) ;
	glEnd() ;

	//DOT
	glBegin(GL_LINE_STRIP) ;
		glVertex2f( 17 , 3 ) ;
		glVertex2f( 19 , 3 ) ;
		glVertex2f( 19 , 1 ) ;
		glVertex2f( 17 , 1 ) ;
		glVertex2f( 17 , 3 ) ;
	glEnd() ;

	glBegin(GL_LINE_STRIP) ;
		glVertex2f( 17 , -1 ) ;
		glVertex2f( 19 , -1 ) ;
		glVertex2f( 19 , -3 ) ;
		glVertex2f( 17 , -3 ) ;
		glVertex2f( 17 , -1 ) ;
	glEnd() ;




}

void fullscore()
{
    glLineWidth(2.0);
    glPushMatrix();
        glTranslatef(-380,-210,0);
        glScaled(10,10,0);
        score();
    glPopMatrix();
}

void zero()
{
    glBegin(GL_LINE_STRIP) ;
		glVertex2f( -1 , 4 ) ;
		glVertex2f( -3 , 2 ) ;
		glVertex2f( -3 , -2 ) ;
		glVertex2f( -1 , -4 ) ;
		glVertex2f( 1 , -4 ) ;
		glVertex2f( 3 , -2 ) ;
		glVertex2f( 3 , 2 ) ;
		glVertex2f( 1 , 4 ) ;
		glVertex2f( -1 , 4 ) ;
    glEnd();
    glBegin(GL_LINE_STRIP);
		glVertex2f( -1 , 5 ) ;
		glVertex2f( -4 , 2 ) ;
		glVertex2f( -4 , -2 ) ;
		glVertex2f( -1 , -5 ) ;
		glVertex2f( 1 , -5 ) ;
		glVertex2f( 4 , -2 ) ;
		glVertex2f( 4 , 2 ) ;
		glVertex2f( 1 , 5 ) ;
		glVertex2f( -1 , 5 ) ;
	glEnd() ;
}

void one()
{
    glBegin(GL_LINE_STRIP) ;
		glVertex2f( -4 , 3 ) ;
		glVertex2f( -2 , 5 ) ;
		glVertex2f( 1 , 5 ) ;
		glVertex2f( 1 , -4 ) ;
		glVertex2f( 3 , -4 ) ;
		glVertex2f( 3 , -6 ) ;
		glVertex2f( -3 , -6 ) ;
		glVertex2f( -3 , -4 ) ;
		glVertex2f( -1 , -4 ) ;
		glVertex2f( -1 , 3 ) ;
		glVertex2f( -4 , 1 ) ;
		glVertex2f( -4 , 3 ) ;
	glEnd() ;
}

void two()
{
    glBegin(GL_LINE_STRIP) ;
		glVertex2f( 3 , -4 ) ;
		glVertex2f( 3 , -5 ) ;
		glVertex2f( -4 , -5 ) ;
		glVertex2f( -4 , -3 ) ;
		glVertex2f( 2 , 2 ) ;
		glVertex2f( 2 , 3 ) ;
		glVertex2f( 1 , 4 ) ;
		glVertex2f( -2 , 4 ) ;
		glVertex2f( -3 , 3 ) ;
		glVertex2f( -3 , 2 ) ;
		glVertex2f( -4 , 2 ) ;
		glVertex2f( -4 , 3 ) ;
		glVertex2f( -2 , 5 ) ;
		glVertex2f( 1 , 5 ) ;
		glVertex2f( 3 , 3 ) ;
		glVertex2f( 3 , 1 ) ;
		glVertex2f( -3 , -4 ) ;
		glVertex2f( 3 , -4 ) ;
		glVertex2f( 3 , -5 ) ;
	glEnd() ;
}

void three()
{
    glBegin(GL_LINE_STRIP) ;
		glVertex2f( -3 , 2 ) ;
		glVertex2f( -3 , 3 ) ;
		glVertex2f( -2 , 4 ) ;
		glVertex2f( 0 , 4 ) ;
		glVertex2f( 1 , 3 ) ;
		glVertex2f( 1 , 2 ) ;
		glVertex2f( -1 , 0 ) ;
		glVertex2f( 1 , -2 ) ;
		glVertex2f( 1 , -3 ) ;
		glVertex2f( 0 , -4 ) ;
		glVertex2f( -2 , -4 ) ;
		glVertex2f( -3 , -3 ) ;
		glVertex2f( -3 , -2 ) ;
		glVertex2f( -4 , -2 ) ;
		glVertex2f( -4 , -3 ) ;
		glVertex2f( -2 , -5 ) ;
		glVertex2f( 0 , -5 ) ;
		glVertex2f( 2 , -3 ) ;
		glVertex2f( 2 , -2 ) ;
		glVertex2f( 0 , 0 ) ;
		glVertex2f( 2 , 2 ) ;
		glVertex2f( 2 , 3 ) ;
		glVertex2f( 0 , 5 ) ;
		glVertex2f( -2 , 5 ) ;
        glVertex2f( -4 , 3 ) ;
		glVertex2f( -4 , 2 ) ;
		glVertex2f( -3 , 2 ) ;
	glEnd() ;
}
void four()
{
    glBegin(GL_LINE_STRIP) ;
		glVertex2f( 0 , -4 ) ;
		glVertex2f( 1 , -4 ) ;
		glVertex2f( 1 , -2 ) ;
		glVertex2f( 2 , -2 ) ;
		glVertex2f( 2 , -1 ) ;
		glVertex2f( 1 , -1 ) ;
		glVertex2f( 1 , 4 ) ;
		glVertex2f( 0 , 4 ) ;
		glVertex2f( -5 , -1 ) ;
		glVertex2f( -5 , -2 ) ;
		glVertex2f( 0 , -2 ) ;
		glVertex2f( 0 , -4 ) ;
	glEnd() ;

	glBegin(GL_LINE_STRIP) ;
		glVertex2f( 0 , -1 ) ;
		glVertex2f( -4 , -1 ) ;
		glVertex2f( 0 , 3 ) ;
		glVertex2f( 0 , -1 ) ;
	glEnd() ;

}

void five()
{
    glBegin(GL_LINE_STRIP) ;
		glVertex2f( 3 , 4 ) ;
		glVertex2f( 3 , 5 ) ;
		glVertex2f( -3 , 5 ) ;
		glVertex2f( -3 , 0 ) ;
		glVertex2f( -2 , 0 ) ;
		glVertex2f( -1 , 1 ) ;
		glVertex2f( 1 , 1 ) ;
		glVertex2f( 2 , 0 ) ;
		glVertex2f( 2 , -2 ) ;
		glVertex2f( 1 , -3 ) ;
		glVertex2f( -1 , -3 ) ;
		glVertex2f( -2 , -2 ) ;
		glVertex2f( -2 , -1 ) ;
		glVertex2f( -3 , -1 ) ;
		glVertex2f( -3 , -3 ) ;
		glVertex2f( -2 , -4 ) ;
		glVertex2f( 2 , -4 ) ;
		glVertex2f( 3 , -2 ) ;
		glVertex2f( 3 , 0 ) ;
		glVertex2f( 1 , 2 ) ;
		glVertex2f( -1 , 2 ) ;
		glVertex2f( -2 , 1 ) ;
		glVertex2f( -2 , 4 ) ;
		glVertex2f( 3 , 4 ) ;
	glEnd() ;

}

void six()
{
    glBegin(GL_LINE_STRIP);
        glVertex2d(-1,0);
        glVertex2d(-2,-1);
        glVertex2d(-2,-3);
        glVertex2d(-1,-4);
        glVertex2d(1,-4);
        glVertex2d(2,-3);
        glVertex2d(2,-1);
        glVertex2d(1,0);
        glVertex2d(-1,0);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex2d(2,3);
        glVertex2d(2,4);
        glVertex2d(-2,4);
        glVertex2d(-2,1);
        glVertex2d(2,1);
        glVertex2d(3,0);
        glVertex2d(3,-4);
        glVertex2d(2,-5);
        glVertex2d(-2,-5);
        glVertex2d(-3,-4);
        glVertex2d(-3,4);
        glVertex2d(-2,5);
        glVertex2d(2,5);
        glVertex2d(3,4);
        glVertex2d(3,3);
        glVertex2d(2,3);
    glEnd();
}

void seven()
{
    glBegin(GL_LINE_STRIP);
        glVertex2d(-4,3);
        glVertex2d(-4,5);
        glVertex2d(4,5);
        glVertex2d(4,3);
        glVertex2d(0,-5);
        glVertex2d(-2,-5);
        glVertex2d(2,3);
        glVertex2d(-4,3);
    glEnd();

}

void eight()
{
    glBegin(GL_LINE_STRIP);
        glVertex2d(1,1);
        glVertex2d(2,2);
        glVertex2d(2,3);
        glVertex2d(1,4);
        glVertex2d(-1,4);
        glVertex2d(-2,3);
        glVertex2d(-2,2);
        glVertex2d(-1,1);
        glVertex2d(1,1);
    glEnd();

     glBegin(GL_LINE_STRIP);
        glVertex2d(1,-1);
        glVertex2d(2,-2);
        glVertex2d(2,-3);
        glVertex2d(1,-4);
        glVertex2d(-1,-4);
        glVertex2d(-2,-3);
        glVertex2d(-2,-2);
        glVertex2d(-1,-1);
        glVertex2d(1,-1);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex2d(2,0);
        glVertex2d(3,1);
        glVertex2d(3,4);
        glVertex2d(2,5);
        glVertex2d(-2,5);
        glVertex2d(-3,4);
        glVertex2d(-3,1);
        glVertex2d(-2,0);
        glVertex2d(2,0);

        glVertex2d(3,-1);
        glVertex2d(3,-4);
        glVertex2d(2,-5);
        glVertex2d(-2,-5);
        glVertex2d(-3,-4);
        glVertex2d(-3,-1);
        glVertex2d(-2,0);
        glVertex2d(2,0);
    glEnd();

}

void nine()
{
    glPushMatrix();
        glRotated(180,0,0,0);
        six();
	glPopMatrix();

}

void comzero()
{
    glPushMatrix();
        glTranslated(-100,-210,0);
        glScaled(10,10,0);
        zero();
    glPopMatrix();

}

void comone()
{
    glPushMatrix();
        glTranslated(-100,-210,0);
        glScaled(10,10,0);
        one();
    glPopMatrix();
}

void comtwo()
{
    glPushMatrix();
        glTranslated(-100,-210,0);
        glScaled(10,10,0);
        two();
    glPopMatrix();
}

void comthree()
{
    glPushMatrix();
        glTranslated(-100,-210,0);
        glScaled(10,10,0);
        three();
    glPopMatrix();

}

void comfour()
{
    glPushMatrix();
        glTranslated(-100,-210,0);
        glScaled(10,10,0);
        four();
    glPopMatrix();

}

void comfive()
{
    glPushMatrix();
        glTranslated(-100,-210,0);
        glScaled(10,10,0);
        five();
    glPopMatrix();

}

void scorenum(int n)
{
    if(n==0)comzero();
    if(n==1)comone();
    if(n==2)comtwo();
    if(n==3)comthree();
    if(n==4)comfour();
    if(n==5)comfive();
}

void result()
{
    int ps=0;
    if(cir_fl==0)ps++;
    if(pent_fl==0)ps++;
    if(star_fl==0)ps++;
    if(rect_fl==0)ps++;
    if(tri_fl==0)ps++;

     res=ps;
     //tccnt=res;
}

void boundary()
{
    drawRec(1,1,0,-597,597,597,597,597,-597,-597,-597);
	drawRec(0,0,1,-600,600,600,600,600,-600,-600,-600);
	drawRec(0,0,1,-50,30,50,30,100,-100,-100,-100);
	drawRec(0,0,1,-600,-100,600,-100,600,-600,-600,-600);
	drawRec(0,0,1,-3,0,-3,-600,3,-600,3,0);
	drawRec(0,0,1,-600,-100,0,-100,0,-300,-600,-300);
}

void checkcir()
{
        circle(0,y_tran);
        glColor3f( 1.0 , 1.0 , 0.0 ) ;
        glPushMatrix();
            glTranslatef(0,y_tran,0);
            circle(0,0,40);
            glColor3f( 1.0 , 0.0 , 0.0 ) ;
            circle(0,0,30);
        glPopMatrix();
        glColor3f( 1.0 , 0.0 , 0.0 ) ;

}

void checkpent()
{
        circle(-200,538-y_tran+270);
        glPushMatrix();
            glTranslatef(-200,538-y_tran+270,0);
            glRotatef(90,0,0,1);
            glScaled(4.0,4.0,0.0);
            pentagon();
        glPopMatrix();
        glColor3f( 1.0 , 0.0 , 0.0 ) ;

}

void checkstar()
{
        circle(-400,y_tran);
        glPushMatrix();
            glTranslatef(-400,y_tran,0);
            glScaled(5.0,5.0,0.0);
            star();
        glPopMatrix();
        glColor3f( 1.0 , 0.0 , 0.0 ) ;

}

void checkrect()
{
        circle(200,538-y_tran+270);
        glPushMatrix();
            glTranslatef(200,538-y_tran+270,0);
            glRotatef(90,0,0,1);
            glScaled(5.0,5.0,0.0);
            rectangle();
        glPopMatrix();
        glColor3f( 1.0 , 0.0 , 0.0 ) ;
}

void checktri()
{
        glPushMatrix();
            circle(400,y_tran);
            glTranslatef(400,y_tran,0);
            glRotatef(90,0,0,1);
            glScaled(5.0,5.0,0.0);
            triangle();
        glPopMatrix();
        glColor3f( 1.0 , 0.0 , 0.0 ) ;

}

void checkflag()
{
    if(cir_fl==1)checkcir();
    if(pent_fl==1)checkpent();
    if(star_fl==1)checkstar();
    if(rect_fl==1)checkrect();
    if(tri_fl==1)checktri();
}

void mid_cir_and_arrow()
{
    circle(0,0,20);
    glColor3f( 1.0 , 0.0 , 0.0 );
	glPushMatrix();
		glScaled(12.0,12.0,0.0);
		glRotatef(angle-90,0,0,1);
		arrow();
	glPopMatrix();

	glPushMatrix();
		glRotatef(angle,0,0,1);
		glTranslatef(cnt,0,0);
		circle();
	glPopMatrix();
}

void draw_text(const char *text, int length, int x, int y)
{
    glMatrixMode(GL_PROJECTION);
    double *matrix = new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX, matrix);
    glLoadIdentity();
    glOrtho(-600,600,-600,600,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x,y);
    for(int i=0; i<length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);

}


void g()
{
    glBegin(GL_LINE_STRIP) ;
		glVertex2f( 1 , 1 ) ;
		glVertex2f( 5 , 1 ) ;
		glVertex2f( 5 , -3 ) ;
		glVertex2f( 3 , -5 ) ;
		glVertex2f( -3 , -5 ) ;
		glVertex2f( -5 , -3 ) ;
		glVertex2f( -5 , 3 ) ;
		glVertex2f( -3 , 5 ) ;

		glVertex2f( 4 , 5 ) ;

		glVertex2f( 5 , 4 ) ;
		glVertex2f( 4 , 3 ) ;
		glVertex2f( 3 , 3 ) ;

		glVertex2f( -2 , 3 ) ;
		glVertex2f( -3 , 2 ) ;
		glVertex2f( -3 , -2 ) ;
		glVertex2f( -2 , -3 ) ;
		glVertex2f( 2 , -3 ) ;
		glVertex2f( 3 , -2 ) ;
		glVertex2f( 3 , -1 ) ;
		glVertex2f( 1 , -1 ) ;
		glVertex2f( 1 , 1 ) ;
	glEnd() ;
}

void a()
{
    glBegin(GL_LINE_STRIP) ;
		glVertex2f( -1 , 5 ) ;
		glVertex2f( -5 , -5 ) ;
		glVertex2f( -3 , -5 ) ;
		glVertex2f( -2 , -2 ) ;
		glVertex2f( 2 , -2 ) ;
		glVertex2f( 3 , -5 ) ;
		glVertex2f( 5 , -5 ) ;
		glVertex2f( 1 , 5 ) ;
		glVertex2f( -1 , 5 ) ;
    glEnd();

    glBegin(GL_LINE_STRIP);
		glVertex2f( 0 , 3 ) ;
		glVertex2f( -1 , 0 ) ;
		glVertex2f( 1 , 0 ) ;
		glVertex2f( 0 , 3 ) ;
	glEnd() ;
}

void m()
{
    glBegin(GL_LINE_STRIP) ;
		glVertex2f( 0 , -2 ) ;
		glVertex2f( 2 , 5 ) ;
		glVertex2f( 5 , 5 ) ;
		glVertex2f( 5 , -5 ) ;
		glVertex2f( 3 , -5 ) ;
		glVertex2f( 3 , 3 ) ;
		glVertex2f( 1 , -5 ) ;
		glVertex2f( -1 , -5 ) ;
		glVertex2f( -3 , 3 ) ;
		glVertex2f( -3 , -5 ) ;
		glVertex2f( -5 , -5 ) ;
		glVertex2f( -5 , 5 ) ;
		glVertex2f( -2 , 5 ) ;
		glVertex2f( 0 , -2 ) ;
	glEnd() ;
}

void e()
{
    glBegin(GL_LINE_STRIP) ;
		glVertex2f( 2 , 3 ) ;
		glVertex2f( 2 , 5 ) ;
		glVertex2f( -5 , 5 ) ;
		glVertex2f( -5 , -5 ) ;
		glVertex2f( 2 , -5 ) ;
		glVertex2f( 2 , -3 ) ;
		glVertex2f( -3 , -3 ) ;
		glVertex2f( -3 , -1 ) ;
		glVertex2f( 0 , -1 ) ;
		glVertex2f( 0 , 1 ) ;
		glVertex2f( -3 , 1 ) ;
		glVertex2f( -3 , 3 ) ;
		glVertex2f( 2 , 3 ) ;
	glEnd() ;
}

void o()
{
    glBegin(GL_LINE_STRIP) ;
		glVertex2f( -2 , 5 ) ;
		glVertex2f( 2 , 5 ) ;
		glVertex2f( 5 , 2 ) ;
		glVertex2f( 5 , -2 ) ;
		glVertex2f( 2 , -5 ) ;
		glVertex2f( -2 , -5 ) ;
		glVertex2f( -5 , -2 ) ;
		glVertex2f( -5 , 2 ) ;
		glVertex2f( -2 , 5 ) ;
    glEnd();

    glBegin(GL_LINE_STRIP);
		glVertex2f( -1 , 3 ) ;
		glVertex2f( 1 , 3 ) ;
		glVertex2f( 3 , 1 ) ;
		glVertex2f( 3 , -1 ) ;
		glVertex2f( 1 , -3 ) ;
		glVertex2f( -1 , -3 ) ;
		glVertex2f( -3 , -1 ) ;
		glVertex2f( -3 , 1 ) ;
		glVertex2f( -1 , 3 ) ;
	glEnd() ;
}

void v()
{
    glBegin(GL_LINE_STRIP) ;
		glVertex2f( 0 , -3 ) ;
		glVertex2f( 3 , 5 ) ;
		glVertex2f( 5 , 5 ) ;
		glVertex2f( 1 , -5 ) ;
		glVertex2f( -1 , -5 ) ;
		glVertex2f( -5 , 5 ) ;
		glVertex2f( -3 , 5 ) ;
		glVertex2f( 0 , -3 ) ;
	glEnd() ;
}
void r()
{
    glBegin(GL_LINE_STRIP) ;
		glVertex2f( -5 , 5 ) ;
		glVertex2f( 0 , 5 ) ;
		glVertex2f( 2 , 3 ) ;
		glVertex2f( 2 , 0 ) ;
		glVertex2f( 0 , -2 ) ;
		glVertex2f( 3 , -5 ) ;
		glVertex2f( 1 , -5 ) ;
		glVertex2f( -2 , -2 ) ;
		glVertex2f( -3 , -2 ) ;
		glVertex2f( -3 , -5 ) ;
		glVertex2f( -5 , -5 ) ;
		glVertex2f( -5 , 5 ) ;
    glEnd();

    glBegin(GL_LINE_STRIP);
		glVertex2f( -3 , 3 ) ;
		glVertex2f( -1 , 3 ) ;
		glVertex2f( 0 , 2 ) ;
		glVertex2f( 0 , 1 ) ;
		glVertex2f( -1 , 0 ) ;
		glVertex2f( -3 , 0 ) ;
		glVertex2f( -3 , 3 ) ;
	glEnd() ;
}


void comm(int x, int y)
{
    glPushMatrix();
        glTranslated(x,y,0);
        glScaled(15,15,0);
        m();
    glPopMatrix();

}

void comr(int x, int y)
{
    glPushMatrix();
        glTranslated(x,y,0);
        glScaled(15,15,0);
        r();
    glPopMatrix();

}

void comv(int x, int y)
{
    glPushMatrix();
        glTranslated(x,y,0);
        glScaled(15,15,0);
        v();
    glPopMatrix();

}


void coma(int x, int y)
{
    glPushMatrix();
        glTranslated(x,y,0);
        glScaled(15,15,0);
        a();
    glPopMatrix();

}

void comg(int x, int y)
{
    glPushMatrix();
        glTranslated(x,y,0);
        glScaled(15,15,0);
        g();
    glPopMatrix();
}

void como(int x, int y)
{
    glPushMatrix();
        glTranslated(x,y,0);
        glScaled(15,15,0);
        o();
    glPopMatrix();
}

void come(int x, int y)
{
    glPushMatrix();
        glTranslated(x,y,0);
        glScaled(15,15,0);
        e();
    glPopMatrix();
}

void game()
{
    glPushMatrix();
    glTranslated(300,300,0);
    comg(-485,0);
    coma(-340,0);
    comm(-180,0);
    come(-15,0);
    glPopMatrix();

}

void over()
{
    glPushMatrix();
    glTranslated(300,100,0);
    como(-485,0);
    comv(-340,0);
    come(-180,0);
    comr(-55,0);
    glPopMatrix();

}

void gameover()
{
    game();
    over();

}


void values(int vl)
{
    if(vl==0)zero();
    else if(vl==1)one();
    else if(vl==2)two();
    else if(vl==3)three();
    else if(vl==4)four();
    else if(vl==5)five();
    else if(vl==6)six();
    else if(vl==7)seven();
    else if(vl==8)eight();
    else if(vl==9)nine();
}

void timevalue(int p1, int p2)
{
    glPushMatrix();
        glTranslated(-250,-400,0);
        glScaled(10,10,0);
        values(p2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-350,-400,0);
        glScaled(10,10,0);
        values(p1);
    glPopMatrix();

}

void checktime(int t)
{
    if(t<1000)timevalue(0,0);
    else if(t>=1000 && t<2000)timevalue(0,1);
    else if(t>=2000 && t<3000)timevalue(0,2);
    else if(t>=3000 && t<4000)timevalue(0,3);
    else if(t>=4000 && t<5000)timevalue(0,4);
    else if(t>=5000 && t<6000)timevalue(0,5);
    else if(t>=6000 && t<7000)timevalue(0,6);
    else if(t>=7000 && t<8000)timevalue(0,7);
    else if(t>=8000 && t<9000)timevalue(0,8);
    else if(t>=9000 && t<10000)timevalue(0,9);
    else if(t>=10000 && t<11000)timevalue(1,0);
    else if(t>=11000 && t<12000)timevalue(1,1);
    else if(t>=12000 && t<13000)timevalue(1,2);
    else if(t>=13000 && t<14000)timevalue(1,3);
    else if(t>=14000 && t<15000)timevalue(1,4);
    else if(t>=15000 && t<16000)timevalue(1,5);
    else if(t>=16000 && t<17000)timevalue(1,6);
    else if(t>=17000 && t<18000)timevalue(1,7);
    else if(t>=18000 && t<19000)timevalue(1,8);
    else if(t>=19000 && t<20000)timevalue(1,9);
    else if(t>=20000 && t<21000)timevalue(2,0);
    else if(t>=21000 && t<22000)timevalue(2,1);
    else if(t>=22000 && t<23000)timevalue(2,2);
    else if(t>=23000 && t<24000)timevalue(2,3);
    else if(t>=24000 && t<25000)timevalue(2,4);
    else if(t>=25000 && t<26000)timevalue(2,5);
    else if(t>=26000 && t<27000)timevalue(2,6);
    else if(t>=27000 && t<28000)timevalue(2,7);
    else if(t>=28000 && t<29000)timevalue(2,8);
    else if(t>=29000 && t<30000)timevalue(2,9);
    else if(t>=30000 && t<31000)timevalue(3,0);
    else if(t>=31000 && t<32000)timevalue(3,1);
    else if(t>=32000 && t<33000)timevalue(3,2);
    else if(t>=33000 && t<34000)timevalue(3,3);
    else if(t>=34000 && t<35000)timevalue(3,4);
    else if(t>=35000 && t<36000)timevalue(3,5);
    else if(t>=36000 && t<37000)timevalue(3,6);
    else if(t>=37000 && t<38000)timevalue(3,7);
    else if(t>=38000 && t<39000)timevalue(3,8);
    else if(t>=39000 && t<40000)timevalue(3,9);
    else if(t>=40000 && t<41000)timevalue(4,0);
    else if(t>=41000 && t<42000)timevalue(4,1);
    else if(t>=42000 && t<43000)timevalue(4,2);
    else if(t>=43000 && t<44000)timevalue(4,3);
    else if(t>=44000 && t<45000)timevalue(4,4);
    else if(t>=45000 && t<46000)timevalue(4,5);
    else if(t>=46000 && t<47000)timevalue(4,6);
    else if(t>=47000 && t<48000)timevalue(4,7);
    else if(t>=48000 && t<49000)timevalue(4,8);
    else if(t>=49000 && t<50000)timevalue(4,9);
    else if(t>=50000 && t<51000)timevalue(5,0);
    else if(t>=51000 && t<52000)timevalue(5,1);
    else if(t>=52000 && t<53000)timevalue(5,2);
    else if(t>=53000 && t<54000)timevalue(5,3);
    else if(t>=54000 && t<55000)timevalue(5,4);
    else if(t>=55000 && t<56000)timevalue(5,5);
    else if(t>=56000 && t<57000)timevalue(5,6);
    else if(t>=57000 && t<58000)timevalue(5,7);
    else if(t>=58000 && t<59000)timevalue(5,8);
    else if(t>=59000 && t<60000)timevalue(5,9);
    else if(t>=60000 && t<61000)timevalue(6,0);
    else start=0;


}
void gettime()
{
    int timme;
    timme=glutGet(GLUT_ELAPSED_TIME);
    //cout<<"time = "<<timme<<endl;
    checktime(timme);

}

void display(void){
	glClear( GL_COLOR_BUFFER_BIT) ;
	glMatrixMode(GL_MODELVIEW) ;
	glLoadIdentity();

	gettime();

	if(ttcnt==0 || res==5)start=0;

	if(start==1){
	//boundary code are here
	boundary();

	//upper circles code are here
	glColor3f( 1.0 , 0.0 , 0.0 ) ;
	checkflag();

	//down operation
	mid_cir_and_arrow();

	//sending pattern
	things(sct);

	//smiley
	glColor3f( 1.0 , 1.0 , 0.0 );
	smiley();
	}

	else
    {
        gameover();
    }

    //score number
    glColor3f( 1.0 , 0.0 , 0.0 ) ;
    fullscore();
    glColor3f( 1.0 , 1.0 , 1.0 ) ;
	glLineWidth(2.0);
	scorenum(res);
	result();

	glutSwapBuffers() ;
}

void found(float x, float xx, float yy, float an)
{

    //cout<<"x "<<xx<<" y "<<yy<<"  y_tran "<<y_tran<<endl;

    if(xx>=380 && xx<=420 && yy>=y_tran-20 && yy<=y_tran+20)
    {
        if(sct==0 && an<90){tri_fl=0;sm=1;}
        if(sct==1 && an>90){star_fl=0;sm=1;}
    }
    else if(xx>=160 && xx<=240 && yy>=538-y_tran+270-20 && yy<=538-y_tran+270+20)
    {
        if(sct==2 && an<90){rect_fl=0;sm=1;}
        if(sct==4 && an>90){pent_fl=0;sm=1;}
    }
    else if(xx>=-1 && xx<=30 && yy>=y_tran-20 && yy<=y_tran+20)
    {
        if(sct==3){cir_fl=0;sm=1;}
    }



    if(sct==1 && xx>440 && star_fl==1)sm=2;
    else if(sct==0 && xx>580 && tri_fl==1)sm=2;
    else if(sct==3 && xx>=40 && cir_fl==1)sm=2;
    else if((sct==2 && an<90 && xx<240 && rect_fl==1) || (sct==2 && an<90 && xx>580 && rect_fl==1))sm=2;
    else if((sct==4 && an>90 && xx<240 && pent_fl==1) || (sct==4 && an>90 && xx>580 && pent_fl==1))sm=2;

    else if((sct==1 && an<120) || (sct==1 && an>=150))sm=2;
    else if((sct==4 && an<100) || (sct==4 && an>135))sm=2;
    else if((sct==3 && an<87) || (sct==3 && an>93))sm=2;
    else if((sct==2 && an>80) || (sct==2 && an<45))sm=2;
    else if((sct==0 && an>60) || (sct==0 && an<30))sm=2;

}

void anim()
{

    if( rotateFlag == 1 ){
		cnt=cnt+.40;
		float ang=angle;
		float pi=3.1416;
		if(angle>90)ang=180-angle;
		float xcnt=cnt*cos(ang*pi/180);
		float ycnt=cnt*sin(ang*pi/180);
		found(cnt,xcnt,ycnt,angle);
		//cout<<xcnt<<" "<<ycnt<<" cnt "<<cnt<<" angle "<<ang<<" sct "<<sct<<endl;
		if( abs(xcnt) >= 600 || abs(ycnt)>=600)
			{cnt = 0 ; rotateFlag =0;}
	}

        if(up==1)y_tran+=.08;
        if(up==0)y_tran-=.08;
        if(y_tran>538)up=0;
        if(y_tran<270)up=1;

		glutPostRedisplay();

}

void init(){

	glClearColor( 0.0 , 0.3 , 0.0 , 0.0 );  //Setting Background-RGBA
	glMatrixMode( GL_PROJECTION) ;
	glLoadIdentity() ;
	glOrtho( -600.0 , 600.0 , -600.0 , 600.0 , -1.0 , 1.0) ;

}

void keyboardHandler(unsigned char key, int x, int y)
{
    switch (key)
	{
		case 13:
			if(rotateFlag == 0)
				{
				    rotateFlag = 1;
				    ttcnt--;
                }
			break ;

        case ' ':
            sct=(sct+1)%5;
            break;

		case 27:
			 exit(0);
	}
}


void handleSpecialKeypress(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_LEFT:
            isLeftKeyPressed = true;
            if (!isRightKeyPressed)
                {
                    angle += 1.00;
                    sm=0;
                }
            break;

        case GLUT_KEY_RIGHT:
            isRightKeyPressed = true;
            if (!isLeftKeyPressed)
                {
                    angle -= 1.00;
                    sm=0;
                }
            break;
    }
}

void handleSpecialKeyReleased(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_LEFT:
            isLeftKeyPressed = false;
            break;

        case GLUT_KEY_RIGHT:
            isRightKeyPressed = false;
            break;
    }
}

int main()
{

    puts("************************////////*************************");
    puts("*                                                       *");
    puts("*  ->  YOU HAVE ONLY 10 SHOTS TO FINISH THE GAME        *");
    puts("*  ->  FOR MOVING THE ARROW, PRESS 'LEFT'  OR  'RIGHT'  *");
    puts("*  ->  FOR CHANGING THE PATTERN  'PRESS SPACE BAR'      *");
    puts("*  ->  FOR FIRING PRESS  'ENTER'                        *");
    puts("*                                                       *");
    puts("************************////////*************************");
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //display mode

	glutInitWindowSize(500,500 );
	glutInitWindowPosition(400,150);
	glutCreateWindow("MATCH THE PATTERN") ;

	init() ;
	glutDisplayFunc(display) ;
	glutKeyboardFunc(keyboardHandler);
    glutSpecialFunc(handleSpecialKeypress);
    glutSpecialUpFunc(handleSpecialKeyReleased);
	glutIdleFunc(anim) ;

	glutMainLoop() ;
    return 0;
}
