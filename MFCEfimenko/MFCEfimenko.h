
// MFCEfimenko.h : main header file for the MFCEfimenko application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCEfimenkoApp:
// See MFCEfimenko.cpp for the implementation of this class
//

class CMFCEfimenkoApp : public CWinApp
{
public:
	CMFCEfimenkoApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCEfimenkoApp theApp;
