#include "system\DiploidEngineSetting.h"

DiploidEngineSetting::DiploidEngineSetting()
{
	//window関連
	window_x = 1280;
	window_y = 720;
	window_bit = 32;
	refresh_rate = 60;
	window_mode = TRUE;
	window_name = "DiploidEngine";//Diploid Engine ver0.05
}

void DiploidEngineSetting::Init()
{
	DiploidEngineSetting::SetBegin();//DXLIB初期化より前に設定する処理。

	if (DxLib_Init() == -1)
	{
		DxLib_End();
	}

	DiploidEngineSetting::SetEnd();//DXLIB初期化より後に設定する処理。
}

void DiploidEngineSetting::SetBegin()
{
	SetUseCharCodeFormat(DX_CHARCODEFORMAT_SHIFTJIS);
	//SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);//文字コード変更	
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);//フォントの描画の仕方
	SetFontThickness(1);//フォントの太さを設定
	ChangeFont("メイリオ");//フォントの種類の設定
	SetFontSize(15);//フォントの大きさを設定
	SetBackgroundColor(0, 0, 0);
	SetOutApplicationLogValidFlag(FALSE);//ログ出力関連
	SetGraphMode(window_x, window_y, window_bit, refresh_rate);//解像度変更
	ChangeWindowMode(window_mode);//ウィンドウモード変更
	SetMainWindowText(window_name);//アプリケーションの名前を変更

	SetUseASyncLoadFlag(TRUE);//非同期読み込み
	SetUseDXArchiveFlag(TRUE);//DXアーカイブ読み込み
	SetAlwaysRunFlag(TRUE);//ウィンドウ非アクティブで処理を実行

	SetFullScreenScalingMode(DX_FSSCALINGMODE_NEAREST);//画面補間の変更
	SetDrawMode(DX_DRAWMODE_NEAREST);//画像拡大時の補間変更
	SetFullSceneAntiAliasingMode(4, 2);//AA設定

	SetEnableXAudioFlag(TRUE);//XAudioフラグ

	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);

}

void DiploidEngineSetting::SetEnd()
{
	//screen_handle = MakeScreen(window_x, window_y, FALSE);
	//SetDrawScreen(screen_handle);//裏画面処理をオン

	SetDrawScreen(DX_SCREEN_BACK);//裏画面処理をオン
	SetCameraNearFar(0.1f, 10000.0f);

}

void DiploidEngineSetting::End()
{
	DxLib_End();
}