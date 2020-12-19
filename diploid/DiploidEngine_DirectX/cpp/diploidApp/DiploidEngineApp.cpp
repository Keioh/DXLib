#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate(DiploidEngineApp* app)
{

}

void DiploidEngineApp::Load(DiploidEngineApp* app)
{	
	logo_scene.Load();
	title_scene.Load();
}

void DiploidEngineApp::Init(DiploidEngineApp* app)
{	
	logo_scene.Init();
	title_scene.Init();
}

void DiploidEngineApp::Updata(DiploidEngineApp* app)
{	
	if (logo_scene.GetFinalScene() == false)
	{
		logo_scene.Updata();
	}
	else
	{		
		title_scene.Updata();

		//スタートボタンを押したとき
		if (title_scene.GetFinalScene() == GAME_START)
		{

		}

		//ロードボタンを押したとき
		if (title_scene.GetFinalScene() == GAME_LOAD)
		{

		}

		//オプションボタンを押したとき
		if (title_scene.GetFinalScene() == GAME_OPTION)
		{

		}

		//終了ボタンを押したとき
		if (title_scene.GetFinalScene() == GAME_EXIT)
		{
			app->diploidEngineSetting.SetExit(1);
		}

		//何も押していない時
		if (title_scene.GetFinalScene() == GAME_NONE)
		{

		}
	}
}

void DiploidEngineApp::Draw(DiploidEngineApp* app)
{
	if (logo_scene.GetFinalScene() == false)
	{
		logo_scene.Draw();
	}
	else
	{
		title_scene.Draw();
	}

	//scr_gra.Draw(0.3f);
}

void DiploidEngineApp::Destory(DiploidEngineApp* app)
{

}

void DiploidEngineApp::End(DiploidEngineApp* app)
{

}