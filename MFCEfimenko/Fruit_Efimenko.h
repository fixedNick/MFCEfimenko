#pragma once
#include "framework.h"

class MyDialogE;
class AddDialog;


class Fruit_Efimenko : public CObject

{
public:
	DECLARE_SERIAL(Fruit_Efimenko);
	string name;
	int amount = 0; //параметры по умолчанию
	double price = 0;
	Fruit_Efimenko();
	~Fruit_Efimenko();
	virtual void Serialize(CArchive& ar);
	virtual void PrintFruit();
	virtual void InputFruit();
	virtual void sizenL(int* nLength, CDC* pDC);

	virtual void Fillfield(MyDialogE* dlg);
	virtual void Fillfield(AddDialog* dlg);

	virtual void ReadFromFields(AddDialog* dlg);
	virtual void DrowInterface(CDC* pDC, int* PosX, int& top, int Height);
};

