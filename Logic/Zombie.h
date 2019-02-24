#pragma once
#define ZInitPos 10.5*Site_width;  //��ʬ����ʱ�ĳ�ʼλ��
#define WalkSpeed 0.01*Site_width;   //��ʬÿ֡���ƶ��ٶ�
#define ZDamage 5;      //��ʬһ�ι������˺�
#define ZDamageSpeed 40   //��ʬÿ�ι����Ĺ������
#define ZHealth 30;
#include "GFont.h"
extern bool gameOver;

class Zombie
{
private:
	bool state;    //0Ϊ���ߣ�1Ϊ����
	float pos;     //��ʬ��ǰ��λ��
	int time;      //��ʬ�Լ��ļ�ʱ��
	int health;    //��ʬ������ֵ
	int ID;        //��ǰ�ڽ�ʬ�����е�λ��
	int site;      //��ʬ��ǰ���ڵĸ���

	int type_arm;     //���ƶ���
	int type_leg;     //���ƶ���
	bool walk;    //�Ƿ�������
public:
	Zombie(int);
	void setState(bool);     //��ʬ״̬�ı�
	void Inwhichsite();     //��ʬ��ǰ���Ǹ�����
	void update();          //���½�ʬ��Ϊ
	void draw();            //����
	void die();             //��ʬ����
	void takeDamage(int);   //��ʬ�ܵ��˺�
	int getSite();         //��ȡ��ǰ��ʬ���ڵĸ���
	float getPos();
	GFont m_pFont;
};

extern Zombie* zom[50];        //��ʬ����
extern int Zombie_num;         //��ʬ������
extern int Backmost;           //λ�����Ľ�ʬ���ڵĸ���