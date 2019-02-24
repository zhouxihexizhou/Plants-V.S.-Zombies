#pragma once
#include <gl/glut.h>
#include "glVector.h"
class Glight
{
public:
	Glight(void);
	~Glight(void);
	float amb[4];			//环境光
	float dif[4];			//漫反射光
	float spe[4];			//镜面反射光
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

