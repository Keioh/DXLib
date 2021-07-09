#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate(DiploidEngineApp* app)
{

}

void DiploidEngineApp::OnceLoad(DiploidEngineApp* app)
{	

}

void DiploidEngineApp::Load(DiploidEngineApp* app)
{		
	test.CreateFontData(22, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	test.Create("なぜ自分はここにいるのか、どうやって来たのか、定かではない。ただ一つ、確かなことは目の前にいる少女の言葉に耳を傾ける事だけだった。");

	logo_scene.Load();
	title_scene.Load();
	game_scene.Load();
	option_scene.Load();
	file_scene.Load();
}

void DiploidEngineApp::OnceInit(DiploidEngineApp* app)
{		
}

void DiploidEngineApp::Init(DiploidEngineApp* app)
{	
	test.Init(100, 100);

	logo_scene.Init();
	title_scene.Init(app->diploidEngineSetting);
	game_scene.Init(app->diploidEngineSetting);
	option_scene.Init(app->diploidEngineSetting);
	file_scene.Init(app->diploidEngineSetting);
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
			game_scene.SetSystemData(option_scene.GetSystemData());//optionからのシステム設定を取得
			game_scene.SetInGameFlag(true);//ゲーム中フラグをtrueにする
			game_scene.Updata(app->diploidEngineInput, app->diploidEngineScreen);//ゲーム画面を更新

			//オプションボタンが押されていたら
			if (game_scene.GetOptionButtonFlag() == true)
			{
				title_scene.SetSecne(GAME_OPTION);//シーン変更
			}

			//ロードボタンが押されていたら
			if (game_scene.GetLoadButtonFlag() == true)
			{
				title_scene.SetSecne(GAME_FILE);//シーン変更
			}

			//セーブボタンが押されていたら
			if (game_scene.GetSaveButtonFlag() == true)
			{
				title_scene.SetSecne(GAME_FILE);//シーン変更
			}
		}

		//ロードボタンを押したとき
		if (title_scene.GetFinalScene() == GAME_FILE)
		{
			file_scene.Updata(app->diploidEngineInput, app->diploidEngineSetting, app->diploidEngineScreen, game_scene.GetInGameFlag(), game_scene.GetSelectedScene());

			//戻るボタンを押していたら
			switch (file_scene.GetReturnButton())
			{
			//タイトルに戻る。
			case GAME_TITLE:
				title_scene.SetSecne(GAME_TITLE);//シーン変更
				break;
			//ゲームに戻る。
			case GAME_START:
				title_scene.SetSecne(GAME_START);//シーン変更
				break;
			default:break;
			}
		}

		//オプションボタンを押したとき
		if (title_scene.GetFinalScene() == GAME_OPTION)
		{
			option_scene.Updata(app->diploidEngineInput, app->diploidEngineSetting, app->diploidEngineScreen, game_scene.GetInGameFlag());//オプション画面を更新(最後の引数にはgame_sceneのInGameflagを入れる。)		

			//戻るボタンを押していたら
			switch (option_scene.GetReturnFlag())
			{
			//タイトルに戻る。
			case GAME_TITLE:game_scene.SetOptionButtonFlag(-1);//game_sceneのオプションボタンの選択フラグを-1に変更(ボタンを初期化)	
							game_scene.SetInGameFlag(false);//ゲーム中フラグをfalseにする
							game_scene.Reset();//ゲームをリセットする。
							title_scene.SetSecne(GAME_TITLE);//シーン変更
							break;
			//ゲームに戻る。
			case GAME_START:game_scene.SetOptionButtonFlag(-1);//game_sceneのオプションボタンの選択フラグを-1に変更(ボタンを初期化)	
							game_scene.SetInGameFlag(true);//ゲーム中フラグをtrueにする
							title_scene.SetSecne(GAME_START);//シーン変更
							break;
			default:break;
			}
		}

		//終了ボタンを押したとき
		if (title_scene.GetFinalScene() == GAME_EXIT)
		{
			app->diploidEngineSetting.SetExit(1);//終了する。
		}

		//何も押していない時
		if (title_scene.GetFinalScene() == GAME_TITLE)
		{
			title_scene.Updata(app->diploidEngineScreen);//タイトル画面を更新
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
			title_scene.Draw(app->diploidEngineScreen);
		}

		//スタートボタンを押したとき
		if (title_scene.GetFinalScene() == GAME_START)
		{
			game_scene.Draw(app->diploidEngineScreen);
		}

		//ロードボタンを押したとき
		if (title_scene.GetFinalScene() == GAME_FILE)
		{
			file_scene.Draw(app->diploidEngineScreen);
		}

		//オプションボタンを押したとき
		if (title_scene.GetFinalScene() == GAME_OPTION)
		{
			option_scene.Draw(app->diploidEngineScreen);
		}
	}

	test.Draw();
	//DrawFormatString(100, 100, GetColor(150, 150, 150), "frame = %f", app->diploidEngineScreen.GetFrameTime());
	//DrawFormatString(0, 200, GetColor(100, 100, 100), "scene = %d", title_scene.GetFinalScene());
	//DrawFormatString(0, 220, GetColor(100, 100, 100), "%d", game_scene.GetOptionButtonFlag());
}

void DiploidEngineApp::CreateShadowModel(DiploidEngineApp* app)
{

}

void DiploidEngineApp::CreateShadowPassiveModel(DiploidEngineApp* app)
{

}

void DiploidEngineApp::Destory(DiploidEngineApp* app)
{

}

void DiploidEngineApp::End(DiploidEngineApp* app)
{

}