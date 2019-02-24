#pragma once
#include "stdafx.h"
#include "math.h"
#include "Ball.h"
#include "Texture.h"
int plantnum=0;
Ball head;	  //����ͷ
Ball eye;	  //�����۾�
Ball leaf;	  //����Ҷ��
Ball leaves;	//����˫Ҷ
Texture tex1;	//��������
Texture tex2;	//�������

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
	if(Backmost>=site)     //��ǰֲ��ǰ���н�ʬ���������ģʽ
	{
		setState(1);
		if(time==PDamageSpeed)  //ֲ����һ���������ȴʱ���Ѿ����
		{
			bul[Bullet_num]=new Bullet(pos);
			Bullet_num++;
			time=0;
		}
	}
	else                   //ǰ��û�н�ʬ����ֲ��������״̬
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
	
	//ͷ
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
	
	//�۾�
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

	//ͷ��Ҷ��
	glPushMatrix();
	glColor3f(0,1,0);
	glRotatef(-45,0,0,1);
	glScalef(3,1,1.5);
	glTranslatef(size*(-0.2),0,0);
	leaf.Draw(size*0.15);
	//glutSolidSphere(size*0.15,36,36);
	glPopMatrix();

	//�·�Ҷ��
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

	//��
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
	
	//��
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

