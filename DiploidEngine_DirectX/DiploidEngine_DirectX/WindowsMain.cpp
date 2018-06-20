#pragma once
#include "DxLib.h"
#include "system\DiploidEngineSetting.h"
#include "diploidApp\DiploidEngineApp.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DiploidEngineApp diploid_engine_app;//ループなどの処理もろもろ

	diploid_engine_app.diploidEngineSetting.Init();//エンジン初期化

	diploid_engine_app.Load();//ゲーム起動時にデータを読み込む処理

	diploid_engine_app.Init();//エンジン初期化後一回だけ初期化する処理

	diploid_engine_app.diploidEngineNetwork.Init();//ネット処理初期化

	while (ProcessMessage() == 0)
	{
		diploid_engine_app.diploidEngineNetwork.Update();//ネット処理の更新
		diploid_engine_app.diploidEngineImpact.Init();//衝突処理の初期化

		ClearDrawScreen();//画面に描写されているものを削除

		//diploid_engine_app.diploidEngineImpact.
		//diploid_engine_app.diploidEngineLayer.Updata();

		diploid_engine_app.Updata();//メインループ

		//diploid_engine_app.diploidEngineImpact.Updata();
		//diploid_engine_app.diploidEngineLayer.Draw();

		diploid_engine_app.Draw();//メイン描写

		ScreenFlip();//表画面へ描写
	}

	diploid_engine_app.diploidEngineSound.End();//メモリにあるサウンドをすべて削除
	diploid_engine_app.diploidEngineNetwork.End();//ネット処理の終了
	InitGraph();//メモリ上にある画像データをすべて削除
	diploid_engine_app.diploidEngineSetting.End();//エンジンの終了

	return 0;
}