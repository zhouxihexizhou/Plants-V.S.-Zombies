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
	bool rain;		//rainΪtrueʱ�����꣬rainΪfalseʱ����ѩ
private:
	void ResetParticle(int id,bool bFirst=false);	//�������ӵĳ�ʼ��״̬
	Particle m_particle[2000];
	int m_numParticle;    //�����õ����Ӹ���
	GLuint m_textureid[2];   //�������� 0���꣬1��ѩ
	int m_lasttime;		  //��¼�������е��ϴ�ʱ��
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
	void ResetParticle(int id,bool bFirst=false);	//�������ӵĳ�ʼ��״̬
	Particle m_particle[200];
	int m_numParticle;    //�����õ����Ӹ���
	GLuint m_textureid;   //�������� 0���꣬1��ѩ
	int m_lasttime;		  //��¼�������е��ϴ�ʱ��
	glVector pos;			//�ڵ���λ��
};