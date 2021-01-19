#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate(DiploidEngineApp* app)
{

}

void DiploidEngineApp::Load(DiploidEngineApp* app)
{	
	logo_scene.Load();
	title_scene.Load();
	game_scene.Load();
}

void DiploidEngineApp::Init(DiploidEngineApp* app)
{	
	logo_scene.Init();
	title_scene.Init();
	game_scene.Init(app->diploidEngineSetting);
}

void DiploidEngineApp::Updata(DiploidEngineApp* app)
{	
	if (logo_scene.GetFinalScene() == false)
	{
		logo_scene.Updata(app->diploidEngineScreen);
	}
	else
	{		
		//スタートボタンを押したとき
		if (title_scene.GetFinalScene() == GAME_START)
		{
			game_scene.Updata(app->diploidEngineInput);
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
		if (title_scene.GetFinalScene() == GAME_TITLE)
		{
			title_scene.Updata();
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
		//何も押していない時
		if (title_scene.GetFinalScene() == GAME_TITLE)
		{
			title_scene.Draw();
		}

		//スタートボタンを押したとき
		if (title_scene.GetFinalScene() == GAME_START)
		{
			game_scene.Draw();
		}

		//ロードボタンを押したとき
		if (title_scene.GetFinalScene() == GAME_LOAD)
		{

		}

		//オプションボタンを押したとき
		if (title_scene.GetFinalScene() == GAME_OPTION)
		{

		}
	}
}

void DiploidEngineApp::Destory(DiploidEngineApp* app)
{

}

void DiploidEngineApp::End(DiploidEngineApp* app)
{

}