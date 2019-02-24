#include "StdAfx.h"
#include "Camera.h"
#include <gl/glut.h>
#include "glMath.h"
Camera::Camera(void)
{
	Init();
}


Camera::~Camera(void)
{
}


void Camera::Init(void)
{
	m_pos=glVector(40.9477,260.606,341.608);
	m_eyedir=glVector(-0.0539763,-0.462267,-0.885104);
	m_updir=glVector(-0.0228217,0.886732,-0.461734);
	m_hpr=glVector(0,0,0);
	int i;
	for(i=0;i<16;i++)
	{
		if(i==0||i==5||i==10||i==15)
		{
			m_viewMatrix[i]=1;
			m_viewMatrixSave[i]=1;
		}
		else
		{
			m_viewMatrixSave[i]=0;
			m_viewMatrix[i]=0;
		}
	}
}
void Camera::Move(int dir,double len)      //dir=0表示左右移，dir=1表示上下移，dir=2表示前后移
{
	glPushMatrix();
	glLoadIdentity();
	if(dir==0)
		glTranslatef(-len,0,0);
	else if(dir==1)
		glTranslatef(0,-len,0);
	else
		glTranslatef(0,0,-len);
	glMultMatrixd(m_viewMatrix);
	glGetDoublev(GL_MODELVIEW_MATRIX,m_viewMatrix);
	glMath::InverseMatrix(m_viewMatrix,m_viewMatrixInverse);
	glPopMatrix();
	m_pos=&m_viewMatrixInverse[12];
}
void Camera::Rotate(int dir,double len)//dir=0表示左右转，dir=1表示上下转，dir=2表示滚动转
{
	glPushMatrix();
	glLoadIdentity();
	if(dir==0)		
		glRotated(-len,0,1,0);	//h
	else if(dir==1)
		glRotated(-len,1,0,0);	//p
	else
		glRotated(-len,0,0,1);	//r
	glMultMatrixd(m_viewMatrix);
	glGetDoublev(GL_MODELVIEW_MATRIX,m_viewMatrix);
	glMath::InverseMatrix(m_viewMatrix,m_viewMatrixInverse);
	glPopMatrix();
	m_eyedir=m_viewMatrixInverse*glVector(0,0,-1);
	m_eyedir-=m_pos;
	m_updir=m_viewMatrixInverse*glVector(0,1,0);
	m_updir-=m_pos;
}
void Camera::ShowView()
{
	if(m_pos.x<-480)
		m_pos.x=-480;
	else if(m_pos.x>480)
		m_pos.x=480;
	if(m_pos.y<20)
		m_pos.y=20;
	else if(m_pos.y>980)
		m_pos.y=980;
	if(m_pos.z<-480)
		m_pos.z=-480;
	else if(m_pos.z>480)
		m_pos.z=480;
	gluLookAt(	m_pos.x,m_pos.y,m_pos.z,
		m_pos.x+m_eyedir.x,m_pos.y+m_eyedir.y,m_pos.z+m_eyedir.z,
		m_updir.x,m_updir.y,m_updir.z
		);
	glGetDoublev(GL_MODELVIEW_MATRIX,m_viewMatrix);
	glMath::InverseMatrix(m_viewMatrixInverse,m_viewMatrixInverse);
}
