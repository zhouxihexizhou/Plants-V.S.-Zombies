#pragma once
#include <gl/glut.h>
#include "Texture.h"
#include <iostream>
#include <string>
using namespace std;
class Ball
{
public:
	void Init(string);
	Ball(void);
	~Ball(void);
	void Draw(double);

	double radius;
	GLUquadricObj *qobj;
	Texture tex;
};

