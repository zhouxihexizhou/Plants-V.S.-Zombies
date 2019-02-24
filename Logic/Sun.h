#pragma once
#include <gl/glut.h>
#include "glVector.h"
#include "Time.h"
class Sun
{
public:
	Sun(void);
	~Sun(void);
	double seta;	//������еĽǶ�
	double r;		//̫����С�뾶
	double R;		//����뾶
	Time* suntime;
	glVector pos;
	void Init(double a,double b,Time*);
	void Draw();
	void SetSeta(double base);
};

