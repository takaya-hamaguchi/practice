object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #35506#38988#65300
  ClientHeight = 412
  ClientWidth = 584
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object shp_Title: TShape
    Left = 0
    Top = 0
    Width = 584
    Height = 30
    Pen.Color = clGray
  end
  object lbl_Title: TLabel
    Left = 0
    Top = 0
    Width = 584
    Height = 29
    Alignment = taCenter
    AutoSize = False
    Caption = #35506#38988#65300
    Color = clFuchsia
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindow
    Font.Height = -16
    Font.Name = #65325#65331' '#26126#26397
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    Transparent = False
    Layout = tlCenter
  end
  object Shape2: TShape
    Left = -1
    Top = 368
    Width = 586
    Height = 46
    Pen.Color = clGray
  end
  object grd_Address: TDBGrid
    Left = 20
    Top = 50
    Width = 545
    Height = 300
    Options = [dgEditing, dgTitles, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgTitleHotTrack]
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'id'
        Title.Alignment = taCenter
        Title.Caption = 'ID'
        Width = 50
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'name'
        Title.Alignment = taCenter
        Title.Caption = #21517#21069
        Width = 120
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'address'
        Title.Alignment = taCenter
        Title.Caption = #20303#25152
        Width = 165
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'memo'
        Title.Alignment = taCenter
        Title.Caption = #12513#12514
        Width = 162
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'valid'
        Title.Alignment = taCenter
        Title.Caption = #26377#21177
        Width = 40
        Visible = True
      end>
  end
  object btn_Preview: TButton
    Left = 445
    Top = 375
    Width = 120
    Height = 30
    Caption = #12503#12524#12499#12517#12540
    TabOrder = 1
    OnClick = btn_PreviewClick
  end
  object btn_End: TButton
    Left = 20
    Top = 375
    Width = 120
    Height = 30
    Caption = #32066#20102
    TabOrder = 2
    OnClick = btn_EndClick
  end
  object btn_CsvOutput: TButton
    Left = 300
    Top = 375
    Width = 120
    Height = 30
    Caption = 'CSV'#20986#21147
    TabOrder = 3
    OnClick = btn_CsvOutputClick
  end
end
