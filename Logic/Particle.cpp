#include "StdAfx.h"
#include "Particle.h"
#include<gl/glut.h>

Particle::Particle(void)
{
	m_color[0]=m_color[1]=m_color[2]=m_color[3]=1;
	m_particleDir[1].Set(0,1,0);
	m_size=10;
	m_XYratio=2;
	m_bActive=false;
}


Particle::~Particle(void)
{
}
void Particle::Draw()
{
	glColor4dv(m_color);
	glBegin(GL_TRIANGLE_STRIP);

	glTexCoord2f(0,0);	glVertex3dv(m_posCorner[0]);
	glTexCoord2f(0,1);	glVertex3dv(m_posCorner[1]);
	glTexCoord2f(1,0);	glVertex3dv(m_posCorner[2]);
	glTexCoord2f(1,1);	glVertex3dv(m_posCorner[3]);

	glEnd();
}
void Particle::BillBoard(const glVector &eyepos)
{
	m_particleDir[0] = eyepos-m_pos;
	m_particleDir[0].Normalize();
	m_particleDir[2] = m_particleDir[0].crossMul(m_particleDir[1]);
	m_particleDir[3] = m_particleDir[2].crossMul(m_particleDir[0]);
	glVector posleft = m_pos+m_particleDir[2]*m_size;
	glVector posright = m_pos-m_particleDir[2]*m_size;
	m_posCorner[0] = posleft+m_particleDir[3]*m_size*m_XYratio;
	m_posCorner[1] = posleft-m_particleDir[3]*m_size*m_XYratio;
	m_posCorner[2] = posright+m_particleDir[3]*m_size*m_XYratio;
	m_posCorner[3] = posright-m_particleDir[3]*m_size*m_XYratio;
}