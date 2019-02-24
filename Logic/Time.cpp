#include "StdAfx.h"
#include "Time.h"
#include "Mmsystem.h"

Time::Time(void)
{
	m_lasttime=timeGetTime();
	m_dSimuTime=0;
	m_SimuTimeRatio=1;
	SYSTEMTIME systime;
	GetSystemTime(&systime);
	m_SimuTimeStart=systime;
}

string Time::GetShowTime()
{
	float t=GetSimuTime()/1000;
	cent=int(t*100)%100;
	second=int(t);
	int minute=second/60;
	int hour=minute/60;
	string ans;
	hour=hour%24;
	minute=minute%60;
	second=second%60;
	ans="."+to_string(long long (cent));
	if(second<10)
		ans=":0"+to_string(long long (second))+ans;
	else
		ans=":"+to_string(long long (second))+ans;
	if(minute<10)
		ans=":0"+to_string(long long (minute))+ans;
	else
		ans=":"+to_string(long long (minute))+ans;
	if(hour<10)
		ans="0"+to_string(long long (hour))+ans;
	else
		ans=to_string(long long (hour))+ans;
	return ans;
}
Time::~Time(void)
{
}

void Time::SimuStart()
{
	m_lasttime=timeGetTime();
	m_dSimuTime=0;
}

void Time::SimuProcess()
{
	int curtime=timeGetTime();
	m_dTimeSpan=m_SimuTimeRatio*(curtime-m_lasttime);
	m_dSimuTime+=m_dTimeSpan;
	m_lasttime=curtime;
}
void Time::SetSimuTimeStartTime(CTime* SimuTimeStart)
{
	if(SimuTimeStart)
		m_SimuTimeStart=*SimuTimeStart;
	else
	{
		SYSTEMTIME systime;
		GetSystemTime(&systime);
		m_SimuTimeStart=systime;
	}
}
CTime& Time::GetSimuTimeCur()
{
	m_SimuTimeCur=m_SimuTimeStart+int(m_dSimuTime/1000);
	return m_SimuTimeCur;
}
double Time::GetSimuTime()
{
	return m_dSimuTime;
}
double Time::GetTimeSpan()
{
	return m_dTimeSpan;
}