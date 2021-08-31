
// dinosaurView.cpp : implementation of the CdinosaurView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "dinosaur.h"
#endif

#include "dinosaurDoc.h"
#include "dinosaurView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdinosaurView

IMPLEMENT_DYNCREATE(CdinosaurView, CView)

BEGIN_MESSAGE_MAP(CdinosaurView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
END_MESSAGE_MAP()

// CdinosaurView construction/destruction

CdinosaurView::CdinosaurView() noexcept
{
	// TODO: add construction code here
	game = Game();
	kd = 0;

}

CdinosaurView::~CdinosaurView()
{
}

BOOL CdinosaurView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CdinosaurView drawing

void CdinosaurView::OnDraw(CDC* /*pDC*/)
{
	CdinosaurDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC pdc(this);
	// TODO: add draw code for native data here
	
	game.vehinh(&pdc);
}

void CdinosaurView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CdinosaurView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CdinosaurView diagnostics

#ifdef _DEBUG
void CdinosaurView::AssertValid() const
{
	CView::AssertValid();
}

void CdinosaurView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdinosaurDoc* CdinosaurView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdinosaurDoc)));
	return (CdinosaurDoc*)m_pDocument;
}
#endif //_DEBUG


// CdinosaurView message handlers


void CdinosaurView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC pdc(this);
	if (game.bamnut(&pdc, point) == 1 )
	{
		
		batdaugame();
	}
	CView::OnLButtonDown(nFlags, point);
}

UINT vatcanchay(LPVOID pParam)
{
	int ran = 0;
	CdinosaurView* cview = (CdinosaurView*)pParam;
	CClientDC pdc(cview);
	cview->game.vatcanchay(&pdc);
	return 0;
}

UINT capnhathinh(LPVOID pParam)
{
	int ran = 0;
	CdinosaurView* cview = (CdinosaurView*)pParam;
	CClientDC pdc(cview);
	cview->game.capnhathinh(&pdc);
	return 0;
}

int CdinosaurView::batdaugame()
{
	// TODO: Add your implementation code here.
	AfxBeginThread(capnhathinh, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	AfxBeginThread(vatcanchay, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	return 0;
}


void CdinosaurView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if (nChar == 32 && kd == 0)
	{
		kd = 1;
		game.robotnhay();
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CdinosaurView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	kd = 0;
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}
