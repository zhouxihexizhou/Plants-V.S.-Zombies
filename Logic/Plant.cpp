#pragma once
#include "stdafx.h"
#include "math.h"
#include "Ball.h"
#include "Texture.h"
int plantnum=0;
Ball head;	  //绘制头
Ball eye;	  //绘制眼镜
Ball leaf;	  //绘制叶子
Ball leaves;	//绘制双叶
Texture tex1;	//茎的纹理
Texture tex2;	//嘴的纹理

Plant :: Plant(int s)
{
	health=30;
	time=0;
	state=0;
	site=s;
	pos=s*Site_width;
	if(plantnum==0)
	{
		head.Init("bean");
		eye.Init("eye");
		leaf.Init("leaf");
		leaves.Init("leaves");
		tex1.Init("leaf.bmp");
		tex2.Init("leaf.bmp");
		plantnum++;
	}
}

void Plant :: setState(bool s)
{
	if(state!=s)
	{
		time=0;
	}
	state=s;
}

void Plant :: shoot()
{
	time++;
	if(Backmost>=site)     //当前植物前面有僵尸，进入射击模式
	{
		setState(1);
		if(time==PDamageSpeed)  //植物下一次射击的冷却时间已经完成
		{
			bul[Bullet_num]=new Bullet(pos);
			Bullet_num++;
			time=0;
		}
	}
	else                   //前方没有僵尸，此植物进入待机状态
	{
		setState(0);
	}
}

void Plant :: draw()
{
	float size=25;
	glPushMatrix();
	glTranslatef(-200,0,0);
	glTranslatef(pos,2*size,0);
	
	//头
	glPushMatrix();
	glColor3f(1,1,0);
	head.Draw(size*0.5);
	glTranslated(-15, 50, 0);
	glDisable(GL_LIGHTING);
	glColor3f(1, 0, 0);
	glScalef(25, 25, 25);
	m_pFont.Font3D(to_string(long long(health)).c_str());
	glEnable(GL_LIGHTING);
	//glScalef(1,1,1);
	//glutSolidSphere(size*0.5,36,36);
	glPopMatrix();
	
	//眼睛
	glPushMatrix();
	glColor3f(0,0,0);
	glScalef(1,1,1);
	glTranslatef(size*0.4,size*0.3,0.4*size);
	glRotatef(-60,0,0,1);
	eye.Draw(size*0.1);
	//glutSolidSphere(size*0.1,36,36);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0,0,0);
	glScalef(1,1,1);
	glTranslatef(size*0.4,0.3*size,-0.4*size);
	glRotatef(-60,0,0,1);
	eye.Draw(size*0.1);
	//glutSolidSphere(size*0.1,36,36);
	glPopMatrix();

	//头上叶子
	glPushMatrix();
	glColor3f(0,1,0);
	glRotatef(-45,0,0,1);
	glScalef(3,1,1.5);
	glTranslatef(size*(-0.2),0,0);
	leaf.Draw(size*0.15);
	//glutSolidSphere(size*0.15,36,36);
	glPopMatrix();

	//下方叶子
	glPushMatrix();
	glColor3f(0,1,0);
	glTranslatef(size*(-0.8),(-1.5)*size,0);
	glRotatef(-30,0,0,1);
	glScalef(4,1,1);
	leaves.Draw(size*0.2);
	//glutSolidSphere(size*0.2,36,36);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0,1,0);
	glTranslatef(size*0.8,(-1.5)*size,0);
	glRotatef(30,0,0,1);
	glScalef(4,1,1);
	leaves.Draw(size*0.2);
	//glutSolidSphere(size*0.2,36,36);
	glPopMatrix();

	//茎
	glColor3f(1,0,0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,tex1.id);
	glPushMatrix();
	glTranslatef(0,-size,0);
	glRotatef(90,1,0,0);
	glTranslatef(0,0,-0.6*size);
	glScalef(1,1,1);
	GLUquadricObj *quadratic;
	quadratic=gluNewQuadric();
	gluCylinder(quadratic,0.2*size,0.2*size,1.5*size,32,32);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	
	//嘴
	glColor3f(0,0.7,0.3);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,tex2.id);
	glPushMatrix();
	glTranslatef(size*0.5,0,0);
	glScalef(1,1,1);
	glRotatef(90,0,1,0);
	gluCylinder(quadratic,0.3*size,0.3*size,0.2*size,32,32);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();
}

void Plant :: takeDamage(int d)
{
	health-=d;
	if(health<=0)
	{
		road[site]=NULL;
		delete this;
	}
}

