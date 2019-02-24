
// LogicView.h : CLogicView 类的接口
//

#pragma once

#include "OpenGL.h"
class CLogicView : public CView
{
	OpenGL m_gl;
protected: // 仅从序列化创建
	CLogicView();
	DECLARE_DYNCREATE(CLogicView)

// 特性
public:
	CLogicDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CLogicView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnInitialUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
//	afx_msg void OnPaint();
};

#ifndef _DEBUG  // LogicView.cpp 中的调试版本
inline CLogicDoc* CLogicView::GetDocument() const
   { return reinterpret_cast<CLogicDoc*>(m_pDocument); }
#endif

