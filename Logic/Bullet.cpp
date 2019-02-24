#pragma once
#include "stdafx.h"
#include "math.h"
#include "Ball.h"
#include "glParticleCtrl.h"
fireParticleCtrl fire;
Ball ball;
int num=0;
Bullet ::Bullet(float p)
{
	Initpos=p;
	pos=p;
	ID=Bullet_num;
	index=num%5;
	if(num==0)
	{
		ball.Init("metal");
	}
	num++;
	fire.SetPos(glVector(-80,0,0));
	fire.Init(200);
}

void Bullet :: destroy()
{
	int i;
	for(i=ID+1;i<Bullet_num;i++)
	{
		bul[i-1]=bul[i];		bul[i-1]->ID=i-1;
	}
	bul[i]=NULL;
	Bullet_num--;
	//delete &ball;
	delete this;
}

void Bullet :: update()
{
	pos+=BulletSpeed;
	if(pos> 11*Site_width)    //子弹飞出了边界，进行销毁
	{
		destroy();
	}
	for(int i=0;i<Zombie_num;i++)
	{
		if(zom[i]->getPos()>=Initpos && zom[i]->getPos()<=pos) //击中了一名僵尸
		{
			int damage=PDamage;
			zom[i]->takeDamage(damage);
			destroy();
		}
		else if(zom[i]->getPos()>pos)
		{
			break;
		}
	}
}

void Bullet :: draw()
{
	float size=25;
	glPushMatrix();
	glTranslatef(-200,0,0);
	glTranslatef(pos,2*size,0);
	fire.SetPos(glVector(-8,0,0));
	fire.UpdatePos();
	fire.Draw();
	glColor3f(1,1,0);
	glScalef(1,1,1);
	ball.Draw(size*0.3);
	//glutSolidSphere(size*0.3,36,36);
	glPopMatrix();
}

