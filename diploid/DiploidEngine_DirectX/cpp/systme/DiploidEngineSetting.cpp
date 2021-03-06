#include "system\DiploidEngineSetting.h"

DiploidEngineSetting::DiploidEngineSetting()
{	
	GetScreenState(&buffer_window_x, &buffer_window_y, &buffer_window_bit);

	//システムセーブファイルを開く
	file.ReadOpen("data/system_config.txt");
	
	while (file.GetFileInAdr())
	{
		string_data.push_back(file.GetLine());
	}

	file.Close();


	//window関連
	window_x = translate.FindDataInt(string_data, "window_x");	
	window_y = translate.FindDataInt(string_data, "window_y");	
	refresh_rate = translate.FindDataInt(string_data, "refresh_rate");
	window_mode = translate.FindDataBool(string_data, "window_mode");
	vsync = translate.FindDataBool(string_data, "vsync");
	sim_window_x = translate.FindDataInt(string_data, "simulation_window_x");
	sim_window_y = translate.FindDataInt(string_data, "simulation_window_y");

	//window_x = 1280;
	//window_y = 720;
	window_bit = 32;
	//refresh_rate = 60;
	//window_mode = TRUE;
	window_name = "NovelGame(DiploidEngine2 NovelSystemVersion 0.7.41)";

	//シミュレーションスクリーン関連(標準設定は元の画面サイズ÷2)
	screen_handle = -1;
	//sim_window_x = window_x / 2;
	//sim_window_y = window_y / 2;
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
	SetWaitVSyncFlag(vsync);//垂直同期信号を待つかのflag
	SetUseCharCodeFormat(DX_CHARCODEFORMAT_SHIFTJIS);
	//SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);//文字コード変更	
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);//フォントの描画の仕方
	SetFontThickness(1);//フォントの太さを設定
	ChangeFont("メイリオ");//フォントの種類の設定
	SetFontSize(15);//フォントの大きさを設定
	SetBackgroundColor(255, 255, 255);
	SetOutApplicationLogValidFlag(FALSE);//ログ出力関連
	SetGraphMode(window_x, window_y, window_bit, refresh_rate);//解像度変更
	ChangeWindowMode(window_mode);//ウィンドウモード変更
	SetMainWindowText(window_name);//アプリケーションの名前を変更

	SetUseASyncLoadFlag(TRUE);//非同期読み込み
	SetUseDXArchiveFlag(TRUE);//DXアーカイブ読み込み
	SetAlwaysRunFlag(TRUE);//ウィンドウ非アクティブで処理を実行

	SetFullScreenScalingMode(DX_FSSCALINGMODE_NEAREST);//画面補間の変更 DX_FSSCALINGMODE_NEAREST DX_FSSCALINGMODE_BILINEAR
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
	SetMouseDispFlag(TRUE);//マウスカーソルの表示
}

void DiploidEngineSetting::End()
{
	DxLib_End();
}


void DiploidEngineSetting::Updata()
{
	GetScreenState(&buffer_window_x, &buffer_window_y, &buffer_window_bit);

	if ((buffer_window_x != window_x) || (buffer_window_y != window_y))
	{
		SetGraphMode(window_x, window_y, window_bit, refresh_rate);//解像度変更

		reload = true;
	}
}


void DiploidEngineSetting::SetExit(int flag)
{
	exit = flag;
}

void DiploidEngineSetting::SetWindowSize(int new_window_x, int new_window_y)
{
	window_x = new_window_x;
	window_y = new_window_y;
}


int DiploidEngineSetting::GetExit()
{
	return exit;
}


bool DiploidEngineSetting::GetReloadFlag()
{
	return reload;
}

void DiploidEngineSetting::SetReloadFlag(bool new_flag)
{
	reload = new_flag;
}