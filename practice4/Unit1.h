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
__published:	// IDE �Ǘ��̃R���|�[�l���g
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
private:	// ���[�U�[�錾
	void __fastcall CsvOutput();
	void __fastcall Preview();
public:		// ���[�U�[�錾
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
