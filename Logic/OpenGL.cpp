#include "StdAfx.h"
#include "OpenGL.h"
#include "Texture.h"
#include "Mmsystem.h"
#include "Box.h"
#include <string>

int frame=0;

Zombie* zom[50]={NULL};
Plant* road[Site_num]={NULL};
Bullet* bul[50]={NULL};
int Zombie_num=0;
int Bullet_num=0;

int Backmost=0;
int sun=0;
bool pause = 0;
bool gameOver = 0;
int system_time = 0;
int remain_zombie=6;
OpenGL::OpenGL(void)
{
	m_hWnd=0;
	m_hDC=0;
	m_hglrc=0;

	m_pCamera=NULL;
	m_pControl=NULL;
}

OpenGL::~OpenGL(void)
{
	delete m_pCamera;
	delete m_pControl;
	delete m_pTime;
}

//�����Ļ�����InDraw��
void OpenGL::OnPaint(void)
{
	if (!pause&&!gameOver) {
		system_time++;
	}
	if(system_time%60==0 && !pause&&!gameOver)
	{
		//sun+=25;
		sun+=50;
	}
	m_pTime->SimuProcess();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	OnView();
	InDraw();
	SwapBuffers(m_hDC);
}

bool OpenGL::PreTranslateMessage(unsigned int message, unsigned int wParam, unsigned int lParam)
{
	m_pControl->PreTranslateMessage(message,wParam,lParam);
	return false;
}

bool OpenGL::Init(HWND hWnd)
{
	m_hWnd = hWnd;
	m_hDC = GetDC(hWnd);
	PIXELFORMATDESCRIPTOR pfd = //�������ظ�ʽ
	{
		sizeof(PIXELFORMATDESCRIPTOR),		// size of this pfd	�ṹ��С
		1,                              // version number	�ṹ�汾������Ϊ1
		PFD_DRAW_TO_WINDOW |            // support window	���ظ�ʽѡ���־������
		PFD_SUPPORT_OPENGL |		    // support OpenGL
		//			PFD_GENERIC_ACCELERATED|		// ����
		PFD_DOUBLEBUFFER,				// double buffered
		PFD_TYPE_RGBA,                  // RGBA type		PFD_RGBA|PFD_INDEX RGB���ڻ���������
		24,                             // 24-bit color depth	������ɫ����λ��
		0,								// color bits ignored	�����ɫλ��
		0,								// color bits ignored	ʹ�õ�ɫ��ת��Ϊ��ɫʱ����ɫλ�仯����Ŀ
		0,								// color bits ignored   ������ɫλ��
		0,								// color bits ignored   ʹ�õ�ɫ��ת��Ϊ��ɫʱ����ɫλ�仯����Ŀ
		0,								// color bits ignored   ������ɫλ��
		0,								// color bits ignored   ʹ�õ�ɫ��ת��Ϊ��ɫʱ����ɫλ�仯����Ŀ            
		0,                              // no alpha buffer		�����alpha��ɫλ��������һ���OpenGL��װ���ԣ���ֵʼ��δ0
		0,                              // shift bit ignored	ת��Ϊalpha��ɫλ���仯����Ŀ������һ���OpenGL��װ���ԣ���ֵʼ��δ0
		0,                              // no accumulation buffer	ʵ���ۼ�����Ҫ����ɫ����λ��
		0, 0, 0, 0,                     // accum bits ignored	ʵ���ۼ�����Ҫ�ĺ�ɫ����ɫ����ɫ��alphaɫλ��
		24,                             // 16-bit z-buffer		����Ҫ����Ȼ�����λ��
		0,                              // no stencil buffer	����Ҫ��ģ�滺����λ��
		0,                              // no auxiliary buffer	����Ҫ�ĸ���������λ��������һ���OpenGL��װ���ԣ���ֵʼ��δ0
		PFD_MAIN_PLANE,                 // main layer			WIN32API��ʹ�ú�֧�ֱ�����
		0,                              // reserved				Ϊ������ʹ�ö�׼���ı�������
		0,								// layer masks ignored	WIN32API��ʹ�ú�֧�ֱ�����
		0,								// ָ��RGBA��͸��������ɫ����������Ӧ�ڸ���ͼ�����ظ�ʽ 
		0								// WIN32API��ʹ�ú�֧�ֱ�����
	};	
	int pf = ChoosePixelFormat(m_hDC, &pfd);
	if(!pf)	return FALSE;
	if (!SetPixelFormat(m_hDC, pf, &pfd))
		return FALSE;
	m_hglrc = wglCreateContext(m_hDC);
	wglMakeCurrent(m_hDC,m_hglrc);


	glClearColor(0.0,0.0,0.0,0.0);
	glClearDepth(1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	m_PerspectiveParam[0]=60;
	m_PerspectiveParam[2]=0.1;
	m_PerspectiveParam[3]=10000;
	m_pCamera=new Camera;
	m_pControl=new GControl(this);
	m_pTime=new Time;
	m_pFont=new GFont;
	//������postinit�е�����
	m_pCamera->Init();
	m_pControl->SetSpeed(0.5,0.1);
	m_particle.Init(2000);
	sky.InitSky(500);
	suna.Init(30,500,m_pTime);
	box.Init("timg");
	
	light1.SetAMB(1.5,1.5,1.5,0);
	light1.SetDIF(10,10,10,0);
	light1.SetSPE(1.0,1.0,1.0,0);
	light1.Shine();

	float amb[4] = { 0.5,0.5,0.5,1 };
	float dif[4] = { 0.3,0.3,0.3,1 };
	float spe[4] = { 0.0,0.0,0.0,1 };
	float position[4] = { 0,500,0,1 };
	glEnable(GL_LIGHT2);
	glLightfv(GL_LIGHT2, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, dif);
	glLightfv(GL_LIGHT2, GL_SPECULAR, spe);
	glLightfv(GL_LIGHT2, GL_POSITION, position);
	Road road;
	road.create(1);
	road.create(9);
	return true;
}

void OpenGL::OnSize(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	m_PerspectiveParam[1]=(GLfloat)w/h;
	gluPerspective(m_PerspectiveParam[0],m_PerspectiveParam[1],m_PerspectiveParam[2],m_PerspectiveParam[3]);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void OpenGL::OnView(void)
{
	
	m_pCamera->ShowView();
	m_pControl->KeyboardCtrlView();
}

void create()            //���ɽ�ʬ
{
	if(system_time==2 || system_time==400 || system_time==450 || system_time==800 || system_time==900 ||system_time==1000) 
	{
		zom[Zombie_num]= new Zombie(Zombie_num);
		Zombie_num++;
	}
}

void BackmostZombie()
{
	if(Zombie_num>0)
	{
		Backmost = zom[Zombie_num-1]->getSite();
	}
	else
	{
		Backmost = 0;
	}
}

void PaintZombie()
{
	for(int i=0;i<Zombie_num;i++)
	{
		if (!pause&&!gameOver)
		{
			zom[i]->update();
		}
		zom[i]->draw();
	}
}

void PaintPlant()
{
	for(int i=1;i<Site_num;i++)
	{
		if(road[i]!=NULL)
		{
			road[i]->draw();
			if (!pause && !gameOver)
			{
				road[i]->shoot();
			}
		}
	}
}

void PaintBullet()
{
	for(int i=0;i<Bullet_num;i++)
	{
		if (!pause && !gameOver)
		{
			bul[i]->update();
		}
		bul[i]->draw();
	}
}

void OpenGL::InDraw(void)
{
	frame=(frame+1)%500;
	glPushMatrix();
	suna.Draw();
	
	//��պ�
	glColor4f(1,1,1,1);
	sky.ShowSky();
	//��������
	if(suna.pos[1]>0)
		light1.SetPos(suna.pos);
	//box.Draw(50,50,50);

	create();
	Road road;
	road.draw();
	PaintZombie();
	BackmostZombie();
	PaintPlant();
	PaintBullet();
	//��Ϸ����

	glTranslated(0,0,-5);
	glutSolidTeapot(2);
	//����ϵͳ
	m_particle.UpdatePos();
	if(frame>250)
		m_particle.rain=false;
	else
		m_particle.rain=true;
	m_particle.Draw();
	
	//float t=m_pTime->GetSimuTime()/1000;
	//CString str;
	//glColor3f(1,0,0);
	//str.Format("%.2f",t);
	//m_pFont->Font2D(str.GetBuffer(0),-0.9,0.9,7);
	//glColor3f(1,1,1);
	//ʱ����ʾ
	m_pFont->Font2D("sun:",-0.9,0.7,7);
	
	if (gameOver) {
		m_pFont->Font2D("GAME OVER", -0.1, 0, 7);
	}
	else if(remain_zombie==0)
	{
		m_pFont->Font2D("YOU WIN", -0.1, 0, 7);
	}
	else if (pause) {
		m_pFont->Font2D("GAME STOPPED", -0.1, 0, 7);
	}
	char c[20];
	itoa(sun,c,10);
	m_pFont->Font2D(c,-0.8,0.7,7);
	
	glPopMatrix();
}
