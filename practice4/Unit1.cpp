//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "sqlite3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CorepoEng2009"
#pragma link "sqlite3.lib"
#pragma resource "*.dfm"
TForm1 *Form1;

//**************************************************
//【イベント処理】
//**************************************************
//---------------------------------------------------------------------------
/**
 * フォームロード
 */
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	// メソッド内変数宣言
	TGridRect selection;

	try
	{
		//**************************************************
		//【初期化】
		//  変数
		//**************************************************
		selection.Left = -1;
		selection.Top = -1;
		selection.Right = -1;
		selection.Bottom = -1;

		//**************************************************
		//【初期化】
		//  コントロール
		//**************************************************
		// 住所リスト
		this->grd_Address->RowCount = 1;
		this->grd_Address->RowHeights[0] = 24;
		this->grd_Address->FixedRows = 0;

		// 住所リスト（ヘッダ）
		this->grd_Address->Cells[0][0] = "ID";
		this->grd_Address->ColWidths[0] = 50;

		this->grd_Address->Cells[1][0] = "名前";
		this->grd_Address->ColWidths[1] = 100;

		this->grd_Address->Cells[2][0] = "住所";
		this->grd_Address->ColWidths[2] = 174;

		this->grd_Address->Cells[3][0] = "メモ";
		this->grd_Address->ColWidths[3] = 150;

		this->grd_Address->Cells[4][0] = "有効";
		this->grd_Address->ColWidths[4] = 45;

		// 住所リスト（選択状態）
		this->grd_Address->Selection = selection;

		//**************************************************
		//【住所リスト表示】
		//**************************************************
		ShowAddress();
	}
	catch (int e)
	{
		ShowMessage("初期表示中に例外が発生しました。");
	}
}
//---------------------------------------------------------------------------
/**
 * 閉じるボタン押下
 * @param TObject *Sender 呼び出し元オブジェクト
 * @return void
 */
void __fastcall TForm1::btn_EndClick(TObject *Sender)
{
	// メソッド内変数宣言

	//**************************************************
	//【終了】
	//**************************************************
	this->Close();
}
//---------------------------------------------------------------------------
/**
 * CSV出力ボタン押下
 * @param TObject *Sender 呼び出し元オブジェクト
 * @return void
 */
void __fastcall TForm1::btn_CsvOutputClick(TObject *Sender)
{
	// メソッド内変数宣言

	try
	{
		//**************************************************
		//【チェック】
		//**************************************************
        //
		// データ
		//
		if (this->grd_Address->Row == 0)
		{
			// なし
			ShowMessage("CSV出力するデータがありません。");
			return;
		}

		//**************************************************
		//【CSV出力処理】
		//**************************************************
        CsvOutput();
	}
	catch (int e)
	{
		ShowMessage("CSV出力中に例外が発生しました。");
	}
}
//---------------------------------------------------------------------------
 /**
 * プレビューボタン押下
 * @param TObject *Sender 呼び出し元オブジェクト
 * @return void
 */
void __fastcall TForm1::btn_PreviewClick(TObject *Sender)
{
	// メソッド内変数宣言

	try
	{
        //**************************************************
		//【チェック】
		//**************************************************
        //
		// データ
		//
		if (this->grd_Address->Row == 0)
		{
			// なし
			ShowMessage("プレビューするデータがありません。");
			return;
		}

		//**************************************************
		//【プレビュー処理】
		//**************************************************
        Preview();
	}
	catch (int e)
	{
		ShowMessage("プレビュー中に例外が発生しました。");
	}
}
//---------------------------------------------------------------------------
 /**
 * 住所リスト描画
 * @param TObject *Sender 呼び出し元オブジェクト
 * @param int ACol 描画する列位置
 * @param int ARow 描画する行位置
 * @param TRect &Rect 描画するセル座標
 * @param TGridDrawState State
 * @return void
 */
void __fastcall TForm1::grd_AddressDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
//	// メソッド内変数宣言
//    AnsiString value;
//	unsigned int pos;
//	RECT r = RECT(Rect);
//
//	//**************************************************
//	//【ヘッダ】
//	//**************************************************
//	if (ARow == 0)
//	{
//		pos = DT_SINGLELINE | DT_VCENTER | DT_CENTER;
//	}
//	//**************************************************
//	//【通常行】
//	//**************************************************
//	else if (ARow > 0)
//	{
//		switch (ACol)
//		{
//			// ID
//			case 0:
//				pos = DT_SINGLELINE | DT_VCENTER | DT_RIGHT;
//				break;
//
//			// 名前
//			case 1:
//				pos = DT_SINGLELINE | DT_VCENTER | DT_LEFT;
//				break;
//
//			// 住所
//			case 2:
//				pos = DT_SINGLELINE | DT_VCENTER | DT_LEFT;
//				break;
//
//			// メモ
//			case 3:
//				pos = DT_SINGLELINE | DT_VCENTER | DT_LEFT;
//				break;
//
//			// 有効
//			case 4:
//				pos = DT_SINGLELINE | DT_VCENTER | DT_CENTER;
//				break;
//		}
//	}
//
//	// セル値取得
//	value = grd_Address->Cells[ACol][ARow];
//
//	// クリア
//	grd_Address->Canvas->FillRect(Rect);
//
//	// フォーカス枠の描画
//	if (State.Contains(gdSelected))
//	{
//		grd_Address->Canvas->Font->Color = clHighlightText;
//
//		if (State.Contains(gdFocused))
//		{
//			DrawFocusRect(
//				grd_Address->Canvas->Handle,
//				&r
//			);
//		}
//	}
//	else
//	{
//		//grd_Address->Canvas->Font->Color = grd_Address->Font->Color;
//		grd_Address->Canvas->Font->Color = clWindowText;
//	}
//
////	// テキスト表示領域の設定
////	InflateRect(
////		&r,
////		-2,
////		-2
////	);
//
//	// セル再描画
//	DrawText(
//		grd_Address->Canvas->Handle,
//		value.c_str(),
//		value.Length(),
//		&Rect,
//		pos
//	);
	TStringGrid *grid = dynamic_cast<TStringGrid *>(Sender);
	AnsiString value = grd_Address->Cells[ACol][ARow];
	unsigned int position = DT_VCENTER|DT_CENTER|DT_SINGLELINE;

	// セルの背景色を変更する
	if (ARow == 0)
	{
		grd_Address->Canvas->Brush->Color = clBtnFace;
	}
	else
	{
		grd_Address->Canvas->Brush->Color = clWhite;
	}

	// 背景色で塗りつぶす
	grd_Address->Canvas->FillRect(Rect);

	// セルの中の文字列を再度、Canvasに描画する。
	// フォントカラーを書き直す
	// 背景色を書き直す
	grd_Address->Canvas->Font->Color=grd_Address->Font->Color;

	// 位置
	if (ARow == 0)
	{
		// ヘッダ
		position = DT_SINGLELINE | DT_VCENTER | DT_CENTER;
	}
	else if (ARow > 0)
	{
		// 通常行
		switch (ACol)
		{
			// ID
			case 0:
				position = DT_SINGLELINE | DT_VCENTER | DT_RIGHT;
				break;

			// 名前
			case 1:
				position = DT_SINGLELINE | DT_VCENTER | DT_LEFT;
				break;

			// 住所
			case 2:
				position = DT_SINGLELINE | DT_VCENTER | DT_LEFT;
				break;

			// メモ
			case 3:
				position = DT_SINGLELINE | DT_VCENTER | DT_LEFT;
				break;

			// 有効
			case 4:
				position = DT_SINGLELINE | DT_VCENTER | DT_CENTER;
				break;
		}
	}

	// 再描画
	DrawText(
		grd_Address->Canvas->Handle,
		value.c_str(),
		value.Length(),
		&Rect,
		position
	);
}
//---------------------------------------------------------------------------

//**************************************************
//【ユーザー定義関数】
//**************************************************
/**
 * 【コールバック】住所リスト表示
 * @param void*
 * @param int argc
 * @param char** argv
 * @param char** columnNames
 * @return int
 */
int callback_ShowAddress(void*, int argc, char** argv, char** columnNames)
{
	// メソッド内変数宣言
	int ret = 0;

	try
	{
		//**************************************************
		//【住所リスト】
		//  行追加
		//**************************************************
		Form1->grd_Address->RowCount++;

		// 行インデックス取得
		int rowIndex = Form1->grd_Address->RowCount - 1;

		//**************************************************
		//【住所リスト】
		//  スタイル設定
		//**************************************************
		// 固定行
		Form1->grd_Address->FixedRows = 1;

        // 高さ
		Form1->grd_Address->RowHeights[rowIndex] = 24;

		//**************************************************
		//【住所リスト表示】
		//  データ設定
		//**************************************************
		AnsiString id = argv[0];
		AnsiString name = argv[1];
		AnsiString address = argv[2];
		AnsiString memo = argv[3];
		AnsiString valid = argv[4];

		// ID
		Form1->grd_Address->Cells[0][rowIndex] = id;

		// 名前
		Form1->grd_Address->Cells[1][rowIndex] = name;

		// 住所
		Form1->grd_Address->Cells[2][rowIndex] = address;

		// メモ
		Form1->grd_Address->Cells[3][rowIndex] = memo;

		// 有効
		if (valid == "1")
		{
			// ○：有効
			Form1->grd_Address->Cells[4][rowIndex] = "○";
		}
		else
		{
			// ×：無効
			Form1->grd_Address->Cells[4][rowIndex] = "×";
		}
    }
	catch (int e)
	{
		throw e;
	}

	return ret;
}
//---------------------------------------------------------------------------
/**
 * 住所リスト表示
 * @param
 * @return void
 */
void __fastcall TForm1::ShowAddress()
{
	// メソッド内変数宣言
	sqlite3* dbObj;
	char *sql;
	int result;

	try
	{
		//**************************************************
		//【ＤＢ接続】
		//**************************************************
		if (sqlite3_open("practice4.sqlite3", &dbObj) != SQLITE_OK)
		{
			// ＮＧ
			ShowMessage("ＤＢ接続中に異常が発生しました。");
			return;
		}

		//**************************************************
		//【ＳＱＬ生成】
		//**************************************************
		sql =
			sqlite3_mprintf(
				"SELECT "
					"* "
				"FROM "
					"p4_address "
				"ORDER BY "
					"id"
		);

		//**************************************************
		//【ＳＱＬ実行】
		//**************************************************
		// 実行
		result =
			sqlite3_exec(
				dbObj,
				sql,
				callback_ShowAddress,
				NULL,
				NULL
		);

		// 実行結果チェック
		if (result != SQLITE_OK)
		{
			ShowMessage("ＳＱＬ実行中に異常が発生しました。");
		}

		// オブジェクト解放
		sqlite3_free(sql);

		//**************************************************
		//【ＤＢ切断】
		//**************************************************
		sqlite3_close(dbObj);
    }
	catch (int e)
	{
		throw e;
	}
}
//---------------------------------------------------------------------------
/**
 * CSV出力処理
 * @param
 * @return void
 */
void __fastcall TForm1::CsvOutput()
{
	// メソッド内変数宣言
	TStringList *output = new TStringList;

	try
	{
        //**************************************************
		//【CSV出力データ生成】
		//**************************************************
		for (int i = 0; i < this->grd_Address->RowCount; i++)
		{
			//==================================================
			//【出力データ抽出】
			//==================================================
			AnsiString id = this->grd_Address->Cells[0][i];
			AnsiString name = this->grd_Address->Cells[1][i];
			AnsiString address = this->grd_Address->Cells[2][i];
			AnsiString memo = this->grd_Address->Cells[3][i];
			AnsiString valid = this->grd_Address->Cells[4][i];

			//==================================================
			//【チェック】
			//==================================================
			if (i != 0 && valid != "○")
			{
				continue;
			}

			//==================================================
			//【出力レコード生成】
			//==================================================
			TStringList *record = new TStringList;
			record->Add(id);
			record->Add(name);
			record->Add(address);
			record->Add(memo);

			//==================================================
			//【出力データ設定】
			//==================================================
			output->Add(record->CommaText);
		}

		//**************************************************
		//【CSV出力】
		//**************************************************
		// ダイアログ設定
		dlg_CsvOutput->DefaultExt = ".csv";
		dlg_CsvOutput->Filter = "CSVファイル (*.csv)|*.csv";
		dlg_CsvOutput->Title = "出力先を指定してください。";
		dlg_CsvOutput->Options << ofOverwritePrompt << ofCreatePrompt;

		// ダイアログ表示
		if (dlg_CsvOutput->Execute())
		{
			// 出力
			output->SaveToFile(dlg_CsvOutput->FileName);
		}
    }
	catch (int e)
	{
		throw e;
	}
}
//---------------------------------------------------------------------------
/**
 * プレビュー処理
 * @param
 * @return void
 */
void __fastcall TForm1::Preview()
{
	// メソッド内変数宣言
	DWORD CrpErrCode;
	DWORD WinErrCode;
	TcwPrintFlags prtOpt;

	try
	{
        //**************************************************
		//【レポート設定】
		//**************************************************
		crp_practice4->ReportPath = "../practice4.crp";
		prtOpt << cpfDIALOG << cpfSTRETCH <<cpfPREVIEW_MAXIMIZED;

        //**************************************************
		//【印刷ジョブ開始】
		//**************************************************
		if (crp_practice4->OpenPrintJob(
				"",     //印刷ジョブ名
				prtOpt,	//オプション設定
				true,	//印刷プレビューの表示
				"",     //印刷プレビュー画面のタイトル
				NULL    //プレビューを表示するウインドウ
			)  == false)
		{
			// 印刷ジョブ開始失敗
			crp_practice4->ReportPath = "";
			ShowMessage("印刷ジョブの開始中に異常が発生しました。");
			return;
		}

        //**************************************************
		//【印刷データ設定】
		//**************************************************
		int record = 0;
		int page = 1;
		int pageAll = (this->grd_Address->RowCount / 15) + 1;

		// 住所リスト
		for (int i = 1; i < this->grd_Address->RowCount; i++)
		{
			//==================================================
			//【印刷データ抽出】
			//==================================================
			AnsiString id = this->grd_Address->Cells[0][i];
			AnsiString name = this->grd_Address->Cells[1][i];
			AnsiString address = this->grd_Address->Cells[2][i];
			AnsiString memo = this->grd_Address->Cells[3][i];
			AnsiString valid = this->grd_Address->Cells[4][i];

			//==================================================
			//【チェック】
			//==================================================
			if (valid != "○")
			{
				continue;
			}

			//==================================================
			//【改ページ処理】
			//==================================================
			if (record >= 15)
			{
				crp_practice4->ClearAllText();
				record = 0;
				page++;
			}

			record++;

            //==================================================
			//【印刷データ設定】
			//==================================================
			// ID
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Id")->Text = id;

			// 名前
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Name")->Text = name;

			// 住所
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Address")->Text = name;

			// メモ
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Memo")->Text = name;

			//==================================================
			//【印刷（プレビュー）】
			//==================================================
			if (record >= 15)
			{
				// ページ数
				crp_practice4->Item("", "lbl_Page")->Text = IntToStr(page) + "／" + IntToStr(pageAll);

				// 改ページ前
				crp_practice4->PrintReport();
			}
		}

		// 空行
		while (record < 15)
		{
			record++;

			//==================================================
			//【空行非表示】
			//==================================================
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Id")->Visible = false;
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Name")->Visible = false;
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Address")->Visible = false;
			crp_practice4->Item("Record" + IntToStr(record), "lbl_Memo")->Visible = false;
		}

		// ページ数
		crp_practice4->Item("", "lbl_Page")->Text = IntToStr(page) + "／" + IntToStr(pageAll);

        //**************************************************
		//【印刷（プレビュー）】
		//**************************************************
		crp_practice4->PrintReport();

        //**************************************************
		//【印刷ジョブ終了】
		//**************************************************
		crp_practice4->ClosePrintJob(true);

		//**************************************************
		//【レポートクローズ】
		//**************************************************
		crp_practice4->ReportPath = "";
    }
	catch (int e)
	{
		throw e;
	}
}
//---------------------------------------------------------------------------

