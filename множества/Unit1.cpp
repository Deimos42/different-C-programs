//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

/*
Set1::Set1(const Set1 &X):size1(X.size1)    // new int[size1]
{
    mas = new int[size1];
	for(int i = 0; i < 100; i++)
		mas[i] = X.mas[i];
}
*/


Set1::~Set1()
{
   //delete[]mas;  //
   size1 = 0;
}

void Set1::Add(int elem)
{
	int k = 0;

	if(size1 == 0)
	{
		size1 += 1;
		mas[0] = elem;  // mas[k]
        k += 1;
    }
	else
	{
		//while((elem != mas[k])and(k < size1))
		//{
		// 	k += 1;
		//}

		while(k < size1)
		{
			if(elem == mas[k])
				break;
			k += 1;
		}

		if(k >= size1)
		{
			size1 += 1;
			//k += 1;  //
			mas[k] = elem;
        }
	}
	//return elem;
	//Vivod();
}

int Set1::Poisk(int chisl)
{
	int k = 0;
	int index = -1;

	//while((k < size1)and(mas[k] != chisl))
	//{
	//    k += 1;
	//}

	while(k < size1)
    {
        if(mas[k] == chisl)
            break;
		k += 1;
	}

    if(mas[k] == chisl)
    {
        index = k;
		//cout << "��� ����� ���� �� ���������" << endl;
		//cout << "��� ������: " << index << endl;
	}

	//else
	//{
	//	cout << "������ ����� ��� �� ���������" << endl;
	//}
	return index;
}

void Set1::Del(int chisl) // int   // ���� ����� ���� ������� ���-�� � ���������� ��������� �������, ��� ��� �� �� ��������� � ������ �� �������� ������
{
// �������� � ���������� ���������� ������� ����� ��������
	int k = 0;
	int index;

	while(k < size1)
    {
        if(mas[k] == chisl)
            break;
        k += 1;
	}

    if(mas[k] == chisl)
    {
        index = k;
        for(int j = index; j < size1-1; j++)
		{
            mas[j] = mas[j+1];
		}
		mas[size1-1] = 0;
		//ShowMessage(size1);

		size1 -= 1;
		//return 1;
	}
	//return 0;
}

// ����������� ������� �� ������ ����� ��������
Set1 operator&(Set1& A,Set1& B)
{
    int i;
    int j;
    int elem;
	Set1 P;

    for(int k = 0; k < A.size1; k++)
    {
		elem = A.mas[k];
		P.Add(elem);
    }


    bool flag;
    for(int j = 0; j < B.size1; j++)
    {
        flag = false;
        for(int i = 0; i < A.size1; i++)
		{
            if(B.mas[j] == A.mas[i])
            {
				flag = true;
                break;
            }
        }
        if(flag == false)
        {
			elem = B.mas[j];
			P.Add(elem);
        }
    }

    return P;

}

// �������� � ����������� ���������� �������� � �����������
Set1 operator|(Set1& A,Set1& B)
{
    int i = 0;
    int j = 0;
    int elem;
	Set1 C;

    bool flag;
    for(int j = 0; j < B.size1; j++)
    {
        flag = false;
        for(int i = 0; i < A.size1; i++)
		{
            if(B.mas[j] == A.mas[i])
            {
				flag = true;
                break;
            }
        }
        if(flag == true)
        {
			elem = B.mas[j];
			C.Add(elem);
        }
    }

    return C;
}


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Repaint();
	int w = A.size1;
	int w2 = B.size1;
	int w3 = S.size1;
	int w4 = V.size1;

	int el;
	int el2;
	int el3;
	int el4;

	//Label39->Caption = w;    ��� �������� �������� ���������
	//Label40->Caption = w2;
	//Label41->Caption = w3;
	//Label42->Caption = w4;

	// ����� �������� � ���� ������ ���� ������ ��������
	//----- �������������� ����� ----------------------
	// 1 ���������

	Canvas->MoveTo(200,100);
	Canvas->LineTo(200+w*30,100);

	Canvas->MoveTo(200,130);
	Canvas->LineTo(200+w*30,130);

	// 2 ���������
	Canvas->MoveTo(200,160);
	Canvas->LineTo(200+w2*30,160);

	Canvas->MoveTo(200,190);
	Canvas->LineTo(200+w2*30,190);

	// ������������ ���������
	Canvas->MoveTo(200,390);  // 490
	Canvas->LineTo(200+w3*30,390);  // 490

	Canvas->MoveTo(200,420);         // 520
	Canvas->LineTo(200+w3*30,420);  // 520

	// ������������ ���������
	Canvas->MoveTo(200,490);            // 590
	Canvas->LineTo(200+w4*30,490);     // 590

	Canvas->MoveTo(200,520);             // 620
	Canvas->LineTo(200+w4*30,520);     // 620


	//----- ������������ ����� ----------------------
	// 1 ���������

	for(int i = 0; i <= w; i++)
	{
		el = A.mas[i];
		Canvas->MoveTo(200+i*30,100);
		Canvas->LineTo(200+i*30,130);
	}


	switch (w) {
	case 1:
		Label1->Caption = A.mas[0];
		break;
	case 2:
		Label1->Caption = A.mas[0];
		Label2->Caption = A.mas[1];
		break;
	case 3:
		Label1->Caption = A.mas[0];
		Label2->Caption = A.mas[1];
		Label3->Caption = A.mas[2];
		break;
	case 4:
		Label1->Caption = A.mas[0];
		Label2->Caption = A.mas[1];
		Label3->Caption = A.mas[2];
		Label4->Caption = A.mas[3];
		break;
	case 5:
		Label1->Caption = A.mas[0];
		Label2->Caption = A.mas[1];
		Label3->Caption = A.mas[2];
		Label4->Caption = A.mas[3];
		Label5->Caption = A.mas[4];
		break;
	case 6:
		Label1->Caption = A.mas[0];
		Label2->Caption = A.mas[1];
		Label3->Caption = A.mas[2];
		Label4->Caption = A.mas[3];
		Label5->Caption = A.mas[4];
		Label6->Caption = A.mas[5];
		break;
	case 7:
		Label1->Caption = A.mas[0];
		Label2->Caption = A.mas[1];
		Label3->Caption = A.mas[2];
		Label4->Caption = A.mas[3];
		Label5->Caption = A.mas[4];
		Label6->Caption = A.mas[5];
		Label7->Caption = A.mas[6];
		break;
	case 8:
		Label1->Caption = A.mas[0];
		Label2->Caption = A.mas[1];
		Label3->Caption = A.mas[2];
		Label4->Caption = A.mas[3];
		Label5->Caption = A.mas[4];
		Label6->Caption = A.mas[5];
		Label7->Caption = A.mas[6];
		Label8->Caption = A.mas[7];
		break;
	case 9:
		Label1->Caption = A.mas[0];
		Label2->Caption = A.mas[1];
		Label3->Caption = A.mas[2];
		Label4->Caption = A.mas[3];
		Label5->Caption = A.mas[4];
		Label6->Caption = A.mas[5];
		Label7->Caption = A.mas[6];
		Label8->Caption = A.mas[7];
		Label9->Caption = A.mas[8];
		break;
	default:
		break;
	}


	// 2 ���������

	for(int i = 0; i <= w2; i++)
	{
		el2 = B.mas[i];
		Canvas->MoveTo(200+i*30,160);
		Canvas->LineTo(200+i*30,190);
	}

	switch (w2) {
	case 1:
		Label10->Caption = B.mas[0];
		break;
	case 2:
		Label10->Caption = B.mas[0];
		Label11->Caption = B.mas[1];
		break;
	case 3:
		Label10->Caption = B.mas[0];
		Label11->Caption = B.mas[1];
		Label12->Caption = B.mas[2];
		break;
	case 4:
		Label10->Caption = B.mas[0];
		Label11->Caption = B.mas[1];
		Label12->Caption = B.mas[2];
		Label13->Caption = B.mas[3];
		break;
	case 5:
		Label10->Caption = B.mas[0];
		Label11->Caption = B.mas[1];
		Label12->Caption = B.mas[2];
		Label13->Caption = B.mas[3];
		Label14->Caption = B.mas[4];
		break;
	case 6:
		Label10->Caption = B.mas[0];
		Label11->Caption = B.mas[1];
		Label12->Caption = B.mas[2];
		Label13->Caption = B.mas[3];
		Label14->Caption = B.mas[4];
		Label15->Caption = B.mas[5];
		break;
	case 7:
		Label10->Caption = B.mas[0];
		Label11->Caption = B.mas[1];
		Label12->Caption = B.mas[2];
		Label13->Caption = B.mas[3];
		Label14->Caption = B.mas[4];
		Label15->Caption = B.mas[5];
		Label16->Caption = B.mas[6];
		break;
	case 8:
		Label10->Caption = B.mas[0];
		Label11->Caption = B.mas[1];
		Label12->Caption = B.mas[2];
		Label13->Caption = B.mas[3];
		Label14->Caption = B.mas[4];
		Label15->Caption = B.mas[5];
		Label16->Caption = B.mas[6];
		Label17->Caption = B.mas[7];
		break;
	case 9:
		Label10->Caption = B.mas[0];
		Label11->Caption = B.mas[1];
		Label12->Caption = B.mas[2];
		Label13->Caption = B.mas[3];
		Label14->Caption = B.mas[4];
		Label15->Caption = B.mas[5];
		Label16->Caption = B.mas[6];
		Label17->Caption = B.mas[7];
		Label18->Caption = B.mas[8];
		break;
    default:
		break;
	}

	// ��������� �����������
	for(int i = 0; i <= w3; i++)  // w3
	{
		el3 = S.mas[i];
		Canvas->MoveTo(200+i*30,390);   // 490
		Canvas->LineTo(200+i*30,420);    // 520
	}


	switch (w3) {       // w3
	case 1:
		Label19->Caption = S.mas[0];
		break;
	case 2:
		Label19->Caption = S.mas[0];
		Label20->Caption = S.mas[1];
		break;
	case 3:
		Label19->Caption = S.mas[0];
		Label20->Caption = S.mas[1];
		Label21->Caption = S.mas[2];
		break;
	case 4:
		Label19->Caption = S.mas[0];
		Label20->Caption = S.mas[1];
		Label21->Caption = S.mas[2];
		Label22->Caption = S.mas[3];
		break;
	case 5:
		Label19->Caption = S.mas[0];
		Label20->Caption = S.mas[1];
		Label21->Caption = S.mas[2];
		Label22->Caption = S.mas[3];
		Label23->Caption = S.mas[4];
		break;
	case 6:
		Label19->Caption = S.mas[0];
		Label20->Caption = S.mas[1];
		Label21->Caption = S.mas[2];
		Label22->Caption = S.mas[3];
		Label23->Caption = S.mas[4];
		Label24->Caption = S.mas[5];
		break;
	case 7:
		Label19->Caption = S.mas[0];
		Label20->Caption = S.mas[1];
		Label21->Caption = S.mas[2];
		Label22->Caption = S.mas[3];
		Label23->Caption = S.mas[4];
		Label24->Caption = S.mas[5];
		Label25->Caption = S.mas[6];
		break;
	case 8:
		Label19->Caption = S.mas[0];
		Label20->Caption = S.mas[1];
		Label21->Caption = S.mas[2];
		Label22->Caption = S.mas[3];
		Label23->Caption = S.mas[4];
		Label24->Caption = S.mas[5];
		Label25->Caption = S.mas[6];
		Label26->Caption = S.mas[7];
		break;
	case 9:
		Label19->Caption = S.mas[0];
		Label20->Caption = S.mas[1];
		Label21->Caption = S.mas[2];
		Label22->Caption = S.mas[3];
		Label23->Caption = S.mas[4];
		Label24->Caption = S.mas[5];
		Label25->Caption = S.mas[6];
		Label26->Caption = S.mas[7];
		Label27->Caption = S.mas[8];
		break;
	case 10:
		Label19->Caption = S.mas[0];
		Label20->Caption = S.mas[1];
		Label21->Caption = S.mas[2];
		Label22->Caption = S.mas[3];
		Label23->Caption = S.mas[4];
		Label24->Caption = S.mas[5];
		Label25->Caption = S.mas[6];
		Label26->Caption = S.mas[7];
		Label27->Caption = S.mas[8];
		Label28->Caption = S.mas[9];
		break;
	case 11:
		Label19->Caption = S.mas[0];
		Label20->Caption = S.mas[1];
		Label21->Caption = S.mas[2];
		Label22->Caption = S.mas[3];
		Label23->Caption = S.mas[4];
		Label24->Caption = S.mas[5];
		Label25->Caption = S.mas[6];
		Label26->Caption = S.mas[7];
		Label27->Caption = S.mas[8];
		Label28->Caption = S.mas[9];
		Label29->Caption = S.mas[10];
		break;
	case 12:
		Label19->Caption = S.mas[0];
		Label20->Caption = S.mas[1];
		Label21->Caption = S.mas[2];
		Label22->Caption = S.mas[3];
		Label23->Caption = S.mas[4];
		Label24->Caption = S.mas[5];
		Label25->Caption = S.mas[6];
		Label26->Caption = S.mas[7];
		Label27->Caption = S.mas[8];
		Label28->Caption = S.mas[9];
		Label29->Caption = S.mas[10];
		Label30->Caption = S.mas[11];
		break;

	default:
		break;
	}


	// ��������� �����������
	for(int i = 0; i <= w4; i++)  // w4
	{
		el4 = V.mas[i];
		Canvas->MoveTo(200+i*30,490);     // 590
		Canvas->LineTo(200+i*30,520);      // 620
	}


	switch (w4) {    // w4
	case 1:
		Label31->Caption = V.mas[0];
		break;
	case 2:
		Label31->Caption = V.mas[0];
		Label32->Caption = V.mas[1];
		break;
	case 3:
		Label31->Caption = V.mas[0];
		Label32->Caption = V.mas[1];
		Label33->Caption = V.mas[2];
		break;
	case 4:
		Label31->Caption = V.mas[0];
		Label32->Caption = V.mas[1];
		Label33->Caption = V.mas[2];
		Label34->Caption = V.mas[3];
		break;
	case 5:
		Label31->Caption = V.mas[0];
		Label32->Caption = V.mas[1];
		Label33->Caption = V.mas[2];
		Label34->Caption = V.mas[3];
		Label35->Caption = V.mas[4];
		break;
	case 6:
		Label31->Caption = V.mas[0];
		Label32->Caption = V.mas[1];
		Label33->Caption = V.mas[2];
		Label34->Caption = V.mas[3];
		Label35->Caption = V.mas[4];
		Label36->Caption = V.mas[5];
		break;
	case 7:
		Label31->Caption = V.mas[0];
		Label32->Caption = V.mas[1];
		Label33->Caption = V.mas[2];
		Label34->Caption = V.mas[3];
		Label35->Caption = V.mas[4];
		Label36->Caption = V.mas[5];
		Label37->Caption = V.mas[6];
		break;
	case 8:
		Label31->Caption = V.mas[0];
		Label32->Caption = V.mas[1];
		Label33->Caption = V.mas[2];
		Label34->Caption = V.mas[3];
		Label35->Caption = V.mas[4];
		Label36->Caption = V.mas[5];
		Label37->Caption = V.mas[6];
		Label38->Caption = V.mas[7];
		break;
	case 9:
		Label31->Caption = V.mas[0];
		Label32->Caption = V.mas[1];
		Label33->Caption = V.mas[2];
		Label34->Caption = V.mas[3];
		Label35->Caption = V.mas[4];
		Label36->Caption = V.mas[5];
		Label37->Caption = V.mas[6];
		Label38->Caption = V.mas[7];
		Label39->Caption = V.mas[8];
		break;
	case 10:
		Label31->Caption = V.mas[0];
		Label32->Caption = V.mas[1];
		Label33->Caption = V.mas[2];
		Label34->Caption = V.mas[3];
		Label35->Caption = V.mas[4];
		Label36->Caption = V.mas[5];
		Label37->Caption = V.mas[6];
		Label38->Caption = V.mas[7];
		Label39->Caption = V.mas[8];
		Label40->Caption = V.mas[9];
		break;
	case 11:
		Label31->Caption = V.mas[0];
		Label32->Caption = V.mas[1];
		Label33->Caption = V.mas[2];
		Label34->Caption = V.mas[3];
		Label35->Caption = V.mas[4];
		Label36->Caption = V.mas[5];
		Label37->Caption = V.mas[6];
		Label38->Caption = V.mas[7];
		Label39->Caption = V.mas[8];
		Label40->Caption = V.mas[9];
		Label41->Caption = V.mas[10];
		break;
	case 12:
		Label31->Caption = V.mas[0];
		Label32->Caption = V.mas[1];
		Label33->Caption = V.mas[2];
		Label34->Caption = V.mas[3];
		Label35->Caption = V.mas[4];
		Label36->Caption = V.mas[5];
		Label37->Caption = V.mas[6];
		Label38->Caption = V.mas[7];
		Label39->Caption = V.mas[8];
		Label40->Caption = V.mas[9];
		Label41->Caption = V.mas[10];
		Label42->Caption = V.mas[11];
		break;

	default:
		break;
	}




}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int elem;
	int res;
	//Set1 A;
	UnicodeString elem1;
	elem1 = Edit1->Text;
	elem = elem1.ToInt(); // ���� ����� ���� - ������� �������� �� ������������ �����
	A.Add(elem);
	Button1->Click();
	//ShowMessage(res);
	//ShowMessage();
	//Label1->Caption = res;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	int elem;
	int res;
	//Set1 A;
	UnicodeString elem1;
	elem1 = Edit4->Text;
	elem = elem1.ToInt(); // ���� ����� ���� - ������� �������� �� ������������ �����
	B.Add(elem);
	Button1->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	int elem;
	//int bol;
	UnicodeString elem1;
	elem1 = Edit2->Text;
	elem = elem1.ToInt();
	//bol = A.Del(elem);
	A.Del(elem);
	Button1->Click();
	//if(bol == 0)
		//A.size1 += 1;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button8Click(TObject *Sender)
{
	int elem;
	UnicodeString elem1;
	elem1 = Edit5->Text;
	elem = elem1.ToInt();
	B.Del(elem);
	Button1->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	int elem;
	int index;
	UnicodeString elem1;
	elem1 = Edit3->Text;
	elem = elem1.ToInt();
	index = A.Poisk(elem);
	Button1->Click();
	//Edit3->index;
	if(index == -1)
	{
		AnsiString str = "������ �������� �� ���������� �� ���������";
		ShowMessage(str);
	}
	else
	{
		AnsiString str = "������� ������������� ��� ��������: " + IntToStr(index);
		ShowMessage(str);
	}



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
    int elem;
	int index;
	UnicodeString elem1;
	elem1 = Edit6->Text;
	elem = elem1.ToInt();
	index = B.Poisk(elem);
	Button1->Click();
	if(index == -1)
	{
		AnsiString str2 = "������ �������� �� ���������� �� ���������";
		ShowMessage(str2);
	}
	else
	{
		AnsiString str2 = "������� ������������� ��� ��������: " + IntToStr(index);
		ShowMessage(str2);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{
	S = A & B;
	Button1->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	V = A | B;
    Button1->Click();
}
//---------------------------------------------------------------------------

