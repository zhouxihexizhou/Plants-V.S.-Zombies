#include "StdAfx.h"
#include "Glight.h"

int Glight::number=0;
Glight::Glight(void)
{
	id=number;
	pos.Set(0,0,0);
	for(int i=0;i<4;i++)
	{
		amb[i]=0;
		dif[i]=0;
		spe[i]=0;
	}
	number++;
}
int Glight::GetID()
{
	return id;
}
Glight::~Glight(void)
{
}
void Glight::SetAMB(float a,float b,float c,float d)
{
	amb[0]=a;
	amb[1]=b;
	amb[2]=c;
	amb[3]=d;
}
void Glight::SetDIF(float a,float b,float c,float d)
{
	dif[0]=a;
	dif[1]=b;
	dif[2]=c;
	dif[3]=d;
}
void Glight::SetSPE(float a,float b,float c,float d)
{
	spe[0]=a;
	spe[1]=b;
	spe[2]=c;
	spe[3]=d;
}
void Glight::SetPos(glVector v)
{
	pos=v;
	Shine();
}
void Glight::Shine()
{
	glEnable(GL_LIGHTING);
	float position[4];
	for(int i=0;i<3;i++)
		position[i]=pos[i];
	position[3]=0;
	switch(id)
	{
	case 0:
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0,GL_AMBIENT,amb);			
		glLightfv(GL_LIGHT0,GL_DIFFUSE,dif);
		glLightfv(GL_LIGHT0,GL_SPECULAR,spe);
		glLightfv(GL_LIGHT0,GL_POSITION,position);
		break;
	case 1:
		glEnable(GL_LIGHT1);
		glLightfv(GL_LIGHT1,GL_AMBIENT,amb);			
		glLightfv(GL_LIGHT1,GL_DIFFUSE,dif);
		glLightfv(GL_LIGHT1,GL_SPECULAR,spe);
		glLightfv(GL_LIGHT1,GL_POSITION,position);
		break;
	case 2:
		glEnable(GL_LIGHT2);
		glLightfv(GL_LIGHT2,GL_AMBIENT,amb);			
		glLightfv(GL_LIGHT2,GL_DIFFUSE,dif);
		glLightfv(GL_LIGHT2,GL_SPECULAR,spe);
		glLightfv(GL_LIGHT2,GL_POSITION,position);
		break;
	case 3:
		glEnable(GL_LIGHT3);
		glLightfv(GL_LIGHT3,GL_AMBIENT,amb);			
		glLightfv(GL_LIGHT3,GL_DIFFUSE,dif);
		glLightfv(GL_LIGHT3,GL_SPECULAR,spe);
		glLightfv(GL_LIGHT3,GL_POSITION,position);
		break;
	case 4:
		glEnable(GL_LIGHT4);
		glLightfv(GL_LIGHT4,GL_AMBIENT,amb);			
		glLightfv(GL_LIGHT4,GL_DIFFUSE,dif);
		glLightfv(GL_LIGHT4,GL_SPECULAR,spe);
		glLightfv(GL_LIGHT4,GL_POSITION,position);
		break;
	case 5:
		glEnable(GL_LIGHT5);
		glLightfv(GL_LIGHT5,GL_AMBIENT,amb);			
		glLightfv(GL_LIGHT5,GL_DIFFUSE,dif);
		glLightfv(GL_LIGHT5,GL_SPECULAR,spe);
		glLightfv(GL_LIGHT5,GL_POSITION,position);
		break;
	}
}
void Glight::Shut()
{
	switch(id)
	{
	case 0:
		glDisable(GL_LIGHT0);
		break;
	case 1:
		glDisable(GL_LIGHT1);
		break;
	case 2:
		glDisable(GL_LIGHT2);
		break;
	case 3:
		glDisable(GL_LIGHT3);
		break;
	case 4:
		glDisable(GL_LIGHT4);
		break;
	case 5:
		glDisable(GL_LIGHT5);
		break;
	}
}