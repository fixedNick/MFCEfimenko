// AddDialog.cpp : implementation file
//

#include "pch.h"
#include "MFCEfimenko.h"
#include "AddDialog.h"
#include "afxdialogex.h"


int TABS_COUNT = 2;

// AddDialog dialog

IMPLEMENT_DYNAMIC(AddDialog, CDialogEx)

AddDialog::AddDialog(CMFCEfimenkoDoc* pDocIns, int index, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_name(_T(""))
	, m_amount(0)
	, m_price(0)
	, m_color(_T(""))
	, m_seeds(0)
	, m_trees(0)
	, m_ShowType(TRUE)
{
	this->pDoc = pDocIns;
	f_index = index;
}

AddDialog::~AddDialog()
{
}
void AddDialog::SetFruitFields(bool decision)
{
		if (decision)
		{
			//SHOWNORMAL
			e_control_name.ShowWindow(SW_SHOWNORMAL);
			e_control_amount.ShowWindow(SW_SHOWNORMAL);
			e_control_price.ShowWindow(SW_SHOWNORMAL);
			//GetDlgItem(IDC_STATIC)->ShowWindow(SW_SHOWNORMAL);

		}
		else
		{
			//SW_HIDE
			e_control_name.ShowWindow(SW_HIDE);
			e_control_amount.ShowWindow(SW_HIDE);
			e_control_price.ShowWindow(SW_HIDE);
			//GetDlgItem(IDC_STATIC)->ShowWindow(SW_HIDE);

		}
}


void AddDialog::SetAppleFields(bool decision)
{
	if (decision)
	{    //SW_SHOWNORMAL
		e_control_name.ShowWindow(SW_SHOWNORMAL);
		e_control_amount.ShowWindow(SW_SHOWNORMAL);
		e_control_price.ShowWindow(SW_SHOWNORMAL);
		e_control_color.ShowWindow(SW_SHOWNORMAL);
		e_control_seeds.ShowWindow(SW_SHOWNORMAL);
		e_control_trees.ShowWindow(SW_SHOWNORMAL);
		//GetDlgItem(IDC_STATIC5)->EnableWindow();

	}
	else
	{
		//SW_HIDE
		e_control_name.ShowWindow(SW_HIDE);
		e_control_amount.ShowWindow(SW_HIDE);
		e_control_price.ShowWindow(SW_HIDE);
		e_control_color.ShowWindow(SW_HIDE);
		e_control_seeds.ShowWindow(SW_HIDE);
		e_control_trees.ShowWindow(SW_HIDE);
		//GetDlgItem(IDC_STATIC5)->ShowWindow(SW_HIDE);
		}
}

void AddDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT2_AMOUNT, m_amount);
	DDX_Text(pDX, IDC_EDIT2_PRICE, m_price);
	DDX_Text(pDX, IDC_EDIT2_COLOR, m_color);
	DDX_Text(pDX, IDC_EDIT2_SEEDS, m_seeds);
	DDX_Text(pDX, IDC_EDIT2_TREES, m_trees);
	DDX_Control(pDX, IDC_EDIT2_NAME, e_control_name);
	DDX_Control(pDX, IDC_EDIT2_AMOUNT, e_control_amount);
	DDX_Control(pDX, IDC_EDIT2_PRICE, e_control_price);
	DDX_Control(pDX, IDC_EDIT2_COLOR, e_control_color);
	DDX_Control(pDX, IDC_EDIT2_SEEDS, e_control_seeds);
	DDX_Control(pDX, IDC_EDIT2_TREES, e_control_trees);
	DDX_Radio(pDX, IDC_RADIO_FRUIT, m_ShowType);
	DDX_Control(pDX, IDC_TAB1, TabManager);
}


BEGIN_MESSAGE_MAP(AddDialog, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_FRUIT, &AddDialog::OnBnClickedRadioFruit)
	ON_BN_CLICKED(IDC_RADIO_APPLE, &AddDialog::OnBnClickedRadioFruit)
	ON_BN_CLICKED(IDOK, &AddDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK1, &AddDialog::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON1, &AddDialog::BtnToLeftClicked)
	ON_BN_CLICKED(IDC_BUTTON2, &AddDialog::BtnToRightClicked)
END_MESSAGE_MAP()


// AddDialog message handlers


BOOL AddDialog::OnInitDialog()
{

	CDialogEx::OnInitDialog();
	if (f_index == -1)
	{
		CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
		pBtn->SetCheck(1);

	}

	if (f_index >= 0)
		pDoc->saladRecipe.LoadObj(this, f_index);
	// TODO:  Add extra initialization here

	TabManager.InsertItem(0, "Fruit");
	TabManager.InsertItem(1, "Apple");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void AddDialog::OnBnClickedRadioFruit()
{
	UpdateData();
	switch (m_ShowType)
	{
	case 0:
		SetAppleFields(false);
		SetFruitFields(true);
		break;
	case 1:
		SetFruitFields(false);
		SetAppleFields(true);
		break;
	}
}


void AddDialog::OnBnClickedOk()//first for add// second for edit
{
	if (f_index < 0)
	{
		pDoc->saladRecipe.save_obj(this, m_ShowType);
	}
	else
	{
		pDoc->saladRecipe.save_obj(this, m_ShowType, f_index);// change exact index
	}
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}




void AddDialog::OnBnClickedCheck1()
{
	UpdateData();

	if (IsDlgButtonChecked(IDC_CHECK1))
	{
		SetAppleFields(true);
	}
	else
	{
		SetAppleFields(false);
		SetFruitFields(true);
	}
}
	// TODO: Add your control notification handler code here

void AddDialog::BtnToLeftClicked()
{
	TabManager.SetCurSel(TabManager.GetCurSel() == 0 ?
		(TABS_COUNT - 1) :
		(TabManager.GetCurSel() - 1));
	// TODO: Add your control notification handler code here
}


void AddDialog::BtnToRightClicked()
{
	TabManager.SetCurSel(TabManager.GetCurSel() == (TABS_COUNT - 1) ?
		0 :
		(TabManager.GetCurSel() + 1));
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
}
