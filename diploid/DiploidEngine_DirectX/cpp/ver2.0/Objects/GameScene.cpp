#include "ver2.0/Objects/GameScene.h"

void GameScene::Load()
{
	jp.Load();

	string_back_wall.Load("texter/novel/basic/string_back_wall.png");
	data_back_wall.Load("texter/novel/basic/data_ui.png");
	data_test.Load("texter/novel/date/test.png");
	place_test.Load("texter/novel/place/test.png");

	novel_scene.Load("texter/novel/clock.png", "clock");
	novel_scene.Load("texter/novel/00.png", "1");
	novel_scene.Load("texter/novel/02.png", "2");

	end_anime.Load("texter/novel/icon/64_64/0.png");
	end_anime.Load("texter/novel/icon/64_64/1.png");
	end_anime.Load("texter/novel/icon/64_64/2.png");
	end_anime.Load("texter/novel/icon/64_64/3.png");


	auto_button.Load();
	skip_button.Load();
	option_button.Load();
	load_button.Load();
	save_button.Load();
	quick_load_button.Load();
	quick_save_button.Load();

}

void GameScene::Init(DiploidEngineSetting& setting)
{
	jp.Init(setting);
	jp.SetSpeed(5000);

	auto_button.Init(VGet(setting.window_x - 64, setting.window_y - 16, 0));
	auto_button.SetSpeed(60);
	skip_button.Init(VGet(setting.window_x - (64 * 2), setting.window_y - 16, 0));
	option_button.Init(VGet(setting.window_x - (64 * 3), setting.window_y - 16, 0));
	load_button.Init(VGet(setting.window_x - (64 * 4), setting.window_y - 16, 0));
	save_button.Init(VGet(setting.window_x - (64 * 5), setting.window_y - 16, 0));
	quick_load_button.Init(VGet(setting.window_x - (64 * 6), setting.window_y - 16, 0));
	quick_save_button.Init(VGet(setting.window_x - (64 * 7), setting.window_y - 16, 0));

	novel_scene.Init(VGet(0, 0, 0));

	string_back_wall.Init(VGet(0, 0, 0));
	data_back_wall.Init(VGet(0, 0, 0));
	data_test.Init(VGet(0, 0, 0));
	place_test.Init(VGet(0, 0, 0));

	box.Init(VGet(0, 0, 0), VGet(setting.window_x, setting.window_y, 0), GetColor(0, 0, 0));
	box.SetFill(true);


	end_anime.Init(VGet(setting.window_x * 0.8f, setting.window_y - 64, 0), 4, 0.5f, 0.5f);
}

void GameScene::Updata(DiploidEngineInput& input, DiploidEngineScreen& screen)
{	
	end_anime.SetAnimationSpeed(250 * screen.GetFrameTime());

	//オプション機能の更新
	option_button.Update(input);

	//ロード機能の更新
	load_button.Update(input);

	//セーブ機能の更新
	save_button.Update(input);

	//クイックロード機能の更新
	quick_load_button.Update(input);

	//クイックセーブ機能の更新
	quick_save_button.Update(input);

	//フェードアウト完了していたら
	if (box_draw_flag == 1)
	{
		//オート機能の更新
		auto_button.Update(input, jp.string[click].GetEnd(), screen.GetFrameTime());

		//スキップ機能の更新
		skip_button.Update(input, screen.GetFrameTime());


		//オート機能の進めflagがtrueだったら
		if (auto_button.GetNextFlag() == true)
		{
			if ((jp.string.size() - 1) != click)
			{
				jp.string[click].SetCompleteFlag(true);//既読済みflagを立てる
				click++;//次の文
			}
		}

		//既読済みflagだったら
		if (jp.string[click].GetCompleteFlag() == true)
		{
			//スキップ機能のflagが0だったら(選択状態なら)
			if (skip_button.GetNextFlag() == 0)
			{
				jp.string[click].AllIn();//最後の文字まで表示
				novel_scene.AlphaMax();//背景を完全表示			
			}
			else if (skip_button.GetNextFlag() == 1)//スキップ機能のflagが1だったら
			{
				if ((jp.string.size() - 1) != click)
				{
					jp.string[click].SetCompleteFlag(true);//既読済みflagを立てる
					click++;//次の文
				}
			}
		}

		//スキップボタンにカーソルがクリックされ、かつ選択状態なら
		if (skip_button.GetClick() == true)
		{
			if (skip_button.GetSelected() == 1)
			{
				auto_button.SetSelected(-1);//オートボタンの選択状態を解除
			}
		}

		//オートボタンにカーソルがクリックされ、かつ選択状態なら
		if (auto_button.GetClick() == true)
		{
			if (auto_button.GetSelected() == 1)
			{
				skip_button.SetSelected(-1);//スキップボタンの選択状態を解除
			}
		}

		//オプションボタンにカーソルが合わさっていてクリックされたなら
		if ((option_button.GetHit() == true) && (option_button.GetClick() == true))
		{
			option_button.SetSelected(1);//オプションボタンの選択状態を維持
			box_draw_flag = 2;//フェードアウトフラグを立てる
		}

		//ロードボタンにカーソルが合わさっていてクリックされたなら
		if ((load_button.GetHit() == true) && (load_button.GetClick() == true))
		{
			is_save_or_load = GAME_LOAD;//ロード画面へ行くフラグを立てる
			load_button.SetSelected(1);//オプションボタンの選択状態を維持
			box_draw_flag = 2;//フェードアウトフラグを立てる
		}

		//セーブボタンにカーソルが合わさっていてクリックされたなら
		if ((save_button.GetHit() == true) && (save_button.GetClick() == true))
		{
			is_save_or_load = GAME_SAVE;//セーブ画面へ行くフラグを立てる
			save_button.SetSelected(1);//オプションボタンの選択状態を維持
			box_draw_flag = 2;//フェードアウトフラグを立てる
		}



		//全てのUIからカーソルが離れているとき
		if ((auto_button.GetHit() == false) && (skip_button.GetHit() == false) && (option_button.GetHit() == false)
			&& (load_button.GetHit() == false) && (save_button.GetHit() == false) && (quick_load_button.GetHit() == false) && (quick_save_button.GetHit() == false))
		{
			//左クリックしたとき
			if (input.GetPressMouse(MOUSE_INPUT_LEFT) == true)
			{
				//スキップがオンならオフにする。
				if (skip_button.GetSelected() == 1)
				{
					skip_button.SetSelected(-1);
				}
				else//スキップがオフなら
				{
					if (jp.string[click].GetEnd() == 0)//最後まで表示されていなかったら
					{
						jp.string[click].AllIn();//最後の文字まで表示
						novel_scene.AlphaMax();//背景を完全表示
					}
					else
					{
						if ((jp.string.size() - 1) != click)
						{
							jp.string[click].SetCompleteFlag(true);//既読済みflagを立てる
							click++;//次の文を表示
						}
					}
				}
			}
		}
	}


	//場面の切り替え
	novel_scene.SetDrawName(jp.string[click].GetSceneName());

	novel_scene.Update(screen);//場面切り替えのアップデート

	//シーンが始まったら
	if (box_draw_flag == 0)//フェードアウト始め
	{
		alpha -= alpha_speed * screen.GetFrameTime();//透過値を変更

		if (alpha <= 0)//透過値フロー処理
		{
			alpha = 0;
			box_draw_flag = 1;//フェードアウト完了
		}
	}

	if (box_draw_flag == 2)//フェードイン始め
	{
		alpha += alpha_speed * screen.GetFrameTime();//透過値を変更

		if (alpha > 255)//透過値フロー処理
		{
			alpha = 255;
			box_draw_flag = 3;//フェードイン完了
		}
	}
}

void GameScene::Draw(DiploidEngineScreen& screen)
{
	//背景の描画
	novel_scene.Draw();

	//data_back_wall.Draw();
	//data_test.Draw();
	//place_test.Draw();

	//screen_graphics.Draw(0.1f);

	//文字表示の背景の描画
	string_back_wall.Draw();

	//フェードアウトが完了したら
	if (box_draw_flag == 1)
	{
		jp.string[click].Draw(screen.GetFrameTime());//文字の描画
	}

	//文が最後まで描画されていたら
	if (jp.string[click].GetEnd() == 1)
	{
		end_anime.StackDraw();//完了アイコンのアニメを描画
	}
	else
	{
		end_anime.Reset();//完了アイコンのアニメを最初からに設定
	}

	//オートボタンの描画
	auto_button.Draw(screen.GetFrameTime());

	//スキップボタンの描画
	skip_button.Draw(screen.GetFrameTime());

	//オプションボタンの描画
	option_button.Draw(screen.GetFrameTime());

	//ロードボタンの描画
	load_button.Draw(screen.GetFrameTime());

	//セーブボタンの描画
	save_button.Draw(screen.GetFrameTime());

	//クイックロードボタンの描画
	quick_load_button.Draw(screen.GetFrameTime());

	//クイックセーブボタンの描画
	quick_save_button.Draw(screen.GetFrameTime());


	//フェードアウト用BOX
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	box.Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void GameScene::Reset()
{
	//各ボタンのパラメーターと状態をリセットする
	auto_button.Reset();
	skip_button.Reset();
	option_button.Reset();
	load_button.Reset();
	save_button.Reset();
	quick_load_button.Reset();
	quick_save_button.Reset();

	//ロードかセーブかのフラグをリセット
	is_save_or_load = GAME_LOAD;


	//文字列データを最初からにする
	click = 0;
	jp.Reset();
}


void GameScene::SetInGameFlag(bool new_flag)
{
	in_game = new_flag;
}

bool GameScene::GetInGameFlag()
{
	return in_game;
}


void GameScene::SetOptionButtonFlag(int new_flag)
{
	option_button.SetSelected(new_flag);
}

bool GameScene::GetOptionButtonFlag()
{
	if ((option_button.GetSelected() == 1) && (box_draw_flag == 3))
	{
		box_draw_flag = 0;//フェードアウトのflagを立てる
		option_button.SetSelected(-1);//選択状態を解除
		return true;
	}
	else
	{
		return false;
	}
}


void GameScene::SetLoadButtonFlag(int new_flag)
{
	load_button.SetSelected(new_flag);
}

bool GameScene::GetLoadButtonFlag()
{
	if ((load_button.GetSelected() == 1) && (box_draw_flag == 3))
	{
		box_draw_flag = 0;//フェードアウトのflagを立てる
		load_button.SetSelected(-1);//選択状態を解除
		return true;
	}
	else
	{
		return false;
	}
}


void GameScene::SetSaveButtonFlag(int new_flag)
{
	save_button.SetSelected(new_flag);
}

bool GameScene::GetSaveButtonFlag()
{
	if ((save_button.GetSelected() == 1) && (box_draw_flag == 3))
	{
		box_draw_flag = 0;//フェードアウトのflagを立てる
		save_button.SetSelected(-1);//選択状態を解除
		return true;
	}
	else
	{
		return false;
	}
}


int GameScene::GetSelectedScene()
{
	return is_save_or_load;
}