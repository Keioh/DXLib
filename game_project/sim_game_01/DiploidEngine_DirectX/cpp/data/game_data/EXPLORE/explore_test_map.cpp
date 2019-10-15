#include "data/game_data/EXPLORE/explore_test_map.h"

void Explore_TestMap::Load()
{
	//マップの読み込み
	_MapLoad();

	//プレーヤーの読み込み
	player_direction.Load();

	//視界域の読み込み
	player_visibility.image.Load("texter/game/character/shikai.png");


	//戦闘画面の背景画像の読み込み
	combat_back_texter.image.Load("texter/game/battle/back.png");

	//戦闘コマンド画像の読み込み
	battle_command.SwitchButtonBOX_Load("texter/game/battle/battle.png", 60, 30);

}

void Explore_TestMap::Init(VECTOR position)
{		
	//マップの初期化
	_MapInit(position);

	//プレーヤーの初期化
	player_direction.Init(player_size);

	//視界域の初期化
	player_visibility.image.Init(VGet(1280 / 2, 720 / 2, 0));

	//敵の初期化
	enemy_position = VGet(100, 0, 0);
	enemy_test.box.Init(VGet(1280 / 2 + enemy_position.x, 720 / 2 + enemy_position.y, 0), VGet(50,50,0));
	enemy_test.box.name_tag = "test_enemy";
	enemy_test.box.layer_number = DIPLOID_LAYER_02;

	//戦闘画面の背景画像の初期化
	combat_back_texter.image.Init(VGet(1280/2, 720/2, 0));

	//戦闘コマンドの初期化
	battle_command.SwitchButtonBOX_Init(VGet(100, 300, 0), VGet(60, 30, 0), "battle_command", DIPLOID_LAYER_03);
}

void Explore_TestMap::Push(DiploidEngineImpact& impact)
{	
	//マップのプッシュ
	_MapPush(&impact);

	//プレーヤーのプッシュ
	player_direction.Push(impact);

	//敵のプッシュ
	impact.PushBox(enemy_test.box);

}

void Explore_TestMap::Updata(DiploidEngineImpact& impact, DiploidEngineInput& input, CommandUI& command_ui, StatusBar& status_bar, Clock& clock)
{	
	//敵がプレイヤーと当たっていたら
	if (impact.GetBoxImpactFlag_Sreach_Name_Tag("test_enemy") == true)
	{
		enemy_hit = true;
	}

	//敵と当たっていないとき
	if (enemy_hit == false)
	{

		system.OneDeletePOINT_Impact(impact, "battle_command_point");//戦闘画面のマウスポイントと削除
		system.OneDeleteBOX_Impact(impact, "battle_command");//戦闘コマンドの削除
		system.FlagReset_OnePushPOINT();//読み込みフラグをfalseに

		//マップのアップデート
		_MapUpdate(&impact, &input, &command_ui, &status_bar, &clock);

		//プレーヤーのアップデート
		player_direction.Updata(impact, input);
	}
	else if(enemy_hit == true)//敵との戦闘
	{

		system.FlagReset_OneDeletePOINT();//削除フラグをfalseに

		//マウスカーソル(戦闘画面UI画面)
		mouse_point.point.Init(VGet(0, 0, 0));
		mouse_point.point.mouse_point_move_flag = true;
		mouse_point.point.layer_number = DIPLOID_LAYER_03;
		mouse_point.point.name_tag = "battle_command_point";
		system.OnePushPOINT_Impact(impact, mouse_point.point);//戦闘画面のマウスポイントを追加
		system.OnePushBOX_Impact(impact, battle_command.box);//戦闘コマンドを追加。


		battle_command.SwitchButtonBOX_Update(MOUSE_INPUT_LEFT, impact, input);//戦闘コマンドの更新


		if (input.GetPressKey(KEY_INPUT_L) == true)
		{
			impact.DestoryBox_Name_Tag("test_enemy");

			enemy_hit = false;
		}
	}
}

void Explore_TestMap::Draw(bool draw)
{
	if (enemy_hit == false)
	{
		//マップの描写
		_MapDraw(draw);

		//プレーヤーの描写
		player_direction.Draw(draw);

		//視界域の描写
		player_visibility.image.Draw(draw);
	}
	else
	{
		//戦闘画面の背景画像の描写
		combat_back_texter.image.Draw();

		//戦闘コマンドの描写
		battle_command.SwitchButtonBOX_Draw(draw);
	}
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
	test_map_texter.image.Init(VGet((1280 / 2), (720 / 2), 0), 4.0f);
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

void Explore_TestMap::_MapUpdate(DiploidEngineImpact* impact, DiploidEngineInput* input, CommandUI* command_ui, StatusBar* status_bar, Clock* clock)
{
	//背景画像のアップデート
	test_map_texter.image.Updata();

	//走っているときと歩いているときの具体処理
	if (movement_type == PLAYER_RUN)
	{
		if (clock->isSecondFlag() == true)
		{		
			command_ui->information_command.AddStaminaEXP(1);//持久力の経験値を1上げる

			status_bar->SubSP(1, command_ui->information_command);//スタミナポイント(SP)を１減らす
		}

	}
	else if(movement_type == PLAYER_WALK)
	{
		if (command_ui->information_command.GetStaminaPoint() < command_ui->information_command.GetMaxStaminaPoint())//スタミナポイントが0でなければ
		{
			if (clock->isSecondFlag() == true)
			{
				status_bar->AddSP(1, command_ui->information_command);//スタミナポイント(SP)を１回復する
			}
		}
	}

	//走る
	if ((input->GetKey(KEY_INPUT_LSHIFT) == true) && (((input->GetKey(KEY_INPUT_A) == true) || ((input->GetKey(KEY_INPUT_D) == true)) || ((input->GetKey(KEY_INPUT_W) == true) || ((input->GetKey(KEY_INPUT_S) == true))))))
	{
		if (command_ui->information_command.GetStaminaPoint() != 0)//スタミナポイントが0でなければ
		{
			movement_type = PLAYER_RUN;//移動状態を「走り」にする

		}
		else
		{
			movement_type = PLAYER_WALK;//移動状態を「走り」にする
		}
	}
	else
	{
		movement_type = PLAYER_WALK;//移動状態を「走り」にする
	}	

	//左へ行く
	if (input->GetKey(KEY_INPUT_A) == true)
	{
		if (impact->GetBoxImpactFlag_Sreach_Name_Tag("player_left") == false)//左が当たっていなければ
		{
			//歩き
			if (movement_type == PLAYER_WALK)
			{
				for (int count = 0; count <= map_number; count++)
				{
					impact->SetBoxPositionAnimationX_Sreach_Object_Name("map_chip_wall_impact", movement_speed);//移動	
					test_map_texter.image.move_speed.x = movement_speed;

					impact->SetBoxPositionAnimationX_Sreach_Object_Name("test_enemy", movement_speed);//移動	

				}
			}

			//走り
			if (movement_type == PLAYER_RUN)
			{
				for (int count = 0; count <= map_number; count++)
				{
					impact->SetBoxPositionAnimationX_Sreach_Object_Name("map_chip_wall_impact", movement_speed * movement_run_scale);//移動	
					test_map_texter.image.move_speed.x = movement_speed * movement_run_scale;

					impact->SetBoxPositionAnimationX_Sreach_Object_Name("test_enemy", movement_speed * movement_run_scale);//移動	


				}
			}
		}
	}

	//右へ行く
	if (input->GetKey(KEY_INPUT_D) == true)
	{
		if (impact->GetBoxImpactFlag_Sreach_Name_Tag("player_right") == false)//右が当たっていなければ
		{
			//歩き
			if (movement_type == PLAYER_WALK)
			{
				for (int count = 0; count <= map_number; count++)
				{

					impact->SetBoxPositionAnimationX_Sreach_Object_Name("map_chip_wall_impact", -movement_speed);//移動
					test_map_texter.image.move_speed.x = -movement_speed;

					impact->SetBoxPositionAnimationX_Sreach_Object_Name("test_enemy", -movement_speed);//移動	

				}
			}

			//走り
			if (movement_type == PLAYER_RUN)
			{
				for (int count = 0; count <= map_number; count++)
				{

					impact->SetBoxPositionAnimationX_Sreach_Object_Name("map_chip_wall_impact", -movement_speed * movement_run_scale);//移動
					test_map_texter.image.move_speed.x = -movement_speed * movement_run_scale;

					impact->SetBoxPositionAnimationX_Sreach_Object_Name("test_enemy", -movement_speed * movement_run_scale);//移動	

				}
			}
		}
	}

	//上へ行く
	if (input->GetKey(KEY_INPUT_W) == true)
	{
		if (impact->GetBoxImpactFlag_Sreach_Name_Tag("player_up") == false)//上が当たっていなければ
		{
			//歩き
			if (movement_type == PLAYER_WALK)
			{
				for (int count = 0; count <= map_number; count++)
				{
					impact->SetBoxPositionAnimationY_Sreach_Object_Name("map_chip_wall_impact", movement_speed);//移動
					test_map_texter.image.move_speed.y = movement_speed;

					impact->SetBoxPositionAnimationY_Sreach_Object_Name("test_enemy", movement_speed);//移動
				}
			}

			//走り
			if (movement_type == PLAYER_RUN)
			{
				for (int count = 0; count <= map_number; count++)
				{
					impact->SetBoxPositionAnimationY_Sreach_Object_Name("map_chip_wall_impact", movement_speed * movement_run_scale);//移動
					test_map_texter.image.move_speed.y = movement_speed * movement_run_scale;

					impact->SetBoxPositionAnimationY_Sreach_Object_Name("test_enemy", movement_speed * movement_run_scale);//移動

				}
			}
		}
	}

	//下へ行く
	if (input->GetKey(KEY_INPUT_S) == true)
	{
		if (impact->GetBoxImpactFlag_Sreach_Name_Tag("player_down") == false)//下が当たっていなければ
		{
			//歩き
			if (movement_type == PLAYER_WALK)
			{
				for (int count = 0; count <= map_number; count++)
				{
					impact->SetBoxPositionAnimationY_Sreach_Object_Name("map_chip_wall_impact", -movement_speed);//移動
					test_map_texter.image.move_speed.y = -movement_speed;

					impact->SetBoxPositionAnimationY_Sreach_Object_Name("test_enemy", -movement_speed);//移動
				}
			}

			//走り
			if (movement_type == PLAYER_RUN)
			{
				for (int count = 0; count <= map_number; count++)
				{
					impact->SetBoxPositionAnimationY_Sreach_Object_Name("map_chip_wall_impact", -movement_speed * movement_run_scale);//移動
					test_map_texter.image.move_speed.y = -movement_speed * movement_run_scale;

					impact->SetBoxPositionAnimationY_Sreach_Object_Name("test_enemy", -movement_speed * movement_run_scale);//移動
				}
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


bool Explore_TestMap::GetEnemyHitFlag()
{
	return enemy_hit;
}