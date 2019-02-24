#pragma once
#include <gl/glut.h>
#include "glVector.h"
class Glight
{
public:
	Glight(void);
	~Glight(void);
	float amb[4];			//������
	float dif[4];			//�������
	float spe[4];			//���淴���
	glVector pos;
	static int number;
	void SetAMB(float,float,float,float);
	void SetDIF(float,float,float,float);
	void SetSPE(float,float,float,float);
	void SetPos(glVector);
	int id;
	int GetID();
	void Shine();
	void Shut();
};

