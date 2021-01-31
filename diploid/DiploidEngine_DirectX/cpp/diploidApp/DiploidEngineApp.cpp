#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate(DiploidEngineApp* app)
{

}

void DiploidEngineApp::Load(DiploidEngineApp* app)
{	
	logo_scene.Load();
	title_scene.Load();
	game_scene.Load();
	option_scene.Load();
}

void DiploidEngineApp::Init(DiploidEngineApp* app)
{	
	logo_scene.Init();
	title_scene.Init();
	game_scene.Init(app->diploidEngineSetting);
	option_scene.Init(app->diploidEngineSetting);
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
			option_scene.Updata(app->diploidEngineInput);

			//戻るボタンが押されていたらタイトルに戻る。
			if (option_scene.GetReturnFlag() == true)
			{
				title_scene.SetSecne(GAME_TITLE);
			}
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
	//ロゴシーンがまだ描画中なら
	if (logo_scene.GetFinalScene() == false)
	{
		logo_scene.Draw();
	}
	else//描画が完了していたら(タイトル画面の表示からの遷移)
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
			option_scene.Draw();
		}
	}
}

void DiploidEngineApp::Destory(DiploidEngineApp* app)
{

}

void DiploidEngineApp::End(DiploidEngineApp* app)
{

}