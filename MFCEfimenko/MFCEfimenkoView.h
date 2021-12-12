
// MFCEfimenkoView.h : interface of the CMFCEfimenkoView class
//

#pragma once


class CMFCEfimenkoView : public CScrollView
{
protected: // create from serialization only
	CMFCEfimenkoView() noexcept;
	DECLARE_DYNCREATE(CMFCEfimenkoView)

// Attributes
public:
	CMFCEfimenkoDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CMFCEfimenkoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCEfimenkoView.cpp
inline CMFCEfimenkoDoc* CMFCEfimenkoView::GetDocument() const
   { return reinterpret_cast<CMFCEfimenkoDoc*>(m_pDocument); }
#endif

