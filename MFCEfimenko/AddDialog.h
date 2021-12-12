#pragma once

#include "MFCEfimenkoDoc.h"
// AddDialog dialog

class AddDialog : public CDialogEx
{
	DECLARE_DYNAMIC(AddDialog)
private:
		CMFCEfimenkoDoc* pDoc;
		int f_index;
public:
	AddDialog(CMFCEfimenkoDoc*, int index, CWnd* pParent = nullptr);   // standard constructor
	virtual ~AddDialog();
	void SetFruitFields(bool decision);
	void SetAppleFields(bool decision);

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_name;
	int m_amount;
	double m_price;
	CString m_color;
	int m_seeds;
	int m_trees;
	virtual BOOL OnInitDialog();
	CEdit e_control_name;
	CEdit e_control_amount;
	CEdit e_control_price;
	CEdit e_control_color;
	CEdit e_control_seeds;
	CEdit e_control_trees;
	CImageList m_im;
	afx_msg void OnBnClickedRadioFruit();
	BOOL m_ShowType;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCheck1();
	CEdit t_name;
	CEdit t_amount;
	CEdit t_price;
	CTabCtrl TabManager;
};
