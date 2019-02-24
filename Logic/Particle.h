#pragma once
#include "glVector.h"
class Particle
{
public:
	void Draw();        //绘制粒子
	void BillBoard(const glVector &eyepos);
	Particle(void);
	~Particle(void);

	glVector m_pos;     //粒子中心位置
	double m_size;		//粒子的大小
	double m_XYratio;	//粒子的长宽比例
	glVector m_particleDir[4];	//计算粒子billboard位置时用到的方向
	glVector m_posCorner[4];	//粒子角点的坐标

	double m_color[4];		//计算粒子颜色
	bool m_bActive;			//粒子是否存活
	glVector m_speed;		//速度
	glVector m_acc;			//加速度
	double m_lifetime;		//粒子生命时间
	double m_colorfade;	
};

