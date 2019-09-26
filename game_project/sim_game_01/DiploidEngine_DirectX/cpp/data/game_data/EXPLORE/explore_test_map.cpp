#include "data/game_data/EXPLORE/explore_test_map.h"

void Explore_TestMap::Load()
{
	//マップ関連
	test_map.map.Load("texter/game/map/test_map.png", 12, 12);
	map_image_x = 12;
	map_image_y = 12;

	test_map_texter.image.Load("texter/game/map/test_map_texter.png");
}

void Explore_TestMap::Init(VECTOR position)
{		
	//マップ関連
	map_chip_size = 400.0f;//マップチップの大きさ
	
	player_size = map_chip_size * 0.2f;

	map_size = VGet((map_chip_size * map_image_x) / 2, (map_chip_size * map_image_y) / 2, 0);
	map_position = position;
	map_center_position_sub = VSub(map_position, map_size);//マップサイズからマップの半分の大きさを求める

	test_map.map.SetMapChipSize(map_chip_size);
	test_map.map.Create();


	test_map_texter.image.Init(VGet((1280 / 2), (720 / 2), 0), 40.0f);


	//プレーヤー関連
	player_left.box.Init(VGet((1280 / 2) - (player_size / 2) - 20, (720 / 2) - (player_size / 2), 0), VGet(20, player_size, 0));//左
	player_right.box.Init(VGet((1280 / 2) + (player_size / 2), (720 / 2) - (player_size / 2), 0), VGet(20, player_size, 0));//右
	player_up.box.Init(VGet((1280 / 2) - (player_size / 2), (720 / 2) - (player_size / 2) - 20, 0), VGet(player_size, 20, 0));//上
	player_down.box.Init(VGet((1280 / 2) - (player_size / 2), (720 / 2) + (player_size / 2), 0), VGet(player_size, 20, 0));//下

}

void Explore_TestMap::Push(DiploidEngineImpact& impact)
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


	//マップ関連
	for (auto count = test_map.map.MAP.begin(); count != test_map.map.MAP.end(); ++count)//map.MAP配列をsize_t(auto)で取得しMAP.end()まで下記のことを繰り返す
	{
		if ((count->red == 0) && (count->green == 0) && (count->blue == 0) && (count->alph == 255))//α値が255の時かつ黒の時
		{
			test_map.box.Init(VGet((count->x * count->size) + map_center_position_sub.x, (count->y * count->size) + map_center_position_sub.y, 0), VGet(count->size, count->size, 0));
			test_map.box.layer_number = DIPLOID_LAYER_01;
			test_map.box.name_tag = "map_chip_" + map_number;
			impact.PushBox(test_map.box);

			map_number++;
		}
	}
}

void Explore_TestMap::Updata(DiploidEngineImpact& impact, DiploidEngineInput& input)
{
	//左へ行く
	if (input.GetKey(KEY_INPUT_LEFT) == true)
	{
		if (impact.GetBoxImpactFlag_Sreach_Name_Tag("player_left") == false)//左が当たっていなければ
		{
			for (int count = 0; count <= map_number; count++)
			{
				impact.SetBoxPositionAnimationX_Sreach_Object_Name("map_chip_" + count, movement_speed);//移動	
				test_map_texter.image.move_speed.x = movement_speed;
			}
		}
	}

	//右へ行く
	if (input.GetKey(KEY_INPUT_RIGHT) == true)
	{
		if (impact.GetBoxImpactFlag_Sreach_Name_Tag("player_right") == false)//右が当たっていなければ
		{
			for (int count = 0; count <= map_number; count++)
			{
				impact.SetBoxPositionAnimationX_Sreach_Object_Name("map_chip_" + count, -movement_speed);//移動
				test_map_texter.image.move_speed.x = -movement_speed;
			}
		}
	}
	
	//上へ行く
	if (input.GetKey(KEY_INPUT_UP) == true)
	{
		if (impact.GetBoxImpactFlag_Sreach_Name_Tag("player_up") == false)//上が当たっていなければ
		{
			for (int count = 0; count <= map_number; count++)
			{
				impact.SetBoxPositionAnimationY_Sreach_Object_Name("map_chip_" + count, movement_speed);//移動
				test_map_texter.image.move_speed.y = movement_speed;
			}
		}
	}

	//下へ行く
	if (input.GetKey(KEY_INPUT_DOWN) == true)
	{
		if (impact.GetBoxImpactFlag_Sreach_Name_Tag("player_down") == false)//下が当たっていなければ
		{
			for (int count = 0; count <= map_number; count++)
			{
				impact.SetBoxPositionAnimationY_Sreach_Object_Name("map_chip_" + count, -movement_speed);//移動
				test_map_texter.image.move_speed.y = -movement_speed;
			}
		}
	}		
	
	test_map_texter.image.Updata();
}

void Explore_TestMap::Draw(bool draw)
{
	test_map_texter.image.Draw();
}
