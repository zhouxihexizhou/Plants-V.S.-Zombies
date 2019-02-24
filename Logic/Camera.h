#pragma once
#include "glVector.h"
class Camera
{
public:
	Camera(void);
	~Camera(void);
	void Init(void);
	void ShowView();          //视图矩阵
	void Rotate(int dir,double len);
	void Move(int dir,double len);
	glVector m_pos;           //视点当前位置
	glVector m_hpr;           //视点方向角,x::h,y::p,z::r
	glVector m_eyedir;        //视线方向
	glVector m_updir;         //上方向量
	double m_viewMatrix[16];  //视图矩阵
	double m_viewMatrixInverse[16];   //视图矩阵逆矩阵
	double m_viewMatrixSave[16];      //保存的视图矩阵
};

