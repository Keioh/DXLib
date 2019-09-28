#include "data/game_data/EXPLORE/explore_test_map.h"

void Explore_TestMap::Load()
{
	//マップの読み込み
	_MapLoad();

	//プレーヤーの読み込み
	player_direction.Load();
}

void Explore_TestMap::Init(VECTOR position)
{		
	//マップの初期化
	_MapInit(position);

	//プレーヤーの初期化
	player_direction.Init(player_size);
}

void Explore_TestMap::Push(DiploidEngineImpact& impact)
{	
	//マップのプッシュ
	_MapPush(&impact);

	//プレーヤーのプッシュ
	player_direction.Push(impact);
}

void Explore_TestMap::Updata(DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	//マップのアップデート
	_MapUpdate(&impact, &input);

	//プレーヤーのアップデート
	player_direction.Updata(impact, input);
}

void Explore_TestMap::Draw(bool draw)
{
	//マップの描写
	_MapDraw(draw);

	//プレーヤーの描写
	player_direction.Draw(draw);
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