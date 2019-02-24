
// LogicView.cpp : CLogicView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Logic.h"
#endif

#include "LogicDoc.h"
#include "LogicView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLogicView

IMPLEMENT_DYNCREATE(CLogicView, CView)

BEGIN_MESSAGE_MAP(CLogicView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CLogicView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_WM_TIMER()
//	ON_WM_PAINT()
END_MESSAGE_MAP()

// CLogicView 构造/析构

CLogicView::CLogicView()
{
	// TODO: 在此处添加构造代码

}

CLogicView::~CLogicView()
{
}

BOOL CLogicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CLogicView 绘制

void CLogicView::OnDraw(CDC* /*pDC*/)
{
	CLogicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	m_gl.OnPaint();
	// TODO: 在此处为本机数据添加绘制代码
}


// CLogicView 打印


void CLogicView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CLogicView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CLogicView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CLogicView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CLogicView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CLogicView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CLogicView 诊断

#ifdef _DEBUG
void CLogicView::AssertValid() const
{
	CView::AssertValid();
}

void CLogicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLogicDoc* CLogicView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLogicDoc)));
	return (CLogicDoc*)m_pDocument;
}
#endif //_DEBUG


// CLogicView 消息处理程序


BOOL CLogicView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	return true;
	return CView::OnEraseBkgnd(pDC);
}


void CLogicView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	m_gl.OnSize(cx,cy);
	// TODO: 在此处添加消息处理程序代码
}


void CLogicView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_gl.OnPaint();
	CView::OnTimer(nIDEvent);
}


void CLogicView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	if(!m_gl.Init(this->GetSafeHwnd()))
		return;
		//AfxMessageBox("error!");
	SetTimer(1,30,NULL);
	// TODO: 在此添加专用代码和/或调用基类
}


BOOL CLogicView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	m_gl.PreTranslateMessage(pMsg->message,pMsg->wParam,pMsg->lParam);
	return CView::PreTranslateMessage(pMsg);
}


//void CLogicView::OnPaint()
//{
//	CPaintDC dc(this); // device context for painting
//	// TODO: 在此处添加消息处理程序代码
//	// 不为绘图消息调用 CView::OnPaint()
//}
