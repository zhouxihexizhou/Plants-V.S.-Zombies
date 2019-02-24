#pragma once
#include <gl/glut.h>
#include "Texture.h"
class Texture;
class Sky
{
public:
	Sky(void);
	void InitSky(double);
	void ShowSky(void);
	~Sky(void);
private:
	Texture tex[6];
	double Radius;
};

