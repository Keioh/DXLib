//include
#include "DxLib.h"
#include "System.h"

System::System()
{
	size.x = 1280;
	size.y = 720;
	size.bit = 32;
	fullscreen = -1;
}

//DXLIB初期化
void System::Dx_Init(bool w_mode, int r, int g, int b, char* name)
{
	//DXLIBより前に初期化する関数
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(w_mode);
	SetGraphMode(size.x, size.y, size.bit);
	SetMainWindowText(name);
	SetWindowSizeChangeEnableFlag(true);

	//DXLIBの初期化
	DxLib_Init();

	//DXLIBの後に初期化する関数	
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	SetUseDXArchiveFlag(TRUE);//アーカイブ読み込み可能に変更
	SetDXArchiveExtension("kou");//拡張子変更
	SetDXArchiveKeyString("999");//アーカイブパスワードを指定
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);//フォントタイプの変更
	SetFontThickness(6);//フォントの太さを変更
	SetCameraPositionAndTarget_UpVecY(VGet(0.0f, 0.0f, 0.0f), VGet(0.0f, 1.0f, 0.0f));
	SetMouseDispFlag(TRUE);
	SetUseASyncLoadFlag(TRUE);
	SetAlwaysRunFlag(TRUE);
	SetBackgroundColor(r, g, b);
}

//DXLIB終了処理
void System::Dx_End()
{
	DxLib_End();
}