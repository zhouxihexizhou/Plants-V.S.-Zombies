#pragma once
#define PDamage 1;      //ֲ��һ�ι������˺�
#define PDamageSpeed 50   //ֲ��ÿ�ι����Ĺ������
#include "GFont.h"
class Plant
{
private:
	int health;   //ֲ�������
	int site;     //ֲ�����ڵĸ���
	int pos;      //ֲ��������λ��
	int time;     //ֲ���ڲ��ļ�ʱ��
	bool state;   //ֲ�ﵱǰ����״̬��0Ϊ���У�1Ϊ����
public:
	Plant(int);
	void shoot();         //ֲ�﷢���ӵ�
	void takeDamage(int);    //ֲ������
	void draw();          //ֲ��Ļ���
	void setState(bool);   //�ı䵱ǰֲ���״̬
	GFont m_pFont;
};

extern Plant* road[Site_num];