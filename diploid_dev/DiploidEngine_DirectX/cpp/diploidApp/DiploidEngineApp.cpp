#include "diploidApp\DiploidEngineApp.h"


void DiploidEngineApp::FileCreate(DiploidEngineApp* app)
{

}

void DiploidEngineApp::OnceLoad(DiploidEngineApp* app)
{	
	game_scene.OnceLoad();
}

void DiploidEngineApp::Load(DiploidEngineApp* app)
{		
	logo_scene.Load();
	title_scene.Load();
	game_scene.Load();
	option_scene.Load();
	file_scene.Load();
}

void DiploidEngineApp::OnceInit(DiploidEngineApp* app)
{		
	ui.Init(VGet(0, 20, 0), VGet(100, 20, 0));
	uiGroup.Push(ui, "test1");

	ui.Init(VGet(0, 40, 0), VGet(100, 20, 0));
	uiGroup.Push(ui, "test2");

	ui.Init(VGet(0, 60, 0), VGet(100, 20, 0));
	uiGroup.Push(ui, "test3");


	ui.Init(VGet(100, 100, 0), VGet(100, 100, 0));

}

void DiploidEngineApp::Init(DiploidEngineApp* app)
{	
	logo_scene.Init();
	title_scene.Init(app->diploidEngineSetting);
	game_scene.Init(app->diploidEngineSetting);
	option_scene.Init(app->diploidEngineSetting);
	file_scene.Init(app->diploidEngineSetting);

	r_box.Init(VGet(100, 100, 0), VGet(100, 100, 0), GetColor(200, 200, 200));
}

void DiploidEngineApp::Updata(DiploidEngineApp* app)
{
	ui.Updata();

	if (ui.GetSelectedUI() == 1)
	{
		r_box.SetColor(GetColor(240, 240, 240));

		if (r < 30)
		{
			r += 1.5f;
		}
	}
	else
	{
		r_box.SetColor(GetColor(220, 220, 220));

		if (r > 20)
		{
			r -= 1.5f;
		}
	}

	if (ui.GetSelectedUI() != 1)
	{
		if (ui.GetHit() == true)
		{
			r_box.SetColor(GetColor(220, 220, 220));

			if (r < 20)
			{
				r += 1.5f;
			}
		}
		else
		{
			r_box.SetColor(GetColor(180, 180, 180));

			if (r > 5)
			{
				r -= 1.5f;
			}
		}
	}

	//r_box.SetSize(VGet(x, y, 0));
	r_box.SetRoundness(r);
	ui.SetSize(r_box.GetSize().x, r_box.GetSize().y);

	//x++;
	//y++;

	//if (time > 10)
	//{
	//	app->diploidDebug.log.Push(std::to_string(app->diploidDebug.GetInGameTime()) + "ms:テスト" + std::to_string(count));

	//	count++;

	//	time = 0;
	//}

	//time++;

	uiGroup.Update();

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
			game_scene.Updata(app->diploidEngineInput, app->diploidEngineScreen, app->diploidDebug);//ゲーム画面を更新

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

	uiGroup.Draw();
	r_box.Draw();
	ui.Draw(true);

	DrawFormatString(0, 0, GetColor(100, 100, 100), "In Game Time : %d", app->diploidDebug.GetInGameTime() / 1000);

	DrawFormatString(0, 20, GetColor(100, 100, 100), "UI1 : %d", uiGroup.VectorPointer().at(0).GetSelectedUI());
	DrawFormatString(0, 40, GetColor(100, 100, 100), "UI2 : %d", uiGroup.VectorPointer().at(1).GetSelectedUI());
	DrawFormatString(0, 60, GetColor(100, 100, 100), "UI3 : %d", uiGroup.VectorPointer().at(2).GetSelectedUI());

}

void DiploidEngineApp::CreateShadowModel(DiploidEngineApp* app)
{

}

void DiploidEngineApp::CreateShadowPassiveModel(DiploidEngineApp* app)
{

}

void DiploidEngineApp::WebConversion(DiploidEngineApp* app)
{
	box.Init(VGet(50, 25, 0), VGet(100, 50, 0), GetColor(255, 255, 255));
	box.SetName("TestBox");

	conv.toWebCode(box, 100, 100, 100);

	box.Init(VGet(60, 18, 0), VGet(80, 30, 0), GetColor(255, 255, 255));
	box.SetName("TestBox2");

	conv.toWebCode(box, 100, 100, 100);

}

void DiploidEngineApp::Destory(DiploidEngineApp* app)
{

}

void DiploidEngineApp::End(DiploidEngineApp* app)
{

}