#pragma once
#include "framework.h"
#include "Fruit_Efimenko.h"
#include "Apple_Efimenko.h"


class MyDialogE;
class AddDialog;

class Salad_Efimenko 
{
public:

	vector <shared_ptr<Fruit_Efimenko>> plate;
	void AddFruit();
	void AddApple();
	void PrintFruitt();
	void WriteFruitToFile(CArchive& ar);
	void ReadFruitFromFile(CArchive& ar);
	void DeleteFruit();
	Salad_Efimenko();
	int Delete_fromList(int res);
	CSize DocSize(CDC* pDC);
	
	void GetList(MyDialogE* dlg, int dword);
	void LoadObj(AddDialog* dlg, int index);

	void save_obj(AddDialog* dlg, bool check, int index =-1);
	

};
