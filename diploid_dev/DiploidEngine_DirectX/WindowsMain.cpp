#pragma once
//#define BOOST_PYTHON_STATIC_LIB
//#include <boost/python.hpp>
#include <memory>
#include "DxLib.h"
#include "system\DiploidEngineSetting.h"
#include "diploidApp\DiploidEngineApp.h"

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	// ウインドウモードで起動
//	ChangeWindowMode(TRUE);
//
//	// ＤＸライブラリの初期化
//	if (DxLib_Init() < 0) return -1;
//
//	int font = 0, err = 0, size = 0;
//	font = CreateFontToHandle(NULL, 20, 4, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
//	err = GetFontStateToHandle(NULL, &size, NULL, font);
//
//	DrawFormatString(0, 0, GetColor(255, 255, 255), "font:0x%x  err:%d  size:%d", font, err, size);
//
//	WaitKey();
//
//	// ＤＸライブラリの後始末
//	DxLib_End();
//
//	// ソフトの終了
//	return 0;
//}

//debug情報ありと書かれている物はリリースするときにfalseにすること。
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DiploidEngineApp *diploid_engine_app = new DiploidEngineApp();//ループなどの処理もろもろ

	//Py_Initialize();//Pythonの初期化

	//std::shared_ptr<DiploidEngineApp> diploid_engine_app;

	//DiploidEngineApp diploid_engine_app;
	diploid_engine_app->diploidDebug.Init();//デバッグ機能の初期化
	
	diploid_engine_app->diploidEngineSetting.Init();//エンジン初期化
	
	diploid_engine_app->FileCreate(diploid_engine_app);//ゲーム起動時にファイルを作成

	diploid_engine_app->OnceLoad(diploid_engine_app);//ゲーム起動時に音データを読み込む処理

	diploid_engine_app->OnceInit(diploid_engine_app);//エンジン初期化後一回だけ音の初期化する処理

	diploid_engine_app->Load(diploid_engine_app);//ゲーム起動時に画像データを読み込む処理

	diploid_engine_app->Init(diploid_engine_app);//エンジン初期化後一回だけ画像の初期化する処理

	diploid_engine_app->diploidEngineNetwork.Init();//ネット処理初期化

	diploid_engine_app->diploidEngineInput.Init();//入力機器初期化

	diploid_engine_app->WebConversion(diploid_engine_app);

	while ((ProcessMessage() == 0) && (diploid_engine_app->diploidEngineSetting.GetExit() == 0))
	{	
		diploid_engine_app->diploidEngineScreen.FrameCountEnd();//1フレームの時間を計算を終了

		diploid_engine_app->diploidEngineScreen.FrameCountStart();//1フレームの時間を計算を開始

		//解像度が変更変更されたときにデータを再び読み込む
		if (diploid_engine_app->diploidEngineSetting.GetReloadFlag() == true)
		{	
			InitFontToHandle();//すべてのフォントハンドルを削除

			diploid_engine_app->Load(diploid_engine_app);//ゲーム起動時にデータを読み込む処理

			diploid_engine_app->Init(diploid_engine_app);//画像の初期化する処理

			SetDrawScreen(DX_SCREEN_BACK);//裏画面処理をオン

			diploid_engine_app->diploidEngineSetting.SetReloadFlag(false);//flagをfalseに
		}

		diploid_engine_app->diploidEngineSetting.Updata();

		diploid_engine_app->diploidEngineScreen.Init(diploid_engine_app->diploidEngineSetting.GetSystemData().refreshrate);//FPS初期化

		diploid_engine_app->diploidEngineNetwork.Update();//ネット処理の更新

		diploid_engine_app->DestorySync();//デストロイ処理を同期(同期対象：Impact / Layer)
		diploid_engine_app->diploidEngineLayer.Destory();//destory変数がtrueのものを削除(Impact処理より前に記述)
		diploid_engine_app->diploidEngineImpact.Destory();//衝突しているものを削除

		diploid_engine_app->diploidEngineImpact.Init();//衝突処理の初期化

		ClearDrawScreen();//画面に描写されているものを削除

		diploid_engine_app->diploidEngineImpact.Updata();//衝突判定
		diploid_engine_app->diploidEngineLayer.Updata();//レイヤー画像をアップデート

		diploid_engine_app->Updata(diploid_engine_app);//メインループ

		diploid_engine_app->diploidEngineInput.Update();//入力機器アップデート

		diploid_engine_app->diploidEngineLayer.Draw(false);//レイヤー画像を表示(debug情報あり)
		diploid_engine_app->diploidEngineImpact.Draw(true);//衝突範囲を描写(debug情報あり)

		diploid_engine_app->Draw(diploid_engine_app);//メイン描写

		diploid_engine_app->Destory(diploid_engine_app);//ゲーム中の動的削除処理。

		diploid_engine_app->diploidEngineInput.Draw(1000, 0);//入力判定の表示(debug情報あり)

		diploid_engine_app->diploidEngineScreen.Update();//FPSをアップデート

		diploid_engine_app->diploidEngineScreen.Draw(800, 0, true);//FPSを表示(debug情報あり)

		diploid_engine_app->diploidDebug.Update(diploid_engine_app->diploidEngineSetting);//デバッグ機能の更新

		diploid_engine_app->diploidDebug.Draw();//デバッグ機能の描画

		ScreenFlip();//表画面へ描写

		//diploid_engine_app->diploidEngineScreen.FrameCountEnd();//1フレームの時間を計算を終了

		diploid_engine_app->diploidEngineScreen.Wait();//FPS待機
	}

	diploid_engine_app->End(diploid_engine_app);//エンジン終了前処理。
	diploid_engine_app->diploidEngineNetwork.End();//ネット処理の終了
	InitSoftImage();//メモリ上にあるソフトウェア画像をすべて削除
	InitGraph();//メモリ上にある画像データをすべて削除
	InitSoundMem();//メモリにあるサウンドをすべて削除
	InitKeyInput();//すべてのキー入力を削除
	InitFontToHandle();//すべてのフォントハンドルを削除
	diploid_engine_app->diploidEngineSetting.End();//エンジンの終了

	delete diploid_engine_app;

	//diploid_engine_app.reset();

	return 0;
}