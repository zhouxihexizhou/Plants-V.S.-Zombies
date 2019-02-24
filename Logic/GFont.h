#pragma once
#include <gl/glut.h>
#include <afxtempl.h>
class GFont
{
public:
	GFont(void);
	~GFont(void);
	void Font2D(const char *str,double x,double y,int type);
	bool Font3D(CString str);
	bool Font3D(CString str,int &id);
private:
	bool Create3DFont();
	LOGFONT m_logFontDefault;
	int m_iFormat;
	double m_fDeviation;
	double m_fExtrusion;
	CFont *m_pFontSelected;
	int m_iFormatDefault;
	double m_fDeviationDefault;
	double m_fExtrusionDefault;
	int m_iFirstChar;
	int m_iLastChar;
	int m_iNumberChars;
	int m_iDisplayListStart;
	int m_iDisplayListBase;
	bool m_bHaveCreate3DFont;
	CArray<int,int>m_fontlist;	//保存所有的已经生成的三维字体列表
};

