#include "ver2.0/Objects/FileScene.h"

void FileScene::Load()
{
	load_string_image.Load();//ロード画面のタイトル画像
	save_string_image.Load();//セーブ画面のタイトル画像

	back_button.Load();

	save_load_object_image.Load("texter/basic/file/0.png");
	save_load_object_button.Load(save_load_object_image.GetGraphicsHandl());
}

void FileScene::Init(DiploidEngineSetting& setting)
{
	//フェード用BOX
	box.Init(VGet(0, 0, 0), VGet(setting.window_x, setting.window_y, 0), GetColor(0, 0, 0));
	box.SetFill(true);

	load_string_image.Init(VGet(0, 0, 0));//ロード画面のタイトル画像
	save_string_image.Init(VGet(0, 0, 0));//セーブ画面のタイトル画像


	//戻るボタン
	back_button.Init(VGet(setting.window_x - (128 + 4), setting.window_y - (32 + 4), 0));

	//セーブとロードのボタン
	save_load_object_image.Init(VGet(300, 100, 0));
	save_load_object_button.Init(VGet(300, 100, 0), save_load_object_image.GetSize());
}

void FileScene::Updata(DiploidEngineInput& input, DiploidEngineSetting& setting, DiploidEngineScreen& screen, bool in_game_flag, int save_or_load_flag)
{
	SetBackgroundColor(255, 255, 255);

	in_game_flag_buffer = in_game_flag;//ゲーム中かのフラグを更新
	save_or_load_flag_buffer = save_or_load_flag;//ロード画面へ行くのかセーブ画面へ行くのかのフラグを更新


	save_load_object_button.Updata();//セーブとロードのボタン

	//戻るボタン
	back_button.Update(input);

	//ロード画面のフラグが立っていたら。
	if (save_or_load_flag_buffer == GAME_LOAD)
	{
		//ロード画面のタイトル画像
		load_string_image.Updata();
	}

	//セーブ画面のフラグが立っていたら。
	if (save_or_load_flag_buffer == GAME_SAVE)
	{
		//セーブ画面のタイトル画像
		save_string_image.Updata();
	}

	//フェードアウト完了していたら
	if (box_draw_flag == 1)
	{
		//戻るボタンをクリックしたら
		if (back_button.GetClick() == true)
		{
			back_button.SetSelectedFlag(1);
			box_draw_flag = 2;
		}
	}

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


	if (mosaic >= mosaic_max)//モザイク値フロー処理
	{
		mosaic = mosaic_max;
	}
	else
	{
		mosaic += mosaic_speed;//モザイク値を変更
	}
}

void FileScene::Draw(DiploidEngineScreen& screen, bool draw, bool debug)
{
	//ロード画面のフラグが立っていたら。
	if (save_or_load_flag_buffer == GAME_LOAD)
	{
		load_string_image.Draw();//ロード画面のタイトル画像
	}

	//セーブ画面のフラグが立っていたら。
	if (save_or_load_flag_buffer == GAME_SAVE)
	{
		save_string_image.Draw();//セーブ画面のタイトル画像
	}

	//戻るボタン
	back_button.Draw(screen.GetFrameTime());

	//test.Draw();
	save_load_object_button.Draw();//セーブとロードのボタン

	//モザイク処理
	//scr_gra.Draw(mosaic);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	box.Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

int FileScene::GetReturnButton()
{
	if ((back_button.GetSelected() == 1) && (box_draw_flag == 3) && (in_game_flag_buffer == false))
	{
		load_string_image.Reset();//ロード画面のタイトル画像の初期化
		save_string_image.Reset();//セーブ画面のタイトル画像の初期化

		box_draw_flag = 0;//フェードアウトのflagを立てる
		back_button.SetSelectedFlag(-1);
		return GAME_TITLE;//タイトルに戻る
	}

	if ((back_button.GetSelected() == 1) && (box_draw_flag == 3) && (in_game_flag_buffer == true))
	{
		load_string_image.Reset();//ロード画面のタイトル画像の初期化
		save_string_image.Reset();//セーブ画面のタイトル画像の初期化

		box_draw_flag = 0;//フェードアウトのflagを立てる
		back_button.SetSelectedFlag(-1);
		return GAME_START;//ゲームに戻る
	}

	return GAME_NONE;
}

void FileScene::SetSecne(int scene_type)
{
	secen_select = scene_type;
	button_click = scene_type;
}