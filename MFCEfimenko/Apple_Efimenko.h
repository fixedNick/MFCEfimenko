#pragma once
#include "Fruit_Efimenko.h"
class MyDialogE;
class AddDialog;


class Apple_Efimenko :
    public Fruit_Efimenko
{
public:
    DECLARE_SERIAL(Apple_Efimenko);
    string color;
    int trees;
    char seed;

    Apple_Efimenko();
    ~Apple_Efimenko();

    void Serialize(CArchive& ar);
    void PrintFruit();
    void InputFruit();
    void sizenL(int* nLength, CDC* pDC);
    void DrowInterface(CDC* pDC, int* PosX, int& top, int Height);
    void Fillfield(MyDialogE* dlg);
    void Fillfield(AddDialog* dlg);
    void ReadFromFields(AddDialog* dlg);
};

