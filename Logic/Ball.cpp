#include "StdAfx.h"
#include "Ball.h"


Ball::Ball(void)
{
	radius=0;
	qobj = gluNewQuadric();
	gluQuadricNormals(qobj,GLU_SMOOTH);
	gluQuadricTexture(qobj,GL_TRUE);
}

void Ball::Init(string name)
{
	tex.Init(name+".bmp");
}
void Ball::Draw(double r)
{
	radius=r;
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, tex.id);
	glColor4f(1,1,1,1);
	gluSphere(qobj,radius,32,32);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}
Ball::~Ball(void)
{
	
}
