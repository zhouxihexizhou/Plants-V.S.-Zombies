#pragma once
#include <gl/glut.h>
#include "glVector.h"
#include "Time.h"
class Sun
{
public:
	Sun(void);
	~Sun(void);
	double seta;	//在天空中的角度
	double r;		//太阳大小半径
	double R;		//轨道半径
	Time* suntime;
	glVector pos;
	void Init(double a,double b,Time*);
	void Draw();
	void SetSeta(double base);
};

