#pragma once
#define BulletSpeed 0.1*Site_width;

class Bullet
{
private:
	float Initpos;   //�ӵ������λ��
	float pos;       //�ӵ���ǰ��λ��
	int ID;          //�ӵ������е�λ��
	int index;		//ռ�õ�����ϵͳ��λ�ã�������10
public:
	Bullet(float);
	void update();
	void draw();
	void destroy();
};

extern Bullet* bul[50];
extern int Bullet_num;