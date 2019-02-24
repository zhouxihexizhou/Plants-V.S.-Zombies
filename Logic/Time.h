#pragma once
#include <string>
#include <iostream>
using namespace std;
class Time
{
public:
	Time(void);
	~Time(void);
	void SimuStart();			//���濪ʼ
	void SimuProcess();			//���������
	double GetTimeSpan();		//�õ�����ʱ����
	CTime &GetSimuTimeCur();	//�õ���ǰ����ʱ��
	double GetSimuTime();		//�õ�����ʱ�䣨����Ϊ��λ��
	void SetSimuTimeStartTime(CTime *SetSimuTimeStartTime);  //���÷��濪ʼ��ʱ��
	string GetShowTime();		//���ر��Ӹ�ʽ��ʱ��
	int second;					//ʱ������
	int cent;					//ʱ�������
private:
	double m_dSimuTime;			//����ʱ��
	double m_dTimeSpan;			//���ε��õķ���ʱ����
	CTime m_SimuTimeStart;		//���濪ʼʱ��
	CTime m_SimuTimeCur;		//��ǰ����ʱ��
	double m_SimuTimeRatio;		//����ʱ������ʵʱ��ı�ֵ
	int m_lasttime;				//��¼�ϴ�ϵͳʱ��
};

