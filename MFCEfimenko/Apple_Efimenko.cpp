#include "pch.h"
#include "Apple_Efimenko.h"
#include "MyDialogE.h"
#include "AddDialog.h"


IMPLEMENT_SERIAL(Apple_Efimenko, Fruit_Efimenko, VERSIONABLE_SCHEMA | 0);

Apple_Efimenko::Apple_Efimenko()
{
}
Apple_Efimenko::~Apple_Efimenko()
{
}


void Apple_Efimenko::Serialize(CArchive& ar)
{
	Fruit_Efimenko::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << CString(name.c_str()) << amount << price;
		ar << CString(color.c_str()) << trees << seed;
	}
	else
	{
		CString tmp;
		ar >> tmp;
		name = tmp;
		ar >> amount;
		ar >> price;

		ar >> tmp;
		color = tmp;
		ar >> trees;
		ar >> seed;
	}
}

void Apple_Efimenko::PrintFruit()
{
	cout << "====================" << '\n' << "Название: " << name << endl;
	cout << "Кол-во: " << amount << '\n' << "Цена: " << price << endl << endl;
	cout << "Цвет: " << color << '\n' << "Число деревьев: " << trees << '\n' << "Число косточек: " << seed << '\n';
}

void Apple_Efimenko::InputFruit()
{
	cout << "Введите имя: ";
	cin >> name;
	cout << "Введите кол-во: ";
	cin >> amount;
	cout << "Введите стои-ть: ";
	cin >> price;
	cout << "Введите цвет: ";
	cin >> color;
	cout << "Введите число деревьев: ";
	cin >> trees;
	cout << "Число косточек: ";
	cin >> seed;
}

void Apple_Efimenko::sizenL(int* nLength, CDC* pDC)
{
	nLength[0] = pDC->GetTextExtent(name.c_str()).cx;
	nLength[1] = pDC->GetTextExtent(to_string(amount).c_str()).cx;
	nLength[2] = pDC->GetTextExtent(to_string(round(price)).c_str()).cx;
	nLength[3] = pDC->GetTextExtent(color.c_str()).cx;
	nLength[4] = pDC->GetTextExtent(to_string(trees).c_str()).cx;
	nLength[5] = pDC->GetTextExtent(to_string(seed).c_str()).cx;
}

void Apple_Efimenko::DrowInterface(CDC* pDC, int* PosX, int& top, int Height)
{
	pDC->TextOut(PosX[0], top, name.c_str());
	pDC->TextOut(PosX[1], top, to_string(amount).c_str());
	pDC->TextOut(PosX[2], top, to_string(floor(price)).c_str());
	pDC->TextOut(PosX[3], top, color.c_str());
	pDC->TextOut(PosX[4], top, to_string(trees).c_str());
	pDC->TextOut(PosX[5], top, to_string(seed).c_str());
	top += Height;
}
void Apple_Efimenko::Fillfield(MyDialogE* dlg) //POINTER ON DIALOG
{
	dlg->m_name = name.c_str();
	dlg->m_amount = amount;
	dlg->m_price = price;
	dlg->m_color = color.c_str();
	dlg->m_seeds = seed;
	dlg->m_trees = trees;

	dlg->UpdateData(false);
	dlg->SetAppleFields(true);
}

void Apple_Efimenko::Fillfield(AddDialog* dlg)
{
	dlg->m_name = name.c_str();
	dlg->m_amount = amount;
	dlg->m_price = price;
	dlg->m_color = color.c_str();
	dlg->m_seeds = seed;
	dlg->m_trees = trees;
	dlg->UpdateData(false);
}

void Apple_Efimenko::ReadFromFields(AddDialog* dlg)
{
	dlg->UpdateData(true);
	name = dlg->m_name;
	amount=dlg->m_amount;
	price = dlg->m_price;
	color = dlg->m_color;
	seed = dlg->m_amount;
	trees = dlg->m_trees;
}