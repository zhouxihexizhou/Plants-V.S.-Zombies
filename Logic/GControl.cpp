#include "StdAfx.h"
#include "GControl.h"
#include "Camera.h"
#include "OpenGL.h"

extern bool pause;
extern bool gameOver;
GControl::GControl(OpenGL *pGL)
{
	for(int i=0;i<ALL;i++)
		m_keyStatus[i]=false;
	m_opengl=pGL;
	m_cam=pGL->m_pCamera;
	m_fStep[0]=2.07965*14;
	m_fStep[1]=3.62887*3;
	m_fKeyStep=0.03;
}

GControl::~GControl(void)
{
}


void GControl::SetSpeed(double ms, double rs)
{
}


bool GControl::PreTranslateMessage(unsigned int message, unsigned int wParam, unsigned int lParam)
{
	switch(message)
	{
	case WM_KEYDOWN:
		return SetKeyStatus(wParam,true);
		break;
	case WM_KEYUP:
		return SetKeyStatus(wParam,false);
		break;
	default:
		return false;
	}
	return true;
}


bool GControl::SetKeyStatus(unsigned int nChar, bool bVal)
{
	Road road;
	if (!pause&&!gameOver) {
		switch (nChar)
		{
		case 'Q':
			m_keyStatus[M_BACK] = bVal;
			break;
		case 'E':
			m_keyStatus[M_FRONT] = bVal;
			break;
		case 'A':
			m_keyStatus[M_LEFT] = bVal;
			break;
		case 'D':
			m_keyStatus[M_RIGHT] = bVal;
			break;
		case 'W':
			m_keyStatus[M_UP] = bVal;
			break;
		case 'S':
			m_keyStatus[M_DOWN] = bVal;
			break;
		case 'U':
			m_keyStatus[R_FRONT] = bVal;
			break;
		case 'O':
			m_keyStatus[R_BACK] = bVal;
			break;
		case 'J':
			m_keyStatus[R_LEFT] = bVal;
			break;
		case 'L':
			m_keyStatus[R_RIGHT] = bVal;
			break;
		case 'I':
			m_keyStatus[R_UP] = bVal;
			break;
		case 'K':
			m_keyStatus[R_DOWN] = bVal;
			break;
		case '-':
		case 189:
			m_keyStatus[M_SPEEDDOWN] = bVal;
			break;
		case '=':
		case 187:
			m_keyStatus[M_SPEEDUP] = bVal;
			break;
		case '[':
		case 219:
			m_keyStatus[R_SPEEDDOWN] = bVal;
			break;
		case ']':
		case 221:
			m_keyStatus[R_SPEEDUP] = bVal;
			break;
		case '1':
			road.create(1);
			break;
		case '2':
			road.create(2);
			break;
		case '3':
			road.create(3);
			break;
		case '4':
			road.create(4);
			break;
		case '5':
			road.create(5);
			break;
		case '6':
			road.create(6);
			break;
		case '7':
			road.create(7);
			break;
		case '8':
			road.create(8);
			break;
		case '9':
			road.create(9);
			break;
		default:
			return false;
		}
		KeyboardCtrlView();
	}
	
	return true;
}
bool GControl::KeyboardCtrlView(void)
{
	bool bHaveKeyDown = false;
	//平移
	if(m_keyStatus[M_FRONT])
	{
		m_cam->Move(2,m_fKeyStep*m_fStep[0]);
		bHaveKeyDown = true;
	}
	if(m_keyStatus[M_BACK])
	{
		m_cam->Move(2,-m_fKeyStep*m_fStep[0]);
		bHaveKeyDown = true;
	}
	if(m_keyStatus[M_LEFT])
	{
		m_cam->Move(0,-m_fKeyStep*m_fStep[0]);
		bHaveKeyDown = true;
	}
	if(m_keyStatus[M_RIGHT])
	{
		m_cam->Move(0,+m_fKeyStep*m_fStep[0]);
		bHaveKeyDown = true;
	}
	if(m_keyStatus[M_UP])
	{
		m_cam->Move(1,m_fKeyStep*m_fStep[0]);
		bHaveKeyDown = true;
	}
	if(m_keyStatus[M_DOWN])
	{
		m_cam->Move(1,-m_fKeyStep*m_fStep[0]);
		bHaveKeyDown = true;
	}

	//旋转
	if(m_keyStatus[R_FRONT])
	{
		m_cam->Rotate(2,m_fKeyStep*m_fStep[1]);
		bHaveKeyDown = true;
	}
	if(m_keyStatus[R_BACK])
	{
		m_cam->Rotate(2,-m_fKeyStep*m_fStep[1]);
		bHaveKeyDown = true;
	}
	if(m_keyStatus[R_LEFT])
	{
		m_cam->Rotate(0,m_fKeyStep*m_fStep[1]);
		bHaveKeyDown = true;
	}
	if(m_keyStatus[R_RIGHT])
	{
		m_cam->Rotate(0,-m_fKeyStep*m_fStep[1]);
		bHaveKeyDown = true;
	}
	if(m_keyStatus[R_UP])
	{
		m_cam->Rotate(1,m_fKeyStep*m_fStep[1]);
		bHaveKeyDown = true;
	}
	if(m_keyStatus[R_DOWN])
	{
		m_cam->Rotate(1,-m_fKeyStep*m_fStep[1]);
		bHaveKeyDown = true;
	}
	if(m_keyStatus[M_SPEEDDOWN])	//减小速度
	{
		m_fStep[0]*=0.9;
		bHaveKeyDown = true;
	}
	if(m_keyStatus[M_SPEEDUP])	//增加速度
	{
		m_fStep[0]*=1.1;
		bHaveKeyDown = true;
	}
	if(m_keyStatus[R_SPEEDDOWN])	//减小速度
	{
		m_fStep[1]*=0.9;
		bHaveKeyDown = true;
	}
	if(m_keyStatus[R_SPEEDUP])	//增加速度
	{
		m_fStep[1]*=1.1;
		bHaveKeyDown = true;
	}
	if(bHaveKeyDown)
		InvalidateRect(m_opengl->m_hWnd,NULL,FALSE);
	return bHaveKeyDown;
	
}
