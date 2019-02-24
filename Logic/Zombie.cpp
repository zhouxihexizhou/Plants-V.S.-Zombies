#pragma once
#include "stdafx.h"
#include "math.h"
#include "Ball.h"
#include "Texture.h"
#include "Box.h"
#include "OpenGL.h"
Ball zomeye;
Ball zomhead;
Box arms;
Box legs;
Box body;
int zomnum=0;


Zombie :: Zombie(int ID)
{
	if(zomnum==0)
	{
		zomeye.Init("eye");
		zomhead.Init("zomhead");
		arms.Init("arms");
		legs.Init("legs");
		body.Init("body");
	}
	this->pos=ZInitPos;
	this->state=0;
	this->site=10;
	this->health=ZHealth;
	this->time=0;
	this->ID=ID;
	
	this->type_arm=0;
	this->type_leg=0;
	this->walk=true;
}



void Zombie :: draw()
{
	float size=25;
	glPushMatrix();
	glTranslatef(-200,0,0);
	glTranslatef(pos,2.5*size,0);
	glRotatef(90,0,1,0);
	//ͷ
	glPushMatrix();
	glColor3f(1,1,0);
	glScalef(1,1,1);
	glRotatef(-90,0,0,-1);
	//glutSolidSphere(size*0.5,36,36);
	zomhead.Draw(size*0.5);
	glRotatef(90, 0, 0, -1);
	glRotatef(-90, 0, 1, 0);
	glTranslated(-15, 50, 0);
	glDisable(GL_LIGHTING);
	glColor3f(1, 0, 0);
	glScalef(25, 25, 25);
	m_pFont.Font3D(to_string(long long(health)).c_str());
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//�۾�
	glPushMatrix();
	glColor3f(0,0,0);
	glScalef(1,1,1);
	glTranslatef(-size*0.4,0.1*size,-0.5*size);
	//glutSolidSphere(size*0.12,36,36);
	zomeye.Draw(size*0.12);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0,0,0);
	glScalef(1,1,1);
	glTranslatef(-size*0.4,0.1*size,-0.5*size);
	//glutSolidSphere(size*0.12,36,36);
	zomeye.Draw(size*0.12);
	glPopMatrix();
	
	//��
	glPushMatrix();
	glColor3f(1,0,0);
	glScalef(2,1,1);
	glTranslatef(0,-0.1*size,-0.4*size);
	glutSolidSphere(size*0.12,36,36);
	glPopMatrix();

	//����
	glColor3f(1,0,0);
	glPushMatrix();
	glTranslatef(0,-size,0);
	glScalef(1,1,0.3);
	//glutSolidCube(size);
	body.Draw(size,size,size);
	glPopMatrix();
	//�첲
	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(-size*0.4,-size*0.7,0);
	if(walk==false){
	    if(type_arm==0){
	        glRotatef(-45,1,0,0);
	    }else if(type_arm==1){
	        glRotatef(0,1,0,0);
	    }else if(type_arm==2){
	        glRotatef(45,1,0,0);
	    }
	}
	glTranslatef(0,0,-size*0.8);
	glScalef(0.2,0.2,1.3);
	//glutSolidCube(size);
	arms.Draw(size,size,size);
	glPopMatrix();
	//�첲
	glColor3f(0,1,0);
	glPushMatrix();
	glTranslatef(size*0.4,-size*0.7,0);
	if(walk==false){
	    if(type_arm==0){
	        glRotatef(45,1,0,0);
	    }else if(type_arm==1){
	        glRotatef(0,1,0,0);
	    }else if(type_arm==2){
	        glRotatef(-45,1,0,0);
	    }
	}
	glTranslatef(0,0,-size*0.8);
	glScalef(0.2,0.2,1.3);
	//glutSolidCube(size);
	arms.Draw(size,size,size);
	glPopMatrix();
	//��
	glColor3f(0,0,1);
	glPushMatrix();
	glTranslatef(-size*0.4,-size*1.5,0);
	if(walk==true){
	    if(type_arm==0){
	        glRotatef(45,1,0,0);
	    }else if(type_arm==1){
	        glRotatef(0,1,0,0);
	    }else if(type_arm==2){
	        glRotatef(-45,1,0,0);
	    }
	}
	glTranslatef(0,-size*0.5,0);
	glScalef(0.2,1.2,0.2);
	//glutSolidCube(size);
	legs.Draw(size,size,size);
	glPopMatrix();
	//��
	glColor3f(0,0,1);
	glPushMatrix();
	glTranslatef(size*0.4,-size*1.5,0);
	if(walk==true){
	    if(type_arm==0){
	        glRotatef(-45,1,0,0);
	    }else if(type_arm==1){
	        glRotatef(0,1,0,0);
	    }else if(type_arm==2){
	        glRotatef(45,1,0,0);
	    }
	}
	glTranslatef(0,-size*0.5,0);
	glScalef(0.2,1.2,0.2);
	//glutSolidCube(size);
	legs.Draw(size,size,size);
	glPopMatrix();
	glPopMatrix();
}

void Zombie ::Inwhichsite()
{
	site=int(pos/Site_width);
}

void Zombie :: setState(bool s)
{
	if(state!=s)   //ÿ��״̬ת�����轫��ʱ������  
	{
		time=0;
	}
	state=s;
}

void Zombie :: update()
{
	Inwhichsite();
	time++;
	if(time%5==0){      //���ƶ���
		type_arm++;
		if(type_arm==3){
		    type_arm=0;
		}
	}
	if(time%10==0){    //���ƶ���
		type_leg++;
		if(type_leg==3){
		    type_leg=0;
		}
	}
	if(pos<=0)  //��ʬ����������ӣ�������
	{
		//printf("������ӱ����ˣ�������\n");
		//system("pause");
		gameOver = true;
	}
	else
	{
		if(site<Site_num)
		{
			if(road[site]!=NULL)   //��ǰ��������ֲ���ʬ��Ϊ����ģʽ
			{
				setState(1);
			}
			else                   //��ǰ��������ֲ���ʬ��Ϊ����ģʽ
			{
				setState(0);
			}
		}
		else                      //��ֲ���������⣬��ʬΪ����ģʽ
		{
			setState(0);
		}
	}
	if(state==1)             //����ģʽ��ʬ��Ϊ
	{
		if(time==ZDamageSpeed)   //������ȴ���
		{
			int damage=ZDamage;
			road[site]->takeDamage(damage);
			time=0;
		}
		walk=false;
	}
	else                     //����ģʽ��ʬ��Ϊ
	{
		pos-=WalkSpeed;
		Inwhichsite();
		walk=true;
	}
}

void Zombie :: die()
{
	int i;
	for(i=ID+1;i<Zombie_num;i++)
	{
		zom[i-1]=zom[i];
		zom[i-1]->ID=i-1;
	}
	zom[i]=NULL;
	Zombie_num--;
	remain_zombie--;
	delete this;
}

void Zombie :: takeDamage(int d)
{
	health-=d;
	if(health <= 0)
	{
		die();
	}
}

int Zombie :: getSite()
{
	return this->site;
}

float Zombie ::getPos()
{
	return this->pos;
}
