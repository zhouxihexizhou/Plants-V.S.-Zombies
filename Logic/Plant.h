#pragma once
#define PDamage 1;      //植物一次攻击的伤害
#define PDamageSpeed 50   //植物每次攻击的攻击间隔
#include "GFont.h"
class Plant
{
private:
	int health;   //植物的生命
	int site;     //植物所在的格子
	int pos;      //植物所处的位置
	int time;     //植物内部的计时器
	bool state;   //植物当前所处状态，0为空闲，1为攻击
public:
	Plant(int);
	void shoot();         //植物发射子弹
	void takeDamage(int);    //植物受伤
	void draw();          //植物的绘制
	void setState(bool);   //改变当前植物的状态
	GFont m_pFont;
};

extern Plant* road[Site_num];