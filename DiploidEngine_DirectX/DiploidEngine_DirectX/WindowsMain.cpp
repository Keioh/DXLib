#pragma once
#include "DxLib.h"
#include "system\DiploidEngineSetting.h"
#include "diploidApp\DiploidEngineApp.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DiploidEngineApp diploid_engine_app;//ループなどの処理もろもろ

	diploid_engine_app.diploidEngineSetting.Init();

	diploid_engine_app.Init();

	while (ProcessMessage() == 0)
	{
		diploid_engine_app.diploidEngineImpact.Init();
		ClearDrawScreen();

		//diploid_engine_app.diploidEngineImpact.
		diploid_engine_app.Update();
		//diploid_engine_app.diploidEngineImpact.Updata();

		diploid_engine_app.Draw();
		ScreenFlip();//表画面へ描写
	}

	diploid_engine_app.diploidEngineSetting.End();

	return 0;
}