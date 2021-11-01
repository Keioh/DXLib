#include "system\DiploidEngineSetting.h"

DiploidEngineSetting::DiploidEngineSetting()
{
	//システムセーブファイルを開く
	file.ReadOpen("data/system_config.txt");
	
	while ((ProcessMessage() == 0) && (file.GetFileInAdr()))
	{
		string_data.push_back(file.GetLine());
	}

	file.Close();

	//言語の設定
	system_data.language = translate.FindDataString(string_data, "language");

	//window関連
	system_data.window_x = translate.FindDataInt(string_data, "window_x");
	system_data.window_y = translate.FindDataInt(string_data, "window_y");
	system_data.refreshrate = translate.FindDataInt(string_data, "refreshrate");
	system_data.window_mode = translate.FindDataBool(string_data, "window_mode");
	system_data.vsync = translate.FindDataBool(string_data, "vsync");
	system_data.simulation_window_x = translate.FindDataInt(string_data, "simulation_window_x");
	system_data.simulation_window_y = translate.FindDataInt(string_data, "simulation_window_y");

	//シャドウマップ関連
	system_data.shadow_map = translate.FindDataBool(string_data, "shadow_map");
	system_data.shadow_map_size_x = translate.FindDataInt(string_data, "shadow_map_size_x");
	system_data.shadow_map_size_y = translate.FindDataInt(string_data, "shadow_map_size_y");
	system_data.shadow_map_min_area_x = translate.FindDataFloat(string_data, "shadow_map_min_area_x");
	system_data.shadow_map_min_area_y = translate.FindDataFloat(string_data, "shadow_map_min_area_y");
	system_data.shadow_map_min_area_z = translate.FindDataFloat(string_data, "shadow_map_min_area_z");
	system_data.shadow_map_max_area_x = translate.FindDataFloat(string_data, "shadow_map_max_area_x");
	system_data.shadow_map_max_area_y = translate.FindDataFloat(string_data, "shadow_map_max_area_y");
	system_data.shadow_map_max_area_z = translate.FindDataFloat(string_data, "shadow_map_max_area_z");

	//game設定関連
	system_data.string_draw_speed = translate.FindDataInt(string_data, "string_draw_speed");
	system_data.string_auto_speed = translate.FindDataInt(string_data, "string_auto_speed");
	system_data.string_background_alpha = translate.FindDataInt(string_data, "string_background_alpha");

	//window_x = 1280;
	//window_y = 720;
	window_bit = 32;
	//refresh_rate = 60;
	//window_mode = TRUE;
	window_name = "NovelGame(DiploidEngine2 NovelSystemVersion 0.7.61)";

	//シミュレーションスクリーン関連(標準設定は元の画面サイズ÷2)
	screen_handle = -1;
	//sim_window_x = window_x / 2;
	//sim_window_y = window_y / 2;	

	GetScreenState(&buffer_window_x, &buffer_window_y, &buffer_window_bit);
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
	SetWaitVSyncFlag(system_data.vsync);//垂直同期信号を待つかのflag

	if (system_data.language == "japanese")
	{
		SetUseCharCodeFormat(DX_CHARCODEFORMAT_SHIFTJIS);//文字コード変更
	}

	if (system_data.language == "english")
	{
		SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);//文字コード変更
	}

	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);//フォントの描画の仕方
	SetFontThickness(1);//フォントの太さを設定
	ChangeFont("メイリオ");//フォントの種類の設定
	SetFontSize(15);//フォントの大きさを設定
	SetBackgroundColor(255, 255, 255);
	SetOutApplicationLogValidFlag(FALSE);//ログ出力関連
	SetGraphMode(system_data.window_x, system_data.window_y, window_bit, system_data.refreshrate);//解像度変更
	ChangeWindowMode(system_data.window_mode);//ウィンドウモード変更
	SetMainWindowText(window_name);//アプリケーションの名前を変更

	SetUseASyncLoadFlag(TRUE);//非同期読み込み
	SetUseDXArchiveFlag(TRUE);//DXアーカイブ読み込み
	SetAlwaysRunFlag(TRUE);//ウィンドウ非アクティブで処理を実行

	SetFullScreenScalingMode(DX_FSSCALINGMODE_BILINEAR);//画面補間の変更 DX_FSSCALINGMODE_NEAREST DX_FSSCALINGMODE_BILINEAR
	SetDrawMode(DX_DRAWMODE_BILINEAR);//画像拡大時の補間変更 DX_DRAWMODE_BILINEAR DX_DRAWMODE_NEAREST
	SetFullSceneAntiAliasingMode(4, 2);//フルスクリーンAA設定
	SetCreateDrawValidGraphMultiSample(4, 2);//AA設定

	SetEnableXAudioFlag(TRUE);//XAudioフラグ

	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);

	GetScreenState(&buffer_window_x, &buffer_window_y, &buffer_window_bit);
}

void DiploidEngineSetting::SetEnd()
{
	//screen_handle = MakeScreen(window_x, window_y, FALSE);
	//SetDrawScreen(screen_handle);//裏画面処理をオン

	SetDrawScreen(DX_SCREEN_BACK);//裏画面処理をオン
	SetMouseDispFlag(TRUE);//マウスカーソルの表示

	//3D関連
	SetCameraNearFar(100.0f, 10000.0f);
	SetupCamera_Perspective(1.054f);
	ChangeLightTypePoint(VGet(1100.851f, 300.4314f, 1500.125f), 2000.0f, 0.0f, 0.0005f, 0.0f);
}

void DiploidEngineSetting::End()
{
	DxLib_End();
}


void DiploidEngineSetting::Updata()
{
	GetScreenState(&buffer_window_x, &buffer_window_y, &buffer_window_bit);

	if ((buffer_window_x != system_data.window_x) || (buffer_window_y != system_data.window_y))
	{
		SetGraphMode(system_data.window_x, system_data.window_y, window_bit, system_data.refreshrate);//解像度変更

		//3D関係の設定
		SetCameraNearFar(100.0f, 10000.0f);
		SetupCamera_Perspective(1.054f);
		ChangeLightTypePoint(VGet(1100.851f, 300.4314f, 1500.125f), 2000.0f, 0.0f, 0.0005f, 0.0f);

		reload = true;
	}
}


void DiploidEngineSetting::SetExit(int flag)
{
	exit = flag;
}

void DiploidEngineSetting::SetWindowSize(int new_window_x, int new_window_y)
{
	system_data.window_x = new_window_x;
	system_data.window_y = new_window_y;

	//GetScreenState(&buffer_window_x, &buffer_window_y, &buffer_window_bit);
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

SystemData DiploidEngineSetting::GetSystemData()
{
	return system_data;
}