#pragma once
#include "Texture.h"
#include <iostream>
#include <string>
using namespace std;
class Box
{
public:
	Box(void);
	~Box(void);
	double chang;
	double kuan;
	double gao;
	Texture tex;
	void Draw(double a,double b,double c);
	void Init(string);
};

