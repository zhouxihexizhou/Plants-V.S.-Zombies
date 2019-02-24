#include "stdafx.h"
#include "Sun.h"
#include <string>
#include <iostream>
#include "GFont.h"

Sun::Sun(void)
{
	r=0;
	R=0;
	pos.Set(0,0,0);
}

void Sun::Init(double a,double b,Time *t)
{
	r=a;
	R=b;
	suntime=t;
}

void Sun::SetSeta(double base)
{
	seta=base*6.0;
	seta=AngToRad(seta);
}

void Sun::Draw()
{
	GFont pFont;
	double x=-R*cos(seta);
	double y=R*sin(seta)*2;
	pos.Set(x,y,0);
	string showtime=suntime->GetShowTime();

	SetSeta(suntime->second*1.0+suntime->cent/100.0);
	glPushMatrix();
	if(y>0)
	{
		glTranslated(x,y,0);
		glDisable(GL_LIGHTING);
		glColor3f(5.0,0,0);
		glutSolidSphere(r,20,20);
		glTranslated(-50, -100, 0);
		glColor3f(0.5,0.5 , 0);
		glScalef(25, 25, 25);
		pFont.Font3D(showtime.c_str());
		glEnable(GL_LIGHTING);
	}
	else
	{
		glDisable(GL_LIGHT1);
	}
	glPopMatrix();
}

Sun::~Sun(void)
{
}
