
// MFCEfimenkoView.cpp : implementation of the CMFCEfimenkoView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCEfimenko.h"
#endif

#include "MFCEfimenkoDoc.h"
#include "MFCEfimenkoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCEfimenkoView

IMPLEMENT_DYNCREATE(CMFCEfimenkoView, CScrollView)

BEGIN_MESSAGE_MAP(CMFCEfimenkoView, CScrollView)
END_MESSAGE_MAP()

// CMFCEfimenkoView construction/destruction

CMFCEfimenkoView::CMFCEfimenkoView() noexcept
{
	// TODO: add construction code here

}

CMFCEfimenkoView::~CMFCEfimenkoView()
{
}

BOOL CMFCEfimenkoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CMFCEfimenkoView drawing

void CMFCEfimenkoView::OnDraw(CDC* pDC)
{
	CMFCEfimenkoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CSize DocSize = pDoc->saladRecipe.DocSize(pDC);
	//Установить режим отображения и размер документа
SetScrollSizes(MM_TEXT, DocSize, CSize(500, 500), CSize(500, 500));
	// TODO: add draw code for native data here
}


void CMFCEfimenkoView::OnInitialUpdate()
{
	// TODO: calculate the total size of this view
	CScrollView::OnInitialUpdate();
	//Определить размер документа
	CSize defsize(2000, 2000);
	//Установить режим отображения и размер документа
	SetScrollSizes(MM_TEXT, defsize, CSize(500, 500), CSize(50, 50));
}


// CMFCEfimenkoView diagnostics

#ifdef _DEBUG
void CMFCEfimenkoView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMFCEfimenkoView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMFCEfimenkoDoc* CMFCEfimenkoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCEfimenkoDoc)));
	return (CMFCEfimenkoDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCEfimenkoView message handlers
