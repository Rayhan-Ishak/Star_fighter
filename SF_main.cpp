//
//  SF_main.cpp
//  Space_fighter
//
//  Created by Rayhan Ishak on 10/4/23.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "fssimplewindow.h"



const double YsPi=3.1415927;
const double G=9.8;

void DrawHealthBar(double w, double max)
{
    double x=10,y=10;
    
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+max,y);
    glVertex2i(x+max,y+10);
    glVertex2i(x,y+10);
    glEnd();
    
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+w,y);
    glVertex2i(x+w,y+10);
    glVertex2i(x,y+10);
    glEnd();
}
//void DrawPlayer(int x,int y)
void DrawPlayer(int x, int y, double Rad,int scale, double flame1)
{
    int x1,x2,x3,x4,x5,x6,x7,x8,x9,x10;
    int y1,y2,y3,y4,y5,y6,y7,y8,y9,y10;

    double d1,d2,d3,d4,d5,d6,d7,d8,d9,d10;
    double theta1,theta2,theta3,theta4,theta5,theta6,theta7,theta8,theta9,theta10;
    double r,b,b1,b2,flame;
    
    
    r=rand()%5;
    r=r/10+0.5;
    
    b=rand()%3;
    b=b/10+0.7;
    
    flame=rand()%10;
    flame=flame/10+1.7-flame1/5;
    
    
    
    x1 = scale*6;
    x2 = scale*0;
    x3 = scale*-6;
    x4 = scale*-6;
    x5 = scale*-10;
    x6 = scale*-6;
    x7 = scale*-10;
    x8 = scale*-10;
    x9 = scale*-20;
    x10 = scale*-15;
    
    y1 = scale*0;
    y2 = scale*20;
    y3 = scale*0;
    y4 = scale*0;
    y5 = scale*-10;
    y6 = scale*0;
    y7 = scale*-10;
    y8 = scale*5;
    y9 = scale*-10;
    y10 = scale*-20;
    
    
    theta1 = 0;
    theta2 = YsPi/2;;
    theta3 = YsPi;// atan(y3/x3);
    theta4 = YsPi/2;
    theta5 = 5*YsPi/4;// atan(y3/x3);
    theta6 = YsPi/2;
    theta7 = 5*YsPi/4;// atan(y3/x3);
    theta8  = atan(y8/x8);
    theta9  = atan(y9/x9);
    theta10 = atan(y10/x10);
    
    d1=scale*6;
    d2=scale*-20;
    d3=scale*6;
    d4=scale*6;
    d5=scale*sqrt(200);//-x5/cos(theta5);
    d6=scale*6;
    d7=scale*sqrt(200);//-x5/cos(theta5);
    d8=scale*sqrt(125)/5;
    d9=scale*sqrt(500)/6;
    d10=scale*sqrt(625)/flame;
    
    glColor3f(r,0,0.3);
    glBegin(GL_POLYGON);
    glVertex2i(x,y);
    glVertex2i(x+d8*cos(theta8+Rad),y+d8*sin(theta8+Rad));
    glVertex2i(x+d9*cos(theta9+Rad),y+d9*sin(theta9+Rad));
    glVertex2i(x+d10*cos(theta10+Rad+0.2),y+d10*sin(theta10+Rad+0.2));
    glEnd();
    
    glColor3f(r,0,0.5);
    glBegin(GL_POLYGON);
    glVertex2i(x,y);
    glVertex2i(x-d8*cos(theta8-Rad),y+d8*sin(theta8-Rad));
    glVertex2i(x-d9*cos(theta9-Rad),y+d9*sin(theta9-Rad));
    glVertex2i(x-d10*cos(theta10-Rad+0.2),y+d10*sin(theta10-Rad+0.2));
    glEnd();
    
    b=rand()%5;
    b=b/10+0.5;
    b1=rand()%3;
    b1=b/10+0.7;
    b2=rand()%5;
    b2=b/10+0.5;
    r=rand()%5;
    r=r/10;
    
    glShadeModel(GL_SMOOTH);
    glBegin(GL_POLYGON);
    //glColor3f(0.8,0.5,b);
    glColor3f(1,0.5,b);
    glVertex2i(x+d1*cos(theta1+Rad),y+d1*sin(theta1+Rad));
    glColor3f(r,0.5,b1);
    glVertex2i(x+d2*cos(theta2+Rad),y+d2*sin(theta2+Rad));
    glColor3f(1,0.5,b2);
    glVertex2i(x+d3*cos(theta3+Rad),y+d3*sin(theta3+Rad));
    glEnd();
    
    glColor3f(1,0.7,1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(x,y);
    glVertex2i(x-d4*cos(theta4-Rad),y+d4*sin(theta4-Rad));
    glVertex2i(x-d5*cos(theta5-Rad),y+d5*sin(theta5-Rad));
    //glVertex2i(x+d6*cos(theta6+Rad),y+d6*sin(theta6+Rad));
    glEnd();
    
    glColor3f(1,0.8,1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(x,y);
    glVertex2i(x+d4*cos(theta4+Rad),y+d4*sin(theta4+Rad));
    glVertex2i(x+d5*cos(theta5+Rad),y+d5*sin(theta5+Rad));
    //glVertex2i(x+d6*cos(theta6+Rad),y+d6*sin(theta6+Rad));
    glEnd();
    
    
}
void DrawAsteroid(double x,double y,double w)
{
    double h=w;
    double size=h*3/50;
    double flame_r;
    double flame_b;
    double flame_length_1, flame_length_2;
    double rad;
    
    flame_b=rand()%5;
    flame_b=flame_b/10+0.4;
    
    flame_r=rand()%5;
    flame_r=flame_b/10+0.5;
    
    
    flame_length_1=rand()%2+3;
    flame_length_2=rand()%3+flame_length_1;
    

    rad=rand()%80;
    rad=rad/100-0.3;
    glColor3f(1,0,flame_b);
    glBegin(GL_POLYGON);
    glVertex2i(x+w/2,y);
    //glVertex2i(x+w,y);
    glVertex2i(x+cos(rad)*w*flame_length_2,y+h/2-sin(rad)*w*flame_length_2);
    glVertex2i(x+w/2,y+h);
    glEnd();

    
    flame_r=rand()%5;
    flame_r=flame_r/10+0.5;
    glColor3f(flame_r,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(x+w/2,y);
    glVertex2i(x+cos(rad)*w*flame_length_1,y-sin(rad)*w*flame_length_1);
    glVertex2i(x+w,y+h);
    glEnd();
   
    flame_r=rand()%5;
    flame_r=flame_r/10+0.5;
    glColor3f(flame_r,0,0);
    glBegin(GL_POLYGON);
    //glVertex2i(x,y);
    glVertex2i(x+w,y);
    glVertex2i(x+cos(rad)*w*flame_length_1,y+h-sin(rad)*w*flame_length_1);
    glVertex2i(x+w/2,y+h);
    glEnd();
    
    
    
    double ast_r=rand()%5;
    ast_r=ast_r/10+0.5;
    
    glColor3f(ast_r,0.25,0);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    rad = 10;
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*size;
        double c=cos(ang)*size;
        double cx=x+rad*c;
        double cy=y+rad*s;
        glVertex2d(cx+w/2,cy+h/2);
    }
    glEnd();
    
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    rad = 10;
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*size/1.1;
        double c=cos(ang)*size/1.1;
        double cx=x+rad*c;
        double cy=y+rad*s;
        glVertex2d(cx+w/2,cy+h/2);
    }
    
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    rad = 10;
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*size/3;
        double c=cos(ang)*size/3;
        double cx=x+rad*c;
        double cy=y+rad*s;
        glVertex2d(cx+w/3,cy+h/3);
    }
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    rad = 10;
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*size/4;
        double c=cos(ang)*size/4;
        double cx=x+rad*c;
        double cy=y+rad*s;
        glVertex2d(cx+w/3,cy+h/3);
    }
    glEnd();
    
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    rad = 10;
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*size/6;
        double c=cos(ang)*size/6;
        double cx=x+rad*c;
        double cy=y+rad*s;
        glVertex2d(cx+w/1.3,cy+h/1.5);
    }
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    rad = 10;
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*size/7;
        double c=cos(ang)*size/7;
        double cx=x+rad*c;
        double cy=y+rad*s;
        glVertex2d(cx+w/1.3,cy+h/1.5);
    }
    glEnd();
}

void DrawLaser(double x, double y, double Rad, double width, int arc,double r, double b)
{
    //x=10,y=10;
    int Length = width;
    Rad=-Rad-YsPi/2;
    
    glColor3f(r,0,b);
    glBegin(GL_POLYGON);
    glVertex2i(x,y);
    glVertex2i(x-Length*cos(Rad)-arc*sin(-Rad),y+Length*sin(Rad)+arc*cos(-Rad));
    glVertex2i(x-Length*cos(Rad)+arc*sin(-Rad),y+Length*sin(Rad)-arc*cos(-Rad));
    //glVertex2i(x-5*sin(Rad),y-5*cos(Rad));
    glEnd();
}

void DrawLaserCooldown(double w, double max)
{
    double x=10,y=25;
    
    glColor3f(0,0,1);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+max,y);
    glVertex2i(x+max,y+10);
    glVertex2i(x,y+10);
    glEnd();
    
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+w,y);
    glVertex2i(x+w,y+10);
    glVertex2i(x,y+10);
    glEnd();
}
void DrawProjectile(double x,double y,double w,double rad,double r,double g,double b)
{
    double h=w;
    double size=h*3/50;
    
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+w,y);
    glVertex2i(x+w,y+h);
    glVertex2i(x,y+h);
    glEnd();
    
    glColor3f(0.5,0,0);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*size;
        double c=cos(ang)*size;
        double cx=x+rad*c;
        double cy=y+rad*s;
        glVertex2d(cx+w/2,cy+h/2);
    }
    glEnd();
    
    glColor3f(0.4,0,0);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*size/1.5;
        double c=cos(ang)*size/1.5;
        double cx=x+rad*c;
        double cy=y+rad*s;
        glVertex2d(cx+w/2,cy+h/2);
    }
    glEnd();
    
    glColor3f(0.2,0,0);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*size/3;
        double c=cos(ang)*size/3;
        double cx=x+rad*c;
        double cy=y+rad*s;
        glVertex2d(cx+w/2,cy+h/2);
    }
    glEnd();
}
void DrawProjectile1(double x,double y,double w,double rad,double r,double g,double b)
{
    double h=w;
    double size=h*3/50;
    
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+w,y);
    glVertex2i(x+w,y+h);
    glVertex2i(x,y+h);
    glEnd();
    
    glColor3f(0.5,0,0);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*size;
        double c=cos(ang)*size;
        double cx=x+rad*c;
        double cy=y+rad*s;
        glVertex2d(cx+w/2,cy+h/2);
    }
    glEnd();
    
    glColor3f(0.4,0,0);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*size/1.5;
        double c=cos(ang)*size/1.5;
        double cx=x+rad*c;
        double cy=y+rad*s;
        glVertex2d(cx+w/2,cy+h/2);
    }
    glEnd();
    
    glColor3f(0.2,0,0);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*size/3;
        double c=cos(ang)*size/3;
        double cx=x+rad*c;
        double cy=y+rad*s;
        glVertex2d(cx+w/2,cy+h/2);
    }
    glEnd();
}
void DrawProjectile2(double x,double y,double w,double rad,double r,double g,double b)
{
    double h=w;
    double size=h*3/50;
    
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+w,y);
    glVertex2i(x+w,y+h);
    glVertex2i(x,y+h);
    glEnd();
    
    glColor3f(0.5,0,0);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*size;
        double c=cos(ang)*size;
        double cx=x+rad*c;
        double cy=y+rad*s;
        glVertex2d(cx+w/2,cy+h/2);
    }
    glEnd();
    
    glColor3f(0.4,0,0);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*size/1.5;
        double c=cos(ang)*size/1.5;
        double cx=x+rad*c;
        double cy=y+rad*s;
        glVertex2d(cx+w/2,cy+h/2);
    }
    glEnd();
    
    glColor3f(0.2,0,0);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*size/3;
        double c=cos(ang)*size/3;
        double cx=x+rad*c;
        double cy=y+rad*s;
        glVertex2d(cx+w/2,cy+h/2);
    }
    glEnd();
}
void Drawbackgound(int width, int height)
{
    
    double b=rand()%5;
    b=b/10;
    
    double r=rand()%5;
    r=r/10;

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(0,0);
    glColor3f(0,0,0);
    glVertex2i(width,0);
    glColor3f(0,0,0);
    glVertex2i(width,height);
    glColor3f(0,0,0);
    glVertex2i(0,height);
    glEnd();
    
    
    glColor3f(1,1,1);
    int i=0;
    int stars, size=10;
    int x,y;
    
    //scales the amount of stars relative to window size
    stars = (width+height)/100;
    
    for (i=0; i<stars; i++) {
        x=rand()%width;
        y=rand()%height;
        
        glBegin(GL_LINE_LOOP);
        glVertex2i(x,y);
        glVertex2i(x+size,y);
        glVertex2i(x,y+size/2);
        glVertex2i(x+size/2,y-size/2);
        glVertex2i(x+size,y+size/2);
        glEnd();
    }
    
}
void DrawExplosion(double ex,double ey,double a,double rad,double r,double g,double b)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*a;
        double c=cos(ang)*a;
        double x=ex+rad*c;
        double y=ey+rad*s;
        glVertex2d(x,y);
    }
    glEnd();
}
void DrawExplosion1(double ex,double ey,double a,double rad,double r,double g,double b)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*a;
        double c=cos(ang)*a;
        double x=ex+rad*c;
        double y=ey+rad*s;
        glVertex2d(x,y);
    }
    glEnd();
}
void DrawExplosion2(double ex,double ey,double a,double rad,double r,double g,double b)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*a;
        double c=cos(ang)*a;
        double x=ex+rad*c;
        double y=ey+rad*s;
        glVertex2d(x,y);
    }
    glEnd();
}
void DrawExplosion3(double ex,double ey,double a,double rad,double r,double g,double b)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*a;
        double c=cos(ang)*a;
        double x=ex+rad*c;
        double y=ey+rad*s;
        glVertex2d(x,y);
    }
    glEnd();
}
void DrawExplosion4(double ex,double ey,double a,double rad,double r,double g,double b)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*a;
        double c=cos(ang)*a;
        double x=ex+rad*c;
        double y=ey+rad*s;
        glVertex2d(x,y);
    }
    glEnd();
}
void DrawExplosion5(double ex,double ey,double a,double rad,double r,double g,double b)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*a;
        double c=cos(ang)*a;
        double x=ex+rad*c;
        double y=ey+rad*s;
        glVertex2d(x,y);
    }
    glEnd();
}
void DrawExplosion6(double ex,double ey,double a,double rad,double r,double g,double b)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*a;
        double c=cos(ang)*a;
        double x=ex+rad*c;
        double y=ey+rad*s;
        glVertex2d(x,y);
    }
    glEnd();
}
void DrawExplosion7(double ex,double ey,double a,double rad,double r,double g,double b)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*a;
        double c=cos(ang)*a;
        double x=ex+rad*c;
        double y=ey+rad*s;
        glVertex2d(x,y);
    }
    glEnd();
}
void DrawExplosion8(double ex,double ey,double a,double rad,double r,double g,double b)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*a;
        double c=cos(ang)*a;
        double x=ex+rad*c;
        double y=ey+rad*s;
        glVertex2d(x,y);
    }
    glEnd();
}
void DrawExplosion9(double ex,double ey,double a,double rad,double r,double g,double b)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*a;
        double c=cos(ang)*a;
        double x=ex+rad*c;
        double y=ey+rad*s;
        glVertex2d(x,y);
    }
    glEnd();
}
void DrawExplosion10(double ex,double ey,double a,double rad,double r,double g,double b)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*a;
        double c=cos(ang)*a;
        double x=ex+rad*c;
        double y=ey+rad*s;
        glVertex2d(x,y);
    }
    glEnd();
}

void DrawPlayerDeath(double ex,double ey,double a,double circle,double circle1,double circle2, double r,double g,double b)
{
    double rad=100;
    glColor3f(1,1,1);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,0b1111000011110000);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*circle2;
        double c=cos(ang)*circle2;
        double x=ex+rad*c;
        double y=ey+rad*s;
        glVertex2d(x,y);
    }
    glEnd();

        
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glBegin(GL_LINE_LOOP);
    glVertex2f(ex+a/2,ey);
    glVertex2f(ex+a/10,ey+a/10);
    glVertex2f(ex,ey+a/2);
    glVertex2f(ex-a/10,ey+a/10);
    glVertex2f(ex-a/2,ey);
    glVertex2f(ex-a/10,ey-a/10);
    glVertex2f(ex,ey-a/2);
    glVertex2f(ex+a/10,ey-a/10);
    glVertex2f(ex+a/2,ey);
    glEnd();
    
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*circle;
        double c=cos(ang)*circle;
        double x=ex+rad*c;
        double y=ey+rad*s;
        glVertex2d(x,y);
    }
    glEnd();

    glColor3f(r,0,b);
    glBegin(GL_POLYGON);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<64; ++i)
    {
        double ang=YsPi*(double)i/32.0;
        double s=sin(ang)*circle1;
        double c=cos(ang)*circle1;
        double x=ex+rad*c;
        double y=ey+rad*s;
        glVertex2d(x,y);
    }
    glEnd();
}

bool CheckCollision(double mx,double my,double tx,double ty,double tw,double th)
{
    return (
        tx<=mx && mx<=tx+tw &&
        ty<=my && my<=ty+th
    );
}

const int ast_num=10;

int main(void)
{
    
    double vel = 0.5, ang_vel = 2, max_vel = 7;
    int width=800,height=600;
    int player_x = width/2, player_y = height/2, player_state=1,player_health=width/4,max_health=width/4;
    double player_Rad=0;
    double play_vx=0,play_vy=0;
    int player_scale = 2;
    double flame,flame1=0;
    double Rad=0;
    int Mode=0;
    double mouse_rad = 0;

    
    int Prg_x, Prg_y, Prg_vx=0, Prg_vy=0, Prg_v=10, Prg_state=0, Prg_a=0;
    int Prg_x1, Prg_y1, Prg_vx1=0, Prg_vy1=0, Prg_state1=0, Prg_a1=0;
    int Prg_x2, Prg_y2, Prg_vx2=0, Prg_vy2=0, Prg_state2=0, Prg_a2=0;
    int Prg_state3=0,Prg_state4=4,Prg_state5=0;
    
    double  Prg_Rad=0;
    int Lsr_state=0, Lsr_x=100,Lsr_y=100,Lsr_shot=0,Lsr_time=0, arc=0;
    double Lsr_r=1,Lsr_b=0,Lsr_Rad=0,Lsr_cooldown=100;
    double ast_x[ast_num],ast_y[ast_num], ast_vx[ast_num],ast_vy[ast_num],ast_Rad[ast_num],ast_size[ast_num],ast_state[ast_num],ast_final[ast_num],ast_a[ast_num], ast_j[ast_num];
    int i=0;
    double ast_alive = 10;
    double ex=0,ey=0, a=0.5,a1=0.5,a2=0,a3=0,a4=0, explosion = 0;
    int  re=1, ge=0, be=0, j=0, jj=0;
    srand(time(NULL));
    double r, g, b;
    
    int Start=0;

    for(int i=0; i<ast_num; ++i)
    {
        //ast_j[i]=0;
        //ast_a[i]=0;
        ast_x[i]=800;
        ast_y[i]=rand()%600;
        
        ast_x[i]=300;
        ast_y[i]=rand()%600;
        
        ast_vx[i]=-(rand()%15+5);
        ast_vy[i]=rand()%30-15;
        
        
        //ast_vx[i]=0;
        //ast_vy[i]=0;
        
        ast_size[i]=15+rand()%10;
        ast_state[i]=1;
        ast_final[i]=0;
        //ast_alive[i]=0;

    }

    FsOpenWindow(0,0,width,height,1);
    for(;;)
    {
        FsGetWindowSize(width,height);
        glViewport(0,0,width,height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0,width,height,0,-1,1);
        
        double dt=0.05;
        FsPollDevice();
        auto key=FsInkey();
        
        int lb,mb,rb,mx,my;
        int evt=FsGetMouseEvent(lb,mb,rb,mx,my);
    
        printf("%lf %lf\n\n",play_vx,play_vy);
        if(FSKEY_ESC==key)
        {
            break;
        }
        if (Mode==0) {
            if(0!=FsGetKeyState(FSKEY_SHIFT))
            {
                max_vel=12;
                flame1=5;
            }
            if(0==FsGetKeyState(FSKEY_SHIFT))
            {
                max_vel=5;
                flame1=0;
            }
            if(0!=FsGetKeyState(FSKEY_A))
            {
                player_Rad-=0.0523599*ang_vel;
            }
            if(0!=FsGetKeyState(FSKEY_D))
            {
                player_Rad+=0.0523599*ang_vel;
            }
            if(0!=FsGetKeyState(FSKEY_W))
            {
                if (play_vx>=-max_vel && play_vx<=max_vel) {
                    play_vx -= vel*cos(player_Rad+YsPi/2);
                }
                if (play_vx<=-max_vel) {
                    play_vx +=1;
                }
                if (play_vx>=max_vel) {
                    play_vx -=1;
                }
                
                if (play_vy>=-max_vel && play_vy<=max_vel) {
                    play_vy -= vel*sin(player_Rad+YsPi/2);
                }
                if (play_vy<=-max_vel) {
                    play_vy +=1;
                }
                if (play_vy>=max_vel) {
                    play_vy -=1;
                }
                
            }
            if(0!=FsGetKeyState(FSKEY_S))
            {
                flame1=-10;
                
                if (play_vx>-max_vel && play_vx<=max_vel) {
                    play_vx += vel*cos(player_Rad+YsPi/2);
                }
                if (play_vx<=-max_vel) {
                    play_vx +=1;
                }
                if (play_vx>=max_vel) {
                    play_vx -=1;
                }
                if (play_vy>-max_vel && play_vy<=max_vel) {
                    play_vy += vel*sin(player_Rad+YsPi/2);
                }
                if (play_vy<=-max_vel) {
                    play_vy +=1;
                }
                if (play_vy>=max_vel) {
                    play_vy -=1;
                }
            }
        }
        if (Mode==1) {

            player_x = mx;
            player_y = my;
            if(0!=FsGetKeyState(FSKEY_A))
            {
                player_Rad-=0.075*ang_vel;
            }
            if(0!=FsGetKeyState(FSKEY_D))
            {
                player_Rad+=0.075*ang_vel;
            }
            
        }
        if (Mode==3) {
        }
    
        switch(key)
        {
            case FSKEY_P:
                if (0==Start) {
                    Start=1;
                    for(int i=0; i<ast_num; ++i)
                    {
                        ast_x[i]=800;
                        ast_y[i]=rand()%600;
                    }
                }
                
            break;
            case FSKEY_TAB:
                if (Mode==0) {
                    Mode += 1;
                    FsSetMousePosition(player_x, player_y);
                }
                else {
                    Mode -= 1;
                }
                
            break;
                
            case FSKEY_SPACE:
                if(0==Lsr_state && 0==Lsr_time)
                {
                    Prg_x = player_x;
                    Prg_y = player_y;
                    Prg_a = 1;
                    
                    Prg_x1 = player_x;
                    Prg_y1 = player_y;
                    Prg_a1 = 1;
                    
                    Prg_x2 = player_x;
                    Prg_y2 = player_y;
                    Prg_a2 = 1;
                    
                    Prg_Rad = player_Rad-YsPi/2;
                    
                    Prg_vx=Prg_v*cos(Prg_Rad);
                    Prg_vy=Prg_v*sin(Prg_Rad);
                    
                    Prg_vx1=Prg_v*cos(Prg_Rad);
                    Prg_vy1=Prg_v*sin(Prg_Rad);
                    
                    Prg_vx2=Prg_v*cos(Prg_Rad);
                    Prg_vy2=Prg_v*sin(Prg_Rad);
                    
                    Prg_state=1;
                    Prg_state1=1;
                    Prg_state2=1;
                    
                    Lsr_x = player_x;
                    Lsr_y = player_y;
                    Lsr_Rad = player_Rad;
                    arc=width/25;
                    Lsr_state=1;
                }
            break;
            case FSKEY_ENTER:
                if(0==Prg_state && 0==Prg_state1 && 0==Prg_state2)
                {
        
                    Prg_x = player_x;
                    Prg_y = player_y;
                    Prg_a = 1;
                    
                    Prg_x1 = player_x;
                    Prg_y1 = player_y;
                    Prg_a1 = 1;
                    
                    Prg_x2 = player_x;
                    Prg_y2 = player_y;
                    Prg_a2 = 1;
                    
                    Prg_Rad = player_Rad-YsPi/2;
                    
                    Prg_vx=Prg_v*cos(Prg_Rad);
                    Prg_vy=Prg_v*sin(Prg_Rad);
                    
                    Prg_vx1=Prg_v*cos(Prg_Rad);
                    Prg_vy1=Prg_v*sin(Prg_Rad);
                    
                    Prg_vx2=Prg_v*cos(Prg_Rad);
                    Prg_vy2=Prg_v*sin(Prg_Rad);
                    
                    Prg_state=1;
                    Prg_state1=1;
                    Prg_state2=1;
                    Prg_state3=1;
                }
            break;
        }

        //checks player collision of the asteroids
        for(int i=0; i<ast_num; ++i)
        {
            if(0!=player_state && 0!=Start && 0!=ast_state[i] && true==CheckCollision(player_x,player_y,ast_x[i],ast_y[i],ast_size[i]*2,ast_size[i]*2))
            {
                ast_state[i]=0;
                player_health -= max_health*0.25;
                ast_alive-=ast_state[i];
                explosion = 1;
                a=0;
                j=0;
                ex = ast_x[i];
                ey = ast_y[i];
                printf("Hit!\n");
            }
        }
        //checks projectile collision of the asteroids
        for(int i=0; i<ast_num; ++i)
        {
            if(0!=Prg_state && 0!=Start && 0!=ast_state[i] && true==CheckCollision(Prg_x,Prg_y,ast_x[i],ast_y[i],ast_size[i]*2,ast_size[i]*2))
            {
                ast_state[i]=0;
                Prg_state = 0;
                ast_alive-=ast_state[i];
                explosion = 1;
                a=0;
                j=0;
                ex = ast_x[i];
                ey = ast_y[i];
                printf("Hit!\n");
            }
            if(0!=Prg_state1 && 0!=ast_state[i] && 0!=Start &&  true==CheckCollision(Prg_x1-Prg_a1*sin(Prg_Rad),Prg_y1+Prg_a1*cos(Prg_Rad),ast_x[i],ast_y[i],ast_size[i]*2,ast_size[i]*2))
            {
                ast_state[i]=0;
                Prg_state1 = 0;
                ast_alive-=ast_state[i];
                explosion = 1;
                a=0;
                j=0;
                ex = ast_x[i];
                ey = ast_y[i];
                printf("Hit!\n");
            }
            if(0!=Prg_state2 && 0!=ast_state[i] && 0!=Start &&   true==CheckCollision(Prg_x2+Prg_a2*sin(Prg_Rad),Prg_y2-Prg_a2*cos(Prg_Rad),ast_x[i],ast_y[i],ast_size[i]*2,ast_size[i]*2))
            {
                ast_state[i]=0;
                Prg_state2 = 0;
                ast_alive-=ast_state[i];
                explosion = 1;
                a=0;
                j=0;
                ex = ast_x[i];
                ey = ast_y[i];
                printf("Hit!\n");
            }
        }
        
        //moves the player across the screen
        if (player_x > width) {
            player_x -= width;
        }
        if (player_y > height) {
            player_y -=height;
        }
        if (player_x < 0) {
            player_x += width;
        }
        if (player_y < 0) {
            player_y +=height;
        }

        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
       // printf("%lf",r);
        Drawbackgound(width, height);
        i=0;
        if (ast_alive>0 && 0!=Start) {
            for (i=0; i<ast_num; i++) {
                if (0!=ast_state[i] )
                {
                    if (ast_y[i] > height) {
                        ast_y[i] -=height;
                    }
                    if (ast_x[i] < 0) {
                        ast_x[i] += width;
                    }
                    if (ast_y[i] < 0) {
                        ast_y[i] +=height;
                    }
                    DrawAsteroid(ast_x[i],ast_y[i],ast_size[i]);
                    ast_x[i] += ast_vx[i];
                    ast_y[i] += ast_vy[i];
                }
            }
        }
        
        
       
            
        if (0!=Prg_state) {
            Prg_x += Prg_vx;
            Prg_y += Prg_vy;
            Prg_a += 1.5;
            //Prg_shot +=1;
            DrawProjectile(Prg_x,Prg_y,Prg_a/10,100,1,1,1);
            if(Prg_x<0)
            {
                Prg_state=0;
            }
            if(Prg_x>width)
            {
                Prg_state=0;
            }
            if(Prg_y<0)
            {
                Prg_state=0;
            }
            if(Prg_y>height)
            {
                Prg_state=0;
            }
        }
        if (0!=Prg_state1) {
            Prg_x1 += Prg_vx1;
            Prg_y1 += Prg_vy1;
            Prg_a1 += 1.5;
            //Prg_shot +=1;
            DrawProjectile1(Prg_x1-Prg_a1*sin(Prg_Rad),Prg_y1+Prg_a1*cos(Prg_Rad),Prg_a1/10,100,1,1,1);
            if(Prg_x1<0)
            {
                Prg_state1=0;
            }
            if(Prg_x1>width)
            {
                Prg_state1=0;
            }
            if(Prg_y1<0)
            {
                Prg_state1=0;
            }
            if(Prg_y1>height)
            {
                Prg_state1=0;
            }
        }
        if (0!=Prg_state2) {
            Prg_x2 += Prg_vx2;
            Prg_y2 += Prg_vy2;
            Prg_a2 += 1.5;
            //Prg_shot +=1;
            DrawProjectile2(Prg_x2-Prg_a2*sin(Prg_Rad),Prg_y2+Prg_a2*cos(Prg_Rad),Prg_a2/10,100,1,1,1);
            if(Prg_x2<0)
            {
                Prg_state2=0;
            }
            if(Prg_x2>width)
            {
                Prg_state2=0;
            }
            if(Prg_y2<0)
            {
                Prg_state2=0;
            }
            if(Prg_y2>height)
            {
                Prg_state2=0;
            }
        }
        if (0==Prg_state && 0==Prg_state1 &&
            0==Prg_state2) {
            Prg_state3=0;
        }

        
        DrawLaserCooldown(Lsr_time, Lsr_cooldown);
        if (0!=Lsr_state) {
            if (0!=Prg_state) {
                Prg_x += Prg_vx;
                Prg_y += Prg_vy;
                Prg_a -= 1.5;
                //Prg_shot +=1;
                DrawProjectile(Prg_x,Prg_y,Prg_a/10,100,1,1,1);
                if(Prg_x<0)
                {
                    Prg_state=0;
                }
                if(Prg_x>width)
                {
                    Prg_state=0;
                }
                if(Prg_y<0)
                {
                    Prg_state=0;
                }
                if(Prg_y>height)
                {
                    Prg_state=0;
                }
            }
            if (0!=Prg_state1) {
                Prg_x1 += Prg_vx1;
                Prg_y1 += Prg_vy1;
                Prg_a1 -= 1.5;
                //Prg_shot +=1;
                DrawProjectile1(Prg_x1-Prg_a1*cos(Prg_Rad),Prg_y1+Prg_a1*sin(Prg_Rad),Prg_a1/10,100,1,1,1);
                if(Prg_x1<0)
                {
                    Prg_state1=0;
                }
                if(Prg_x1>width)
                {
                    Prg_state1=0;
                }
                if(Prg_y1<0)
                {
                    Prg_state1=0;
                }
                if(Prg_y1>height)
                {
                    Prg_state1=0;
                }
            }
            if (0!=Prg_state2) {
                Prg_x2 += Prg_vx2;
                Prg_y2 += Prg_vy2;
                Prg_a2 -= 1.5;
                //Prg_shot +=1;
                DrawProjectile2(Prg_x2+Prg_a2*cos(Prg_Rad),Prg_y2-Prg_a2*sin(Prg_Rad),Prg_a2/10,100,1,1,1);
                if(Prg_x2<0)
                {
                    Prg_state2=0;
                }
                if(Prg_x2>width)
                {
                    Prg_state2=0;
                }
                if(Prg_y2<0)
                {
                    Prg_state2=0;
                }
                if(Prg_y2>height)
                {
                    Prg_state2=0;
                }
            }
            Lsr_shot +=1;
            DrawLaser(Lsr_x,Lsr_y,Lsr_Rad,width,arc,Lsr_r,Lsr_b);
            arc -=0.05;
            Lsr_b+=0.025;
            Lsr_r-=0.025;
            if (arc<=0) {
                Prg_state=0;
                Prg_state1=0;
                Prg_state2=0;
                Prg_state3=0;
                
                Lsr_state=0;
                Lsr_shot-=1;
                Lsr_b=0;
                Lsr_r=1;
                Lsr_time = Lsr_cooldown;
            }
            
        }
        if (Lsr_time>0) {
            Lsr_time -=1;
            if (Lsr_time<10) {
                Lsr_time=0;
            }
        }
        if (0!=explosion && j==0) {
            if (a<=0.5 && j==0) {
                a += 0.01;
            }
            if (a>0.5 || j==1) {
                a -= 0.25;
                j=1;
                if (a<=0) {
                    explosion=0;
                }
            }
            re = rand()%2;
            ge = 0;
            be = rand()%2;

            DrawExplosion(ex, ey,a, 100, re, ge, be);
        }
        
        if (player_health<=0) {
            Mode=3;
            a1+=10;
            a2+=0.005;
            a3+=0.0025;
            a4+=0.05;
            r = rand()%2;
            g = 0;
            b = rand()%2;
            DrawPlayerDeath(player_x, player_y, a1, a2,a3,a4, r,g,b);
            if (a<=0.5 && j==0) {
                a += 0.01;
            }
            if (a>0.5 || j==1) {
                a -= 0.25;
                j=1;
                if (a<=0) {
                    explosion=0;
                }
            }
            if (a3>=0.5) {
                break;
            }
           
            re = rand()%2;
            ge = 0;
            be = rand()%2;
            if (0!=ast_state[0] || 0!=ast_final[0]) {
                if (ast_a[0]<=0.5 && ast_j[0]==0) {
                    ast_a[0]+=0.01;
                    ast_final[0]=1;
                }
                if (ast_a[0]>0.5 || ast_j[0]==1) {
                    ast_a[0] -= 0.25;
                    ast_j[0]=1;
                    if (ast_a[0]<=0) {
                        ast_final[0]=0;
                    }
                }
                DrawExplosion(ast_x[0], ast_y[0],ast_a[0], 100, re, ge, be);
                ast_state[0]=0;
            }
            if (0!=ast_state[1] || 0!=ast_final[1]) {
                if (ast_a[1]<=0.5 && ast_j[1]==0) {
                    ast_a[1]+=0.01;
                    ast_final[1]=1;
                }
                if (ast_a[1]>0.5 || ast_j[1]==1) {
                    ast_a[1] -= 0.25;
                    ast_j[1]=1;
                    if (ast_a[1]<=0) {
                        ast_final[1]=0;
                    }
                }
                DrawExplosion1(ast_x[1], ast_y[1],ast_a[1], 100, re, ge, be);
                ast_state[1]=0;
              
            }
            if (0!=ast_state[2] || 0!=ast_final[2]) {
                if (ast_a[2]<=0.5 && ast_j[2]==0) {
                    ast_a[2]+=0.01;
                    ast_final[2]=1;
                }
                if (ast_a[2]>0.5 || ast_j[2]==1) {
                    ast_a[2] -= 0.25;
                    ast_j[2]=1;
                    if (ast_a[2]<=0) {
                        ast_final[2]=0;
                    }
                }
                DrawExplosion2(ast_x[2], ast_y[2],ast_a[2], 100, re, ge, be);
                ast_state[2]=0;
            }
            if (0!=ast_state[3] || 0!=ast_final[3]) {
                if (ast_a[3]<=0.5 && ast_j[3]==0) {
                    ast_final[3]=1;
                    ast_final[3]=1;
                }
                if (ast_a[3]>0.5 || ast_j[3]==1) {
                    ast_a[3] -= 0.25;
                    ast_j[3]=1;
                    if (ast_a[3]<=0) {
                        ast_final[3]=0;
                    }
                }
                DrawExplosion3(ast_x[3], ast_y[3],ast_a[3], 100, re, ge, be);
                ast_state[3]=0;
            
            }
            if (0!=ast_state[4] || 0!=ast_final[4]) {
                if (ast_a[4]<=0.5 && ast_j[4]==0) {
                    ast_final[4]=1;
                    ast_final[4]=1;
                }
                if (ast_a[4]>0.5 || ast_j[4]==1) {
                    ast_a[4] -= 0.25;
                    ast_j[4]=1;
                    if (ast_a[4]<=0) {
                        ast_final[4]=0;
                    }
                }
                DrawExplosion4(ast_x[4], ast_y[4],ast_a[4], 100, re, ge, be);
                ast_state[4]=0;
            
            }
            if (0!=ast_state[5] || 0!=ast_final[5]) {
                if (ast_a[5]<=0.5 && ast_j[5]==0) {
                    ast_final[5]=1;
                    ast_final[5]=1;
                }
                if (ast_a[5]>0.5 || ast_j[3]==1) {
                    ast_a[5] -= 0.25;
                    ast_j[5]=1;
                    if (ast_a[5]<=0) {
                        ast_final[5]=0;
                    }
                }
                DrawExplosion5(ast_x[5], ast_y[5],ast_a[5], 100, re, ge, be);
                ast_state[5]=0;
            
            }
            if (0!=ast_state[6] || 0!=ast_final[6]) {
                if (ast_a[6]<=0.5 && ast_j[6]==0) {
                    ast_a[6]+=0.01;
                    ast_final[6]=1;
                }
                if (ast_a[6]>0.5 || ast_j[6]==1) {
                    ast_a[6] -= 0.25;
                    ast_j[6]=1;
                    if (ast_a[6]<=0) {
                        ast_final[6]=0;
                    }
                }
                DrawExplosion6(ast_x[6], ast_y[6],ast_a[6], 100, re, ge, be);
                ast_state[6]=0;
            }
            if (0!=ast_state[7] || 0!=ast_final[7]) {
                if (ast_a[7]<=0.5 && ast_j[7]==0) {
                    ast_a[7]+=0.01;
                    ast_final[7]=1;
                }
                if (ast_a[7]>0.5 || ast_j[7]==1) {
                    ast_a[7] -= 0.25;
                    ast_j[7]=1;
                    if (ast_a[7]<=0) {
                        ast_final[7]=0;
                    }
                }
                DrawExplosion7(ast_x[7], ast_y[7],ast_a[7], 100, re, ge, be);
                ast_state[7]=0;
              
            }
            if (0!=ast_state[8] || 0!=ast_final[8]) {
                if (ast_a[8]<=0.5 && ast_j[8]==0) {
                    ast_a[8]+=0.01;
                    ast_final[8]=1;
                }
                if (ast_a[8]>0.5 || ast_j[8]==1) {
                    ast_a[8] -= 0.25;
                    ast_j[8]=1;
                    if (ast_a[8]<=0) {
                        ast_final[8]=0;
                    }
                }
                DrawExplosion8(ast_x[8], ast_y[8],ast_a[8], 100, re, ge, be);
                ast_state[8]=0;
                
            }
            if (0!=ast_state[9] || 0!=ast_final[9]) {
                if (ast_a[9]<=0.5 && ast_j[9]==0) {
                    ast_final[9]=1;
                    ast_final[9]=1;
                }
                if (ast_a[9]>0.5 || ast_j[9]==1) {
                    ast_a[9] -= 0.25;
                    ast_j[9]=1;
                    if (ast_a[9]<=0) {
                        ast_final[9]=0;
                    }
                }
                DrawExplosion9(ast_x[9], ast_y[9],ast_a[9], 100, re, ge, be);
                ast_state[9]=0;
            
            }
            if (0!=ast_state[10] || 0!=ast_final[10]) {
                if (ast_a[10]<=0.5 && ast_j[10]==0) {
                    ast_final[10]=1;
                    ast_final[10]=1;
                }
                if (ast_a[10]>0.5 || ast_j[10]==1) {
                    ast_a[10] -= 0.25;
                    ast_j[10]=1;
                    if (ast_a[10]<=0) {
                        ast_final[10]=0;
                    }
                }
                DrawExplosion10(ast_x[10], ast_y[10],ast_a[10], 100, re, ge, be);
                ast_state[10]=0;
            
            }
            
        }
        
        player_y += play_vy;
        player_x += play_vx;
        DrawPlayer(player_x, player_y, player_Rad, player_scale,flame1);
        DrawHealthBar(player_health,max_health);
        
        
        printf("%lf %d\n",a, j);
        //printf("%lf %lf %lf\n",balls,vx,vy);
        FsSwapBuffers();
        FsSleep(20);
    }
    return 0;
}

