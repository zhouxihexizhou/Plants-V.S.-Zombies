#pragma once
#include "stdafx.h"
#include "Box.h"
Box ground;
int boxnum=0;
void Road ::draw()
{
	glPushMatrix();
	glTranslatef(-200,0,0);
	float size=25;
	int i=0;
	for(i=0;i<Site_num;i++)
	{
		glPushMatrix();
		glTranslatef(i*Site_width,0,0);
		glColor3f(1,0,0);
		//glScalef(1,0.2,1);
		//glutSolidCube(size);
		ground.Draw(size,size,size*0.2);
		glPopMatrix();
	}
	glPopMatrix();
}

void Road :: create(int s)
{
	if(boxnum==0)
	{
		ground.Init("timg");
		boxnum++;
	}
	if(sun>=100 && road[s]==NULL)
	{
		road[s]=new Plant(s);
		sun-=100;
	}

}