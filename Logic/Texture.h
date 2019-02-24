#pragma once
#define GL_CLAMP_TO_EDGE 0x812F
#include "opengl/glaux.h"
#include <iostream>
using namespace std;
#pragma comment(lib,"glaux.lib")
class Texture
{
public:
	Texture(void);
	~Texture(void);
	static GLuint Num;
	GLuint id;
	string picname;
	GLuint Init(string);
	GLuint getId();
};

