#include "StdAfx.h"
#include "Box.h"


Box::Box(void)
{
	chang=0;
	kuan=0;
	gao=0;
}

void Box::Init(string name)
{
	
	tex.Init(name+".bmp");
}

Box::~Box(void)
{
}

void Box::Draw(double a,double b,double c)
{
	chang=a;
	kuan=b;
	gao=c;
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex.id);
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	// Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-kuan/2.0, -gao/2.0,  chang/2.0);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f( kuan/2.0, -gao/2.0,  chang/2.0);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f( kuan/2.0,  gao/2.0,  chang/2.0);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-kuan/2.0,  gao/2.0,  chang/2.0);	// Top Left Of The Texture and Quad
	// Back Face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-kuan/2.0, -gao/2.0, -chang/2.0);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-kuan/2.0,  gao/2.0, -chang/2.0);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f( kuan/2.0,  gao/2.0, -chang/2.0);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f( kuan/2.0, -gao/2.0, -chang/2.0);	// Bottom Left Of The Texture and Quad
	// Top Face
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-kuan/2.0,  gao/2.0, -chang/2.0);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-kuan/2.0,  gao/2.0,  chang/2.0);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f( kuan/2.0,  gao/2.0,  chang/2.0);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f( kuan/2.0,  gao/2.0, -chang/2.0);	// Top Right Of The Texture and Quad
	// Bottom Face
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-kuan/2.0, -gao/2.0, -chang/2.0);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f( kuan/2.0, -gao/2.0, -chang/2.0);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f( kuan/2.0, -gao/2.0,  chang/2.0);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-kuan/2.0, -gao/2.0,  chang/2.0);	// Bottom Right Of The Texture and Quad
	// Right face
	glTexCoord2f(1.0f, 0.0f); glVertex3f( kuan/2.0, -gao/2.0, -chang/2.0);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f( kuan/2.0,  gao/2.0, -chang/2.0);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f( kuan/2.0,  gao/2.0,  chang/2.0);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f( kuan/2.0, -gao/2.0,  chang/2.0);	// Bottom Left Of The Texture and Quad
	// Left Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-kuan/2.0, -gao/2.0, -chang/2.0);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-kuan/2.0, -gao/2.0,  chang/2.0);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-kuan/2.0,  gao/2.0,  chang/2.0);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-kuan/2.0,  gao/2.0, -chang/2.0);	// Top Left Of The Texture and Quad
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}