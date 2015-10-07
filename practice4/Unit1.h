//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE 管理のコンポーネント
	TLabel *lbl_Title;
	TShape *shp_Title;
	TDBGrid *grd_Address;
	TButton *btn_Preview;
	TShape *Shape2;
	TButton *btn_End;
	TButton *btn_CsvOutput;
	void __fastcall btn_EndClick(TObject *Sender);
	void __fastcall btn_CsvOutputClick(TObject *Sender);
	void __fastcall btn_PreviewClick(TObject *Sender);
private:	// ユーザー宣言
	void __fastcall CsvOutput();
	void __fastcall Preview();
public:		// ユーザー宣言
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
