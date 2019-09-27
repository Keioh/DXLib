#include "data/game_data/EXPLORE/explore_test_map.h"

void Explore_TestMap::Load()
{
	//マップの読み込み
	_MapLoad();

	//プレーヤーの読み込み
	_PlayerLoad();
}

void Explore_TestMap::Init(VECTOR position)
{		
	//マップの初期化
	_MapInit(position);

	//プレーヤーの初期化
	_PlayerInit();
}

void Explore_TestMap::Push(DiploidEngineImpact& impact)
{	
	//プレーヤーのプッシュ
	_PlayerPush(&impact);

	//マップのプッシュ
	_MapPush(&impact);
}

void Explore_TestMap::Updata(DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	//マップのアップデート
	_MapUpdate(&impact, &input);

	//プレーヤーのアップデート
	_PlayerUpdate(&impact, &input);
}

void Explore_TestMap::Draw(bool draw)
{
	//マップの描写
	_MapDraw(draw);

	//プレーヤーの描写
	_PlayerDraw(draw);
}




//マップ関連の関数
void Explore_TestMap::_MapLoad()
{
	//マップ関連
	test_map.map.Load("texter/game/map/test_map.png", 12, 12);
	map_image_x = 12;
	map_image_y = 12;

	//背景画像の読み込み
	test_map_texter.image.Load("texter/game/map/test_map_texter.png");
}

void Explore_TestMap::_MapInit(VECTOR position)
{
	//マップ関連
	map_chip_size = 400.0f;//マップチップの大きさ

	player_size = map_chip_size * 0.2f;

	map_size = VGet((map_chip_size * map_image_x) / 2, (map_chip_size * map_image_y) / 2, 0);
	map_position = position;
	map_center_position_sub = VSub(map_position, map_size);//マップサイズからマップの半分の大きさを求める

	test_map.map.SetMapChipSize(map_chip_size);
	test_map.map.Create();

	//背景画像の初期化
	test_map_texter.image.Init(VGet((1280 / 2), (720 / 2), 0), 40.0f);
}

void Explore_TestMap::_MapPush(DiploidEngineImpact* impact)
{
	//マップ関連
	for (auto count = test_map.map.MAP.begin(); count != test_map.map.MAP.end(); ++count)//map.MAP配列をsize_t(auto)で取得しMAP.end()まで下記のことを繰り返す
	{
		if ((count->red == 0) && (count->green == 0) && (count->blue == 0) && (count->alph == 255))//α値が255の時かつ黒の時
		{
			test_map.box.Init(VGet((count->x * count->size) + map_center_position_sub.x, (count->y * count->size) + map_center_position_sub.y, 0), VGet(count->size, count->size, 0));
			test_map.box.layer_number = DIPLOID_LAYER_01;
			test_map.box.name_tag = "map_chip_wall_impact";
			impact->PushBox(test_map.box);

			map_number++;
		}
	}
}

void Explore_TestMap::_MapUpdate(DiploidEngineImpact* impact, DiploidEngineInput* input)
{	
	//背景画像のアップデート
	test_map_texter.image.Updata();

	//左へ行く
	if (input->GetKey(KEY_INPUT_A) == true)
	{
		if (impact->GetBoxImpactFlag_Sreach_Name_Tag("player_left") == false)//左が当たっていなければ
		{
			for (int count = 0; count <= map_number; count++)
			{
				impact->SetBoxPositionAnimationX_Sreach_Object_Name("map_chip_wall_impact", movement_speed);//移動	
				test_map_texter.image.move_speed.x = movement_speed;
			}
		}
	}

	//右へ行く
	if (input->GetKey(KEY_INPUT_D) == true)
	{
		if (impact->GetBoxImpactFlag_Sreach_Name_Tag("player_right") == false)//右が当たっていなければ
		{
			for (int count = 0; count <= map_number; count++)
			{
				impact->SetBoxPositionAnimationX_Sreach_Object_Name("map_chip_wall_impact", -movement_speed);//移動
				test_map_texter.image.move_speed.x = -movement_speed;
			}
		}
	}

	//上へ行く
	if (input->GetKey(KEY_INPUT_W) == true)
	{
		if (impact->GetBoxImpactFlag_Sreach_Name_Tag("player_up") == false)//上が当たっていなければ
		{
			for (int count = 0; count <= map_number; count++)
			{
				impact->SetBoxPositionAnimationY_Sreach_Object_Name("map_chip_wall_impact", movement_speed);//移動
				test_map_texter.image.move_speed.y = movement_speed;
			}
		}
	}

	//下へ行く
	if (input->GetKey(KEY_INPUT_S) == true)
	{
		if (impact->GetBoxImpactFlag_Sreach_Name_Tag("player_down") == false)//下が当たっていなければ
		{
			for (int count = 0; count <= map_number; count++)
			{
				impact->SetBoxPositionAnimationY_Sreach_Object_Name("map_chip_wall_impact", -movement_speed);//移動
				test_map_texter.image.move_speed.y = -movement_speed;
			}
		}
	}
}

void Explore_TestMap::_MapDraw(bool draw)
{
	//背景画像の描写
	if (draw == true)
	{
		test_map_texter.image.Draw();
	}
}


//プレーヤー関連の関数
void Explore_TestMap::_PlayerLoad()
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

void Explore_TestMap::_PlayerInit()
{
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

void Explore_TestMap::_PlayerPush(DiploidEngineImpact* impact)
{
	//プレーヤー関連
	player_left.box.name_tag = "player_left";
	player_left.box.layer_number = DIPLOID_LAYER_01;
	impact->PushBox(player_left.box);

	player_right.box.name_tag = "player_right";
	player_right.box.layer_number = DIPLOID_LAYER_01;
	impact->PushBox(player_right.box);

	player_up.box.name_tag = "player_up";
	player_up.box.layer_number = DIPLOID_LAYER_01;
	impact->PushBox(player_up.box);

	player_down.box.name_tag = "player_down";
	player_down.box.layer_number = DIPLOID_LAYER_01;
	impact->PushBox(player_down.box);
}

void Explore_TestMap::_PlayerUpdate(DiploidEngineImpact* impact, DiploidEngineInput* input)
{
	//左へ向く
	if (input->GetKey(KEY_INPUT_A) == true)
	{
		//プレーヤー画像の更新
		player_direction = PLAYER_LEFT;
		player_left_image.image.Updata();
	}

	//右へ向く
	if (input->GetKey(KEY_INPUT_D) == true)
	{
		//プレーヤー画像の更新
		player_direction = PLAYER_RIGHT;
		player_right_image.image.Updata();
	}

	//上へ向く
	if (input->GetKey(KEY_INPUT_W) == true)
	{
		//プレーヤー画像の更新
		player_direction = PLAYER_UP;
		player_up_image.image.Updata();
	}

	//下へ向く
	if (input->GetKey(KEY_INPUT_S) == true)
	{
		//プレーヤー画像の更新
		player_direction = PLAYER_DOWN;
		player_down_image.image.Updata();
	}

	//左上を向いたとき
	if ((input->GetKey(KEY_INPUT_A) == true) && (input->GetKey(KEY_INPUT_W) == true))
	{
		//プレーヤー画像の更新
		player_direction = PLAYER_LEFT_UP;
		player_left_up_image.image.Updata();
	}

	//右上を向いたとき
	if ((input->GetKey(KEY_INPUT_D) == true) && (input->GetKey(KEY_INPUT_W) == true))
	{
		//プレーヤー画像の更新
		player_direction = PLAYER_RIGHT_UP;
		player_right_up_image.image.Updata();
	}

	//右下を向いたとき
	if ((input->GetKey(KEY_INPUT_D) == true) && (input->GetKey(KEY_INPUT_S) == true))
	{
		//プレーヤー画像の更新
		player_direction = PLAYER_RIGHT_DOWN;
		player_right_down_image.image.Updata();
	}

	//左下を向いたとき
	if ((input->GetKey(KEY_INPUT_A) == true) && (input->GetKey(KEY_INPUT_S) == true))
	{
		//プレーヤー画像の更新
		player_direction = PLAYER_LEFT_DOWN;
		player_left_down_image.image.Updata();
	}
}

void Explore_TestMap::_PlayerDraw(bool draw)
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