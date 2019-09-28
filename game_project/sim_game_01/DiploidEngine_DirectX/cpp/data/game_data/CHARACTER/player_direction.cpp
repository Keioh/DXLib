#include "data/game_data/CHARACTER/player_direction.h"

void PlayerDirection::Load()
{
	//キャラクター画像の読み込み
	player_up_image.image.Load("texter/game/character/front/front_0.png");
	player_down_image.image.Load("texter/game/character/back/back_0.png");
	player_left_image.image.Load("texter/game/character/left/left_0.png");
	player_right_image.image.Load("texter/game/character/right/right_0.png");

	player_left_up_image.image.Load("texter/game/character/left_up/left_up_0.png");
	player_right_up_image.image.Load("texter/game/character/right_up/right_up_0.png");
	player_left_down_image.image.Load("texter/game/character/left_down/left_down_0.png");
	player_right_down_image.image.Load("texter/game/character/right_down/right_down_0.png");

}

void PlayerDirection::Init(float player_scale)
{
	player_size = player_scale;

	//プレーヤー関連
	player_left.box.Init(VGet((1280 / 2) - (player_size / 2) - 20, (720 / 2) - (player_size / 2), 0), VGet(20, player_size, 0));//左
	player_right.box.Init(VGet((1280 / 2) + (player_size / 2), (720 / 2) - (player_size / 2), 0), VGet(20, player_size, 0));//右
	player_up.box.Init(VGet((1280 / 2) - (player_size / 2), (720 / 2) - (player_size / 2) - 20, 0), VGet(player_size, 20, 0));//上
	player_down.box.Init(VGet((1280 / 2) - (player_size / 2), (720 / 2) + (player_size / 2), 0), VGet(player_size, 20, 0));//下

	//プレーヤー画像の初期化
	player_up_image.image.Init(VGet((1280 / 2) - (player_size / 2) + 38, (720 / 2) - (player_size / 2) + 40, 0), 2.0f);
	player_down_image.image.Init(VGet((1280 / 2) - (player_size / 2) + 38, (720 / 2) - (player_size / 2) + 40, 0), 2.0f);
	player_left_image.image.Init(VGet((1280 / 2) - (player_size / 2) + 38, (720 / 2) - (player_size / 2) + 40, 0), 2.0f);
	player_right_image.image.Init(VGet((1280 / 2) - (player_size / 2) + 38, (720 / 2) - (player_size / 2) + 40, 0), 2.0f);

	player_left_up_image.image.Init(VGet((1280 / 2) - (player_size / 2) + 38, (720 / 2) - (player_size / 2) + 40, 0), 2.0f);
	player_right_up_image.image.Init(VGet((1280 / 2) - (player_size / 2) + 38, (720 / 2) - (player_size / 2) + 40, 0), 2.0f);
	player_left_down_image.image.Init(VGet((1280 / 2) - (player_size / 2) + 38, (720 / 2) - (player_size / 2) + 40, 0), 2.0f);
	player_right_down_image.image.Init(VGet((1280 / 2) - (player_size / 2) + 38, (720 / 2) - (player_size / 2) + 40, 0), 2.0f);

}

void PlayerDirection::Push(DiploidEngineImpact& impact)
{
	//プレーヤー関連
	player_left.box.name_tag = "player_left";
	player_left.box.layer_number = DIPLOID_LAYER_01;
	impact.PushBox(player_left.box);

	player_right.box.name_tag = "player_right";
	player_right.box.layer_number = DIPLOID_LAYER_01;
	impact.PushBox(player_right.box);

	player_up.box.name_tag = "player_up";
	player_up.box.layer_number = DIPLOID_LAYER_01;
	impact.PushBox(player_up.box);

	player_down.box.name_tag = "player_down";
	player_down.box.layer_number = DIPLOID_LAYER_01;
	impact.PushBox(player_down.box);

}

void PlayerDirection::Updata(DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	//左へ向く
	if (input.GetKey(KEY_INPUT_A) == true)
	{
		//プレーヤー画像の更新
		player_direction = PLAYER_LEFT;
		player_left_image.image.Updata();
	}

	//右へ向く
	if (input.GetKey(KEY_INPUT_D) == true)
	{
		//プレーヤー画像の更新
		player_direction = PLAYER_RIGHT;
		player_right_image.image.Updata();
	}

	//上へ向く
	if (input.GetKey(KEY_INPUT_W) == true)
	{
		//プレーヤー画像の更新
		player_direction = PLAYER_UP;
		player_up_image.image.Updata();
	}

	//下へ向く
	if (input.GetKey(KEY_INPUT_S) == true)
	{
		//プレーヤー画像の更新
		player_direction = PLAYER_DOWN;
		player_down_image.image.Updata();
	}

	//左上を向いたとき
	if ((input.GetKey(KEY_INPUT_A) == true) && (input.GetKey(KEY_INPUT_W) == true))
	{
		//プレーヤー画像の更新
		player_direction = PLAYER_LEFT_UP;
		player_left_up_image.image.Updata();
	}

	//右上を向いたとき
	if ((input.GetKey(KEY_INPUT_D) == true) && (input.GetKey(KEY_INPUT_W) == true))
	{
		//プレーヤー画像の更新
		player_direction = PLAYER_RIGHT_UP;
		player_right_up_image.image.Updata();
	}

	//右下を向いたとき
	if ((input.GetKey(KEY_INPUT_D) == true) && (input.GetKey(KEY_INPUT_S) == true))
	{
		//プレーヤー画像の更新
		player_direction = PLAYER_RIGHT_DOWN;
		player_right_down_image.image.Updata();
	}

	//左下を向いたとき
	if ((input.GetKey(KEY_INPUT_A) == true) && (input.GetKey(KEY_INPUT_S) == true))
	{
		//プレーヤー画像の更新
		player_direction = PLAYER_LEFT_DOWN;
		player_left_down_image.image.Updata();
	}

}

void PlayerDirection::Draw(bool draw)
{
	if (draw == true)
	{
		//プレーヤー画像の描写
		switch (player_direction)
		{
		case PLAYER_UP:	player_up_image.image.Draw(); break;
		case PLAYER_DOWN: player_down_image.image.Draw(); break;
		case PLAYER_LEFT: player_left_image.image.Draw(); break;
		case PLAYER_RIGHT: player_right_image.image.Draw(); break;
		case PLAYER_LEFT_UP: player_left_up_image.image.Draw(); break;
		case PLAYER_RIGHT_UP: player_right_up_image.image.Draw(); break;
		case PLAYER_LEFT_DOWN: player_left_down_image.image.Draw(); break;
		case PLAYER_RIGHT_DOWN: player_right_down_image.image.Draw(); break;
		default: break;
		}
	}
}


int PlayerDirection::GetDirection()
{
	return player_direction;
}