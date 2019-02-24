#pragma once
#include "glVector.h"
class Camera
{
public:
	Camera(void);
	~Camera(void);
	void Init(void);
	void ShowView();          //��ͼ����
	void Rotate(int dir,double len);
	void Move(int dir,double len);
	glVector m_pos;           //�ӵ㵱ǰλ��
	glVector m_hpr;           //�ӵ㷽���,x::h,y::p,z::r
	glVector m_eyedir;        //���߷���
	glVector m_updir;         //�Ϸ�����
	double m_viewMatrix[16];  //��ͼ����
	double m_viewMatrixInverse[16];   //��ͼ���������
	double m_viewMatrixSave[16];      //�������ͼ����
};

