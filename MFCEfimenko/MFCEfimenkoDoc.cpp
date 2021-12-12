
// MFCEfimenkoDoc.cpp : implementation of the CMFCEfimenkoDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCEfimenko.h"
#endif

#include "MFCEfimenkoDoc.h"
#include "MyDialogE.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCEfimenkoDoc

IMPLEMENT_DYNCREATE(CMFCEfimenkoDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCEfimenkoDoc, CDocument)
	ON_COMMAND(ID_EDIT_EDITLIST, &CMFCEfimenkoDoc::OnEditlist)
END_MESSAGE_MAP()


// CMFCEfimenkoDoc construction/destruction

CMFCEfimenkoDoc::CMFCEfimenkoDoc() noexcept
{
	// TODO: add one-time construction code here

}

CMFCEfimenkoDoc::~CMFCEfimenkoDoc()
{
}

BOOL CMFCEfimenkoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	saladRecipe.DeleteFruit();

	// (SDI documents will reuse this document)

	return TRUE;
}




// CMFCEfimenkoDoc serialization

void CMFCEfimenkoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		saladRecipe.WriteFruitToFile(ar);
	}
	else
	{
		// TODO: add loading code here
		saladRecipe.DeleteFruit();
		saladRecipe.ReadFruitFromFile(ar);
	AfxGetMainWnd()->Invalidate(); //перересовка окна
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMFCEfimenkoDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMFCEfimenkoDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCEfimenkoDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCEfimenkoDoc diagnostics

#ifdef _DEBUG
void CMFCEfimenkoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCEfimenkoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCEfimenkoDoc commands


void CMFCEfimenkoDoc::OnEditlist()
{
	MyDialogE dlg(this);
	if (dlg.DoModal() == IDOK)
	{
		UpdateAllViews(NULL);
	}
}
