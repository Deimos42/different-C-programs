//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "stddef.h"        //
//---------------------------------------------------------------------------

class Set1
{
	private:
		int chislo;
		//int size1;
		//int s;
		//int *mas;           // int *mas = new int[size1];
	public:
		//int chislo; // ��� ������ ����������� ������� � private
		int size1;   //
		int *mas; //

		Set1() : size1(0),mas(new int[0]) {};
		//Set1(const Set1 &X);
		~Set1();
		//void Vvod();
		//void Vivod();
		void Add(int elem); // void
		void Del(int chisl);   // void
		int Poisk(int chisl);  // void

		friend Set1 operator&(Set1& A,Set1& B); // �����������   const Set& A,const Set& B
		friend Set1 operator|(Set1& A,Set1& B); // �����������  const Set& A,const Set& B


};



class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TEdit *Edit3;
	TButton *Button7;
	TButton *Button8;
	TEdit *Edit4;
	TEdit *Edit5;
	TButton *Button9;
	TEdit *Edit6;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label25;
	TLabel *Label26;
	TLabel *Label27;
	TLabel *Label28;
	TLabel *Label29;
	TLabel *Label30;
	TLabel *Label31;
	TLabel *Label32;
	TLabel *Label33;
	TLabel *Label34;
	TLabel *Label35;
	TLabel *Label36;
	TLabel *Label37;
	TLabel *Label38;
	TLabel *Label39;
	TLabel *Label40;
	TLabel *Label41;
	TLabel *Label42;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);

	Set1 A;
	Set1 B;
	Set1 S;
	Set1 V;

};

/*
class Set1
{
	private:
		int chislo;
		int size1;
		//int s;
		int *mas;           // int *mas = new int[size1];
	public:
		Set1() : size1(0),mas(new int[0]) {};
		Set1(const Set1 &X);
		~Set1();
		//void Vvod();
		//void Vivod();
		int Add(int elem); // void
		void Del(int chisl);
		int Poisk(int chisl);  // void

		friend Set1 operator&(Set1& A,Set1& B); // �����������   const Set& A,const Set& B
		friend Set1 operator|(Set1& A,Set1& B); // �����������  const Set& A,const Set& B


};
*/


//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
