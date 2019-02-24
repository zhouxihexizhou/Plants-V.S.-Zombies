#pragma once
#include <string>
#include <iostream>
using namespace std;
class Time
{
public:
	Time(void);
	~Time(void);
	void SimuStart();			//仿真开始
	void SimuProcess();			//仿真进行中
	double GetTimeSpan();		//得到仿真时间间隔
	CTime &GetSimuTimeCur();	//得到当前仿真时间
	double GetSimuTime();		//得到仿真时间（毫秒为单位）
	void SetSimuTimeStartTime(CTime *SetSimuTimeStartTime);  //设置仿真开始的时间
	string GetShowTime();		//返回表钟格式的时间
	int second;					//时间秒数
	int cent;					//时间毫秒数
private:
	double m_dSimuTime;			//仿真时间
	double m_dTimeSpan;			//两次调用的仿真时间间隔
	CTime m_SimuTimeStart;		//仿真开始时间
	CTime m_SimuTimeCur;		//当前仿真时间
	double m_SimuTimeRatio;		//仿真时间与真实时间的比值
	int m_lasttime;				//记录上次系统时间
};

