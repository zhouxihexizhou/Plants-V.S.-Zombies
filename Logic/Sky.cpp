#include "StdAfx.h"
#include "Sky.h"
#include <iostream>
#include <string>
using namespace std;
Sky::Sky(void)
{
}


Sky::~Sky(void)
{
}
void Sky::InitSky(double R)
{
	Radius=R;
	string name="sky";
	for(int i=0;i<6;i++)
	{
		name="sky"+to_string(long long(i+1))+".bmp";
		tex[i].Init(name);
	}
}
void Sky::ShowSky()
{
	glEnable(GL_TEXTURE_2D);
	//glEnable(GL_FRONT);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glPushMatrix();
	//前
	glBindTexture(GL_TEXTURE_2D,tex[0].id);
	glBegin(GL_QUADS);
	glTexCoord2f( 0.0, 0.0 );   glVertex3f( -Radius, 0, -2*Radius );  //左下
	glTexCoord2f( 0.0, 1.0 );   glVertex3f( -Radius,  2*Radius,  -2*Radius);  //右下
	glTexCoord2f( 1.0, 1.0 );   glVertex3f(  Radius,  2*Radius,  -2*Radius);  //右上
	glTexCoord2f( 1.0, 0.0 );   glVertex3f(  Radius, 0,  -2*Radius);  //左上
	glEnd();
	//前
	glBindTexture(GL_TEXTURE_2D,tex[0].id);
	glBegin(GL_QUADS);
	glTexCoord2f( 0.0, 0.0 );   glVertex3f( -Radius, 0, -Radius );  //左下
	glTexCoord2f( 0.0, 1.0 );   glVertex3f( -Radius,  2*Radius, -Radius );  //右下
	glTexCoord2f( 1.0, 1.0 );   glVertex3f(  Radius,  2*Radius, -Radius );  //右上
	glTexCoord2f( 1.0, 0.0 );   glVertex3f(  Radius, 0, -Radius );  //左上
	glEnd();
	//后
	glBindTexture(GL_TEXTURE_2D,tex[2].id);
	glBegin(GL_QUADS);
	glTexCoord2f( 0.0, 0.0 );   glVertex3f( Radius, 0, Radius );  //左下
	glTexCoord2f( 0.0, 1.0 );   glVertex3f( Radius,  2*Radius, Radius );  //右下
	glTexCoord2f( 1.0, 1.0 );   glVertex3f(  -Radius,  2*Radius, Radius );  //右上
	glTexCoord2f( 1.0, 0.0 );   glVertex3f(  -Radius, 0, Radius );  //左上
	glEnd();
	//左
	glBindTexture(GL_TEXTURE_2D,tex[1].id);
	glBegin(GL_QUADS);
	glTexCoord2f( 0.0, 0.0 );   glVertex3f( -Radius, 0, Radius );  //左下
	glTexCoord2f( 0.0, 1.0 );   glVertex3f( -Radius,  2*Radius, Radius );  //右下
	glTexCoord2f( 1.0, 1.0 );   glVertex3f(  -Radius,  2*Radius, -Radius );  //右上
	glTexCoord2f( 1.0, 0.0 );   glVertex3f(  -Radius, 0, -Radius );  //左上
	glEnd();
	//右
	glBindTexture(GL_TEXTURE_2D,tex[3].id);
	glBegin(GL_QUADS);
	glTexCoord2f( 0.0, 0.0 );   glVertex3f( Radius, 0, -Radius );  //左下
	glTexCoord2f( 0.0, 1.0 );   glVertex3f( Radius,  2*Radius, -Radius );  //右下
	glTexCoord2f( 1.0, 1.0 );   glVertex3f(  Radius,  2*Radius, Radius );  //右上
	glTexCoord2f( 1.0, 0.0 );   glVertex3f(  Radius, 0, Radius );  //左上
	glEnd();
	//下
	glBindTexture(GL_TEXTURE_2D,tex[5].id);
	glBegin(GL_QUADS);
	glTexCoord2f( 0.0, 0.0 );   glVertex3f( -Radius, 0, -Radius );  //左下
	glTexCoord2f( 0.0, 1.0 );   glVertex3f( Radius,  0, -Radius );  //右下
	glTexCoord2f( 1.0, 1.0 );   glVertex3f(  Radius,  0, Radius );  //右上
	glTexCoord2f( 1.0, 0.0 );   glVertex3f(  -Radius, 0, Radius );  //左上
	glEnd();
	//上
	glBindTexture(GL_TEXTURE_2D,tex[4].id);
	glBegin(GL_QUADS);
	glTexCoord2f( 0.0, 0.0 );   glVertex3f( Radius, 2*Radius, -Radius );  //左下
	glTexCoord2f( 0.0, 1.0 );   glVertex3f( -Radius,  2*Radius, -Radius );  //右下
	glTexCoord2f( 1.0, 1.0 );   glVertex3f(  -Radius,  2*Radius, Radius );  //右上
	glTexCoord2f( 1.0, 0.0 );   glVertex3f(  Radius, 2*Radius, Radius );  //左上
	glEnd();
	glPopMatrix();
}