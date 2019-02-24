#pragma once
#include "glVector.h"
class Particle
{
public:
	void Draw();        //��������
	void BillBoard(const glVector &eyepos);
	Particle(void);
	~Particle(void);

	glVector m_pos;     //��������λ��
	double m_size;		//���ӵĴ�С
	double m_XYratio;	//���ӵĳ������
	glVector m_particleDir[4];	//��������billboardλ��ʱ�õ��ķ���
	glVector m_posCorner[4];	//���ӽǵ������

	double m_color[4];		//����������ɫ
	bool m_bActive;			//�����Ƿ���
	glVector m_speed;		//�ٶ�
	glVector m_acc;			//���ٶ�
	double m_lifetime;		//��������ʱ��
	double m_colorfade;	
};

