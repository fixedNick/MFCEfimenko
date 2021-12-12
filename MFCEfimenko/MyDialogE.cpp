// MyDialogE.cpp : implementation file
//

#include "pch.h"
#include "MFCEfimenko.h"
#include "MyDialogE.h"
#include "afxdialogex.h"
#include "AddDialog.h"


// MyDialogE dialog

IMPLEMENT_DYNAMIC(MyDialogE, CDialogEx)

MyDialogE::MyDialogE(CMFCEfimenkoDoc* pDocIns, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_name(_T(""))
	, m_amount(0)
	, m_price(0)
	, m_color(_T(""))
	, m_seeds(0)
	, m_trees(0)
{
	this->pDoc = pDocIns;
}


MyDialogE::~MyDialogE()
{
}

void MyDialogE::SetFruitFields(bool decision)
{
	if (decision)
	{
		//SHOWNORMAL
		control_e_name.ShowWindow(SW_SHOWNORMAL);
		control_e_amount.ShowWindow(SW_SHOWNORMAL);
		control_e_price.ShowWindow(SW_SHOWNORMAL);
		//GetDlgItem(IDC_STATIC)->ShowWindow(SW_SHOWNORMAL);
		
	}
	else
	{
		//SW_HIDE
		control_e_name.ShowWindow(SW_HIDE);
		control_e_amount.ShowWindow(SW_HIDE);
		control_e_price.ShowWindow(SW_HIDE);
		//GetDlgItem(IDC_STATIC)->ShowWindow(SW_HIDE);
		
	}
}

void MyDialogE::SetAppleFields(bool decision)
{
	if (decision)
	{    //SW_SHOWNORMAL
		control_e_name.ShowWindow(SW_SHOWNORMAL);
		control_e_amount.ShowWindow(SW_SHOWNORMAL);
		control_e_price.ShowWindow(SW_SHOWNORMAL);
		control_e_color.ShowWindow(SW_SHOWNORMAL);
		control_e_seeds.ShowWindow(SW_SHOWNORMAL);
		control_e_trees.ShowWindow(SW_SHOWNORMAL);
		//GetDlgItem(IDC_STATIC5)->EnableWindow();
		
	}
	else
	{
		//SW_HIDE
		control_e_name.ShowWindow(SW_HIDE);
		control_e_amount.ShowWindow(SW_HIDE);
		control_e_price.ShowWindow(SW_HIDE);
		control_e_color.ShowWindow(SW_HIDE);
		control_e_seeds.ShowWindow(SW_HIDE);
		control_e_trees.ShowWindow(SW_HIDE);
		//GetDlgItem(IDC_STATIC5)->ShowWindow(SW_HIDE);

	}
}

void MyDialogE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_AMOUNT, m_amount);
	DDX_Text(pDX, IDC_EDIT_PRICE, m_price);
	DDX_Text(pDX, IDC_EDIT_COLOR, m_color);
	DDX_Text(pDX, IDC_EDIT_SEEDS, m_seeds);
	DDX_Text(pDX, IDC_EDIT_TREES, m_trees);
	DDX_Control(pDX, IDC_LISTFRUIT, m_fruitList);
	DDX_Control(pDX, IDC_EDIT_NAME, control_e_name);
	DDX_Control(pDX, IDC_EDIT_AMOUNT, control_e_amount);
	DDX_Control(pDX, IDC_EDIT_PRICE, control_e_price);
	DDX_Control(pDX, IDC_EDIT_COLOR, control_e_color);
	DDX_Control(pDX, IDC_EDIT_SEEDS, control_e_seeds);
	DDX_Control(pDX, IDC_EDIT_TREES, control_e_trees);
}


BEGIN_MESSAGE_MAP(MyDialogE, CDialogEx)

	ON_LBN_SELCHANGE(IDC_LISTFRUIT, &MyDialogE::OnLbnSelchangeListfruit)
	ON_BN_CLICKED(IDC_ADD, &MyDialogE::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_EDIT, &MyDialogE::OnBnClickedEdit)
	ON_BN_CLICKED(IDC_DELETE, &MyDialogE::OnBnClickedDelete)
	//ON_BN_CLICKED(IDC_BUTTON1, &MyDialogE::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDialogE message handlers


BOOL MyDialogE::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	pDoc->saladRecipe.GetList(this,-1);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void MyDialogE::OnLbnSelchangeListfruit()
{
	pDoc->saladRecipe.GetList(this, m_fruitList.GetCurSel());
}

void MyDialogE::OnBnClickedAdd()
{
	AddDialog dialog1(pDoc, -1);
	dialog1.DoModal();
	pDoc->saladRecipe.GetList(this, -3);
}

//void MyDialogE::OnBnClickedAdd() //add dialog
//{
//	int fruitCount = m_fruitList.GetCurSel();
//	AddDialog AddDial(pDoc, fruitCount);
//	AddDial.DoModal();
//	pDoc->saladRecipe.GetList(this, fruitCount);
//	// TODO: Add your control notification handler code here
//}


void MyDialogE::OnBnClickedEdit()
{	
	int index = m_fruitList.GetCurSel();
	if (index == -1) return;
	AddDialog dialog2(pDoc, index);
	dialog2.DoModal();
	pDoc->saladRecipe.GetList(this, index);
	// TODO: Add your control notification handler code here
}


void MyDialogE::OnBnClickedDelete()
{
	int index = m_fruitList.GetCurSel();
	if (index < 0)
		return;
	index = (pDoc->saladRecipe.Delete_fromList(index));
	pDoc->saladRecipe.GetList(this, index);
	// TODO: Add your control notification handler code here
}


void MyDialogE::OnBnClickedButton1()
{
	AddDialog dialog1(pDoc, -1);
	dialog1.DoModal();
	pDoc->saladRecipe.GetList(this, -3);

	// TODO: Add your control notification handler code here
}
