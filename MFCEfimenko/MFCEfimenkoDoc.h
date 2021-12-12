
// MFCEfimenkoDoc.h : interface of the CMFCEfimenkoDoc class
//
#pragma once
#include "Salad_Efimenko.h"


class CMFCEfimenkoDoc : public CDocument
{
protected: // create from serialization only
	CMFCEfimenkoDoc() noexcept;
	DECLARE_DYNCREATE(CMFCEfimenkoDoc)

// Attributes
public:
	

// Operations
public:
	Salad_Efimenko saladRecipe;
// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMFCEfimenkoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnEditlist();
};
