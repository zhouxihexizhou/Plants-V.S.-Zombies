#pragma once
#include "Particle.h"
#include <gl/glut.h>
#include "Texture.h"
#include "glVector.h"
class glParticleCtrl
{
public:
	void Draw();
	void UpdatePos();
	void Init(int num);
	glParticleCtrl(void);
	~glParticleCtrl(void);
	Texture PartTex;
	bool rain;		//rain为true时是下雨，rain为false时是下雪
private:
	void ResetParticle(int id,bool bFirst=false);	//设置粒子的初始化状态
	Particle m_particle[2000];
	int m_numParticle;    //仿真用的粒子个数
	GLuint m_textureid[2];   //粒子纹理 0是雨，1是雪
	int m_lasttime;		  //记录粒子运行的上次时间
};
class fireParticleCtrl
{
public :
	fireParticleCtrl(void);
	~fireParticleCtrl();
	void Draw();
	void UpdatePos();
	void Init(int num);
	Texture PartTex;
	void SetPos(glVector );
private:
	void ResetParticle(int id,bool bFirst=false);	//设置粒子的初始化状态
	Particle m_particle[200];
	int m_numParticle;    //仿真用的粒子个数
	GLuint m_textureid;   //粒子纹理 0是雨，1是雪
	int m_lasttime;		  //记录粒子运行的上次时间
	glVector pos;			//炮弹的位置
};