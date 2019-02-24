#pragma once
#define BulletSpeed 0.1*Site_width;

class Bullet
{
private:
	float Initpos;   //子弹射出的位置
	float pos;       //子弹当前的位置
	int ID;          //子弹数组中的位置
	int index;		//占用的粒子系统的位置，不大于10
public:
	Bullet(float);
	void update();
	void draw();
	void destroy();
};

extern Bullet* bul[50];
extern int Bullet_num;