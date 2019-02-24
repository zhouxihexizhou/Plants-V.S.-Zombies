#pragma once
class OpenGL;
class Camera;
class GControl
{
public:
	GControl(OpenGL *pGL);
	~GControl(void);
	void SetSpeed(double ms, double rs);
	bool KeyboardCtrlView(void);
	bool PreTranslateMessage(unsigned int message, unsigned int wParam, unsigned int lParam);
	enum KEYSTATUS{M_RIGHT,M_LEFT,M_UP,M_DOWN,M_BACK,M_FRONT,
	R_LEFT,R_RIGHT,R_UP,R_DOWN,R_FRONT,R_BACK,M_SPEEDUP,M_SPEEDDOWN,R_SPEEDUP,R_SPEEDDOWN,ALL}KeyVal;
	bool m_keyStatus[ALL];

	OpenGL *m_opengl;
	Camera *m_cam;
private:
	double m_fStep[2]; //移动和旋转步长缩放倍率
	double m_fKeyStep;//键盘按下一个运动命令代表移动步长
	bool SetKeyStatus(unsigned int nChar, bool bVal);
};

