#pragma once
#define ZInitPos 10.5*Site_width;  //僵尸出生时的初始位置
#define WalkSpeed 0.01*Site_width;   //僵尸每帧的移动速度
#define ZDamage 5;      //僵尸一次攻击的伤害
#define ZDamageSpeed 40   //僵尸每次攻击的攻击间隔
#define ZHealth 30;
#include "GFont.h"
extern bool gameOver;

class Zombie
{
private:
	bool state;    //0为行走，1为攻击
	float pos;     //僵尸当前的位置
	int time;      //僵尸自己的计时器
	int health;    //僵尸的生命值
	int ID;        //当前在僵尸数组中的位置
	int site;      //僵尸当前所在的格子

	int type_arm;     //控制动画
	int type_leg;     //控制动画
	bool walk;    //是否在行走
public:
	Zombie(int);
	void setState(bool);     //僵尸状态改变
	void Inwhichsite();     //僵尸当前在那个格子
	void update();          //更新僵尸行为
	void draw();            //绘制
	void die();             //僵尸死亡
	void takeDamage(int);   //僵尸受到伤害
	int getSite();         //获取当前僵尸所在的格子
	float getPos();
	GFont m_pFont;
};

extern Zombie* zom[50];        //存活僵尸数组
extern int Zombie_num;         //存活僵尸的数量
extern int Backmost;           //位于最后的僵尸所在的格子