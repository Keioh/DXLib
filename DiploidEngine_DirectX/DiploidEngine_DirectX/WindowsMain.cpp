#pragma once
#include "DxLib.h"
#include "system\DiploidEngineSetting.h"
#include "diploidApp\DiploidEngineApp.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//DiploidEngineSetting diploid_engine_setting;//エンジンの初期化もろもろ
	DiploidEngineApp diploid_engine_app;//ループなどの処理もろもろ

	diploid_engine_app.diploidEngineSetting.Init();

	diploid_engine_app.Init();

	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();
		diploid_engine_app.Update();

		diploid_engine_app.Draw();
		ScreenFlip();//表画面へ描写
	}

	diploid_engine_app.diploidEngineSetting.End();

	return 0;
}