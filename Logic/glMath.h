#pragma once
#include <gl/glut.h>
#include "glVector.h"
class glMath
{
public:
	glMath(void);
	~glMath(void);
	static double InverseMatrix(double Matrix[],double inverseMatrix[]);
	static void CalculateNormal(glVector *vert,glVector *norm,int numRow,int numCol);
	static void Dir2HPR(glVector dir,glVector up,glVector &hpr);
};

