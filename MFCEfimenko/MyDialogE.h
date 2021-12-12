#pragma once
#include "MFCEfimenkoDoc.h"

// MyDialogE dialog

class MyDialogE : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialogE)

private:
	CMFCEfimenkoDoc* pDoc;
public:
	MyDialogE(CMFCEfimenkoDoc*, CWnd* pParent = nullptr);   // standard constructor
	virtual ~MyDialogE();
	void SetFruitFields(bool decision);
	void SetAppleFields(bool decision);

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
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
	CListBox m_fruitList;
	CEdit control_e_name;
	CEdit control_e_amount;
	CEdit control_e_price;
	CEdit control_e_color;
	CEdit control_e_seeds;
	CEdit control_e_trees;
	afx_msg void OnLbnSelchangeListfruit();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedEdit();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedButton1();
};
