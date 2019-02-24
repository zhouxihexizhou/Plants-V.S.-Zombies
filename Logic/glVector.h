#pragma once
#include <math.h>
#define PAI (3.141592654)
//弧度转角度
#define RadToAng(x) ((x)/PAI*180.0)
//角度转弧度
#define AngToRad(x) ((x)/180.0*PAI)
class glVector  
{
public:
	glVector(void){x=0;y=0;z=0;};
	glVector(double fx,double fy,double fz)
	{
		x=fx;y=fy;z=fz;
	}

	glVector(float *pos)
	{
		x=pos[0];
		y=pos[1];
		z=pos[2];
	}
	glVector(double *pos)
	{
		x=pos[0];
		y=pos[1];
		z=pos[2];
	}
	void Set(double fx,double fy,double fz)
	{
		x=fx;y=fy;z=fz;
	}
	void Set(float *pos)
	{
		x=pos[0];
		y=pos[1];
		z=pos[2];
	}
	void Set(double *pos)
	{
		x=pos[0];
		y=pos[1];
		z=pos[2];
	}
	void Get(double *pos)
	{
		pos[0]=x;
		pos[1]=y;
		pos[2]=z;
	}
	void Get(float *pos)
	{
		pos[0]=float(x);
		pos[1]=float(y);
		pos[2]=float(z);
	}
public:
	~glVector(void){};
public:
	double x,y,z;
	operator double*()
	{
		return &x;
	}
	operator const double*() const
	{
		return &x;
	}
	glVector& operator=(const glVector& p)
	{
		x=p.x;y=p.y;z=p.z;
		return *this;
	}
	glVector operator+(const glVector& p) const
	{
		glVector vec;
		vec.x = x+p.x;
		vec.y = y+p.y;
		vec.z = z+p.z;
		return vec;
	}
	bool operator==(const glVector& p)
	{
		if(fabs(x-p.x)<1e-5)
			if(fabs(y-p.x)<1e-5)
				if(fabs(x-p.x)<1e-5)
					return true;
		return false;
	}
	glVector& operator+=(const glVector& p)
	{
		x+=p.x;
		y+=p.y;
		z+=p.z;
		return *this;
	}
	glVector& operator-=(const glVector& p)
	{
		x-=p.x;
		y-=p.y;
		z-=p.z;
		return *this;
	}
	glVector operator-(const glVector& p) const
	{
		glVector vec;
		vec.x = x-p.x;
		vec.y = y-p.y;
		vec.z = z-p.z;
		return vec;
	}
	glVector operator-() const
	{
		glVector vec;
		vec.x = -x;
		vec.y = -y;
		vec.z = -z;
		return vec;
	}
	glVector operator*(double data) const
	{
		glVector vec;
		vec.x = x*data;
		vec.y = y*data;
		vec.z = z*data;
		return vec;
	}
	friend glVector operator*(double data, const glVector& p)
	{
		glVector vec;
		vec.x = p.x*data;
		vec.y = p.y*data;
		vec.z = p.z*data;
		return vec;
	}
	glVector operator*(float *mat) const
	{
		double v[4];
		int i;
		for(i=0;i<4;i++)
		{
			v[i] = mat[i*4]*x +mat[1+i*4]*y +mat[2+i*4]*z +mat[3+i*4];
		}
		glVector vec;
		for(i=0;i<3;i++)
			vec[i] = v[0]/v[3];
		return vec;
	}
	friend glVector operator*(float *mat, const glVector& p)
	{
		double v[4];
		for(int i=0;i<4;i++)
		{
			v[i] = mat[i]*p.x +mat[4+i]*p.y +mat[8+i]*p.z +mat[12+i];
		}
		glVector vec;
		vec.x = v[0]/v[3];
		vec.y = v[1]/v[3];
		vec.z = v[2]/v[3];
		return vec;
	}
	glVector operator*(double *mat) const
	{
		double v[4];
		int i;
		for(i=0;i<4;i++)
		{
			v[i] = mat[i*4]*x +mat[1+i*4]*y +mat[2+i*4]*z +mat[3+i*4];
		}
		glVector vec;
		for(i=0;i<3;i++)
			vec[i] = v[0]/v[3];
		return vec;
	}
	friend glVector operator*(double *mat, const glVector& p)
	{
		double v[4];
		for(int i=0;i<4;i++)
		{
			v[i] = mat[i]*p.x +mat[4+i]*p.y +mat[8+i]*p.z +mat[12+i];
		}
		glVector vec;
		vec.x = float(v[0]/v[3]);
		vec.y = float(v[1]/v[3]);
		vec.z = float(v[2]/v[3]);
		return vec;
	}
	glVector operator/(double data) const
	{
		glVector vec;
		vec.x = x/data;
		vec.y = y/data;
		vec.z = z/data;
		return vec;
	}
	double dotMul(const glVector&p)
	{
		return x*p.x+y*p.y+z*p.z;
	}
	glVector crossMul(const glVector&p) const
	{
		glVector vec;
		vec.x=y*p.z-z*p.y;
		vec.y=z*p.x-x*p.z;
		vec.z=x*p.y-y*p.x;
		return vec;
	}
	double len()
	{
		return sqrt(x*x+y*y+z*z);
	}
	void Normalize()
	{	
		double l=len();
		x /= l;
		y /= l;
		z /= l;
	}
	void Add(int addr,double val)
	{
		if(addr==0)
			x+=val;
		else if(addr==1)
			y+=val;
		else if(addr==2)
			z+=val;
	}
	void Rotate(double seta,int axis)//绕某个轴旋转seta角度,弧度角
	{
		switch(axis)
		{
		case 0://X 轴
			{
				double y1=y*cos(seta)-z*sin(seta);
				z =y*sin(seta)+z*cos(seta);
				y=y1;
			}
			break;
		case 1://Y 轴
			{
				double x1=x*cos(seta)+z*sin(seta);
				z =-x*sin(seta)+z*cos(seta);
				x=x1;
			}
			break;
		case 2://Y 轴
			{
				double x1=x*cos(seta)-y*sin(seta);
				y =x*sin(seta)+y*cos(seta);
				x=x1;
			}
			break;
		}
	}
	void Rotate(double seta,double x,double y,double z)//绕某个方向转seta角度,弧度角
	{	
		double dis1=x*x+z*z;
		double dis2=dis1+y*y;
		dis1 = sqrt(dis1);
		dis2 = sqrt(dis2);
		//先绕x轴转，使轴转动到XOZ平面上,角度为xyz与XOZ夹角
		double setax = acos(dis1/dis2);
		if(y<0) setax = -setax;
		Rotate(setax,0);
		//再绕y轴转，使轴转动到Z轴重合位置,角度为xyz投影与z轴夹角
		double setay = acos(z/dis1);
		if(x>0) setay = -setay;
		Rotate(setay,1);
		//开始绕z轴转
		Rotate(seta,2);
		//////////////////////////////////////////////////////////////////////////恢复
		//绕y转回来。
		Rotate(-setay,1);
		//绕x转回来。
		Rotate(-setax,0);
	}
};

