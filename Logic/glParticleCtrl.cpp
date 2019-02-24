#include "StdAfx.h"
#include "glParticleCtrl.h"
#include "OpenGL.h"
#include "glMath.h"
glParticleCtrl::glParticleCtrl(void)
{
}
fireParticleCtrl::fireParticleCtrl(void)
{
}
glParticleCtrl::~glParticleCtrl(void)
{
}
fireParticleCtrl::~fireParticleCtrl(void)
{
}
void glParticleCtrl::Init(int num)
{
	m_numParticle=num;
	int i;
	m_lasttime=GetTickCount();
	srand(m_lasttime);
	for(i=0;i<m_numParticle;i++)
		ResetParticle(i,true);
	PartTex.Init("雨.bmp");
	m_textureid[0]=PartTex.getId();
	PartTex.Init("雪花.bmp");
	m_textureid[1]=PartTex.getId();
	rain=false;
}
void fireParticleCtrl::Init(int num)
{
	m_numParticle=num;
	int i;
	m_lasttime=GetTickCount();
	srand(m_lasttime);
	for(i=0;i<m_numParticle;i++)
		ResetParticle(i,true);
	PartTex.Init("fire.bmp");
	m_textureid=PartTex.getId();
}
void glParticleCtrl::UpdatePos()
{
	double mat[16],imat[16];
	glGetDoublev(GL_MODELVIEW_MATRIX,mat);
	glMath::InverseMatrix(mat,imat);
	glVector eyepos=imat*glVector(0,0,0);
	int i;
	int curtime=GetTickCount();
	double usetime=(curtime-m_lasttime)/1000.0;
	m_lasttime=curtime;
	bool g_bPause=false;
	//记录暂停
	//extern bool g_bPause;
	for(i=0;i<m_numParticle;i++)
	{
		if(m_particle[i].m_bActive)    //活的粒子
		{
			m_particle[i].m_lifetime-=1;
			if(!g_bPause)
			{
				m_particle[i].m_speed+=usetime*m_particle[i].m_acc;
				m_particle[i].m_pos+=usetime*m_particle[i].m_speed;
			}
			if(m_particle[i].m_pos[1]<0)
				m_particle[i].m_bActive=false;
		}
		else                          //重新激活粒子
		{
			ResetParticle(i);
		}
		m_particle[i].BillBoard(eyepos);
	}
}
void fireParticleCtrl::UpdatePos()
{
	double mat[16],imat[16];
	glGetDoublev(GL_MODELVIEW_MATRIX,mat);
	glMath::InverseMatrix(mat,imat);
	glVector eyepos=imat*glVector(0,0,0);
	int i;
	int curtime=GetTickCount();
	double usetime=(curtime-m_lasttime)/1000.0;
	m_lasttime=curtime;
	bool g_bPause=false;
	//记录暂停
	//extern bool g_bPause;
	for(i=0;i<m_numParticle;i++)
	{
		if(m_particle[i].m_bActive)    //活的粒子
		{
			m_particle[i].m_lifetime-=1;
			if(!g_bPause)
			{
				m_particle[i].m_speed+=usetime*m_particle[i].m_acc;
				m_particle[i].m_pos+=usetime*m_particle[i].m_speed;
			}
			if(m_particle[i].m_pos[0]<(pos.x-(double(rand())/RAND_MAX)*50))
				m_particle[i].m_bActive=false;
		}
		else                          //重新激活粒子
		{
			ResetParticle(i);
		}
		m_particle[i].BillBoard(eyepos);
	}
}
void glParticleCtrl::Draw()
{
	glPushAttrib(GL_ENABLE_BIT|GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT );
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE);
	glDepthMask(GL_FALSE);
	glEnable(GL_TEXTURE_2D);
	if(rain)
		glBindTexture(GL_TEXTURE_2D,m_textureid[0]);
	else
		glBindTexture(GL_TEXTURE_2D,m_textureid[1]);
	for(int i=0;i<m_numParticle;i++)
	{
		if(m_particle[i].m_bActive)
			m_particle[i].Draw();
	}
	glPopAttrib();
}
void fireParticleCtrl::Draw()
{
	glPushAttrib(GL_ENABLE_BIT|GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT );
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE);
	glDepthMask(GL_FALSE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,m_textureid);
	for(int i=0;i<m_numParticle;i++)
	{
		if(m_particle[i].m_bActive)
			m_particle[i].Draw();
	}
	glPopAttrib();
}
//对系统的所有粒子进行一个设置
void glParticleCtrl::ResetParticle(int id,bool bFirst)
{
	m_particle[id].m_bActive=true;
	//初始位置
	m_particle[id].m_pos.x=	(double(rand())/RAND_MAX)*1000-500;
	m_particle[id].m_pos.z=	(double(rand())/RAND_MAX)*1000-500;
	if(bFirst)
		m_particle[id].m_pos.y=	(double(rand())/RAND_MAX)*1000;
	else
		m_particle[id].m_pos.y=	1000;

	m_particle[id].m_lifetime=100;
	m_particle[id].m_acc.Set(0,-10,0);
	double speed=double(rand())/RAND_MAX*30+1;
	glVector movedir;
	double seta=double(rand())/RAND_MAX*PAI/3;   //30度以内
	movedir[0]=sin(seta);
	movedir[1]=-1;
	movedir[2]=0;
	movedir.Normalize();
	m_particle[id].m_speed=movedir*speed;
	m_particle[id].m_size=1;
	m_particle[id].m_color[3]=1;
}

void fireParticleCtrl::SetPos(glVector p)
{
	pos=p;
}
void fireParticleCtrl::ResetParticle(int id,bool bFirst)
{
	m_particle[id].m_bActive=true;
	//初始位置
	m_particle[id].m_pos.y=	(double(rand())/RAND_MAX)*10-5+pos.y;
	m_particle[id].m_pos.z=	(double(rand())/RAND_MAX)*10-5+pos.z;
	if(bFirst)
		m_particle[id].m_pos.x=	(double(rand())/RAND_MAX)*50+pos.x;
	else
		m_particle[id].m_pos.x=	pos.x;

	m_particle[id].m_lifetime=100;
	m_particle[id].m_acc.Set(-3,0,0);
	double speed=double(rand())/RAND_MAX*15+1;
	glVector movedir;
	double seta=double(rand())/RAND_MAX*PAI/3-PAI/6.0;   //30度以内
	movedir[0]=-1;
	movedir[1]=sin(seta);
	movedir[2]=sin(seta);
	movedir.Normalize();
	m_particle[id].m_speed=movedir*speed;
	m_particle[id].m_size=1;
	m_particle[id].m_color[3]=1;
}