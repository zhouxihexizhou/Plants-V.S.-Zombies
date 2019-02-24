#pragma once
#include <gl/glut.h>
#include "Camera.h"
#include "GControl.h"
#include "Texture.h"
#include "glParticleCtrl.h"
#include "Sky.h"
#include "Time.h"
#include "GFont.h"
#include "Sun.h"
#include "Glight.h"
#include "Box.h"
class OpenGL
{
public:
	OpenGL(void);
	~OpenGL(void);
	void OnPaint(void);
	bool PreTranslateMessage(unsigned int message, unsigned int wParam, unsigned int lParam);
	bool Init(HWND hWnd);
	void OnSize(int w, int h);

	Sky sky;
	Sun suna;
	Box box;
	Glight light0;
	Glight light1;
	glParticleCtrl m_particle;
	Camera *m_pCamera;
	GControl *m_pControl;
	GFont *m_pFont;
	Time *m_pTime;
	HWND m_hWnd;
	HDC m_hDC;
	HGLRC m_hglrc;
	double m_PerspectiveParam[4];


	void OnView(void);
	void InDraw(void);
};

