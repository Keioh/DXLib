#include "ver2.0/Objects/OptionScene.h"

void OptionScene::Load()
{
	//戻るボタンの読み込み
	back_button.Load();

	//保存ボタンの読み込み
	save_button.Load();
}

void OptionScene::Init(DiploidEngineSetting& setting)
{
	//フェード用BOX
	box.Init(VGet(0, 0, 0), VGet(setting.window_x, setting.window_y, 0), GetColor(0, 0, 0));
	box.SetFill(true);

	//戻るボタン
	back_button.Init(VGet(setting.window_x - (128 + 4), setting.window_y - (32 + 4), 0));

	//保存ボタン
	save_button.Init(VGet(setting.window_x - ((128 * 2) + 4), setting.window_y - (32 + 4), 0));

}

void OptionScene::Updata(DiploidEngineInput& input)
{
	SetBackgroundColor(255, 255, 255);//Window背景色を白色に変更


	save_button.Update(input);//保存ボタンの更新処理

	back_button.Update(input);//戻るボタンの更新処理

	if (back_button.GetClick() == true)//戻るボタンがクリックされたら
	{
		back_button.SetSelectedFlag(1);//選択状態を1を維持
		box_draw_flag = 2;//フェードインを始める
	}
	

	//シーンが始まったら
	if (box_draw_flag == 0)//フェードアウト始め
	{
		alpha -= alpha_speed;//透過値を変更

		if (alpha <= 0)//透過値フロー処理
		{
			alpha = 0;
			box_draw_flag = 1;//フェードアウト完了
		}
	}

	if (box_draw_flag == 2)//フェードイン始め
	{
		alpha += alpha_speed;//透過値を変更

		if (alpha > 255)//透過値フロー処理
		{
			alpha = 255;
			box_draw_flag = 3;//フェードイン完了
		}
	}
}

void OptionScene::Draw(bool draw, bool debug)
{
	//保存ボタン
	save_button.Draw(draw, debug);

	//戻るボタン
	back_button.Draw(draw, debug);

	//フェードアウト用BOX
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	box.Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}


bool OptionScene::GetReturnFlag()
{
	if ((back_button.GetSelected() == 1) && (box_draw_flag == 3))
	{
		box_draw_flag = 0;//フェードアウトのflagを立てる
		back_button.SetSelectedFlag(-1);//ボタンの選択状態を-1(初期化)にする。
		return true;
	}

	return false;
}